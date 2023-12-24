#include <stdio.h>
#include <stdlib.h>

int compile(char * compile_cmd){
    char * buffer = malloc(strlen(compile_cmd)+37);
    sprintf(buffer, "%s -Xclang -ast-dump=json > ast.json");
    return system(buffer);
}