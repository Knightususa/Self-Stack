#include "../Headers/stack.h"

main()
{
    Stack_t stk =
    {
        .size = -1,
        .capacity = -1,
        .data = NULL,
        .poison_v = POISON_V
    };

    while(true)   
    {
        int inputOption = InputOption(stk);
        if(inputOption == initStack)
            StackInit(&stk);

        else if(inputOption == pushStack)
            StackPush(&stk, InputPushValue());

        else if(inputOption == popStack)
            StackPop(&stk);

        else if(inputOption == destroyStack)
            StackDestroy(&stk);
    }
}