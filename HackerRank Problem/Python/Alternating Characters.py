#!/bin/python3

import math
import os
import random
import re
import sys
def alternatingCharacters(s):
    s=list(s)
    c=s[0]
    count=0
    for i in range(1,len(s)):
        if c == s[i]:
            count+=1
        elif c!=s[i]:
            c=s[i]
    return count 
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    q = int(input())

    for q_itr in range(q):
        s = input()

        result = alternatingCharacters(s)

        fptr.write(str(result) + '\n')

    fptr.close()
