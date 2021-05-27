package appallingarchitecture;

import java.util.Scanner;

public class appallingarchitecture {

	final static int INF = (int) 2e9;
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
		
		int h = scan.nextInt(), w = scan.nextInt();
		scan.nextLine();
		
		String[] blueprint = new String[h];
		for (int i = 0; i < h; i++) {
			blueprint[i] = scan.nextLine();
		}
		
		double cgw = 0, tot_w = 0, leftmost = INF, rightmost = -1;
		for (int i = 0; i < w; i++) {
			double cw = 0;
			for (int j = 0; j < h; j++) {
				if (blueprint[j].charAt(i) != '.') {
					cw++;
					
					if (j == h - 1) {
						leftmost = Math.min(i, leftmost);
						rightmost = Math.max(i, rightmost);
					}
				}
			}
			tot_w += cw;
			cgw += cw * (i + 0.5);
		}
		rightmost++;
		double mid = cgw / tot_w;
		
		if (leftmost < mid + 1e-12 && mid - 1e-12 < rightmost) {
			System.out.println("balanced");
		}
		else if (mid < leftmost) {
			System.out.println("left");
		}
		else {
			System.out.println("right");
		}
	}

}
