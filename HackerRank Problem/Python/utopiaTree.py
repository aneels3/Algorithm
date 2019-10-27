'''
"The Utopian Tree"  goes through 2 cycles of growth every year. Each spring, it doubles in height. Each summer, its height increases by 1 meter.

Laura plants a Utopian Tree sapling with a height of 1 meter at the onset of spring. How tall will her tree be after  growth cycles?

For example, if the number of growth cycles is , the calculations are as follows:

Period  Height
0          1
1          2
2          3
3          6
4          7
5          14
Function Description

Complete the utopianTree function in the editor below. It should return the integer height of the tree after the input number of growth cycles.

utopianTree has the following parameter(s):

n: an integer, the number of growth cycles to simulate
Input Format

The first line contains an integer, , the number of test cases.
 subsequent lines each contain an integer, , denoting the number of cycles for that test case.
'''

#solution:

import math
import os
import random
import re
import sys


def utopia(x):
    condition = False
    count = 0
    for j in range(x+1):
        if(condition == False):
            count+=1
            condition = True
        else:
            count*=2
            condition = False
    return count

if __name__ == '__main__':
    tree = open(os.environ['OUTPUT_PATH'], 'w')
    t = int(input())
    for i in range(t):
        x = int(input())
        result = utopia(x)
        tree.write(str(result) + '\n')

    tree.close()





