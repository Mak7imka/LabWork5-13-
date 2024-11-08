#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <stdexcept>

void checkValidInput() {
    if (std::cin.fail()) {
        throw "Incorrect input values";
    }
}

void checkValidParamN(int n) {
    if (n <= 0) {
        throw "The value of n must be greater than 0";
    }
}

void checkValidInputAB(double a, double b) {
    if (b < a) {
        throw "The end of the interval (b) must be greater than the start (a)";
    }
}

void checkValidH(double h) {
    if (h <= 0) {
        throw "The step (h) must be greater than 0";
    }
}

double calculate_y(int n, double x) {
    if (x <= 0) {
        double product = 1.0;
        for (int i = 0; i <= n - 1; ++i) {
            product *= (std::pow(i, 3) + i);
        }
        return product;
    }
    else {
        double sum = 0.0;
        for (int i = 0; i <= n - 1; ++i) {
            for (int j = 0; j <= n - 1; ++j) {
                if (i + j != 0) { // Проверка на деление на ноль
                    sum += x / (i + j);
                }
            }
        }
        return sum;
    }
}

void calculate_and_display(int n, double a, double b, double h) {
    char saveToFile;
    std::cout << "Do you want to save the results to a file? (y - Yes, n - No): ";
    std::cin >> saveToFile;

    std::ofstream file;
    if (saveToFile == 'y' || saveToFile == 'Y') {
        file.open("results.txt");
        if (!file.is_open()) {
            throw "Error opening file for writing";
        }
        file << std::setw(10) << "x" << std::setw(20) << "y" << std::endl;
    }

    std::cout << std::setw(10) << "x" << std::setw(20) << "y" << std::endl;

    for (double x = a; x <= b; x += h) {
        double y = calculate_y(n, x);
        std::cout << std::fixed << std::setprecision(4) << std::setw(10) << x << std::setw(20) << y << std::endl;

        if (file.is_open()) {
            file << std::fixed << std::setprecision(4) << std::setw(10) << x << std::setw(20) << y << std::endl;
        }
    }

    if (file.is_open()) {
        file.close();
        std::cout << "Results have been saved to 'results.txt'" << std::endl;
    }
}

int main() {
    int n;
    double a, b, h;

    try {
        std::cout << "Enter the value of n: ";
        std::cin >> n;
        checkValidInput();
        checkValidParamN(n);

        std::cout << "Enter the start of the interval (a): ";
        std::cin >> a;
        checkValidInput();

        std::cout << "Enter the end of the interval (b): ";
        std::cin >> b;
        checkValidInput();
        checkValidInputAB(a, b);

        std::cout << "Enter the step (h): ";
        std::cin >> h;
        checkValidInput();
        checkValidH(h);

        calculate_and_display(n, a, b, h);

    }
    catch (const char* ex) {
        std::cerr << "Error: " << ex << std::endl;
        return -1;
    }

    return 0;
}
