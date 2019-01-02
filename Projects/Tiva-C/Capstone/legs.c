/*
 * legs.c
 * Library based off the servo.c that abstracts the control of servos
 *  Created on: Oct 9, 2018
 *      Author: jross5
 */

#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/debug.h"
#include "driverlib/pwm.h"
#include "driverlib/pin_map.h"
#include "inc/hw_gpio.h"
#include "driverlib/rom.h"
#include "servo.h"

//------------------------------------------------------------------------------------
//INITIALIZATION METHODS
//------------------------------------------------------------------------------------

//Initialize each PWM pin
void All_PWM_Init(){
    uint32_t ui32PWM_Freq = getPWMFrequency();
    GPIOPWM_Enable();
    PWM_Enable();

    // Unlock the Pin PF0 and Set the Commit Bit
    HWREG(GPIO_PORTF_BASE + GPIO_O_LOCK) = GPIO_LOCK_KEY;
    HWREG(GPIO_PORTF_BASE + GPIO_O_CR)   |= 0x01;

    uint32_t ui32PWMClock = getPWMClock();
    uint32_t ui32Load = getLoad(ui32PWMClock, ui32PWM_Freq);

    M0PWM0_Init(ui32Load); //PB6
    M0PWM1_Init(ui32Load); //PB7
    M0PWM2_Init(ui32Load); //PB4
    M0PWM3_Init(ui32Load); //PB5
    M0PWM4_Init(ui32Load); //PE4
    M0PWM5_Init(ui32Load); //PE5
    M0PWM6_Init(ui32Load); //PC4
    M0PWM7_Init(ui32Load); //PC5

    M1PWM0_Init(ui32Load); //PD0
    M1PWM1_Init(ui32Load); //PD1
    M1PWM2_Init(ui32Load); //PA6
    M1PWM3_Init(ui32Load); //PA7
    M1PWM4_Init(ui32Load); //PF0
    M1PWM5_Init(ui32Load); //PF1
    M1PWM6_Init(ui32Load); //PF2
    M1PWM7_Init(ui32Load); //PF3
}

//Initialize each pin used for the hex's Legs
void Legs_Init(uint32_t ui32Load){
    GPIOPWM_Enable();
    PWM_Enable();
    // Unlock the Pin PF0 and Set the Commit Bit
    HWREG(GPIO_PORTF_BASE + GPIO_O_LOCK) = GPIO_LOCK_KEY;
    HWREG(GPIO_PORTF_BASE + GPIO_O_CR)   |= 0x01;

    M0PWM0_Init(ui32Load); //PB6
    M0PWM1_Init(ui32Load); //PB7
    M0PWM2_Init(ui32Load); //PB4
    M0PWM3_Init(ui32Load); //PB5
    M0PWM4_Init(ui32Load); //PE4
    M0PWM5_Init(ui32Load); //PE5
    M0PWM7_Init(ui32Load); //PC5

    M1PWM2_Init(ui32Load); //PA6
    M1PWM3_Init(ui32Load); //PA7
    M1PWM4_Init(ui32Load); //PF0
    M1PWM6_Init(ui32Load); //PF2
    M1PWM7_Init(ui32Load); //PF3

}

//------------------------------------------------------------------------------------
//LEFT LEG POSITION METHODS
//------------------------------------------------------------------------------------

//Front Left Leg position method
//L1F - pin PB5
//L2F - pin PE4
void LegLF_Position(uint8_t ui8L1Degrees,uint8_t ui8L2Degrees,uint32_t ui32Load){
    M0PWM3_PositionServo(ui8L1Degrees, ui32Load);
    M0PWM4_PositionServo(ui8L2Degrees, ui32Load);
}
//Middle Left Leg position method
//L1M - pin PE5
//L2M - pin PB4
void LegLM_Position(uint8_t ui8L1Degrees,uint8_t ui8L2Degrees,uint32_t ui32Load){
    M0PWM5_PositionServo(ui8L1Degrees, ui32Load);
    M0PWM2_PositionServo(ui8L2Degrees, ui32Load);
}
//Back Left Leg position method
//L1B - pin PA6
//L2B - pin PA7
void LegLB_Position(uint8_t ui8L1Degrees,uint8_t ui8L2Degrees,uint32_t ui32Load){
    M1PWM2_PositionServo(ui8L1Degrees, ui32Load);
    M1PWM3_PositionServo(ui8L2Degrees, ui32Load);
}

//------------------------------------------------------------------------------------
//RIGHT LEG POSITION METHODS
//------------------------------------------------------------------------------------

