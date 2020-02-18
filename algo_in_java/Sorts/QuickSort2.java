package algo_in_java.Sorts;

class QuickSort2 {
    public int[] sortArray(int[] nums) {
        quickSort(nums, 0, nums.length - 1);
        return nums;
    }

    public void quickSort(int[] nums, int left, int right) {
        if (left >= right)
            return;
        int pivot = partition(nums, left, right);
        quickSort(nums, left, pivot - 1);
        quickSort(nums, pivot + 1, right);
    }

    private int partition(int[] nums, int left, int right) {
        int pivot = nums[left];
        int p = left;
        for (int i = left + 1; i <= right; i++) {
            if (nums[i] < pivot) {
                System.out.println("nums[i]:" + nums[i] + " pivot:" + pivot + " i:" + i + " left:" + left + " p:" + p);
                //swap(nums, i, ++p);
                ++p;
            }
        }
        swap(nums, left, p);
        return p;
    }

    private void swap(int[] nums, int i, int j) {
        System.out.println("swap:" + i + "and" + j);
        if (i == j)
            return;
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    public static void main(String[] args) {
        QuickSort2 qs = new QuickSort2();
        int[] array = { 5, 4, 3, 1, 3, 7, 8, 9 };
        qs.sortArray(array);
        for(int i = 0; i < array.length; i++){
            System.out.print(i);
            System.err.print(",");
        }
    }
}