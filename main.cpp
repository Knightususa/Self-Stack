#include "stack.cpp"

main()
{
    Stack_t stk = { .size = -1,
                    .capacity = -1,
                    .data = NULL,
                    .poison_v = -1488695267};

    printf(RESET);
    while(true)   
    {
        int inputOption = InputOption(stk);
        if(inputOption == 1)
            StackInit(&stk);

        if(inputOption == 2)
            StackPush(&stk, InputPushValue());

        if(inputOption == 3)
            StackPop(&stk);

        if(inputOption == 4)
            StackDestroy(&stk);
    }
}