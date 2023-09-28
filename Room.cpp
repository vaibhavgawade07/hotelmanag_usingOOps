#include <iostream>
#include <string>
#include <limits>

using namespace std;

class Room {
private:
    int roomNumber;
    string customer;
    double totalAmount = 0;
    int roomprice = 1000;
    int roomprice2 = 2000;
    int roomprice3 = 4000;

public:
    void roomdetails() {
        cout << "Press Number from 1-3 to continue info of the room:" << endl;
        int choice1;
        cin >> choice1;
        switch (choice1) {
            case 1:
                cout << "Single" << endl;
                cout << "Price- Rs " << roomprice << endl;
                cout << "Ac - No" << endl;
                break;
            case 2:
                cout << "Double" << endl;
                cout << "Price- Rs " << roomprice2 << endl;
                cout << "Ac - No" << endl;
                break;
            case 3:
                cout << "Luxury" << endl;
                cout << "Price- Rs " << roomprice3 << endl;
                cout << "Ac - Yes" << endl;
                cout << "Free Breakfast" << endl;
                break;
            default:
                cout << "Invalid data" << endl;
        }
    }

    void Availability(int roomno) {
        if (roomno < 4 || roomno == 2 || roomno == 3) {
            cout << "Available" << endl;
        } else if (roomno >= 4) {
            cout << "Room doesn't Exist!!" << endl;
        } else {
            cout << "Room not Available" << endl;
        }
    }

    void roombook(int roomNumber, const string& customer) {
        this->roomNumber = roomNumber;
        this->customer = customer;
        cout << "The room no " << roomNumber << " booked by " << customer << endl;
    }

    void orderFood(int roomNumber) {
        cout << "\n==========\n   Menu:  \n==========\n";
        string menuItems[] = {"Sandwich", "Pasta", "Noodles", "Coke"};
        double menuPrices[] = {50, 60, 70, 30};
        cout << "Item\tPrice" << endl;
        for (int i = 0; i < sizeof(menuItems) / sizeof(menuItems[0]); i++) {
            cout << i + 1 << ". " << menuItems[i] << "\tRs." << menuPrices[i] << endl;
        }

        double totalAmount = 0;
        while (true) {
            cout << "Enter item number (1-4): ";
            int itemNumber;
            cin >> itemNumber;
            if (itemNumber < 1 || itemNumber > sizeof(menuItems) / sizeof(menuItems[0])) {
                cout << "Invalid item number. Try again." << endl;
                continue;
            }

            cout << "Enter quantity: ";
            int quantity;
            cin >> quantity;
            if (quantity <= 0) {
                cout << "Invalid quantity. Try again." << endl;
                continue;
            }

            totalAmount += menuPrices[itemNumber - 1] * quantity;
            cout << "Do you want to order anything else? (y/n): ";
            char wish;
            cin >> wish;

            if (wish == 'n' || wish == 'N') {
                break;
            }
        }
        cout << "Your bill: Rs" << totalAmount << endl;
    }

    void totalbill() {
        cout << "Sir which room" << endl;
        int romno;
        cin >> romno;
        double totalBil = 0;
        if (romno == 1) {
            totalBil = roomprice + totalAmount;
        } else if (romno == 2) {
            totalBil = roomprice2 + totalAmount;
        } else if (romno == 3) {
            totalBil = roomprice3 + totalAmount;
        }
        cout << "Your Total bill. Rs" << totalBil << endl;
        cout << "===Thanks for Visit.=== Visit Again===" << endl;
    }
};

int main() {
    cout << "\n===== Hotel Management System =====" << endl;
    cout << "\n===Welcome to the Hotel. How may I help you!===" << endl;
    cout << "1. Display Room Details" << endl;
    cout << "2. Display Room Availability" << endl;
    cout << "3. Book Room" << endl;
    cout << "4. Order Food" << endl;
    cout << "5. Bill" << endl;

    Room ob;

    string Naam;  // Declare the variable outside the switch

    while (true) {
        int choice;
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Display room Details" << endl;
                ob.roomdetails();
                break;
            case 2:
                cout << "Enter room from 1-5" << endl;
                int roomno;
                cin >> roomno;
                ob.Availability(roomno);
                break;
            case 3:
                cout << "Enter room No to book" << endl;
                int no;
                cin >> no;
                cin.ignore(1000, '\n'); // Consume the newline character left in the input buffer
                cout << "Enter Name-";
                getline(cin, Naam);
                ob.roombook(no, Naam);
                break;
            case 4:
                cout << "Enter room Number" << endl;
                int roomno1;
                cin >> roomno1;
                ob.orderFood(roomno1);
                cout << "Thanks for Order." << endl;
                break;
            case 5:
                ob.totalbill();
                break;
            default:
                cout << "Invalid" << endl;
        }
    }

    return 0;
}
