# solution for https://www.hackerrank.com/challenges/maximize-it/problem
import itertools


def F(xs, M):
    return sum((map(lambda v: v ** 2, xs))) % M


def maximizeIt(values, M):
    cartesian = itertools.product(*values)
    return max(F(x, M) for x in cartesian)


if __name__ == '__main__':
    K, M = map(int, input().split())
    values = []
    for i in range(0, K):
        Ni, *vs = map(int, input().split())
        values.append(vs)
    print(maximizeIt(values, M))
