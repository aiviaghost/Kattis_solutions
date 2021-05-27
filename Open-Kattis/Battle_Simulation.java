/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package battle_simulation;

import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;

/**
 *
 * @author Julius
 */
public class Battle_Simulation {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException {
        // TODO code application logic here
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
        
        String monster = in.readLine();
        
        StringBuilder str = new StringBuilder();
        
        int i = 0;
        while(i < monster.length()){
            if(i + 2 < monster.length() && is_permutation(monster.substring(i, i + 3))){
                str.append("C");
                i += 2;
            }
            else if(monster.charAt(i) == 'R'){
                str.append("S");
            }
            else if(monster.charAt(i) == 'B'){
                str.append("K");
            }
            else if(monster.charAt(i) == 'L'){
                str.append("H");
            }
            
            i++;
        }
        
        out.print(str.toString());
        out.flush();
        out.close();
    }
    
    private static boolean is_permutation(String s){
        return (s.charAt(0) == 'R' && s.charAt(1) == 'B' && s.charAt(2) == 'L') ||
               (s.charAt(0) == 'R' && s.charAt(1) == 'L' && s.charAt(2) == 'B') || 
               (s.charAt(0) == 'B' && s.charAt(1) == 'R' && s.charAt(2) == 'L') ||
               (s.charAt(0) == 'B' && s.charAt(1) == 'L' && s.charAt(2) == 'R') ||
               (s.charAt(0) == 'L' && s.charAt(1) == 'B' && s.charAt(2) == 'R') || 
               (s.charAt(0) == 'L' && s.charAt(1) == 'R' && s.charAt(2) == 'B');
        
        // return (s.contains("R") && s.contains("B") && s.contains("L"));
    }
    
}
