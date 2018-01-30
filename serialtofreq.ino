/*
  Software serial to frequency generator

  This is based on Tom Igoe's software serial example, but with buffering of
  sent data until the terminating carriage return (CR / 0xD / '\r'), so that
  all the TX data goes out in a block with the characters close together.

 This example code is in the public domain.

 */
#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // RX, TX

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  // set the data rate for the SoftwareSerial port
  mySerial.begin(9600);
}

char buf[40];
int count=0;

void loop() { // run over and over
  if (mySerial.available()) {
    Serial.write(mySerial.read());
  }
  if (Serial.available()) {
    char ch = Serial.read();
    if(ch=='\r'){
      buf[count]=0;
      mySerial.print(buf);
      count = 0;   
    }else if(ch=='\n'){
      ;   
    }else{
      buf[count++] = ch;
    }
  }

}


