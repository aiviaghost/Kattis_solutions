/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package tomater;

import java.util.Scanner;

/**
 *
 * @author julius.thunstrom
 */
public class Tomater {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner scan = new Scanner(System.in);

        int tot = scan.nextInt();
        int days = scan.nextInt();
        int t1 = scan.nextInt();
        int t2 = scan.nextInt();
        int t3 = scan.nextInt();

        boolean[] toms = new boolean[tot];
        boolean[] cToms = new boolean[tot];
        for (int i = 0; i < tot; i++) {
            toms[i] = false;
            cToms[i] = false;
        }
        toms[t1 - 1] = true;
        toms[t2 - 1] = true;
        toms[t3 - 1] = true;
        cToms[t1 - 1] = true;
        cToms[t2 - 1] = true;
        cToms[t3 - 1] = true;
        
        for (int i = 0; i < days; i++) {
            for (int j = 0; j < tot; j++) {
                if (toms[j]) {
                    if (j > 0) {
                        cToms[j - 1] = true;
                    }
                    
                    if (j < tot - 1) {
                        cToms[j + 1] = true;
                    }
                }
            }
            System.arraycopy(cToms, 0, toms, 0, tot);
        }
        
        int count = 0;
        for (int i = 0; i < tot; i++) {
            if (cToms[i]) {
                count++;
            }
        }
        
        System.out.println(count);
    }

}
