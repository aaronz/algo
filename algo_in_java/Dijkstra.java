public class Dijkstra {
    public static final int M = 10000;

    public static void main(String[] args) {
        int[][] weight1 = { { 0, 4, M, 2, M }, { 4, 0, 4, 1, M }, { M, 4, 0, 1, 3 }, { 2, 1, 1, 0, 7 },
                { M, M, 3, 7, 0 } };

        int start = 0;
        int[] shortPath = dijkstra(weight1, start);
        for (int i = 0; i < shortPath.length; i++) {
            System.out.println("Shortest path from: " + start + " to: " + i + " is " + shortPath[i]);
        }
    }

    public static int[] dijkstra(int[][] weight, int start) {
        int n = weight.length;
        int[] shortPath = new int[n];
        String[] path = new String[n];
        for (int i = 0; i < n; i++) {
            path[i] = new String(start + "-->" + i);
        }
        int[] visited = new int[n];

        shortPath[start] = 0;
        visited[start] = 1;

        for (int count = 1; count < n; count++) {
            int k = -1;
            int dmin = Integer.MAX_VALUE;
            for (int i = 0; i < n; i++) {
                if (visited[i] == 0 && weight[start][i] < dmin) {
                    dmin = weight[start][i];
                    k = i;
                }
            }

            shortPath[k] = dmin;
            visited[k] = 1;

            for (int i = 0; i < n; i++) {
                if (visited[i] == 0 && weight[start][k] + weight[k][i] < weight[start][i]) {
                    weight[start][i] = weight[start][k] + weight[k][i];
                    path[i] = path[k] + "-->" + i;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            System.out.println("Shortest path from: " + start + " to: " + i + " is " + path[i]);
        }
        System.out.println("==============");
        return shortPath;
    }
}