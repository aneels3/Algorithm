import java.util.*;

public class Solution {
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
            int n = sc.nextInt();
            char a[] = new char[n];
            String s = sc.next();
            for(int i = 0;i<s.length();i++){
                a[i] = s.charAt(i);
            }
            int j = 0;
            int count = 0;
            int sum=0;
            for(int i=0;i<n;i++)
            {
                if(a[i]=='D')
                {
                    count++;
                    if(count==0)
                    {
                        if(a[j]=='D')
                        {
                            sum++;     
                        }
                        j=i+1;
                    }
                }

                else
                {
                    count--;
                    if(count==0)
                    {
                        if(a[j]=='D')
                        {
                            sum++;   
                        }
                        j=i+1;
                    }
                }
            }
            System.out.print(sum);
    }
}
