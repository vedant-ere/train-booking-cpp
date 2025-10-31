CXX = g++
CXXFLAGS = -std=c++17 -Wall -I.
LDFLAGS = 

# Source files
SRCS = main.cpp \
       services/bookingService.cpp \
       services/fileIO.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Executable name
TARGET = booking_system

# Default target
all: $(TARGET)

# Linking
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET) $(LDFLAGS)

# Compilation
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean
clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean 