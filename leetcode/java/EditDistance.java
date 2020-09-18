package leetcode.java;

import java.util.HashMap;

public class EditDistance {

    public static void main(String[] args) {
        String from = "intention";
        String to = "execution";
        int result = minEditDistanceDP(from, to);
        System.out.println(result);

        String from2 = "horse";
        String to2 = "ros";
        int result2 = minEditDistanceDP(from2, to2);
        System.out.println(result2);
    }

    private static int minEditDistance(String from, String to) {
        if (from == null) {
            from = "";
        }
        if (to == null) {
            to = "";
        }
        memo.clear();
        return minEditDistance(from.toCharArray(), 0, to.toCharArray(), 0);
    }

    private static HashMap<String, Integer> memo = new HashMap<>();

    private static int minEditDistance(char[] from, int index_from, char[] to, int index_to) {
        String key = index_from + "_" + index_to;
        int result;
        if (memo.containsKey(key)) {
            return memo.get(key);
        } else {
            if (index_from > (from.length - 1) || index_to > (to.length - 1)) {
                result = Math.abs((from.length - index_from) - (to.length - index_to));
            } else {
                if (from[index_from] == to[index_to]) {
                    result = minEditDistance(from, index_from + 1, to, index_to + 1);
                } else {
                    result = Math.min(
                            Math.min(minEditDistance(from, index_from + 1, to, index_to) + 1,
                                    minEditDistance(from, index_from, to, index_to + 1) + 1),
                            minEditDistance(from, index_from + 1, to, index_to + 1) + 1);
                }
            }
            memo.put(key, result);
            return result;
        }
    }

    private static int minEditDistanceDP(String from, String to) {
        char[] f = from.toCharArray();
        char[] t = to.toCharArray();
        int m = f.length + 1;
        int n = t.length + 1;

        int[][] dp = new int[m][n];
        for (int i = 0; i < m; i++) {
            dp[i][0] = i;
        }

        for(int j = 0; j < n; j++) {
            dp[0][j] = j;
        }

        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                int up = dp[i-1][j];
                int left = dp[i][j-1];
                int up_left = dp[i-1][j-1];
                if(f[i - 1] == t[j - 1]) {
                    dp[i][j] = up_left;
                } else {
                    dp[i][j] = Math.min(Math.min(up, left), up_left) + 1;
                }
            }
        }
        printDP(dp, m, n);
        return dp[m-1][n-1];
    }

    private static void printDP(int[][] dp, int m, int n) {
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                System.out.print(dp[i][j]);
                System.out.print(" ");
            }
            System.out.println();
        }
    }

}
