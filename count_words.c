#include <stdio.h>
#include <unistd.h>

//named constants
    #define IN 1 // inside a word
    #define OUT 0 // outside a word

int ft_count(const char *str)
{
    int i;
    int new_word;
    int state;

    i = 0;
    new_word = 0;
    state = OUT; //initializing the state, which is out before a new word
    while (str[i] != '\0')
    {
        if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
            state = OUT; 
        else if(state == OUT)
        {
            state = IN;
            new_word++;
        }
        i++;
    }
    return(new_word);
}

void print_first_word(const char *str)
{
    int i;
    i = 0;
    int lengh;
    lengh = 0;
    while (str[i] != ' ')
    {   
        lengh++;
    }
    while (str[i] < i)
    {
        write(1, &str[i], lengh);
        i++;
    }
}

//int ft_digit_check(const char *str) this function will check if only one integer was given as input


int main (int argc, char *argv[])
{
    if (argc != 2 /*|| ft_digit_check(argv[1])*/)
    {
        printf("Error, please type in a sentence as a string\n");
    }
    else
    {
        int result;
        result = ft_count(argv[1]);
        printf("total amount of words: %i\n", result);
        print_first_word(argv[1]);

    }
    return (0); 
}