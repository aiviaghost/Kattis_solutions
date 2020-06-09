/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package tvtittande;

import java.util.HashSet;
import java.util.Scanner;

/**
 *
 * @author Julius
 */
public class TVtittande {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner scan = new Scanner(System.in);
        
        int n = scan.nextInt();
        int k = scan.nextInt();
        
        long[] series = new long[k];
        for (int i = 0; i < k; i++) {
            series[i] = scan.nextLong();
        }
        
        int[][] kalas = new int[n][];
        for (int i = 0; i < n; i++) {
            int day = scan.nextInt();
            int seriesCount = scan.nextInt() + 1;
            kalas[i] = new int[seriesCount];
            kalas[i][0] = day;
            for (int j = 1; j < seriesCount; j++) {
                kalas[i][j] = scan.nextInt();
            }
        }
        
        HashSet<Integer> watched = new HashSet<>();
        long extraTime = 10;
        int currentDay = 0;
        boolean possible = true;
        
        for (int i = 0; i < n; i++) {
            long totSeriesTime = 0;
            for (int j = 1; j < kalas[i].length; j++) {
                if(!watched.contains(kalas[i][j])){
                    totSeriesTime += series[kalas[i][j] - 1];
                    watched.add(kalas[i][j]);
                }
            }
            
            if(totSeriesTime <= 10 * (kalas[i][0] - currentDay - 1)){
                extraTime += 10 * (kalas[i][0] - currentDay - 1) - totSeriesTime;
                currentDay = kalas[i][0];
            }
            else if(totSeriesTime <= 10 * (kalas[i][0] - currentDay - 1) + extraTime){
                extraTime = (10 * (kalas[i][0] - currentDay - 1) + extraTime) - totSeriesTime;
                currentDay = kalas[i][0];
            }
            else{
                possible = false;
                break;
            }
        }
        
        if(possible){
            System.out.println("Ja");
        }
        else{
            System.out.println("Nej");
        }
    }
    
}
