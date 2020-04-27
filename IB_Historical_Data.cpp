#include "IB_Historical_Data.h"

void IB_Historical_Data::reqHistoricalBarData(int uniqID, const ContractType& conT, const std::string& untilWhen, const std::string duration, const std::string barSize, const std::string& bidOrAskChart, const bool useRTH, bool keepUpToDate, std::condition_variable& cv)
{

}

void IB_Historical_Data::onDataRecive(const int uniqueId, const CandleStick& cs)
{
}

void IB_Historical_Data::onDataEnd(const int uniqueId, const std::string& startDateStr, const std::string& endDateStr)
{

}

void IB_Historical_Data::keepDataUpdate(const int uniqueId, const CandleStick& cs)
{

}
