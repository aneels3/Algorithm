import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int i,n,k,ans=0;
        n=sc.nextInt();
        k=sc.nextInt();
        int []a=new int[n];
        int []b=new int[k];
        for(i=0;i<k;i++){
            b[i]=0;
        }
        for(i=0;i<n;i++){
            a[i]=sc.nextInt();
            int x=a[i]%k;
            b[x]++;
        }
        for(i=1;i<k;i++){
            if(k%2==1 || i!=k/2){
            if(b[i]>b[k-i]){
                ans+=b[i];
            }
            else{
                ans+=b[k-i];
            }
        }
        }
        if(k%2==0){
            ans+=2;
        }
        if(b[0]>0){
            ans+=2;
        }
        System.out.println(ans/2);
    }
}