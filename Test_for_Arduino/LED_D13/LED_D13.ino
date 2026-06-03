const int ledPin = 13;  
int brightness = 0;     // LED亮度值（0-255）
int fadeAmount = 1;     // 每次变化的步进值

void setup() {
  pinMode(ledPin, OUTPUT);  // 设置引脚为输出模式
}

void loop() {
  analogWrite(ledPin, brightness);  // 输出PWM信号控制亮度
  
  brightness += fadeAmount;  // 更新亮度值
  
  // 到达亮度边界时反转变化方向
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }
  
  delay(10);  // 短暂延时，控制呼吸速度
}