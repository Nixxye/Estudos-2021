#get an integer
try:
    n = int(input("Height: "))
except ValueError:
    print("n must be an integer")

for i in range(n):
    for j in range(n - i):
        print(" ", end="")
    for k in range(i + 1):
        print("#", end="")
    print(" ", end="")
    for k in range(i + 1):
        print("#", end="")
    print(" ")