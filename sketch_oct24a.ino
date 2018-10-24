#include <PID_v1.h>
#include <stdint.h>

double Setpointx, Inputx, Outputx;
double Setpointy, Inputy, Outputy;

double Kpx = 0.3;                                                     
double Kix = 0.03;                                                      
double Kdx = 0.13;

double Kpy = 0.3;                                                       
double Kiy = 0.08;                                                      
double Kdy = 0.13;

PID PIDX(&Inputx, &Outpuxt, &Setpointx, Kpx, Kix, Kdx, DIRECT);
PID PIDY(&Inputy, &Outputy, &Setpointy, Kpy, Kiy, Kdy, DIRECT);

void setup() {
  PIDX.SetMode(AUTOMATIC);
  PIDX.SetOutputLimits(0, 180);
  PIDY.SetMode(AUTOMATIC);
  PIDY.SetOutputLimits(0, 180);

  delay(100);
}

void loop() {
  

}
