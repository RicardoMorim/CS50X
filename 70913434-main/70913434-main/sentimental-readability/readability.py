# TODO
from cs50 import get_string

# keys to end the sentence
sentences = ["!", "?", "."]

# Get the phrase
phrase = get_string("Write your phrase: ")

# Variables to count the number of sentences, words and letters
sentencescount = 0
wordcount = 0
letterscount = 0

# initializa an empty list that will contain all the uppercase letters
alphabets_in_capital=[]
for i in range(65,91):
    alphabets_in_capital.append(chr(i))


# initialize an empty list that will contain all the lowercase letters
alphabets_in_lowercase=[]
for i in range(97,123):
    alphabets_in_lowercase.append(chr(i))



# Iterate through the phrase and get the number of letters, words and sentences
for i in range(len(phrase)):
    if phrase[i] in sentences:
        sentencescount += 1
        wordcount += 1
    if phrase[i] == " " and phrase[i-1] not in sentences:
        wordcount += 1
    if phrase[i] in alphabets_in_lowercase or phrase[i] in alphabets_in_capital :
        letterscount += 1

# Get tge average letters and sentences
averageletters = (100 * letterscount)/wordcount
averagesentences = (100 * sentencescount) / wordcount

# calculate the grade
Grade = (0.0588 * averageletters) - (0.296 * averagesentences) - 15.8

# Print the Grade
print(Grade)
if Grade > 16:
    print("Grade 16+")
elif Grade < 1:
    print("Before Grade 1")
else:
    print(f"Grade {round(Grade)}")
