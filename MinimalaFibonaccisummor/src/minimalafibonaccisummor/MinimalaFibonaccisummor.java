/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package minimalafibonaccisummor;

import java.util.ArrayList;
import java.util.Scanner;

/**
 *
 * @author Admin
 */
public class MinimalaFibonaccisummor {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner scan = new Scanner(System.in);
        
        long in = scan.nextLong();
        
        ArrayList<Long> fibs = new ArrayList();
        fibs.add(1L);
        fibs.add(1L);
        
        int i = 1;
        do{
            fibs.add(fibs.get(i) + fibs.get(i - 1));
            i++;
        }while(fibs.get(fibs.size() - 1) < in);
        
        ArrayList<Long> outs = new ArrayList();
        long tot = 0;
        int j = fibs.size() - 1;
        while(tot != in){
            long fj = fibs.get(j);
            if(fj <= in && tot+fj <= in){
                tot += fj;
                outs.add(fj);
            }
            j--;
        }
        
        System.out.println(outs.size());
        for (int k = 0; k < outs.size(); k++) {
            System.out.println(outs.get(k));
        }
    }
    
}
