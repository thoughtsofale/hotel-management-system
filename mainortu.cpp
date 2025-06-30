#include <iostream>
#include <ctime>
#include <string>

using namespace std;

struct RoomFeatures {
    string amenities;
    double price;
    string lunchTimings;
    string lunchMenu;
    string gymTimings;
    string poolTimings;
};

struct Room {
    int roomNumber;
    string roomType;
    bool isOccupied;
    string floor;
    RoomFeatures features;
};

struct Customer {
    string name;
    string phoneNumber;
    string cnic;
    string address;
    Room* room;
    int totaldays;
    double totalbill;
};

const int MAX_ROOMS = 100;
Room rooms[MAX_ROOMS];
int totalRooms = 0;
Customer customers[MAX_ROOMS];
int totalCustomers = 0;

void displayMenu() {
    cout << "======= 7 Star Hotel Management System =======\n";
    cout << "1. Manage Rooms\n";
    cout << "2. Search Customer\n";
    cout << "3. Check-In\n";
    cout << "4. Check-Out\n";
    cout << "5. Lunch Menu\n";
    cout << "6. Gym Timings\n";
    cout << "7. Pool Timings\n";
    cout << "8. Exit\n";
    cout << "==============================================\n";
}
void lunchMenu() {
    cout << "======= Lunch Menu =======\n";
    // Display the lunch menu options here
    // You can modify the code to show the menu items or take any necessary input
     cout<<"break fast timing: 8:00 am to 12:00 pm"<<endl;
    cout<<"dinner timing: 7:00 pm to 10:00 pm"<<endl;
    cout << "----------------------------\n";
    cout << endl;
}
void gymTimings() {
    cout << "======= Gym Timings =======\n";
    // Display the gym timings here
    // You can modify the code to show the timings or take any necessary input
    cout<<"morning timing: 6:00 am to 10:00 am"<<endl;
    cout<<"evening timing: 6:00 pm to 10:00 pm"<<endl;
    cout << "----------------------------\n";
    cout << endl;
}
void poolTimings() {
    cout << "======= Pool Timings =======\n";
    // Display the pool timings here
    // You can modify the code to show the timings or take any necessary input
    cout<<"we are providing 24/7 facility of pool ";
    cout << "----------------------------\n";
    cout << endl;
}

void manageRooms() {
    cout << "======= Manage Rooms =======\n";
    for (int i = 0; i < totalRooms; i++) {
        cout << "Room Number: " << rooms[i].roomNumber << endl;
        cout << "Room Type: " << rooms[i].roomType << endl;
        cout << "Occupied: " << (rooms[i].isOccupied ? "Yes" : "No") << endl;
        cout << "Floor: " << rooms[i].floor << endl;
        cout << "Amenities: " << rooms[i].features.amenities << endl;
        cout << "Price: $" << rooms[i].features.price << endl;
        cout << "Lunch Timings: " << rooms[i].features.lunchTimings << endl;
        cout << "Lunch Menu: " << rooms[i].features.lunchMenu << endl;
        cout << "Gym Timings: " << rooms[i].features.gymTimings << endl;
        cout << "Pool Timings: " << rooms[i].features.poolTimings << endl;
        cout << "----------------------------\n";
    }
    cout << endl;
}

void searchCustomer() {
    cout << "======= Search Customer =======\n";
    string phoneNumber;
    cout << "Enter customer phone number: ";
    cin >> phoneNumber;

    for (int i = 0; i < totalCustomers; i++) {
        if (customers[i].phoneNumber == phoneNumber) {
            cout << "Customer Name: " << customers[i].name << endl;
            cout << "Phone Number: " << customers[i].phoneNumber << endl;
            cout << "CNIC: " << customers[i].cnic << endl;
            cout << "Address: " << customers[i].address << endl;
            cout << "Room Number: " << customers[i].room->roomNumber << endl;
            cout << "Floor: " << customers[i].room->floor << endl;
            cout << "----------------------------\n";
            return;
        }
    }
    cout << "Customer not found!\n\n";
}

