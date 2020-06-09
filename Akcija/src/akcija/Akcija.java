/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package akcija;

import java.util.Arrays;
import java.util.Scanner;

/**
 *
 * @author Admin
 */
public class Akcija {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner scan = new Scanner(System.in);
        
        int n = scan.nextInt();
        
        int[] books = new int[n];
        for (int i = 0; i < n; i++) {
            books[i] = scan.nextInt();
        }
        
        Arrays.sort(books);
        
        long sum = 0;
        for (int i = 0; i < n; i += 3) {
            if(i + 2 < n){
                sum += books[i + 1] + books[i + 2];
            }
            else if(i + 1 < n){
                sum += books[i] + books[i + 1];
            }
            else{
                sum += books[i];
            }
        }
        
        System.out.println(sum);
    }

}
