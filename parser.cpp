#include <stdio.h>

#define RED "\x1B[31m"
#define GREEN "\033[0;32m"
#define YELLOW  "\x1B[33m"
#define RESET "\x1B[0m"

bool InputMakeNewStack();
int InputCapacity();
bool InputIsPush();
bool InputIsPop();
int InputPushValue();

void ClearBuf();

bool InputMakeNewStack()
{
    printf("Enter 1 to create new stack\n");
    char inputc = 0;
    inputc = (char)getchar();

    if(inputc != '\n')
        ClearBuf();

    if(inputc == '1')
        return 1;
    return 0;
}

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

bool InputIsPush()
{
    printf("Enter 1 to push element to stack\n");
    char inputc = 0;
    inputc = (char)getchar();

    if(inputc != '\n')
        ClearBuf();

    if(inputc == '1')
        return 1;
    return 0;
}

bool InputIsPop()
{
    printf("Enter 1 to pop element from stack\n");
    char inputc = 0;
    inputc = (char)getchar();

    if(inputc != '\n')
        ClearBuf();

    if(inputc == '1')
        return 1;
    return 0;
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