#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <numeric> 

using namespace std;

// Structure to store milk yield data for each cow
struct CowData {
    vector<double> yields; // List of yields for each day of the week
};

// Function prototypes
void collectYieldData(map<int, CowData>& cowData);
void calculateMilkStatistics(const map<int, CowData>& cowData);
void identifyMostProductive(const map<int, CowData>& cowData);

int main() {
    map<int, CowData> cowData; // Map to store cow data (key: cow ID, value: CowData)

    // Code for Task 1: Record the yield
    collectYieldData(cowData);

    // Code for Task 2: Calculate the statistics
    calculateMilkStatistics(cowData);

    // Code for Task 3: Identify the most productive cow and cows with low milk production
    identifyMostProductive(cowData);

    return 0;
}


// Function to record the yield for each cow every time it is milked
void collectYieldData(map<int, CowData>& cowData) {
    int cowID;
    double yield;

    cout << "Enter cow ID (3-digit) and yield for each milking (0 to stop):\n";
    while (true) {
        cout << "Cow ID: ";
        cin >> cowID;
        if (cowID == 0)
            break;
        cout << "Yield: ";
        cin >> yield;

        // Add yield to the corresponding cow's data
        cowData[cowID].yields.push_back(yield);
    }
}
// Function to calculate the total weekly volume of milk for the herd and the average yield per cow in a week
void calculateMilkStatistics(const map<int, CowData>& cowData) {
    int totalVolume = 0;
    int totalCows = 0;
    double maxTotalYield = 0;
    int mostProductiveCowID = 0;
    int lowYieldDaysThreshold = 4;

    // Calculate total volume and count total cows
    for (const auto& pair : cowData) {
        int lowYieldDays = 0;
        totalCows++;
        double totalYield = accumulate(pair.second.yields.begin(), pair.second.yields.end(), 0.0);
        totalVolume += totalYield;

        // Check if the cow is the most productive
        if (totalYield > maxTotalYield) {
            maxTotalYield = totalYield;
            mostProductiveCowID = pair.first;
        }

        // Count days with low milk production
        for (double yield : pair.second.yields) {
            if (yield < 12.0)
                lowYieldDays++;
        }

        // Check if the cow has low milk production for four or more days
        if (lowYieldDays >= lowYieldDaysThreshold) {
            cout << "Cow ID " << pair.first << ", Total Yield: " << totalYield << " liters\n";
        }
    }

    // Calculate average yield per cow
    double averageYield = static_cast<double>(totalVolume) / totalCows;

    cout << "Total weekly volume of milk for the herd: " << totalVolume << " liters\n";
    cout << "Average yield per cow in a week: " << fixed << setprecision(1) << averageYield << " liters\n";
    cout << "Most productive cow this week: Cow ID " << mostProductiveCowID << ", Total Yield: " << maxTotalYield << " liters\n";
}
// Function to identify the most productive cow and cows with low milk production
void identifyMostProductive(const map<int, CowData>& cowData) {
    int mostProductiveCowID = 0;
    double maxTotalYield = 0;
    int lowYieldDaysThreshold = 4;
    bool foundLowProduction = false;

    // Identify most productive cow
    for (const auto& pair : cowData) {
        double totalYield = accumulate(pair.second.yields.begin(), pair.second.yields.end(), 0.0);
        if (totalYield > maxTotalYield) {
            maxTotalYield = totalYield;
            mostProductiveCowID = pair.first;
        }

        // Check if the cow has low milk production for four or more days
        int lowYieldDays = 0;
        for (double yield : pair.second.yields) {
            if (yield < 12.0)
                lowYieldDays++;
        }
        if (lowYieldDays >= lowYieldDaysThreshold) {
            double totalYield = accumulate(pair.second.yields.begin(), pair.second.yields.end(), 0.0);
            cout << "Cow ID " << pair.first << ", Total Yield: " << totalYield << " liters\n";
            foundLowProduction = true;
        }
    }

    if (!foundLowProduction) {
        cout << "No cows with low milk production for four or more days.\n";
    }
}

