package leetcode.java;

public class Exists {

    public static void main(String[] args) {
        // char[][] board = { { 'A', 'B', 'C', 'E' }, { 'S', 'F', 'C', 'S' }, { 'A', 'D', 'E', 'E' } };
        // String word = "ABCCED";
        // boolean result = exist(board, word);
        // System.out.println(result);

        char[][] board2 = {{'A','B'},{'C','D'}};
        String word2 = "ACDB";
        boolean result2 = exist(board2, word2);
        System.out.println(result2);
    }

    private static boolean exist(char[][] board, String word) {
        if (board.length == 0)
            return false;
        int height = board.length;
        int width = board[0].length;
        boolean[] visited = new boolean[width * height];
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (check(board, height, width, i, j, visited, word, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

    private static boolean check(char[][] board, int height, int width, int row, int column, boolean[] visited,
            String word, int index) {

        if (column >= 0 && column < width && row >= 0 && row < height && !visited[row * width + column]
                && board[row][column] == word.charAt(index)) {
            if (index == word.length() - 1) {
                return true;
            } else {
                visited[row * width + column] = true;

                boolean result = check(board, height, width, row + 1, column, visited, word, index + 1)
                        || check(board, height, width, row, column + 1, visited, word, index + 1)
                        || check(board, height, width, row - 1, column, visited, word, index + 1)
                        || check(board, height, width, row, column - 1, visited, word, index + 1);
                visited[row * width + column] = false;
                return result;
            }
        } else {
            return false;
        }
    }

}
