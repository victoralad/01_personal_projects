public class Binary_search {



    public static boolean recursive_search(int[] array, int x, int left, int right){

        if(left>right){
            System.out.println("Number not found");
            return false;
        }

        int mid = left + ((right - left)/2);
        if(array[mid] == x){
            System.out.println("Number has been found at index: " + mid);
            return true;
        }
        else if(x < array[mid]){
            return recursive_search(array, x, left, mid - 1);
        }
        else{
            return recursive_search(array, x, mid + 1, right);
        }

    }
    public static boolean recursion(int[] array, int x){
        return recursive_search(array, x, 0, array.length - 1);
    }

    public static boolean iterative_search(int[] array, int x){

        int left = 0;
        int right = array.length - 1;

        while(left < right){
            int mid = left + ((right - left)/2);
            if(array[mid] == x){
                System.out.println("Number found at index: " + mid);
                return true;
            }
            else if(x < array[mid]){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }

        }
        System.out.println("Number not found");
        return false;

    }

    public static boolean iteration(int[] array, int x){
        return iterative_search(array, x);
    }
}
