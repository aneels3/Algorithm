a=raw_input("enter the two numbers for finding the gcd: ").split()
x=[]
x.append(int(a[0]))
x.append(int(a[1]))
temp=0
if(x[0]>x[1]):
   while(x[1]!=0):
      temp=x[1]
      x[1]=x[0]%x[1]
      x[0]=temp
   print(x[0])

if(x[0]<x[1]):
    while(x[0]!=0):
      temp=x[0]
      x[0]=x[1]%x[0]
      x[1]=temp
    print(x[1])
