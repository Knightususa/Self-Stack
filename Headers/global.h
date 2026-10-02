#ifndef GLOBAL_H
#define GLOBAL_H


#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

const unsigned long long ArbusDefault = 0xDEDC0CA1DEDC0CA1;


typedef struct
{
    int int_v;
    char char_v;
    double double_v;
}Struction;

#ifdef STACK_T_DOUBLE
typedef double StackElem_t;
#define POISON_V NAN
#define StackDump StackDumpCID
#define InputPushValue InputPushValueCID
#define IsValuePoison IsValuePoisonD
#define PRINTF_T "lg"
#define TEXT_T_VALUE "double"

#elif  defined(STACK_T_CHAR)
typedef char StackElem_t;
#define POISON_V '~'
#define StackDump StackDumpCID
#define InputPushValue InputPushValueCID
#define IsValuePoison IsValuePoisonCI
#define PRINTF_T "c"
#define TEXT_T_VALUE "char"

#elif  defined(STACK_T_STRUCT)
typedef Struction StackElem_t;
#define POISON_V {-1488526967, '~', NAN}
#define StackDump StackDumpS
#define InputPushValue InputPushValueS
#define IsValuePoison IsValuePoisonS

#else
typedef int StackElem_t;
#define POISON_V -1488526967
#define StackDump StackDumpCID
#define InputPushValue InputPushValueCID
#define IsValuePoison IsValuePoisonCI
#define PRINTF_T "i"
#define TEXT_T_VALUE "int"

#endif
//end STACK_T_DOUBLE or STACK_T_CHAR or STACK_T_STRUCT or else(INT)



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



typedef struct
{
    int size;
    int capacity;
    unsigned long long arbusL; //LEFT CANARY
    StackElem_t *data;
    unsigned long long arbusR; //RIGHT CANARY
    unsigned long long arbusDefault;//DEFAULT VALUE OF CANARY
    unsigned long long hashData;
    StackElem_t poison_v;
    unsigned long long hashStack;
}Stack_t;

enum ERRORS
{
    noErr,
    stackNoInit,
    stackOverflow,
    stackUnderflow,
    stackNoResize,
    dataPointerNull,
    leftCanaryKilled,
    rightCanaryKilled,
    hashDataIncorrect,
    hashStackIncorrect
};

enum OPTIONS
{
    initStack,
    destroyStack,
    pushStack,
    popStack
};


#endif
//end #ifndef GLOBAL_H