package pot;

import java.util.Scanner;

public class pot {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
		
		int n = scan.nextInt();
		scan.nextLine();
		int X = 0;
		for (int i = 0; i < n; i++) {
			String in = scan.nextLine();
			int base = Integer.parseInt(in.substring(0, in.length() - 1)), exp = Integer.parseInt(String.valueOf(in.charAt(in.length() - 1)));
			X += Math.pow(base, exp);
		}
		System.out.println(X);
	}

}
