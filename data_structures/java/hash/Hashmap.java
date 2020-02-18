package data_structures.java.hash;

class HashMap {
    private int hsize;
    private LinkedList[] buckets;

    public HashMap(int size) {
        buckets = new LinkedList[size];
        for (int i = 0; i < size; i++) {
            buckets[i] = new LinkedList();
        }
        this.hsize = size;
    }

    public int hashing(int key) {
        int hash = key % hsize;
        if (hash < 0) {
            hash += hsize;
        }
        return hash;
    }

    public void insertHash(int key) {
        int hash = hashing(key);
        buckets[hash].insert(key);
    }

    public void deleteHash(int key) {
        int hash = hashing(key);
        buckets[hash].delete(key);
    }

    public void displayHashTable(){
        for(int i=0; i< hsize; i++){
            System.out.print(i);
            System.out.print(":");
            buckets[i].display();
        }
    }
}