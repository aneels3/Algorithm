#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the compareTriplets function below.
def compareTriplets(a, b):
    arr = [0,0]# array to be returned as alice and bob's score respectively
    for i in range(3):
        if a[i]>b[i]:
            arr[0] = arr[0]+1
        if a[i]<b[i]:
            arr[1] = arr[1]+1
    return arr
            

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')
    a = list(map(int, input().rstrip().split()))
    b = list(map(int, input().rstrip().split()))
    result = compareTriplets(a, b)
    fptr.write(' '.join(map(str, result)))
    fptr.write('\n')
    fptr.close()
