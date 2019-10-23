import math
import os
import random
import re
import sys

def appendAndDelete(s, t, k):
    for i in range(min(len(s),len(t))):
        if s[i]!=t[i]:
            n=i
            break
        else:
            n=i+1
    count=len(s)-n+len(t)-n
    if k>=len(s)+len(t):
        return 'Yes'
    elif k>=count and k%2==count%2:
        return 'Yes'
    else:
        return 'No'

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')
    s = input()
    t = input()
    k = int(input())
    result = appendAndDelete(s, t, k)
    fptr.write(result + '\n')
    fptr.close()
