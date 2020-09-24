package leetcode.java;

import java.util.HashMap;

public class SubarraySum {
    public static void main(String[] args) {
        int[] nums = {1,2,3,1,2,3};
        int result = subarraySum(nums, 3);
        System.out.println(result);
    }

    private static int subarraySum(int[] nums, int target) {
        int pre = 0;
        int total = 0;
        HashMap<Integer, Integer> map = new HashMap<>();
        map.put(0, 1);
        for(int i = 0; i < nums.length; i++) {
            pre += nums[i];
            if(map.containsKey(pre - target)) {
                total += map.get(pre - target);
            }
            map.put(pre, map.getOrDefault(pre, 0) + 1);
        }
        return total;
    }
}
