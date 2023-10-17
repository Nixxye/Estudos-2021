text = input("Text: ")
# variables
length = len(text)
letters = 0
words = 1
sentences = 0
# counting
for i in range(length):
    if (text[i] >= 'a' and text[i] <= 'z') or (text[i] >= 'A' and text[i] <= 'Z'):
        letters += 1
    elif (text[i] == ' '):
        words += 1
    elif (text[i] == '.' or text[i] == '!' or text[i] == '?'):
        sentences += 1
# calculating
grade = 0.0588 * letters * 100 / words - 0.296 * sentences * 100 / words - 15.8
grade = round(grade)
# printing
if (grade < 1):
    print("Before Grade 1")
elif (grade >= 16):
    print("Grade 16+")
else:
    print(f"Grade {grade}")
