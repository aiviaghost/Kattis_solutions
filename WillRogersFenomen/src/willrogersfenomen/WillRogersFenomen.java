/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package willrogersfenomen;

import java.util.ArrayList;
import java.util.Scanner;

/**
 *
 * @author julius.thunstrom
 */
public class WillRogersFenomen {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner scan = new Scanner(System.in);
        
        int countA = scan.nextInt();
        int countB = scan.nextInt();
        
        ArrayList<Integer> a = new ArrayList<>();
        ArrayList<Integer> b = new ArrayList<>();
        
        for (int i = 0; i < countA; i++) {
            a.add(scan.nextInt());
        }
        
        for (int i = 0; i < countB; i++) {
            b.add(scan.nextInt());
        }
        
        double initMeanA = mean(a);
        double initMeanB = mean(b);
        
        boolean aOrB = true;
        boolean impossible = true;
        for (int i = 0; i < a.size(); i++) {
            int ca = a.get(i);
            a.remove(i);
            b.add(ca);
            if(mean(a) > initMeanA && mean(b) > initMeanB){
                aOrB = false;
                impossible = false;
                System.out.println(b.get(b.size() - 1) + " B");
                break;
            }
            a.add(i, ca);
            b.remove(b.size() - 1);
        }
        
        if(aOrB){
            for (int i = 0; i < b.size(); i++) {
                int cb = b.get(i);
                b.remove(i);
                a.add(cb);
                if(mean(a) > initMeanA && mean(b) > initMeanB){
                    impossible = false;
                    System.out.println(a.get(a.size() - 1) + " A");
                    break;
                }
                b.add(i, cb);
                a.remove(a.size() - 1);
            }
        }
        
        if(impossible){
            System.out.println("NEJ");
        }
    }
    
    public static double mean(ArrayList<Integer> list){
        double tot = 0;
        for (int i = 0; i < list.size(); i++) {
            tot += list.get(i);
        }
        return tot / (double) list.size();
    }
    
}
