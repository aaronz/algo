package leetcode.java;

import java.util.Arrays;
import java.util.HashSet;

public class IsUnique {
    public static void main(String[] args) {
        String astr = "leetcode";
        boolean result = isUniqueWithSet(astr);
        System.out.println(result);
    }

    public static boolean isUnique(String astr) {
        if (astr == null || astr.length() <= 1) {
            return true;
        }
        char[] chars = astr.toCharArray();
        Arrays.sort(chars);
        char prev = chars[0];
        for (int i = 1; i < chars.length; i++) {
            if (chars[i] == prev) {
                return false;
            } else {
                prev = chars[i];
            }
        }
        return true;
    }

    private static boolean isUniqueWithBit(String astr) {
        if (astr == null || astr.length() <= 1) {
            return true;
        }
        int mark = 0;
        for (char c : astr.toCharArray()) {
            int moveBit = c - 'a';
            if ((mark ^ (1 << moveBit)) == (1 << moveBit)) {
                return false;
            } else {
                mark |= (1 << moveBit);
            }
        }
        return true;
    }

    private static boolean isUniqueWithSet(String astr) {
        if (astr == null || astr.length() <= 1) {
            return true;
        }
        HashSet<Character> set = new HashSet<>();
        for (char c : astr.toCharArray()) {
            if (set.contains(c)) {
                return false;
            } else {
                set.add(c);
            }
        }
        return true;
    }
}
