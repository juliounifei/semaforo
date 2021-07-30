#include "delay.h"

void tempo(unsigned char X){
  volatile unsigned char i, j;
    
    while(X--)
    {
      for(j = 0; j < 41; j++ ){
            for(i = 0; i < 3; i++ );
      }  
    }
        
}

void tempoSegundos(unsigned char X)
{
    while(X--)
    {
        tempo(0xFA);
        tempo(0xFA);
        tempo(0xFA);
        tempo(0xFA);
    }
}