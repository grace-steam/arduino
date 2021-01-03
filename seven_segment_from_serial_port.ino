/*
  seven_segment_display

  1. Control 4bit seven segment display
  2. Show the number from serial port window.

  created 14 Dec 2020
  by Grace Liu

*/

int LED_A = 2;
int LED_B = 3;
int LED_C = 4;
int LED_D = 5;
int LED_E = 6;
int LED_F = 7;
int LED_G = 8;
int LED_DP = 9;
int CTL_1 = 10;
int CTL_2 = 11;
int CTL_3 = 12;
int CTL_4 = 13;
int N1, N2, N3, N4;
int i=0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(LED_A, OUTPUT);
  pinMode(LED_B, OUTPUT);
  pinMode(LED_C, OUTPUT);
  pinMode(LED_D, OUTPUT);
  pinMode(LED_E, OUTPUT);
  pinMode(LED_F, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_DP, OUTPUT);
  pinMode(CTL_1, OUTPUT);
  pinMode(CTL_2, OUTPUT);
  pinMode(CTL_3, OUTPUT);
  pinMode(CTL_4, OUTPUT);
}

void loop() {
  if (Serial.available()){
    int numin = Serial.read();
    //Serial.println(numin);
    if (numin != 10){
      //Serial.println(i);
      numin = numin - 48;
      //Serial.println(numin);
        switch(i) {
          case 0:
            N1 = numin;
            break;
          case 1:
            N2 = numin;
            break;
          case 2:
            N3 = numin;
            break;
          case 3:
            N4 = numin;
            break;         
        }
      i+=1;
    }
    else {
      i = 0;   
      Serial.print("Your number is : ");
      Serial.print(N1);
      Serial.print(N2);
      Serial.print(N3);
      Serial.println(N4);
    }
    delay(1);
  }
  setctl(LOW, HIGH, HIGH, HIGH);
  display(N1); 
  clear();

  setctl(HIGH, LOW, HIGH, HIGH);
  display(N2);
  clear();
  
  setctl(HIGH, HIGH, LOW, HIGH);
  display(N3);
  clear();

  setctl(HIGH, HIGH, HIGH, LOW);
  display(N4);
  clear();
}
void clear() {
  setctl(HIGH, HIGH, HIGH, HIGH);
  setled(LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW);
}
void setctl(char CTL1, char CTL2, char CTL3, char CTL4) {
  digitalWrite(CTL_1, CTL1);
  digitalWrite(CTL_2, CTL2);
  digitalWrite(CTL_3, CTL3);
  digitalWrite(CTL_4, CTL4);
}
void setled(int LEDA, int LEDB, int LEDC, int LEDD, int LEDE, int LEDF, int LEDG, int LEDDP){
  digitalWrite(LED_A, LEDA);
  digitalWrite(LED_B, LEDB);
  digitalWrite(LED_C, LEDC);
  digitalWrite(LED_D, LEDD);
  digitalWrite(LED_E, LEDE);
  digitalWrite(LED_F, LEDF);
  digitalWrite(LED_G, LEDG);
  digitalWrite(LED_DP, LEDDP);
}

void display(int NUM) {
  switch(NUM) {
    case 0:
      setled(1, 1, 1, 1, 1, 1, 0, 0);
      break;
    case 1:
      setled(0, 1, 1, 0, 0, 0, 0, 0);
      break;
    case 2:
      setled(1, 1, 0, 1, 1, 0, 1, 0);
      break;
    case 3:
      setled(1, 1, 1, 1, 0, 0, 1, 0);
      break;
    case 4:
      setled(0, 1, 1, 0, 0, 1, 1, 0);
      break;
    case 5:
      setled(1, 0, 1, 1, 0, 1, 1, 0);
      break;
    case 6:
      setled(1, 0, 1, 1, 1, 1, 1, 0);
      break;
    case 7:
      setled(1, 1, 1, 0, 0, 0, 0, 0);
      break;
    case 8:
      setled(1, 1, 1, 1, 1, 1, 1, 0);
      break;
    case 9:
      setled(1, 1, 1, 1, 0, 1, 1, 0);
      break;      
  } 
}
