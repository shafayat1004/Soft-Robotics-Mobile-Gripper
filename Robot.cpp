#include <Arduino.h>
#include "Robot.h"

Robot::Robot(){

}

Robot::Robot(int BLUETOOTH_PIN_RX, int BLUETOOTH_PIN_TX, int GRIPPER_BASE_SERVO, int GRIPPER_ELBOW_SERVO, int GRIPPER_WRIST_SERVO, int GRIPPER_FINGER_SERVO, int MOTOR_L_FORW_PIN, int MOTOR_L_BACK_PIN, int MOTOR_R_FORW_PIN, int MOTOR_R_BACK_PIN){

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

bool Robot::attachBase(int BASE_TYPE, int MOTOR_L_FORW_PIN, int MOTOR_L_BACK_PIN, int MOTOR_R_FORW_PIN, int MOTOR_R_BACK_PIN){
    switch (BASE_TYPE){
        case 2:
            pinMode (MOTOR_L_FORW_PIN, OUTPUT);
            pinMode (MOTOR_L_BACK_PIN, OUTPUT);
            pinMode (MOTOR_R_FORW_PIN, OUTPUT);
            pinMode (MOTOR_R_BACK_PIN, OUTPUT);
            return true;

        default:
            return false;
    }
}

void Robot::listen(){
    if (Serial.available() > 0) {
        _command = Serial.read();
        stop();
        switch (_command){
            case '0':
                setSpeed(20);
                break;
            case '1':
                setSpeed(40);
                break;
            case '2':
                setSpeed(60);
                break;
            case '3':
                setSpeed(80);
                break;
            case '4':
                setSpeed(100);
                break;
            case '5':
                setTurnRadius(0);
                break;
            case '6':
                setTurnRadius(1);
                break;
            case '7':
                setTurnRadius(2);
                break;
            case '8':
                setTurnRadius(3);
                break;
            case 'X':
                stop();
                break;
            case '^':
                moveForward(_speed);
                break;
            case 'V':
                moveBackward(_speed);
                break;
            case '>':
                turnRight(_speed);
                break;
            case '<':
                turnLeft(_speed);
                break;
            default:
                break;
        }
    }
    else stop();
}

void Robot::setSpeed(int speed = 50){
    _speed = speed;
}

void Robot::setTurnRadius(int turnRadius){
    _turnRadius = turnRadius;
}

void Robot::moveForward(int speed = 50){
    analogWrite(MOTOR_L_FORW_PIN, speed);
    analogWrite(MOTOR_R_FORW_PIN, speed);
}

void Robot::moveBackward(int speed = 50){
    analogWrite(MOTOR_L_BACK_PIN, speed);
    analogWrite(MOTOR_R_BACK_PIN, speed);    
}

void Robot::turnRight(int degree){
    switch (_turnRadius){
        case 0:
            analogWrite(MOTOR_L_FORW_PIN, _speed);
            analogWrite(MOTOR_R_BACK_PIN, _speed);  
            break;
        case 1:
            analogWrite(MOTOR_L_FORW_PIN, _speed);
            analogWrite(MOTOR_R_BACK_PIN, _speed/2);  
            break;
        case 2:
            analogWrite(MOTOR_L_FORW_PIN, _speed);
            break;
        case 3:
            analogWrite(MOTOR_L_FORW_PIN, _speed);
            analogWrite(MOTOR_R_FORW_PIN, _speed/2);  
            break;    
        default:
            break;
    }
}

void Robot::turnLeft(int degree){
    switch (_turnRadius){
        case 0:
            analogWrite(MOTOR_R_FORW_PIN, _speed);  
            analogWrite(MOTOR_L_BACK_PIN, _speed);
            break;
        case 1:
            analogWrite(MOTOR_R_FORW_PIN, _speed);
            analogWrite(MOTOR_L_BACK_PIN, _speed/2);  
            break;
        case 2:
            analogWrite(MOTOR_R_FORW_PIN, _speed);
            break;
        case 3:
            analogWrite(MOTOR_R_FORW_PIN, _speed);  
            analogWrite(MOTOR_L_FORW_PIN, _speed/2);
            break;
        default:
            break;
    }    
}

void Robot::gripperBaseRotate(int degree){
    
}

void Robot::gripperElbowRotate(int degree){
    
}

void Robot::gripperWristRotate(int degree){
    
}

void Robot::grip(int degree){
    
}

void Robot::stop(){

}
