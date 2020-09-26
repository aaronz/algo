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

    public static void print(boolean[][] matrix) {
        for(int i = 0; i < matrix.length; i++) {
            for(int j = 0; j < matrix[i].length; j++){
                System.out.print(matrix[i][j]);
                System.out.print('\t');
            }
            System.out.println();
        }
    }
}
