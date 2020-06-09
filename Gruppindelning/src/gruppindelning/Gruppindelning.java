/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package gruppindelning;

import java.util.ArrayList;
import java.util.Scanner;

/**
 *
 * @author julius.thunstrom
 */
public class Gruppindelning {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner scan = new Scanner(System.in);

        int peopleCount = scan.nextInt();
        scan.nextLine();

        ArrayList<String> people = new ArrayList<>();

        for (int i = 0; i < peopleCount; i++) {
            people.add(scan.nextLine());
        }

        int pairs = scan.nextInt();
        scan.nextLine();

        ArrayList<String> dict = new ArrayList<>();
        for (int i = 0; i < pairs; i++) {
            String[] temp = scan.nextLine().split(" ");
            dict.add(temp[0]);
            dict.add(temp[1]);
        }

        int groupCount = 0;

        ArrayList<String> used = new ArrayList<>();
        
        while (dict.size() > 0) {
            groupCount++;
            used.add(dict.get(0));
            used.add(dict.get(1));
            
            int i = 2;
            while (i < dict.size()) {
                if (contains(used, dict.get(i), dict.get(i + 1))) {
                    used.add(dict.get(i));
                    used.add(dict.get(i + 1));

                    int index1 = people.indexOf(dict.get(i));
                    int index2 = people.indexOf(dict.get(i + 1));
                    if (index1 != -1 && index2 != -1) {
                        people.remove(index1);
                        dict.remove(i);
                        people.remove(people.indexOf(dict.get(i)));
                        dict.remove(i);
                    } 
                    else if (index1 != -1) {
                        people.remove(index1);
                        dict.remove(i);
                        dict.remove(i);
                    } 
                    else if (index2 != -1) {
                        people.remove(index2);
                        dict.remove(i);
                        dict.remove(i);
                    }
                } 
                else {
                    i += 2;
                }
            }
            
            used.clear();
            
            int index1 = people.indexOf(dict.get(0));
            int index2 = people.indexOf(dict.get(1));
            if (index1 != -1 && index2 != -1) {
                people.remove(index1);
                dict.remove(0);
                people.remove(people.indexOf(dict.get(0)));
                dict.remove(0);
            } 
            else if (index1 != -1) {
                people.remove(index1);
                dict.remove(0);
                dict.remove(0);
            } 
            else if (index2 != -1) {
                people.remove(index2);
                dict.remove(0);
                dict.remove(0);
            }
        }

        groupCount += people.size();
        
        System.out.println(groupCount);
    }

    public static boolean contains(ArrayList<String> list, String toFind1, String toFind2) {
        boolean result = false;
        for (int i = list.size() - 1; i >= 0; i--) {
            if (list.get(i).equals(toFind1) || list.get(i).equals(toFind2)) {
                result = true;
                break;
            }
        }
        return result;
    }

}
