# TODO
from cs50 import get_int
# get the input
while True:
    num = get_int("Height: ")
    if (num > 0 and num != 9):
        break

# create each line of the pyramid and print it
for i in range(1, num+1):
    str = ""
    for j in range(num - i):
        str += " "
    for j in range(i):
        str += "#"
    str += "  "
    for j in range(i):
        str += "#"
    print(str)
    str = ""