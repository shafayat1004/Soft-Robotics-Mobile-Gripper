#include "Robot.h"

// Connectivity ###############################################################
int BLUETOOTH_PIN_RX = 2;
int BLUETOOTH_PIN_TX = 3;

// Inputs  ###################################################################

// Outputs ###################################################################
// Gripper
int GRIPPER_BASE_SERVO   = 4;  // 360deg Rotational Base
int GRIPPER_ELBOW_SERVO  = 5;  // 270deg?
int GRIPPER_WRIST_SERVO  = 6;  // 270deg? 
int GRIPPER_FINGER_SERVO = 7;
// Mobile Base
int BASE_TYPE    = 4; //4 -> 4WD, 2 -> 2WD
int MOTOR_FL_PIN = 8;
int MOTOR_FR_PIN = 9;
int MOTOR_BL_PIN = 10;
int MOTOR_BR_PIN = 11;

Robot robot;

void setup(){
    Serial.begin(4800);
	robot.attachBluetooth(
        BLUETOOTH_PIN_RX, 
        BLUETOOTH_PIN_TX
    );
    robot.attachGripper(
        GRIPPER_BASE_SERVO,
        GRIPPER_ELBOW_SERVO,
        GRIPPER_WRIST_SERVO,
        GRIPPER_FINGER_SERVO
    );
    robot.attachBase(
        BASE_TYPE,
        MOTOR_FL_PIN,   MOTOR_FR_PIN,
        MOTOR_BL_PIN,   MOTOR_BR_PIN
    );
}

void loop(){
    robot.listen();
    robot.moveForward(10);
    robot.moveBackward(10);
    robot.turnRight(90);
    robot.turnLeft(90);
    robot.gripperBaseRotate(180);
    robot.gripperElbowRotate(180);
    robot.gripperWristRotate(180);
    robot.grip(180);
	
}
