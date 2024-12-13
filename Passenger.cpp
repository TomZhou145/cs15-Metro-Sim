/*
*Passenger.cpp
*Tom Zhou
*9/30/24
*Passenger implementation
*/

#include "Passenger.h"

#include <iostream>
#include <string>
#include <sstream>

// Passenger::Passenger()
// {}
/*
 * name:      Passenger()
 * purpose:   This is the constructor for Passenger that initializes
 *            a Passenger object with an ID, starting station, and
 *            ending station.
 * arguments: An integer passenger ID, an integer starting station,
 *            and an integer ending station.
 * returns:   none
 * effects:   Constructs a Passenger with the provided information.
 * note:      Students do not have to modify this function.
 */
Passenger::Passenger(int id, int startingStation, int endingStation)
{
    this->id = id;
    this->startingStation = startingStation;
    this->endingStation = endingStation;
}

/*
 * name:      getId( )
 * purpose:   This is the getter (aka accessor) function that provides
 *            access to the Passenger's ID.
 * arguments: none
 * returns:   The Passenger's ID.
 * effects:   none
 * note:      Students do not have to modify this function.
 */
int Passenger::getId() { return id; }

/*
 * name:      getStartingStation( )
 * purpose:   This is the getter (aka accessor) function that provides
 *            access to the Passenger's starting station.
 * arguments: none
 * returns:   The Passenger's starting station.
 * effects:   none
 * note:      Students do not have to modify this function.
 */
int Passenger::getStartingStation() { return startingStation; }

/*
 * name:      getEndingStation( )
 * purpose:   This is the getter (aka accessor) function that provides
 *            access to the Passenger's ending station.
 * arguments: none
 * returns:   The Passenger's ending station.
 * effects:   none
 * note:      Students do not have to modify this function.
 */
int Passenger::getEndingStation() { return endingStation; }

/* print
 * purpose: to print one Passenger info
 * arguments the address of outstream file
 * returns nothihng
 * effect print one passenger info
 */
void Passenger::print(std::ostream &output)
{

    std::stringstream ss;

    ss << "[";
    ss << id << ", ";
    ss << startingStation;
    ss << "->" << endingStation << "]";

    output << ss.str();
}
