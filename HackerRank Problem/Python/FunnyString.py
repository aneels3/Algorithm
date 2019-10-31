#!/bin/python

# URL: https://www.hackerrank.com/challenges/funny-string/problem

import math
import os
import random
import re
import sys

# Complete the funnyString function below.
def funnyString(s):
    funny = False
    r = s[::-1]
    print r

    s_ascii = list(map(lambda c: ord(c), s))
    r_ascii = list(map(lambda c: ord(c), r))
    s_diff = []
    r_diff = []

    for i in range(len(s_ascii)):
        if i == len(s_ascii) - 1: break
        s_diff.append(abs(s_ascii[i] - s_ascii[i + 1]))
        r_diff.append(abs(r_ascii[i] - r_ascii[i + 1]))

    print s_diff
    print r_diff
    if s_diff == r_diff: funny = True

    return "Funny" if funny else "Not Funny"

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    q = int(raw_input())

    for q_itr in xrange(q):
        s = raw_input()

        result = funnyString(s)

        fptr.write(result + '\n')

    fptr.close()
