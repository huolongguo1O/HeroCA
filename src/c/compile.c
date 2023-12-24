#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compile_c(char * compile_cmd){
    char * buffer = malloc(strlen(compile_cmd)+37);
    sprintf(buffer, "%s -Xclang -ast-dump=json > /tmp/ast.json",  compile_cmd);
    return system(buffer);
}