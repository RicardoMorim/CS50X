#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    //force the user to give a correct value to the hight
    do
    {
        height = get_int("Choose the height of the piramide: ");
    }
    while (8 < height || height < 1);

    //print the piramide
    for (int i = 0; i < height; i++)
    {
        //print the speces in the left side
        for (int j = 0; j < height - i - 1; j++)
        {
            printf(" ");
        }
        //print the "#"
        for (int j = height - i; j <= height; j++)
        {
            printf("#");
        }
        //print the middle spaces
        printf("  ");
        //print the "#" on the right side
        for (int j = height - i; j <= height; j++)
        {
            printf("#");
        }
        //go to a new line
        printf("\n");
    }
}