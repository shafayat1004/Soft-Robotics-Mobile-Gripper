#include "Robot.h"
#include "Base.h"
#include "Gripper.h"

Robot::Robot(){

}

Robot::Robot(int BLUETOOTH_PIN_RX, int BLUETOOTH_PIN_TX, int GRIPPER_BASE_SERVO, int GRIPPER_ELBOW_SERVO, int GRIPPER_WRIST_SERVO, int GRIPPER_FINGER_SERVO, int MOTOR_FL_PIN, int MOTOR_FR_PIN, int MOTOR_BL_PIN, int MOTOR_BR_PIN){

}

Robot::~Robot(){

}

bool Robot::attachBluetooth(int BLUETOOTH_PIN_RX, int BLUETOOTH_PIN_TX){
    pinMode (BLUETOOTH_PIN_RX, OUTPUT);
    pinMode (BLUETOOTH_PIN_TX, OUTPUT);
}

bool Robot::attachGripper(int GRIPPER_BASE_SERVO, int GRIPPER_ELBOW_SERVO, int GRIPPER_WRIST_SERVO, int GRIPPER_FINGER_SERVO){
    _gripperBaseServo.attach(GRIPPER_BASE_SERVO);
    _gripperElbowServo.attach(GRIPPER_ELBOW_SERVO);
    _gripperWristServo.attach(GRIPPER_WRIST_SERVO);
    _gripperFingerServo.attach(GRIPPER_FINGER_SERVO);
}

bool Robot::attachBase(int BASE_TYPE, int MOTOR_FL_PIN, int MOTOR_FR_PIN, int MOTOR_BL_PIN, int MOTOR_BR_PIN){
    switch (BASE_TYPE){
        case 4:
            pinMode (MOTOR_FL_PIN, OUTPUT);
            pinMode (MOTOR_FR_PIN, OUTPUT);
            pinMode (MOTOR_BL_PIN, OUTPUT);
            pinMode (MOTOR_BR_PIN, OUTPUT);
            break;
        
        default:
            break;
    }
}

void Robot::listen(){
    
}

void Robot::moveForward(int speed){
    
}

void Robot::moveBackward(int speed){
    
}

void Robot::turnRight(int degree){
    
}

void Robot::turnLeft(int degree){
    
}

void Robot::gripperBaseRotate(int degree){
    
}

void Robot::gripperElbowRotate(int degree){
    
}

void Robot::gripperWristRotate(int degree){
    
}

void Robot::grip(int degree){
    
}
