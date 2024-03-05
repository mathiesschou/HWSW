#ifndef ALARMSYSTEM_H
#define ALARMSYSTEM_H

class AlarmSystem {
    public:
        AlarmSystem();
        void systemController();

        // Funcftions for system controller:
        void deactivate();
        void activate();
        void triggerAlarm();
        bool Valid(int); 
        int calculationData(int, int[9][9]);

        // Ekstra functions for flow:
        bool askforDeactivate();

    private:
        enum States { inactive, active, alarmed } state;

        int PinGenerator();
};

#endif  