#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>

#include <math.h>
#include <stdbool.h>
#include <string.h>

#include <assert.h>
#include <errno.h>

#include "global.h"
#include "dump.h"
#include "parser.h"



bool Verificator(Stack_t *stack);

enum ERRORS StackInit(Stack_t *stack);
enum ERRORS StackDestroy(Stack_t *stack);
enum ERRORS StackPush(Stack_t *stack, StackElem_t valueToPush);
enum ERRORS StackPop(Stack_t *stack);

enum ERRORS ResizeUp(Stack_t *stack);
enum ERRORS ResizeDown(Stack_t *stack);

#endif
//end #ifndef STACK_H