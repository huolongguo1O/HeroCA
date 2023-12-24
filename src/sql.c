//TODO
#include "cJSON.h"
extern struct _ast_linear * ast_linear;
struct _ast_linear{
    cJSON * this;
    struct _ast_linear * next;
};
char * parse_sql(char * sql);
// HCA SQL GRAMMAR
// 1. SELECT
//    Format: SELECT (results) WHERE (conditions)
//    1.results: Things you need;
//    2.conditions: This function will return a list of results that satisfy the conditions like "kind == VarDecl"
char * execute_sql(char * sql){
    if(memcmp(sql, "SELECT", 6) == 0){
        int pos_condi = strstr(sql, "WHERE") - (int) sql + 6;

    }
}

typedef struct sql_result{
    cJSON * result;
    struct sql_result * next
}sql_result;

sql_result * find_eq_str(char * key, char * value){
    sql_result * ret = 0;
    sql_result * ret_now = ret;
    struct _ast_linear * now = ast_linear;
    while(now != 0){
        cJSON * _value = cJSON_GetObjectItem(now, key);
        if(_value -> valuestring){
            if (strcmp(_value -> valuestring, value) == 0){
                if(ret == 0){
                    ret = now -> this;
                    ret_now = ret;
                }else{
                    ret_now -> next = now -> this;
                    ret_now = ret_now -> next;
                }
            }
        }
    }
}
sql_result * find_eq_int(char * key, int value){}