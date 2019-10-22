#Linear search algorithm in python 
def search(array, key):
  #iterate in the array
	for i in range(len(array)):
	#check each element of array
		if array[i] == key:
		#if element matches key,return index
			return i 
	#else element not found
    	return -1
