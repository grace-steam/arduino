int beep = A3;
int key = A2;
int key_state1 = 0;
int key_state2 = 0;
int key_stable = 0;
int beep_state= 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(beep, OUTPUT);
  pinMode(key, INPUT);
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  key_state1 = digitalRead(A2);
  if (key_state1 != key_state2)
  {
    Serial.print("key_state1 is ");
    Serial.println(key_state1);
    Serial.print("key_state2 is ");
    Serial.println(key_state2);
    delay(20);
    key_state2 = digitalRead(A2);
    Serial.print("key_state2 after read is ");
    Serial.println(key_state2);
    if (key_state1 == key_state2)
    {
      key_stable = key_state2;   
    }
  }
  
  if (key_stable)
  {
    if (beep_state)  
    {
      digitalWrite(beep, LOW);
      beep_state = 0;
    }
    else              
    {
      digitalWrite(beep, HIGH);
      beep_state = 1;
    }
    key_stable = 0;
  }
 // delay (1000);
}
