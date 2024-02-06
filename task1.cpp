#include <iostream>
#include <string>
#include <limits>
using namespace std;
const int num_people = 30;

bool validateWeight(float weight) {
    return (weight >= 20.0 && weight <= 150.0);
}

void inputPupilData(string names[], float weights[]) {
    for (int i = 0; i < num_people; ++i) {
        cout << "Enter the name of person " << i + 1 << ": ";
        getline(cin, names[i]);

        cout << "Enter the weight of " << names[i] << " in kilograms: ";
        float weight;
        while (!(std::cin >> weight) || !validateWeight(weight)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid weight. Weight must be between 20 and 150 kilograms. Kindly Try again: ";
        }

        // Clear the newline character from the buffer
       cin.ignore(numeric_limits<streamsize>::max(), '\n');

        weights[i] = weight;
    }
}

void calculateWeightDifference(const float initialWeights[], const float finalWeights[], float differences[]) {
    for (int i = 0; i < num_people; ++i) {
        differences[i] = finalWeights[i] - initialWeights[i];
    }
}

int main() {
    // Code for Task 1 (Input and store weights and names)
    cout << "**TASK 1 Result: Input and store weights and names**" <<endl;
    string names[num_people];
    float initialWeights[num_people];

    inputPupilData(names, initialWeights);

    // Code for Task 2 (Record the weight on the last day and calculate the difference)
    cout << "\n**TASK 2 Result: Record the weight on the last day and calculate the difference**" << endl;
    float finalWeights[num_people];
    inputPupilData(names, finalWeights);

    // Code for Task 3 (Output information for people with a difference of more than 2.5 kilograms)
    cout << "\n**TASK 3 Result: Output information for people with a difference of more than 2.5 kilograms**" << endl;
    float differences[num_people];
    calculateWeightDifference(initialWeights, finalWeights, differences);

    for (int i = 0; i < num_people; ++i) {
        if (abs(differences[i]) > 2.5) {
            string message = (differences[i] > 0) ? "rise" : "fall";
            cout << names[i] << ": Difference in weight: " << abs(differences[i]) << " kilograms. " << message << "." <<endl;
        }
    }
    return 0;
}
