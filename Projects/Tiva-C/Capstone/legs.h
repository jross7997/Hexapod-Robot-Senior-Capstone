/*
 * legs.h
 *
 *  Created on: Oct 9, 2018
 *      Author: jross5
 */

#ifndef LEGS_H_
#define LEGS_H_

extern void All_PWM_Init();
extern void Legs_Init(uint32_t ui32Load);

extern void LegLF_Position(uint8_t ui8L1Degrees,uint8_t ui8L2Degrees,uint32_t ui32Load);
extern void LegLM_Position(uint8_t ui8L1Degrees,uint8_t ui8L2Degrees,uint32_t ui32Load);
extern void LegLB_Position(uint8_t ui8L1Degrees,uint8_t ui8L2Degrees,uint32_t ui32Load);

extern void LegRF_Position(uint8_t ui8R1Degrees,uint8_t ui8R2Degrees,uint32_t ui32Load);
extern void LegRM_Position(uint8_t ui8R1Degrees,uint8_t ui8R2Degrees,uint32_t ui32Load);
extern void LegRB_Position(uint8_t ui8R1Degrees,uint8_t ui8R2Degrees,uint32_t ui32Load);

extern void Neutral_Stance(uint32_t ui32Load);
extern void forward(uint32_t ui32Load, uint32_t delay);
extern void backward(uint32_t ui32Load, uint32_t delay);
extern void turn_Right(uint32_t ui32Load, uint32_t delay);
extern void turn_Left(uint32_t ui32Load, uint32_t delay);
extern void wave_one(uint32_t ui32Load);
extern void wave_two(uint32_t ui32Load);

#endif /* LEGS_H_ */