//Front Right Leg position method
//R1F - pin PF2
//R2F - pin PF3
void LegRF_Position(uint8_t ui8R1Degrees,uint8_t ui8R2Degrees,uint32_t ui32Load){
    M1PWM6_PositionServo(ui8R1Degrees, ui32Load);
    M1PWM7_PositionServo(ui8R2Degrees, ui32Load);
}
//Middle Right Leg position method
//R1M - pin PF0
//R2M - pin PC5
void LegRM_Position(uint8_t ui8R1Degrees,uint8_t ui8R2Degrees,uint32_t ui32Load){
    M1PWM4_PositionServo(ui8R1Degrees, ui32Load);
    M0PWM7_PositionServo(ui8R2Degrees, ui32Load);
}
//Back right Leg position method
//R1B - pin PB7
//R2B - pin PB6
void LegRB_Position(uint8_t ui8R1Degrees,uint8_t ui8R2Degrees,uint32_t ui32Load){
    M0PWM1_PositionServo(ui8R1Degrees, ui32Load);
    M0PWM0_PositionServo(ui8R2Degrees, ui32Load);
}

//------------------------------------------------------------------------------------
// Custom Position Methods
//------------------------------------------------------------------------------------
//Set every servos on body to 60 and servos on legs to 0 degrees. Standing neutrally
void Neutral_Stance(uint32_t ui32Load){
    LegLF_Position(60,0,ui32Load);
    LegLM_Position(60,0,ui32Load);
    LegLB_Position(60,0,ui32Load);

    LegRF_Position(60,0,ui32Load);
    LegRM_Position(60,0,ui32Load);
    LegRB_Position(60,0,ui32Load);
}

//Walk Forward one cycle
void forward(uint32_t ui32Load, uint32_t delay){
    LegLF_Position(20,45,ui32Load);
    LegLB_Position(20,45,ui32Load);
    LegRM_Position(110,45,ui32Load);
    delayMS(delay);
    LegLF_Position(20,0,ui32Load);
    LegLB_Position(20,0,ui32Load);
    LegRM_Position(110,0,ui32Load);
 //   Neutral_Stance(ui32Load);
    delayMS(delay);
    LegRF_Position(60,20,ui32Load);
    LegRB_Position(60,20,ui32Load);
    LegLM_Position(60,20,ui32Load);
    delayMS(delay);
    LegLF_Position(60,0,ui32Load);
    LegLB_Position(60,0,ui32Load);
    LegRM_Position(60,0,ui32Load);
    delayMS(delay);
    LegRF_Position(60,0,ui32Load);
    LegRB_Position(60,0,ui32Load);
    LegLM_Position(60,0,ui32Load);

    LegRF_Position(120,45,ui32Load);
    LegRB_Position(120,45,ui32Load);
    LegLM_Position(0,45,ui32Load);
    delayMS(delay);
    LegRF_Position(120,0,ui32Load);
    LegRB_Position(120,0,ui32Load);
    LegLM_Position(0,0,ui32Load);
    delayMS(delay);
    LegLF_Position(60,20,ui32Load);
    LegLB_Position(60,20,ui32Load);
    LegRM_Position(60,20,ui32Load);
    delayMS(delay);
    LegRF_Position(60,0,ui32Load);
    LegRB_Position(60,0,ui32Load);
    LegLM_Position(60,0,ui32Load);
    delayMS(delay);
    LegLF_Position(60,0,ui32Load);
    LegLB_Position(60,0,ui32Load);
    LegRM_Position(60,0,ui32Load);
 //   Neutral_Stance(ui32Load);
}

//Walk backward one cycle
void backward(uint32_t ui32Load, uint32_t delay){
    LegLF_Position(120,45,ui32Load);
    LegLB_Position(120,45,ui32Load);
    LegRM_Position(0,45,ui32Load);
    delayMS(delay);
    LegLF_Position(120,0,ui32Load);
    LegLB_Position(120,0,ui32Load);
    LegRM_Position(0,0,ui32Load);
 //   Neutral_Stance(ui32Load);
    delayMS(delay);
    LegRF_Position(60,20,ui32Load);
    LegRB_Position(60,20,ui32Load);
    LegLM_Position(60,20,ui32Load);
    delayMS(delay);
    LegLF_Position(60,0,ui32Load);
    LegLB_Position(60,0,ui32Load);
    LegRM_Position(60,0,ui32Load);
    delayMS(delay);
    LegRF_Position(60,0,ui32Load);
    LegRB_Position(60,0,ui32Load);
    LegLM_Position(60,0,ui32Load);

    LegRF_Position(0,45,ui32Load);
    LegRB_Position(0,45,ui32Load);
    LegLM_Position(120,45,ui32Load);
    delayMS(delay);
    LegRF_Position(0,0,ui32Load);
    LegRB_Position(0,0,ui32Load);
    LegLM_Position(120,0,ui32Load);
    delayMS(delay);
    LegLF_Position(60,20,ui32Load);
    LegLB_Position(60,20,ui32Load);
    LegRM_Position(60,20,ui32Load);
    delayMS(delay);
    LegRF_Position(60,0,ui32Load);
    LegRB_Position(60,0,ui32Load);
    LegLM_Position(60,0,ui32Load);
    delayMS(delay);
    LegLF_Position(60,0,ui32Load);
    LegLB_Position(60,0,ui32Load);
    LegRM_Position(60,0,ui32Load);
    //Neutral_Stance(ui32Load);
}
//Turn left one cycle
void turn_Left(uint32_t ui32Load, uint32_t delay){
    //Neutral_Stance(ui32Load);
    LegLF_Position(120,20,ui32Load);
    LegLB_Position(120,20,ui32Load);
    LegRM_Position(120,20,ui32Load);
    delayMS(delay);
    LegLF_Position(120,0,ui32Load);
    LegLB_Position(120,0,ui32Load);
    LegRM_Position(120,0,ui32Load);
    delayMS(delay);
    LegRF_Position(60,20,ui32Load);
    LegRB_Position(60,20,ui32Load);
    LegLM_Position(60,20,ui32Load);
    delayMS(delay);
    LegLF_Position(60,0,ui32Load);
    LegLB_Position(60,0,ui32Load);
    LegRM_Position(60,0,ui32Load);
    delayMS(delay);
    LegRF_Position(60,0,ui32Load);
    LegRB_Position(60,0,ui32Load);
    LegLM_Position(60,0,ui32Load);
    delayMS(delay);
   // Neutral_Stance(ui32Load);
}

