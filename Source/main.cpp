#include "../Headers/stack.h"

main()
{
    Stack_t stk =
    {
        CANARY_PROTECTION(.arbusL = 0,
                          .arbusDefault = ArbusDefault,)
        .size = -1,
        .capacity = -1,
        .data = NULL,
        .poison_v = POISON_V
        CANARY_PROTECTION(,
                          .canaryL = NULL,
                          .canaryR = NULL,
                          .canaryDefault = CanaryDefault)
        HASH_PROTECTION(,
                        .hashData = 0,
                        .hashStack = 0)
        CANARY_PROTECTION(,
                          .arbusR = 0,)
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