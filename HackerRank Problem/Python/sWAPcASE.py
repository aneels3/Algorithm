#made a function to swapcase
def swap_case(s):
    if 0<=len(s)<=1000:
        a=""
        for i in s:
            if i.isupper()==True:
                a+=i.lower()
            elif i.islower()==True:
                a+=i.upper()
            else:  #number or special characters will come under this.
                a+=i
        return a

if __name__ == '__main__':
    s = input()
    result = swap_case(s)
    print(result) 