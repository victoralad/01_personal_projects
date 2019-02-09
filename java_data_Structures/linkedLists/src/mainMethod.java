public class mainMethod {

    public static void main(String[] args){
        singly_linkedList list = new singly_linkedList();
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
        list.deleteAt(1);
        list.show();
        list.size();
    }
}