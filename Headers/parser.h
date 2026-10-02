#ifndef PARSER_H
#define PARSER_H

#include "global.h"
#include "stack.h"

void ReadInput(char *stringToWriteInput);
void ClearBuf();
void PrintGreenOrRed(bool b);

enum OPTIONS InputOption(Stack_t stack);
void PrintWhatToInputOption(Stack_t stack);
int InputCapacity();

StackElem_t InputPushValueCID();
StackElem_t InputPushValueS();

#endif 
//end #ifndef PARSER_H