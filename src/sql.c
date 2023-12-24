//TODO
#include "cJSON.h"
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
    struct _ast_linear *now = ast_linear;
    while(now != 0){
        cJSON * _value = cJSON_GetObjectItem(now, key);
        if(_value -> valuestring){
            if (strcmp(_value -> valuestring, value) == 0){
                return now;
            }
        }
    }
}
sql_result * find_eq_int(char * key, int value){}