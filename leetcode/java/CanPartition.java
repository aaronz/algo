package leetcode.java;

public class CanPartition {
    public static void main(String[] args) {
        int[] nums = { 3, 3, 3, 4, 5 };
        boolean result = canPartitionDP(nums);
        System.out.println(result);
    }

    public static boolean canPartition(int[] nums) {
        int sum = 0;
        for (int i = 0; i < nums.length; i++) {
            sum += nums[i];
        }

        if (sum % 2 == 1) {
            return false;
        }

        sum /= 2;
        return backtrack(nums, sum, 0);

    }

    private static boolean backtrack(int[] nums, int sum, int index) {
        if (sum == 0) {
            return true;
        } else if (sum < 0) {
            return false;
        } else {
            for (int i = index; i < nums.length; i++) {
                sum -= nums[i];
                if (backtrack(nums, sum, i + 1)) {
                    return true;
                }
                sum += nums[i];
            }
            return false;
        }
    }

    private static boolean canPartitionDP(int[] nums) {
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }

        if (sum % 2 == 1) {
            return false;
        }

        sum /= 2;

        boolean[][] dp = new boolean[nums.length][sum + 1];
        // important: if nums[0] <= sum, then two partition 
        // should be {0}, {nums[0]}.
        if (nums[0] <= sum) {
            dp[0][nums[0]] = true;
        }
        for (int i = 1; i < nums.length; i++) {
            for (int j = 0; j <= sum; j++) {
                if (nums[i] == sum) {
                    dp[i][j] = true;
                } else {
                    if (j > nums[i]) {
                        dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i]];
                    } else {
                        dp[i][j] = dp[i - 1][j];
                    }
                }
            }
        }
        PrintUtil.print(dp);
        return dp[nums.length - 1][sum];
    }
}
