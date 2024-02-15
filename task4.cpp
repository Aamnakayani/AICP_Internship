#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Item {
    int itemNumber;
    string description;
    double reservePrice;
    double highestBid;
    int numberOfBids;
    bool sold;

    Item(int num, string desc, double reserve) : itemNumber(num), description(desc), reservePrice(reserve), highestBid(0), numberOfBids(0), sold(false) {}
};

class Auction {
private:
    vector<Item> items;
    double totalFee;

public:
    Auction() : totalFee(0) {}

    void setupAuction() {
        int itemCount;
        cout << "Enter the number of items in the auction (must be at least 10): ";
        cin >> itemCount;

        if (itemCount < 10) {
            cout << "Error: The number of items must be at least 10." << endl;
            return;
        }

        for (int i = 0; i < itemCount; ++i) {
            int itemNum;
            string desc;
            double reserve;
            cout << "Enter details for item " << i+1 << ":" << endl;
            cout << "Item number: ";
            cin >> itemNum;
            cout << "Description: ";
            cin.ignore();
            getline(cin, desc);
            cout << "Reserve price: ";
            cin >> reserve;
            items.push_back(Item(itemNum, desc, reserve));
        }
    }

    void displayItems() {
        cout << "Items in the auction:" << endl;
        for (const auto& item : items) {
            cout << "Item Number: " << item.itemNumber << endl;
            cout << "Description: " << item.description << endl;
            cout << "Reserve Price: $" << item.reservePrice << endl;
            cout << "-----------------------" << endl;
        }
    }

    void placeBid(int buyerNumber, int itemNumber, double bidAmount) {
        for (auto& item : items) {
            if (item.itemNumber == itemNumber) {
                if (bidAmount > item.highestBid) {
                    item.highestBid = bidAmount;
                    item.numberOfBids++;
                    cout << "Bid successfully placed on item " << itemNumber << " by Buyer " << buyerNumber << endl;
                } else {
                    cout << "Error: Your bid must be higher than the current highest bid." << endl;
                }
                return;
            }
        }
        cout << "Error: Item not found." << endl;
    }

    void endAuction() {
        int soldItems = 0;
        int itemsBelowReserve = 0;
        int itemsWithNoBids = 0;

        for (auto& item : items) {
            if (item.highestBid >= item.reservePrice) {
                item.sold = true;
                totalFee += 0.1 * item.highestBid;
                soldItems++;
            } else if (item.numberOfBids == 0) {
                itemsWithNoBids++;
            } else {
                itemsBelowReserve++;
            }
        }

        cout << "Total fee for sold items: $" << totalFee << endl;
        cout << "Items with bids that did not meet reserve price:" << endl;
        for (const auto& item : items) {
            if (!item.sold && item.numberOfBids > 0 && item.highestBid < item.reservePrice) {
                cout << "Item Number: " << item.itemNumber << ", Final Bid: $" << item.highestBid << endl;
            }
        }
        cout << "Items with no bids:" << endl;
        for (const auto& item : items) {
            if (!item.sold && item.numberOfBids == 0) {
                cout << "Item Number: " << item.itemNumber << endl;
            }
        }

        cout << "Number of items sold: " << soldItems << endl;
        cout << "Number of items with bids that did not meet reserve price: " << itemsBelowReserve << endl;
        cout << "Number of items with no bids: " << itemsWithNoBids << endl;
    }
};

int main() {
    Auction auction;
    auction.setupAuction();

    int choice;
    do {
        cout<<"***Menu****";
        cout << "\nn1. Display Items\n2. Place Bid\n3. End Auction\n4. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                auction.displayItems();
                break;
            case 2:
                int buyerNumber, itemNumber;
                double bidAmount;
                cout << "Enter Buyer Number: ";
                cin >> buyerNumber;
                cout << "Enter Item Number: ";
                cin >> itemNumber;
                cout << "Enter Bid Amount: $";
                cin >> bidAmount;
                auction.placeBid(buyerNumber, itemNumber, bidAmount);
                break;
            case 3:
                auction.endAuction();
                break;
            case 4:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 4);

    return 0;
}
