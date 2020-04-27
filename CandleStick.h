#pragma once
#include <string>

struct CandleStick {
	std::string time;
	double high;
	double low;
	double open;
	double close;
	double wap;
	long long volume;
	int count;
};