# TODO
from cs50 import get_string

# Get the credit card number
number = get_string("Credit card number: ")

# Verify which is the type of the card
if number[0] == "4":
    print("VISA")
elif number[0] == "3":
    print("AMEX")
elif number[0] == "5":
    print("MASTERCARD")
else:
    print("INVALID")