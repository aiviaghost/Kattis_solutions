/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package coloringsocks;

import java.util.Arrays;
import java.util.Scanner;

/**
 *
 * @author Admin
 */
public class ColoringSocks {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner scan = new Scanner(System.in);
        
        int s = scan.nextInt();
        int c = scan.nextInt();
        int k = scan.nextInt();
        
        int[] socks = new int[s];
        for (int i = 0; i < s; i++) {
            socks[i] = scan.nextInt();
        }
        
        Arrays.sort(socks);
        
        int current = socks[0];
        int used = 1;
        int machines = 1;
        for (int i = 1; i < s; i++) {
            if(Math.abs(current - socks[i]) <= k && used < c){
                used++;
            }
            else{
                machines++;
                used = 1;
                current = socks[i];
            }
        }
        
        System.out.println(machines);
    }
    
}
