/*
 *MetroSim.h
 *Tom Zhou
 *9/30/24
 *MetroSim header
 */

#ifndef _METROSIM_H_
#define _METROSIM_H_

#include "Passenger.h"
#include "PassengerQueue.h"

#include <vector> 
#include <istream>
#include <iostream>



class MetroSim
{
    public:
    MetroSim(std::string filename); 
    
    void PLAY(std::string filename,std::istream& command); 

    void printInterface(); 
    void printError(std::string user); 

    void updateRound();
    void mm(std::ofstream &filename); 
    void dropoffPassenger(std::ofstream &filename); 
    void printTrain();

    void printOutFile(std::ofstream &filename); 
    
private:
    // Put any other structs you need here
    int StationSize; 
    int roundNum; 
    int PassengerIDCount; 
    std::vector<std::string> StationName; 
    std::vector<PassengerQueue> Train; 
    std::vector<PassengerQueue> Station; 
    PassengerQueue TrainPrint;
    void MakeStationAndTrain(std::string filename);
};

#endif
