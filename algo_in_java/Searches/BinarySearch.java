package algo_in_java.Searches;

class BinarySearch {
    public <T extends Comparable<T>> int search(T array[], T key, int left, int right) {
        if (right < left)
            return -1;

        int median = (left + right) >>> 1;
        System.out.println("left:" + left + "right:" + right + "median" + median);
        int comp = key.compareTo(array[median]);

        if (comp == 0)
            return median;
        else if (comp > 0)
            return search(array, key, median + 1, right);
        else
            return search(array, key, left, median - 1);
    }

    public static void main(String[] args) {
        Integer[] array = { -1, 0, 3, 5, 9, 12 };
        int key = 13;
        System.out.println(new BinarySearch().search(array, key, 0, array.length-1));
    }
}