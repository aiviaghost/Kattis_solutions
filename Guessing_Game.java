/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package guessing_game;

import java.util.Scanner;

public class Guessing_Game {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        
        boolean[] vis = new boolean[10];
        while (scan.hasNext()) {
            int guess = scan.nextInt();
            scan.nextLine();
            
            if (guess == 0)
                break;
            
            String ans = scan.nextLine();
            
            switch (ans) {
                case "right on":
                    System.out.println((vis[guess - 1] ? "Stan is dishonest" : "Stan may be honest"));  
                    
                    for (int i = 0; i < 10; i++) {
                        vis[i] = false;
                    }
                    break;
                    
                case "too low":
                    for (int i = guess - 1; i >= 0; i--) {
                        vis[i] = true;
                    }
                    break;
                    
                default:
                    for (int i = guess - 1; i < 10; i++) {
                        vis[i] = true;
                    }
                    break;
            }
        }
    }

}
