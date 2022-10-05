import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        sys.exit()
    # TODO: Read database file into a variable
    # dna of each person
    dnafile = {}

    # type (sequences) of dna in the sequence

    sequences = []

    # filename of the dna of each person
    filename = sys.argv[1]

    # filename of the sequence
    dnafilename = sys.argv[2]

    # open and read dna of each person into "dnafile" and the sequences into "sequences"
    with open(filename, "r") as file:
        for index, row in enumerate(file):
            if index == 0:
                sequences = [sequence for sequence in row.strip().split(",")][1:]
            else:
                name = row.strip().split(",")
                dnafile[name[0]] = name[1:]

    # TODO: Read DNA sequence file into a variable
    # read the dna sequence into "sequence"
    with open(dnafilename, "r") as file:
        sequence = file.read().replace('\n', '')

    # TODO: Find longest match of each STR in DNA sequence

    result = [longest_match(sequence, subsequence) for subsequence in sequences]

    # TODO: Check database for matching profiles

    # compares "result" list against dnafile{} values
    # leave the program if there is a match, and print key(name) in dnafile{}
    for s in dnafile:
        count = 0
        for j in range(len(dnafile[s])):
            if result[j] == int(dnafile[s][j]):
                count += 1
        if count == len(sequences):
            return print(s)

    # otherwise, no match
    return print("No match")


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
