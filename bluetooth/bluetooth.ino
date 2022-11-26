#include <SoftwareSerial.h>
// Bluetoothモジュールとはソフトウェアシリアルで通信。
// TXD-(Arduino)D2,RXD-(Arduino)D3に接続。
// ArduinoからのTXは分圧してBluetoothモジュールのRXDに接続。

SoftwareSerial BTserial(2, 3); // RX,TX

void setup() {
  Serial.begin(9600);
  Serial.println("AT コマンドを入力 :");

  // HC-05のデフォルトでのボーレートは38400
  // HC-06のデフォルトのボーレートは9600
  BTserial.begin(38400);
}

void loop() {
  // HC-05(HC-06)から読み取りシリアルモニタに送信する
  if (BTserial.available()) {
    Serial.write(BTserial.read());
  }

  // シリアルモニタからのデータを読み取りHC-05(HC-06)に送信する
  if (Serial.available()) {
    auto str = Serial.read();
    Serial.write(str);
    BTserial.write(str);
  }
}