package algo_in_java.Recursion;

import java.util.HashMap;
import java.util.Map;

class Solution {
    public static void main(String[] args) {
        Solution s = new Solution();
        int[] preorder = { 3, 9, 8, 5, 4, 10, 20, 15, 7 };
        int[] inorder = { 4, 5, 8, 10, 9, 3, 15, 20, 7 };
        TreeNode root = s.buildTree(preorder, inorder);
    }

    Map<Integer, Integer> map;

    private TreeNode buildTreeInternal(int[] preorder, int[] inorder, int preStart, int preEnd, int inStart,
            int inEnd) {
        if (preStart > preEnd || inStart > inEnd) {
            return null;
        }

        TreeNode root = new TreeNode(preorder[preStart]);
        int rootIndex = map.get(preorder[preStart]);
        int leftSize = rootIndex - inStart;
        root.left = buildTreeInternal(preorder, inorder, preStart + 1, preStart + leftSize, inStart, rootIndex - 1);
        root.right = buildTreeInternal(preorder, inorder, preStart + leftSize + 1, preEnd, rootIndex + 1, inEnd);
        return root;
    }

    public TreeNode buildTree(int[] preorder, int[] inorder) {
        map = new HashMap<Integer, Integer>();
        for (int i = 0; i < inorder.length; i++) {
            map.put(inorder[i], i);
        }
        return buildTreeInternal(preorder, inorder, 0, preorder.length - 1, 0, inorder.length - 1);
    }
}

class TreeNode {
    TreeNode left;
    TreeNode right;
    int val;

    TreeNode(int x) {
        this.val = x;
    }
}