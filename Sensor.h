#ifndef SENSOR_H
#define SENSOR_H

class Sensor {
    public:
        Sensor();
        
        int Sensors();
        void Camera(int[9][9]); 

    private: 

    int numberGenerator(int);
};


#endif