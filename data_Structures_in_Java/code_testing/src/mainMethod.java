import java.util.Arrays;
public class mainMethod {

    public static void main(String[] args){

        long startTime = System.nanoTime();



        functions func = new functions();
        int n = 5;
        int memo[] = new int[n];

        //System.out.println(func.fib(n, memo));
        //System.out.println(func.fib(n));

        int arrayA[] = {1, 2, 3, 4};
        System.out.println(Arrays.toString(func.mergeSort(arrayA)));

        long endTime   = System.nanoTime();
        double totalTime = (endTime - startTime)/1000000.0;
        System.out.println("totalTIme: " + totalTime + " ms");

    }
}
