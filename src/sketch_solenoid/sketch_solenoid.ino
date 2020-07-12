/*
 * Arduino Uno sketch to show how it can be used as a speed controller for
 * driving a solenoid
 */


/* 
 *  this is the pwm digital pin 2 in this example
 */
#define MOSFET_PIN 2
/* This is the A0 pin which will be used 
 *  to get the value for the speed
 */
#define SENSOR_PIN 0
/*
 * The number of steps for the speed control
 */
#define QUANTIZATION_FACTOR 100
void setup() {
  // uncomment if you want to use the serial monitor on your computer
  Serial.begin(115200);
  // tell thje arduino that the mosfet pin is an output
  pinMode(MOSFET_PIN, OUTPUT);

}

void loop() {
/*
 * grab the value from the sensor pin and map it to the quantization factor.
 * In this example there will be 100 different speed values
 * pot_value is the mapped potentiometer value
 */
  int pot_value = map(analogRead(SENSOR_PIN),0,1023, 1, QUANTIZATION_FACTOR);
 
 //uncomment if you want to see the values of the potentiometer in the serial monitor
  Serial.print( pot_value);
  Serial.print( "\n");
/*
 * if the mapped potentiometer value is in the range
 * 0 to 99 then write to the 
 */
  if(pot_value < 100 ){
   Serial.print( "About to write high");
    digitalWrite(MOSFET_PIN, HIGH);
    // this is to give the solenoid time to act
    delay(15);
    
    digitalWrite(MOSFET_PIN, LOW);
    //this is the speed control here. it also determins the duty cycle for the solenoid
    delay(pot_value + 20);
  }else
  {
    // if its out of the 0 - 99 range ensure that the mosfet is low 
    digitalWrite(MOSFET_PIN, LOW);
    delay(pot_value + 20);
  }
  
}
