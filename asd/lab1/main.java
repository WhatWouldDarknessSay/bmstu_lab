import java.util.Scanner;
public class main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // // Бинарный поиск
        // int size = scanner.nextInt();
        // int[] array = new int[size];
        // for (int i = 0; i < size; i++) { array[i] = scanner.nextInt(); }
        // int num = scanner.nextInt();

        // int n = array.length;
        // boolean swapped;
        // for (int i = 0; i < n - 1; i++) {
        //     swapped = false;
        //     for (int j = 0; j < n - i - 1; j++) {
        //         if (array[j] > array[j + 1]) {
        //             int tmp = array[j];
        //             array[j] = array[j + 1];
        //             array[j + 1] = tmp;
        //             swapped = true;
        //         }
        //     }
        //     if (!swapped) { break; }
        // }
        // System.out.println(binarySearch(array, num));

        // System.out.println(array[binarySearch(array, num)] == num); // проверка

        // // Эратосфен +3
        // int ne = scanner.nextInt();
        // int[] primes = findFirstNPrimes(ne);
        // for (int i = 0;i < primes.length; i++) {
        //     System.out.print(primes[i] + " ");
        // }
        // System.out.println();

        // // Разделение строки +3
        // String input = scanner.nextLine();
        // System.out.println(splitCamelCase(input));

        // // Тире после и перед +3
        // int input = scanner.nextInt();
        // System.out.println(addDashes(input));

        // // Разница максимального и минимального +2
        // int size = scanner.nextInt();
        // int[] array = new int[size];
        // for (int i = 0; i < size; i++) { array[i] = scanner.nextInt(); }
        // System.out.println(findDifference(array));

        // Палиндром +1
        String input = scanner.nextLine();
        System.out.println(isPalindrome(input));
    }

    public static String splitCamelCase(String input) {
        String rez = "";
        for (int i = 0; i < input.length(); i++) {
            char tmp = input.charAt(i);
            if (i > 0 && Character.isUpperCase(tmp)) { // чек на заглавную
                rez += " ";
            }
            rez += tmp;
        }
        return rez;
    }

    public static int binarySearch(int[] array, int n) {
        int i = 0; // левый
        int j = array.length - 1; // правый
        while (i <= j) {
            int k = i + (j - i) / 2;
            if (array[k] == n) {
                return k;
            }
            if (array[k] > n) {
                j = k - 1;
            } else {
                i = k + 1;
            }
        }
        return -1;
    }
    
    public static int[] findFirstNPrimes(int n) {
        int limit = (int) (n * Math.log(n) + n * Math.log(Math.log(n)));   
        boolean[] isPrime = new boolean[limit + 1];
        int[] primes = new int[n];
        for (int i = 2; i <= limit; i++) {
            isPrime[i] = true;
        }
        int counter = 0;
        for (int p = 2; p <= limit && counter < n; p++) {
            if (isPrime[p]) {
                primes[counter] = p;
                counter += 1;
                for (int i = p * p; i <= limit; i += p) {
                    isPrime[i] = false;
                }
            }
        }
        return primes;
    }

    public static String addDashes(int n) {
        String input = Integer.toString(n);
        String result = "";
        boolean prevNechet = false;

        for (int i = 0; i < input.length(); i++) {
            char tmp = input.charAt(i);
            boolean nechet = (Character.getNumericValue(tmp) % 2 != 0);
            if (nechet) {
                if (!prevNechet && !result.isEmpty()) {
                    result += "-";
                }
                result += tmp;
                result += "-";
                prevNechet = true;
            } else {
                result += tmp;
                prevNechet = false;
            }
        }
        if (result.charAt(result.length() - 1) == '-') { // дефис в конце
            result = result.substring(0, result.length() - 1);
        }

        return result;
    }

    public static int findDifference(int[] arr) {
        int maxx = arr[0];
        int minn = arr[0];

        for (int i = 1; i < arr.length; i++) {
            if (arr[i] > maxx) {
                maxx = arr[i];
            }
            if (arr[i] < minn) {
                minn = arr[i];
            }
        }

        return maxx - minn;
    }

    public static boolean isPalindrome(String input) {
    //     int i = 0;
    //     int j = input.length() - 1;

    //     while (i < j) {
    //         if (input.charAt(i) != input.charAt(j)) {
    //             return false;
    //         }
    //         i += 1;
    //         j -= 1;
    //     }
    //     return true;
    String reversed = new StringBuilder(input).reverse().toString();
    return reversed.equals(input);
    }
}
