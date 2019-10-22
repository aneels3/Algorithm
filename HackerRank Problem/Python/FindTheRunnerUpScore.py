if __name__ == '__main__':
    n = int(input())
    arr = map(int, input().split())
    myList=list(arr)
    z = max(myList)
    while max(myList) == z:
        myList.remove(max(myList))
    print (max(myList))
