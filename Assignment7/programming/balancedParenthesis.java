import java.util.*;

class balancedParenthesis {
    public boolean isValid(String s) {
        Stack<Character> st = new Stack<>();

        for(char ch : s.toCharArray()){
            if(ch == '(' || ch == '{' || ch == '['){
                st.push(ch);
            }

            if(ch == ')' || ch == '}' || ch == ']'){

                if(st.isEmpty()) return false;

                if((ch == ')' && st.peek() != '(') || 
                        (ch == ']' && st.peek() != '[') ||
                        (ch == '}' && st.peek() != '{')){
                            return false;
                }
                
                // if match then pop the matching opening bracket
                st.pop();
            }
        }

        return true;
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter brackets: ");
        String s = sc.nextLine();

        balancedParenthesis obj = new balancedParenthesis();

        if (obj.isValid(s)) {
            System.out.println("Valid Parentheses");
        } else {
            System.out.println("Invalid Parentheses");
        }

        sc.close();
    }


}