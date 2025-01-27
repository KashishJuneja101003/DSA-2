#include <iostream>
#include <unordered_map>
#include <stack>
#include <cmath>
using namespace std;

// Vehicle structure to store the details of each parked vehicle
struct Vehicle {
    string type;         // Type of vehicle (car, bike)
    string license;      // License plate of the vehicle
    int entryTime;       // Entry time of the vehicle in hours
};

class ParkingLot {
private:
    int totalSpots;                           // Total parking spots in the lot
    stack<int> availableSpots;                // Stack for LIFO spot allocation
    unordered_map<string, Vehicle> parkedVehicles; // Map of license -> Vehicle details
    unordered_map<string, int> vehicleSpotMap;     // Map of license -> Spot number
    const int parkingRate = 20;               // Fixed parking fee rate (₹20 per hour)

public:
    // Constructor to initialize parking lot with the total spots
    ParkingLot(int n) : totalSpots(n) {
        for (int i = n; i >= 1; --i) { // Fill the stack with spots in reverse order
            availableSpots.push(i);
        }
    }

    // Function to park a vehicle
    void parkVehicle(string vehicleType, string license, int entryTime) {
        // If no parking spots are available
        if (availableSpots.empty()) {
            cout << "-1\n"; // Parking lot is full
            return;
        }

        // If the vehicle is already parked
        if (parkedVehicles.find(license) != parkedVehicles.end()) {
            cout << "Vehicle with license " << license << " is already parked.\n";
            return;
        }

        // Allocate the top spot from the stack
        int spot = availableSpots.top();
        availableSpots.pop();

        // Store vehicle details
        parkedVehicles[license] = {vehicleType, license, entryTime};
        vehicleSpotMap[license] = spot;

        // Output the allocated spot
        cout << "Spot " << spot << " allocated to " << vehicleType << " " << license << ".\n";
    }

    // Function to remove a vehicle and calculate the parking fee
    void removeVehicle(string license, int exitTime) {
        // If the vehicle is not found in the parking lot
        if (parkedVehicles.find(license) == parkedVehicles.end()) {
            cout << "-1\n"; // Vehicle is not parked in the lot
            return;
        }

        // Retrieve vehicle details
        Vehicle vehicle = parkedVehicles[license];
        int spot = vehicleSpotMap[license];
        int duration = max(1, exitTime - vehicle.entryTime); // Ensure minimum 1-hour fee
        int fee = ceil(duration) * parkingRate;

        // Free the parking spot and remove the vehicle from records
        availableSpots.push(spot);
        parkedVehicles.erase(license);
        vehicleSpotMap.erase(license);

        // Output the removal message and parking fee
        cout << vehicle.type << " " << license << " removed from Spot " << spot 
             << ". Parking fee: ₹" << fee << ".\n";
    }
};

int main() {
    int totalSpots;
    do {
        cout << "Enter total parking spots (1 <= total_spots <= 1000): ";
        cin >> totalSpots;
        if (totalSpots < 1 || totalSpots > 1000) {
            cout << "Invalid input. Please enter a number between 1 and 1000.\n";
        }
    } while (totalSpots < 1 || totalSpots > 1000);

    // Initialize parking lot
    ParkingLot lot(totalSpots);

    int choice;
    while (true) {
        cout << "\n1. Park Vehicle\n2. Remove Vehicle\n3. Exit\nEnter choice: ";
        cin >> choice;
        if (choice == 3) break;

        string vehicleType, license;
        int time;
        switch (choice) {
            case 1: // Park Vehicle
                cout << "Enter vehicle type (car/bike): ";
                cin >> vehicleType;
                cout << "Enter license number: ";
                cin >> license;
                cout << "Enter entry time (0-23): ";
                cin >> time;
                lot.parkVehicle(vehicleType, license, time);
                break;
            case 2: // Remove Vehicle
                cout << "Enter license number: ";
                cin >> license;
                cout << "Enter exit time (0-23): ";
                cin >> time;
                lot.removeVehicle(license, time);
                break;
            default:
                cout << "Invalid choice.\n";
        }
    }

    return 0;
}
