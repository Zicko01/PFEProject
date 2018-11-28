#include <PID_v1.h>
#include <stdint.h>
#include <Servo.h>

//x motoru proslediti PIDY i obrnuto

double Setpointx=300, Inputx, Outputx;//300
double Setpointy=225, Inputy, Outputy;//225
double Kpx = 0.3;                                                     
double Kix = 0.05;                                                      
double Kdx = 0.035;

double Kpy = 0.3;                                                       
double Kiy = 0.09;                                                  
double Kdy = 0.03;

PID PIDX(&Inputx, &Outputx, &Setpointx, Kpx, Kix, Kdx, DIRECT);
PID PIDY(&Inputy, &Outputy, &Setpointy, Kpy, Kiy, Kdy, REVERSE);
Servo servo1,servo2;

int angle = 0;
void postavi()
{
  servo1.write(110);
  servo2.write(100);
}


void setup()
{
  Serial.begin(9600);
  Serial.setTimeout(10);
  servo1.attach(9);
  servo2.attach(6);
  postavi();
  
  PIDX.SetMode(AUTOMATIC);
  PIDX.SetOutputLimits(-80,80);
  PIDY.SetMode(AUTOMATIC);
  PIDY.SetOutputLimits(-70,70);
  PIDX.SetSampleTime(10);
  PIDY.SetSampleTime(10);
  delay(100);
}
int x,y;
String inString,String1,String2;
int i;
String sx="",sy="";
void loop()
{

 while(Serial.available()>0)
 {
  
  inString=Serial.readString();
  String primljen=inString;
   int i;
    for (i = 0; primljen[i] != ','; i++)
      sx += primljen[i];
    i++;
    for (; primljen[i]!='.';i++)
    sy+=primljen[i];
    
    x=sx.toInt();
    y=sy.toInt();
  
    //Serial.println(x);
    //Serial.println(y);
    sx="";
    sy="";
  if(x!=0&&y!=0)
  {
  Inputx=x;
  Inputy=y;
  PIDX.Compute();
  PIDY.Compute();
  servo1.write(110+Outputy);//110+Outputy
  servo2.write(100+Outputx);
  }   
  else
 {
  servo1.write(110);
  servo2.write(100);
 }
 /*
 x=String1.toInt();
 y=String2.toInt();//+90
if(x!=0&&y!=0)
 {
  Inputx=x;
  Inputy=y;
  PIDX.Compute();
  PIDY.Compute();
*/



//servo1.write(110+Outputy);//110+Outputy
//servo2.write(100+Outputx);
//100+Outputx
 }
/* else
 {
  servo1.write(110);
  servo2.write(100);
  }

 //stabilna pozicija je 110 100
 
}

  */


 }  
 



