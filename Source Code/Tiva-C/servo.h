/*
 * servo.h
 *
 *  Created on: Sep 27, 2018
 *      Author: jross5
 */

#ifndef SERVO_H_
#define SERVO_H_

extern void delayMS(uint32_t ms);

extern uint32_t getPWMFrequency();
extern uint32_t getPWMClock();
extern uint32_t getLoad(uint32_t ui32PWMClock, uint32_t ui32PWMFreq);

extern void PWM_Enable();
extern void GPIOPWM_Enable();

extern void M0PWM0_Init(uint32_t ui32Load);
extern void M0PWM1_Init(uint32_t ui32Load);
extern void M0PWM2_Init(uint32_t ui32Load);
extern void M0PWM3_Init(uint32_t ui32Load);
extern void M0PWM4_Init(uint32_t ui32Load);
extern void M0PWM5_Init(uint32_t ui32Load);
extern void M0PWM6_Init(uint32_t ui32Load);
extern void M0PWM7_Init(uint32_t ui32Load);

extern void M1PWM0_Init(uint32_t ui32Load);
extern void M1PWM1_Init(uint32_t ui32Load);
extern void M1PWM2_Init(uint32_t ui32Load);
extern void M1PWM3_Init(uint32_t ui32Load);
extern void M1PWM4_Init(uint32_t ui32Load);
extern void M1PWM5_Init(uint32_t ui32Load);
extern void M1PWM6_Init(uint32_t ui32Load);
extern void M1PWM7_Init(uint32_t ui32Load);

extern void M0PWM0_PositionServo(uint8_t ui8Degrees, uint32_t ui32Load);
extern void M0PWM1_PositionServo(uint8_t ui8Degrees, uint32_t ui32Load);
extern void M0PWM2_PositionServo(uint8_t ui8Degrees, uint32_t ui32Load);
extern void M0PWM3_PositionServo(uint8_t ui8Degrees, uint32_t ui32Load);
extern void M0PWM4_PositionServo(uint8_t ui8Degrees, uint32_t ui32Load);
extern void M0PWM5_PositionServo(uint8_t ui8Degrees, uint32_t ui32Load);
extern void M0PWM6_PositionServo(uint8_t ui8Degrees, uint32_t ui32Load);
extern void M0PWM7_PositionServo(uint8_t ui8Degrees, uint32_t ui32Load);

extern void M1PWM0_PositionServo(uint8_t ui8Degrees, uint32_t ui32Load);
extern void M1PWM1_PositionServo(uint8_t ui8Degrees, uint32_t ui32Load);
extern void M1PWM2_PositionServo(uint8_t ui8Degrees, uint32_t ui32Load);
extern void M1PWM3_PositionServo(uint8_t ui8Degrees, uint32_t ui32Load);
extern void M1PWM4_PositionServo(uint8_t ui8Degrees, uint32_t ui32Load);
extern void M1PWM5_PositionServo(uint8_t ui8Degrees, uint32_t ui32Load);
extern void M1PWM6_PositionServo(uint8_t ui8Degrees, uint32_t ui32Load);
extern void M1PWM7_PositionServo(uint8_t ui8Degrees, uint32_t ui32Load);


#endif /* SERVO_H_ */
