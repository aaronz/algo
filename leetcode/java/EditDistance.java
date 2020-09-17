package leetcode.java;

import java.util.HashMap;

public class EditDistance {

    public static void main(String[] args) {
        String from = "intention";
        String to = "execution";
        int result = minEditDistance(from.toCharArray(), 0, to.toCharArray(), 0);
        System.out.println(result);
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

}
