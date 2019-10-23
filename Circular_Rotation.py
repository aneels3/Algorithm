'''
A simple python program which circularly rotates the input array to the right by k 

'''

n=int(input())
k=int(input())
arr=[]
for i in range(n):
    ele=int(input())
    arr.append(ele)
    
k=k%n
aux=[]
for i in range(n):
    if i>=n-k:
        aux.append(arr[i])
        
aux.reverse()    

arr=arr[:len(arr)-k] 

for i in aux:
    arr.insert(0,i)

print(*arr) 