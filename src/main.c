#include<stdio.h>
#include "args.h"
char * _global_compile_cmd = 0;
char * honggfuzz_bin;
int main(char *argv[], int argc){
    int arg = parse_arg(argv, argc);
    if(ISSET(arg, ARG_HELP)||ISSET(arg, ARG_VERSION)){
        //Already done, can return
        return 0;
    }
    if(ISSET(arg, ARG_RUN_HONGGFUZZ)){
        //TODO
        if(fork()){

        }
    }
    if(!_global_compile_cmd){
        //TODO: Auto compile
    }
    compile_c(_global_compile_cmd);
    analyze_c();
    return 0;
}