/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package union_find;

import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;

/**
 *
 * @author Admin
 */
public class Union_find {
    
    static int[] parents;
    static int[] ranks;
    
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException {
        // TODO code application logic here
        
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
        
        String[] nq = in.readLine().split(" ");
        int n = Integer.parseInt(nq[0]);
        int q = Integer.parseInt(nq[1]);
        
        parents = new int[n];
        ranks = new int[n];
        
        for(int i = 0; i < n; i++){
            parents[i] = i;
        }
        
        for(int i = 0; i < q; i++){
            String line = in.readLine();
            
            char op = line.charAt(0);
            
            int last_space = line.lastIndexOf(' ');
            int a = Integer.parseInt(line.substring(2, last_space));
            int b = Integer.parseInt(line.substring(last_space + 1, line.length()));
            
            if(op == '?'){
                if(find(parents[a]) == find(parents[b])){
                    out.println("yes");
                }
                else{
                    out.println("no");
                }
            }
            else{
                union(a, b);
            }
        }
        
        out.flush();
        out.close();
    }
    
    public static void union(int x, int y){
        int xRoot = find(x);
        int yRoot = find(y);
        if(ranks[xRoot] > ranks[yRoot]){
            parents[yRoot] = xRoot;
        }
        else if(ranks[xRoot] < ranks[yRoot]){
            parents[xRoot] = yRoot;
        }
        else if(xRoot != yRoot){
            parents[yRoot] = xRoot;
            ranks[xRoot] = ranks[xRoot] + 1;
        }
    }
    
    public static int find(int x){
        if(parents[x] == x){
            return x;
        }
        else{
            parents[x] = find(parents[x]);
            return parents[x];
        }
    }
}
