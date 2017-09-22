/* 4x5 Matrix Array 20 Keypad [S187] : http://rdiot.tistory.com/135 [RDIoT Demo] */

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
 
LiquidCrystal_I2C lcd(0x27,20,4);  // LCD2004
 
const byte numRows= 5; //number of rows on the keypad
const byte numCols= 4; //number of columns on the keypad
 
//keymap defines the key pressed according to the row and columns just as appears on the keypad
char keymap[numRows][numCols]= 
{
  {'A','B','#','*'},
  {'1','2','3','U'},
  {'4','5','6','D'},
  {'7','8','9','C'},
  {'L','0','R','E'}
};
 
byte rowPins[numRows] = {10,9,8,7,6}; 
byte colPins[numCols]= {2,3,4,5}; 
 
//initializes an instance of the Keypad class
Keypad myKeypad= Keypad(makeKeymap(keymap), rowPins, colPins, numRows, numCols);
 
String numstr = "";
 
void setup()
{
  lcd.init();  // initialize the lcd 
  lcd.backlight();
  lcd.print("start LCD2004");
 
  delay(1000);
 
  lcd.clear();
}
 
void loop()
{
 
  lcd.setCursor(0,0);
  lcd.print("S187:4x5 20 Keypad");
 
 
  char keypressed = myKeypad.getKey();
  if (keypressed != NO_KEY)
  {
   // Serial.print(keypressed);
    lcd.setCursor(0,1);
    lcd.print("keypressed=" + (String)keypressed + "  ");
 
    switch (keypressed)
    {
      case '1':        
           numstr = "1    ";
        break;
      case '2':           
           numstr = "2    ";
        break;  
      case '3':           
           numstr = "3    ";
        break; 
      case '4':           
           numstr = "4    ";
        break; 
      case '5':           
           numstr = "5    ";
        break;                 
      case '6':           
           numstr = "6    ";
        break; 
      case '7':           
           numstr = "7    ";
        break; 
      case '8':           
           numstr = "9    ";
        break; 
      case '0':           
           numstr = "0    ";
        break; 
      case 'A':           
          numstr = "F1   ";
        break; 
      case 'B':           
          numstr = "F2   ";
        break; 
      case 'C':           
          numstr = "ESC  ";
        break; 
      case 'E':           
          numstr = "ENTER";
        break; 
      case 'D':           
          numstr = "DOWN ";
        break; 
      case 'U':           
          numstr = "UP   ";
        break; 
      case 'R':           
          numstr = "RIGHT ";
        break; 
      case 'L':           
          numstr = "LEFT ";
        break; 
      case '*':           
          numstr = "*    ";
        break; 
      case '#':           
          numstr = "#    ";
        break;                                                 
        
      default:          
        break;
    }
 
    if(numstr !="")
    {
      lcd.setCursor(0,2);
      lcd.print("numstr=" + (String)numstr + " ");
    }
 
  }
 
}
 
