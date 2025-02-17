import java.util.*;


public class main {
    public static void main(String[] args) {
        ArrayList<Student> arrayList = new ArrayList<>();
        LinkedList<Student> linkedList = new LinkedList<>();
        HashSet<Student> hashSet = new HashSet<>();
        HashMap<Long, Student> hashMap = new HashMap<>();
        Deque<Student> deque = new ArrayDeque<>();

        // Создание 10 000 000 объектов и добавление их в структуры данных
        for (long i = 1; i <= 10_000_000L; i++) {
            Student student = new Student(i, "" + i);
            Collections.addAll(arrayList, student);
            Collections.addAll(linkedList, student);
            hashSet.add(student);
            hashMap.put(i, student);
            deque.add(student);
        }

        // Добавление одного несуществующего элемента в конец (id = 10 000 001)
        Student newStudentEnd = new Student(10_000_001L, "New Student End");
        long startTime = System.nanoTime();
        Collections.addAll(arrayList, newStudentEnd);
        long endTime = System.nanoTime();
        System.out.println("ArrayList add end: " + (endTime - startTime) + " ns");

        startTime = System.nanoTime();
        Collections.addAll(linkedList, newStudentEnd);
        endTime = System.nanoTime();
        System.out.println("LinkedList add end: " + (endTime - startTime) + " ns");

        startTime = System.nanoTime();
        hashSet.add(newStudentEnd);
        endTime = System.nanoTime();
        System.out.println("HashSet add end: " + (endTime - startTime) + " ns");

        startTime = System.nanoTime();
        hashMap.put(100_000_001L, newStudentEnd);
        endTime = System.nanoTime();
        System.out.println("HashMap add end: " + (endTime - startTime) + " ns");

        startTime = System.nanoTime();
        deque.addLast(newStudentEnd);
        endTime = System.nanoTime();
        System.out.println("Deque add end: " + (endTime - startTime) + " ns");

        // Добавление одного несуществующего элемента в начало
        Student newStudentStart = new Student(0L, "New Student Start");
        startTime = System.nanoTime();
        arrayList.add(0, newStudentStart);
        endTime = System.nanoTime();
        System.out.println("ArrayList add start: " + (endTime - startTime) + " ns");

        startTime = System.nanoTime();
        ((LinkedList<Student>) linkedList).addFirst(newStudentStart);
        endTime = System.nanoTime();
        System.out.println("LinkedList add start: " + (endTime - startTime) + " ns");

        startTime = System.nanoTime();
        deque.addFirst(newStudentStart);
        endTime = System.nanoTime();
        System.out.println("Deque add start: " + (endTime - startTime) + " ns");

        // Удаление последнего элемента
        startTime = System.nanoTime();
        arrayList.remove(arrayList.size() - 1);
        endTime = System.nanoTime();
        System.out.println("ArrayList remove end: " + (endTime - startTime) + " ns");

        startTime = System.nanoTime();
        ((LinkedList<Student>) linkedList).removeLast();
        endTime = System.nanoTime();
        System.out.println("LinkedList remove end: " + (endTime - startTime) + " ns");

        startTime = System.nanoTime();
        hashSet.remove(newStudentEnd);
        endTime = System.nanoTime();
        System.out.println("HashSet remove end: " + (endTime - startTime) + " ns");

        startTime = System.nanoTime();
        hashMap.remove(10_000_001L);
        endTime = System.nanoTime();
        System.out.println("HashMap remove end: " + (endTime - startTime) + " ns");

        startTime = System.nanoTime();
        deque.removeLast();
        endTime = System.nanoTime();
        System.out.println("Deque remove end: " + (endTime - startTime) + " ns");


        // Удаление первого элемента
        startTime = System.nanoTime();
        arrayList.remove(0);
        endTime = System.nanoTime();
        System.out.println("ArrayList remove start: " + (endTime - startTime) + " ns");

        startTime = System.nanoTime();
        ((LinkedList<Student>) linkedList).removeFirst();
        endTime = System.nanoTime();
        System.out.println("LinkedList remove start: " + (endTime - startTime) + " ns");

        startTime = System.nanoTime();
        deque.removeFirst();
        endTime = System.nanoTime();
        System.out.println("Deque remove start: " + (endTime - startTime) + " ns");


        // Взятие центрального элемента
        startTime = System.nanoTime();
        arrayList.get(5_000_000);
        endTime = System.nanoTime();
        System.out.println("ArrayList get middle: " + (endTime - startTime) + " ns");

        startTime = System.nanoTime();
        ((LinkedList<Student>) linkedList).get(2_000_000);
        endTime = System.nanoTime();
        System.out.println("LinkedList get middle: " + (endTime - startTime) + " ns");

        startTime = System.nanoTime();
        hashMap.get(5_000_000L);
        endTime = System.nanoTime();
        System.out.println("HashMap get middle: " + (endTime - startTime) + " ns");

        startTime = System.nanoTime();
        Student tmp = deque.toArray(new Student[0])[5_000_000];
        endTime = System.nanoTime();
        System.out.println("Deque get middle: " + (endTime - startTime) + " ns");


        // Взятие последнего элемента
        startTime = System.nanoTime();
        arrayList.get(arrayList.size() - 1);
        endTime = System.nanoTime();
        System.out.println("ArrayList get end: " + (endTime - startTime) + " ns");

        startTime = System.nanoTime();
        ((LinkedList<Student>) linkedList).get(linkedList.size() - 1);
        endTime = System.nanoTime();
        System.out.println("LinkedList get end: " + (endTime - startTime) + " ns");

        startTime = System.nanoTime();
        hashMap.get(100_000_000L);
        endTime = System.nanoTime();
        System.out.println("HashMap get end: " + (endTime - startTime) + " ns");

        startTime = System.nanoTime();
        deque.getLast();
        endTime = System.nanoTime();
        System.out.println("Deque get end: " + (endTime - startTime) + " ns");


        // // A1 кольцевой двунаправленный список
        // CircularDoublyLinkedList list = new CircularDoublyLinkedList();
        // list.addFirst(1);
        // list.addLast(2);
        // list.addMiddle(3);
        // list.printForward();
        // System.out.println("Size: " + list.size());
        // list.remove(4);
        // list.printForward();
        // list.printBackward();
        // System.out.println("Size: " + list.size());
        // // A2 кольцевой буфферный массив
        // CircularBuffer buffer = new CircularBuffer(5);
        // for(int i = 1; i <= 5; i++){
        //     buffer.addElement(i);
        // }
        // buffer.printForward();
        // buffer.addElement(6);
        // buffer.printForward();
        // for (int i = 0; i < 6; i++) {
        //     System.out.println("Элемент: " + buffer.getElement());
        //     buffer.printForward();
        // }
        // System.out.println(buffer.size());
        // //C2 самоорганизующийся список
        // SelfOrganizingList selfOrganizingList = new SelfOrganizingList();
        // for (int i = 1; i <= 5; i++){
        //     selfOrganizingList.add(i);
        // }
        // selfOrganizingList.printForward();
        // selfOrganizingList.printBackward();
        // System.out.println("Значение: " + selfOrganizingList.get(2));
        // selfOrganizingList.printForward();
        // System.out.println("Значение: " + selfOrganizingList.get(3));
        // selfOrganizingList.printForward();
        // System.out.println("Значение: " + selfOrganizingList.get(3));
        // selfOrganizingList.printForward();
    }
}
class Student {
    Long id;
    String name;

    public Student(Long id, String name) {
        this.id = id;
        this.name = name;
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
