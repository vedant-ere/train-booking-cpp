#pragma once
#include <iostream>
#include <ctime>
#include "../entities/user.hpp"
#include "../entities/vehicle.hpp"
#include "../entities/train.hpp"
#include "fileIO.hpp"

using namespace std;

template <typename T>
class BookingService {
    public:
        void book(string entityId, User user, string name, string source, string destination);
        void cancelBooking(string entityId, string userId);
        void printBooking(string entityId, string userId);

    private:
        void saveBooking(T entity) {
            FileIO<T> file;
            file.saveToFile(entity);
        }
};

// Template specializations for Vehicle
template <>
void BookingService<Vehicle>::saveBooking(Vehicle entity);

// Template specializations for Train
template <>
void BookingService<Train>::saveBooking(Train entity);