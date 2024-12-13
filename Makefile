#########################################################
#             PROJECT 1: MetroSim Makefile             #
#########################################################

CXX      = clang++
CXXFLAGS = -g3 -Wall -Wextra -Wpedantic -Wshadow
LDFLAGS  = -g3 

# ***TODO***
# Metrosim rule - you need to fill in the linking command,
# add any new dependencies, and add target rules for 
# Passenger.o, MetroSim.o, main.o, and any new dependencies.
# Please use the rules provided below for PassengerQueue.o as an example for
# what to do.
# If you add other classes, you'll have to add their .o files as dependencies 
# here.
# Don't forget:  the clang++ command must be indented with a TAB character
# and be all on one line.
MetroSim: main.o MetroSim.o PassengerQueue.o Passenger.o
	$(CXX) ${LDFLAGS} -o $@ $^

# ***TODO***
# Write rules for any other .o files.
# You can base them on the PassengerQueue.o rule.
# Every .cpp file that is part of your program should have a .o rule.

# This rule builds PassengerQueue.o



Passenger.o: Passenger.cpp Passenger.h
	$(CXX) $(CXXFLAGS) -c Passenger.cpp

PassengerQueue.o: PassengerQueue.cpp PassengerQueue.h Passenger.h 
	$(CXX) $(CXXFLAGS) -c PassengerQueue.cpp

MetroSim.o: MetroSim.cpp MetroSim.h PassengerQueue.h  Passenger.h 
	$(CXX) $(CXXFLAGS) -c MetroSim.cpp 

main.o: main.cpp MetroSim.cpp PassengerQueue.h Passenger.h
	$(CXX) ${CXXFLAGS} -c main.cpp MetroSim.cpp 


# ***TODO***
# The below rule will be used by unit_test.
# Please add any other .o files that are needed by PassengerQueue,
# and any other .o files you wish to test. 
unit_test: unit_test_driver.o Passenger.o PassengerQueue.o MetroSim.o 
	$(CXX) $(CXXFLAGS) $^ 

# unit_test_driver.o: unit_test_driver.cpp PassengerQueue.h Passenger.h
# 	$(CXX) $(CXXFLAGS) -c unit_test_driver.cpp


# remove executables, object code, and temporary files from the current folder 
# -- the executable created by unit_test is called a.out
clean: 
	@rm -r *~ *# *.o a.out core* vgcore* MetroSim







