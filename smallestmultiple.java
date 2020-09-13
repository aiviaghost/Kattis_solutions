import java.math.BigInteger; 
import java.util.Scanner; 

class smallestmultiple {
    private static BigInteger LCM(BigInteger a, BigInteger b) {
        return a.multiply(b).divide(a.gcd(b));
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        while (scan.hasNext()) {
            String[] line = scan.nextLine().split(" ");
            BigInteger lcm = BigInteger.ONE;
            for (int i = 0; i < line.length; i++) {
                lcm = LCM(new BigInteger(line[i]), lcm);
            }
            System.out.println(lcm.toString());
        }
    }
}
