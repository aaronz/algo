package leetcode.java;

import java.util.Arrays;
import java.util.HashSet;

public class ReverseVowels {
    public static void main(String[] args) {
        String result = reverseVowels("result");
        System.out.println(result);
    }

    private final static HashSet<Character> vowels = new HashSet<>(
            Arrays.asList('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'));

    public static String reverseVowels(String s){
        if(s == null)
            return null;
        char[] result = new char[s.length()];
        int i = 0, j = s.length() - 1;
        // notice i <= j; because there could be a condition i and j both point to the same vowel.
        while(i <= j){
            char ci = s.charAt(i);
            char cj = s.charAt(j);
            if(!vowels.contains(ci)){
                result[i++] = ci;
            } else if (!vowels.contains(cj)){
                result[j--] = cj;
            } else {
                result[i++] = cj;
                result[j--] = ci;
            }
        }
        return new String(result);
    }
}