import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    static void extraLongFactorials(int n) {
        BigInteger big = BigInteger.valueOf(n);
        BigInteger result = factorialRecursive(big);
        BigInteger otherResult = factorial(n);
        System.out.println(otherResult);
    }

    private static BigInteger factorial(int n){
        BigInteger fact=BigInteger.valueOf(1);
        for(int i=1;i<=n;i++){
            fact=fact.multiply(BigInteger.valueOf(i));
        }
        return fact;
    }

    private static BigInteger factorialRecursive(BigInteger n){
        if(n==BigInteger.valueOf(0)){
            return BigInteger.valueOf(1);
        }
        else{
            return n.multiply(factorialRecursive(n.subtract(BigInteger.valueOf(1))));
        }
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int n = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        extraLongFactorials(n);

        scanner.close();
    }
}
