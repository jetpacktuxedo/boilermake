#include <SoftwareSerial.h>

#include <Servo.h> 

int thumbMin = 5;
int thumbMax = 160;
int thumbTarget = thumbMax;
int thumbPrev;

int pointerMin = 10;
int pointerMax = 160;
int pointerTarget = pointerMax;
int pointerPrev;

int middleMin = 10;
int middleMax = 165;
int middleTarget = middleMax;
int middlePrev;

int ringMin = 60;
int ringMax = 140;
int ringTarget = ringMax;
int ringPrev;

int pinkyMin = 70;
int pinkyMax = 160;
int pinkyTarget = pinkyMax;
int pinkyPrev;

Servo thumb, pointer, middle, ring, pinky;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created 
 
int pos = 0;    // variable to store the servo position 
 
void setup() 
{ 
  thumb.attach(8);  // attaches the servo on pin 9 to the servo object 
  pointer.attach(7);
  middle.attach(6);
  ring.attach(5);
  pinky.attach(4);
   Serial.begin(9600);
}

void loop() 
{ 
  /*
  updateFingers();
  
  if (thumb.read() <= thumbMin) setThumb(thumbMax);
  else if (thumb.read() >= thumbMax) setThumb(thumbMin);
  
  if (pointer.read() <= pointerMin) setPointer(pointerMax);
  else if (pointer.read() >= pointerMax) setPointer(pointerMin);
  
  if (middle.read() <= middleMin) setMiddle(middleMax);
  else if (middle.read() >= middleMax) setMiddle(middleMin);
  
  if (ring.read() <= ringMin) setRing(ringMax);
  else if (ring.read() >= ringMax) setRing(ringMin);
  
  if (pinky.read() <= pinkyMin) setPinky(pinkyMax);
  else if (pinky.read() >= pinkyMax) setPinky(pinkyMin);
  
  Serial.println(pinky.read());
  */
 // Serial.println("helloworld");
  
  closeAll();
//  closePinky();
//  closeRing();
//  closeMiddle();
//  closePointer();
//  //closeThumb();
  delay(500);
  openAll();
//  
//  //openThumb();
//  openPointer();
//  openMiddle();
//  openRing();
//  openPinky();
  delay(500);
} 

void setThumb(int target){
  if (target <= thumbMax && target >= thumbMin) thumbTarget = target;
}

void setPointer(int target){
  if (target <= pointerMax && target >= pointerMin) pointerTarget = target;
}

void setMiddle(int target){
  if (target <= middleMax && target >= middleMin) middleTarget = target;
}

void setRing(int target){
  if (target <= ringMax && target >= ringMin) ringTarget = target;
}

void setPinky(int target){
  if (target <= pinkyMax && target >= pinkyMin) pinkyTarget = target;
}

void updateFingers(){
  thumbPrev = thumb.read();
  if(thumb.read() > thumbTarget) thumb.write(thumb.read() - 1);
  else if (thumb.read() < thumbTarget)  thumb.write(thumb.read() + 1);
  if (thumbPrev = thumb.read()) setThumb(thumbMin);
  
  pointerPrev = pointer.read();
  if(pointer.read() > pointerTarget) pointer.write(pointer.read() - 1);
  else if (pointer.read() < pointerTarget)  pointer.write(pointer.read() + 1);
  if (pointerPrev = pointer.read()) setPointer(pointerMin);
  
  middlePrev = middle.read();
  if(middle.read() > middleTarget) middle.write(middle.read() - 1);
  else if (middle.read() < middleTarget)  middle.write(middle.read() + 1);
  if (middlePrev = middle.read()) setMiddle(middleMin);
  
  ringPrev = ring.read();
  if(ring.read() > ringTarget) ring.write(ring.read() - 1);
  else if (ring.read() < ringTarget)  ring.write(ring.read() + 1);
  if (ringPrev = ring.read()) setRing(ringMin);
  
  pinkyPrev = pinky.read();
  if(pinky.read() > pinkyTarget) pinky.write(pinky.read() - 1);
  else if (pinky.read() < pinkyTarget)  pinky.write(pinky.read() + 1);
  if (pinkyPrev = pinky.read()) setPinky(pinkyMin);
}

void openAll(){
  for (pos = 0; pos < 180; pos +=1){
    if (pos < thumbMax && pos > thumbMin) thumb.write(pos);
    if (pos < pointerMax && pos > pointerMin) pointer.write(pos);
    if (pos < middleMax && pos > middleMin) middle.write(pos);
    if (pos < ringMax && pos > ringMin) ring.write(pos);
    if (pos < pinkyMax && pos > pinkyMin) pinky.write(pos);
    delay(3);
  }
}
void openThumb(){
  for(pos = thumbMin; pos < thumbMax; pos += 1)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    thumb.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(3);                       // waits 15ms for the servo to reach the position 
  }
}

void openPointer(){
  for(pos = pointerMin; pos < pointerMax; pos += 1)  // goes from 0 degrees to 180 degrees 
  {
    pointer.write(pos);
    delay(2);                       // waits 15ms for the servo to reach the position 
  } 
}

void openMiddle(){
  for(pos = middleMin; pos < middleMax; pos += 1)  // goes from 0 degrees to 180 degrees 
  {
    middle.write(pos);
    delay(2);                       // waits 15ms for the servo to reach the position 
  } 
}

void openRing(){
  for(pos = ringMin; pos < ringMax; pos += 1)  
  {
    ring.write(pos);
    delay(2);                       // waits 15ms for the servo to reach the position 
  }
}

void openPinky(){
   for(pos = pinkyMin; pos < pinkyMax; pos += 1)  
  {
    pinky.write(pos);
    delay(3);                       
  } 
}

void closeAll(){
  for (pos = 180; pos > 0; pos -=1){
    if (pos < thumbMax && pos > thumbMin) thumb.write(pos);
    if (pos < pointerMax && pos > pointerMin) pointer.write(pos);
    if (pos < middleMax && pos > middleMin) middle.write(pos);
    if (pos < ringMax && pos > ringMin) ring.write(pos);
    if (pos < pinkyMax && pos > pinkyMin) pinky.write(pos);
  }
}
void closeThumb(){
  for(pos = thumbMax; pos > thumbMin; pos -= 1)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    thumb.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(3);                       // waits 15ms for the servo to reach the position 
  }
}

void closePointer(){
  for(pos = pointerMax; pos > pointerMin; pos -=1)     // goes from 180 degrees to 0 degrees 
  {                                
    pointer.write(pos);
    delay(3);                       // waits 15ms for the servo to reach the position 
  } 
}

void closeMiddle(){
  for(pos = middleMax; pos > middleMin; pos -= 1)  // goes from 0 degrees to 180 degrees 
  {
    middle.write(pos);
    delay(2);                       // waits 15ms for the servo to reach the position 
  } 
}

void closeRing(){
  for(pos = ringMax; pos > ringMin; pos -= 1)  // goes from 0 degrees to 180 degrees 
  {
    ring.write(pos);
    delay(3);                       // waits 15ms for the servo to reach the position 
  } 
}

void closePinky(){
  for(pos = pinkyMax; pos > pinkyMin; pos -= 1)  // goes from 0 degrees to 180 degrees 
  {
    pinky.write(pos);
    delay(3);                       // waits 15ms for the servo to reach the position 
  } 
}
