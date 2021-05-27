/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package counting_stars;

import java.util.ArrayList;
import java.util.Scanner;

/**
 *
 * @author Julius
 */
public class Counting_Stars {

    static int m, n;
    
    private static boolean is_inside(int x, int y) {
        return 0 <= x && x < n && 0 <= y && y < m;
    }
    
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner scan = new Scanner(System.in);
        
        int t = 0;
        while (scan.hasNext()) {
            t++;
            
            String[] line = scan.nextLine().split(" ");
            m = Integer.parseInt(line[0]);
            n = Integer.parseInt(line[1]);
            
            boolean[][] sky = new boolean[m][n];
            for (int i = 0; i < m; i++) {
                String temp = scan.nextLine();
                for (int j = 0; j < n; j++) {
                    sky[i][j] = temp.charAt(j) == '-';
                }
            }
            
            int stars = 0;
            boolean[][] vis = new boolean[m][n];
            int[][] neighbours = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
            
            for (int y = 0; y < m; y++) {
                for (int x = 0; x < n; x++) {
                    if (!vis[y][x] && sky[y][x]) {
                        stars++;
                        ArrayList<int[]> curr_layer = new ArrayList<>();
                        curr_layer.add(new int[]{x, y});
                        vis[y][x] = true;
                        while (!curr_layer.isEmpty()) {
                            ArrayList<int[]> next_layer = new ArrayList<>();
                            for (int[] c : curr_layer) {
                                for (int[] n : neighbours) {
                                    int nx = c[0] + n[0];
                                    int ny = c[1] + n[1];
                                    if (is_inside(nx, ny) && !vis[ny][nx] && sky[ny][nx]) {
                                        vis[ny][nx] = true;
                                        next_layer.add(new int[]{nx, ny});
                                    }
                                }
                            }
                            curr_layer = next_layer;
                        }
                    }
                }
            }
            
            System.out.println("Case " + t + ": " + stars);
        }
    }
    
}
