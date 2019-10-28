import os
import sys


#
# Complete the timeConversion function below.
#
def timeConversion(s):
    hours = s[:2]
    minutes = s[3:5]
    seconds = s[6:8]
    ampm = s[-2:]
    if ampm == 'AM' and hours == '12':
        hours = '00'
    if ampm == 'PM' and hours != '12':
        hours = str(int(hours) + 12)
    return '{}:{}:{}'.format(hours, minutes, seconds)


if __name__ == '__main__':
    f = open(os.environ['OUTPUT_PATH'], 'w')
    s = input()
    result = timeConversion(s)
    f.write(result + '\n')
    f.close()
