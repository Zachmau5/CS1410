#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void print(double set[], int size) {
    cout << "Set: [";
    for (int i = 0; i < size; i++) {
        cout << set[i];
        if (i < size - 1)
            cout << ", ";
    }
    cout << "]" << endl;
}

double calculateMean(double set[], int size) {
    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += set[i];
    }
    return sum / size;
}

double calculatePearsonCoefficient(double set1[], double set2[], int size) {
    double mean1 = calculateMean(set1, size);
    double mean2 = calculateMean(set2, size);

    double numerator = 0.0;
    double denominator1 = 0.0;
    double denominator2 = 0.0;

    for (int i = 0; i < size; i++) {
        numerator += (set1[i] - mean1) * (set2[i] - mean2);
        denominator1 += pow(set1[i] - mean1, 2);
        denominator2 += pow(set2[i] - mean2, 2);
    }

    double correlationCoefficient = numerator / sqrt(denominator1 * denominator2);
    return correlationCoefficient;
}

int main() {
    const int SIZE = 1000;
    double set1[SIZE];
    double set2[SIZE];
    int index = 0;

    string input;
    do {
        cout << "Enter a value for the x set, leave blank to finish: ";
        getline(cin, input);
        if (!input.empty()) {
            if (!isdigit(input[0]) && !(input[0] == '-' && isdigit(input[1])))
                cout << "Please type numbers only." << endl;
            else {
                set1[index] = stod(input);
                cout << "Adding " << set1[index] << " to x set." << endl;
                index++;
            }
        }
    } while (!input.empty());

    int ySetSize = index; // Store the number of x values for reference
    index = 0; // Reset index to 0 for the y set

    do {
        if (index >= ySetSize) {
            cout << "Maximum number of y values reached." << endl;
            break;
        }
        cout << "Enter a value for the y set, leave blank to finish: ";
        getline(cin, input);
        if (!input.empty()) {
            if (!isdigit(input[0]) && !(input[0] == '-' && isdigit(input[1]))) {
                cout << "Please type numbers only." << endl;
                continue;
            }
            set2[index] = stod(input);
            cout << "Adding " << set2[index] << " to y set." << endl;
            index++;
        }
    } while (!input.empty() && index < ySetSize);

    print(set1, ySetSize);
    print(set2, ySetSize);

    double correlationCoefficient = calculatePearsonCoefficient(set1, set2, ySetSize);
    cout << "Pearson correlation coefficient: " << correlationCoefficient << endl;
}
