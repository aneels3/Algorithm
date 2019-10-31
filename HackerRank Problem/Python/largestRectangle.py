
def max_rect(building): 

    stack = list() 
  
    max_area = 0 
    index = 0
    while index < len(building): 

        if (not stack) or (building[stack[-1]] <= building[index]): 
            stack.append(index) 
            index += 1

        else: 
            top = stack.pop() 
  
            area = (building[top] * 
                   ((index - stack[-1] - 1)  
                   if stack else index)) 
  
            max_area = max(max_area, area) 

    while stack: 
          
        top = stack.pop() 

        area = (building[top] * 
              ((index - stack[-1] - 1)  
                if stack else index)) 
  
        max_area = max(max_area, area) 

    return max_area 

heights = [5, 2, 5, 3, 5, 1, 6] 
print("Max area of rectangle: ", max_rect(heights)) 
