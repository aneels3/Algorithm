def Fibonacci(n): 
    if n<0: 
        print("Incorrect input") 
    elif n==1: 
        return 0
    #First number in fibonacci series is 0
    elif n==2: 
        return 1
    #Second number in fibonacci series is 1
    else: 
        return Fibonacci(n-1)+Fibonacci(n-2)
