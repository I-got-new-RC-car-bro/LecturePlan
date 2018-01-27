#include <SoftwareSerial.h> //시리얼통신 라이브러리 호출
 
int blueRx=2;   //Rx HC-06 -> Arduino
int blueTx=3;   //Tx Arduino -> HC-06

SoftwareSerial mySerial(blueRx, blueTx);  //시리얼 통신을 위한 객체선언
char key_value = 0;
 
void setup() 
{
  Serial.begin(9600);   //시리얼모니터
  mySerial.begin(9600); //블루투스 시리얼
}
void loop()
{
  if (mySerial.available()) {  
    key_value = mySerial.read();
    //Serial.write(key_value);  //블루투스측 내용을 시리얼모니터에 출력
    //Serial.println(" ");

    switch(key_value)
    {
      case 'S': // 정지
        Serial.println("Stop");  
        break;
        
      case 'F': // 직진
        Serial.println("Go");
        break;

      case 'B': // 후진
        Serial.println("Back");
        break;
         
      case 'L': //좌회전
        Serial.println("Left");
        break;
                
      case 'R': // 우회전
        Serial.println("Right");
        break;

        
    }
  }
  if (Serial.available()) {         
    mySerial.write(Serial.read());  //시리얼 모니터 내용을 블루추스 측에 WRITE
  
  }
}



