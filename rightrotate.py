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

k = 4
n = [7, 8, 9, 10, 11, 12] 
  
print(rightRotate(n, k)) 

