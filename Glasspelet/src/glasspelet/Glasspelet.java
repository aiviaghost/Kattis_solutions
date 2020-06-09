/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package glasspelet;

import java.util.Random;
import java.util.Scanner;

/**
 *
 * @author Admin
 */
public class Glasspelet {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner scan = new Scanner(System.in);

        int n = scan.nextInt();
        int k = scan.nextInt();
        int q = scan.nextInt();

        int[] order = new int[n];
        for (int i : order) {
            i = scan.nextInt();
        }

        int[][] quests = new int[q][2];
        for (int[] quest : quests) {
            quest[0] = scan.nextInt();
            quest[1] = scan.nextInt();
        }

        if (k == 1) {
            for (int i = 0; i < q; i++) {
                if((quests[i][1] - quests[i][0] + 1) % 2 == 0){
                    System.out.println(1);
                }
                else{
                    System.out.println(2);
                }
            }
        } 
        else {
            Random rand = new Random();
            for (int i = 0; i < q; i++) {
                System.out.println(rand.nextInt(3));
            }
        }
    }

}
