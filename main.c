#include <pic18f4520.h>
#include "config.h"
#include "delay.h"
#include "lcd.h"
#include "ssd.h"
#include "stdio.h"

#define L0 0x80
#define L1 0xC0
#define CLR 0x01
#define ON 0x0F

void main(void) {
    TRISB = 0x00;
    PORTB = 0x00;
    ssdInit();
    lcdInit();
    lcdCommand(ON);
    
    for (;;) {
        
        lcdCommand(CLR);
        printf("siga");
        PORTB = 0x80; //Acende verde
        tempoSegundos(9); //9 segundos
        ssdDigit((4), 0);
        ssdUpdate();
        
        lcdCommand(CLR);
        printf("reduza");
        PORTB = 0x40; //Acende amarelo
        tempoSegundos(4); //4 segundos
        ssdDigit((9), 1);
        ssdUpdate();
        
        lcdCommand(CLR);
        printf("pare");
        PORTB = 0x20; //Acende Vermelho
        tempoSegundos(9); //9 segundos
        ssdDigit((2), 2);
        ssdUpdate();
        
        
        lcdCommand(CLR);
        printf("atencao");
        PORTB = 0x40; //Acende amarelo
        tempoSegundos(1); //a segundos
        PORTB = 0x00; //Acende Vermelho
        tempoSegundos(1); //a segundos
        ssdDigit((9), 3); 
        ssdUpdate();
        
    }
}

