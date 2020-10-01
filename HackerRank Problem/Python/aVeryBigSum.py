#!/bin/python3

import os


# Complete the aVeryBigSum function below.
def aVeryBigSum(ar):
    b = 0
    for i in range(0, ar_count):
        b = b+ar[i]
    return b


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')
    ar_count = int(input())
    ar = list(map(int, input().rstrip().split()))
    result = aVeryBigSum(ar)
    fptr.write(str(result) + '\n')
    fptr.close()
