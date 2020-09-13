/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lagomvinkladetrianglar1;

import java.util.ArrayList;
import java.util.Scanner;

/**
 *
 * @author Admin
 */
public class LagomVinkladeTrianglar1 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner scan = new Scanner(System.in);
        int orgN = scan.nextInt();
        
        int tot = 0;
        ArrayList<Integer> solves = new ArrayList(); 
        for(int c = 1; c <= orgN; c++){
            for(int a = 1; a <= orgN; a++){
                if(a == c){
                    tot++;
                }
                else{
                    for(int b = 1; b <= orgN; b++){
                        if(a*a + b*b - a*b == c*c){
                            if(!contains(solves, b, a)){
                                solves.add(a);
                                solves.add(b);
                                tot++;
                            }
                        }
                    }
                }
            }
        }
        
        System.out.println(tot-2);
    }
    
    public static boolean contains(ArrayList arr, int b, int a){
        boolean result = false;
        if(arr.size() > 1){
            for(int i = arr.size()-1; i > arr.size()/2; i -= 2){
                if((int)arr.get(i-1) == b && (int)arr.get(i) == a){
                    result = true;
                    break;
                }
            }
        }
        return result;
    }
    
}
