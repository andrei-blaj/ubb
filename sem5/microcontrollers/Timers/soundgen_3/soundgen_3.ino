
/*
 
 Timer examples
 Timer0, CTC mode - Clear Timer on Compare 
 Generating sound

when TCNT0 == OCR0 
it clears TCNT0 (sets it to 0)

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

  OCR0A = 10;
  //OCR0A  = 28; 
  TCCR0A = 0b01000010;  //setting CTC mode
                        //last 2 bits are WGM1 and 0 set them to 10
                        //first 2 bits are COM0A1,COM0A0 set them to 01
                        //this means the toggle happens on the OCR0 output
                        //so it toggles whenever TCNT0==OCR0
  TCCR0B = 0b00000101;  //prescaler : 256

  TCNT0  = 0x00;       //inital value:0
  TIMSK0 = 0b00000000; //no interrupts
  TIFR0  = 0b00000111; //clear all flags
  
  //PORTD output pin - OC0A is the pin number 6
  DDRD |= 0b11100000;   //D7 D6 D5 set as outputs 

  sei();
  
  //main loop
  
  while (1)
    {
      //.. the timer system handles toggling the OCR0 output
      // we can look it up the OCR0 output is in fact the D6 pin
    }

  
  return 0;  
}
