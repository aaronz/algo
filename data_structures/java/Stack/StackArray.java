package data_structures.java.Stack;

public class StackArray {
    public static final int DEFAULT_SIZE = 10;
    private int maxSize;
    private int[] stackArray;
    private int top;

    public StackArray() {
        this(DEFAULT_SIZE);
    }

    public StackArray(int size) {
        maxSize = size;
        stackArray = new int[maxSize];
        top = -1;
    }

    public boolean isFull() {
        return top >= maxSize - 1;
    }

    public boolean isEmpty() {
        return top <= -1;
    }

    public void push(int value) {
        if (isFull()) {
            resize(maxSize * 2);
            push(value);
        } else {
            stackArray[++top] = value;
        }
    }

    public void resize(int newSize) {
        int[] tempArray = new int[newSize];
        for (int i = 0; i < stackArray.length; i++) {
            tempArray[i] = stackArray[i];
        }
        stackArray = tempArray;
        maxSize = newSize;
    }

    public int pop() {
        if (!isEmpty()) {
            return stackArray[top--];
        } else {
            System.out.println("Stack is empty");
            return -1;
        }
    }

    public int peek() {
        if (!isEmpty()) {
            return stackArray[top];
        } else {
            System.out.println("The stack is empty, cant peek.");
            return -1;
        }
    }

    public static void main(String[] args) {
        StackArray stack = new StackArray(4);
        stack.push(1);
        stack.push(2);
        stack.push(3);
        stack.push(4);
        stack.push(5);
        stack.push(6);
        stack.push(6);
        stack.push(6);
        stack.push(6);
        stack.push(6);
        stack.push(9);
        System.out.println(stack.isEmpty());
        System.out.println(stack.isFull());
        System.out.println(stack.peek());
        System.out.println(stack.pop());
    }
}