/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package a_real_challenge;

import java.util.Scanner;

/**
 *
 * @author Admin
 */
public class A_Real_Challenge {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner scan = new Scanner(System.in);
        
        long i = scan.nextLong();
        
        double side = Math.sqrt(i);
        
        System.out.println(4 * side);
    }

}
