public class stack_dynamic_array {

    int capacity = 2;
    int stack[] = new int[capacity];
    int top = 0;

    private void shrink(){
        int length = top;
        if (length<= (capacity/4)){
            capacity /=2;
            int newStack[] = new int[capacity];
            System.arraycopy(stack, 0, newStack, 0, length);
            stack = newStack;
        }

    }

    private void expand(){
        int length = top;
        int newStack[] = new int[capacity *2];
        System.arraycopy(stack, 0, newStack, 0, length);
        stack = newStack;
        capacity *=2;

    }

    public void push(int data){
        if(top == capacity){
            expand();

        }
            stack[top] = data;
            top++;

    }

    public int pop(){

        int data = 0;
        if(top>0){
            top--;
            data = stack[top];
            stack[top] = 0;
            shrink();
        }
        else{
            System.out.println("Stack is already empty");
        }
        return data;
    }

    public int peek(){
        if(top>0){
            int data;
            data = stack[top - 1];
            System.out.println("The top of the stack is "+ data + " at position: "+ top);
            return data;
        }
        else{
            System.out.println("The stack is empty");
            return 0;
        }
    }

    public int size(){
        System.out.println("The size of the stack is: "+ capacity);
        return capacity;
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