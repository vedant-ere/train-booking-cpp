#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "../external/json.hpp"
#include "../entities/vehicle.hpp"
#include "../entities/train.hpp"

using namespace std;
using json = nlohmann::json;

template <typename T>
class FileIO {
    private:
        const string filename = "db.json";
        
    public:
        void saveToFile(T entity);
        vector<T> readFromFile();
};

// Forward declarations of template specializations
template <>
void FileIO<Vehicle>::saveToFile(Vehicle entity);
template <>
vector<Vehicle> FileIO<Vehicle>::readFromFile();
template <>
void FileIO<Train>::saveToFile(Train entity);
template <>
vector<Train> FileIO<Train>::readFromFile(); 