public class dop {
    public static void main(String[] args) {
        CircularDoublyLinkedList list = new CircularDoublyLinkedList();
        list.addLast(22);
        list.addLast(11);
        list.addLast(99);
        list.addLast(55);
        list.addLast(33);

        System.out.println("Исходный список:");
        list.printForward();

        list.insertionSort();
        System.out.println("Отсортированный список:");
        list.printForward();
    }
}



class ANode {
    int data;
    ANode prev;
    ANode next;

    public ANode(int data) {
        this.data = data;
    }
}

class CircularDoublyLinkedList {
    private ANode head = null;
    private ANode tail = null;
    private int size = 0;

    public void addFirst(int data) {
        ANode newANode = new ANode(data);
        if (head == null) {
            head = newANode;
            tail = newANode;
            head.next = head;
            head.prev = head;
        } else {
            newANode.next = head;
            newANode.prev = tail;
            head.prev = newANode;
            tail.next = newANode;
            head = newANode;
        }
        size++;
    }

    public void addLast(int data) {
        ANode newANode = new ANode(data);
        if (head == null) {
            head = newANode;
            tail = newANode;
            head.next = head;
            head.prev = head;
        } else {
            newANode.next = head;
            newANode.prev = tail;
            tail.next = newANode;
            head.prev = newANode;
            tail = newANode;
        }
        size++;
    }

    public void addMiddle(int data) {
        if (head == null) {
            addFirst(data);
        } else {
            ANode newANode = new ANode(data);
            ANode current = head;
            for (int i = 0; i < size / 2; i++) {
                current = current.next;
            }
            newANode.next = current;
            newANode.prev = current.prev;
            current.prev.next = newANode;
            current.prev = newANode;
            size++;
        }
    }

    public void remove(int index) {
        if (head == null) return;
        ANode current = head;
        for(int i = 1; i < index; i++){
            current = current.next;
        }
        current.prev.next = current.next;
        current.next.prev = current.prev;
        if (current == head) head = current.next;
        if (current == tail) tail = current.prev;
        size -= 1;
    }

    public int size() {
        return size;
    }

    public void printForward() {
        if (head == null) return;
        ANode current = head;
        do {
            System.out.print(current.data + " ");
            current = current.next;
        } while (current != head);
        System.out.println();
    }

    public void printBackward() {
        if (tail == null) return;
        ANode current = tail;
        do {
            System.out.print(current.data + " ");
            current = current.prev;
        } while (current != tail);
        System.out.println();
    }

    public void insertionSort() {
        if (head == null || head.next == head) return;

        ANode sorted = null;
        ANode current = head;

        do {
            ANode next = current.next;
            if (sorted == null) {
                current.prev = current.next = current;
                sorted = current;
            } else {
                ANode position = sorted;
                do {
                    if (current.data < position.data) break;
                    position = position.next;
                } while (position != sorted);

                if (current.data < sorted.data) sorted = current;

                current.next = position;
                current.prev = position.prev;
                position.prev.next = current;
                position.prev = current;
            }
            current = next;
        } while (current != head);
        head = sorted;
        tail = sorted.prev;
    }
}




class CircularBuffer {
    private int[] array;
    private int writePtr = 0;
    private int readPtr = 0;
    private int size = 0;
    private int capacity;

    public CircularBuffer(int capacity) {
        this.capacity = capacity;
        this.array = new int[capacity];

    }

    public void addElement(int data) {
        if (size == capacity) {
            readPtr = (readPtr + 1) % capacity;
        }
        array[writePtr] = data;
        writePtr = (writePtr + 1) % capacity;

        size++;
    }

    public int getElement() {

        if (size == 0) return 0;
        int data = array[readPtr];
        array[readPtr] = 0;
        readPtr = (readPtr + 1) % capacity;
        size--;
        return data;
    }

    public int size() {
        return size;
    }

    public void printForward() {
        for (int i = 0; i < capacity; i++) {
            System.out.print(array[i] + " ");

        }
        System.out.println();
    }

    public void printBackward() {
        for (int i = capacity - 1; i >= 0; i--) {
                System.out.print(array[i] + " ");
        }
        System.out.println();
    }
}
