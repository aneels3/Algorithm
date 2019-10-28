import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        final Scanner scanner = new Scanner(System.in);
        final int stairs = scanner.nextInt();
        final String staircase = constructStaircase(stairs);
        System.out.println(staircase);
    }
    
   public static String constructStaircase(final int stairs) {
        StringBuilder builder = new StringBuilder();
        for (int i=0; i<stairs; i++) {
            for (int j=stairs-1; j>=0; j--) {
                if (i>=j) {
                    builder.append("#");
                } else {
                    builder.append(" ");
                }
            }
            builder.append("\n");
        }

        return builder.toString();
    }
}
