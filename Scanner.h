class IHistorical_Data;
class Pattren;
class Stock;
#include <iostream> 
#include<vector>


class Scanner
{
public:
	Scanner();
	//------------Getters
	std::vector<Stock*>* getLongs();
	std::vector<Stock*>* getShorts();
	IHistorical_Data* getHistoricalInstance();

	//------------Setters
	void setPattren(Pattren*);
	void setHistoricalInstance(IHistorical_Data*);


private:
	Pattren* itsPattren;
	IHistorical_Data* itsHistoricalData;
	std::vector<Stock*> *longs;
	std::vector<Stock*> *shorts;
	void removeDualStocks();


	std::vector<Stock*>* getDataFromDB(std::string);

};