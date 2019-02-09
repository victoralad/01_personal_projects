public class stack_array {

    int stack[] = new int[5];
    int top = 0;

    public void push(int data){
        if(top<5){
            stack[top] = data;
            top++;
        }
        else{
            System.out.println("Stack already full. You need to resize array");
        }
    }

    public int pop(){
        if(top>0){
            int data;
            top--;
            data = stack[top];
            stack[top] = 0;
            return data;
        }
        else{
            System.out.println("Stack is already empty");
            return 0;
        }
    }

    public int peek(){
      if(top>0){
          int data;
          data = stack[top - 1];
          System.out.println("The top element is "+ data);
          return data;
      }
      else{
          System.out.println("The stack is empty");
          return 0;
      }
    }

    public int size(){
        System.out.println("The size of the stack is: "+ top);
        return top;
    }

    public boolean isEmpty(){
        boolean empty = top<=0;
        System.out.println("isEmpty: " + empty);
        return top<=0;
    }

    public void show(){
        if(top>0){
            for(int n: stack){
                System.out.println(n + " ");
            }
        }
        else{
            System.out.println("The stack is empty");
        }
        System.out.println( " ");
    }
}