#include <iostream>
#include <fstream>
#include <string>

int calculateCalibrationSumPart1(const std::string& filename) {
    std::ifstream fin;
    fin.open(filename);

    if (fin.fail())
    {
        std::cout << "Unable to open the file." << std::endl;
        exit(1);
    }

    int sum = 0;

    // Read each line from the file
    std::string line;
    while (std::getline(fin, line)) {
        int firstDigit = -1;
        int lastDigit = -1;

        // Loop through each character in the line
        for (int i = 0; i < line.size(); i++)
        {
            if (isdigit(line[i]))
            {
                if (firstDigit == -1)
                {
                    // First digit not found yet
                    firstDigit = line[i] - '0';
                }
                lastDigit = line[i] - '0'; // Always update last digit
            }
        }

        // Check if only one digit is found
        if (lastDigit != -1 && firstDigit == -1) {
            firstDigit = lastDigit;
        }

        // Add the calibration value (first digit * 10 + last digit) to the sum
        sum += firstDigit * 10 + lastDigit;
    }

    fin.close();

    return sum;
}

int main() {
    std::string filename = "input.txt";

    int sum = calculateCalibrationSumPart1(filename);

    std::cout << "Sum of calibration values: " << sum << std::endl;

    return 0;
}
