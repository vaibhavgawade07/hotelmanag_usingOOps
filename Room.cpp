#include <iostream>
#include <string>
#include <limits>

class Room {
private:
    int roomNumber;
    std::string customer;
    double totalAmount = 0;
    int roomprice = 1000;
    int roomprice2 = 2000;
    int roomprice3 = 4000;

public:
    void roomdetails() {
        std::cout << "Press Number from 1-3 to continue info of the room:" << std::endl;
        int choice1;
        std::cin >> choice1;
        switch (choice1) {
            case 1:
                std::cout << "Single" << std::endl;
                std::cout << "Price- Rs " << roomprice << std::endl;
                std::cout << "Ac - No" << std::endl;
                break;
            case 2:
                std::cout << "Double" << std::endl;
                std::cout << "Price- Rs " << roomprice2 << std::endl;
                std::cout << "Ac - No" << std::endl;
                break;
            case 3:
                std::cout << "Luxury" << std::endl;
                std::cout << "Price- Rs " << roomprice3 << std::endl;
                std::cout << "Ac - Yes" << std::endl;
                std::cout << "Free Breakfast" << std::endl;
                break;
            default:
                std::cout << "Invalid data" << std::endl;
        }
    }

    void Availability(int roomno) {
        if (roomno < 4 || roomno == 2 || roomno == 3) {
            std::cout << "Available" << std::endl;
        } else if (roomno >= 4) {
            std::cout << "Room doesn't Exist!!" << std::endl;
        } else {
            std::cout << "Room not Available" << std::endl;
        }
    }

    void roombook(int roomNumber, const std::string& customer) {
        this->roomNumber = roomNumber;
        this->customer = customer;
        std::cout << "The room no " << roomNumber << " booked by " << customer << std::endl;
    }

    void orderFood(int roomNumber) {
        std::cout << "\n==========\n   Menu:  \n==========\n";
        std::string menuItems[] = {"Sandwich", "Pasta", "Noodles", "Coke"};
        double menuPrices[] = {50, 60, 70, 30};
        std::cout << "Item\tPrice" << std::endl;
        for (int i = 0; i < sizeof(menuItems) / sizeof(menuItems[0]); i++) {
            std::cout << i + 1 << ". " << menuItems[i] << "\tRs." << menuPrices[i] << std::endl;
        }

        double totalAmount = 0;
        while (true) {
            std::cout << "Enter item number (1-4): ";
            int itemNumber;
            std::cin >> itemNumber;
            if (itemNumber < 1 || itemNumber > sizeof(menuItems) / sizeof(menuItems[0])) {
                std::cout << "Invalid item number. Try again." << std::endl;
                continue;
            }

            std::cout << "Enter quantity: ";
            int quantity;
            std::cin >> quantity;
            if (quantity <= 0) {
                std::cout << "Invalid quantity. Try again." << std::endl;
                continue;
            }

            totalAmount += menuPrices[itemNumber - 1] * quantity;
            std::cout << "Do you want to order anything else? (y/n): ";
            char wish;
            std::cin >> wish;

            if (wish == 'n' || wish == 'N') {
                break;
            }
        }
        std::cout << "Your bill: Rs" << totalAmount << std::endl;
    }

    void totalbill() {
        std::cout << "Sir which room" << std::endl;
        int romno;
        std::cin >> romno;
        double totalBil = 0;
        if (romno == 1) {
            totalBil = roomprice + totalAmount;
        } else if (romno == 2) {
            totalBil = roomprice2 + totalAmount;
        } else if (romno == 3) {
            totalBil = roomprice3 + totalAmount;
        }
        std::cout << "Your Total bill. Rs" << totalBil << std::endl;
        std::cout << "===Thanks for Visit.=== Visit Again===" << std::endl;
    }
};

int main() {
    std::cout << "\n===== Hotel Management System =====" << std::endl;
    std::cout << "\n===Welcome to the Shubham Hotel. How may I help you!===" << std::endl;
    std::cout << "1. Display Room Details" << std::endl;
    std::cout << "2. Display Room Availability" << std::endl;
    std::cout << "3. Book Room" << std::endl;
    std::cout << "4. Order Food" << std::endl;
    std::cout << "5. Bill" << std::endl;

    Room ob;

    std::string Naam;  // Declare the variable outside the switch

    while (true) {
        int choice;
        std::cin >> choice;
        switch (choice) {
            case 1:
                std::cout << "Display room Details" << std::endl;
                ob.roomdetails();
                break;
            case 2:
                std::cout << "Enter room from 1-5" << std::endl;
                int roomno;
                std::cin >> roomno;
                ob.Availability(roomno);
                break;
            case 3:
                std::cout << "Enter room No to book" << std::endl;
                int no;
                std::cin >> no;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Consume the newline character left in the input buffer
                std::cout << "Enter Name-";
                std::getline(std::cin, Naam);
                ob.roombook(no, Naam);
                break;
            case 4:
                std::cout << "Enter room Number" << std::endl;
                int roomno1;
                std::cin >> roomno1;
                ob.orderFood(roomno1);
                std::cout << "Thanks for Order." << std::endl;
                break;
            case 5:
                ob.totalbill();
                break;
            default:
                std::cout << "Invalid" << std::endl;
        }
    }

    return 0;
}
