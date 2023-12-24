#define ARG_HELP 1
#define ARG_VERSION 2
#define ARG_RUN_HONGGFUZZ 4

#define ISSET(var, bit) (((var) & (~bit)) != var)