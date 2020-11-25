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
int cells[] = {white,white,white,white,white,white,white,white,white,
               red,red,red,red,red,red,red,red,red,
               green,green,green,green,green,green,green,green,green,
               magenta,magenta,magenta,magenta,magenta,magenta,magenta,magenta,magenta,
               blue,blue,blue,blue,blue,blue,blue,blue,blue,
               yellow,yellow,yellow,yellow,yellow,yellow,yellow,yellow,yellow}
int shiftreg[] = new int[27];
//arrayer för celler och skiftregister, där varje cell innehåller färgkoden för dess färg
//cellpositioner: https://docs.google.com/spreadsheets/d/1I1vEZkltXm3n-aRes2yo80VTgN-QR8bWqV914L8BkHc/edit#gid=0
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
    
    arrin[7] = cells[19];
    arrin[8] = cells[24];
    arrin[9] = cells[25];
    
    arrin[41] = cells[7];
    arrin[42] = cells[8];
    arrin[45] = cells[9];
    
    arrin[46] = cells[45];
    arrin[47] = cells[42];
    arrin[48] = cells[41];
    
    arrin[19] = cells[48];
    arrin[24] = cells[47];
    arrin[25] = cells[46];
    
    arrin[12] = cells[18];
    arrin[11] = cells[13];
    arrin[10] = cells[12];
    arrin[15] = cells[11];
    arrin[16] = cells[10];
    arrin[17] = cells[15];
    arrin[18] = cells[16];
    arrin[13] = cells[17];
    
  } else{
    arrin[19] = cells[7];
    arrin[24] = cells[8];
    arrin[25] = cells[9];
    
    arrin[7] = cells[41];
    arrin[8] = cells[42];
    arrin[9] = cells[45];
    
    arrin[45] = cells[46];
    arrin[42] = cells[47];
    arrin[41] = cells[48];
    
    arrin[48] = cells[19];
    arrin[47] = cells[24];
    arrin[46] = cells[25];
    
    arrin[18] = cells[12];
    arrin[13] = cells[11];
    arrin[12] = cells[10];
    arrin[11] = cells[15];
    arrin[10] = cells[16];
    arrin[15] = cells[17];
    arrin[16] = cells[18];
    arrin[17] = cells[13];
  }
  
  for(int i = 0; i < 54; i++){
    
    cells[i] = arrin[i];
    
  }
}

void rotateW(int arrin[], bool inverted){
  
  if(!inverted){
    
    arrin[28] = cells[25];
    arrin[29] = cells[26];
    arrin[30] = cells[27];
    
    arrin[25] = cells[10];
    arrin[26] = cells[11];
    arrin[27] = cells[12];
    
    arrin[12] = cells[41];
    arrin[11] = cells[40];
    arrin[10] = cells[39];
    
    arrin[39] = cells[28];
    arrin[40] = cells[29];
    arrin[41] = cells[30];
    
    arrin[1] = cells[7];
    arrin[2] = cells[6];
    arrin[3] = cells[1];
    arrin[4] = cells[2];
    arrin[6] = cells[8];
    arrin[7] = cells[9];
    arrin[8] = cells[4];
    arrin[9] = cells[3];
    
  } else{
    
    arrin[25] = cells[28];
    arrin[26] = cells[29];
    arrin[27] = cells[30];
    
    arrin[10] = cells[25];
    arrin[11] = cells[26];
    arrin[12] = cells[27];
    
    arrin[41] = cells[12];
    arrin[40] = cells[11];
    arrin[39] = cells[10];
    
    arrin[28] = cells[39];
    arrin[29] = cells[40];
    arrin[30] = cells[41];
    
    arrin[7] = cells[1];
    arrin[6] = cells[2];
    arrin[1] = cells[3];
    arrin[2] = cells[4];
    arrin[8] = cells[6];
    arrin[9] = cells[7];
    arrin[4] = cells[8];
    arrin[3] = cells[9];
    
  }
  
  for(int i = 0; i < 54; i++){
    
    cells[i] = arrin[i];
    
  }
}

void applychange(){
  for(int i = 0; i < 28; i++){
    shiftreg[i] = ((cells[i*2] << 3) + cells[i*2+1]) << 2;
  }
}
