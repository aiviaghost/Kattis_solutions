/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package konsonantkoll;

import java.util.Scanner;

/**
 *
 * @author Julius
 */
public class Konsonantkoll {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner scan = new Scanner(System.in);
        
        String in = scan.nextLine();
        
        String out = "";
        
        char[] konsonanter = "bcdfghjklmnpqrstvwxz".toCharArray();
        
        int i = 0;
        while(i < in.length()){
            char ci = in.charAt(i);
            boolean result = contains(konsonanter, ci);
            if(result && i > 1 && ((in.charAt(i - 1) != ci ^ in.charAt(i - 2) != ci) || (in.charAt(i - 1) != ci && in.charAt(i - 2) != ci))){
                out += ci;
            }
            else if(i < 2 && result){
                out += ci;
            }
            else if(!result){
                out += ci;
            }
            i++;
        }
        
        System.out.println(out);
    }
    
    public static boolean contains(char[] arr, char c){
        boolean result = false;
        for (char ac : arr) {
            if(ac == c){
                result = true;
                break;
            }
        }
        return result;
    }
    
}
