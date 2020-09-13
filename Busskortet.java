/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package busskortet;

import java.util.Scanner;

/**
 *
 * @author Julius
 */
public class Busskortet {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner scan = new Scanner(System.in);
        
        int in = scan.nextInt();
        
        int sum = 0;
        int i = 0;
        
        while(true){
            if(sum >= in){
                break;
            }
            
            if(in - sum > 400){
                sum += 500;
            }
            else if(in - sum > 100){
                sum += 200;
            }
            else{
                sum += 100;
            }
            
            i++;
        }
        
        System.out.println(i);
    }
    
}
