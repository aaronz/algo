package leetcode.java;

public class AddStrings {
    public String addStrings(String number1, String number2) {
        if (number1 == null || number1.length() == 0)
            return number2;
        if (number2 == null || number2.length() == 0)
            return number1;

        if (number1.length() < number2.length()) {
            String temp = number1;
            number1 = number2;
            number2 = temp;
        }

        int carry = 0;
        int i = number2.length() - 1;
        int delta = number1.length() - number2.length();
        StringBuilder result = new StringBuilder();
        while (i >= 0) {
            int current1 = Character.getNumericValue(number1.charAt(i + delta));
            int current2 = Character.getNumericValue(number2.charAt(i));
            int sum = current1 + current2 + carry;
            if (sum > 9) {
                carry = 1;
                sum = sum % 10;
            } else {
                carry = 0;
            }
            result = result.insert(0, String.valueOf(sum));
            i--;
        }

        while ((i + delta) >= 0) {
            int current1 = Character.getNumericValue(number1.charAt(i + delta));
            int sum = current1 + carry;
            if (sum > 9) {
                carry = 1;
                sum = sum % 10;
            } else {
                carry = 0;
            }
            result = result.insert(0, String.valueOf(sum));
            i--;
        }
        if (carry == 1) {
            result = result.insert(0, "1");
        }
        return result.toString();

    }

    public static void main(String[] args) {
        String number1 = "12345";
        String number2 = "99234";
        AddStrings solution = new AddStrings();
        String result = solution.addStrings(number1, number2);
        System.out.println(result);
    }

}