/*
*Passenger.h
*Tom Zhou
*9/30/24
*Passenger header
*/

#ifndef __PASSENGER_H__
#define __PASSENGER_H__

#include <iostream>
#include <string>

class Passenger {
   public:
    Passenger(int id, int startingStation, int endingStatgetion);
    int getId();
    int getStartingStation();
    int getEndingStation();
    void print(std::ostream &output);

   private:
    int id;
    int startingStation;
    int endingStation;
};

#endif

