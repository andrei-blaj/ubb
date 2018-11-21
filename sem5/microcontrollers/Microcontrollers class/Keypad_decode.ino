

/* 
Digital input demonstration
Keypad reading

Using the Keypad library from  
Elegoo CustomKeypad.pde v 1.0
author Alexander Brevig
contact alexanderbrevig@gmail.com

Modify this code in the following way:

Step 1. if there is no password set (beginning of program)
Prompt the user to set a password (finishing with #)
Step 2. Re-read the password from the user (finishing with #)
don't let the user exceed the maximum password length
if the passwords do not match go back to Step 1.
Step 3. Say that the password has been set
Step 4. Ask for a password, read in the password
Step 5. if the password does not match go to Step 4. again
Step 6. if the password matches, write that the password matches,
turn LED on Pin 13 off for 1 second
then turn it back on, then go back to Step 4

*/
#include <Keypad.h>

const byte ROWS = 4; //four rows
const byte COLS = 3; //four columns
//define the symbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
byte rowPins[ROWS] = {9, 8, 7, 6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 4, 3}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

bool password_was_set=false;
int max_password_length;
char password[100];
char repeated_password[100];
char data_read[100];
bool successful_identification;
bool firstiteration=true;

void setup()
  {
  Serial.begin(9600);
  Serial.println("\n\rPassword program start");  
  Serial.flush();
    
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
  
  password_was_set = false;
  max_password_length = 10;
  }

void read_string()
{
  bool string_complete;
  int  char_position;
  char char_read;

  char_position = 0;
  strcpy(data_read,"");
  string_complete = false;

  while ((!string_complete)&&(char_position<max_password_length))
    {
    //wait for next key to be pressed
    char_read = customKeypad.getKey();
          
    while (!char_read)
      {
        char_read = customKeypad.getKey();
      }

        if (char_read!='#')
          {
          Serial.print(char_read);
          data_read[char_position] = char_read; 
          char_position++;
          }
        if (char_read=='#') 
         {
          string_complete = true;
          data_read[char_position]='\0';
         }
      
    }
  
}

void loop()
{
      
  if (!password_was_set)
    {
      
    Serial.print("Please set a password:");
    read_string();
    Serial.println();
    
    strcpy(password,data_read);
    Serial.print("Please repeat the password:");
    read_string();
    Serial.println();
       
    strcpy(repeated_password,data_read);

    if (strcmp(password,repeated_password)==0)
        {
        Serial.println("Password was set successfuly");  
        password_was_set = true;
        }
    else        
        {
        Serial.println("Passwords do not match. Password was not set.");  
        }    
    }
else
    {
    Serial.print("Enter password:");
    read_string();
    Serial.println();
    if (strcmp(data_read,password)==0)
        {
            Serial.println("Access granted");
            digitalWrite(13, LOW);
            delay(1000);
            digitalWrite(13, HIGH);           
        }
      
    }  
}
