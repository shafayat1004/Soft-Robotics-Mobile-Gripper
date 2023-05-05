#include "Robot.h"
#include <SoftwareSerial.h>

// Connectivity ###############################################################
int BLUETOOTH_PIN_RX = 2;
int BLUETOOTH_PIN_TX = 3;
SoftwareSerial bluetooth(BLUETOOTH_PIN_TX, BLUETOOTH_PIN_RX);
// Inputs  ###################################################################
int PRESSURE_SENSOR = 12;
// Outputs ###################################################################
// Gripper
int GRIPPER_BASE_SERVO     = 4;  // 360deg Rotational Base
int GRIPPER_BASE2_SERVO    = 5;  // 360deg Rotational Base
int GRIPPER_SHOULDER_SERVO = 6;  // 360deg Rotational Base
int GRIPPER_ELBOW_SERVO    = 7;  // 270deg?
int GRIPPER_WRIST_SERVO    = 8;  // 270deg? 
int GRIPPER_FINGER_SERVO   = 9;
// Mobile Base
int BASE_TYPE        = 2;   //4 -> 4WD, 2 -> 2WD
int MOTOR_L_FORW_PIN = 10;
int MOTOR_L_BACK_PIN = 11;
int MOTOR_R_FORW_PIN = 12;
int MOTOR_R_BACK_PIN = 13;

Robot robot;

void setup(){
    Serial.begin(9600);
    bluetooth.begin(9600);

    robot.attachGripper(
        GRIPPER_BASE_SERVO,
        GRIPPER_BASE2_SERVO,
        GRIPPER_SHOULDER_SERVO,
        GRIPPER_ELBOW_SERVO,
        GRIPPER_WRIST_SERVO,
        GRIPPER_FINGER_SERVO
    );
    robot.attachBase(
        BASE_TYPE,
        MOTOR_L_FORW_PIN,   MOTOR_L_BACK_PIN,
        MOTOR_R_FORW_PIN,   MOTOR_R_BACK_PIN
    );
}

void loop(){
    
    robot.testAllSystems();
    
    if (bluetooth.available() >= 2) {
        unsigned int num1     = bluetooth.read();
        unsigned int num2     = bluetooth.read();
        unsigned int finalNum = (num2 * 256) + num1;
        robot.listenForCommands((int)finalNum);
    }
	
}
