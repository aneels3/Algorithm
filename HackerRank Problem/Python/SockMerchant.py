#!/bin/python3

import math
import os
import random
import re
import sys


def bubble_sort(nums):
    # We set swapped to True so the loop looks runs at least once
    swapped = True
    while swapped:
        swapped = False
        for i in range(len(nums) - 1):
            if nums[i] > nums[i + 1]:
                # Swap the elements
                nums[i], nums[i + 1] = nums[i + 1], nums[i]
                # Set the flag to True so we'll loop again
                swapped = True
    return nums

# Complete the sockMerchant function below.
def sockMerchant(n, ar):
    count = 0
    ar = bubble_sort(ar)
    i = 0
    while i < n-1 :
        if ar[i] == ar[i+1]:
            count = count + 1
            i = i + 2 
        else:
            i = i+1    
    return count

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')
    n = int(input())
    ar = list(map(int, input().rstrip().split()))
    result = sockMerchant(n, ar)
    fptr.write(str(result) + '\n')
    fptr.close()
