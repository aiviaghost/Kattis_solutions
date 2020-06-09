/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package skolavslutningen;

import java.util.ArrayList;
import java.util.Scanner;

/**
 *
 * @author julius.thunstrom
 */
public class Skolavslutningen {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner scan = new Scanner(System.in);
        
        int n = scan.nextInt();
        int m = scan.nextInt();
        int classes = scan.nextInt();
        scan.nextLine();
        
        char[][] s = new char[n][m];
        
        // make arrays column by column instead of row by row, the add students to top of each array each line
        for (int i = 0; i < n; i++) {
            String temp = scan.nextLine();
            for (int j = 0; j < m; j++) {
                s[i][j] = temp.charAt(j);
            }
        }
        
        ArrayList<Character> used = new ArrayList<>();
        ArrayList<Character> current = new ArrayList<>();
        int colors = n * m;
        for(int i = 0; i < m; i++){
            for (int j = 0; j < n; j++) {
                char tc = s[j][i];
                
                if(!contains(used, tc)){
                    
                }
                else{
                    colors--;
                }
            }
        }
        
        System.out.println(colors);
    }
    
    public static boolean contains(ArrayList<Character> list, char c){
        boolean contains = false;
        for (Character character : list) {
            if(character == c){
                contains = true;
                break;
            }
        }
        return contains;
    }
    
}
