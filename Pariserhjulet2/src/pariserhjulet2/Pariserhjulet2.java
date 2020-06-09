/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pariserhjulet2;

import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.Scanner;
import java.util.TreeSet;

/**
 *
 * @author Admin
 */
public class Pariserhjulet2 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner scan = new Scanner(System.in);
        
        int n = scan.nextInt();
        int m = scan.nextInt();
        
        ArrayList<Long> q = new ArrayList<>();
        TreeSet<Long> wheel = new TreeSet<>();
        for (long i = 0; i < n; i++) {
            if(i < m){
                wheel.add(i);
            }
            
            q.add(m * scan.nextLong());
        }
        
        long totTime = 0;
        
        for (int i = 0; i < q.size(); i++) {
            long temp = wheel.pollFirst();
            wheel.add(q.get(i) + temp);
            if(q.get(i) + temp > totTime){
                totTime = q.get(i) + temp;
            }
        }
        
        System.out.println(totTime);
    }
    
}
