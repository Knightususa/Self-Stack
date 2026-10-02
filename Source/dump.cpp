#include "../Headers/dump.h"


#ifndef STACK_T_STRUCT
//CI - CHAR or INT
bool IsValuePoisonCI(Stack_t stk, StackElem_t value)
{
    if(value == stk.poison_v)
        return true;
    return false;
}

//D - DOUBLE
bool IsValuePoisonD(Stack_t stk, StackElem_t value)
{
    if(isnan(stk.poison_v) && isnan(value))
        return true;
    else if(stk.poison_v == value)
        return true;
    return false;
}

//CID - CHAR or INT or DOUBLE
int StackDumpCID(Stack_t *stk)
{
    printf(YELLOW "DEBUG |Index| Pointer          | Value\n");
    printf(YELLOW "DEBUG |" CYAN "     | %p | capacity  = %i\n", &(stk->capacity), stk->capacity);
    printf(YELLOW "DEBUG |" CYAN "     | %p | size      = %i\n", &(stk->size), stk->size);
    printf(YELLOW "DEBUG |" CYAN "     | %p | poison_v  = %" PRINTF_T "\n", &(stk->poison_v), stk->poison_v);
    printf(YELLOW "DEBUG |" CYAN "     | %p | hashData  = %llu\n", &(stk->hashData), stk->hashData);
    printf(YELLOW "DEBUG |" CYAN "     | %p | hashStack = %llu\n", &(stk->hashStack), stk->hashStack);
    printf(YELLOW "DEBUG |" CYAN "-----|------------------|----------------------\n");
    for (int i = 0; i < stk->capacity; i++)
    {
        printf(YELLOW "DEBUG |" CYAN " [%i] | %p | %" PRINTF_T " | ", i, &(stk->data[i]), stk->data[i]);
        if(i < stk->size)
            printf(GREEN "*\n");
        else
            printf(RED "*\n");
    }
    printf(YELLOW "DEBUG |\n");
    printf(YELLOW "DEBUG | " CYAN "[");
    for (int i = 0; i < stk->capacity; i++)
    {
        printf("%" PRINTF_T, stk->data[i]);
        if(i != stk->capacity - 1)
            printf(", ");
    }
    printf("]\n");
    printf(RESET);
    return 1;
}
#endif 
//end #ifndef STACK_T_STRUCT



//-------------------------------------------------------------------
//-------------------------------------------------------------------
//-------------------------------------------------------------------



#ifdef STACK_T_STRUCT
//S - STRUCT
bool IsValuePoisonS(Stack_t stk, StackElem_t value)
{
    if((isnan(stk.poison_v.double_v) && isnan(value.double_v)) || (stk.poison_v.double_v == value.double_v))
    {
        if(stk.poison_v.int_v == value.int_v)
        {
            if(stk.poison_v.char_v == value.char_v)
                return true;
        }
    }
    return false;
}

//S - STRUCT
int StackDumpS(Stack_t *stk)
{
    printf(YELLOW "DEBUG |Index| Pointer          | Value\n");
    printf(YELLOW "DEBUG |" CYAN "     | %p | capacity = %i\n", &(stk->capacity), stk->capacity);
    printf(YELLOW "DEBUG |" CYAN "     | %p | size     = %i\n", &(stk->size), stk->size);
    printf(YELLOW "DEBUG |" CYAN "     | %p | poison_v.int_v    = %i\n",  &(stk->poison_v.int_v), stk->poison_v.int_v);
    printf(YELLOW "DEBUG |" CYAN "     | %p | poison_v.char_v   = %c\n",  &(stk->poison_v.char_v), stk->poison_v.char_v);
    printf(YELLOW "DEBUG |" CYAN "     | %p | poison_v.double_v = %lg\n", &(stk->poison_v.double_v), stk->poison_v.double_v);
    printf(YELLOW "DEBUG |" CYAN "-----|------------------|----------------------\n");
    for (int i = 0; i < stk->capacity; i++)
    {
        printf(YELLOW "DEBUG |" CYAN " [%i] | %p | %i, %c, %lg | ", i, &(stk->data[i]), stk->data[i].int_v, stk->data[i].char_v, stk->data[i].double_v);
        if(i < stk->size)
            printf(GREEN "*\n");
        else
            printf(RED "*\n");
    }
    printf(YELLOW "DEBUG |\n");
    printf(YELLOW "DEBUG | " CYAN "[");
    for (int i = 0; i < stk->capacity; i++)
    {
        printf("(%i, %c, %lg)", stk->data[i].int_v, stk->data[i].char_v, stk->data[i].double_v);
        if(i != stk->capacity - 1)
            printf(", ");
    }
    printf("]\n");
    printf(RESET);
    return 1;
}
#endif 
//end #ifdef STACK_T_STRUCT