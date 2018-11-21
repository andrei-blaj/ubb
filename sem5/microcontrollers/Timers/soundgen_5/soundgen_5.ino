
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247

#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494

#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978

#define cnt2Delay 400

#define CPU_clock 12000000
unsigned int timerlimit;
byte pin_state = 0;

int cnt = 1;

ISR(TIMER1_OVF_vect)
{
TCNT1 = timerlimit;

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

void setsound(int soundfrequency)
{
timerlimit = 65535 - CPU_clock/soundfrequency/2;  
}


void setup() 
{
  cli();
  
  TCCR1A = 0b00000000; //normal mode
  TCCR1B = 0b00000001; //prescaler : 1 ( 12MHz )
  TCNT1  = timerlimit;
                       //counts on 2 bytes up to 65535
                       //counting to 65535 means 183 Hz
                       
  TIMSK1 = 0b00000001; //we have overflow interrupt 
  TIFR1  = 0b00000111; //clear all flags
  
  DDRD |= 0b11100000;   //D7 D6 D5 as outputs 

  sei();

  
Serial.begin(9600);

}

void loop() 
{


  if (cnt == 1) {
    setsound(NOTE_D4);
    Serial.println(timerlimit);
    delay(100);
    setsound(NOTE_FS4);
    Serial.println(timerlimit);
    delay(100);
    setsound(NOTE_B4);
    Serial.println(timerlimit);
    delay(100);
    setsound(NOTE_D4);
    Serial.println(timerlimit);
    delay(200);
    setsound(NOTE_CS4);
    Serial.println(timerlimit);
    delay(100);
    setsound(NOTE_B4);
    Serial.println(timerlimit);
    delay(200);
    setsound(NOTE_AS4);
    Serial.println(timerlimit);
    delay(100);
    setsound(NOTE_B4);
    Serial.println(timerlimit);
    delay(1000);
    
    cnt = 2;
  }

  if (cnt == 2) {

    setsound(NOTE_B4);
    Serial.println(timerlimit);
    delay(cnt2Delay);

    setsound(NOTE_CS4);
    Serial.println(timerlimit);
    delay(cnt2Delay);

    setsound(NOTE_D4);
    Serial.println(timerlimit);
    delay(cnt2Delay);

    setsound(NOTE_E4);
    Serial.println(timerlimit);
    delay(cnt2Delay);

    setsound(NOTE_FS4);
    Serial.println(timerlimit);
    delay(cnt2Delay);

    setsound(NOTE_D4);
    Serial.println(timerlimit);
    delay(cnt2Delay);
    setsound(NOTE_FS4);
    Serial.println(timerlimit);
    delay(cnt2Delay);
    setsound(NOTE_D4);
    Serial.println(timerlimit);
    delay(cnt2Delay);
    setsound(NOTE_FS4);
    Serial.println(timerlimit);
    delay(cnt2Delay);

    cnt = 3;
  }

  if (cnt == 3) { 
      setsound(NOTE_FS4);
      Serial.println(timerlimit);
      delay(200);

      setsound(NOTE_D4);
      Serial.println(timerlimit);
      delay(400);

      setsound(NOTE_E4);
      Serial.println(timerlimit);
      delay(200);

      setsound(NOTE_CS4);
      Serial.println(timerlimit);
      delay(400);

      cnt = 4;

  }

  

}
