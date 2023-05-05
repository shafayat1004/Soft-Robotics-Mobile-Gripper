#ifndef Robot_h
#define Robot_h

#include <Servo.h>

class Robot{
    private:
        Servo _gripperBaseServo;  Servo _gripperBase2Servo;  Servo _gripperShoulderServo;  Servo _gripperElbowServo;  Servo _gripperWristServo;  Servo _gripperFingerServo;   
        int _speed          = 50;
        int _turnRadius     = 0;
        int _actionDuration = 10;
        
    public:
        int BLUETOOTH_PIN_RX;     int BLUETOOTH_PIN_TX;
        int GRIPPER_BASE_SERVO;   int GRIPPER_BASE2_SERVO;   int GRIPPER_SHOULDER_SERVO;   int GRIPPER_ELBOW_SERVO;   int GRIPPER_WRIST_SERVO;   int GRIPPER_FINGER_SERVO;
        int MOTOR_L_FORW_PIN;     int MOTOR_L_BACK_PIN;      int MOTOR_R_FORW_PIN;      int MOTOR_R_BACK_PIN;

        Robot();

        Robot(
            int GRIPPER_BASE_SERVO,   int GRIPPER_BASE2_SERVO,   int GRIPPER_SHOULDER_SERVO, int GRIPPER_ELBOW_SERVO,   int GRIPPER_WRIST_SERVO,   int GRIPPER_FINGER_SERVO,
            int MOTOR_L_FORW_PIN,     int MOTOR_L_BACK_PIN,      int MOTOR_R_FORW_PIN,       int MOTOR_R_BACK_PIN
        );

        ~Robot();
        
        bool attachGripper(
            int GRIPPER_BASE_SERVO,
            int GRIPPER_BASE2_SERVO,
            int GRIPPER_SHOULDER_SERVO,
            int GRIPPER_ELBOW_SERVO,
            int GRIPPER_WRIST_SERVO,
            int GRIPPER_FINGER_SERVO
        );
        
        bool attachBase(
            int BASE_TYPE,
            int MOTOR_L_FORW_PIN,   int MOTOR_L_BACK_PIN,
            int MOTOR_R_FORW_PIN,   int MOTOR_R_BACK_PIN
        );

        void listenForCommands(int command);
        void setSpeed(int speed = 50);
        void setTurnRadius(int turnRadius);
        void moveForward(int speed = 50);
        void moveBackward(int speed = 50);
        void turnRight(int degree);
        void turnLeft(int degree);
        void gripperBaseRotate(int degree);
        void gripperBase2Rotate(int degree);
        void gripperShoulderRotate(int degree);
        void gripperElbowRotate(int degree);
        void gripperWristRotate(int degree);
        void grip(int degree);
        void stop();
        void testAllSystems(HardwareSerial &serial = Serial);
};
#endif
    