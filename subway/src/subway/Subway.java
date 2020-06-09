/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package subway;

import java.util.Scanner;

/**
 *
 * @author Julius
 */
public class Subway {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner scan = new Scanner(System.in);
        
        int a1 = scan.nextInt();
        int a2 = scan.nextInt();
        int a3 = scan.nextInt();
        int a4 = scan.nextInt();
        
        int tot = 0;
        tot += a4;
        
        tot += a3;
        a1 = Math.max(a1-a3, 0);
        
        tot += (2 * a2)/4;
        if((2*a2)%4 > 0){
            tot++;
        }
        
        a1 = Math.max(a1 - (2*a2)%4, 0);
        
        tot += a1/4;
        a1 = a1%4;
        if(a1 > 0){
            tot++;
        }
        
        System.out.println(tot);
    }
    
}
