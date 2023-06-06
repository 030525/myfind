#ifndef _time_h_
#define _time_h_

#include <chrono>
#include <iostream>

class Timer {
public:
	void start_counting();
	double end_output();
	void end_counting();
	double output_last();
private:
	std::chrono::steady_clock::time_point begin, final;
	std::chrono::duration<double> duration;
	double second;
};


#endif



