public class mainMethod {

    public static void main(String[] args){
        doubly_linkedList list = new doubly_linkedList();
        list.insert(5);
        list.insert(4);
        list.insert(9);
        list.size();
        list.insert(15);
        list.insert(7);
        list.show();
        list.delete();
        list.show();
        list.insertAtStart(2);
        list.show();
        list.insertAt(3, 12);
        list.show();
        list.deleteAt(6);
        list.show();
        list.size();
    }
}