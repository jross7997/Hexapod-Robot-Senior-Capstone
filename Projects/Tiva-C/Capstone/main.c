//
#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/gpio.h"
#include "driverlib/interrupt.h"
#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"
#include "driverlib/uart.h"
#include "servo.h"
#include "legs.h"
#include "uartcomm.h"


char last_Command = 'S';
uint8_t cont_Command = 0;
uint8_t fast_Command = 0;

void UARTIntHandler(void){
    uint32_t ui32Status;
    char tempChar;

    ui32Status = UARTIntStatus(UART1_BASE, true); //get interrupt status

    UARTIntClear(UART1_BASE, ui32Status); //clear the asserted interrupts

    tempChar = UARTCharGet(UART1_BASE);
    if(tempChar == 'C'){
        if(cont_Command == 1){
            cont_Command = 0;
        }else{
            cont_Command = 1;
        }
    }else if(tempChar == 'F'){
        if(fast_Command == 1){
            fast_Command = 0;
        }else{
            fast_Command = 1;
        }
    }else {
        last_Command = tempChar;
    }

//// Check the functionality of the UART by printing to a serial reader on a PC
//    UARTCharPut(UART0_BASE, last_Command);
//    UARTCharPut(UART0_BASE, '\n');
}

 int main(void) {
    uint32_t ui32PWM_Freq = getPWMFrequency();

    SysCtlClockSet(SYSCTL_SYSDIV_4 | SYSCTL_USE_PLL | SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ);

    uint32_t ui32PWMClock = getPWMClock();
    uint32_t ui32Load = getLoad(ui32PWMClock, ui32PWM_Freq);
    Legs_Init(ui32Load);
    UART1_Init();

//// Check the functionality of the UART by printing to a serial reader on a PC
//    UART0_Init();

    while (1){
        switch (last_Command){
            case 'S':
                Neutral_Stance(ui32Load);
                break;
            case 'U':
                if(fast_Command == 0){
                    forward(ui32Load, 500);
                }else {
                    forward(ui32Load, 100);
                }

                if(cont_Command == 0){last_Command = 'S';}
                break;
            case 'D':
                if(fast_Command == 0){
                    backward(ui32Load, 500);
                }else {
                    backward(ui32Load, 100);
                }
             if(cont_Command==0){last_Command = 'S';}
                break;
            case 'L':
                if(fast_Command == 0){
                    turn_Left(ui32Load, 500);
                }else {
                    turn_Left(ui32Load, 100);
                }
               if(cont_Command==0){last_Command = 'S';}
                break;
            case 'R':
                if(fast_Command == 0){
                    turn_Right(ui32Load, 500);
                }else {
                    turn_Right(ui32Load, 100);
                }
              if(cont_Command==0){last_Command = 'S';}
                break;
            case 'H':
                wave_one(ui32Load);
                wave_one(ui32Load);
                last_Command = 'S';
                break;
            case 'W':
                wave_two(ui32Load);
                wave_two(ui32Load);
                last_Command = 'S';
                break;
//// Uncomment to test each leg individually
//            case '1':
//                LF_Test(ui32Load);
//                last_Command = 'S';
//                break;
//            case '2':
//                LM_Test(ui32Load);
//                last_Command = 'S';
//                break;
//            case '3':
//                LB_Test(ui32Load);
//                last_Command = 'S';
//                break;
//            case '4':
//                RF_Test(ui32Load);
//                last_Command = 'S';
//                break;
//            case '5':
//                RM_Test(ui32Load);
//                last_Command = 'S';
//                break;
//            case '6':
//                RB_Test(ui32Load);
//                last_Command = 'S';
//                break;
            default:
                Neutral_Stance(ui32Load);
                break;
        }
    }

}

