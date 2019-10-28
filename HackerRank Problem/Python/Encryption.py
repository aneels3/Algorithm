#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the encryption function below.
def encryption(s):
    code=s[:]
    l=len(s)
    columns=int(math.ceil(l**(0.5)))
    rows=int(columns)-1
    if rows*columns<l:
        rows=columns
        
    grid=[]
    for i in range(rows):
        grid.append(code[:columns])
        code=code[columns:]

    encrypted=''
    for i in range(columns):
        for j in range(rows):
            if i<len(grid[j]):
                encrypted+=grid[j][i]
        encrypted+=" "    

    return encrypted  

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')
    s = input()
    result = encryption(s)
    fptr.write(result + '\n')
    fptr.close()
