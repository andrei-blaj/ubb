
/*
 
 Timer examples
 Timer0, Normal mode
 - Normal mode and  TCNT0 polling
 - Normal mode and TOV polling (TIFR register)

Generating sound

NOTE: if your board is 16Mhz redo the calculations
 
 */


int main()
{
  //setup

  //TIMER0 setup
  
  //Waveform generation mode: TCCR0A Bits 1,0 
  //and TCCR0B Bit 3
  //Normal mode = 0 0 0

  //TCCR0B Bits 2,1,0 : Prescaler
  
  //Prescaler Select: TCCR0B Bits 2,1,0
  // 0 0 0 No clock source
  // 0 0 1 Prescaler = 1 (no prescaler) 12 MHz   12MHz/256  = 46875 Hz
  // 0 1 0 Prescaler = 8                1.5 MHz  1.5Mhz/256 = 5859.375 Hz
  
  // 0 1 1 Prescaler = 64               187.5kHz 187.5kHz/256 = 732.421875 Hz
  // this looks like a good prescaler to generate sounds because
  // the lowest frequency is  732/2 = 366 Hz 
  // and the highest is 93.75 kHz

  //1 0 0  Prescaler = 256              46.875 kHz 46.875/256 = 183.1 Hz
  // this seems to be even better, lowest frequency is 183/2 = 91 Hz
  // and the highest is just above the hearing threshold at 23.4375 kHz

  //1 0 1  Prescaler = 1024             11.71875 kHz    11.71875 kHz/256 = 45.77 Hz
  // this is useful in generating low tones down to  45.77/2 = 22 Hz-ig de 
  // however it can only go up to 5.85 kHz 

  cli();
   
  TCCR0A = 0b00000000;  //normal mode
  TCCR0B = 0b00000100;  //prescaler : 256

  TCNT0  = 0x00;       //starting value:0
  TIMSK0 = 0b00000000; //there are no interrupts
  TIFR0  = 0b00000001; //clear TOV flag
  //PORTD output pin
  DDRD |= 0b11100000;   //D7 D6 D5 are set as outputs 

  byte pin_state = 0;    //this will help us to switch

  sei();
  
  //main loop
  
  
  while (1)
    {

      /*
      //first method: read the TCNT0 directly       
      //wait for overflow in the Timer0
      while( TCNT0<0xFF);      
      //we get here when the timer hits 0xFF

      //TCNT0 = 0xF5;

      //12 Mhz/ 256 = 46.875 kHz
      //F5 to FF = count 10 times 
      //F5- starting value, F6, F7, F8, F9, FA, FB, FC, FD, FE, FF
      //4687.5 Hz is the frequency we get half of it because of toggle = 2339.5 Hz
      //this is somewhere between the C#7 and  D7 sounds

       TCNT0 = 228; 

      // how to I calculate things when I know the frequency I want:
      // I would like to have the A5 sound on  880 Hz
      // this means overflows happening at 1760 Hz
      // 46.875 KHz / 1760 Hz = 26.63 not precisely this sound
      // let's count 27 steps that is close
      //255-27 = 228  
      */
      
      
      //second method: instead of reading and comparing TCNT0 
      //we read the TOV bit from TIFR register
      //wait until overflow happens in Timer0
      while( TIFR0 == 0x00);
      //we reset all flags 0x07 is enough we only have 3 flags
      //these three flags are now reset: OCR0A OCR0B TOV
      TIFR0 = 0xFF; 
      //we get here when the timer is 0x00
      //we need to count 1 less than previously
      //TCNT0 = 0xF6;
      TCNT0 = 229;
      
     
      //at each overflow we toggle the PORTD 7,6,5 bits
      if (pin_state==0) 
        {
          PORTD &= 0b00011111;
          pin_state = 1;
        }
      else 
        {
          PORTD |= 0b11100000;
          pin_state = 0;
        }
    }

  
  return 0;  
}
