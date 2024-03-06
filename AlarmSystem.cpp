#include <iostream>
#include <chrono> //? Måske kan vivado ikke håndtere dette. 

#include <string> 
#include "AlarmSystem.h"
#include "RandomGenerator.h"
#include "Sensor.h"
#include "CalculationData.cpp"

AlarmSystem::AlarmSystem() : state(inactive) {}

//! Controlling the whole system
void AlarmSystem::systemController() {
    bool continueRunning = true;
    int alarmedCounter = 0;
    int total = 0; 

    Sensor sensor;

    int counter = 0;
    int s_data = 0; 
    int matrix[9][9] = {0};

    // Controller 

    /* Deactivate alarm - not a requirement. */
    while(continueRunning == true) {
        if(alarmedCounter == 3) {
            if(!askforDeactivate()) {
                deactivate();
                alarmedCounter = 0;
                continueRunning = false;
            } else {
            state = active;
            }
            alarmedCounter = 0; // Reset counter.
        }
        
        /* Activate Alarm*/
        if(state == inactive) {
            activate();
        }

        /* Active State controls*/
        while(state == active) {
            sensor.Camera(matrix);

            if(counter == 2){
                /*
                for(int i = 0; i < 9; ++i) {
                    for(int j = 0; j < 9; ++j) {
                        std::cout << matrix[i][j] << " ";
                    }
                    std::cout << std::endl;
                    }

                std::cout << s_data << std::endl; */ //! Prints af sensordata
                
                int totalSum = calculationData(s_data, matrix);
                
                if(totalSum >= 6290) {
                    std::cout << "Intrusion detected with total value: " << totalSum << std::endl;
                    triggerAlarm();
                    break;
                } else {
                    std::cout << "No intrusion. Total value: " << totalSum << std::endl;
                }

                s_data = 0;
                counter = 0;
            } else {
                s_data = s_data + sensor.Sensors(); 
                counter++;
            }
        }
        
        /* If alarmed */
        if(state == alarmed) {
            std::cout << "Theif captured. System will be reset." << std::endl;

            s_data = 0;
            int matrix[9][9] = {0};

            deactivate();
            total++;
            /* For deactivating.*/
            alarmedCounter++;
        }
    }

    std::cout << "End of program." << std::endl;
    std::cout << "Total alarms: " << total << std::endl;
}

//! Claculation for intrusion
/*
int AlarmSystem::calculationData(int s, int matrix[9][9]) {
    int sum = 0;

    for(int i = 0; i < 9; ++i) {
        for(int j = 0; j < 9; ++j) {
            int Im = (s + .84) * matrix[i][j]; // Beregner I_m(i, j) for det aktuelle element
            sum += Im; // Tilføjer I_m(i, j) til den samlede sum
        }
    }

    return sum;
}*/

//! Used for activating the system
void AlarmSystem::activate() {
    int counter = 0;

    while(state == inactive) {
        int randomPin = Valid(PinGenerator());
        
        // Activating system
        if(Valid(randomPin) == true) {
            state = active;
            std::cout << "Pincode correct, activating system..." << std::endl;
            std::cout << "Numer of tries: " << counter << "." << std::endl;
            counter = 0;
        } else {
            std::cout << "Pincode incorrect." << std::endl;
            counter++;
        }
    }
}

//! Function for checking if pin is valid
bool AlarmSystem::Valid(int P) {
    if(P % 2 == 0) {
        return true;
    } else {
    return false;
    }
}

//! Function using RandomGenerator.h to generate at random number between 0 and 10. 
int AlarmSystem::PinGenerator() {    
    // Generate a random pin between 0 and 10
    RandomInt pinCode;
    int P = pinCode.next() % 6; 

    return P;
}

//! Change state to alarmed
void AlarmSystem::triggerAlarm() {
    state = alarmed;
}

//! Deactivate
void AlarmSystem::deactivate() {
    state = inactive;


}

//! Ekstra functions for flow
bool AlarmSystem::askforDeactivate() {
    std::string response; 

    std::cout << "The alarm has been set off 3 times, do you wish to deactivate the alarm?" << std::endl;
    std::cout << "Answer: 'Yes' if you want to stop, and 'No', if you wish to continue." << std::endl;

    /*std::getline(std::cin, response);

    if(response == "Yes") {
        std::cout << "Deactivating system operation." << std::endl;
        return false;
    } else if(response == "No") {
        std::cout << "Continue system operation." << std::endl; 
        return true;
    }   else{
        std::cout << "No valid answer. Continue system operation." << std::endl;
        return true;
    }*/

    // Simulated true input to keep running
    return true;
}