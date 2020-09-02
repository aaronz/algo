package leetcode.java;

import java.util.HashSet;
import java.util.Set;

public class XorMax {

    public static int findMaxXor(int[] nums) {
        if (nums == null || nums.length == 0) {
            return 0;
        }
        int max = nums[0];
        for (int i = 0; i < nums.length; i++) {
            max = Math.max(max, nums[i]);
        }
        int L = (Integer.toBinaryString(max)).length();
        int maxXor = 0, currentXor;
        Set<Integer> prefixes = new HashSet<>();
        for (int i = L - 1; i > -1; i--) {
            maxXor <<= 1;
            currentXor = maxXor | 1;
            System.out.println(String.format("maxXor:%d, currentXor:%d", maxXor, currentXor));
            prefixes.clear();
            for (int num : nums) {
                prefixes.add(num >> i);
            }
            for (int p : prefixes) {
                System.out.println(String.format("currentXor:%d^p:%d=%d", currentXor, p, currentXor ^ p));
                if (prefixes.contains(currentXor ^ p)) {
                    maxXor = currentXor;
                    break;
                }
            }
        }
        return maxXor;
    }

    public static int findMaxXorWithTrie(int[] nums) {
        // Compute length L of max number in a binary representation
        int maxNum = nums[0];
        for (int num : nums)
            maxNum = Math.max(maxNum, num);
        int L = (Integer.toBinaryString(maxNum)).length();

        // zero left-padding to ensure L bits for each number
        int n = nums.length, bitmask = 1 << L;
        String[] strNums = new String[n];
        for (int i = 0; i < n; ++i) {
            strNums[i] = Integer.toBinaryString(bitmask | nums[i]).substring(1);
            System.out.println(strNums[i]);
        }

        TrieNode trie = new TrieNode();
        int maxXor = 0;
        for (String num : strNums) {
            TrieNode node = trie, xorNode = trie;
            int currXor = 0;
            for (Character bit : num.toCharArray()) {
                // insert new number in trie
                if (node.children.containsKey(bit)) {
                    node = node.children.get(bit);
                } else {
                    TrieNode newNode = new TrieNode();
                    node.children.put(bit, newNode);
                    node = newNode;
                }

                // compute max xor of that new number
                // with all previously inserted
                Character toggledBit = bit == '1' ? '0' : '1';
                if (xorNode.children.containsKey(toggledBit)) {
                    currXor = (currXor << 1) | 1;
                    xorNode = xorNode.children.get(toggledBit);
                } else {
                    currXor = currXor << 1;
                    xorNode = xorNode.children.get(bit);
                }
            }
            maxXor = Math.max(maxXor, currXor);
        }

        return maxXor;
    }

    public static void main(String[] args) {
        int[] nums = { 3, 10, 5, 25, 2 };
        int result = findMaxXorWithTrie(nums);
        System.out.println(result);
    }

}