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
		
		int leftmost = INF, rightmost = -1;
		int[] psum = new int[w];
		for (int i = 0; i < w; i++) {
			if (i >= 1) {
				psum[i] = psum[i - 1];
			}
			for (int j = 0; j < h; j++) {
				if (blueprint[j].charAt(i) != '.') {
					psum[i]++;
					
					if (j == h - 1) {
						leftmost = Math.min(i, leftmost);
						rightmost = Math.max(i, rightmost);
					}
				}
			}
		}
		rightmost++; // if we imagine each cell as an infinitely rectangles with height = 1 and width = dx then the rightmost support of the building is the rightmost dx-slice of the rightmost cell
		
		double lb = 0, rb = w + 1, mid = -1;
		while (rb - lb > 0) {
			mid = (lb + rb) / 2.0;
			
		}
		
		if (leftmost < mid && mid < rightmost) {
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
