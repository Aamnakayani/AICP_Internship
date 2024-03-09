#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

double calculatePrice(string day, int arrivalHour, int hours, string frequentParkingNumber);
void task1();
void task2();
void task3();

double dailyTotal = 0.0;

int main() {
    int choice;
    
    do {
        cout << "Car Park Payment System Menu\n";
        cout << "1. Task 1 - Calculate Price to Park\n";
        cout << "2. Task 2 - Keep Total of Payments\n";
        cout << "3. Task 3 - Make Payments Fairer\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                task1();
                break;
            case 2:
                task2();
                break;
            case 3:
                task3();
                break;
            case 4:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 4);
    
    return 0;
}

double calculatePrice(string day, int arrivalHour, int hours, string frequentParkingNumber) {
    double pricePerHour;
    int maxStay;
    double discount;
    double total = 0.0;


    if (day == "Sunday" && arrivalHour >= 8 && arrivalHour <= 15) {
        pricePerHour = 2.00;
        maxStay = 8;
    } else if ((day == "Monday" || day == "Tuesday" || day == "Wednesday" || day == "Thursday" || day == "Friday") && arrivalHour >= 8 && arrivalHour <= 15) {
        pricePerHour = 10.00;
        maxStay = 2;
    } else if (day == "Saturday" && arrivalHour >= 8 && arrivalHour <= 15) {
        pricePerHour = 3.00;
        maxStay = 4;
    } else {
        pricePerHour = 2.00;
        maxStay = 2;
    }

    if (arrivalHour >= 16 && arrivalHour <= 23) {
        discount = 0.5;
    } else {
        discount = 0.1;
    }

  
    if (!frequentParkingNumber.empty() && frequentParkingNumber.length() == 5) {
        int checkDigit = (frequentParkingNumber[0] + frequentParkingNumber[1] + frequentParkingNumber[2] + frequentParkingNumber[3]) % 11;
        if (checkDigit == (frequentParkingNumber[4] - '0')) {
            total = (hours <= maxStay) ? (pricePerHour * hours * (1 - discount)) : (pricePerHour * maxStay * (1 - discount));
        } else {
            cout << "Invalid frequent parking number. No discount applied.\n";
            total = (hours <= maxStay) ? (pricePerHour * hours) : (pricePerHour * maxStay);
        }
    } else {
        total = (hours <= maxStay) ? (pricePerHour * hours) : (pricePerHour * maxStay);
    }

    return total;
}


void task1() {
    string day;
    int arrivalHour, hours;
    string frequentParkingNumber;
    
    cout << "Enter day of the week: ";
    cin >> day;
    cout << "Enter hour of arrival (0-23): ";
    cin >> arrivalHour;
    cout << "Enter number of hours to park: ";
    cin >> hours;
    cout << "Enter frequent parking number (if available, otherwise leave blank): ";
    cin >> frequentParkingNumber;
    
    double price = calculatePrice(day, arrivalHour, hours, frequentParkingNumber);
    cout << fixed << setprecision(2);
    cout << "Price to park: $" << price << endl;
}


void task2() {
    dailyTotal = 0.0; 
    int numCustomers;
    
    cout << "Enter number of customers for today: ";
    cin >> numCustomers;
    
    for (int i = 0; i < numCustomers; ++i) {
        string day, frequentParkingNumber;
        int arrivalHour, hours;
        double pricePaid;
        
        cout << "Enter day of the week for customer " << i + 1 << ": ";
        cin >> day;
        cout << "Enter hour of arrival (0-23) for customer " << i + 1 << ": ";
        cin >> arrivalHour;
        cout << "Enter number of hours to park for customer " << i + 1 << ": ";
        cin >> hours;
        cout << "Enter price paid for parking for customer " << i + 1 << ": ";
        cin >> pricePaid;
        cout << "Enter frequent parking number (if available, otherwise leave blank) for customer " << i + 1 << ": ";
        cin >> frequentParkingNumber;
        
        double calculatedPrice = calculatePrice(day, arrivalHour, hours, frequentParkingNumber);
        if (pricePaid < calculatedPrice) {
            cout << "Error: Insufficient payment.\n";
            return;
        }
        
        dailyTotal += pricePaid;
    }
    
    cout << fixed << setprecision(2);
    cout << "Daily total payments: $" << dailyTotal << endl;
}


void task3() {
    string day;
    int arrivalHour, hours;
    string frequentParkingNumber;
    
    cout << "Enter day of the week: ";
    cin >> day;
    cout << "Enter hour of arrival (0-23): ";
    cin >> arrivalHour;
    cout << "Enter number of hours to park: ";
    cin >> hours;
    cout << "Enter frequent parking number (if available, otherwise leave blank): ";
    cin >> frequentParkingNumber;
    
    double priceBefore4PM = calculatePrice(day, arrivalHour, hours, frequentParkingNumber);
    double eveningPrice = calculatePrice(day, 16, (arrivalHour < 16) ? (16 - arrivalHour) : 0, frequentParkingNumber);
    double totalPrice = priceBefore4PM + eveningPrice;
    
    cout << fixed << setprecision(2);
    cout << "Price to park before 4:00 PM: $" << priceBefore4PM << endl;
    cout << "Evening charge after 4:00 PM: $" << eveningPrice << endl;
    cout << "Total price: $" << totalPrice << endl;
}
