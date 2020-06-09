/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package turnering;

import java.util.Arrays;
import java.util.Scanner;

/**
 *
 * @author julius.thunstrom
 */
public class Turnering {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner scan = new Scanner(System.in);
        
        int players = scan.nextInt();
        int rounds = scan.nextInt();
        
        int[][] table = new int[2][players / 2];
        
       
        for (int j = 0; j < players / 2; j++) {
            table[0][j] = j + 1;
        }
        for (int i = players / 2 - 1; i >= 0; i--) {
            table[1][i] = players - i;
        }
        
        for (int i = 1; i < rounds; i++) {
            int lastA = table[0][players / 2 - 1];
            
            for (int j = players / 2 - 1; j > 0; j--) {
                table[0][j] = table[0][j - 1];
            }
            
            table[0][0] = table[1][1];
            
            for (int j = 1; j < players / 2 - 1; j++) {
                table[1][j] = table[1][j + 1];
            }
            
            table[1][players / 2 - 1] = lastA;
        }
        
        for(int i = 0; i < players / 2; i++){
            System.out.println(table[0][i] + "-" + table[1][i]);
        }
    }
    
}
