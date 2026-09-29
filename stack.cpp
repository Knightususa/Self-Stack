#include "parser.cpp"
#include <assert.h>
#include <errno.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef ISDEBUG
#define yaissert(usl)                                                                                                  \
    if (!(usl))                                                                                                        \
    {                                                                                                                  \
        printf("Assertion failed: " #usl ", function %s, file %s:%i\n", __func__, __FILE_NAME__, __LINE__);            \
        abort();                                                                                                       \
    }
#else
#define yaissert(usl)
#endif

bool Verificator(Stack_t *stk);
enum ERRORS StackInit(Stack_t *stk);
enum ERRORS StackDestroy(Stack_t *stk);
enum ERRORS StackPush(Stack_t *stk, StackElem_t elem);
enum ERRORS StackPop(Stack_t *stk);
int PrintStack(Stack_t *stk);

enum ERRORS StackInit(Stack_t *stk)
{
    stk->capacity = InputCapacity();

    if (stk->capacity <= 0)
    {
        printf("Capacity must be > 0\n");
        return stackNoInit;
    }

    stk->data = (StackElem_t *)calloc(stk->capacity, sizeof(StackElem_t));

    if (stk->data == NULL)
    {
        printf(RED "Can't create stack(\n\n" RESET);
        return stackNoInit;
    }
    stk->size = 0;

    for (int i = 0; i < stk->capacity; i++)
        stk->data[i] = stk->poison_v;

    yaissert(PrintStack(stk));

    return noErr;
}

enum ERRORS StackDestroy(Stack_t *stk)
{
    yaissert(Verificator(stk));

    for (int i = 0; i < stk->capacity; i++)
        stk->data[i] = stk->poison_v;

    free(stk->data);
    stk->data = NULL;
    stk->size = -1;
    stk->capacity = -1;
    return noErr;
}

enum ERRORS StackPush(Stack_t *stk, StackElem_t elem)
{
    yaissert(Verificator(stk));

    if (stk->size == stk->capacity)
    {
        printf(RED "Stack overflow\n\n" RESET);
        return stackOverflow;
    }
    stk->data[stk->size++] = elem;

    yaissert(PrintStack(stk));

    return noErr;
}

enum ERRORS StackPop(Stack_t *stk)
{
    yaissert(Verificator(stk));

    if (stk->size == 0)
    {
        printf(RED "Stack underflow\n\n" RESET);
        return stackUnderflow;
    }
    stk->size--;
    stk->data[stk->size] = stk->poison_v;

    yaissert(PrintStack(stk));

    return noErr;
}

bool Verificator(Stack_t *stk)
{
    printf(YELLOW);
    if (stk->data == NULL)
    {
        printf("Pointer to data is NULL\n");
        return 0;
    }

    if (stk->capacity <= 0)
    {
        printf("Capacity of data <= 0\n");
        return 0;
    }

    if (stk->capacity < stk->size)
    {
        printf("Capacity less than size\n");
        return 0;
    }

    for (int i = 0; i < stk->size; i++)
    {
        if (stk->data[i] == stk->poison_v)
        {
            printf("Element of data number %i is poison value\n", i);
            return 0;
        }
    }

    for (int j = stk->size; j < stk->capacity; j++)
    {
        if (stk->data[j] != stk->poison_v)
        {
            printf("Element of data with index %i not a poison value\n", j);
            return 0;
        }
    }
    printf(RESET);
    return 1;
}

int PrintStack(Stack_t *stk)
{
    printf(YELLOW "DEBUG | capacity = %i\n", stk->capacity);
    printf("DEBUG | size     = %i\n", stk->size);
    printf("DEBUG | poison_v = %i\n", stk->poison_v);
    for (int i = 0; i < stk->capacity; i++)
        printf("DEBUG | %p | %i |\n", &(stk->data[i]), stk->data[i]);
    printf("DEBUG | [");
    for (int i = 0; i < stk->capacity; i++)
    {
        printf(" %i", stk->data[i]);
        if(i != stk->capacity - 1)
            printf(",");
    }
    printf("]\n");
    printf(RESET);
    return 1;
}