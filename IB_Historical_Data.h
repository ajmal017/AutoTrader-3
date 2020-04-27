#pragma once
//#include "IB_EWrapperFunctions.h"
#include "IHistorical_Data.h"
#include "IB_Fun_Adapter.h"

class IB_Historical_Data : public IHistorical_Data, public IB_Fun_Adapter
{
public: 
	void reqHistoricalBarData(int uniqID, const ContractType& conT, const std::string& untilWhen,
		const std::string duration, const std::string barSize, const std::string& bidOrAskChart,
		const bool useRTH, bool keepUpToDate, std::condition_variable& cv) override;

	void onDataRecive(const int uniqueId, const CandleStick& cs);

	void onDataEnd(const int uniqueId, const std::string& startDateStr, const std::string& endDateStr);

	void keepDataUpdate(const int uniqueId, const CandleStick& cs);
private:



//---------------------------functions

	
};

