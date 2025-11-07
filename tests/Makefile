CXX = g++
CXXFLAGS = -std=c++17 -Wall -I..

# Source files
TEST_SRC = test_booking.cpp
SERVICE_SRC = ../services/bookingService.cpp ../services/fileIO.cpp

# Object files
TEST_OBJ = test_booking.o
SERVICE_OBJ = bookingService.o fileIO.o

# Executable
TARGET = test_booking

all: $(TARGET)

$(TARGET): $(TEST_OBJ) $(SERVICE_OBJ)
	$(CXX) $(TEST_OBJ) $(SERVICE_OBJ) -o $(TARGET)

test_booking.o: test_booking.cpp
	$(CXX) $(CXXFLAGS) -c test_booking.cpp -o test_booking.o

bookingService.o: ../services/bookingService.cpp
	$(CXX) $(CXXFLAGS) -c ../services/bookingService.cpp -o bookingService.o

fileIO.o: ../services/fileIO.cpp
	$(CXX) $(CXXFLAGS) -c ../services/fileIO.cpp -o fileIO.o

clean:
	rm -f $(TEST_OBJ) $(SERVICE_OBJ) $(TARGET) db.json

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run
