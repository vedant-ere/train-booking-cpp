#pragma once
#include <iostream>
#include <time.h>
#include <vector>
#include "user.hpp"
#include "train.hpp"

using namespace std;

struct Vehicle {
    string vehicleId;
    string name;
    string source;
    string destination;
    time_t time;
    vector<vector<User>> seats;
};

inline Train convert(Vehicle vehicle) {
    Train train;
    train.trainId = vehicle.vehicleId;
    train.name = vehicle.name;
    train.source = vehicle.source;
    train.destination = vehicle.destination;
    train.time = vehicle.time;
    train.seats.resize(vehicle.seats.size());
    for(size_t i = 0; i < vehicle.seats.size(); i++) {
        train.seats[i] = vehicle.seats[i];
    }
    return train;
}