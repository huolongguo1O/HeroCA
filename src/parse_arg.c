#include "args.h"
int parse_arg(char *argv[], int argc){
    int i;
    int ret;
    for(i = 1; i < argc; i++){
        // 检查参数是否以"-"开头
        if(argv[i][0] == '-' && argv[i][1] != '\0'){
            // 检查参数是否为合法的选项
            if(strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0){
                // 处理帮助选项
                ret |= ARG_HELP;
                printf("");
                return 1;
            }
            else if(strcmp(argv[i], "-v") == 0 || strcmp(argv[i], "--version") == 0){
                ret |= ARG_VERSION;
            }
            // source compile command
            else if(strcmp(argv[i], "-c") == 0 || strcmp(argv[i], "--compile") == 0){
                //ret |= ARG_COMPILE;
                _global_compile_cmd = malloc(strlen(argv[i+1]));
                strcpy(_global_compile_cmd, argv[i+1]);
                i++;
            }
            // source run command
            else if(strcmp(argv[i], "-r") == 0 || strcmp(argv[i], "--run-honggfuzz") == 0){
                ret |= ARG_RUN_HONGGFUZZ;
            }
            // source debug command
            
        }
    }
    return ret;
}