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
    // Implementation for cancel booking
}

template <>
void BookingService<Vehicle>::printBooking(string entityId, string userId) {
    // Implementation for print booking
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
    // Implementation for cancel booking
}

template <>
void BookingService<Train>::printBooking(string entityId, string userId) {
    // Implementation for print booking
}

template <>
void BookingService<Train>::saveBooking(Train entity) {
    FileIO<Train> file;
    file.saveToFile(entity);
}