/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package uppstallning;

import java.util.Scanner;

/**
 *
 * @author julius.thunstrom
 */
public class Uppstallning {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner scan = new Scanner(System.in);
        
        int tot = scan.nextInt();
        
        int[][] stats = new int[tot][3];
        
        for(int i = 0; i < tot; i++){
            stats[i][0] = scan.nextInt();
            stats[i][1] = scan.nextInt();
            stats[i][2] = 65 + i;
        }
        
        quickSort(stats, 0, tot - 1);
        
        int[] finalPos = new int[tot];
        
        for (int i = 0; i < tot; i++) {
            finalPos[i] = 0;
        }
        
        for (int i = 0; i < tot; i++) {
            int j = 0;
            int x = 0;
            while(j < stats[i][0] || finalPos[x] != 0){
                if(finalPos[x] == 0){
                    j++;
                }
                x++;
            }
            finalPos[x] = stats[i][2];
        }
        
        String out = "";
        for (int c : finalPos) {
            out += Character.toString((char) c);
        }
        System.out.println(out);
    }
    
    public static void quickSort(int[][] arr, int low, int high){
        if(arr == null || arr.length == 0){
            return;
        }
        
        if(low >= high){
            return;
        }
        
        int mid = low + (high - low)/2;
        int pivot = arr[mid][0] + arr[mid][1];
        
        int left = low;
        int right = high;
        
        while(left <= right){
            while(arr[left][0] + arr[left][1] > pivot){
                left++;
            }
            
            while(arr[right][0] + arr[right][1] < pivot){
                right--;
            }
            
            if(left <= right){
                int[] temp = arr[left];
                arr[left] = arr[right];
                arr[right] = temp;
                left++;
                right--;
            }
        }
        
        if(low < right){
            quickSort(arr, low, right);
        }
        
        if(high > left){
            quickSort(arr, left, high);
        }
    }
}
