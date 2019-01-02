/*
 * servo.c
 * Library based off the TIVA C workshop to control the SG90 micro servos
 *
 *  Created on: Sep 27, 2018
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

#define PWM_FREQUENCY 55

uint32_t getPWMFrequency(){
    return PWM_FREQUENCY;
}

void delayMS(uint32_t ms)
{
    SysCtlDelay((SysCtlClockGet() / (3 * 1000)) * ms);
}

uint32_t getPWMClock(){
    return (SysCtlClockGet() / 64);
}

uint32_t getLoad(uint32_t ui32PWMClock, uint32_t ui32PWMFreq){
    return ((ui32PWMClock / ui32PWMFreq) - 1);
}
void PWM_Enable(){
    SysCtlPWMClockSet(SYSCTL_PWMDIV_64);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM1);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM0);
}
void GPIOPWM_Enable(){
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOC);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
}

//------------------------------------------------------------------------------------------------------------
//M0 Initilization Methods
//-------------------------------------------------------------------------------------------------------------
void M0PWM0_Init(uint32_t ui32Load){
    GPIOPinTypePWM(GPIO_PORTB_BASE, GPIO_PIN_6);
    GPIOPinConfigure(GPIO_PB6_M0PWM0);
    PWMGenConfigure(PWM0_BASE, PWM_GEN_0, PWM_GEN_MODE_DOWN);
    PWMGenPeriodSet(PWM0_BASE, PWM_GEN_0, ui32Load);
    PWMOutputState(PWM0_BASE, PWM_OUT_0_BIT, true);
    PWMGenEnable(PWM0_BASE, PWM_GEN_0);
}
void M0PWM1_Init(uint32_t ui32Load){
    GPIOPinTypePWM(GPIO_PORTB_BASE, GPIO_PIN_7);
    GPIOPinConfigure(GPIO_PB7_M0PWM1);
    PWMGenConfigure(PWM0_BASE, PWM_GEN_0, PWM_GEN_MODE_DOWN);
    PWMGenPeriodSet(PWM0_BASE, PWM_GEN_0, ui32Load);
    PWMOutputState(PWM0_BASE, PWM_OUT_1_BIT, true);
    PWMGenEnable(PWM0_BASE, PWM_GEN_0);
}
void M0PWM2_Init(uint32_t ui32Load){
    GPIOPinTypePWM(GPIO_PORTB_BASE, GPIO_PIN_4);
    GPIOPinConfigure(GPIO_PB4_M0PWM2);
    PWMGenConfigure(PWM0_BASE, PWM_GEN_1, PWM_GEN_MODE_DOWN);
    PWMGenPeriodSet(PWM0_BASE, PWM_GEN_1, ui32Load);
    PWMOutputState(PWM0_BASE, PWM_OUT_2_BIT, true);
    PWMGenEnable(PWM0_BASE, PWM_GEN_1);
}
void M0PWM3_Init(uint32_t ui32Load){
    GPIOPinTypePWM(GPIO_PORTB_BASE, GPIO_PIN_5);
    GPIOPinConfigure(GPIO_PB5_M0PWM3);
    PWMGenConfigure(PWM0_BASE, PWM_GEN_1, PWM_GEN_MODE_DOWN);
    PWMGenPeriodSet(PWM0_BASE, PWM_GEN_1, ui32Load);
    PWMOutputState(PWM0_BASE, PWM_OUT_3_BIT, true);
    PWMGenEnable(PWM0_BASE, PWM_GEN_1);
}
void M0PWM4_Init(uint32_t ui32Load){
    GPIOPinTypePWM(GPIO_PORTE_BASE, GPIO_PIN_4);
    GPIOPinConfigure(GPIO_PE4_M0PWM4);
    PWMGenConfigure(PWM0_BASE, PWM_GEN_2, PWM_GEN_MODE_DOWN);
    PWMGenPeriodSet(PWM0_BASE, PWM_GEN_2, ui32Load);
    PWMOutputState(PWM0_BASE, PWM_OUT_4_BIT, true);
    PWMGenEnable(PWM0_BASE, PWM_GEN_2);
}
void M0PWM5_Init(uint32_t ui32Load){
    GPIOPinTypePWM(GPIO_PORTE_BASE, GPIO_PIN_5);
    GPIOPinConfigure(GPIO_PE5_M0PWM5);
    PWMGenConfigure(PWM0_BASE, PWM_GEN_2, PWM_GEN_MODE_DOWN);
    PWMGenPeriodSet(PWM0_BASE, PWM_GEN_2, ui32Load);
    PWMOutputState(PWM0_BASE, PWM_OUT_5_BIT, true);
    PWMGenEnable(PWM0_BASE, PWM_GEN_2);
}
void M0PWM6_Init(uint32_t ui32Load){
    GPIOPinTypePWM(GPIO_PORTC_BASE, GPIO_PIN_4);
    GPIOPinConfigure(GPIO_PC4_M0PWM6);
    PWMGenConfigure(PWM0_BASE, PWM_GEN_3, PWM_GEN_MODE_DOWN);
    PWMGenPeriodSet(PWM0_BASE, PWM_GEN_3, ui32Load);
    PWMOutputState(PWM0_BASE, PWM_OUT_6_BIT, true);
    PWMGenEnable(PWM0_BASE, PWM_GEN_3);
}
void M0PWM7_Init(uint32_t ui32Load){
    GPIOPinTypePWM(GPIO_PORTC_BASE, GPIO_PIN_5);
    GPIOPinConfigure(GPIO_PC5_M0PWM7);
    PWMGenConfigure(PWM0_BASE, PWM_GEN_3, PWM_GEN_MODE_DOWN);
    PWMGenPeriodSet(PWM0_BASE, PWM_GEN_3, ui32Load);
    PWMOutputState(PWM0_BASE, PWM_OUT_7_BIT, true);
    PWMGenEnable(PWM0_BASE, PWM_GEN_3);
}

//------------------------------------------------------------------------------------------------------------
//M1 Initilization Methods
//-------------------------------------------------------------------------------------------------------------
void M1PWM0_Init(uint32_t ui32Load){
    GPIOPinTypePWM(GPIO_PORTD_BASE, GPIO_PIN_0);
    GPIOPinConfigure(GPIO_PD0_M1PWM0);
    PWMGenConfigure(PWM1_BASE, PWM_GEN_0, PWM_GEN_MODE_DOWN);
    PWMGenPeriodSet(PWM1_BASE, PWM_GEN_0, ui32Load);
    PWMOutputState(PWM1_BASE, PWM_OUT_0_BIT, true);
    PWMGenEnable(PWM1_BASE, PWM_GEN_0);
}
void M1PWM1_Init(uint32_t ui32Load){
    GPIOPinTypePWM(GPIO_PORTD_BASE, GPIO_PIN_1);
    GPIOPinConfigure(GPIO_PD1_M1PWM1);
    PWMGenConfigure(PWM1_BASE, PWM_GEN_0, PWM_GEN_MODE_DOWN);
    PWMGenPeriodSet(PWM1_BASE, PWM_GEN_0, ui32Load);
    PWMOutputState(PWM1_BASE, PWM_OUT_1_BIT, true);
    PWMGenEnable(PWM1_BASE, PWM_GEN_0);
}
void M1PWM2_Init(uint32_t ui32Load){
    GPIOPinTypePWM(GPIO_PORTA_BASE, GPIO_PIN_6);
    GPIOPinConfigure(GPIO_PA6_M1PWM2);
    PWMGenConfigure(PWM1_BASE, PWM_GEN_1, PWM_GEN_MODE_DOWN);
    PWMGenPeriodSet(PWM1_BASE, PWM_GEN_1, ui32Load);
    PWMOutputState(PWM1_BASE, PWM_OUT_2_BIT, true);
    PWMGenEnable(PWM1_BASE, PWM_GEN_1);
}
void M1PWM3_Init(uint32_t ui32Load){
    GPIOPinTypePWM(GPIO_PORTA_BASE, GPIO_PIN_7);
    GPIOPinConfigure(GPIO_PA7_M1PWM3);
    PWMGenConfigure(PWM1_BASE, PWM_GEN_1, PWM_GEN_MODE_DOWN);
    PWMGenPeriodSet(PWM1_BASE, PWM_GEN_1, ui32Load);
    PWMOutputState(PWM1_BASE, PWM_OUT_3_BIT, true);
    PWMGenEnable(PWM1_BASE, PWM_GEN_1);
}
void M1PWM4_Init(uint32_t ui32Load){
    GPIOPinTypePWM(GPIO_PORTF_BASE, GPIO_PIN_0);
    GPIOPinConfigure(GPIO_PF0_M1PWM4);
    PWMGenConfigure(PWM1_BASE, PWM_GEN_2, PWM_GEN_MODE_DOWN);
    PWMGenPeriodSet(PWM1_BASE, PWM_GEN_2, ui32Load);
    PWMOutputState(PWM1_BASE, PWM_OUT_4_BIT, true);
    PWMGenEnable(PWM1_BASE, PWM_GEN_2);
}
void M1PWM5_Init(uint32_t ui32Load){
    GPIOPinTypePWM(GPIO_PORTF_BASE, GPIO_PIN_1);
    GPIOPinConfigure(GPIO_PF1_M1PWM5);
    PWMGenConfigure(PWM1_BASE, PWM_GEN_2, PWM_GEN_MODE_DOWN);
    PWMGenPeriodSet(PWM1_BASE, PWM_GEN_2, ui32Load);
    PWMOutputState(PWM1_BASE, PWM_OUT_5_BIT, true);
    PWMGenEnable(PWM1_BASE, PWM_GEN_2);
}
void M1PWM6_Init(uint32_t ui32Load){
    GPIOPinTypePWM(GPIO_PORTF_BASE, GPIO_PIN_2);
    GPIOPinConfigure(GPIO_PF2_M1PWM6);
    PWMGenConfigure(PWM1_BASE, PWM_GEN_3, PWM_GEN_MODE_DOWN);
    PWMGenPeriodSet(PWM1_BASE, PWM_GEN_3, ui32Load);
    PWMOutputState(PWM1_BASE, PWM_OUT_6_BIT, true);
    PWMGenEnable(PWM1_BASE, PWM_GEN_3);
}
void M1PWM7_Init(uint32_t ui32Load){
    GPIOPinTypePWM(GPIO_PORTF_BASE, GPIO_PIN_3);
    GPIOPinConfigure(GPIO_PF3_M1PWM7);
    PWMGenConfigure(PWM1_BASE, PWM_GEN_3, PWM_GEN_MODE_DOWN);
    PWMGenPeriodSet(PWM1_BASE, PWM_GEN_3, ui32Load);
    PWMOutputState(PWM1_BASE, PWM_OUT_7_BIT, true);
    PWMGenEnable(PWM1_BASE, PWM_GEN_3);
}
//------------------------------------------------------------------------------------------------------------
//M0 Position Methods
//-------------------------------------------------------------------------------------------------------------
//M0 PWM0 Pin PB6 position method
void M0PWM0_PositionServo(uint8_t ui8Degrees, uint32_t ui32Load) // Servo position from 0 to 120 degrees
{
    uint8_t ui8Adjust;

    if (ui8Degrees > 120)
    {
        ui8Adjust = 140;
    }
    else
    {
        ui8Adjust = 56.0 + ((float) ui8Degrees * (140.0 - 56.0)) / 120.0;
    }
    PWMPulseWidthSet(PWM0_BASE, PWM_OUT_0, ui8Adjust * ui32Load / 1000);
}

//M0 PWM1 Pin PB7 position method
void M0PWM1_PositionServo(uint8_t ui8Degrees, uint32_t ui32Load) // Servo position from 0 to 120 degrees
{
    uint8_t ui8Adjust;

    if (ui8Degrees > 120)
    {
        ui8Adjust = 140;
    }
    else
    {
        ui8Adjust = 56.0 + ((float) ui8Degrees * (140.0 - 56.0)) / 120.0;
    }
    PWMPulseWidthSet(PWM0_BASE, PWM_OUT_1, ui8Adjust * ui32Load / 1000);
}

//M0 PWM2 Pin PB4 position method
void M0PWM2_PositionServo(uint8_t ui8Degrees, uint32_t ui32Load) // Servo position from 0 to 120 degrees
{
    uint8_t ui8Adjust;

    if (ui8Degrees > 120)
    {
        ui8Adjust = 140;
    }
    else
    {
        ui8Adjust = 56.0 + ((float) ui8Degrees * (140.0 - 56.0)) / 120.0;
    }
    PWMPulseWidthSet(PWM0_BASE, PWM_OUT_2, ui8Adjust * ui32Load / 1000);
}
//M0 PWM3 Pin PB5 position method
void M0PWM3_PositionServo(uint8_t ui8Degrees, uint32_t ui32Load) // Servo position from 0 to 120 degrees
{
    uint8_t ui8Adjust;

    if (ui8Degrees > 120)
    {
        ui8Adjust = 140;
    }
    else
    {
        ui8Adjust = 56.0 + ((float) ui8Degrees * (140.0 - 56.0)) / 120.0;
    }
    PWMPulseWidthSet(PWM0_BASE, PWM_OUT_3, ui8Adjust * ui32Load / 1000);
}
//M0 PWM4 Pin PE4 position method
void M0PWM4_PositionServo(uint8_t ui8Degrees, uint32_t ui32Load) // Servo position from 0 to 120 degrees
{
    uint8_t ui8Adjust;

    if (ui8Degrees > 120)
    {
        ui8Adjust = 140;
    }
    else
    {
        ui8Adjust = 56.0 + ((float) ui8Degrees * (140.0 - 56.0)) / 120.0;
    }
    PWMPulseWidthSet(PWM0_BASE, PWM_OUT_4, ui8Adjust * ui32Load / 1000);
}
//M0 PWM5 Pin PE5 position method
void M0PWM5_PositionServo(uint8_t ui8Degrees, uint32_t ui32Load) // Servo position from 0 to 120 degrees
{
    uint8_t ui8Adjust;

    if (ui8Degrees > 120)
    {
        ui8Adjust = 140;
    }
    else
    {
        ui8Adjust = 56.0 + ((float) ui8Degrees * (140.0 - 56.0)) / 120.0;
    }
    PWMPulseWidthSet(PWM0_BASE, PWM_OUT_5, ui8Adjust * ui32Load / 1000);
}
//M0 PWM6 Pin PC4 position method
void M0PWM6_PositionServo(uint8_t ui8Degrees, uint32_t ui32Load) // Servo position from 0 to 120 degrees
{
    uint8_t ui8Adjust;

    if (ui8Degrees > 120)
    {
        ui8Adjust = 140;
    }
    else
    {
        ui8Adjust = 56.0 + ((float) ui8Degrees * (140.0 - 56.0)) / 120.0;
    }
    PWMPulseWidthSet(PWM0_BASE, PWM_OUT_6, ui8Adjust * ui32Load / 1000);
}
//M0 PWM7 Pin PC5 position method
void M0PWM7_PositionServo(uint8_t ui8Degrees, uint32_t ui32Load) // Servo position from 0 to 120 degrees
{
    uint8_t ui8Adjust;

    if (ui8Degrees > 120)
    {
        ui8Adjust = 140;
    }
    else
    {
        ui8Adjust = 56.0 + ((float) ui8Degrees * (140.0 - 56.0)) / 120.0;
    }
    PWMPulseWidthSet(PWM0_BASE, PWM_OUT_7, ui8Adjust * ui32Load / 1000);
}

//------------------------------------------------------------------------------------------------------------
//M1 Position Methods
//-------------------------------------------------------------------------------------------------------------
//M1 PWM0 Pin PD0 position method
void M1PWM0_PositionServo(uint8_t ui8Degrees, uint32_t ui32Load) // Servo position from 0 to 120 degrees
{
    uint8_t ui8Adjust;

    if (ui8Degrees > 120)
    {
        ui8Adjust = 140;
    }
    else
    {
        ui8Adjust = 56.0 + ((float) ui8Degrees * (140.0 - 56.0)) / 120.0;
    }
    PWMPulseWidthSet(PWM1_BASE, PWM_OUT_0, ui8Adjust * ui32Load / 1000);
}

//M1 PWM1 Pin PD1 position method
void M1PWM1_PositionServo(uint8_t ui8Degrees, uint32_t ui32Load) // Servo position from 0 to 120 degrees
{
    uint8_t ui8Adjust;

    if (ui8Degrees > 120)
    {
        ui8Adjust = 140;
    }
    else
    {
        ui8Adjust = 56.0 + ((float) ui8Degrees * (140.0 - 56.0)) / 120.0;
    }
    PWMPulseWidthSet(PWM1_BASE, PWM_OUT_1, ui8Adjust * ui32Load / 1000);
}

//M1 PWM2 Pin PA6 position method
void M1PWM2_PositionServo(uint8_t ui8Degrees, uint32_t ui32Load) // Servo position from 0 to 120 degrees
{
    uint8_t ui8Adjust;

    if (ui8Degrees > 120)
    {
        ui8Adjust = 140;
    }
    else
    {
        ui8Adjust = 56.0 + ((float) ui8Degrees * (140.0 - 56.0)) / 120.0;
    }
    PWMPulseWidthSet(PWM1_BASE, PWM_OUT_2, ui8Adjust * ui32Load / 1000);
}
//M1 PWM3 Pin PA7 position method
void M1PWM3_PositionServo(uint8_t ui8Degrees, uint32_t ui32Load) // Servo position from 0 to 120 degrees
{
    uint8_t ui8Adjust;

    if (ui8Degrees > 120)
    {
        ui8Adjust = 140;
    }
    else
    {
        ui8Adjust = 56.0 + ((float) ui8Degrees * (140.0 - 56.0)) / 120.0;
    }
    PWMPulseWidthSet(PWM1_BASE, PWM_OUT_3, ui8Adjust * ui32Load / 1000);
}
//M1 PWM4 Pin PF0 position method
void M1PWM4_PositionServo(uint8_t ui8Degrees, uint32_t ui32Load) // Servo position from 0 to 120 degrees
{
    uint8_t ui8Adjust;

    if (ui8Degrees > 120)
    {
        ui8Adjust = 140;
    }
    else
    {
        ui8Adjust = 56.0 + ((float) ui8Degrees * (140.0 - 56.0)) / 120.0;
    }
    PWMPulseWidthSet(PWM1_BASE, PWM_OUT_4, ui8Adjust * ui32Load / 1000);
}
//M1 PWM5 Pin PF1 position method
void M1PWM5_PositionServo(uint8_t ui8Degrees, uint32_t ui32Load) // Servo position from 0 to 120 degrees
{
    uint8_t ui8Adjust;

    if (ui8Degrees > 120)
    {
        ui8Adjust = 140;
    }
    else
    {
        ui8Adjust = 56.0 + ((float) ui8Degrees * (140.0 - 56.0)) / 120.0;
    }
    PWMPulseWidthSet(PWM1_BASE, PWM_OUT_5, ui8Adjust * ui32Load / 1000);
}
//M1 PWM6 Pin PF2 position method
void M1PWM6_PositionServo(uint8_t ui8Degrees, uint32_t ui32Load) // Servo position from 0 to 120 degrees
{
    uint8_t ui8Adjust;

    if (ui8Degrees > 120)
    {
        ui8Adjust = 140;
    }
    else
    {
        ui8Adjust = 56.0 + ((float) ui8Degrees * (140.0 - 56.0)) / 120.0;
    }
    PWMPulseWidthSet(PWM1_BASE, PWM_OUT_6, ui8Adjust * ui32Load / 1000);
}
//M1 PWM7 Pin PF3 position method
void M1PWM7_PositionServo(uint8_t ui8Degrees, uint32_t ui32Load) // Servo position from 0 to 120 degrees
{
    uint8_t ui8Adjust;

    if (ui8Degrees > 120)
    {
        ui8Adjust = 140;
    }
    else
    {
        ui8Adjust = 56.0 + ((float) ui8Degrees * (140.0 - 56.0)) / 120.0;
    }
    PWMPulseWidthSet(PWM1_BASE, PWM_OUT_7, ui8Adjust * ui32Load / 1000);
}
