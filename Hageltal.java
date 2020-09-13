/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package hageltal;

import java.util.ArrayList;
import java.util.Objects;
import java.util.Scanner;

/**
 *
 * @author Admin
 */
public class Hageltal {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner scan = new Scanner(System.in);
        
        int n, m;
        n = scan.nextInt();
        m = scan.nextInt();
        
        
        ArrayList<Integer> nMap = new ArrayList<>();
        nMap.add(n);
        while(n != m && n > 1){
            if((n & 1) == 0){
                n /= 2;
                nMap.add(n);
            }
            else{
                n = 3 * n + 1;
                nMap.add(n);
            }
        }
        
        
        ArrayList<Integer> mMap = new ArrayList<>();
        mMap.add(m);
        while(m != n && m > 1){
            if((m & 1) == 0){
                m /= 2;
                mMap.add(m);
            }
            else{
                m = 3 * m + 1;
                mMap.add(m);
            }
        }
        
        for (int i = 0; i < nMap.size(); i++) {
            for (int j = 0; j < mMap.size(); j++) {
                if(Objects.equals(nMap.get(i), mMap.get(j))){
                    System.out.println(i + j);
                    i = nMap.size();
                    break;
                }
            }
        }
    }
    
}
