/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package im_thinking_of_a_number;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

/**
 *
 * @author Julius
 */
public class Im_Thinking_of_a_Number {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner scan = new Scanner(System.in);
        
        while (scan.hasNext()) {
            int n = scan.nextInt();
            if (n == 0)
                break;
            
            scan.nextLine();
            
            int lb = 0, rb = Integer.MAX_VALUE;
            ArrayList<Integer> divs = new ArrayList<>();
            
            for (int i = 0; i < n; i++) {
                String clue = scan.nextLine();
                
                switch (clue.charAt(0)) {
                    case 'l':
                        rb = Math.min(Integer.parseInt(clue.substring(clue.lastIndexOf(' ') + 1, clue.length())), rb);
                        break;
                        
                    case 'g':
                        lb = Math.max(Integer.parseInt(clue.substring(clue.lastIndexOf(' ') + 1, clue.length())), lb);
                        break;
                        
                    default:
                        divs.add(Integer.parseInt(clue.substring(clue.lastIndexOf(' ') + 1)));
                        break;
                }
            }
            
            if (lb >= rb) {
                System.out.println("none");
            }
            else if (rb == Integer.MAX_VALUE) {
                System.out.println("infinite");
            }
            else {
                int range = rb - lb;
                boolean[] valid = new boolean[range];
                Arrays.fill(valid, true);
                for (int d : divs) {
                    for (int i = 1; i < range; i++) {
                        if ((lb + i) % d != 0) {
                            valid[i] = false;
                        }
                    }
                }
                StringBuilder sb = new StringBuilder();
                for (int i = 1; i < range; i++) {
                    if (valid[i]) {
                        sb.append(lb + i).append(" ");
                    }
                }
                System.out.println(sb.length() == 0 ? "none" : sb.toString().trim());
            }
        }
    }
    
}
