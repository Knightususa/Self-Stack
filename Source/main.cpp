#include "../Headers/stack.h"

main()
{
    Stack_t stk =
    {
        .size = -1,
        .capacity = -1,
        .arbusL = 0,
        .data = NULL,
        .arbusR = 0,
        .arbusDefault = ArbusDefault,
        .hashData = 0,
        .poison_v = POISON_V,
        .hashStack = 0
    };

    while(true)   
    {
        int inputOption = InputOption(stk);
        if(inputOption == initStack)
        {
            stk.capacity = InputCapacity();
            StackInit(&stk);
        }

        else if(inputOption == pushStack)
            StackPush(&stk, InputPushValue());

        else if(inputOption == popStack)
            StackPop(&stk);

        else if(inputOption == destroyStack)
            StackDestroy(&stk);
    }
}