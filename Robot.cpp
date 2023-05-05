#include <Arduino.h>
#include "Robot.h"

Robot::Robot(){

}

Robot::Robot(int GRIPPER_BASE_SERVO, int GRIPPER_BASE2_SERVO, int GRIPPER_SHOULDER_SERVO, int GRIPPER_ELBOW_SERVO, int GRIPPER_WRIST_SERVO, int GRIPPER_FINGER_SERVO, int MOTOR_L_FORW_PIN, int MOTOR_L_BACK_PIN, int MOTOR_R_FORW_PIN, int MOTOR_R_BACK_PIN){

}

Robot::~Robot(){

}

bool Robot::attachGripper(int GRIPPER_BASE_SERVO, int GRIPPER_BASE2_SERVO, int GRIPPER_SHOULDLER_SERVO, int GRIPPER_ELBOW_SERVO, int GRIPPER_WRIST_SERVO, int GRIPPER_FINGER_SERVO){
    _gripperBaseServo.attach(GRIPPER_BASE_SERVO);
    _gripperBase2Servo.attach(GRIPPER_BASE2_SERVO);
    _gripperShoulderServo.attach(GRIPPER_SHOULDLER_SERVO);
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

int mapToServoDegree(int input, int min, int max){
    return map(input, min, max, 0, 180);
}

void Robot::stop(){
    analogWrite(MOTOR_R_FORW_PIN, 0);
    analogWrite(MOTOR_L_FORW_PIN, 0);
    analogWrite(MOTOR_R_BACK_PIN, 0);
    analogWrite(MOTOR_L_BACK_PIN, 0);
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
    delay(_actionDuration);
    stop();
}

void Robot::moveBackward(int speed = 50){
    analogWrite(MOTOR_L_BACK_PIN, speed);
    analogWrite(MOTOR_R_BACK_PIN, speed);  
    delay(_actionDuration);
    stop();  
}

void Robot::turnRight(int degree){
    switch (_turnRadius){
        case 0:
            analogWrite(MOTOR_L_FORW_PIN, _speed);
            analogWrite(MOTOR_R_BACK_PIN, _speed);  
            delay(_actionDuration);
            stop();
            break;
        case 1:
            analogWrite(MOTOR_L_FORW_PIN, _speed);
            analogWrite(MOTOR_R_BACK_PIN, _speed/2);  
            delay(_actionDuration);
            stop();  
            break;
        case 2:
            analogWrite(MOTOR_L_FORW_PIN, _speed);  
            delay(_actionDuration);
            stop();
            break;
        case 3:
            analogWrite(MOTOR_L_FORW_PIN, _speed);
            analogWrite(MOTOR_R_FORW_PIN, _speed/2);  
            delay(_actionDuration);
            stop();  
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
            delay(_actionDuration);
            stop();
            break;
        case 1:
            analogWrite(MOTOR_R_FORW_PIN, _speed);
            analogWrite(MOTOR_L_BACK_PIN, _speed/2);  
            delay(_actionDuration);
            stop();  
            break;
        case 2:
            analogWrite(MOTOR_R_FORW_PIN, _speed);  
            delay(_actionDuration);
            stop();
            break;
        case 3:
            analogWrite(MOTOR_R_FORW_PIN, _speed);  
            analogWrite(MOTOR_L_FORW_PIN, _speed/2);  
            delay(_actionDuration);
            stop();
            break;
        default:
            break;
    }    
}

void Robot::gripperBaseRotate(int degree){
    _gripperBaseServo.write(degree);
}

void Robot::gripperBase2Rotate(int degree){
    _gripperBase2Servo.write(degree);
}

void Robot::gripperShoulderRotate(int degree){
    _gripperShoulderServo.write(degree);
}

void Robot::gripperElbowRotate(int degree){
    _gripperElbowServo.write(degree);
}

void Robot::gripperWristRotate(int degree){
    _gripperWristServo.write(degree);
}

void Robot::grip(int degree){
    _gripperFingerServo.write(degree);
}

void Robot::listenForCommands(int command){
    stop();

    if (command == 20){
        setSpeed(20);
    }
    else if (command == 40){
        setSpeed(40);
    }
    else if (command == 60){
        setSpeed(60);
    }
    else if (command == 80){
        setSpeed(80);
    }
    else if (command == 100){
        setSpeed(100);
    }
    else if (command == 21){
        setTurnRadius(0);
    }
    else if (command == 22){
        setTurnRadius(1);
    }
    else if (command == 23){
        setTurnRadius(2);
    }
    else if (command == 24){
        setTurnRadius(3);
    }
    else if (command == 5){
        stop();
    }
    else if (command == 8) {
        moveForward(_speed);
    }
    else if (command == 2){
        moveBackward(_speed);
    }
    else if (command == 6) {
        turnRight(_speed);
    }
    else if (command == 4) {
        turnLeft(_speed);
    }
    else if (command >= 1000 && command <= 1180) {
        int degree = mapToServoDegree (command, 1000, 1180);
        grip(degree);
    }
    else if (command >= 2000 && command <= 2180) {
        int degree = mapToServoDegree (command, 2000, 2180);
        gripperWristRotate(degree);
    }
    else if (command >= 3000 && command <= 3180) {
        int degree = mapToServoDegree (command, 3000, 3180);
        gripperElbowRotate(degree);
    }
    else if (command >= 4000 && command <= 4180) {
        int degree = mapToServoDegree (command, 4000, 4180);
        gripperShoulderRotate(degree);
    }
    else if (command >= 5000 && command <= 5180) {
        int degree = mapToServoDegree (command, 5000, 5180);
        gripperBase2Rotate(degree);
    }
    else if (command >= 6000 && command <= 6180) {
        int degree = mapToServoDegree (command, 6000, 6180);
        gripperBaseRotate(degree);
    }
    else stop();
}

void Robot::testAllSystems(HardwareSerial &serial = Serial){
    Serial.println("Setting speed to 20");
    setSpeed(20);
    Serial.println("Moving Forward");
    moveForward(_speed);
    Serial.println("Moving Backward");
    moveBackward(_speed);
    Serial.println("Turning Right 90 degree");
    turnRight(90);
    Serial.println("Turning Left 90 degree");
    turnLeft(90);

    Serial.println("Setting speed to 100");
    setSpeed(100);
    Serial.println("Moving Forward");
    moveForward(_speed);
    Serial.println("Moving Backward");
    moveBackward(_speed);
    Serial.println("Turning Right 180 degree");
    turnRight(180);
    Serial.println("Turning Left 180 degree");
    turnLeft(180);

    Serial.println("Rotating Gripper Base to 180 degree position");
    gripperBaseRotate(180);
    Serial.println("Rotating Gripper Base to 0 degree position");
    gripperBaseRotate(0);

    Serial.println("Rotating Gripper Base2 to 180 degree position");
    gripperBase2Rotate(180);
    Serial.println("Rotating Gripper Base2 to 0 degree position");
    gripperBase2Rotate(0);

    Serial.println("Rotating Gripper Shoulder to 180 degree position");
    gripperShoulderRotate(180);
    Serial.println("Rotating Gripper Shoulder to 0 degree position");
    gripperShoulderRotate(0);

    Serial.println("Rotating Gripper Elbow to 180 degree position");
    gripperElbowRotate(180);
    Serial.println("Rotating Gripper Elbow to 0 degree position");
    gripperElbowRotate(0);
    
    Serial.println("Rotating Gripper Wrist to 180 degree position");
    gripperWristRotate(180);
    Serial.println("Rotating Gripper Wrist to 0 degree position");
    gripperWristRotate(0);

    Serial.println("Closing Grip Fully");
    grip(180);
    Serial.println("Opening Grip Fully");
    grip(0);
    
    Serial.println("Stopping All Movement");
    stop();
}
