
/*
 Timer examples
 Timer0, Normal mode
 - Timer Overflow Interrupt
 
 Generating sound
 
 */

byte pin_state = 0;    //this will help us to switch

ISR(TIMER0_OVF_vect) 
{
      //third method: we set it in TIMSK0 that when 
      //the TOV flag is set there should be an interrupt
      //the flag is cleared by executing the interrupt
      
      //we get here when TCNT0 is 0x00
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
   
  TCCR0A = 0b00000000;  //normal uzemmod
  TCCR0B = 0b00000100;  //prescaler : 256

  TCNT0  = 0x00;       //starting value:0
  TIMSK0 = 0b00000001; //we have overflow interrupt
  TIFR0  = 0b00000001; //clear TOV flag
  //PORTD output pin
  DDRD |= 0b11100000;   //D7 D6 D5 as outputs 

  sei();
  
  //main loop
  
  while (1)
    {
      //.. the interrupt does the work not the main loop
      //.. the main loop is free
      
    }

  
  return 0;  
}
