package data_structures.java.hash;

public class App{
    public static void main(String[] args){
        HashMap h = new HashMap(7);
        h.insertHash(1);
        h.insertHash(2);
        h.insertHash(3);
        h.insertHash(5);
        h.insertHash(8);
        h.insertHash(100);
        h.displayHashTable();
    }
}