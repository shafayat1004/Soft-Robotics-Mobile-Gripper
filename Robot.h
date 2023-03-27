#ifndef Robot_h
#define Robot_h

#include <Servo.h>

class Robot{
    private:
        Servo _gripperBaseServo;  Servo _gripperElbowServo;  Servo _gripperWristServo;  Servo _gripperFingerServo;
        
    public:
        int BLUETOOTH_PIN_RX;     int BLUETOOTH_PIN_TX;
        int GRIPPER_BASE_SERVO;   int GRIPPER_ELBOW_SERVO;   int GRIPPER_WRIST_SERVO;   int GRIPPER_FINGER_SERVO;
        int MOTOR_FL_PIN;         int MOTOR_FR_PIN;          int MOTOR_BL_PIN;          int MOTOR_BR_PIN;
        
        Robot();

        Robot(
            int BLUETOOTH_PIN_RX,     int BLUETOOTH_PIN_TX,
            int GRIPPER_BASE_SERVO,   int GRIPPER_ELBOW_SERVO,   int GRIPPER_WRIST_SERVO,   int GRIPPER_FINGER_SERVO,
            int MOTOR_FL_PIN,         int MOTOR_FR_PIN,          int MOTOR_BL_PIN,          int MOTOR_BR_PIN
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
            int MOTOR_FL_PIN,   int MOTOR_FR_PIN,
            int MOTOR_BL_PIN,   int MOTOR_BR_PIN
        );

        void listen();
        void moveForward(int speed);
        void moveBackward(int speed);
        void turnRight(int degree);
        void turnLeft(int degree);
        void gripperBaseRotate(int degree);
        void gripperElbowRotate(int degree);
        void gripperWristRotate(int degree);
        void grip(int degree);
};
#endif
    