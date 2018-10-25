public class functions {


    int fib(int n, int[]memo){

        if(n<=0){
            return 0;
        }
        else if(n==1){
            return 1;
        }
        else if(memo[n-1] == 0){
            memo[n-1] = fib(n-1, memo) + fib(n-2, memo);
            return memo[n-1];
            //System.out.println(memo[n-1]);
        }
        else {
            return memo[n - 1];
        }

    }

    /*long fib(int n) {

        if (n <= 0) {
            return 0;
        }
        else if (n == 1) {
            return 1;
        }
        else{
            return fib(n-1)+fib(n-2);
        }
    }*/

    int[] mergeSort(int[]arrayA){
        int n = arrayA.length;
        int[]sortedArray;
        for(int  i= 0; i<n/2; i++){

            if(n=1)

            return mergeSort(arrayA);
        }
        for(int i = n/2; i<n; i++){
            return mergeSort(arrayA);
        }

        //System.out.println("n "+ n);
        return sortedArray;
    }

}
