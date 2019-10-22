#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the fibonacciModified function below.
def fibonacciModified(t1, t2, n):
    if(n==1):
        return t2
    elif(n==0):
        return t1
    else:
        a=fibonacciModified(t1,t2,n-2)
        b=fibonacciModified(t1,t2,n-1)
        n=a+b*b
        return n

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t1T2n = input().split()

    t1 = int(t1T2n[0])

    t2 = int(t1T2n[1])

    n = int(t1T2n[2])

    #if(t1==0 and t2==1):
    result = fibonacciModified(t1, t2, n-1)
    #elif(t1==1 and t2==1):
    #    result = fibonacciModified(t1, t2, n)
    #elif(t1==1 and t2==2):
    #    result = fibonacciModified(t1, t2, n+1)

    fptr.write(str(result) + '\n')

    fptr.close()
