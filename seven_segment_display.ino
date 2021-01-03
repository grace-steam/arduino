/*
  seven_segment_display

  Control 4bit seven segment display

  created 13 Dec 2020
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

void setup() {
  // put your setup code here, to run once:
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
  // put your main code here, to run repeatedly:

  setctl(LOW, HIGH, HIGH, HIGH);
  setled(LOW, HIGH, HIGH, LOW, LOW, LOW, LOW, LOW);
  clear();

  setctl(HIGH, LOW, HIGH, HIGH);
  setled(HIGH, HIGH, LOW, HIGH, HIGH, LOW, HIGH, LOW);
  clear();
  
  setctl(HIGH, HIGH, LOW, HIGH);
  setled(HIGH, HIGH, HIGH, HIGH, LOW, LOW, HIGH, LOW);
  clear();

  setctl(HIGH, HIGH, HIGH, LOW);
  setled(LOW, HIGH, HIGH, LOW, LOW, HIGH, HIGH, LOW);
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
