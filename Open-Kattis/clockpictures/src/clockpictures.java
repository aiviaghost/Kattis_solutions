package clockpictures;

import java.io.*;
import java.math.*;
import java.util.*;
import java.util.stream.Stream;

public class clockpictures {

	static BigInteger base = new BigInteger("360000"), P = new BigInteger("10378967773691252059");

	public static BigInteger Poly_Hash(int[] s) {
		int n = s.length;
		
		BigInteger h = BigInteger.ZERO;
		for (int i = 0; i < n; i++) {
			h = h.multiply(base).add(BigInteger.valueOf(s[i])).mod(P);
		}

		return h;
	}

	static final int INF = (int) 2e9;

	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));

		int n = Integer.valueOf(in.readLine());
		int[] a = Arrays.stream(in.readLine().split(" ")).mapToInt(i -> Integer.valueOf(i)).toArray();
		int[] b = Arrays.stream(in.readLine().split(" ")).mapToInt(i -> Integer.valueOf(i)).toArray();

		Arrays.sort(a);
		Arrays.sort(b);

		int[] a_diff = new int[n], b_diff = new int[n];
		for (int i = 0; i < n; i++) {
			a_diff[i] = (a[(i + 1) % n] - a[i % n] + 360000) % 360000;
			b_diff[i] = (b[(i + 1) % n] - b[i % n] + 360000) % 360000;
		}
		
		BigInteger ha = Poly_Hash(a_diff);
		BigInteger hb = Poly_Hash(b_diff);

		boolean ok = ha.equals(hb);
		if (!ok) {
			for (int i = 0; i < n; i++) {
				BigInteger sub = BigInteger.valueOf(b_diff[i]).multiply(base.modPow(BigInteger.valueOf(n), P)).mod(P);
				hb = hb.multiply(base).mod(P).subtract(sub).mod(P).add(BigInteger.valueOf(b_diff[i])).mod(P);
				if (ha.equals(hb)) {
					ok = true;
					break;
				}
			}
		}

		out.write(ok ? "possible\n" : "impossible\n");

		out.flush();
		out.close();
	}
}
