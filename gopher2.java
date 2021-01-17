package Gopher2;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;

class P {
	double x, y;
	
	P(double x, double y) {
		this.x = x;
		this.y = y;
	}
}

public class gopher2 {

	static boolean[] is_used;
	static int[] left, right;
	static ArrayList<ArrayList<Integer>> G;
	
	private static boolean dfs(int curr) {
		if (is_used[curr]) {
			return false;
		}
		
		is_used[curr] = true;
		
		for (int next : G.get(curr)) {
			if (left[curr] == -1 || dfs(left[next])) {
				left[next] = curr;
				right[curr] = next;
				return true;
			}
		}
		
		return false;
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Scanner scan = new Scanner(System.in);
		while (scan.hasNext()) {
			Integer[] nmsv = Arrays.asList(scan.nextLine().split(" ")).stream()
																	  .map(i -> Integer.valueOf(i))
																	  .toArray(Integer[]::new);
			int n = nmsv[0], m = nmsv[1], s = nmsv[2], v = nmsv[3];

			ArrayList<P> gophers = new ArrayList<>();
 			for (int i = 0; i < n; i++) {
				double x = Double.valueOf(scan.next()), y = Double.valueOf(scan.next());
				gophers.add(new P(x, y));
			}
			
 			ArrayList<P> holes = new ArrayList<>();
			for (int i = 0; i < m; i++) {
				double x = Double.valueOf(scan.next()), y = Double.valueOf(scan.next());
				holes.add(new P(x, y));
			}
			
			G = new ArrayList<>(Collections.nCopies(n, new ArrayList<>()));
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					double dist = Math.hypot(gophers.get(i).x - holes.get(j).x, gophers.get(i).y - holes.get(j).y);
					if (dist <= (double) s * v) {
						G.get(i).add(j);
					}
				}
			}
			
			is_used = new boolean[n + m];
			left = new int[m];
			right = new int[n];
			Arrays.fill(left,  -1);
			Arrays.fill(right, -1);
			for (int i = 0; i < n; i++) {
				if (right[i] == -1) {
					Arrays.fill(is_used, false);
					dfs(i);
				}
			}
			
			int vuln_count = 0;
			for (int i = 0; i < n; i++) {
				if (right[i] == -1) {
					vuln_count++;
				}
			}
			System.out.println(vuln_count);
			
			scan.nextLine();
		}
	}

}
