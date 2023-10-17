# get input
number = input("Credit card number: ")
sum = 0
length = len(number)
# even locations
for i in range(length - 2, -1, -2):
    temp = int(number[i]) * 2
    if temp >= 10:
        sum += temp % 10 + 1
    else:
        sum += temp
# odd locations
for i in range(length - 1, -1, -2):
    sum += int(number[i])
# getting the start number
start = int(number[0]) * 10 + int(number[1])
# checking company
if sum % 10 == 0:
    if length == 15 and (start == 34 or start == 37):
        print("AMEX")
    elif length == 16 and (start == 51 or start == 52 or start == 53 or start == 54 or start == 55):
        print("MASTERCARD")
    elif length == 13 or length == 16 and (int(start / 10) == 4):
        print("VISA")
else:
    print("INVALID")