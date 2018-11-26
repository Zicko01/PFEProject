#include <iostream>
#include "pid.h"
using namespace std;

int main()
{
	double InputX, SetpointX, OutputX;
	double InputY, SetpointY, OutputY;

	double KpX = 0.1;
	double KiX = 0.0;
	double KdX = 0.0;

	double KpY = 0.1;
	double KiY = 0.0;
	double KdY = 0.0;

	PID PIDX(&InputX, &OutputX, &SetpointX, KpX, KiX, KdX, DIRECT);
	PID PIDY(&InputY, &OutputY, &SetpointY, KpY, KiY, KdY, REVERSE);

	PIDX.SetMode(AUTOMATIC);
	PIDY.SetMode(AUTOMATIC);

	SetpointX = 300;
	SetpointY = 225;

	PIDX.SetOutputLimits(-80, 80);
	PIDY.SetOutputLimits(-70, 70);

	while (true)
	{
		//	int time;
		//	cin >> time;
		//	PIDX.SetTimeChange(time);
		//	PIDY.SetTimeChange(time);
		cin >> InputX >> InputY;

		PIDX.Compute();
		PIDY.Compute();
	
		cout << "x servo: " << 110 + OutputY << endl;
		cout << "y servo: " << 100 + OutputX << endl;
	}
	system("pause");
}