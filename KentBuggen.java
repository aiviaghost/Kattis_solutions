/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package kentbuggen;

import java.util.ArrayList;
import java.util.Scanner;

/**
 *
 * @author Admin
 */
public class KentBuggen {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner scan = new Scanner(System.in);
        
        int n = scan.nextInt();
        scan.nextLine();
        ArrayList<String> names = new ArrayList();
        for(int i = 0; i < n; i++){
            names.add(scan.nextLine());
        }
        
        names.sort(String::compareTo);
        
        ArrayList<String> multiple = new ArrayList();
        for(int i = 0; i < n-1; i++){
            if(names.get(i).equals(names.get(i+1)) && !contains(multiple, names.get(i+1))){
                multiple.add(names.get(i+1));
            }
        }
        
        System.out.println(multiple.size());
    }
    
    public static boolean contains(ArrayList list, String str){
        boolean result = false;
        if(list.size() > 0){
            if(list.get(list.size()-1).equals(str)){
                result = true;
            }
        }
        return result;
    }
    
}
