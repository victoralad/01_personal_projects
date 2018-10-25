public class singly_linkedList {

    Node head, tail;
    int size = 0;
    public void insert(int data){

        Node node = new Node();
        node.data = data;

        if(head == null){
            head = node;
            tail = node;
        }
        else{
            tail.next = node;
            tail = node;
        }
        size++;
        System.out.println("insert: " + data);
    }

    public void insertAt(int index, int data){

        Node node = new Node();
        node.data = data;

        if(index==1){
            insertAtStart(data);
        }
        else if(index == size){
            insert(data);
        }
        else {
            if (head == null) {
                System.out.println("List has no head, node will be assigned as head");
                head = node;
                tail = node;
                size++;
            }
            /*else if(index>size+1){
                System.out.println("Index is invalid. The current size of the list is: " + size);

            }*/
            else {
                Node n = head;
                for (int i = 1; i < index - 1; i++) {
                    n = n.next;
                }
                node.next = n.next;
                n.next = node;
                size++;
            }
            System.out.println("insert: " + data + " at pos: " + index);

        }
    }

    public void insertAtStart(int data){

        Node node = new Node();
        node.data = data;

        if(head == null){
            head = node;
            tail = node;
        }
        else{
            //Node n = head;

            node.next = head;
            head = node;
        }
        size++;
        System.out.println("insertAtStart: " + data);
    }

    public void deleteAt(int index){

        if (head == null) {
            System.out.println("List is empty");
        }

        else if(size == 1) {

            if(index> size) {
                System.out.println("Invalid index. The current size of the list is: " + size);
            }
            else{
                head = null;
                tail = null;
                size--;
                System.out.println("List has been rendered empty");
            }
        }
        else {
            if (index == 1) {
                //Node n = new Node();
                Node n = head;
                head = n.next;
                n = null;
                //head = head.next;
                size--;
            } else if (index > size) {
                System.out.println("Invalid index. The current size of the list is: " + size);
            } else {

                Node n = head;
                for (int i = 1; i < index - 1; i++) {
                    n = n.next;
                }
                if(index == size) {
                    tail = n;
                }
                n.next = n.next.next;

                size--;
            }
        }

        System.out.println("delete data at position: "+ index);
    }

    public void delete(){


        if(head == null){
            System.out.println("There's nothing to delete");
        }
        else if(size==1){
            head = null;
            tail = null;
            size--;
            System.out.println("List has been rendered empty");
        }
        else{
            Node n = head;
            while(n.next.next != null){
                //System.out.println("wohoo!");
                //System.out.println(n.data);
                n = n.next;
            }
            n.next = null;
            tail = n;
            size--;
        }
        System.out.println("delete()");
    }

    public void show() {
        Node node = head;
        if (head != null){
            while (node.next != null) {
                System.out.println(node.data);
                node = node.next;
            }

            System.out.println(node.data);
        }
        else{
            System.out.println("Yeah list is empty");
        }
        System.out.println("");
    }

    public void size(){
        System.out.println("The size of the list is: "+ size);
        System.out.println("tail: "+ tail.data);
    }
}