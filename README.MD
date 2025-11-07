# Train Booking System

## Description
A C++ based train booking system that implements object-oriented programming concepts and file I/O operations for persistent data storage. The system manages train schedules, passenger bookings, and seat reservations using modern C++17 features and template-based generic programming.

## Features
- **Book Tickets**: Create bookings for trains and vehicles
- **View Bookings**: Display detailed booking information
- **Cancel Bookings**: Remove bookings and free up seats
- **Generic Templates**: Works with both Train and Vehicle types
- **Persistent Storage**: JSON-based file storage for all bookings
- **Multiple Passengers**: Support for multiple passengers per booking

## Quick Start

### Prerequisites
- C++ compiler with C++17 support (g++)
- Make build system
- Linux, Mac, or Windows with WSL

### Build the Project

```bash
make
```

### Run the Application

```bash
./booking_system
```

### Run Tests

```bash
cd tests
make run
```

See `tests/README.md` for detailed testing instructions.

## Project Structure

```
train-booking-cpp/
├── entities/              # Data models
│   ├── user.hpp          # User/Passenger struct
│   ├── train.hpp         # Train struct
│   └── vehicle.hpp       # Vehicle struct
├── services/             # Business logic
│   ├── bookingService.hpp # Booking service (header)
│   ├── bookingService.cpp # Booking service (implementation)
│   ├── fileIO.hpp        # File I/O service (header)
│   └── fileIO.cpp        # File I/O service (implementation)
├── external/             # Third-party libraries
│   └── json.hpp          # nlohmann/json library
├── tests/                # Test suite
│   ├── test_booking.cpp  # Test file
│   ├── Makefile          # Test build configuration
│   └── README.md         # Testing guide
├── main.cpp              # Application entry point
├── Makefile              # Build configuration
└── README.MD             # This file
```

## Technical Implementation

### Core C++ Concepts Used
- **Templates & Generics**: Template specialization for Vehicle and Train types
- **File I/O**: Reading and writing booking data to JSON files
- **Standard Template Library (STL)**: Vectors for dynamic arrays, time_t for timestamps
- **Structs**: Lightweight data structures for entities
- **External Libraries**: nlohmann/json for JSON serialization/deserialization
- **Modern C++17**: Standard compliance for robust code

### Key Components

#### 1. Entity Classes (Structs)

**User** (`entities/user.hpp`)
```cpp
struct User {
    string userId;
    string name;
    string aadharCard;
    vector<Vehicle*> vehicles;
};
```

**Train** (`entities/train.hpp`)
```cpp
struct Train {
    string trainId;
    string name;
    string source;
    string destination;
    time_t time;
    vector<vector<User>> seats;  // 2D seat matrix
};
```

**Vehicle** (`entities/vehicle.hpp`)
```cpp
struct Vehicle {
    string vehicleId;
    string name;
    string source;
    string destination;
    time_t time;
    vector<vector<User>> seats;  // 2D seat matrix
};
```

#### 2. BookingService (Template Class)

**Location**: `services/bookingService.hpp` and `services/bookingService.cpp`

**Public Methods**:
- `book(string entityId, User user, string name, string source, string destination)` - Creates a new booking
- `cancelBooking(string entityId, string userId)` - Cancels an existing booking
- `printBooking(string entityId, string userId)` - Displays booking details

**Template Specializations**:
- `BookingService<Vehicle>` - For vehicle bookings
- `BookingService<Train>` - For train bookings

**Example Usage**:
```cpp
// Create user
User user;
user.userId = "U001";
user.name = "John Doe";
user.aadharCard = "1234-5678-9012";

// Book a vehicle
BookingService<Vehicle> bookingService;
bookingService.book("V001", user, "Express Train", "Mumbai", "Delhi");

// Print booking
bookingService.printBooking("V001", "U001");

// Cancel booking
bookingService.cancelBooking("V001", "U001");
```

#### 3. FileIO (Template Class)

**Location**: `services/fileIO.hpp` and `services/fileIO.cpp`

**Public Methods**:
- `saveToFile(T entity)` - Appends an entity to the JSON file
- `readFromFile()` - Reads all entities of type T from the JSON file
- `updateFile(vector<T> entities)` - Overwrites the JSON file with provided entities

**Features**:
- Automatic JSON serialization/deserialization
- Separate handling for Vehicle and Train types
- Persistent storage in `db.json`

## API Reference

### BookingService Methods

#### `book()`
Creates a new booking and saves it to the database.

**Parameters**:
- `entityId` - Unique identifier for the vehicle/train
- `user` - User object with passenger details
- `name` - Name of the vehicle/train
- `source` - Starting station
- `destination` - Ending station

**Returns**: void

---

#### `cancelBooking()`
Cancels a booking by removing the user from the seat allocation.

**Parameters**:
- `entityId` - ID of the vehicle/train
- `userId` - ID of the user to remove

**Returns**: void

**Output**: Prints confirmation message or error if booking not found

---

#### `printBooking()`
Displays detailed information about a booking.

**Parameters**:
- `entityId` - ID of the vehicle/train
- `userId` - ID of the user

**Returns**: void

**Output**: Formatted booking details including route, time, and passenger info

## Database Schema

Bookings are stored in `db.json` as a JSON array. Each booking contains:

**Vehicle Booking**:
```json
{
    "vehicleId": "V001",
    "name": "Express Train",
    "source": "Mumbai",
    "destination": "Delhi",
    "time": 1699363200,
    "seats": [
        [
            {
                "userId": "U001",
                "name": "John Doe",
                "aadharCard": "1234-5678-9012"
            }
        ]
    ]
}
```

**Train Booking**:
```json
{
    "trainId": "T001",
    "name": "Rajdhani Express",
    "source": "Chennai",
    "destination": "Kolkata",
    "time": 1699363200,
    "seats": [
        [
            {
                "userId": "U002",
                "name": "Jane Smith",
                "aadharCard": "9876-5432-1098"
            }
        ]
    ]
}
```

## Building and Compilation

### Main Application

```bash
# Clean previous builds
make clean

# Build the project
make

# Run the application
./booking_system
```

### Tests

```bash
# Navigate to tests directory
cd tests

# Build and run tests
make run

# Or build separately
make
./test_booking

# Clean test artifacts
make clean
```

## Usage Example

### Interactive Console Usage

```
Enter User ID: U001
Enter Name: John Doe
Enter Aadhar Card Number: 123456789012
Enter the option:
Enter 1 to book the train
1
Enter Train ID: T001
Enter Train Name: Rajdhani Express
Enter Source Station: Mumbai
Enter Destination Station: Delhi
Train booked successfully!
```

## Testing

The project includes a comprehensive test suite that validates all booking operations.

**Tests Include**:
1. Vehicle booking creation
2. Booking retrieval and display
3. Multiple concurrent bookings
4. Booking cancellation
5. Cancellation verification
6. Train booking (template verification)
7. Invalid booking lookups

**Run Tests**:
```bash
cd tests
make run
```

For detailed testing instructions, see `tests/README.md`.

## Error Handling

The system handles various error conditions:
- **File Not Found**: Returns empty list when `db.json` doesn't exist
- **Invalid Entity**: Skips incompatible records (e.g., Vehicle records when reading Trains)
- **Booking Not Found**: Displays appropriate error message
- **User Not Found**: Notifies when attempting to cancel non-existent booking

## Future Enhancements

Potential improvements for the system:
- User authentication and login system
- Seat selection interface (row/column selection)
- Search functionality for available trains
- Date/time based booking validation
- Booking history per user
- Multiple seat booking in single transaction
- Payment integration
- Email/SMS notifications
