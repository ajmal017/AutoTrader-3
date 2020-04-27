#pragma once


class ILevel_1_Data
{
private:

	double high;
	double low;
	int volume;
	long close_price;

public:
	virtual void askingData() = 0;
	virtual void cancelingDataStreaming() = 0;
	virtual double getHigh() = 0;
	virtual double getLow() = 0;
	virtual double getBidPrice() = 0;
	virtual double getAskPrice() = 0;
	virtual int getBidSize() = 0;
	virtual int getAskSize() = 0;

};