package leetcode.java;

public class LongestIncreaseSubstring {

    public static void main(String[] args) {
        int[] nums = { 10, 9, 2, 5, 3, 7, 101, 18 };
        int result = longestIncreaseSubstring(nums);
        System.out.println(result);
    }

    private static int longestIncreaseSubstring(int[] nums) {
        int max = 0;
        int current = 0;
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] > nums[i - 1]) {
                current += 1;
                max = Math.max(current, max);
            } else {
                current = 1;
            }
        }
        return max;
    }

}
