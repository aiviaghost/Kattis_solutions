/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package modulo;

import java.util.HashSet;
import java.util.Scanner;

/**
 *
 * @author julius.thunstrom
 */
public class Modulo {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner scan = new Scanner(System.in);
        
        HashSet<Integer> unique = new HashSet<>();
        for (int i = 0; i < 10; i++) {
            unique.add(scan.nextInt() % 42);
        }
        
        System.out.println(unique.size());
    }
    
}
