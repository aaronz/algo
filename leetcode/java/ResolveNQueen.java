package leetcode.java;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class ResolveNQueen {

    public static void main(String[] args){
        List<List<String>> result = solveNQueens(4);
        PrintUtil.print(result);
    }

    public static List<List<String>> solveNQueens(int n) {
        List<List<String>> result = new ArrayList<>();
        List<String> solution = new ArrayList<>();
        char[] temp = new char[n];
        Arrays.fill(temp, '.');
        for (int i = 0; i < n; i++) {
            String line = new String(temp);
            solution.add(line);
        }
        backtrack(n, 0, solution, result);
        return result;
    }

    private static void backtrack(int n, int row, List<String> solution, List<List<String>> result) {
        if (row == n) {
            result.add(new ArrayList<>(solution));
            return;
        }

        for (int column = 0; column < n; column++) {
            String line = solution.get(row);
            char[] array = line.toCharArray();

            if (isValid(row, column, array, solution)) {
                array[column] = 'Q';
                solution.set(row, new String(array));
                backtrack(n, row + 1, solution, result);
                solution.set(row, line);
            } else {
                continue;
            }
        }
    }

    private static boolean isValid(int row, int column, char[] array, List<String> solution) {
        for (int i = 0; i < row; i++) {
            if (solution.get(i).charAt(column) == 'Q') {
                return false;
            }
        }

        for (int i = row, j = column; i >= 0 && j >= 0; i--, j--) {
            if (solution.get(i).charAt(j) == 'Q') {
                return false;
            }
        }

        for (int i = row, j = column; i >= 0 && j < array.length; i--, j++) {
            if (solution.get(i).charAt(j) == 'Q') {
                return false;
            }
        }

        return true;
    }
}
