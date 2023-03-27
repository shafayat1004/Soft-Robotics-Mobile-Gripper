#include "Robot.h"
#include <Base.h>
#include<Gripper.h>

Robot::Robot(){

}

Robot::~Robot(){
    
}

bool Robot::attachBluetooth(int BLUETOOTH_PIN_RX, int BLUETOOTH_PIN_TX){
    return false;
}

bool Robot::attachGripper(int GRIPPER_BASE_SERVO, int GRIPPER_ELBOW_SERVO, int GRIPPER_WRIST_SERVO, int GRIPPER_FINGER_SERVO){
    return false;
}

bool Robot::attachBase(String BASE_TYPE, int MOTOR_FL_PIN, int MOTOR_FR_PIN, int MOTOR_BL_PIN, int MOTOR_BR_PIN){
    return false;
}
