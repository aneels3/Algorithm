import java.util.*;

public class Solution{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int cost = sc.nextInt();
        int d = sc.nextInt();
        int minDiff = sc.nextInt();
        int minCost = sc.nextInt();
        int diff = cost;
        int count = 0;
        while(cost<=minCost){
            diff = diff - d;
            if(diff < minDiff){
                diff = minDiff;
                d = 0;
            }
            cost = cost + diff;
            count++;
        }
        System.out.println(count);
    }
}
