#ifndef Robot_h
#define Robot_h

class Robot{
    private:
        /* data */
    public:
        int BLUETOOTH_PIN_RX;   int BLUETOOTH_PIN_TX;
        int GRIPPER_BASE_SERVO;   int GRIPPER_ELBOW_SERVO;   int GRIPPER_WRIST_SERVO;   int GRIPPER_FINGER_SERVO;
        int MOTOR_FL_PIN;   int MOTOR_FR_PIN;   int MOTOR_BL_PIN;   int MOTOR_BR_PIN;
        Robot(/* args */);
        ~Robot();
        
        bool attachBluetooth(
            int BLUETOOTH_PIN_RX, 
            int BLUETOOTH_PIN_TX
        );
        
        bool attachGripper(
            int GRIPPER_BASE_SERVO,
            int GRIPPER_ELBOW_SERVO,
            int GRIPPER_WRIST_SERVO,
            int GRIPPER_FINGER_SERVO
        );
        
        bool attachBase(
            String BASE_TYPE,
            int MOTOR_FL_PIN,   int MOTOR_FR_PIN,
            int MOTOR_BL_PIN,   int MOTOR_BR_PIN
        );
};
#endif
    