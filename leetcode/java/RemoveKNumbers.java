package leetcode.java;

import java.util.LinkedList;

public class RemoveKNumbers {
    public String removeKNumbers(String nums, int k) {
        if (nums == null || nums.isEmpty() || k >= nums.length()) {
            return "0";
        }

        LinkedList<Character> stack = new LinkedList<>();
        int j = k;

        for (Character c : nums.toCharArray()) {
            while (stack.peekLast() != null && stack.peekLast() > c && j > 0) {
                stack.removeLast();
                j--;
            }

            stack.addLast(c);
        }

        while (stack.peekFirst() != null && stack.peekFirst() == '0') {
            stack.removeFirst();
        }

        StringBuilder result = new StringBuilder();
        for (int i = 0; i < nums.length() - k && i < stack.size(); i++) {
            result.append(stack.get(i));
        }
        return result.length() == 0 ? "0" : result.toString();
    }

    public static void main(String[] args) {
        RemoveKNumbers solution = new RemoveKNumbers();
        // String nums = "1432219";
        // String result = solution.removeKNumbers(nums, 3);
        // System.out.println(result);
        String result = solution.removeKNumbers("10200", 1);
        System.out.println(result);
        // result = solution.removeKNumbers("10", 2);
        // System.out.println(result);
        String result2 = solution.removeKNumbers("112", 1);
        System.out.println(result2);
    }
}