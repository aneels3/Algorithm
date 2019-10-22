#Linear search algorithm in python 
def search(array, key): 
  
    for i in range(len(array)): 
  
        if array[i] == key: 
            return i 
  
    return -1