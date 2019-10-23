// Solution for Angry Professor 
// Link: https://www.hackerrank.com/challenges/angry-professor/problem

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    
    int x,j;
    scanf("%d",&x) ;
    for(j=0;j<x;j++){
        
        int n,k,a[1005],i,p=0;
        signed int t ; 
        scanf("%d %d",&n,&k);
        for(i=0;i<n;i++){
            scanf("%d",&t) ;
            if(t<=0)
            p++ ;
        }
    if(p>=k)
        printf("NO\n") ;
    else
        printf("YES\n")  ;
            
    }
    return 0;
}
