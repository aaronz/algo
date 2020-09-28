package leetcode.java;

import java.util.Stack;

public class NextGreaterElementV2 {

    public static void main(String[] args) {
        int[] nums = { 1, 2, 1 };
        int[] result = nextGreaterElements(nums);
        for (int i : result) {
            System.out.println(i);
        }
    }

    private static int[] nextGreaterElements(int[] nums) {
        int[] temp = new int[nums.length * 2];
        for (int i = 0; i < nums.length; i++) {
            temp[i] = nums[i];
            temp[i + nums.length] = nums[i];
        }

        Stack<Integer> stack = new Stack<>();
        int[] result = new int[nums.length];
        for (int i = temp.length - 1; i >= 0; i--) {
            while (!stack.isEmpty() && stack.peek() <= temp[i]) {
                stack.pop();
            }
            if (i < nums.length) {
                result[i] = stack.isEmpty() ? -1 : stack.peek();
            }
            stack.push(temp[i]);

        }
        return result;
    }

}
