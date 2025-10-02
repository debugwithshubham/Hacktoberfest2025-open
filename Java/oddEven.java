// Simple Java program to print numbers and their even/odd status
public class EvenOddChecker {

    // Main method: program entry point
    public static void main(String[] args) {
        // Define how many numbers we want to check
        int n = 10;

        // Loop from 1 to n
        for (int i = 1; i <= n; i++) {
            // Check if the number is even
            if (i % 2 == 0) {
                System.out.println(i + " is even");
            } else { // Otherwise, it is odd
                System.out.println(i + " is odd");
            }
        }
    }
}
