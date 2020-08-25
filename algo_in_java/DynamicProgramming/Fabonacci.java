package algo_in_java.DynamicProgramming;

import java.util.HashMap;
import java.util.Map;

public class Fabonacci {

    private static Map<Integer, Integer> map = new HashMap<>();

    // fib with memo
    public static int fibMemo(int n) {
        if (map.containsKey(n)) {
            return map.get(n);
        }

        int f;
        if (n <= 1) {
            f = n;
        } else {
            f = fibMemo(n - 1) + fibMemo(n - 2);
            map.put(n, f);
        }
        return f;
    }

    public static int fibBottomUp(int n) {
        Map<Integer, Integer> fib = new HashMap<>();
        for (int i = 0; i <= n; i++) {
            int f;
            if (i <= 1) {
                f = i;
            } else {
                f = fib.get(i - 1) + fib.get(i - 2);
            }
            fib.put(i, f);
        }
        return fib.get(n);
    }

    public static void main(String[] args){
        System.out.println(fibBottomUp(1));
        System.out.println(fibBottomUp(2));
        System.out.println(fibBottomUp(5));
        System.out.println(fibBottomUp(10));
        System.out.println(fibMemo(10));
    }
}