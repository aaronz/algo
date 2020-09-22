package leetcode.java;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;

public class Permutation {
    public static void main(String[] args) {
        int[] nums = { 1, 2, 3, 4 };
        // List<List<Integer>> result = permute(nums);
        // printList(result);
        List<List<Integer>> result2 = permute2(nums);
        printList(result2);
    }

    private static void printList(List<List<Integer>> result){

        for (int i = 0; i < result.size(); i++) {
            for (int j = 0; j < result.get(i).size(); j++) {
                System.out.print(result.get(i).get(j));
            }
            System.out.println();
        }
    }

    private static List<List<Integer>> res = new LinkedList<>();

    private static List<List<Integer>> permute(int[] nums) {
        LinkedList<Integer> track = new LinkedList<>();
        backtrack(nums, track);
        return res;
    }

    private static void backtrack(int[] nums, LinkedList<Integer> track) {
        if (nums.length == track.size()) {
            res.add(new LinkedList<>(track));
            return;
        }

        for (int i = 0; i < nums.length; i++) {
            if (track.contains(nums[i])) {
                continue;
            }

            track.add(nums[i]);
            backtrack(nums, track);
            track.removeLast();
        }
    }

    private static List<List<Integer>> permute2(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        List<Integer> output = new ArrayList<>();
        for (int num : nums) {
            output.add(num);
        }
        backtrackSwap(output.size(), result, output, 0);
        return result;
    }

    private static void backtrackSwap(int n, List<List<Integer>> result, List<Integer> output, int first) {
        if (first == n) {
            result.add(new ArrayList<>(output));
            return;
        }

        for (int i = first; i < output.size(); i++) {
            Collections.swap(output, i, first);
            backtrackSwap(n, result, output, first + 1);
            Collections.swap(output, i, first);
        }
    }

}
