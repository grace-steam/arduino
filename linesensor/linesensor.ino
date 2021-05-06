//=======================================================
//  小車巡線
//=======================================================
//#include <Servo.h>
int Left_motor = 8;
int Left_motor_pwm = 9;
int Right_motor_pwm = 10;
int Right_motor = 11;
int SensorRight = 3;     //右巡線感測器
int SensorLeft = 4;       //左巡線感測器
int SL;    //左巡線感測器狀態
int SR;    //右巡線感測器狀態

void setup()
{
  pinMode(Left_motor, OUTPUT); 
  pinMode(Left_motor_pwm, OUTPUT); 
  pinMode(Right_motor, OUTPUT); 
  pinMode(Right_motor_pwm, OUTPUT);
  pinMode(SensorRight, INPUT); //定義右巡線感測器狀態為輸入
  pinMode(SensorLeft, INPUT); //定義左巡線感測器狀態為輸入
}

void run(int rm, int rm_pwm, int lm, int lm_pwm, int rm_pwm2, int lm_pwm2)
{
    digitalWrite(Right_motor,rm);
    digitalWrite(Right_motor_pwm,rm_pwm);
    analogWrite(Right_motor_pwm,rm_pwm2);

    digitalWrite(Left_motor,lm);
    digitalWrite(Left_motor_pwm,lm_pwm);
    analogWrite(Left_motor_pwm,lm_pwm2);
}

void loop()
{
  // 偵測到黑線 輸出HIGH 偵測到白色區域 輸出LOW
  SR = digitalRead(SensorRight);
  // LOW表示在白色區域，車子底板上L1亮；HIGH表示在壓在黑線上，車子底板上L1滅
  SL = digitalRead(SensorLeft);
  // LOW表示在白色區域，車子底板上L2亮；HIGH表示在壓在黑線上，車子底板上L2滅
  if (SL == LOW && SR == LOW) // 左右都偵測到白色，表示車子還沒到黑線上，直走
    run(1, 0, 1, 0, 50, 50);
  else if (SL == HIGH & SR == LOW)// 右邊偵測到白色，表示車子向右偏離軌道，向左調整方向
    run(1, 0, 1, 0, 50, 25);
  else if (SL == LOW & SR == HIGH) // 左邊偵測到白色，表示車子向左偏離軌道，向右調整方向
    run(1, 0, 1, 0, 25, 50);
  else run(1, 0, 1, 0, 50, 50); // 都是黑色, 直走
}
