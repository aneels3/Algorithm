# Enter your code here. Read input from STDIN. Print output to STDOUT
s=input()
n=int(input())
#to count no of a in complete string
c1=0
for i in s:
    if i=="a":
        c1+=1
#to count no of "a" in part of string
a=n-(n//len(s))*len(s)
st=s[:a]
c2=0
for i in st:
    if i=="a":
        c2+=1
print(count*(n//len(s))+c2)
