public class dop2 {
    public static void main(String[] args) {
        CircularBuffer buffer = new CircularBuffer(5);
        buffer.addElement(22);
        buffer.addElement(11);
        buffer.addElement(99);
        buffer.addElement(55);
        buffer.addElement(33);

        System.out.println("Исходный буфер:");
        buffer.printForward();

        buffer.selectionSort();
        System.out.println("Отсортированный буфер:");
        buffer.printForward();
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

    // Метод сортировки выбором
    public void selectionSort() {
        for (int i = 0; i < size - 1; i++) {
            int minIndex = i;
            for (int j = i + 1; j < size; j++) {
                if (array[(readPtr + j) % capacity] < array[(readPtr + minIndex) % capacity]) {
                    minIndex = j;
                }
            }
            // Обмен местами элементов
            int temp = array[(readPtr + minIndex) % capacity];
            array[(readPtr + minIndex) % capacity] = array[(readPtr + i) % capacity];
            array[(readPtr + i) % capacity] = temp;
        }
    }
}

