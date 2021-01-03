int WaterPin = 0;
int SensorValue = 0;
int AlertValue = 300;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  SensorValue = analogRead(0);
  Serial.println(SensorValue);

  if (SensorValue > AlertValue)
  {
    Serial.println("High water level");
  }
  delay(1000);
}
