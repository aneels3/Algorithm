#Linear search algorithm in python 
def search(array, key): 
    #iterating through the array
    for i in range(len(array)): 
      #checking for key value with each element of array
      if array[i] == key:
            #if matches return the index
            return i
    #else not found
    return -1
