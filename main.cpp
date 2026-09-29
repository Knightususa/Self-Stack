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
        
        if(InputMakeNewStack())
        {
            stk.capacity = InputCapacity();
            StackInit(&stk);
        }

        if(InputIsPush())
            StackPush(&stk, InputPushValue());

        if(InputIsPop())
            StackPop(&stk);
    }
}