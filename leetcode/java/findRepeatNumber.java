package leetcode.java;

import java.util.HashSet;

public class FindRepeatNumber {

    public static int findRepeatNumber(int[] nums) {
        HashSet<Integer> set = new HashSet<>();
        for (int num : nums) {
            if (set.contains(num)) {
                return num;
            } else {
                set.add(num);
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        int[] nums = { 2, 3, 1, 0, 2, 5, 3 };
        int result = findRepeatNumber(nums);
        System.out.println(result);
    }
}
