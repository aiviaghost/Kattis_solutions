package hashing;

import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;

public class hashing {

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
        
        String s = in.readLine();
        Poly_Hash ph = new Poly_Hash(s);
        int Q = Integer.valueOf(in.readLine());
        for (int i = 0; i < Q; i++) {
            String[] lr = in.readLine().split(" ");
            int l = Integer.valueOf(lr[0]), r = Integer.valueOf(lr[1]);
            out.write(ph.hash(l, r).toString(10));
            out.write("\n");
        }

        out.flush();
        out.close();
    }

}

class Poly_Hash {

    BigInteger b = new BigInteger("31"), P = new BigInteger("18446744073709551615");
    BigInteger[] B, H;

    public Poly_Hash(String s) {
        B = new BigInteger[s.length() + 1];
        H = new BigInteger[s.length() + 1];
        
        B[0] = BigInteger.ONE;
        H[0] = BigInteger.ZERO;
        for (int i = 0; i < s.length(); i++) {
            H[i + 1] = H[i].multiply(b).mod(P).add(BigInteger.valueOf(Long.valueOf(s.charAt(i)))).mod(P);
            B[i + 1] = B[i].multiply(b).mod(P);
        }
    }

    public BigInteger hash(int lb, int rb) {
        return H[rb].subtract(H[lb].multiply(B[rb - lb]).mod(P)).mod(P);
    }

}
