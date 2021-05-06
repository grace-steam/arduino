#include <IRremote.h>

void setup() {
  Serial.begin(115200);
  //IrReceiver.begin(A4, ENABLE_LED_FEEDBACK);
  IrReceiver.begin(A4); // 設定紅外線接收的腳位
}

void loop() {
  if(IrReceiver.decode()) // 紅外線接收到資料解碼
  {
    Serial.println(IrReceiver.decodedIRData.command, HEX); //把紅外線收到的資料用16進位方式印出來 
    IrReceiver.resume(); // 繼續接收下一筆
  }
}
