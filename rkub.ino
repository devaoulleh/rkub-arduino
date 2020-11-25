int white = 0b111;
int red = 0b100;
int green = 0b010;
int blue = 0b001;
int yellow = 0b110;
int magenta = 0b101;

int latchPin = 8;
int clockPin = 12;
int dataPin = 11;
int cells[] = new int[54];
void setup() {
//set pins to output so you can control the shift register
pinMode(latchPin, OUTPUT);
pinMode(clockPin, OUTPUT);
pinMode(dataPin, OUTPUT);
}
void loop() {
// count from 0 to 255 and display the number
// on the LEDs
int data = 0b01110100;
// take the latchPin low so
// the LEDs don't change while you're sending in bits:
digitalWrite(latchPin, LOW);
// shift out the bits:
shiftOut(dataPin, clockPin, MSBFIRST, data);
//take the latch pin high so the LEDs will light up:
digitalWrite(latchPin, HIGH);
// pause before next value:
delay(500);

}

int appenddata(int data, int data2){
  data = (data << 3) + data2;
  return data;
}
void rotateR(int arrin[], bool inverted){
  if(inverted){
    
  }
  else{
    
}
