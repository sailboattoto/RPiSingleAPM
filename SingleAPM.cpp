#include "SingleAPM.hpp"

int main()
{
	long int timer;
	long int timer_end;
	Stablize_Mode test;
	test.ControlCalibration();
	test.SensorsGryoCalibration();
	while (true)
	{
		timer = clock();
		test.SensorsParse();
		test.ControlParse();
		test.AttitudeUpdate();
		test.MotorUpdate();
		timer_end = clock();
		if ((timer_end - timer) > 4000)
		{
			std::cout << "[WARING!!!!] Frequency Sync error , Over 4ms !!!!! Dangours !!! Gryo Angle error !!!!!";
			_flag_ForceFailed_Safe = true;
		}
		usleep(4000 - (timer_end - timer));
	}
}