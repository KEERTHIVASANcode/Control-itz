//including required module
#include <IRremote.h>

 //code for certain button(varies according to the remote)
#define first_key  48703 
#define second_key  58359 
#define third_key  539 
#define fourth_key  25979 
int receiver_pin = 8;   

//intializing pins for output
int first_led_pin = 7;
int second_led_pin = 6;
int third_led_pin = 5;
int fourth_led_pin = 4;

int led[] = {0,0,0,0}; 
IRrecv receiver(receiver_pin); 
decode_results output;

// setting the output pins
void setup()
{
  Serial.begin(9600);
  receiver.enableIRIn();  
  pinMode(first_led_pin, OUTPUT);
  pinMode(second_led_pin, OUTPUT);
  pinMode(third_led_pin, OUTPUT);
  pinMode(fourth_led_pin, OUTPUT);
  }
 
void loop() {
  if (receiver.decode(&output)) {
    unsigned int value = output.value;
 // finding which button is pressed and switching it ON
 //if it is OFF and viceversa
    switch(value) {
       case first_key:    
         if(led[1] == 1) {       
            digitalWrite(first_led_pin, LOW);
            led[1] = 0;           
         } else {                      
             digitalWrite(first_led_pin, HIGH); 
             led[1] = 1;          
         }
          break; 
       case second_key:
      
         if(led[2] == 1) {
            digitalWrite(second_led_pin, LOW);
            led[2] = 0;
         } else {
             digitalWrite(second_led_pin, HIGH);
             led[2] = 1;
         }
          break;
       case third_key:
      
         if(led[3] == 1) {
            digitalWrite(third_led_pin, LOW);
            led[3] = 0;
         } else {
             digitalWrite(third_led_pin, HIGH);
             led[3] = 1;
         }
          break;   
          case fourth_key:
      
         if(led[4] == 1) {       
            digitalWrite(fourth_led_pin, LOW);
            led[4] = 0;           
         } else {                      
             digitalWrite(fourth_led_pin, HIGH); 
             led[4] = 1;          
         }
          break;        
    }
    Serial.println(value); 
    receiver.resume(); 
  }
}
