public class mainMethod {

    public static void main(String[] args){
        Binary_Tree tree = new Binary_Tree();

        tree.insert(5);
        tree.insert(2);
        tree.insert(6);
        tree.insert(1);
        tree.insert(4);
        tree.printPostOrder(tree.root);
    }
}
