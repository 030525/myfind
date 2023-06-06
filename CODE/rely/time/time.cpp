#include "time.h"

void Timer::start_counting(){
	begin = std::chrono::steady_clock::now();
}
double Timer::end_output() {
	end_counting();
	return output_last();
}

void Timer::end_counting() {
	final = std::chrono::steady_clock::now();
}

double Timer::output_last() {
	duration = (begin - final);
	second = duration.count();
	printf("it takes %6fs , %4fms\n", second, second * 1000);
	//std::cout << "it takes " << second << "s , " << second * 1000 << "ms" << std::endl;
	return second;
}