

import java.util.Scanner;

public class Encryption {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        s = s.replaceAll("\\s+", "");
        int l = s.length();
        int row = (int) Math.floor(Math.sqrt(l));
        int col = (int) Math.ceil(Math.sqrt(l));
        if (row * col < l) {
            row = col;
        }
        char ch[][] = new char[row][col];
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                ch[i][j] = '*';
            }
        }
        int k = 0;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (k < s.length()) {
                    ch[i][j] = s.charAt(k);
                    k++;
                }
            }
        }
        

          
        for(int i=0;i<col;i++){
            for(int j=0;j<row;j++){
                if(ch[j][i] == '*'){
                    ;
                }
                else{
                    System.out.print(ch[j][i]);
                }
                
            }
              System.out.print(" ");  
        }

    }
}
