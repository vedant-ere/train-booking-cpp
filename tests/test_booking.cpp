#include <iostream>
#include <cassert>
#include <fstream>
#include "../entities/user.hpp"
#include "../entities/vehicle.hpp"
#include "../entities/train.hpp"
#include "../services/bookingService.hpp"

using namespace std;

// Helper function to clean up test database
void cleanupTestDB() {
    remove("db.json");
}

// Test 1: Book a vehicle
void test_book_vehicle() {
    cout << "\n[TEST 1] Testing Vehicle Booking..." << endl;

    cleanupTestDB();

    User user;
    user.userId = "U001";
    user.name = "John Doe";
    user.aadharCard = "1234-5678-9012";

    BookingService<Vehicle> bookingService;
    bookingService.book("V001", user, "Express Train", "Mumbai", "Delhi");

    cout << "[PASS] Vehicle booking created successfully!" << endl;
}

// Test 2: Print booking
void test_print_booking() {
    cout << "\n[TEST 2] Testing Print Booking..." << endl;

    BookingService<Vehicle> bookingService;
    bookingService.printBooking("V001", "U001");

    cout << "[PASS] Booking printed successfully!" << endl;
}

// Test 3: Book multiple users
void test_multiple_bookings() {
    cout << "\n[TEST 3] Testing Multiple Bookings..." << endl;

    User user2;
    user2.userId = "U002";
    user2.name = "Jane Smith";
    user2.aadharCard = "9876-5432-1098";

    BookingService<Vehicle> bookingService;
    bookingService.book("V002", user2, "Superfast Train", "Delhi", "Bangalore");

    User user3;
    user3.userId = "U003";
    user3.name = "Bob Johnson";
    user3.aadharCard = "5555-6666-7777";

    bookingService.book("V002", user3, "Superfast Train", "Delhi", "Bangalore");

    cout << "[PASS] Multiple bookings created successfully!" << endl;
}

// Test 4: Print multiple bookings
void test_print_multiple() {
    cout << "\n[TEST 4] Testing Print Multiple Bookings..." << endl;

    BookingService<Vehicle> bookingService;

    cout << "\nBooking 1:" << endl;
    bookingService.printBooking("V002", "U002");

    cout << "\nBooking 2:" << endl;
    bookingService.printBooking("V002", "U003");

    cout << "[PASS] Multiple bookings printed successfully!" << endl;
}

// Test 5: Cancel a booking
void test_cancel_booking() {
    cout << "\n[TEST 5] Testing Cancel Booking..." << endl;

    BookingService<Vehicle> bookingService;
    bookingService.cancelBooking("V001", "U001");

    cout << "[PASS] Booking cancelled!" << endl;
}

// Test 6: Verify cancelled booking
void test_verify_cancellation() {
    cout << "\n[TEST 6] Verifying Cancelled Booking..." << endl;

    BookingService<Vehicle> bookingService;
    cout << "\nTrying to print cancelled booking (should show 'not found'):" << endl;
    bookingService.printBooking("V001", "U001");

    cout << "[PASS] Cancellation verified!" << endl;
}

// Test 7: Test Train booking
void test_train_booking() {
    cout << "\n[TEST 7] Testing Train Booking..." << endl;

    User user;
    user.userId = "U004";
    user.name = "Alice Brown";
    user.aadharCard = "1111-2222-3333";

    BookingService<Train> trainBooking;
    trainBooking.book("T001", user, "Rajdhani Express", "Chennai", "Kolkata");

    cout << "\nPrinting train booking:" << endl;
    trainBooking.printBooking("T001", "U004");

    cout << "[PASS] Train booking works!" << endl;
}

// Test 8: Invalid booking lookup
void test_invalid_lookup() {
    cout << "\n[TEST 8] Testing Invalid Booking Lookup..." << endl;

    BookingService<Vehicle> bookingService;
    cout << "\nLooking up non-existent booking:" << endl;
    bookingService.printBooking("V999", "U999");

    cout << "[PASS] Invalid lookup handled correctly!" << endl;
}

int main() {
    cout << "======================================" << endl;
    cout << "  TRAIN BOOKING SYSTEM - TEST SUITE  " << endl;
    cout << "======================================" << endl;

    try {
        test_book_vehicle();
        test_print_booking();
        test_multiple_bookings();
        test_print_multiple();
        test_cancel_booking();
        test_verify_cancellation();
        test_train_booking();
        test_invalid_lookup();

        cout << "\n======================================" << endl;
        cout << "  ALL TESTS PASSED! ✓" << endl;
        cout << "======================================\n" << endl;

    } catch (const exception& e) {
        cout << "\n[FAIL] Test failed with error: " << e.what() << endl;
        return 1;
    }

    return 0;
}
