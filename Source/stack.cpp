#include "stack.h"

enum ERRORS StackInit(Stack_t *stk)
{
    stk->capacity = InputCapacity();

    if (stk->capacity <= 0)
    {
        printf(RED "\nCapacity must be > 0\n" RESET);
        return stackNoInit;
    }

    stk->data = (StackElem_t *)calloc(stk->capacity, sizeof(StackElem_t));

    if (stk->data == NULL)
    {
        printf(RED "\nCan't create stack(\n\n" RESET);
        return stackNoInit;
    }
    stk->size = 0;

    for (int i = 0; i < stk->capacity; i++)
        stk->data[i] = stk->poison_v;
    printf(MAGENTA "\nCreate and initialize stack successfully\n\n" RESET);
    yaissert(StackDump(stk));

    return noErr;
}

enum ERRORS StackDestroy(Stack_t *stk)
{
    if(stk->data == NULL)
    {
        printf(RED "\nPointer to data is NULL when trying to destroy\n\n" RESET);
        return dataPointerNull;
    }
    yaissert(Verificator(stk));
    
    for (int i = 0; i < stk->capacity; i++)
    stk->data[i] = stk->poison_v;
    // printf("data")
    free(stk->data);
    stk->data = NULL;
    stk->size = -1;
    stk->capacity = -1;
    printf(MAGENTA "\nDestroy stack successfully\n\n" RESET);
    return noErr;
}

enum ERRORS StackPush(Stack_t *stk, StackElem_t elem)
{
    if(stk->data == NULL)
    {
        printf(RED "\nPointer to data is NULL when trying to push\n\n" RESET);
        return dataPointerNull;
    }
    yaissert(Verificator(stk));
    enum ERRORS resizeUp = noErr;

    if (stk->size == stk->capacity)
        resizeUp = ResizeUp(stk);

    if(resizeUp == stackOverflow)
        return stackOverflow;

    stk->data[stk->size++] = elem;
    printf(MAGENTA "\nSuccessfully pushed\n\n" RESET);
        
    yaissert(StackDump(stk));

    return resizeUp;
}

enum ERRORS StackPop(Stack_t *stk)
{
    if(stk->data == NULL)
    {
        printf(RED "\nPointer to data is NULL when trying to pop\n\n" RESET);
        return dataPointerNull;
    }
    yaissert(Verificator(stk));

    if (stk->size <= 0)
    {
        printf(RED "\nStack underflow\n\n" RESET);
        stk->size = 0;
        return stackUnderflow;
    }

    stk->size--;
    stk->data[stk->size] = stk->poison_v;
    printf(MAGENTA "\nSuccessfully poped\n\n" RESET);

    enum ERRORS resizeDown = ResizeDown(stk);

    yaissert(StackDump(stk));

    return resizeDown;
}

enum ERRORS ResizeUp(Stack_t *stk)
{
    int cap = stk->capacity;
    void *dataNew = realloc(stk->data, sizeof(StackElem_t) * (cap * 2));
    
    if(dataNew == NULL)
    {
        printf(RED "\nCant resize up stack\n\n" RESET);
        return stackOverflow;
    }

    stk->capacity = stk->capacity * 2;
    stk->data = (StackElem_t *) dataNew; 

    for(int i = cap; i < cap * 2; i++)
        stk->data[i] = stk->poison_v;

    printf(MAGENTA "\nResize up stack\n\n" RESET);
    return noErr;
}

enum ERRORS ResizeDown(Stack_t *stk)
{
    if(stk->capacity <= stk->size * 4)
        return noErr;

    void *dataNew = realloc(stk->data, sizeof(StackElem_t) * (stk->capacity / 2));
    if(dataNew == NULL)
    {
        printf(RED "\nCant resize down stack\n\n" RESET);
        return stackNoResize;
    }

    stk->data = (StackElem_t *) dataNew;
    stk->capacity /= 2;
    printf(MAGENTA "\nResize down stack\n\n" RESET);
    return noErr;
}

bool Verificator(Stack_t *stk)
{
    printf(MAGENTA);
    if (stk->data == NULL)
    {
        printf("Pointer to data is NULL\n" RESET);
        return 0;
    }

    if (stk->capacity <= 0)
    {
        printf("Capacity of data <= 0\n" RESET);
        StackDump(stk);
        return 0;
    }

    if (stk->capacity < stk->size)
    {
        printf("Capacity less than size\n" RESET);
        StackDump(stk);
        return 0;
    }

    for (int i = 0; i < stk->size; i++)
    {
        if (IsValuePoison(*stk, stk->data[i]))
        {
            printf("Element of data number %i is poison value\n" RESET, i);
            StackDump(stk);
            return 0;
        }
    }

    for (int j = stk->size; j < stk->capacity; j++)
    {
        if (!IsValuePoison(*stk, stk->data[j]))
        {
            printf("Element of data with index %i not a poison value\n" RESET, j);
            StackDump(stk);
            return 0;
        }
    }
    return 1;
}