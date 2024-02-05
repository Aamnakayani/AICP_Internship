#include <iostream>
#include <string>
#include <limits>

const int num_pupils = 30;

bool validateWeight(float weight) {
    return (weight >= 20.0 && weight <= 150.0);
}

void inputPupilData(std::string names[], float weights[]) {
    for (int i = 0; i < num_pupils; ++i) {
        std::cout << "Enter the name of pupil " << i + 1 << ": ";
        std::getline(std::cin, names[i]);

        std::cout << "Enter the weight of " << names[i] << " in kilograms: ";
        float weight;
        while (!(std::cin >> weight) || !validateWeight(weight)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid weight. Weight must be between 20 and 150 kilograms. Try again: ";
        }

        // Clear the newline character from the buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        weights[i] = weight;
    }
}

void calculateWeightDifference(const float initialWeights[], const float finalWeights[], float differences[]) {
    for (int i = 0; i < num_pupils; ++i) {
        differences[i] = finalWeights[i] - initialWeights[i];
    }
}

int main() {
    // Task 1: Input and store weights and names
    std::cout << "TASK 1: Input and store weights and names" << std::endl;
    std::string names[num_pupils];
    float initialWeights[num_pupils];

    inputPupilData(names, initialWeights);

    // Task 2: Record the weight on the last day and calculate the difference
    std::cout << "\nTASK 2: Record the weight on the last day and calculate the difference" << std::endl;
    float finalWeights[num_pupils];
    inputPupilData(names, finalWeights);

    // Task 3: Output information for pupils with a difference of more than 2.5 kilograms
    std::cout << "\nTASK 3: Output information for pupils with a difference of more than 2.5 kilograms" << std::endl;
    float differences[num_pupils];
    calculateWeightDifference(initialWeights, finalWeights, differences);

    for (int i = 0; i < num_pupils; ++i) {
        if (std::abs(differences[i]) > 2.5) {
            std::string message = (differences[i] > 0) ? "rise" : "fall";
            std::cout << names[i] << ": Difference in weight: " << std::abs(differences[i]) << " kilograms. " << message << "." << std::endl;
        }
    }

    return 0;
}