void checkIn() {
    cout << "======= Check-In =======\n";
    int numOfRooms;
    cout << "Enter the number of rooms to check-in: ";
    cin >> numOfRooms;

    cout << "Available Room Types:\n";
    cout << "1. Deluxe\n";
    cout << "2. Suite\n";

    for (int i = 0; i < numOfRooms; i++) {
        int roomType;
        cout << "Enter room type for room " << i + 1 << ": ";
        cin >> roomType;

        if (roomType < 1 || roomType > 2) {
            cout << "Invalid room type!\n\n";
            return;
        }

        cout << "Available Rooms:\n";
        for (int j = 0; j < totalRooms; j++) {
            if (rooms[j].roomType == (roomType == 1 ? "Deluxe" : "Suite") && !rooms[j].isOccupied) {
                cout << "Room Number: " << rooms[j].roomNumber << endl;
                cout << "Room Type: " << rooms[j].roomType << endl;
                cout << "Floor: " << rooms[j].floor << endl;
                cout << "----------------------------\n";
            }
        }

        int roomNumber;
        cout << "Enter room number for room " << i + 1 << ": ";
        cin >> roomNumber;

        if (roomNumber < 0 || roomNumber >= totalRooms || rooms[roomNumber].isOccupied) {
            cout << "Invalid room number!\n\n";
            return;
        }

        cout << "Enter customer name: ";
        string name;
        cin.ignore();
        getline(cin, name);

        cout << "Enter customer phone number: ";
        string phoneNumber;
        cin >> phoneNumber;

        cout << "Enter customer CNIC: ";
        string cnic;
        cin >> cnic;

        cout << "Enter customer address: "<<endl;
        string address;
        cin.ignore();
        getline(cin, address);
        cout<<"enter total number of days: ";
        int totaldays;
        cin>>totaldays;
        double totalbill = totaldays * rooms[roomNumber].features.price;  // Calculate the total bill

        customers[totalCustomers].name = name;
        customers[totalCustomers].phoneNumber = phoneNumber;
        customers[totalCustomers].cnic = cnic;
        customers[totalCustomers].address = address;
        customers[totalCustomers].room = &rooms[roomNumber];
        customers[totalCustomers].totaldays = totaldays;
        customers[totalCustomers].totalbill = totalbill;  
       
        rooms[roomNumber].isOccupied = true;
        cout << "Total Bill: $" << totalbill << endl; // show total bill of customer

        totalCustomers++;
    }

    cout << "Check-in completed!\n\n";
}

void checkOut() {
    cout << "======= Check-Out =======\n";
    string phoneNumber;
    cout << "Enter customer phone number: ";
    cin >> phoneNumber;

    for (int i = 0; i < totalCustomers; i++) {
        if (customers[i].phoneNumber == phoneNumber) {
            customers[i].room->isOccupied = false;
            for (int j = i; j < totalCustomers - 1; j++) {
                customers[j] = customers[j + 1];
            }
            totalCustomers--;
            cout << "Check-out completed!\n\n";
            return;
        }
    }
    cout << "Customer not found!\n\n";
}

int main() {
    rooms[totalRooms++] = { 101, "Deluxe", false, "First Floor", {"TV, Mini Bar, Wi-Fi", 150.0, "12:00 PM - 3:00 PM", "Deluxe Lunch Menu", "6:00 AM - 10:00 PM", "8:00 AM - 8:00 PM"} };
rooms[totalRooms++] = { 102, "Suite", false, "First Floor", {"TV, Mini Bar, Wi-Fi, Kitchen", 250.0, "12:00 PM - 3:00 PM", "Suite Lunch Menu", "6:00 AM - 10:00 PM", "8:00 AM - 8:00 PM"} };
rooms[totalRooms++] = { 201, "Deluxe", false, "Second Floor", {"TV, Mini Bar, Wi-Fi", 150.0, "12:00 PM - 3:00 PM", "Deluxe Lunch Menu", "6:00 AM - 10:00 PM", "8:00 AM - 8:00 PM"} };
rooms[totalRooms++] = { 202, "Suite", false, "Second Floor", {"TV, Mini Bar, Wi-Fi, Kitchen", 250.0, "12:00 PM - 3:00 PM", "Suite Lunch Menu", "6:00 AM - 10:00 PM", "8:00 AM - 8:00 PM"} };
rooms[totalRooms++] = { 301, "Deluxe", false, "Third Floor", {"TV, Mini Bar, Wi-Fi", 150.0, "12:00 PM - 3:00 PM", "Deluxe Lunch Menu", "6:00 AM - 10:00 PM", "8:00 AM - 8:00 PM"} };
rooms[totalRooms++] = { 302, "Suite", false, "Third Floor", {"TV, Mini Bar, Wi-Fi, Kitchen", 250.0, "12:00 PM - 3:00 PM", "Suite Lunch Menu", "6:00 AM - 10:00 PM", "8:00 AM - 8:00 PM"} };

    int choice;
    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                manageRooms();
                break;
            case 2:
                searchCustomer();
                break;
            case 3:
                checkIn();
                break;
            case 4:
                checkOut();
                break;
                case 5:
                lunchMenu();
                break;
            case 6:
                gymTimings();
                break;
            case 7:
                poolTimings();
                break;
            case 8:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 8);

    return 0;
}

