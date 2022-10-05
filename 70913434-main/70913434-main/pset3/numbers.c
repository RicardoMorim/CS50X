#include <stdio.h>
#include <cs50.h>
#include <string.h>


typedef struct
{
    string name;
    string number;
}
person;


int main(void)
{
    //tamanho da array
    const int num = get_int("numero de numeros: \n");
    
    person people[num];
    
    for (int i = 0; i < num; i++)
    {
        //contruir e organizar as arrays
        people[i].name = get_string("Name: \n");
        people[i].number = get_string("Number: \n");
    } 
    
    //nome e numero a encontrar
    string name2find = get_string("Name to find: \n");
    for (int i = 0; i < num; i++)
    {
        //encontrar o numero
        if (strcmp(people[i].name, name2find) == 0)
        {
            printf("found: %s: %s\n", people[i].name, people[i].number);
            return 0;
        }
        
    }
    //se não encontrar 
    printf("Not found\n");
    return 1;
        
}