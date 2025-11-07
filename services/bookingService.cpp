#include "bookingService.hpp"
#include <ctime>

// Template implementation for Vehicle
template <>
void BookingService<Vehicle>::book(string entityId, User user, string name, string source, string destination) {
    Vehicle vehicle;
    vehicle.vehicleId = entityId;
    vehicle.name = name;
    vehicle.source = source;
    vehicle.destination = destination;
    vehicle.time = time(nullptr);
    vehicle.seats = {{user}};
    
    saveBooking(vehicle);
}

template <>
void BookingService<Vehicle>::cancelBooking(string entityId, string userId) {
    vector<Vehicle> allBookings = getAllBookings();
    bool found = false;

    for (auto& vehicle : allBookings) {
        if (vehicle.vehicleId == entityId) {
            // Find and remove the user from seats
            for (auto& row : vehicle.seats) {
                auto it = row.begin();
                while (it != row.end()) {
                    if (it->userId == userId) {
                        it = row.erase(it);
                        found = true;
                        cout << "Booking cancelled successfully for User ID: " << userId << endl;
                    } else {
                        ++it;
                    }
                }
            }

            // Remove empty rows
            auto rowIt = vehicle.seats.begin();
            while (rowIt != vehicle.seats.end()) {
                if (rowIt->empty()) {
                    rowIt = vehicle.seats.erase(rowIt);
                } else {
                    ++rowIt;
                }
            }
        }
    }

    if (found) {
        updateAllBookings(allBookings);
    } else {
        cout << "Booking not found for Vehicle ID: " << entityId << " and User ID: " << userId << endl;
    }
}

template <>
void BookingService<Vehicle>::printBooking(string entityId, string userId) {
    vector<Vehicle> allBookings = getAllBookings();
    bool found = false;

    for (const auto& vehicle : allBookings) {
        if (vehicle.vehicleId == entityId) {
            // Search for the user in seats
            for (const auto& row : vehicle.seats) {
                for (const auto& user : row) {
                    if (user.userId == userId) {
                        found = true;
                        cout << "\n========== BOOKING DETAILS ==========" << endl;
                        cout << "Vehicle ID: " << vehicle.vehicleId << endl;
                        cout << "Vehicle Name: " << vehicle.name << endl;
                        cout << "Route: " << vehicle.source << " -> " << vehicle.destination << endl;

                        // Convert time_t to readable format
                        char timeStr[100];
                        struct tm* timeinfo = localtime(&vehicle.time);
                        strftime(timeStr, sizeof(timeStr), "%Y-%m-%d %H:%M:%S", timeinfo);
                        cout << "Booking Time: " << timeStr << endl;

                        cout << "\n--- Passenger Details ---" << endl;
                        cout << "User ID: " << user.userId << endl;
                        cout << "Name: " << user.name << endl;
                        cout << "Aadhar Card: " << user.aadharCard << endl;
                        cout << "====================================\n" << endl;
                        break;
                    }
                }
                if (found) break;
            }
        }
        if (found) break;
    }

    if (!found) {
        cout << "Booking not found for Vehicle ID: " << entityId << " and User ID: " << userId << endl;
    }
}

template <>
void BookingService<Vehicle>::saveBooking(Vehicle entity) {
    FileIO<Vehicle> file;
    file.saveToFile(entity);
}

// Template implementation for Train
template <>
void BookingService<Train>::book(string entityId, User user, string name, string source, string destination) {
    Train train;
    train.trainId = entityId;
    train.name = name;
    train.source = source;
    train.destination = destination;
    train.time = time(nullptr);
    train.seats = {{user}};
    
    saveBooking(train);
}

template <>
void BookingService<Train>::cancelBooking(string entityId, string userId) {
    vector<Train> allBookings = getAllBookings();
    bool found = false;

    for (auto& train : allBookings) {
        if (train.trainId == entityId) {
            // Find and remove the user from seats
            for (auto& row : train.seats) {
                auto it = row.begin();
                while (it != row.end()) {
                    if (it->userId == userId) {
                        it = row.erase(it);
                        found = true;
                        cout << "Booking cancelled successfully for User ID: " << userId << endl;
                    } else {
                        ++it;
                    }
                }
            }

            // Remove empty rows
            auto rowIt = train.seats.begin();
            while (rowIt != train.seats.end()) {
                if (rowIt->empty()) {
                    rowIt = train.seats.erase(rowIt);
                } else {
                    ++rowIt;
                }
            }
        }
    }

    if (found) {
        updateAllBookings(allBookings);
    } else {
        cout << "Booking not found for Train ID: " << entityId << " and User ID: " << userId << endl;
    }
}

template <>
void BookingService<Train>::printBooking(string entityId, string userId) {
    vector<Train> allBookings = getAllBookings();
    bool found = false;

    for (const auto& train : allBookings) {
        if (train.trainId == entityId) {
            // Search for the user in seats
            for (const auto& row : train.seats) {
                for (const auto& user : row) {
                    if (user.userId == userId) {
                        found = true;
                        cout << "\n========== BOOKING DETAILS ==========" << endl;
                        cout << "Train ID: " << train.trainId << endl;
                        cout << "Train Name: " << train.name << endl;
                        cout << "Route: " << train.source << " -> " << train.destination << endl;

                        // Convert time_t to readable format
                        char timeStr[100];
                        struct tm* timeinfo = localtime(&train.time);
                        strftime(timeStr, sizeof(timeStr), "%Y-%m-%d %H:%M:%S", timeinfo);
                        cout << "Booking Time: " << timeStr << endl;

                        cout << "\n--- Passenger Details ---" << endl;
                        cout << "User ID: " << user.userId << endl;
                        cout << "Name: " << user.name << endl;
                        cout << "Aadhar Card: " << user.aadharCard << endl;
                        cout << "====================================\n" << endl;
                        break;
                    }
                }
                if (found) break;
            }
        }
        if (found) break;
    }

    if (!found) {
        cout << "Booking not found for Train ID: " << entityId << " and User ID: " << userId << endl;
    }
}

template <>
void BookingService<Train>::saveBooking(Train entity) {
    FileIO<Train> file;
    file.saveToFile(entity);
}