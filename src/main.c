#include<stdio.h>
#include "args.h"
char * _global_compile_cmd;
int main(char *argv[], int argc){
    int arg = parse_arg(argv, argc);
    if(ISSET(arg, ARG_HELP)||ISSET(arg, ARG_VERSION)){
        //Already done, can return
        return 0;
    }
    if(ISSET(arg, ARG_RUN_HONGGFUZZ)){
        //TODO
        
    }
}