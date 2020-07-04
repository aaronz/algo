package leetcode.java;

class Solution {
    public static void main(String[] args) {
        int[] numbers = new int[] {3,4,6,8,9};
        int target = 10;
        int[] result = twoSum(numbers, target);
        if(result != null){
            for(int i : result){
                System.out.println(i);
            }
        }
    }

    public static int[] twoSum(int[] numbers, int target) {
        if (numbers == null)
            return null;

        int i = 0, j = numbers.length - 1;
        while (i < j) {
            int sum = numbers[i] + numbers[j];
            if (sum == target) {
                return new int[] { i + 1, j + 1 };
            } else if (sum < target) {
                i++;
            } else {
                j--;
            }
        }
        return null;
    }
}