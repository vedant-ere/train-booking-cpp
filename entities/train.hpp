#pragma once
#include <iostream>
#include <time.h>
#include <vector>
#include "user.hpp"

using namespace std;

struct Train {
    string trainId;
    string name;
    string source;
    string destination;
    time_t time;
    vector<vector<User>> seats;
};