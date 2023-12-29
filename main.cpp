//#include <stdio.h>
#include "pico/stdlib.h"

uint8_t test1 = 0;
uint8_t test2[] = {0,0,0,0};
uint8_t test3[] = {0,00,00,00,0};



#include "24aa01.cpp"
#include "hardware/i2c.h"


int main() {
    stdio_init_all();
    EPROOM_24AA01::init();

    printf("initing\n");
    sleep_ms(2000);
    printf("initing wait end\n");


    uint8_t read128[128];
    //for (int i = 0; i < 100;i++) read100[i] = 0;

    //EPROOM_24AA01::clearAllMemory();
    while(1) {
        // EPROOM_24AA01::clearAllMemory();

        if (EPROOM_24AA01::checkIfDataPresent()) {
            printf("DATA IS PRESENT\n");
            EPROOM_24AA01::readAll();
            printf("reg 1: %i            \n", test1);
            printf("reg 2: %i %i %i %i   \n", test2[0], test2[1], test2[2], test2[3]);
            printf("reg 3: %i %i %i %i %i\n", test3[0], test3[1], test3[2], test3[3], test3[4]);

        } else {
            printf("DATA IS not PRESENT\n");
            EPROOM_24AA01::writeAll();
            sleep_ms(1);
            EPROOM_24AA01::randomRead(0,read128,128);

            for (int i = 0; i < 128; i+=8)
                printf("%i,%i,%i,%i,%i,%i,%i,%i\n", read128[i], read128[i+1], read128[i+2], read128[i+3], read128[i+4], read128[i+5], read128[i+6], read128[i+7]);
        }

        sleep_ms(1000);

    }
    return 0;
}