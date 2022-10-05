#include <stdio.h>
#include <cs50.h>


int main(void){
    //Get the person name
    string name = get_string("What's your name? ");
    //print Hello + the name
    printf("hello, %s\n", name);
}