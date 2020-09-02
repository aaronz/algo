package leetcode.java;

public class ValidTree {
    public static void main(String[] args) {
        int[][] edges = { { 0, 1 }, { 0, 2 }, { 0, 3 }, { 1, 4 } };
        boolean result = validTree(5, edges);
        System.out.println(result);
    }

    public static boolean validTree(int n, int[][] edges) {
        DisjointSet set = new DisjointSet(n);
        for (int[] edge : edges) {
            if (!set.union(edge[0], edge[1])) {
                return false;
            }
        }
        return set.getCount() == 1;
    }
}