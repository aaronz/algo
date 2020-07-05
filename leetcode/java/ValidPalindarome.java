package leetcode.java;

public class ValidPalindarome {
    public static void main(String[] args) {
        boolean result = validPalindarome("abcdcbae");
        System.out.println(result);
    }

    public static boolean validPalindarome(String s) {
        if (s == null)
            return false;
        for (int i = 0, j = s.length() - 1; i < j; i++, j--) {
            if (s.charAt(i) != s.charAt(j)) {
                return isPalindarome(s, i, j - 1) || isPalindarome(s, i + 1, j);
            }
        }
        return true;
    }

    private static boolean isPalindarome(String s, int i, int j) {
        while (i < j) {
            if (s.charAt(i++) != s.charAt(j--)) {
                return false;
            }
        }
        return true;
    }
}