#!/bin/python3

import math
import os
import random
import re
import sys

def saveThePrisoner(n, m, s):
    result = (n+m+s-1)%n
    if result == 0:
        return n
    else:
        return result


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')
    t = int(input())
    for t_itr in range(t):
        nms = input().split()
        n = int(nms[0])
        m = int(nms[1])
        s = int(nms[2])
        result = saveThePrisoner(n, m, s)
        fptr.write(str(result) + '\n')
    fptr.close()
