# Python program to right rotate a list by n 
def rightRotate(lists, num): 
    output_list = [] 
    # Will add values from n to the new list 
    for item in range(len(lists) - num, len(lists)): 
        output_list.append(lists[item]) 
    # Will add the values before 
    # n to the end of new list     
    for item in range(0, len(lists) - num):  
        output_list.append(lists[item]) 
    return output_list 
  
# Driver Code 
if __name__ == "__main__":
  list1 = [] 
# number of elemetns as input 
  n = int(input("Enter number of elements : ")) 
# iterating till the range 
  for i in range(0, n): 
     ele = int(input()) 
     list1.append(ele)
print(list1)
k = int(input("Enter the number of positions you want to shift:"))
print(rightRotate(list1, k)) 

