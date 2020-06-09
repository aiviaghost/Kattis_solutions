/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pariserhjulet;

import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

/**
 *
 * @author julius.thunstrom
 */
public class Pariserhjulet {
    
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        int m = scan.nextInt();
        
        Queue<Integer> q = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            q.add(scan.nextInt());
        }
        
        int[] wheel = new int[m];
        
        for (int i = 0; i < m; i++) {
            wheel[i] = 0;
        }
        
        int shifts = 0;
        int zeroCounter = m;
        int x = 0;
        while(true){
            if (wheel[x] == 0 && !q.isEmpty()) {
                wheel[x] = q.poll();
                zeroCounter--;
            }
            else if(wheel[x] > 1){
                wheel[x]--;
            }
            else if(!q.isEmpty()){
                wheel[x] = q.poll();
            }
            else if(wheel[x] != 0){
                wheel[x] = 0;
                zeroCounter++;
            }
            x = (x + 1) % m;
            
            if(zeroCounter == m){
                break;
            }
            
            shifts++;
        }
        
        System.out.println(shifts);
    }
    
    /*public static boolean isZero(int[] arr){
        boolean result = true;
        for (int i : arr) {
            if(i != 0){
                result = false;
                break;
            }
        }
        return result;
    }*/
    
    /*public static void addCountries(int[] wheel){
        currentLowest = q.peek();
        while(wheel[0] > 0){
            if(!q.isEmpty()){
                int temp = q.poll();
                wheel[0] = temp;
                if(temp < currentLowest){
                    currentLowest = temp;
                }
                shift(wheel);
            }
        }
    }*/
    
    /*public static void shift(int[] arr){
        int length = arr.length;
        int temp = arr[length - 1];
        for (int i = 1; i < length; i++) {
            arr[i] = arr[i - 1];
        }
        arr[0] = temp;
    }*/
    
}
