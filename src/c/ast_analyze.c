#include<stdio.h>
#include<stdlib.h>
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
int analyze_c(){
    char * text = textFileRead("/tmp/ast.json");
    cJSON * json = cJSON_Parse(text);
    //printf("%s",text);
    return 0;
}