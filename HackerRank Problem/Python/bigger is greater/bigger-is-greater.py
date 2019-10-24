
import math
import os
import random
import re
import sys

# Complete the biggerIsGreater function below.
def biggerIsGreater(w):
    w = [letter for letter in w.split()[0]]
    sizeW = len(w)
    for i in range((sizeW-2), -1, -1):
        for j in range((i+1), sizeW):
            if(w[i]<w[j]):
                tmp = w[i]
                w[i] = w[j]
                w[j] = tmp
                return ''.join(w)

        for j in range(i, sizeW-1):
            if(w[j]>w[j+1]):
                tmp = w[j]
                w[j] = w[j+1]
                w[j+1] = tmp
    return "no answer"
if __name__ == '__main__':
    fptr = open('input.txt')

    T = int(fptr.readline())

    for T_itr in range(T):
        w = fptr.readline()

        result = biggerIsGreater(w)
        print(result)

    fptr.close()

