#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the staircase function below.
def staircase(n):
    staircase = []
    for i in range(1,n+1):
        staircase.append((n-i)*" " + (i)*"#")
    sys.stdout.write('\n'.join(staircase))

if __name__ == '__main__':
    n = int(input())
    staircase(n)