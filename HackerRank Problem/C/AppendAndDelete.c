#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    char* s = (char *)malloc(512000 * sizeof(char));
    scanf("%s",s);
    char* t = (char *)malloc(512000 * sizeof(char));
    scanf("%s",t);
    int i,j,k; 
    scanf("%d",&k);
    int a=strlen(s);
    int b=strlen(t);
    if(a<b){
        for(i=0;i<a;i++){
            if(s[i]!=t[i]){
                break;
            }
        }
        int x=i;
        int y=a+b-2*i;
        if(a+b<=k){
            printf("Yes\n");
        }
        else if(y%2==0 && k%2==0 && k>=y){
            printf("Yes\n");
        }
        else if(y%2==1 && k%2==1 && k>=y){
            printf("Yes\n");
        }
        else{
            printf("No\n");
        }
    }
    else{
        for(i=0;i<b;i++){
            if(s[i]!=t[i]){
                break;
            }
        }
        int x=i;
        int y=a+b-2*i;
        if(a+b<=k){
            printf("Yes\n");
        }
        else if(y%2==0 && k%2==0 && k>=y){
            printf("Yes\n");
        }
        else if(y%2==1 && k%2==1 && k>=y){
            printf("Yes\n");
        }
        else{
            printf("No\n");
        }
    }
    return 0;
}