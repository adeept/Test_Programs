
#define OLED_I2C_ADDR 0x3C
#include <SSD1306AsciiWire.h>
SSD1306AsciiWire oled;

void OLED_Setup() 
{
  Wire.begin();
  oled.begin(&Adafruit128x64, OLED_I2C_ADDR);
  oled.setFont(Adafruit5x7);
  oled.clear();
}
  
void OLED_clear()
{
  oled.clear();
}
  
void OLED_test()
{
  oled.clear();
  oled.invertDisplay(true); 
}

void OLED_recover()
{
  oled.invertDisplay(false); 
}

void OLED(int font, int x, int y, char text[])
{
  if(font == 1){
    oled.set1X();
  } else {
    oled.set2X();
  }
  
  oled.setCursor(x,y); // (x,y)
  oled.print(text);
  oled.println(); 
}


String comdata = "";

void setup()
{
  Serial.begin(115200);       // set up a wifi serial communication baud rate 115200

  Serial.println("AT+CWMODE=3\r\n");//set to softAP+station mode
  delay(3000);     
  Serial.println("AT+CWSAP=\"Adeept_ESP8266_Test\",\"12345678\",8,2\r\n");   //TCP Protocol, server IP addr, port
  delay(1000);     
  Serial.println("AT+RST\r\n");     //reset wifi
  delay(1000);    
  Serial.println("AT+CIPMUX=1\r\n");//set to multi-connection mode
  delay(1000);
  Serial.println("AT+CIPSERVER=1,4000\r\n");//set as server
  delay(1000);
  Serial.println("AT+CIPSTO=7000\r\n");//keep the wifi connecting 7000 seconds
  delay(1000);

  OLED_Setup();                //OLED initialization
  OLED_test();

}

void loop()
{
   while(Serial.available()>0)
   {  
    comdata += char(Serial.read());
   }
  //  Serial.println(comdata);
   OLED_clear();
   OLED(1, 0, 2, comdata.c_str());
   delay(1000);
   comdata = "";
}
