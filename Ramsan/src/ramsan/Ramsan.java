/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ramsan;

import java.util.ArrayList;
import java.util.Scanner;

/**
 *
 * @author Admin
 */
public class Ramsan {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner scan = new Scanner(System.in);
        
        ArrayList<Integer> children = new ArrayList<>();
        
        int words = scan.nextInt();
        int childCount = scan.nextInt();
        
        for (int i = 1; i <= childCount; i++) {
            children.add(i);
        }
        
        int index = 0;
        while(children.size() > 1){
            index += (words % children.size()) - 1;
            index %= children.size();
            children.remove(index);
        }
        
        System.out.println(children.get(0));
    }
    
}
