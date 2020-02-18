package data_structures.java.hash;

class LinkedList {
    private Node head;
    private int size;

    public LinkedList() {
        head = null;
        size = 0;
    }

    public void insert(int data) {
        Node newNode = new Node(data);

        size++;
        if (head == null) {
            head = newNode;
        } else {
            newNode.next = head;
            head = newNode;
        }
    }

    public void delete(int data) {
        if(size == 0){
            System.out.println("UnderFlow!");
            return;
        }
        else{
            Node current = head;
            if(current.data == data){
                head = current.next;
                size--;
                return;
            } else {
                while(current.next.next != null){
                    if(current.next.data == data){
                        current.next = current.next.next;
                        size--;
                        return;
                    } else {
                        current = current.next;
                    }
                }
                System.out.println("Key not found!");
            }
        }
    }

    public void display(){
        Node temp = head;
        while(temp != null){
            System.out.print(temp.data);
            System.err.print("->");
            temp = temp.next;
        }
        System.out.println();
    }
}

class Node {
    int data;
    Node next;

    public Node(int data) {
        this.data = data;
        this.next = null;
    }
}