package leetcode.java;

import java.util.HashMap;

public class SubarrayDivByK {

    public static void main(String[] args) {
        int[] nums = { 1, 2, 3 };
        int result = subarrayDivByK(nums, 3);
        System.out.println(result);
    }

    private static int subarrayDivByK(int[] nums, int k) {
        int pre = 0;
        int total = 0;
        HashMap<Integer, Integer> map = new HashMap<>();
        map.put(0, 1);
        for (int i = 0; i < nums.length; i++) {
            pre = ((pre + nums[i]) % k + k) % k;
            map.put(pre, map.getOrDefault(pre, 0) + 1);
        }
        // 余数相同的相减才能被k整除
        for (Integer value : map.values()) {
            total += (value * (value - 1)) / 2;
        }
        return total;
    }

}
