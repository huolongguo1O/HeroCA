#include<stdio.h>
#include<stdlib.h>
#include "../cJSON.h"
cJSON * ast = 0;
struct _ast_linear{
    cJSON * this;
    struct _ast_linear * next;
} * ast_linear;
char* textFileRead(char* filename)
{
    char* text;
    FILE *pf = fopen(filename,"r");
    fseek(pf,0,SEEK_END);
    long lSize = ftell(pf);
    text=(char*)malloc(lSize+1);
    rewind(pf); 
    fread(text,sizeof(char),lSize,pf);
    text[lSize] = '\0';
    return text;
}
struct _ast_linear * to_linear(cJSON * _ast){
    cJSON * inner = cJSON_GetObjectItem(_ast,"inner");
    struct _ast_linear * head = 0;
    struct _ast_linear * now = 0;
    for(int i = 0; i < cJSON_GetArraySize(inner); i++){
        struct _ast_linear * new = malloc(sizeof(struct _ast_linear));
        new -> this = cJSON_GetArrayItem(inner,i);
        // new -> next = head;
        if(i == 0) 
            head = new;
        now -> next = new;
        now = new;
        if (cJSON_GetArraySize(cJSON_GetObjectItem(cJSON_GetArrayItem(inner,i),"inner")) > 0){
            now -> next = to_linear(cJSON_GetArrayItem(inner,i));
        }
    }
    return head;
}
int analyze_c(){
    char * text = textFileRead("/tmp/ast.json");
    ast = cJSON_Parse(text);
    ast_linear = to_linear(ast);
    return ast;
}