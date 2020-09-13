/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package matrixinverse;

import java.util.Scanner;

/**
 *
 * @author Admin
 */
public class MatrixInverse {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        
       Scanner scan = new Scanner(System.in);
       
       int case_count = 1;
       while(scan.hasNext()){
           int a = scan.nextInt();
           int b = scan.nextInt();
           int c = scan.nextInt();
           int d = scan.nextInt();
           
           double det = a * d - b * c;
           
           System.out.println("Case " + case_count + ":");
           System.out.println((int) (d / det) + " " + (int) (-b / det));
           System.out.println((int) (-c / det) + " " + (int) (a / det));
           
           case_count++;
       }
    }

}
