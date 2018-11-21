
//Microcontrollers Demo Course #2 2017 @ Andras Libal
//code for a 4 part 7 segment display 
//this is how we connect the 7 segment display:
//top from right to left to pins 2..7
//bottom from right to left to pins 8..13
//on a Kingbright CC56-12EWA this is what the pins are like listed

#define DELAY 1000

int pintable[8];
int segmenttable[5];
int lettertable[10][8];

int loopcount,num1,num2,num3,num4;
int firstPair, secondPair;

void setup() {

firstPair = 1;
secondPair = 30;

int i;

for(i=2;i<=13;i++)
 pinMode(i,OUTPUT);

pintable[0] = 6;    //a
pintable[1] = 2;    //b
pintable[2] = 10;   //c
pintable[3] = 12;   //d
pintable[4] = 13;    //e
pintable[5] = 5;   //f
pintable[6] = 9;    //g
pintable[7] = 11;   //dot

segmenttable[1] = 8;  //seg 1
segmenttable[2] = 3;  //seg 2
segmenttable[3] = 4;  //seg 3
segmenttable[4] = 7;  //seg 4

//letter 0

lettertable[0][0] = 1; //a
lettertable[0][1] = 1; //b
lettertable[0][2] = 1; //c
lettertable[0][3] = 1; //d
lettertable[0][4] = 1; //e
lettertable[0][5] = 1; //f
lettertable[0][6] = 0; //g
lettertable[0][7] = 0; //dot

//letter 1

lettertable[1][0] = 0; //a
lettertable[1][1] = 1; //b
lettertable[1][2] = 1; //c
lettertable[1][3] = 0; //d
lettertable[1][4] = 0; //e
lettertable[1][5] = 0; //f
lettertable[1][6] = 0; //g
lettertable[1][7] = 0; //dot

//letter 2

lettertable[2][0] = 1; //a
lettertable[2][1] = 1; //b
lettertable[2][2] = 0; //c
lettertable[2][3] = 1; //d
lettertable[2][4] = 1; //e
lettertable[2][5] = 0; //f
lettertable[2][6] = 1; //g
lettertable[2][7] = 0; //dot

//letter 3

lettertable[3][0] = 1; //a
lettertable[3][1] = 1; //b
lettertable[3][2] = 1; //c
lettertable[3][3] = 1; //d
lettertable[3][4] = 0; //e
lettertable[3][5] = 0; //f
lettertable[3][6] = 1; //g
lettertable[3][7] = 0; //dot

//letter 4

lettertable[4][0] = 0; //a
lettertable[4][1] = 1; //b
lettertable[4][2] = 1; //c
lettertable[4][3] = 0; //d
lettertable[4][4] = 0; //e
lettertable[4][5] = 1; //f
lettertable[4][6] = 1; //g
lettertable[4][7] = 0; //dot

//letter 5

lettertable[5][0] = 1; //a
lettertable[5][1] = 0; //b
lettertable[5][2] = 1; //c
lettertable[5][3] = 1; //d
lettertable[5][4] = 0; //e
lettertable[5][5] = 1; //f
lettertable[5][6] = 1; //g
lettertable[5][7] = 0; //dot

//letter 6

lettertable[6][0] = 1; //a
lettertable[6][1] = 0; //b
lettertable[6][2] = 1; //c
lettertable[6][3] = 1; //d
lettertable[6][4] = 1; //e
lettertable[6][5] = 1; //f
lettertable[6][6] = 1; //g
lettertable[6][7] = 0; //dot

//letter 7

lettertable[7][0] = 1; //a
lettertable[7][1] = 1; //b
lettertable[7][2] = 1; //c
lettertable[7][3] = 0; //d
lettertable[7][4] = 0; //e
lettertable[7][5] = 0; //f
lettertable[7][6] = 0; //g
lettertable[7][7] = 0; //dot

//letter 8

lettertable[8][0] = 1; //a
lettertable[8][1] = 1; //b
lettertable[8][2] = 1; //c
lettertable[8][3] = 1; //d
lettertable[8][4] = 1; //e
lettertable[8][5] = 1; //f
lettertable[8][6] = 1; //g
lettertable[8][7] = 0; //dot

//letter 9

lettertable[9][0] = 1; //a
lettertable[9][1] = 1; //b
lettertable[9][2] = 1; //c
lettertable[9][3] = 1; //d
lettertable[9][4] = 0; //e
lettertable[9][5] = 1; //f
lettertable[9][6] = 1; //g
lettertable[9][7] = 0; //dot



//numbers to display

num1 = 0;
num2 = 0;
num3 = 0;
num4 = 0;
loopcount = 0;

}
int cnt = 0;
void write_letter(int letter)
{
  int i;
  
  //write out new number
  for(i=0;i<8;i++)
    {
    if (lettertable[letter][i]==1) digitalWrite(pintable[i],HIGH);
    else digitalWrite(pintable[i],LOW);
    }
    
 }

void loop() {
  
  //segments - off for all
  digitalWrite(8,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(7,HIGH);

  num4 = firstPair / 10;
  num3 = firstPair % 10;
  num2 = secondPair / 10;
  num1 = secondPair % 10;

  write_letter(num1);

  //on for the 1st segment
  digitalWrite(8,LOW);
  delay(1);
  digitalWrite(8,HIGH);

  write_letter(num2);

  //on for the 2nd segment
  digitalWrite(3,LOW);
  delay(1);
  digitalWrite(3,HIGH);

  write_letter(num3);

  //on for the 3rd segment
  digitalWrite(4,LOW);
  delay(1);
  digitalWrite(4,HIGH);

  write_letter(num4);

  //on for the 4th segment
  digitalWrite(7,LOW);
  delay(1);
  digitalWrite(7,HIGH);
  
  cnt++;
//  delay(1000);
  if (cnt % 250 == 0) {

    secondPair--;
  
    if (secondPair == -1 && firstPair != 0) {
      secondPair = 59;
      firstPair--;
    } else if (secondPair == -1 && firstPair == 0) {
      secondPair = 0;
    }
  }
}
