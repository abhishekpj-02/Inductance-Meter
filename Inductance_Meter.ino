/*
 * =================================================================================
 * HARDWARE CONNECTION REFERENCE
 * =================================================================================
 *
 * ARDUINO PINS USED:
 * - D13 (OUTPUT): LC Tank Kick Pulse Output.
 * - D11 (INPUT): Digital Square Wave Input from Comparator Output.
 * - A4 (SDA) / A5 (SCL): I2C Communication with LCD.
 *
 * LM339 (Comparator) WIRING:
 * - VCC (Pin 3): Connect to Arduino 5V Rail.
 * - GND (Pin 12): Connect to Arduino GND Rail.
 * - Input 1+ (e.g., Pin 5): Connect to the LC Tank (Lx and Cref junction).
 * - Input 1- (e.g., Pin 4): Connect to the 2.5V Reference (voltage divider).
 * - Output 1 (Pin 1 or 2): Connect via a PULL-UP RESISTOR (e.g., 10k Ohm) to the 5V rail, 
 * and then connect to Arduino D11.
 *
 * LC TANK CIRCUIT:
 * - The Unknown Inductor (Lx) and the Reference Capacitor (Cref) are connected in parallel.
 * - The D13 Kick Pulse is applied to this parallel tank (often via a 150 Ohm resistor).
 *
 * =================================================================================
 */
//LCD config
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4);  //sometimes the adress is not 0x3f. Change to 0x27 if it dosn't work.

//13 is the input to the circuit (connects to 150ohm resistor), 11 is the comparator/op-amp output.
double pulse, frequency, capacitance, inductance, inductance_mH;
void setup(){
  lcd.init();
  lcd.backlight();
  Serial.begin(115200);
  pinMode(11, INPUT);//output through a 150 ohm resistor to thr LC circuit
  pinMode(13, OUTPUT);//Input from the comparator output//Use any other pin you select
}
void loop(){
  
  digitalWrite(13, HIGH); 
  delay(5);//give some time to charge inductor.
  digitalWrite(13,LOW);
  delayMicroseconds(100); //make sure resination is measured
  pulse = pulseIn(11,HIGH,5000);//returns 0 if timeout
  if(pulse > 0.1){ //if a timeout did not occur and it took a reading:
    
  capacitance =2E-6; // <- insert value here
  
  
  frequency = 1.E6/(2*pulse);
  inductance = 1./(capacitance*frequency*frequency*4.*3.14159*3.14159);/
  inductance *= 1E6; 
  inductance_mH = inductance * 1000; 

  //Serial print
  Serial.print("High for uS:");
  Serial.print( pulse );
  Serial.print("\tfrequency Hz:");
  Serial.print( frequency );
  Serial.print("\tinductance uH:");
  Serial.println( inductance );
  delay(10);

  //LCD print
  lcd.clear();
  lcd.setCursor(0,0); 
  lcd.print("uH Inductance mH");
  lcd.setCursor(0,1); 
  lcd.print(inductance);
  lcd.setCursor(10,1); 
  lcd.print(inductance_mH);        
  delay(500);
  }
}

