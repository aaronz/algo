package leetcode.java;

import java.util.Arrays;

public class DisjointSet {
    int[] parent;
    int[] rank;
    int count;

    DisjointSet(int n) {
        parent = new int[n];
        Arrays.fill(parent, -1);
        rank = new int[n];
        this.count = n;
    }

    private int findRoot(int x) {
        int root = x;
        while (parent[root] != -1) {
            root = parent[root];
        }
        return root;
    }

    public boolean union(int x, int y) {
        int rootX = findRoot(x);
        int rootY = findRoot(y);
        if(rootX == rootY){
            return false;
        }
        if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else {
            parent[rootX] = rootY;
            rank[rootY]++;
        }
        count--;
        return true;
    }

    public int getCount(){
        return this.count;
    }

}