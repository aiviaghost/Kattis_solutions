/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package calculator;

import java.text.DecimalFormat;
import java.text.DecimalFormatSymbols;
import java.util.Locale;
import java.util.Scanner;
import java.util.Stack;

public class Calculator {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        DecimalFormatSymbols separator = new DecimalFormatSymbols(Locale.getDefault());
        separator.setDecimalSeparator('.');
        DecimalFormat f = new DecimalFormat("0.00", separator);

        while (scan.hasNext()) {
            System.out.println(f.format(evaluatePostfix(infixToPostfix(scan.nextLine()))));
        }
    }

    private static String infixToPostfix(String input) {
        input = input.replace(" ", "");

        // This loop formats the input so that negative numbers become easier to evaluate, i.e "5+-2" will become "5+(0-2)" and "-5*-2" will become "(0-5)*(0-2)"
        int x = 0;
        while (x < input.length()) {
            if ((x > 0 && isOperator(input.charAt(x - 1)) && isOperator(input.charAt(x))) || (x == 0 && isOperator(input.charAt(x))) || (isOperator(input.charAt(x)) && input.charAt(x - 1) == '(')) {
                int i = lengthOfNumber(input, x + 1);
                String tempS1 = input.substring(0, x);
                String tempS2 = "(0" + input.substring(x, x + 1 + i) + ")";
                String tempS3 = input.substring(x + i + 1, input.length());
                input = tempS1 + tempS2 + tempS3;

                x += i + 4;
            }

            x++;
        }

        String postfix = "";

        Stack<Character> operators = new Stack();

        /*
        * If we detect a number we add it to the postfix string
        * If we detect an opening parenthesis we add it to the stack
        * If we detect a closing parenthesis we pop all operators in the stack and add them to the postfix string up until the opening parenthesis
        * If we detect an operator we pop all operators in the stack with higher precedence and add them to the postfix string, finally we add the current operator to the stack
        * Lastly we add any remaining operators in the stack to the postfix string
         */
        x = 0;
        while (x < input.length()) {
            char tempCh = input.charAt(x);

            if (isDigit(tempCh)) {
                int i = lengthOfNumber(input, x);
                postfix += input.substring(x, x + i) + " ";
                x += i - 1;
            } else if (tempCh == '(') {
                operators.push(tempCh);
            } else if (tempCh == ')') {
                char tempOp = operators.pop();
                while (tempOp != '(') {
                    postfix += tempOp;
                    tempOp = operators.pop();
                }
            } else if (isOperator(tempCh)) {
                while (!operators.isEmpty() && precedence(tempCh) <= precedence(operators.peek())) {
                    postfix += Character.toString(operators.pop());
                }
                operators.push(tempCh);
            }

            x++;
        }

        while (!operators.isEmpty()) {
            postfix += Character.toString(operators.pop());
        }

        return postfix;
    }

    // Method to check if character is one of the supported operators, parentheses are dealt with separately
    private static boolean isOperator(char ch) {
        return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
    }

    //Method to check if character is a digit or not
    private static boolean isDigit(char ch) {
        return ch == '.' || ch == '0' || ch == '1' || ch == '2' || ch == '3' || ch == '4' || ch == '5' || ch == '6' || ch == '7' || ch == '8' || ch == '9';
    }

    // Method to find the length of the current number, parameters are a string and a starting point in the string
    private static int lengthOfNumber(String input, int x) {
        int i = 0;
        while ((x + i) < input.length() && isDigit(input.charAt(x + i))) {
            i++;
        }

        return i;
    }

    // Check precedence of operator by following the order of operations:  ^  >  * /  >  + -
    private static int precedence(char ch) {
        switch (ch) {
            case '^':
                return 4;

            case '*':
            case '/':
                return 3;

            case '+':
            case '-':
                return 2;

            // For this implementation opening parenthesis will have a lower precedence than the other operators mainly so that we do not "pop it" to the postfix string
            case '(':
                return 1;

            default:
                return 0;
        }
    }

    private static Double evaluatePostfix(String postfix) {
        Stack<Double> numbers = new Stack();

        int x = 0;
        while (x < postfix.length()) {
            char tempCh = postfix.charAt(x);

            if (isDigit(tempCh)) {
                int i = lengthOfNumber(postfix, x);
                numbers.push(Double.parseDouble(postfix.substring(x, x + i)));
                x += i - 1;
            } else if (isOperator(tempCh)) {
                numbers.push(performOperator(numbers.pop(), numbers.pop(), tempCh));
            }

            x++;
        }

        return numbers.pop();
    }

    // Method to perform given operator on the last two Doubles in the stack
    private static Double performOperator(Double d1, Double d2, char op) {
        switch (op) {
            case '+':
                return d2 + d1;

            case '-':
                return d2 - d1;

            case '*':
                return d2 * d1;

            case '/':
                return d2 / d1;

            default:
                return null;
        }
    }

}
