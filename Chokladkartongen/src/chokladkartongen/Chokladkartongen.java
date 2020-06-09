/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package chokladkartongen;

import java.util.Scanner;

/**
 *
 * @author julius.thunstrom
 */
public class Chokladkartongen {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner scan = new Scanner(System.in);
        
        int c = scan.nextInt();
        
        int[] obs = new int[c];
        
        for(int i = 0; i < c; i++){
            obs[i] = scan.nextInt();
        }
        
        int count = 0;
        for (int i = 1; i < c; i++) {
            if(obs[i] > obs[i - 1]){
                count++;
            }
        }
        
        System.out.println(count);
    }
    
}
