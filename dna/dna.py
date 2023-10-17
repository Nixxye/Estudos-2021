import csv
import sys


def main():

    # Check for command-line usage
    if (len(sys.argv) != 3):
        print("Usage: python dna.py data.csv sequence.txt")
        sys.exit(1)
    # Read database file into a variable
    element_count = 0
    list = []
    with open(sys.argv[1]) as file_dna:
        reader = csv.DictReader(file_dna)
        for row in reader:
            list.append(row)
            element_count += 1
    # Getting the srts
    str_list = []
    with open(sys.argv[1]) as file_dna1:
        str_templist = file_dna1.readline()
        temp_list = str_templist.split(',')
        for word in temp_list:
            if word != 'name':
                str_list.append(word.rstrip())
    # Read DNA sequence file into a variable
    with open(sys.argv[2]) as file_sequence:
        sequence = file_sequence.read()
    # TODO: Find longest match of each STR in DNA sequence
    str_match = []
    str_list_len = len(str_list)
    for i in range(str_list_len):
        counter = 0  # Temporary variable that keep the sequence number
        longest_match = 0
        for start in range(len(sequence)-len(str_list[i])):
            end = start + len(str_list[i])
            if str_list[i] == sequence[start:end]:
                temp_len = len(str_list[i])
                if sequence[start - temp_len:end - temp_len] == str_list[i]:
                    counter += 1
                else:
                    counter = 1
                if counter > longest_match:  # Put longest match in a variable
                    longest_match = counter
        str_match.append(longest_match)  # Put str in a list
    # Check database for matching profiles
    i = 0
    match = False  # Check if there is no match
    for x in list:
        j = 0
        str_counter = 0
        for word in str_list:
            if int(x[word]) == int(str_match[j]):
                str_counter += 1
            j += 1
            if str_counter == len(str_match):
                print(f"{x['name']}")
                match = True
                break
        i += 1
    if match == False:
        print("No match")
    return

main()