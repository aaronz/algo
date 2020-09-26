package leetcode.java;

import java.util.HashMap;
import java.util.HashSet;

public class MinWindow {

    public static void main(String[] args) {
        // String s = "ADOBECODEBANCABC";
        // String t = "ABC";
        // String result = minWindowsWithOccurrence(s, t);
        // System.out.println(result);

        String s1 = "aab";
        String t1 = "ba";
        String result1 = minWindowsWithOccurrence(s1, t1);
        System.out.println(result1);
    }

    private static String minWindowsWithOccurrence(String s, String t) {
        if (s == null || t == null || s.isEmpty() || t.isEmpty() || s.length() < t.length()) {
            return "";
        }

        HashMap<Character, Integer> need = new HashMap<>();
        for (char c : t.toCharArray()) {
            need.put(c, need.getOrDefault(c, 0) + 1);
        }

        int left = 0, right = 0, start = 0, len = Integer.MAX_VALUE, valid = 0;
        HashMap<Character, Integer> have = new HashMap<>();

        while (right < s.length()) {
            char r = s.charAt(right);
            if (need.containsKey(r)) {
                if (need.get(r) > have.getOrDefault(r, 0)) {
                    valid++;
                }
                have.put(r, have.getOrDefault(r, 0) + 1);
            }

            if (valid == t.length()) {
                if ((right - left) < len) {
                    start = left;
                    len = right - left;
                }
                while (left < right) {
                    char l = s.charAt(left);
                    left++;
                    if (need.containsKey(l)) {
                        if (need.get(l) >= have.get(l)) {
                            valid--;
                            have.put(l, have.get(l) - 1);
                            break;
                        } else {
                            have.put(l, have.get(l) - 1);
                            if((right - left) < len) {
                                start = left;
                                len = right - left;
                            }
                        }
                    } else {
                        if ((right - left) < len) {
                            start = left;
                            len = right - left;
                        }
                    }

                }
            }
            right++;
        }
        return len == Integer.MAX_VALUE ? "" : s.substring(start, start + len + 1);
    }

    private static String minWindow(String s, String t) {
        if (s == null || s.isEmpty() || t == null || t.isEmpty() || s.length() < t.length()) {
            return "";
        }
        HashSet<Character> need = new HashSet<>();
        for (char c : t.toCharArray()) {
            need.add(c);
        }

        int left = 0;
        int right = 0;
        int len = Integer.MAX_VALUE;
        int valid = 0;
        int start = 0;
        while (right < s.length()) {
            char c = s.charAt(right);
            if (need.contains(c)) {
                valid++;
            }

            if (valid == need.size()) {
                // record down result
                if ((right - left) < len) {
                    start = left;
                    len = right - left;
                }

                while (left < right) {
                    char l = s.charAt(left);
                    left++;
                    if (need.contains(l)) {
                        valid--;
                        break;
                    } else {
                        // record down result
                        if ((right - left) < len) {
                            len--;
                            start = left;
                        }
                    }
                }
            }
            right++;
        }
        return len == Integer.MAX_VALUE ? "" : s.substring(start, start + len + 1);
    }

}
