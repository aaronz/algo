package algo_in_java.Sorts;

class BubbleSort{
    public void sort(int[] array){
        for(int i = 0 ; i < array.length; i++){
            for(int j = 0; j < array.length-1-i; j++){
                if(array[j] > array[j+1]){
                    swap(array, j, j+1);
                }
            }
        }
    }

    public void swap(int[] array, int i, int j){
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }

    public static void main(String[] args){
        int[] array = {5,4,3,2,1,2,3,4,5};
        BubbleSort sort = new BubbleSort();
        sort.sort(array);
        for(int i = 0; i < array.length; i++){
            System.out.print(array[i]);
            System.out.print(",");
        }
    }
}