#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the miniMaxSum function below.
def miniMaxSum(arr):
    max, min, sum = 0, 0 ,0
    for num in arr:
        sum += num
    for i in range(len(arr)):
        iSum = sum - arr[i]
        if(i == 0):
            max, min = iSum, iSum
        if(max < iSum):
            max = iSum
        if(min > iSum):
            min = iSum
    print("" + str(min) + " " + str(max))

if __name__ == '__main__':
    arr = list(map(int, input().rstrip().split()))
    miniMaxSum(arr)