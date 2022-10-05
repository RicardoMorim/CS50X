import os
import requests
import urllib.parse

from functools import wraps
from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.security import check_password_hash, generate_password_hash
from datetime import datetime, timezone
from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

# Make sure API key is set
if not os.environ.get("API_KEY"):
    raise RuntimeError("API_KEY not set")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    owns = own_shares()
    total = 0
    for symbol, shares in owns.items():
        result = lookup(symbol)
        name, price = result["name"], result["price"]
        stock_value = shares * price
        total += stock_value
        owns[symbol] = (name, shares, usd(price), usd(stock_value))
    cash = db.execute("SELECT cash FROM users WHERE id = ? ",
                      session["user_id"])[0]['cash']
    total += cash
    return render_template("index.html", owns=owns, cash=usd(cash), total=usd(total))


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    if request.method == "GET":
        return render_template("/buy.html")

    symbol = request.form.get("symbol")
    shares = request.form.get("shares")
    stock = lookup(symbol)

    if not shares or not symbol or "." in shares or "," in shares or shares.isdigit() == False:
        return apology("No symbol or no ammount of shares or shares isnt an integer")
    if (int(shares) < 1):
        return apology("Introduce a positive ammount of shares.")
    if not stock:
        return apology("Wrong symbol")

    price = stock["price"]

    cost = float(price)*int(shares)

    rows = db.execute("SELECT cash FROM users WHERE id=:id",
                      id=session["user_id"])

    cash = rows[0]["cash"]

    newtotal = cash - cost

    if (newtotal < 0):
        return apology("Sorry you can't afford this stocks")

    db.execute("INSERT INTO purshases (person_id, symbol, shares, price, total, time, type) VALUES (?, ?, ?, ?, ?, ?, ?)",
               session["user_id"], symbol, shares, price, cost, time_now(), "buy")

    db.execute("UPDATE users SET CASH = ? WHERE ID = ?",
               newtotal, session["user_id"])

    return redirect("/")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""

    history = db.execute(
        "SELECT SYMBOL, SHARES, PRICE, TIME, TYPE FROM PURSHASES WHERE person_id = ?", session["user_id"])

    return render_template("/history.html", history=history)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?",
                          request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method == "GET":
        return render_template("/quote.html")

    else:
        price = lookup(request.form.get("symbol"))
        if price:

            return render_template("/quoted.html", price=price)

        return apology("Invalid symbol")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    if request.method == "GET":
        return render_template("/register.html")

    else:

        usedname = db.execute("SELECT username FROM users")
        wname = request.form.get("username")
        for i in usedname:
            if wname in i["username"] or not wname:
                return apology("Username error. Must be already taken or it not provided or no password provided.")

        if request.form.get("password") != request.form.get("confirmation") or not request.form.get("password"):
            return apology("Passwords don't match or no password provided")

        password = request.form.get("password")

        hpassword = generate_password_hash(
            password, method='pbkdf2:sha256', salt_length=8)

        db.execute("INSERT INTO USERS (username, hash) VALUES (?,?)",
                   wname, hpassword)

        return redirect("/")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    ownedstocks = db.execute(
        "SELECT symbol FROM PURSHASES WHERE PERSON_ID = ?", session["user_id"])
    ownedstock = []

    for i in range(len(ownedstocks)):
        if ownedstocks[i]["symbol"] not in ownedstock:
            ownedstock.append(ownedstocks[i]["symbol"])

    if request.method == "GET":

        return render_template("sell.html", stocks=ownedstock)

    selling = request.form.get("symbol")

    if selling not in ownedstock:
        return apology("You do not own that stock")

    ownedshares = db.execute(
        "SELECT SUM(shares) FROM PURSHASES WHERE symbol = ? AND PERSON_ID = ?", selling, session["user_id"])
    ammount = request.form.get("shares")

    if int(ownedshares[0]["SUM(shares)"]) < int(ammount):
        return apology("You do not have all those shares!")
    ammount = -int(ammount)
    info = lookup(selling)
    price = info["price"]
    total = float(price)*int(-ammount)
    cash = db.execute("SELECT CASH FROM USERS WHERE ID = ?",
                      session["user_id"])[0]["cash"]
    newcash = float(cash) + total

    db.execute("INSERT INTO purshases (PERSON_ID, SYMBOL, SHARES, PRICE, TOTAL, TIME, TYPE) VALUES (?,?,?,?,?,?,?)",
               session["user_id"], selling, ammount, info["price"], total, time_now(), "sell")
    db.execute("UPDATE USERS SET CASH = ? WHERE ID = ?",
               newcash, session["user_id"])

    return redirect("/")


def time_now():
    """HELPER: get current UTC date and time"""
    now_utc = datetime.now(timezone.utc)
    return str(now_utc.date()) + ' @time ' + now_utc.time().strftime("%H:%M:%S")


def own_shares():
    """Helper function: Which stocks the user owns, and numbers of shares owned. Return: dictionary {symbol: qty}"""
    user_id = session["user_id"]
    owns = {}
    query = db.execute(
        "SELECT symbol, shares FROM purshases WHERE person_id = ?", user_id,)
    for q in query:
        symbol, shares = q["symbol"], q["shares"]
        owns[symbol] = owns.setdefault(symbol, 0) + shares
    # filter zero-share stocks
    owns = {k: v for k, v in owns.items() if v != 0}
    return owns
