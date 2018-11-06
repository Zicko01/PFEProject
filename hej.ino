#include <PID_v1.h>
#include <stdint.h>
#include <Servo.h>
double Setpointx, Inputx, Outputx;
double Setpointy, Inputy, Outputy;
double Kpx = 0.3;                                                     
/*double Kix = 0.03;                                                      
double Kdx = 0.13;
double Kpy = 0.3;                                                       
double Kiy = 0.08;                                                      
double Kdy = 0.13;

PID PIDX(&Inputx, &Outputx, &Setpointx, Kpx, Kix, Kdx, DIRECT);
PID PIDY(&Inputy, &Outputy, &Setpointy, Kpy, Kiy, Kdy, DIRECT);

Servo servox;
Servo servoy;


 void setup() {
  Serial.begin(9600);
  PIDX.SetMode(AUTOMATIC);
  PIDX.SetOutputLimits(0, 180);
  PIDY.SetMode(AUTOMATIC);
  PIDY.SetOutputLimits(0, 180);
  servox.attach();//ubacis pin od servoa
  servoy.attach();//isto
   delay(100);
}
 void loop() {
  PIDX.compute();
  PIDY.compute();
  servox.write(Outputx);
  servoy.write(Outputy);
 }*/


String inString="";
void setup()
{
Serial.begin(9600);
//pinMode(6,OUTPUT);
  
}
int x,y;
void loop()
{
 while(Serial.available()>0){
  /*
    Ovo sam nasao na netu.
    Kolko sam shvatio ovaj serial read cita samo jedan bajt u trenutku
    Ova itsDigit funkcija nzm kako proverava dal je broj,ako jeste nakaci
    ga na kraj inString-a koji predstavlja celokupni  broj koji nam treba  
  */
    int inChar = Serial.read();
    if (isDigit(inChar)) {
      inString += (char)inChar;
    }
    if (inChar == '\n') {
      x = inString.toInt();
      inString = "";
    }
      inChar = Serial.read();
    if (isDigit(inChar)) {
      inString += (char)inChar;
    }
    if (inChar == '\n') {
       y = inString.toInt();
      inString = "";
    }
//analogWrite(6,x);
delay(10);


 
 } 

}










 
