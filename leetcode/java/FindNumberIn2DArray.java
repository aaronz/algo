package leetcode.java;

public class FindNumberIn2DArray {
    public static void main(String[] args) {
        int[][] matrix = {{}};
        boolean result = findNumberIn2DArray(matrix, 0);
        System.out.println(result);
    }

    private static boolean findNumberIn2DArray(int[][] matrix, int target) {
        if (matrix.length <= 0) {
            return false;
        }
        if (matrix[0].length <= 0) {
            return false;
        }

        int width = matrix[0].length;
        int height = matrix.length;
        int column = width - 1;
        int row = 0;
        while (row < height && column >= 0) {
            int current = matrix[row][column];
            if (current == target) {
                return true;
            } else if (current > target) {
                column--;
            } else {
                row++;
            }
        }

        return false;
    }
}
