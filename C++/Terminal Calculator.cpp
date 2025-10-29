/**
 * @file calculator.cpp
 * @brief A simple, robust console calculator written in C++.
 * * This program performs basic arithmetic operations (+, -, *, /)
 * based on user input. It includes error handling for invalid input
 * and division by zero.
 */

#include <iostream> // For console input/output (cin, cout, cerr)
#include <string>   // For using the string class
#include <sstream>  // For parsing user input from a string
#include <limits>   // For numeric_limits (used in error handling)
#include <cctype>   // For tolower()

/**
 * @brief Clears the input stream and ignores remaining characters.
 * * This helper function is used to recover from a failed input
 * stream state (e.g., if a user enters text instead of a number).
 */
void clearInputBuffer() {
    // Clear the error state of the stream
    std::cin.clear(); 
    // Ignore all characters up to the next newline
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
}

/**
 * @brief Checks if a string is a "quit" command.
 * @param input The user's input string.
 * @return true if the user wants to quit, false otherwise.
 */
bool isQuitCommand(const std::string& input) {
    // Check for "exit" or "q"
    return (input == "exit" || input == "q");
}

/**
 * @brief Main function for the calculator application.
 * * Contains the main application loop, prompts for input,
 * parses the input, performs calculations, and handles errors.
 * * @return 0 on successful execution, 1 on error (though this app loops).
 */
int main() {
    double num1, num2;  // To store the numbers
    char op;            // To store the operator
    std::string inputLine; // To read the full line of input

    std::cout << "--- C++ Console Calculator ---" << std::endl;
    std::cout << "Enter a calculation (e.g., 5 + 3, 10 * 2, 8 / 4)" << std::endl;
    std::cout << "Type 'q' or 'exit' to quit." << std::endl;
    std::cout << "------------------------------" << std::endl;

    // Main application loop
    while (true) {
        std::cout << "\n> "; // Prompt for input

        // Read the entire line from the user
        if (!std::getline(std::cin, inputLine)) {
            // This handles end-of-file (Ctrl+D/Ctrl+Z)
            std::cout << "Input error. Exiting." << std::endl;
            break; 
        }

        // --- 1. Check for quit command ---
        // Create a temporary string to check in lowercase
        std::string lowerInput = inputLine;
        for (char &c : lowerInput) {
            // Cast to unsigned char before passing to std::tolower to avoid
            // undefined behaviour when char is signed and has negative values.
            c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
        }

        if (isQuitCommand(lowerInput)) {
            std::cout << "Goodbye!" << std::endl;
            break; // Exit the while loop
        }

        // --- 2. Parse the input string ---
        std::stringstream ss(inputLine);
        
        // Try to extract num1, op, and num2
        // ss >> num1 >> op >> num2;
        
        if (!(ss >> num1)) {
            // Failed to read the first number
            std::cerr << "Error: Invalid input. Please use format: number operator number" << std::endl;
            continue; // Go to the next loop iteration
        }

        if (!(ss >> op)) {
            // Failed to read the operator
            std::cerr << "Error: Missing operator. Please use format: number operator number" << std::endl;
            continue;
        }

        if (!(ss >> num2)) {
            // Failed to read the second number
            std::cerr << "Error: Missing second number. Please use format: number operator number" << std::endl;
            continue;
        }

        // Check if there is extra junk at the end of the line
        std::string junk;
        if (ss >> junk) {
             std::cerr << "Error: Too much input. Please use format: number operator number" << std::endl;
             continue;
        }

        // --- 3. Perform the calculation ---
        double result = 0.0;
        bool validOperation = true;

        switch (op) {
            case '+':
                result = num1 + num2;
                break;
            case '-':
                result = num1 - num2;
                break;
            case '*':
                result = num1 * num2;
                break;
            case '/':
                if (num2 == 0) {
                    // Specific error for division by zero
                    std::cerr << "Error: Cannot divide by zero." << std::endl;
                    validOperation = false;
                } else {
                    result = num1 / num2;
                }
                break;
            default:
                // Handle unknown operators
                std::cerr << "Error: Unknown operator '" << op << "'. Use +, -, *, or /." << std::endl;
                validOperation = false;
                break;
        }

        // --- 4. Print the result ---
        if (validOperation) {
            // std::cout.precision(10); // Optional: Set precision
            std::cout << "Result: " << result << std::endl;
        }
    }

    return 0; // Successful exit
}
