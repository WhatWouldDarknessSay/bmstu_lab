public class dop3 {
    public static void main(String[] args) {
        SelfOrganizingList list = new SelfOrganizingList();

        // Adding elements to the list
        list.add(5);
        list.add(3);
        list.add(8);
        list.add(1);
        list.add(7);

        System.out.println("List before sorting by data:");
        list.printForward();

        // Sorting the list by data
        list.sort();

        // Printing the list after sorting
        System.out.println("List after sorting by data:");
        list.printForward();
        // System.out.println("tail: " + list.tail.data);
    }
}

class CNode {
    int data;
    CNode prev;
    CNode next;
    int counter;

    public CNode(int data)
    {
        this.data = data;
        this.prev = null;
        this.next = null;
        this.counter=0;
    }
}



class SelfOrganizingList {
    private CNode head = null;
    private CNode tail = null;
    private int size=0;

    public int size() {
        return size;
    }

    public void add(int data) {
        CNode newNode = new CNode(data);
        if (head == null) {
            head = tail = newNode;
            head.next = head.prev = head; // Кольцевая связь
        } else {
            tail.next = newNode;
            newNode.prev = tail;
            newNode.next = head;
            head.prev = newNode;
            tail = newNode;
        }
        size++;
    }
    public int get(int index) {
        CNode current = head;
        for (int i = 1; i < index; i++) {
            current = current.next;
        }
        current.counter++;
        selfOrganize(current);
        return current.data;
    }

    public void sort() {
        CNode current = head;
        do {
            CNode next = current.next;
            selfOrganizeByData(current);
            current = next;
        } while (current != head);
    }

    private void selfOrganizeByData(CNode node){
            // System.out.println("haha" + node.data);
        while (node.prev != tail && node.data < node.prev.data && node.counter >= node.prev.counter) {
            // System.out.println("xd");

            if (tail == node) {
                tail = node.prev;
            }

            CNode prevNode = node.prev;
            CNode nextNode = node.next;

            prevNode.prev.next = node;
            node.prev = prevNode.prev;

            node.next = prevNode;
            prevNode.prev = node;

            prevNode.next = nextNode;
            nextNode.prev = prevNode;

            if (head == prevNode) {
                head = node;
            }
        }
    }

    private void selfOrganize(CNode node) {
        while (node.prev != tail && node.counter > node.prev.counter) {
            CNode prevNode = node.prev;
            CNode nextNode = node.next;

            prevNode.prev.next = node;
            node.prev = prevNode.prev;

            node.next = prevNode;
            prevNode.prev = node;

            prevNode.next = nextNode;
            nextNode.prev = prevNode;

            if (head == prevNode) {
                head = node;
            }
        }
    }

    public void remove(int index) {
        if (head == null) return;
        CNode current = head;
        for(int i = 1; i < index; i++){
            current = current.next;
        }
        current.prev.next = current.next;
        current.next.prev = current.prev;
        if (current == head) head = current.next;
        if (current == tail) tail = current.prev;
        size -= 1;
    }

    public void printForward() {
        if (head == null) return;
        CNode current = head;
        do {
            System.out.print(current.data + " ");
            current = current.next;
        } while (current != head);
        System.out.println();
    }

    public void printBackward() {
        if (tail == null) return;
        CNode current = tail;
        do {
            System.out.print(current.data + " ");
            current = current.prev;
        } while (current != tail);
        System.out.println();
    }
}
