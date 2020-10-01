#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the plusMinus function below.
def plusMinus(arr):
    numb = {"pos": 0, "neg": 0, "zero": 0}
    for num in arr:
        if(num == 0):
            numb["zero"] += 1
        elif(num > 0):
            numb["pos"] += 1
        else:
            numb["neg"] += 1
    print(numb["pos"]/len(arr))
    print(numb["neg"]/len(arr))
    print(numb["zero"]/len(arr))

if __name__ == '__main__':
    n = int(input())
    arr = list(map(int, input().rstrip().split()))
    plusMinus(arr)