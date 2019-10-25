// Solution for Counting Valleys problem
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int 
countingValleys(int n, char* s) {
    int count = 0, level = 0;
    int i;
    for(i = 0; i < n; i++) {
        if(s[i] == 'D') {
            level--;
        }
        else {
            level++;
            if(level == 0) {
                count++;
            }
        }
    }
    return count;
}

int 
main(int argc, char *argv[]) {
    if(argc == 2) {
        int len = strlen(argv[1]);
        char *str = (char *)malloc((len+1) * sizeof(char));
        memcpy(str, argv[1], len+1);

        int valleys = countingValleys(len, str);
        
        printf("Path: %s\n", str);
        printf("Valley's crossed: %d\n", valleys);
        free(str);
    }
    return 0;
}
