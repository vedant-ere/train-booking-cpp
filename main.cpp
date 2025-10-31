#include <iostream>
#include "entities/vehicle.hpp"
#include "entities/user.hpp"
#include "./services/bookingService.hpp"

using namespace std;

int main() {
    string userId;
    string name;
    string aadharCard;

    cout << "Enter User ID: ";
    cin >> userId;
    cout << "Enter Name: ";
    cin >> name;
    cout << "Enter Aadhar Card Number: ";
    cin >> aadharCard;

    cout << "Enter the option: " << endl;
    cout << "Enter 1 to book the train" << endl;
    int option;
    cin >> option;

    // signup login user using userid --> user.json
    // fetch train using train name --> train.json
    // booking --> fetch train using trainId, fetch seats, store user there, booking.json

    switch(option) {
        case 1: {
            string trainId, trainName, source, destination;
            
            cout << "Enter Train ID: ";
            cin >> trainId;
            cout << "Enter Train Name: ";
            cin >> trainName;
            cout << "Enter Source Station: ";
            cin >> source;
            cout << "Enter Destination Station: ";
            cin >> destination;

            User user;
            user.userId = userId;
            user.name = name;
            user.aadharCard = aadharCard;
            
            BookingService<Vehicle> bookingService;
            bookingService.book(trainId, user, trainName, source, destination);
            
            cout << "Train booked successfully!" << endl;
            break;
        }
        default:
            cout << "Invalid option" << endl;
            break;
    }

    return 0;
}