#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// Constants for ticket prices
const double ADULT_ONE_DAY_PRICE = 20.00;
const double CHILD_ONE_DAY_PRICE = 12.00;
const double SENIOR_ONE_DAY_PRICE = 16.00;
const double FAMILY_ONE_DAY_PRICE = 60.00;
const double ADULT_TWO_DAY_PRICE = 30.00;
const double CHILD_TWO_DAY_PRICE = 18.00;
const double SENIOR_TWO_DAY_PRICE = 24.00;
const double FAMILY_TWO_DAY_PRICE = 90.00;
const double GROUP_ONE_DAY_PRICE = 15.00;
const double GROUP_TWO_DAY_PRICE = 22.50;
const double LION_FEEDING_PRICE = 2.50;

const double PENGUIN_FEEDING_PRICE = 2.00;
const double BBQ_PRICE = 5.00;

// Function to display ticket options and attractions
void displayOptions() {
    std::cout << "Ticket Options:\n";
    std::cout << "============================\n";
    std::cout << "One-day tickets:\n";
    std::cout << "1. Adult - $" << ADULT_ONE_DAY_PRICE << endl;
    std::cout << "2. Child - $" << CHILD_ONE_DAY_PRICE << endl;
    std::cout << "3. Senior - $" << SENIOR_ONE_DAY_PRICE << endl;
    std::cout << "4. Family - $" << FAMILY_ONE_DAY_PRICE << endl;
    std::cout << "\nTwo-day tickets:\n";
    std::cout << "5. Adult - $" << ADULT_TWO_DAY_PRICE << endl;
    std::cout << "6. Child - $" << CHILD_TWO_DAY_PRICE << endl;
    std::cout << "7. Senior - $" << SENIOR_TWO_DAY_PRICE << endl;
    std::cout << "8. Family - $" << FAMILY_TWO_DAY_PRICE << endl;
    std::cout << "\nExtra Attractions:\n";
    std::cout << "9. Lion Feeding - $" << LION_FEEDING_PRICE << endl;
    std::cout << "10. Penguin Feeding - $" << PENGUIN_FEEDING_PRICE << endl;
    std::cout << "11. Evening BBQ (two-day tickets only) - $" << BBQ_PRICE << endl;
    std::cout << "============================\n";
}

void processBooking() {
    char option;
    double totalCost = 0.0;
    vector<char> selections; // Change the vector to hold characters

    std::cout << "Enter the options for your booking (separated by spaces), enter 'd' to finish: ";
    while (cin >> option && option != 'd') { // Compare with a character
        selections.push_back(option);
    }

    for (const char& selection : selections) { // Iterate over characters
        if (selection == '1') {
            totalCost += ADULT_ONE_DAY_PRICE;
        } else if (selection == '2') {
            totalCost += CHILD_ONE_DAY_PRICE;
        } else if (selection == '3') {
            totalCost += SENIOR_ONE_DAY_PRICE;
        } else if (selection == '4') {
            totalCost += FAMILY_ONE_DAY_PRICE;
        } else if (selection == '5') {
            totalCost += ADULT_TWO_DAY_PRICE;
        } else if (selection == '6') {
            totalCost += CHILD_TWO_DAY_PRICE;
        } else if (selection == '7') {
            totalCost += SENIOR_TWO_DAY_PRICE;
        } else if (selection == '8') {
            totalCost += FAMILY_TWO_DAY_PRICE;
        } else if (selection == '9') {
            totalCost += LION_FEEDING_PRICE;
        } else if (selection == 'a') {
            totalCost += PENGUIN_FEEDING_PRICE; // Change the character to 'a'
        } else if (selection == 'b') {
            totalCost += BBQ_PRICE; // Change the character to 'b'
        } else {
            std::cout << "Invalid option selected.\n";
        }
    }

    std::cout << fixed << setprecision(2);
    std::cout << "Total Cost: $" << totalCost << endl;
    // Generate and display a unique booking number (you can implement this part)
}


int main() {
    int choice;
    bool exitProgram = false;

    while (!exitProgram) {
        std::cout << "Wildlife Park Ticket Booking System\n";
        std::cout << "1. Display Ticket Options and Attractions\n";
        std::cout << "2. Make a Booking\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displayOptions();
                break;
            case 2:
                processBooking();
                break;
            case 3:
                exitProgram = true;
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
