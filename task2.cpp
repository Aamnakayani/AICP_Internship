#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;
const int MIN_SENIORS = 10;
const int MAX_SENIORS = 36;
const double CARER_COST = 0.0;
const double COACH_COSTS[3] = {150, 190, 225};
const double MEAL_COSTS[3] = {14.0, 13.5, 13.0};
const double TICKET_COSTS[3] = {21.0, 20.0, 19.0};
const int COST_RANGES[3][2] = {{12, 16}, {17, 26}, {27, 39}};

void calculateOutingCosts(int numSeniors, double& totalCost, double& costPerPerson) {
    int rangeIndex = -1;
    for (int i = 0; i < 3; ++i) {
        if (numSeniors >= COST_RANGES[i][0] && numSeniors <= COST_RANGES[i][1]) {
            rangeIndex = i;
            break;
        }
    }
    if (rangeIndex == -1) {
        cout << "Invalid number of seniors for outing." << endl;
        return;
    }
    totalCost = COACH_COSTS[rangeIndex] + MEAL_COSTS[rangeIndex] + TICKET_COSTS[rangeIndex];
    int numCarers = (numSeniors > 24) ? 2 : 1;
    totalCost += numCarers * CARER_COST;
    costPerPerson = totalCost / (numSeniors + numCarers);
}

void recordOutingParticipants(int numSeniors, double costPerPerson) {
    vector<string> names;
    vector<double> payments;

    cout << "---Enter names and payments for the participants:---" << endl;
    for (int i = 0; i < numSeniors; ++i) {
        string name;
        double payment;
        cout << "Enter Name of participant " << i + 1 << ": ";
        cin >> name;
        cout << "Enter Payment made by " << name << ": $";
        cin >> payment;
        names.push_back(name);
        payments.push_back(payment);
    }

    cout << "\n***List of participants:***" << endl;
    cout << setw(20) << left << "Name" << "Payment" << endl;
    double totalPayments = 0;
    for (int i = 0; i < numSeniors; ++i) {
        cout << setw(20) << left << names[i] << "$" << payments[i] << endl;
        totalPayments += payments[i];
    }
    cout << "The Total amount collected is : $" << totalPayments << endl;
}

void identifyBreakEvenOrProfit(double totalCost, double totalPayments) {
    cout << "\nThe Total cost of the outing is : $" << totalCost << endl;
    cout << "The Total amount collected is : $" << totalPayments << endl;

    if (totalPayments >= totalCost) {
        double profit = totalPayments - totalCost;
        cout << "The outing has made a profit of :  $" << profit << endl;
    } else {
        double loss = totalCost - totalPayments;
        cout << "The outing has faced a loss of : $" << loss << endl;
    }
}
int main() {
    int numSeniors;
    cout << "---Enter the number of senior citizens interested in the outing: ";
    cin >> numSeniors;

    if (numSeniors < MIN_SENIORS || numSeniors > MAX_SENIORS) {
        cout << "Invalid number of seniors for outing." << endl;
        return 1;
    }

    double totalCost, costPerPerson;
    calculateOutingCosts(numSeniors, totalCost, costPerPerson);
    cout << fixed << setprecision(2);
    cout << "The Total cost of the outing is : $ " << totalCost << endl;
    cout << "The Cost per person is : $" << costPerPerson << endl;

    recordOutingParticipants(numSeniors, costPerPerson);

    double totalPayments = 0;
    for (int i = 0; i < numSeniors; ++i) {
        double payment;
        cout << "Payment made by participant " << i + 1 << ": $";
        cin >> payment;
        totalPayments += payment;
    }

    double remainingAmount = totalCost - totalPayments;
    if (remainingAmount > 0) {
        cout << "There's still an amount of $" << remainingAmount << " remaining to be collected." << endl;
        totalPayments += remainingAmount;
    }
    identifyBreakEvenOrProfit(totalCost, totalPayments);
    return 0;
}
