
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
}