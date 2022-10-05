#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

bool check_s(char s);


int main(void)
{
    //get  the sentence
    string sentence = get_string("Enter your text:\n");
    //initialize the variavles of the formula
    float L = 0, S = 0, W = 0;

    //get the ammount of letters, sentences and words
    for (int i = 0; i < strlen(sentence); i++)
    {

        if(sentence[i] >= 65 && sentence[i] <= 122)
        {
            L++;
        }
        else if (check_s(sentence[i]) == true)
        {
            S++;
        }
        else if (sentence[i] == ' ')
        {
            W++;
        }
    }
    //add the last word which didnt got added in the last loop because the sentence doesnt have a space at the end
    W++;
    //use the formula
    float letters = 100 * L / W;
    float Set = 100 * S / W;
    float let = letters * 0.0588, sen = Set * 0.296;
    int index = round(let - sen - 15.8);
    //print the results
    if (index < 1){
        printf("Before Grade 1\n");
        return 0;
    }
    else if(index < 16){
        printf("Grade %i\n", index);
        return 0;
    }
    printf("Grade 16+\n");
    return 0;
}

bool check_s(char s){
    string sent = ".!?";
    for (int i = 0; i < strlen(sent); i++)
    {
        if (sent[i] == s)
        {
            return true;
        }
    }
    return false;
}