public class mainMethod {

    public static void main(String[] args){

        stack_dynamic_array num = new stack_dynamic_array();
        num.push(15);
        num.push(0);
        num.push(1);
        num.push(30);
        num.push(40);
        num.push(60);
        num.push(34);
        num.push(65);
        num.push(23);
        //num.show();

        num.pop();
        num.pop();
        num.pop();
        num.pop();
        //num.pop();
        num.isEmpty();
        num.peek();
        num.size();
        num.show();
    }



}
