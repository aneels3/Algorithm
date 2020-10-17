import java.util.Scanner;
public class EvenOddChecker{
	public static void main (String[] args){
		Scanner inputZaed = new Scanner (System.in);
		int num;

		System.out.println("Masukkan sebuah bilangan : ");
		num = inputZaed.nextInt();

		String output = (num%2==0) ?"Even Number":"Odd number";
		System.out.println(output);
		
	}
}
