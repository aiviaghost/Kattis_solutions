/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package minigolf;

import java.util.Scanner;

/**
 *
 * @author Admin
 */
public class Minigolf {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        int nums[] = new int[n];
        for(int i = 0; i < n; i++){
            nums[i] = scan.nextInt();
            if(nums[i] > 7){
                nums[i] = 7;
            }
        }
        
        int tot = 0;
        for(int i = 0; i < n; i++){
            if(i%2 == 0){
                tot += nums[i] - 2;
            }
            else if(i%2 == 1){
                tot += nums[i] - 3;
            }
        }
        
        System.out.println(tot);
    }
    
}
