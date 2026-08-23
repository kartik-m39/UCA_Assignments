import java.util.*;

class evaluatePostfixExpression {
    public int evaluatePostfix(String[] arr) {
        Stack<Integer> st = new Stack<>();

        for(String str : arr){

            if(str.equals("+")){
                int num1 = st.pop();
                int num2 = st.pop();
                st.push(num2 + num1);
            }else if(str.equals("-")){
                int num1 = st.pop();
                int num2 = st.pop();
                st.push(num2 - num1);
            }else if(str.equals("*")){
                int num1 = st.pop();
                int num2 = st.pop();
                st.push(num2 * num1);
            }else if(str.equals("/")){
                int num1 = st.pop();
                int num2 = st.pop();
                st.push(num2 / num1);
            }else if(str.equals("^")){
                int num1 = st.pop();
                int num2 = st.pop();
                st.push((int)Math.pow(num2,num1));
            }else{
                // push the num in the stack
                st.push(Integer.parseInt(str));
            }
        }
        return st.peek();
    }

    public static void main(String[] args) {

        String[] arr = {"2", "3", "1", "*", "+", "9", "-"};

        evaluatePostfixExpression obj = new evaluatePostfixExpression();

        int result = obj.evaluatePostfix(arr);

        System.out.println("Result: " + result);
    }
}