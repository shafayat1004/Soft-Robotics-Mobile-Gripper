#ifndef Robot_h
#define Robot_h

#include <Servo.h>

class Robot{
    private:
        Servo _gripperBaseServo;  Servo _gripperElbowServo;  Servo _gripperWristServo;  Servo _gripperFingerServo;
        char _command;              
        int _speed = 50;
        int _turnRadius = 0;
        
    public:
        int BLUETOOTH_PIN_RX;     int BLUETOOTH_PIN_TX;
        int GRIPPER_BASE_SERVO;   int GRIPPER_ELBOW_SERVO;   int GRIPPER_WRIST_SERVO;   int GRIPPER_FINGER_SERVO;
        int MOTOR_L_FORW_PIN;     int MOTOR_L_BACK_PIN;      int MOTOR_R_FORW_PIN;      int MOTOR_R_BACK_PIN;
        
        Robot();

        Robot(
            int BLUETOOTH_PIN_RX,     int BLUETOOTH_PIN_TX,
            int GRIPPER_BASE_SERVO,   int GRIPPER_ELBOW_SERVO,   int GRIPPER_WRIST_SERVO,   int GRIPPER_FINGER_SERVO,
            int MOTOR_L_FORW_PIN,     int MOTOR_L_BACK_PIN,      int MOTOR_R_FORW_PIN,      int MOTOR_R_BACK_PIN
        );

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
            int BASE_TYPE,
            int MOTOR_L_FORW_PIN,   int MOTOR_L_BACK_PIN,
            int MOTOR_R_FORW_PIN,   int MOTOR_R_BACK_PIN
        );

        void listen();
        void setSpeed(int speed = 50);
        void setTurnRadius(int turnRadius);
        void moveForward(int speed = 50);
        void moveBackward(int speed = 50);
        void turnRight(int degree);
        void turnLeft(int degree);
        void gripperBaseRotate(int degree);
        void gripperElbowRotate(int degree);
        void gripperWristRotate(int degree);
        void grip(int degree);
        void stop();
};
#endif
    