#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

#define RMSIZE 20

int main(int argc, char *argv[]){
    if(argc != 3){
        printf("usage: %s <pattern> <str>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *pattern = argv[1];
    const char *str = argv[2];
    regmatch_t regmatch[RMSIZE];

    regex_t re;
    int cflags = REG_EXTENDED;
    //int cflags = REG_EXTENDED + REG_NEWLINE;

    regcomp(&re, pattern, cflags);

    int status = regexec(&re, str, RMSIZE, regmatch, 0);

    printf("pattern: \"%s\"\nstr: \"%s\"\n", pattern, str);

    if(status == REG_NOMATCH){
        printf("no match!\n");
    }else if(status == 0){
        printf("match_str: \"%.*s\"\n", regmatch[0].rm_eo-regmatch[0].rm_so, str+regmatch[0].rm_so);

        int subc = 0;
        for(int i=0; i<(signed int)strlen(pattern); i++){
            if(pattern[i] == '('){
                subc++;
            }
        }

        for(int i=1; i<=subc; i++){
            printf("sub%d_str: \"%.*s\"\n", i, regmatch[i].rm_eo-regmatch[i].rm_so, str+regmatch[i].rm_so);
        }
    }

    regfree(&re);

    return 0;
}
