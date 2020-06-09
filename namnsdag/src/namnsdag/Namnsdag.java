/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package namnsdag;

import java.util.Scanner;

/**
 *
 * @author Admin
 */
public class Namnsdag {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner scan = new Scanner(System.in);
        
        String name = scan.nextLine();
        int days = scan.nextInt();
        scan.nextLine();
        String names[] = new String[days];
        for(int i = 0; i < days; i++){
            names[i] = scan.nextLine();
        }
        
        int daysToWait = 0;
        boolean exit = false;
        for(int i = 0; i < days; i++){
            if(exit){
                break;
            }
            if(names[i].length() == name.length()){
                for(int j = 0; j < name.length(); j++){
                    char arr1[] = name.toCharArray();
                    char arr2[] = names[i].toCharArray();
                    arr1[j] = arr2[j];
                    String newName = new String(arr1);
                    if(newName.equals(names[i])){
                        daysToWait = i+1;
                        exit = true;
                        break;
                    }
                }
            }
        }
        
        System.out.println(daysToWait);
    }
    
}
