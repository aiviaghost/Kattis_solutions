/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package goat_ropes;

import java.text.DecimalFormat;
import java.text.DecimalFormatSymbols;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Locale;
import java.util.Scanner;

/**
 *
 * @author Julius
 */
public class Goat_ropes {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner scan = new Scanner(System.in);

        int n = scan.nextInt();
        int ineq_count = (n * (n - 1)) / 2;

        int[][] posts = new int[n][2];

        for (int i = 0; i < n; i++) {
            posts[i][0] = scan.nextInt();
            posts[i][1] = scan.nextInt();
        }

        double[] dists = new double[ineq_count];
        int counter = 0;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                int dx = Math.abs(posts[i][0] - posts[j][0]);
                int dy = Math.abs(posts[i][1] - posts[j][1]);
                dists[counter] = Math.sqrt(dx * dx + dy * dy);
                counter++;
            }
        }
        
        int tot_var_count = n + ineq_count;
        String[] solution_mix = new String[ineq_count];
        String[] vars = new String[n];
        for (int i = 0; i < n; i++) {
            vars[i] = "r" + i;
        }
        for (int i = 0; i < ineq_count; i++) {
            solution_mix[i] = "s" + i;
        }

        HashMap<Object, Object> dict = new HashMap<>();
        for (int i = 0; i < n; i++) {
            dict.put(vars[i], i);
            dict.put(i, vars[i]);
        }
        for (int i = 0; i < ineq_count; i++) {
            dict.put(solution_mix[i], n + i);
            dict.put(n + i, solution_mix[i]);
        }

        double[][] tableau = new double[ineq_count + 2][tot_var_count + 1];
        
        int temp_row_index = 0;
        for(int i = 0; i < n - 1; i++){
            for(int j = i + 1; j < n; j++){
                tableau[temp_row_index][i] = 1;
                tableau[temp_row_index][j] = 1;
                tableau[temp_row_index][n + temp_row_index] = 1;
                tableau[temp_row_index][tot_var_count] = dists[temp_row_index];
                temp_row_index++;
            }
        }
        for(int i = 0; i < n; i++){
            tableau[tableau.length - 1][i] = 1;
        }
        
        // System.out.println(Arrays.deepToString(tableau).replace("],", ",\n"));
        
        int[] cj_columns = new int[tot_var_count];
        int[] cj_rows = new int[ineq_count];
        for(int i = 0; i < n; i++){
            cj_columns[i] = 1;
        }
        
        while(!is_optimal(tableau[tableau.length - 1])){
            int pivot_column = 0;
            for(int i = 0; i < n; i++){
                if(tableau[tableau.length - 1][i] > tableau[tableau.length - 1][pivot_column]){
                    pivot_column = i;
                }
            }
            
            String entering_variable = (String) dict.get(pivot_column);
            
            double[] divisors = new double[ineq_count];
            double[] constants = new double[ineq_count];
            for(int i = 0; i < ineq_count; i++){
                divisors[i] = tableau[i][pivot_column];
                constants[i] = tableau[i][tableau[i].length - 1];
            }
            int pivot_row = get_pivot_row(constants, divisors);
            
            solution_mix[pivot_row] = entering_variable;
            cj_rows[pivot_row] = cj_columns[(int) dict.get(entering_variable)];
            
            double pivot_number = tableau[pivot_row][pivot_column];
            for(int i = 0; i < tableau[pivot_row].length; i++){
                tableau[pivot_row][i] = tableau[pivot_row][i] / pivot_number;
            }
            
            for(int i = 0; i < ineq_count; i++){
                if(i != pivot_row){
                    double old_row_value = tableau[i][pivot_column]; // Arrays.copyOf(tableau[i], tableau[i].length);
                    for(int j = 0; j < tableau[i].length; j++){
                        tableau[i][j] = tableau[i][j] - old_row_value * tableau[pivot_row][j];
                    }
                }
            }
            
            /*
            for(int i = 0; i < tableau[tableau.length - 1].length; i++){
                double old_row_value = tableau[tableau.length - 1][pivot_column];
                tableau[tableau.length - 1][i] = tableau[tableau.length - 1][i] - old_row_value * tableau[pivot_row][i];
            }
            */
            
            for(int i = 0; i < n; i++){
                double sum = 0;
                for(int j = 0; j < ineq_count; j++){
                    sum += cj_rows[j] * tableau[j][i];
                }
                tableau[tableau.length - 2][i] = sum;
            }
            
            for(int i = 0; i < n; i++){
                tableau[tableau.length - 1][i] = cj_columns[i] - tableau[tableau.length - 2][i];
            }
        }
        
        double tot_sum = 0;
        for(int i = 0; i < ineq_count; i++){
            tot_sum += tableau[i][tableau[i].length - 1]; //cj_columns[(int) dict.get(solution_mix[i])];
            System.out.println(tableau[i][tableau[i].length - 1]);
        }
        
        // System.out.println(Arrays.deepToString(tableau).replace("],", "],\n"));
        
        
        DecimalFormatSymbols separator = new DecimalFormatSymbols(Locale.getDefault());
        separator.setDecimalSeparator('.');
        DecimalFormat f = new DecimalFormat("0.00", separator);
        System.out.println(f.format(tot_sum));
        
        // System.out.println(2 * Math.PI * tot_sum);
    }
    
    private static boolean is_optimal(double[] objective_function){
        for(Double i : objective_function){
            if(i > 0){
                return false;
            }
        }
        return true;
    }

    private static int get_pivot_row(double[] constants, double[] divisors){
        double[] ratios = new double[constants.length];
        for(int i = 0; i < constants.length; i++){
            ratios[i] = (divisors[i] != 0) ? constants[i] / divisors[i] : Double.MAX_VALUE;
        }
        double smallest_ratio = Double.MAX_VALUE;
        int index = 0;
        for(int i = 0; i < ratios.length; i++){
            if(ratios[i] < smallest_ratio && ratios[i] >= 0){
                smallest_ratio = ratios[i];
                index = i;
            }
        }
        return index;
    }
    
}
