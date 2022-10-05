#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    //get the card number
    long number = get_long("Enter your credit card number: ");
    int sum;
    //get the  length
    int count = 0;
    long cc = number;
    while (cc > 0)
    {
        cc = cc / 10;
        count++;
    }
    if (count != 13 && count != 15 && count != 16)
    {
        printf("INVALID\n");
        return 0;
    }
    //calculate the sum
    int sum1 = 0;
    int sum2 = 0;
    long x = number;
    int total = 0;
    int mod1;
    int mod2;
    int d1;
    int d2;
    do
    {
        // Remove last digit and add to sum1
        mod1 = x % 10;
        x = x / 10;
        sum1 = sum1 + mod1;
        // Remove second last digit
        mod2 = x % 10;
        x = x / 10;
        // Double second last digit and add digits to sum2
        mod2 = mod2 * 2;
        d1 = mod2 % 10;
        d2 = mod2 / 10;
        sum2 = sum2 + d1 + d2;
    }
    while (x > 0);


    // Get starting digits
    long start = number;
    do
    {
        start = start / 10;
    }
    while (start > 100);

    total = sum1 + sum2;

    // check Luhn Algorithm
    if (total % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    bool a = count == 13 || count == 16;

    // Check for mastercard
    if ((start / 10 == 5) && (0 < start % 10 && start % 10 < 6))
    {
        printf("MASTERCARD\n");
    }
    //check for amex
    else if ((start / 10 == 3) && (start % 10 == 4 || start % 10 == 7))
    {
        printf("AMEX\n");
    }
    //check for visa
    else if (start / 10 == 4 && a == true)
    {

        printf("VISA\n");
    }
    //if no one of these gets checked, the card is invalid
    else
    {
        printf("INVALID\n");
        return 0;
    }
}
