#include <Servo.h>

Servo myservo; 
int pos = 0;

//Echo food tank pin 3  EFT
//Trig food tank pin 2  TFT
//Servo pin 4           S_P
//R1 pin 5              TR
//G1 pin 6              TG
//G2 pin 7              BG
//R2 pin 8              BR
//Pet detector trig A5  PDT
//Pet detector echo A4  PDE
//Water pump pin 9      WP
//Water tank ECHO pin A1
//Water Tank Trig pin A0
//Food bowl trig pin 11
//Food bowl Echo pin10
//Water bowl Trig pin 
//Water bowl Echo pin
int EFT=3;
int TFT=2;
int S_P=4;
int TR=5;
int TG=6;
int BG=7;
int BR=8;
int WP=9;
int PDT=A5;
int PDE=A4;
int fbt=11;
int fbe=10;
int wbt=A3;
int wbe=A2;
int WTT=A0;
int WTE=A1;
long duration ,duration1,duration2,duration3,duration4 ,cm , inches,cmfb ,cmwb,cmbt,cmwt,inchesfb,incheswb,incheswt,inchesbt;

void setup() {
Serial.begin (9600);
digitalWrite(TR,LOW);
digitalWrite(BG,LOW);
digitalWrite(TG,LOW);
digitalWrite(BR,LOW);
pinMode(TFT,OUTPUT);
pinMode(EFT,INPUT);
pinMode(PDT,OUTPUT);
pinMode(PDE,INPUT);
pinMode(SP,OUTPUT);
pinMode(TR,OUTPUT);
pinMode(BR,OUTPUT);
pinMode(TG,OUTPUT);
pinMode(BG,OUTPUT);
pinMode(WP,OUTPUT);
pinMode(WTT,OUTPUT);
pinMode(WTE,INPUT);
pinMode(wbt,OUTPUT);
pinMode(wbe,INPUT);
pinMode(fbt,OUTPUT);
pinMode(fbe,INPUT);
myservo.attach(4);

}

void loop() {
digitalWrite(PDT,LOW);
delayMicroseconds(5);
digitalWrite(PDT,HIGH);
delayMicroseconds(10);
digitalWrite(PDT,LOW);
duration = pulseIn(PDE,HIGH);
cm = (duration/2)/29.1;
inches = ((duration/2)/74);
Serial.print(inches);
Serial.print("in, ");
Serial.print(cm);
Serial.print("cm ");
Serial.println();


digitalWrite(TFT,LOW);
delayMicroseconds(5);
digitalWrite(TFT,HIGH);
delayMicroseconds(10);
digitalWrite(TFT,LOW);
duration1 = pulseIn(EFT,HIGH);
cmbt = (duration1/2)/29.1;
inchesbt = ((duration1/2)/74);
Serial.print(inchesbt);
Serial.print("btheheheheein, ");
Serial.print(cmbt);
Serial.print("bthehehhecm ");
Serial.println();

digitalWrite(WTT,LOW);
delayMicroseconds(5);
digitalWrite(WTT,HIGH);
delayMicroseconds(10);
digitalWrite(WTT,LOW);
duration2 = pulseIn(WTE,HIGH);
cmwt = (duration2/2)/29.1;
incheswt = ((duration2/2)/74);
Serial.print(incheswt);
Serial.print("wtin, ");
Serial.print(cmwt);
Serial.print("wtcm ");
Serial.println();

  digitalWrite(fbt,LOW);
delayMicroseconds(5);
digitalWrite(fbt,HIGH);
delayMicroseconds(10);  
digitalWrite(fbt,LOW);
duration3 = pulseIn(fbe,HIGH);
cmfb = (duration3/2)/29.1;
inchesfb = ((duration3/2)/74);
Serial.print(inchesfb);
Serial.print("fbin, ");
Serial.print(cmfb);
Serial.print("fbcm ");
Serial.println();

digitalWrite(wbt,LOW);
delayMicroseconds(5);
digitalWrite(wbt,HIGH);
delayMicroseconds(10);
digitalWrite(wbt,LOW);
duration4 = pulseIn(wbe,HIGH);
cmwb = (duration4/2)/29.1;
incheswb = ((duration4/2)/74);
Serial.print(incheswb);
Serial.print("wbin, ");
Serial.print(cmwb);
Serial.print("wbcm ");
Serial.println();
if(cm<18)
{



     if(cmwb>13){
     digitalWrite(WP,HIGH);
     delay(3000);
     digitalWrite(WP,LOW);}
        if(cmfb>13){
       for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15); 
    delay(150);                      // waits 15 ms for the servo to reach the position
  }
    }
    if(cmwt>27){
    digitalWrite(TG,HIGH);
    digitalWrite(TR,LOW);
    }
    else{}
    digitalWrite(TR,HIGH);
    digitalWrite(TG,LOW);}
    if(cmbt>14){
    digitalWrite(BG,HIGH);digitalWrite(BR,LOW); }
    else{
    digitalWrite(BG,LOW);digitalWrite(BR,HIGH); 

    }
}
