package leetcode.java;

import java.util.HashMap;
import java.util.Stack;

public class NextGreaterElement {
    public static void main(final String[] args) {
        final int[] nums1 = { 1, 2, 3, 4, 5 };
        final int[] nums2 = { 1, 2 };
        final int[] result = nextGreaterElement(nums1, nums2);
        for (int i = 0; i < result.length; i++) {
            System.out.print(result[i]);
            System.out.print('\t');
        }
    }

    private static int[] nextGreaterElement(final int[] nums1, final int[] nums2) {
        final int[] result = new int[nums2.length];
        HashMap<Integer, Integer> map = new HashMap<>();
        for(int i = 0; i < nums2.length; i++) {
            map.put(nums2[i], i);
        }
        final Stack<Integer> stack = new Stack<>();
        for (int i = nums1.length - 1; i >= 0; i--) {
            while (!stack.isEmpty() && stack.peek() < nums1[i]) {
                stack.pop();
            }
            if(map.containsKey(nums1[i])){
                result[map.get(nums1[i])] = stack.isEmpty() ? -1: stack.peek();
            }
            stack.push(nums1[i]);
        }
        return result;
    }
}