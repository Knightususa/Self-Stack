#include "parser.h"

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



#ifndef STACK_T_STRUCT
StackElem_t InputPushValueCID()
{
    while(true)
    {
        printf("Enter value for push\n");
        StackElem_t push = 0;
        int inputN = scanf("%" PRINTF_T, &push);
        ClearBuf();
        if(inputN == 1)
            return push;
        printf(RED "Enter one " TEXT_T_VALUE " value\n" RESET);
    }
}
#endif
//end #ifndef STACK_T_STRUCT




#ifdef STACK_T_STRUCT
StackElem_t InputPushValueS()
{
    StackElem_t value = {};
    while(true)
    {
        printf("Enter int for push\n");
        int push = 0;
        int inputN = scanf("%i", &push);
        ClearBuf();
        if(inputN == 1)
        {
            value.int_v = push;
            break;
        }
        printf(RED "Enter one int value\n" RESET);
    }

    while(true)
    {
        printf("Enter char for push\n");
        char push = 0;
        int inputN = scanf("%c", &push);
        ClearBuf();
        if(inputN == 1)
        {
            value.char_v = push;
            break;
        }
        printf(RED "Enter one char value\n" RESET);
    }

    while(true)
    {
        printf("Enter double for push\n");
        double push = 0;
        int inputN = scanf("%lg", &push);
        ClearBuf();
        if(inputN == 1)
        {
            value.double_v = push;
            break;
        }
        printf(RED "Enter one double value\n" RESET);
    }

    return value;
}
#endif
//end #ifdef STACK_T_STRUCT




void ClearBuf()
{
    char inputc = 0;
    while(inputc != '\n')
        inputc = (char)getchar();
}

enum OPTIONS InputOption(Stack_t stk)
{
    PrintWhatToInputOption(stk);

    while(true)
    {
        char read[8] = {};
        ReadInput(read);

        if     (strcmp(read, "init") == 0)
            return initStack;

        else if(strcmp(read, "push") == 0)
        {
            if(stk.data == NULL)
                printf(RED "Cant push without init\n" RESET);
            else
                return pushStack; 
        }

        else if(strcmp(read, "pop") == 0)
        {
            if(stk.data == NULL)
                printf(RED "Cant pop without init\n" RESET);
            else
                return popStack; 
        }

        else if(strcmp(read, "destroy") == 0)
        {
            if(stk.data == NULL)
                printf(RED "Cant destroy without init\n" RESET);
            else
                return destroyStack; 
        }

        printf(RED "Invalid input\n" RESET);
    }
}

void PrintWhatToInputOption(Stack_t stk)
{
    printf(GREEN);
    printf( "Enter >init< to initialise stack\n");
    bool b1 = stk.data == NULL;
    bool b2 = stk.capacity == stk.size;
    bool b3 = stk.size == 0;

    PrintGreenOrRed(!(b1 || b2));
    printf( "Enter >push< to push element\n");

    PrintGreenOrRed(!(b1 || b3));
    printf("Enter >pop< to pop element\n");

    PrintGreenOrRed(!b1);
    printf("Enter >destroy< to debosh\n" RESET);
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

void PrintGreenOrRed(bool b)
{
    if(b)
        printf(GREEN);
    else
        printf(RED);
}