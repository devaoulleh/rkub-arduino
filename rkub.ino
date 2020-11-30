/*
ccl: w1, r3, b5, g7, y9, m11
cl:  2,  4,  6,  8,  10, 12
shuffle: 13
reset: 14
*/
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
int cells[] = {0, 
               white,white,white,white,white,white,white,white,white,
               red,red,red,red,red,red,red,red,red,
               green,green,green,green,green,green,green,green,green,
               magenta,magenta,magenta,magenta,magenta,magenta,magenta,magenta,magenta,
               blue,blue,blue,blue,blue,blue,blue,blue,blue,
               yellow,yellow,yellow,yellow,yellow,yellow,yellow,yellow,yellow}
int shiftreg[] = new int[27];
//arrayer för celler och skiftregister, där varje cell innehåller färgkoden för dess färg

//cellpositioner: https://docs.google.com/spreadsheets/d/1I1vEZkltXm3n-aRes2yo80VTgN-QR8bWqV914L8BkHc/edit#gid=0

void setup() {
  
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  //anger läget för utdatapins
  Serial.begin(9600);
  applychange();
}
void loop() {

  if(Serial.available() > 0){
    incomingByte = Serial.read();
  } else incomingByte = 0;
  


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

void rotateG(int arrin[], bool inverted){
  
  if(!inverted){
    
    arrin[1] = cells[34];
    arrin[6] = cells[33];
    arrin[7] = cells[28];
    
    arrin[12] = cells[1];
    arrin[13] = cells[6];
    arrin[18] = cells[7];
    
    arrin[46] = cells[12];
    arrin[51] = cells[13];
    arrin[52] = cells[18];
    
    arrin[34] = cells[46];
    arrin[33] = cells[51];
    arrin[28] = cells[52];
    
    arrin[27] = cells[21];
    arrin[26] = cells[22];
    arrin[25] = cells[27];
    arrin[24] = cells[26];
    arrin[19] = cells[25];
    arrin[20] = cells[24];
    arrin[21] = cells[19];
    arrin[22] = cells[20];
    
  } else{
    
    arrin[34] = cells[1];
    arrin[33] = cells[6];
    arrin[28] = cells[7];
    
    arrin[1] = cells[12];
    arrin[6] = cells[13];
    arrin[7] = cells[18];
    
    arrin[12] = cells[46];
    arrin[13] = cells[51];
    arrin[18] = cells[52];
    
    arrin[46] = cells[34];
    arrin[51] = cells[33];
    arrin[52] = cells[28];
    
    arrin[21] = cells[27];
    arrin[22] = cells[26];
    arrin[27] = cells[25];
    arrin[26] = cells[24];
    arrin[25] = cells[19];
    arrin[24] = cells[20];
    arrin[19] = cells[21];
    arrin[20] = cells[22];
    
  }
  
  for(int i = 0; i < 54; i++){
    
    cells[i] = arrin[i];
    
  }
}

void rotateB(int arrin[], bool inverted){
  
  if(!inverted){
    
    arrin[9] = cells[16];
    arrin[4] = cells[15];
    arrin[3] = cells[10];
    
    arrin[30] = cells[9];
    arrin[31] = cells[4];
    arrin[36] = cells[3];
    
    arrin[54] = cells[30];
    arrin[49] = cells[31];
    arrin[48] = cells[36];
    
    arrin[16] = cells[54];
    arrin[15] = cells[49];
    arrin[10] = cells[48];
    
    arrin[41] = cells[45];
    arrin[40] = cells[42];
    arrin[39] = cells[41];
    arrin[38] = cells[40];
    arrin[37] = cells[39];
    arrin[44] = cells[38];
    arrin[45] = cells[37];
    arrin[42] = cells[44];
    
  } else{
    
    arrin[9] = cells[30];
    arrin[4] = cells[31];
    arrin[3] = cells[36];
    
    arrin[30] = cells[54];
    arrin[31] = cells[49];
    arrin[36] = cells[48];
    
    arrin[54] = cells[16];
    arrin[49] = cells[15];
    arrin[48] = cells[10];
    
    arrin[16] = cells[9];
    arrin[15] = cells[4];
    arrin[10] = cells[3];
    
    arrin[41] = cells[39];
    arrin[40] = cells[38];
    arrin[39] = cells[37];
    arrin[38] = cells[44];
    arrin[37] = cells[45];
    arrin[44] = cells[42];
    arrin[45] = cells[41];
    arrin[42] = cells[40];
    
  }
  
  for(int i = 0; i < 54; i++){
    
    cells[i] = arrin[i];
    
  }
}

void rotateM(int arrin[], bool inverted){
  
  if(!inverted){
    
    arrin[3] = cells[37];
    arrin[2] = cells[38];
    arrin[1] = cells[39];
    
    arrin[27] = cells[3];
    arrin[22] = cells[2];
    arrin[21] = cells[1];
    
    arrin[52] = cells[27];
    arrin[53] = cells[22];
    arrin[54] = cells[21];
    
    arrin[37] = cells[52];
    arrin[38] = cells[53];
    arrin[39] = cells[54];
    
    arrin[30] = cells[36];
    arrin[29] = cells[31];
    arrin[28] = cells[30];
    arrin[33] = cells[29];
    arrin[34] = cells[28];
    arrin[35] = cells[33];
    arrin[36] = cells[34];
    arrin[31] = cells[35];
    
  } else{
    
    arrin[3] = cells[27];
    arrin[2] = cells[22];
    arrin[1] = cells[21];
    
    arrin[27] = cells[52];
    arrin[22] = cells[53];
    arrin[21] = cells[54];
    
    arrin[52] = cells[37];
    arrin[53] = cells[38];
    arrin[54] = cells[39];
    
    arrin[37] = cells[3];
    arrin[38] = cells[2];
    arrin[39] = cells[1];
    
    arrin[30] = cells[28];
    arrin[29] = cells[33];
    arrin[28] = cells[34];
    arrin[33] = cells[35];
    arrin[34] = cells[36];
    arrin[35] = cells[31];
    arrin[36] = cells[30];
    arrin[31] = cells[29];
    
  }
  
  for(int i = 0; i < 54; i++){
    
    cells[i] = arrin[i];
    
  }
}

void rotateY(int arrin[], bool inverted){
  
  if(!inverted){
    
    arrin[18] = cells[21];
    arrin[17] = cells[20];
    arrin[16] = cells[19];
    
    arrin[45] = cells[18];
    arrin[44] = cells[17];
    arrin[37] = cells[16];
    
    arrin[36] = cells[45];
    arrin[35] = cells[44];
    arrin[34] = cells[37];
    
    arrin[21] = cells[36];
    arrin[20] = cells[35];
    arrin[19] = cells[34];
    
    arrin[46] = cells[52];
    arrin[47] = cells[51];
    arrin[48] = cells[46];
    arrin[49] = cells[47];
    arrin[54] = cells[48];
    arrin[53] = cells[49];
    arrin[52] = cells[54];
    arrin[51] = cells[53];
    
  } else{
    
    arrin[18] = cells[45];
    arrin[17] = cells[44];
    arrin[16] = cells[37];
    
    arrin[45] = cells[36];
    arrin[44] = cells[35];
    arrin[37] = cells[34];
    
    arrin[36] = cells[21];
    arrin[35] = cells[20];
    arrin[34] = cells[19];
    
    arrin[21] = cells[18];
    arrin[20] = cells[17];
    arrin[19] = cells[16];
    
    arrin[46] = cells[48];
    arrin[47] = cells[49];
    arrin[48] = cells[54];
    arrin[49] = cells[53];
    arrin[54] = cells[52];
    arrin[53] = cells[51];
    arrin[52] = cells[46];
    arrin[51] = cells[47];
    
  }
  
  for(int i = 1; i <= 54; i++){
    
    cells[i] = arrin[i];
    
  }
}

void shuffle(){
  for(int i = 0; i < 100;i++){
    ran = (int)random(1,12);
    if(ran == 1){
      rotateW(cells, true);
    }else if(ran == 2){
      rotateW(cells,false);
    }else if(ran == 3){
      rotateR(cells, true);
    }else if(ran == 4){
      rotateR(cells, false);
    }else if(ran == 5){
      rotateB(cells, true);
    }else if(ran == 6){
      rotateB(cells, false);
    }else if(ran == 7){
      rotateG(cells, true);
    }else if(ran == 8){
      rotateG(cells, false);
    }else if(ran == 9){
      rotateY(cells, true);
    }else if(ran == 10){
      rotateY(cells, false);
    }else if(ran == 11){
      rotateM(cells, true);
    }else if(ran == 12){
      rotateM(cells, false);
    }
  }
}

void applychange(){ //uppdaterar skiftregister efter cellers tillstånd
  for(int i = 0; i < 27; i++){
    shiftreg[i] = ((cells[i*2+1] << 3) + cells[i*2+2]) << 2;
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, shiftreg[i]);
    digitalWrite(latchPin, HIGH);
  }
  
}
