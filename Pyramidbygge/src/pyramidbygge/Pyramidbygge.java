/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pyramidbygge;

import java.util.Scanner;

/**
 *
 * @author julius.thunstrom
 */
public class Pyramidbygge {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner scan = new Scanner(System.in);
        
        long max = scan.nextLong();
        
        long used = 0;
        long height = 0;
        long i = 1;
        while(true){
            if(used + i * i <= max){
                used += i * i;
            }
            else{
                break;
            }
            height++;
            i += 2;
        }
        
        System.out.println(height);
    }
    
}
