int white = 0b000;
int red = 0b011;
int green = 0b101;
int blue = 0b110;
int yellow = 0b001;
int magenta = 0b010;
//färgkoder RGB för färgerna, gemensam anod
int latchPin = 8;
int clockPin = 12;
int dataPin = 11;
//pins för utdata;
int incomingByte = 0;
int cells[] = {white,white,white,white,white,white,white,white,white,
               red,red,red,red,red,red,red,red,red,
               green,green,green,green,green,green,green,green,green,
               magenta,magenta,magenta,magenta,magenta,magenta,magenta,magenta,magenta,
               blue,blue,blue,blue,blue,blue,blue,blue,blue,
               yellow,yellow,yellow,yellow,yellow,yellow,yellow,yellow,yellow}
int shiftreg[] = new int[27];
//arrayer för celler och skiftregister, där varje cell innehåller färgkoden för dess färg
void setup() {
  applychange();
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  //anger läget för udatapins
  Serial.begin(9600);
  
}
void loop() {

  if(Serial.available() > 0){
    incomingByte = Serial.read();
  }
// take the latchPin low so
// the LEDs don't change while you're sending in bits:
digitalWrite(latchPin, LOW);
// shift out the bits:
shiftOut(dataPin, clockPin, MSBFIRST, data);
//take the latch pin high so the LEDs will light up:
digitalWrite(latchPin, HIGH);

}


void rotateR(int arrin[], bool inverted){
  if(!inverted){
    
  }
  else{
    
}
void applychange(){ //uppdaterar skiftregister efter cellers tillstånd
  for(int i = 0; i < 28; i++){
    shiftreg[i] = ((cells[i*2] << 3) + cells[i*2+1]) << 2;
  }
}