//Turn Right one cycle
void turn_Right(uint32_t ui32Load, uint32_t delay){
 //   Neutral_Stance(ui32Load);
    LegLF_Position(0,20,ui32Load);
    LegLB_Position(0,20,ui32Load);
    LegRM_Position(0,20,ui32Load);
    delayMS(delay);
    LegLF_Position(0,0,ui32Load);
    LegLB_Position(0,0,ui32Load);
    LegRM_Position(0,0,ui32Load);
    delayMS(delay);
    LegRF_Position(60,20,ui32Load);
    LegRB_Position(60,20,ui32Load);
    LegLM_Position(60,20,ui32Load);
    delayMS(delay);
    LegLF_Position(60,0,ui32Load);
    LegLB_Position(60,0,ui32Load);
    LegRM_Position(60,0,ui32Load);
    delayMS(delay);
    LegRF_Position(60,0,ui32Load);
    LegRB_Position(60,0,ui32Load);
    LegLM_Position(60,0,ui32Load);
    delayMS(delay);
//    Neutral_Stance(ui32Load);
}

void wave_one(uint32_t ui32Load){
    LegRF_Position(0,120,ui32Load);
    delayMS(250);
    LegRF_Position(120,120,ui32Load);
    delayMS(250);
    LegRF_Position(0,120,ui32Load);
}

void wave_two(uint32_t ui32Load){
    LegRM_Position(100,0,ui32Load);
    LegLM_Position(20,0,ui32Load);

    LegRB_Position(20,0,ui32Load);
    LegLB_Position(100,0,ui32Load);

    LegRF_Position(0,120,ui32Load);
    LegLF_Position(120,120,ui32Load);
    delayMS(250);
    LegRF_Position(120,120,ui32Load);
    LegLF_Position(0,120,ui32Load);
    delayMS(250);
    LegRF_Position(0,120,ui32Load);
    LegLF_Position(120,120,ui32Load);
 //   Neutral_Stance(ui32Load);

}


void LF_Test(uint32_t ui32Load){
    Neutral_Stance(ui32Load);
    LegLF_Position(100,45,ui32Load);
    delayMS(250);
    LegLF_Position(100,0,ui32Load);
    delayMS(250);
    LegLF_Position(60,0,ui32Load);
    delayMS(250);
}
void LM_Test(uint32_t ui32Load){
    Neutral_Stance(ui32Load);
    LegLM_Position(20,45,ui32Load);
    delayMS(250);
    LegLM_Position(20,0,ui32Load);
    delayMS(250);
    LegLM_Position(60,0,ui32Load);
    delayMS(250);
}
void LB_Test(uint32_t ui32Load){
    Neutral_Stance(ui32Load);
    LegLB_Position(100,45,ui32Load);
    delayMS(250);
    LegLB_Position(100,0,ui32Load);
    delayMS(250);
    LegLB_Position(60,0,ui32Load);
    delayMS(250);
}

void RF_Test(uint32_t ui32Load){
    Neutral_Stance(ui32Load);
    LegRF_Position(100,45,ui32Load);
    delayMS(250);
    LegRF_Position(100,0,ui32Load);
    delayMS(250);
    LegRF_Position(60,0,ui32Load);
    delayMS(250);
}
void RM_Test(uint32_t ui32Load){
    Neutral_Stance(ui32Load);
    LegRM_Position(100,45,ui32Load);
    delayMS(250);
    LegRM_Position(100,0,ui32Load);
    delayMS(250);
    LegRM_Position(60,0,ui32Load);
    delayMS(250);
}
void RB_Test(uint32_t ui32Load){
    Neutral_Stance(ui32Load);
    LegRB_Position(100,45,ui32Load);
    delayMS(250);
    LegRB_Position(100,0,ui32Load);
    delayMS(250);
    LegRB_Position(60,0,ui32Load);
    delayMS(250);
}
