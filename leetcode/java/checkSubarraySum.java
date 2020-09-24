package leetcode.java;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

public class checkSubarraySum {

    public static void main(String[] args) {
        int[] nums = { 4, 0, 5, 7 };
        boolean result = checkSubarraySum(nums, 10);
        System.out.println(result);
    }

    private static boolean checkSubarraySum(int[] nums, int k) {
        int pre = 0;
        HashMap<Integer, List<Integer>> map = new HashMap<>();
        List<Integer> first = new ArrayList<>();
        first.add(-1);
        map.put(0, first);
        for (int i = 0; i < nums.length; i++) {
            pre += nums[i];
            if (k != 0) {
                pre = pre % k;
            }
            if (map.containsKey(pre)) {
                List<Integer> l = map.get(pre);
                if (!l.isEmpty() && (i - l.get(0)) > 1) {
                    return true;
                }
                map.get(pre).add(i);
            } else {
                List<Integer> l = new ArrayList<>();
                l.add(i);
                map.put(pre, l);
            }
        }
        return false;
    }
}
