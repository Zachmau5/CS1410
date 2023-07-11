#include <iostream>
#include <iomanip>
#include <cmath>
#include <unordered_map>
#include <vector>

const int MAX_SIZE = 100;  // Maximum size of the array
void collectAndOrganizeData(double data[], double dataCopy[], int& numDataPoints) {
    std::cout << "Enter the number of data points: ";
    std::cin >> numDataPoints;

    std::cout << "Enter the data points:\n";
    for (int i = 0; i < numDataPoints; ++i) {
        std::cout << "Data point " << i + 1 << ": ";
        std::cin >> data[i];
    }

    // Print the collected data
    std::cout << "Original Dataset: ";
    for (int i = 0; i < numDataPoints; ++i) {
        std::cout << "[" << std::fixed << std::setprecision(1) << data[i] << "]";
        if (i != numDataPoints - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;

    // Make a copy of the data
    for (int i = 0; i < numDataPoints; ++i) {
        dataCopy[i] = data[i];
    }

    // Sort the copy (using bubble sort for simplicity)
    for (int i = 0; i < numDataPoints - 1; ++i) {
        for (int j = 0; j < numDataPoints - i - 1; ++j) {
            if (dataCopy[j] > dataCopy[j + 1]) {
                double temp = dataCopy[j];
                dataCopy[j] = dataCopy[j + 1];
                dataCopy[j + 1] = temp;
            }
        }
    }

    // Print the sorted copy
    std::cout << "Sorted copy: ";
    for (int i = 0; i < numDataPoints; ++i) {
        std::cout << "[" << std::fixed << std::setprecision(1) << dataCopy[i] << "]" << " ";
    }
    std::cout << std::endl;
}

double calculateMean(const double data[], int numDataPoints) {
    double sum = 0.0;
    for (int i = 0; i < numDataPoints; ++i) {
        sum += data[i];
    }
    return sum / numDataPoints;
}

double calculateMedian(const double sortedData[], int numDataPoints) {
    if (numDataPoints % 2 == 0) {
        return (sortedData[numDataPoints / 2 - 1] + sortedData[numDataPoints / 2]) / 2.0;
    } else {
        return sortedData[numDataPoints / 2];
    }
}

double calculateRange(const double data[], int numDataPoints) {
    double min = data[0];
    double max = data[0];
    for (int i = 1; i < numDataPoints; ++i) {
        if (data[i] < min) {
            min = data[i];
        }
        if (data[i] > max) {
            max = data[i];
        }
    }
    return max - min;
}

double calculateSampleVariance(const double data[], int numDataPoints) {
    double mean = calculateMean(data, numDataPoints);
    double variance = 0.0;
    for (int i = 0; i < numDataPoints; ++i) {
        variance += pow(data[i] - mean, 2);
    }
    return variance / (numDataPoints - 1);
}

double calculateSampleStandardDeviation(const double data[], int numDataPoints) {
    double variance = calculateSampleVariance(data, numDataPoints);
    return sqrt(variance);
}

void calculateMode(const double data[], int numDataPoints) {
    std::unordered_map<double, int> frequencyMap;
    int maxFrequency = 0;
    for (int i = 0; i < numDataPoints; ++i) {
        frequencyMap[data[i]]++;
        if (frequencyMap[data[i]] > maxFrequency) {
            maxFrequency = frequencyMap[data[i]];
        }
    }

    std::vector<double> modes;
    for (const auto& pair : frequencyMap) {
        if (pair.second == maxFrequency) {
            modes.push_back(pair.first);
        }
    }

    // Output the modes
    if (modes.empty() || maxFrequency == 1) {
        std::cout << "No mode found." << std::endl;
    } else {
        std::cout << "Multiple modes found: ";
        for (int i = 0; i < modes.size(); ++i) {
            std::cout << std::fixed << std::setprecision(2) << modes[i];
            if (i != modes.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << std::endl;
    }
}

int main() {
    double data[MAX_SIZE];
    double dataCopy[MAX_SIZE];
    int numDataPoints;

    collectAndOrganizeData(data, dataCopy, numDataPoints);
    double mean = calculateMean(data, numDataPoints);
    double median = calculateMedian(dataCopy, numDataPoints);
    double range = calculateRange(data, numDataPoints);
    double sampleVariance = calculateSampleVariance(data, numDataPoints);
    double sampleStandardDeviation = calculateSampleStandardDeviation(data, numDataPoints);
    std::cout << std::endl;
    std::cout << "Central Tendancy" << std::endl;
    std::cout << "Mean: " << std::fixed << std::setprecision(3) << mean << std::endl;
    std::cout << "Median: " << std::fixed << std::setprecision(2) << median << std::endl;
    calculateMode(data, numDataPoints);
    std::cout << std::endl;
    std::cout << "Disperson" << std::endl;
    std::cout << "Range: " << std::fixed << std::setprecision(2) << range << std::endl;
    std::cout << "Sample Variance: " << std::fixed << std::setprecision(5) << sampleVariance << std::endl;
    std::cout << "Sample Standard Deviation: " << std::fixed << std::setprecision(5) << sampleStandardDeviation << std::endl;

}
