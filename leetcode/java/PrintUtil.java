package leetcode.java;

import java.util.List;

public class PrintUtil {
    public static void print(List<List<String>> printable) {
        for(List<String> l : printable) {
            for(String s : l) {
                System.out.println(s);
            }
            System.out.println("=======separator=======");
        }
    }
}
