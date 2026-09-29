#include <stdio.h>
#include <string.h>


#define RED "\x1B[31m"
#define GREEN "\033[0;32m"
#define YELLOW  "\x1B[33m"
#define RESET "\x1B[0m"

typedef int StackElem_t;

typedef struct
{
    int size;
    int capacity;
    StackElem_t *data;
    StackElem_t poison_v;
}Stack_t;

enum ERRORS {noErr,
    stackNoInit,
    stackOverflow,
    stackUnderflow};

int InputOption(Stack_t);
void ReadInput(char *read);

int InputCapacity();
int InputPushValue();
void ClearBuf();
void PrintGOrR(bool b);


int InputCapacity()
{
    while(true)
    {
        printf("Enter capacity\n");
        int capacity = -1;
        scanf("%i", &capacity);
        ClearBuf();
        if(capacity > 0)
            return capacity;
        printf(RED "Capacity must be positive\n" RESET);
    }
}

int InputPushValue()
{
    while(true)
    {
        printf("Enter value for push\n");
        int push = 0;
        int inputN = scanf("%i", &push);
        ClearBuf();
        if(inputN == 1)
            return push;
        printf(RED "Enter one int value\n" RESET);
    }
}


void ClearBuf()
{
    char inputc = 0;
    while(inputc != '\n')
        inputc = (char)getchar();
}

int InputOption(Stack_t stk)
{
    printf(GREEN);
    printf( "Enter >init< to initialise stack\n");
    bool b1 = stk.data == NULL;
    bool b2 = stk.capacity == stk.size;
    bool b3 = stk.size == 0;

    PrintGOrR(!(b1 || b2));
    printf( "Enter >push< to push element\n");

    PrintGOrR(!(b1 || b3));
    printf("Enter >pop< to pop element\n");

    PrintGOrR(!b1);
    printf("Enter >destroy< to debosh\n" RESET);

    while(true)
    {
        char read[8] = {};
        ReadInput(read);

        if     (strcmp(read, "init") == 0)
            return 1;

        else if(strcmp(read, "push") == 0)
        {
            if(stk.data == NULL)
                printf(RED "Cant push without init\n" RESET);
            else
                return 2; 
        }

        else if(strcmp(read, "pop" ) == 0)
        {
            if(stk.data == NULL)
                printf(RED "Cant pop without init\n" RESET);
            else
                return 3; 
        }

        else if(strcmp(read, "destroy" ) == 0)
        {
            if(stk.data == NULL)
                printf(RED "Cant destroy without init\n" RESET);
            else
                return 4; 
        }

        printf(RED "Invalid input\n" RESET);
    }
}

void ReadInput(char *read)
{
    char inputc = (char)getchar();
    int i = 0;
    while(inputc != '\n' && i < 7)
    {
        read[i++] = inputc;
        inputc = (char)getchar();
    }
    read[i] = '\0';
    if(inputc != '\n')
    {
        while(inputc != '\n')
            inputc = (char)getchar();
        printf(RED "Too long input\n" RESET);
    }
}

void PrintGOrR(bool b)
{
    if(b)
        printf(GREEN);
    else
        printf(RED);
}