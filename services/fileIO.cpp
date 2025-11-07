// This file can be deleted as all implementations are now in the header file

#include "fileIO.hpp"

// Template implementation for Vehicle
template <>
void FileIO<Vehicle>::saveToFile(Vehicle entity) {
    json j;
    ifstream file(filename);
    
    if (file.is_open()) {
        file >> j;
        file.close();
    }
    
    // Convert seats to a serializable format
    json seatsJson = json::array();
    for (const auto& row : entity.seats) {
        json rowJson = json::array();
        for (const auto& user : row) {
            json userJson = {
                {"userId", user.userId},
                {"name", user.name},
                {"aadharCard", user.aadharCard}
            };
            rowJson.push_back(userJson);
        }
        seatsJson.push_back(rowJson);
    }
    
    json entityJson = {
        {"vehicleId", entity.vehicleId},
        {"name", entity.name},
        {"source", entity.source},
        {"destination", entity.destination},
        {"time", entity.time},
        {"seats", seatsJson}
    };
    
    j.push_back(entityJson);
    
    ofstream outFile(filename);
    outFile << j.dump(4);
    outFile.close();
}

template <>
vector<Vehicle> FileIO<Vehicle>::readFromFile() {
    vector<Vehicle> entities;
    ifstream file(filename);

    if (!file.is_open()) {
        return entities;
    }

    json j;
    file >> j;
    file.close();

    for (const auto& item : j) {
        // Only read Vehicle objects (skip Train objects)
        if (!item.contains("vehicleId")) {
            continue;
        }

        Vehicle entity;
        entity.vehicleId = item["vehicleId"];
        entity.name = item["name"];
        entity.source = item["source"];
        entity.destination = item["destination"];
        entity.time = item["time"];

        // Convert seats back from JSON
        entity.seats.clear();
        for (const auto& rowJson : item["seats"]) {
            vector<User> row;
            for (const auto& userJson : rowJson) {
                User user;
                user.userId = userJson["userId"];
                user.name = userJson["name"];
                user.aadharCard = userJson["aadharCard"];
                row.push_back(user);
            }
            entity.seats.push_back(row);
        }

        entities.push_back(entity);
    }

    return entities;
}

// Template implementation for Train
template <>
void FileIO<Train>::saveToFile(Train entity) {
    json j;
    ifstream file(filename);
    
    if (file.is_open()) {
        file >> j;
        file.close();
    }
    
    // Convert seats to a serializable format
    json seatsJson = json::array();
    for (const auto& row : entity.seats) {
        json rowJson = json::array();
        for (const auto& user : row) {
            json userJson = {
                {"userId", user.userId},
                {"name", user.name},
                {"aadharCard", user.aadharCard}
            };
            rowJson.push_back(userJson);
        }
        seatsJson.push_back(rowJson);
    }
    
    json entityJson = {
        {"trainId", entity.trainId},
        {"name", entity.name},
        {"source", entity.source},
        {"destination", entity.destination},
        {"time", entity.time},
        {"seats", seatsJson}
    };
    
    j.push_back(entityJson);
    
    ofstream outFile(filename);
    outFile << j.dump(4);
    outFile.close();
}

template <>
vector<Train> FileIO<Train>::readFromFile() {
    vector<Train> entities;
    ifstream file(filename);

    if (!file.is_open()) {
        return entities;
    }

    json j;
    file >> j;
    file.close();

    for (const auto& item : j) {
        // Only read Train objects (skip Vehicle objects)
        if (!item.contains("trainId")) {
            continue;
        }

        Train entity;
        entity.trainId = item["trainId"];
        entity.name = item["name"];
        entity.source = item["source"];
        entity.destination = item["destination"];
        entity.time = item["time"];

        // Convert seats back from JSON
        entity.seats.clear();
        for (const auto& rowJson : item["seats"]) {
            vector<User> row;
            for (const auto& userJson : rowJson) {
                User user;
                user.userId = userJson["userId"];
                user.name = userJson["name"];
                user.aadharCard = userJson["aadharCard"];
                row.push_back(user);
            }
            entity.seats.push_back(row);
        }

        entities.push_back(entity);
    }

    return entities;
}

// Template implementation for Vehicle - updateFile
template <>
void FileIO<Vehicle>::updateFile(vector<Vehicle> entities) {
    json j = json::array();

    for (const auto& entity : entities) {
        // Convert seats to a serializable format
        json seatsJson = json::array();
        for (const auto& row : entity.seats) {
            json rowJson = json::array();
            for (const auto& user : row) {
                json userJson = {
                    {"userId", user.userId},
                    {"name", user.name},
                    {"aadharCard", user.aadharCard}
                };
                rowJson.push_back(userJson);
            }
            seatsJson.push_back(rowJson);
        }

        json entityJson = {
            {"vehicleId", entity.vehicleId},
            {"name", entity.name},
            {"source", entity.source},
            {"destination", entity.destination},
            {"time", entity.time},
            {"seats", seatsJson}
        };

        j.push_back(entityJson);
    }

    ofstream outFile(filename);
    outFile << j.dump(4);
    outFile.close();
}

// Template implementation for Train - updateFile
template <>
void FileIO<Train>::updateFile(vector<Train> entities) {
    json j = json::array();

    for (const auto& entity : entities) {
        // Convert seats to a serializable format
        json seatsJson = json::array();
        for (const auto& row : entity.seats) {
            json rowJson = json::array();
            for (const auto& user : row) {
                json userJson = {
                    {"userId", user.userId},
                    {"name", user.name},
                    {"aadharCard", user.aadharCard}
                };
                rowJson.push_back(userJson);
            }
            seatsJson.push_back(rowJson);
        }

        json entityJson = {
            {"trainId", entity.trainId},
            {"name", entity.name},
            {"source", entity.source},
            {"destination", entity.destination},
            {"time", entity.time},
            {"seats", seatsJson}
        };

        j.push_back(entityJson);
    }

    ofstream outFile(filename);
    outFile << j.dump(4);
    outFile.close();
}

// Explicit template instantiations
template class FileIO<Vehicle>;
template class FileIO<Train>;