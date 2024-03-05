#include <iostream>
#include "AlarmSystem.h"    
    using namespace std;

int main() {
    cout << "Test 1" << endl;
    
    // Opretter instans
    AlarmSystem myAlarm; 

    // Run it 
    myAlarm.systemController();
    
    return 0;
}