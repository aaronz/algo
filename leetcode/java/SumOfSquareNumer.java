package leetcode.java;

public class SumOfSquareNumer {
    public static void main(String[] args) {
        boolean result = judgeSquareNumber(5);
        System.out.println(result);
    }

    public static boolean judgeSquareNumber(int target) {
        if (target < 0)
            return false;
        int i = 0, j = (int) Math.sqrt(target);
        while (i < j) {
            int sum = i * i + j * j;
            if(sum == target){
                return true;
            } else if ( sum < target) {
                i++;
            } else {
                j++;
            }
        }
        return false;
    }
}