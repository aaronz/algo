package leetcode.java;

public class MergeTwoList {
    public static void main(String[] args) {
        int[] number1 = { 1, 2, 3, 4, 0, 0, 0, 0 };
        int[] number2 = { 1, 2, 3, 5 };
        merge(number1, 4, number2, 4);
        for(int i = 0; i < 8; i++){
            System.out.println(number1[i]);
        }
    }

    public static void merge(int[] number1, int m, int[] number2, int n) {
        int i = m - 1, j = n - 1;
        int mergeIndex = m + n - 1;
        while (i >= 0 || j >= 0) {
            if (i < 0) {
                number1[mergeIndex--] = number2[j--];
            } else if (j < 0) {
                number1[mergeIndex--] = number1[i--];
            } else if (number1[i] < number2[j]) {
                number1[mergeIndex--] = number2[j--];
            } else {
                number1[mergeIndex--] = number1[i--];
            }
        }
    }
}