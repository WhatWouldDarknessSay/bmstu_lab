import java.util.Scanner;
public class main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        // ввод массива
        int[] arr = new int[1];
        int count = 0;
        System.out.println("Ввод массива (/ если все)");
        System.out.print("Введите элемент: ");
        String c = scanner.nextLine();
        while (!c.equals("/")) {
            int intv = Integer.parseInt(c);
                if (count == arr.length) {
                    arr = upCap(arr);
                }
                arr[count] = intv; 
                count++;
            System.out.print("Введите элемент: ");
            c = scanner.nextLine();
        }


        System.out.println();
        Tree tr = new Tree();

        for (int i = 0; i < arr.length; i++) {
            tr.addElem(arr[i]);
        }

        //tree sort
        int[] arr_tree = tr.print();
        for(int i=0;i<arr_tree.length;i++){
            System.out.println(arr_tree[i]);
        }

        //shell sort
        System.out.println();
        int[] arr_shell = new int[arr.length];
        System.arraycopy(arr, 0, arr_shell, 0, arr.length);
        shellSort(arr_shell);
        for(int i=0;i<arr_shell.length;i++){
            System.out.println(arr_shell[i]);
        }


        //quicksort
        System.out.println();
        quickSort(arr, 0, arr.length-1);   
        for(int i=0;i<arr.length;i++){
            System.out.println(arr[i]);
        }



    }

    static int[] upCap(int[] arr){
        int[] temp = new int[arr.length+1];
        for(int i=0;i<arr.length;i++){
            temp[i]=arr[i];
        }

        return temp;

    }

    
 
    public static void quickSort(int[] arr, int low, int high) {
        if (low < high) {
            int tmp = workQuicksort(arr, low, high);

            quickSort(arr, low, tmp - 1);
            quickSort(arr, tmp + 1, high);
        }
    }
    
    public static int workQuicksort(int[] arr, int low, int high) {
        int pivot = arr[high];
        int i = (low - 1);

        for (int j = low; j < high; j++) {
            if (arr[j] <= pivot) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;

        return i + 1;
    }

     public static void shellSort(int[] array) {
        int n = array.length;
        for (int gap = n / 2; gap > 0; gap /= 2) {
            for (int i = gap; i < n; i++) {
                int temp = array[i];
                int j;
                for (j = i; j >= gap && array[j - gap] > temp; j -= gap) {
                    array[j] = array[j - gap];
                }
                array[j] = temp;
            }
        }
    }
}

class NodeForTree {
    int value;
    NodeForTree left;
    NodeForTree right;

    public NodeForTree(int elem){
        this.value=elem;
        this.left=null;
        this.right=null;
    }
}

class Tree {
    NodeForTree head;
    int size = 0;
    
    public void addElem(int elem){
        if (head==null) {
            head = new NodeForTree(elem);
            size++;
        } else {
            NodeForTree temp = head;
            while (true) {
                if (elem >= temp.value) {
                    if (temp.right!=null) {
                        temp = temp.right;
                    } else {
                        temp.right = new NodeForTree(elem);
                        size++;
                        break;
                    }
                } else {
                    if (temp.left!=null) {
                        temp=temp.left;
                    } else {
                        temp.left = new NodeForTree(elem);
                        size++;
                        break;
                    }
                }
            }
        }
    }

    public int[] print(){
        int[] arr = new int[size];
        rekursiya(head, arr, 0);

        return arr;
    }

    private int rekursiya(NodeForTree node, int[] arr, int index){
        if (node==null) {
            return index;
        }

        index = rekursiya(node.left, arr, index);

        arr[index] = node.value;
        index++;

        index = rekursiya(node.right, arr, index);
        
        return index;
    }
}
