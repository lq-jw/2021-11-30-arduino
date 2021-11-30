#include <BluetoothSerial.h>
BluetoothSerial BT;
int ledPin = 12;
int ledPinb = 13;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  BT.begin("doudouTestEsp32");//請改名
}

void loop() {
  // put your main code here, to run repeatedly:
  while (BT.available()) {
    //讀取藍芽資料
    String BTdata=BT.readString();
    //顯示在序列視窗
    Serial.println(BTdata);
    if(BTdata=="a"){
           digitalWrite(ledPin,HIGH);
      }
          if(BTdata=="b"){
           digitalWrite(ledPinb,HIGH);
      }

  }
  delay(1);
}
