#pragma once
#include "ContractType.h"
#include <string>
#include <condition_variable>
#include <CandleStick.h>



class IHistorical_Data
{

public:

	//---------------------------functions
	virtual void reqHistoricalBarData(int uniqID, const ContractType& conT, const std::string& untilWhen,
		const std::string duration, const std::string barSize, const std::string& bidOrAskChart,
		const bool useRTH, bool keepUpToDate, std::condition_variable& cv) = 0;

	virtual void onDataRecive(const int uniqueId, const CandleStick& cs) = 0;
	virtual void onDataEnd(const int uniqueId, const std::string& startDateStr, const std::string& endDateStr) = 0;

	virtual void keepDataUpdate(const int uniqueId, const CandleStick& cs) = 0;



};
										

