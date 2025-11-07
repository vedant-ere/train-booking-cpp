# How to Run Tests - Simple Guide

This folder contains tests for the Train Booking System. Don't worry, it's easy to run!

## What You Need

- A C++ compiler (g++)
- Linux, Mac, or Windows with WSL
- That's it!

## Running the Tests (3 Easy Steps)

### Step 1: Open Terminal

Open your terminal and go to the `tests` folder:

```bash
cd tests
```

### Step 2: Build the Tests

Just type this command:

```bash
make
```

You should see some messages about compiling. If there are no errors, you're good!

### Step 3: Run the Tests

Now run the tests:

```bash
make run
```

OR you can just run:

```bash
./test_booking
```

## What the Tests Do

The tests will check if everything works correctly. Here's what gets tested:

1. **Book a Train** - Can we book a train ticket?
2. **View Booking** - Can we see our booking details?
3. **Multiple Bookings** - Can multiple people book the same train?
4. **Cancel Booking** - Can we cancel a ticket?
5. **Verify Cancel** - Is the ticket really cancelled?
6. **Train vs Vehicle** - Do both types work?
7. **Invalid Lookup** - What happens when we search for something that doesn't exist?

## What Success Looks Like

If everything works, you'll see:

```
  ALL TESTS PASSED! 
```

## If Something Goes Wrong

### Problem: "make: command not found"

**Solution:** You need to install build tools.

- **Ubuntu/Debian:** `sudo apt-get install build-essential`
- **Mac:** Install Xcode Command Line Tools: `xcode-select --install`

### Problem: Compilation errors

**Solution:** Make sure you're in the `tests` folder and all source files exist:

```bash
cd tests
ls  # You should see test_booking.cpp, Makefile, and this README.md
```

### Problem: "No such file or directory"

**Solution:** Go back to the project root and try again:

```bash
cd ..
cd tests
make clean
make
make run
```

## Cleaning Up

To remove compiled files and test database:

```bash
make clean
```

This deletes:
- All `.o` files (compiled object files)
- The `test_booking` executable
- The test `db.json` database file

## Understanding the Output

Each test will print:

- `[TEST X]` - Which test is running
- Details about what's being tested
- `[PASS]` - The test passed!

If a test fails, you'll see `[FAIL]` with an error message.

## Tips

- Run tests after making changes to the code
- Tests create a temporary database (`db.json`) that gets cleaned up
- Each test builds on the previous one, so they run in order
- Tests are automatic - just watch the output!

## What's Being Tested?

The tests check these functions:

1. `book()` - Creating new bookings
2. `printBooking()` - Displaying booking details
3. `cancelBooking()` - Removing bookings

Both `Vehicle` and `Train` types are tested to make sure the template system works correctly.

## Need More Help?

Check the main project README.md in the parent folder for more information about the booking system.

Happy Testing! 
