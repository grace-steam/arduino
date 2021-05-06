int Left_motor = 8;int Left_motor_pwm = 9;int Right_motor_pwm = 10;int Right_motor = 11;
int beep = A3;
void setup() {
    pinMode(Left_motor, OUTPUT);
    pinMode(Left_motor_pwm,OUTPUT);
    pinMode(Right_motor_pwm,OUTPUT);
    pinMode(Right_motor,OUTPUT);
    pinMode(beep,OUTPUT);
}
void run(){
    digitalWrite(Right_motor,HIGH);
    digitalWrite(Right_motor_pwm,LOW);
    analogWrite(Right_motor_pwm,50);

    digitalWrite(Left_motor,HIGH);
    digitalWrite(Left_motor_pwm,LOW);
    analogWrite(Left_motor_pwm,50);
}
void loop() { 
    delay(500);
    digitalWrite(beep,LOW);
    //run();  
}
  
