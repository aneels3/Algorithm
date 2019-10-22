#include<iostream> 
using namespace std; 
  
bool isMagic(int n) 
{ 
    int sum = 0; 
      
    /*A number is said to be a magic number, if the sum of 
    its digits are calculated till a single digit recursively 
    by adding the sum of the digits after every addition. If 
    the single digit comes out to be 1,then the number is
    a magic number*/
    while (n > 0 || sum > 9) 
    { 
        if (n == 0) 
        { 
            n = sum; 
            sum = 0; 
        } 
        sum += n % 10; 
        n /= 10; 
    } 
      
    // Return true if sum becomes 1. 
    return (sum == 1); 
} 
   
// Driver code 
int main() 
{ 
    int n = 1234; 
    if (isMagic(n)) 
        cout << "Magic Number"; 
    else
        cout << "Not a magic Number"; 
    return 0; 
} 