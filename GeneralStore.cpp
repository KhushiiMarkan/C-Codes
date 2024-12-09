#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

class Store {
    struct Product {
        int id;
        string name;
        float price;
    };

    Product products[4] = {
        {101, "Lays", 20},
        {102, "Juice", 50},
        {103, "Biscuits", 30},
        {104, "Chocolates", 20}
    };

    int selectedId;
    vector<int> ID;
    int selectedQuantity;
    float totalAmount = 0;
    vector<int> Q;

public:
    void list();
    void buy();
    void bill();
};

void Store::list() {
    cout << "Here is a list of items that are available at our Store." << endl;
    cout << "-------------------------------------------------" << endl;
    cout << left << setw(15) << "ProductID" 
         << setw(25) << "ProductName" 
         << setw(10) << "Price" << endl;
    cout << "-------------------------------------------------" << endl;

    for (int i = 0; i < 4; i++) {
        cout << left << setw(15) << products[i].id 
             << setw(25) << products[i].name 
             << fixed << setprecision(2) << setw(10) << products[i].price << endl;
    }
}

void Store::buy() {
    char choice;
    do {
        cout << "Enter the product ID to buy the item: ";
        cin >> selectedId;
        ID.push_back(selectedId);

        cout << "Enter the quantity: ";
        cin >> selectedQuantity;
        Q.push_back(selectedQuantity);

        cout << "Do you want to buy anything else? (Y/N): ";
        cin >> choice;
    } while (choice == 'Y' || choice == 'y');
}

void Store::bill() {
    cout << "Here's your bill:" << endl;
    cout << "----------------------------------------------------------------------" << endl;
    cout << left << setw(15) << "ProductID" 
         << setw(25) << "ProductName" 
         << setw(10) << "Quantity" 
         << setw(10) << "Price" 
         << setw(10) << "Amount" << endl;
    cout << "----------------------------------------------------------------------" << endl;

    for (int j = 0; j < ID.size(); j++) {
        float amount = 0;
        for (int i = 0; i < 4; i++) {
            if (products[i].id == ID[j]) {
                amount = products[i].price * Q[j];
                totalAmount += amount;

                cout << left << setw(15) << products[i].id 
                     << setw(25) << products[i].name 
                     << setw(10) << Q[j] 
                     << fixed << setprecision(2) << setw(10) << products[i].price 
                     << setw(10) << amount << endl;

                break;
            }
        }
    }
    cout << "-------------------------------------------------------" << endl;
    cout << "Your total bill is: " << fixed << setprecision(2) << totalAmount << endl;
}

int main() {
    cout << "Welcome to our General Store" << endl;
    Store s;
    s.list();
    s.buy();
    s.bill();
    return 0;
}
