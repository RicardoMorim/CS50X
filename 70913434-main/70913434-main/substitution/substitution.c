#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

bool check_duplicate(string str);

int main(int argc, string argv[])
{

    // Check if argument is provided
    if (argc != 2)
    {
        printf("Not enough arguments provided\n");
        return 1;
    }
    // check if the key is complete
    string cifer = argv[1];
    if (strlen(cifer) != 26)
    {
        printf("key not long enough\n");
        return 1;
    }
    // check for duplicate and invalid caracters in key
    if (check_duplicate(cifer) == true)
    {
        printf("Duplicated or invalid caracters in the key\n");
        return 1;
    }
    // get the sentence to be encripted and store all letters in a variable in ascii order
    string sentence = get_string("Text to be incripted:\n"), alph = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    // initialize two variables "encripted" to store the encripted letter and print it and "index" to store the index of the letter
    char encripted;
    int index;
    // print the beggining of the output
    printf("ciphertext: ");
    for (int i = 0; i < strlen(sentence); i++)
    {
        // if its a letter
        if (sentence[i] >= 65 && sentence[i] <= 122)
        {
            // get the index in the "alph" variable by subtracting 65 (value of 'a' in ascii)
            index = sentence[i] - 65;
            // if its a lower case letter print the correspodent lower caase of "cifer"
            if (index > 26)
            {

                char a = tolower(cifer[index - 32]);

                printf("%c", a);
            }
            // else print its upper case correspondent
            else
            {
                encripted = toupper(cifer[index]);
                printf("%c", encripted);
            }
        }
        // if its not a letter print it self
        else
        {
            encripted = sentence[i];
            printf("%c", encripted);
        }
    }
    // print a new line
    printf("\n");
    return 0;
}

// function to check for duplicated characters and invalid characters
bool check_duplicate(string str)
{
    int i, j;
    for (i = 0; i < strlen(str); i++)
    {
        for (j = 0; j < strlen(str); j++)
        {
            // if characters are same and not at the same index or if invalid return true else false
            if (((str[i] == str[j]) && (i != j)) || (str[i] > 'z' || str[i] < 'A') || (str[i] > 'Z' && str[i] < 'a'))
            {
                // returns true if duplicate or invalid is found in string else returns false
                return true;
            }
        }
    }

    return false; // returns false if no duplicate or invalid is found in string
}
