public class Binary_Tree {

    Node root;


    //Node n;

    //check out how the call stack works for recursion

    public void insert(int value){
        Node n = new Node(value);

        if(root == null){
            root = n;
        }
        else {
            Node temp = root;
            while (temp != null) {
                if (value <= temp.data) {
                    if(temp.left != null){
                        temp = temp.left;
                    }
                    else{
                        temp.left = n;
                        break;
                    }
                }
                else {
                    if(temp.right != null){
                        temp = temp.right;
                    }
                    else{
                        temp.right = n;
                        //System.out.println("hey");
                        break;
                    }
                }

            }

        }

    }

    public void delete(int value){
        Node temp = root;
        Node parent = root;
        if(root == null){
            System.out.println("Tree is already empty");
        }
        else{

            while (temp.data != value) {
                parent = temp;
                if(temp.data <= value){
                    temp = temp.left;
                }
                else{
                    temp = temp.right;
                }
                if(temp == null){
                    System.out.println("Value not found");
                }

            }
        }
        if(parent.left == null && parent.right == null){

        }
    }

    /*public void insert(int value){
        Node n = new Node(value);

        if(root == null){
            root = n;
        }
        else{
            Node temp = root;
            if(n.data<=temp.data){
                if(temp.left == null){
                    temp.left = n;
                    System.out.println("yup");
                }
                else{
                    insert(value);
                }

            }
            else{
                if(temp.right == null){
                    temp.right = n;
                    System.out.println("damn");
                }
                else{
                    insert(value);
                }
            }
        }




    }
*/


    public void printInOrder(Node temp){

        if(temp == null){
            if(root == null){
                System.out.println("Tree is empty");
            }
        }
        else{

            printInOrder(temp.left);

            System.out.println(temp.data);

            printInOrder(temp.right);


        }
    }

    public void printPreOrder(Node temp){

        if(temp == null){
            if(root == null){
                System.out.println("Tree is empty");
            }
        }
        else{


            System.out.println(temp.data);

            printInOrder(temp.left);

            printInOrder(temp.right);


        }
    }

    public void printPostOrder(Node temp){

        if(temp == null){
            if(root == null){
                System.out.println("Tree is empty");
            }
        }
        else{


            printInOrder(temp.left);

            printInOrder(temp.right);

            System.out.println(temp.data);


        }
    }
}
