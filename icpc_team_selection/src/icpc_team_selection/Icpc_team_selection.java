/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package icpc_team_selection;

import java.util.Arrays;
import java.util.Scanner;

/**
 *
 * @author Admin
 */
public class Icpc_team_selection {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner scan = new Scanner(System.in);

        int test_cases = scan.nextInt();
        for (int i = 0; i < test_cases; i++) {
            int n = 3 * scan.nextInt();
            int[] arr = new int[n];
            for (int j = 0; j < n; j++) {
                arr[j] = scan.nextInt();
            }
            Arrays.sort(arr);
            int sum = 0;
            if (n > 3) {
                for (int j = 2; j < n - 3; j += 3) {
                    sum += arr[j];
                }
            }
            sum += arr[n - 2];
            System.out.println(sum);
        }
    }

}
