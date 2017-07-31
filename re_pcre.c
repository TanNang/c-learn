#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcre.h>

#define RMSIZE 20

int main(int argc, char *argv[]){
    if(argc != 3){
        printf("usage: %s <pattern> <str>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *pattern = argv[1];
    const char *str = argv[2];
    const char *errmsg = NULL;
    int erroffset = -1;
    int rmoffsets[RMSIZE] = {0};

    pcre *re = NULL;
    int cflags = PCRE_EXTENDED + PCRE_MULTILINE;
    //int cflags = PCRE_EXTENDED + PCRE_DOTALL;

    re = pcre_compile(pattern, cflags, &errmsg, &erroffset, NULL);

    if(re == NULL){
        printf("erroffset: %d, errmsg: %s\n", erroffset, errmsg);
        exit(EXIT_FAILURE);
    }

    int status = pcre_exec(re, NULL, str, strlen(str), 0, 0, rmoffsets, RMSIZE);

    printf("pattern: \"%s\"\nstr: \"%s\"\n", pattern, str);

    if(status < 0){
        printf("no match!\n");
    }else if(status > 0){
        printf("match_str: \"%.*s\"\n", rmoffsets[1]-rmoffsets[0], str+rmoffsets[0]);

        int subc = 0;
        for(int i=0; i<(signed int)strlen(pattern); i++){
            if(pattern[i] == '('){
                subc++;
            }
        }

        for(int i=1; i<=subc; i++){
            printf("sub%d_str: \"%.*s\"\n", i, rmoffsets[i*2+1]-rmoffsets[i*2], str+rmoffsets[i*2]);
        }
    }

    pcre_free(re);

    return 0;
}
