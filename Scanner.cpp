#include "Scanner.h"
#include "Pattren.h"
#include "IB_Historical_Data.h"
#include "Stock.h"
#include "UniqueID.h"
#include <fstream>
#include <string>
#include <ctime>
using namespace std::unique_lock;

Scanner::Scanner()
{
	this->setPattren(new Pattren);
	this->setHistoricalInstance(new IB_Historical_Data);
	this->longs = getDataFromDB("Longs");
	this->shorts = getDataFromDB("Shorts");

}

void Scanner::setPattren(Pattren* ptr)
{
	this->itsPattren = ptr;
}

void Scanner::setHistoricalInstance(IHistorical_Data* historical_instance)
{
	this->itsHistoricalData = historical_instance;
}


std::vector<Stock*>* Scanner::getLongs()
{
	return this->longs;
}

std::vector<Stock*>* Scanner::getShorts()
{
	return this->shorts;
}

IHistorical_Data* Scanner::getHistoricalInstance()
{
	return this->itsHistoricalData;
}


std::vector<Stock*>* Scanner::getDataFromDB(std::string path)
{
	std::vector<Stock*> *result = new std::vector<Stock*>;

	std::ifstream infile;
	infile.open(path + ".txt");
	if (infile) {
		std::string buffer;
		std::string line;

		while (infile) {
			//read each line from file
			std::getline(infile, line);

			//splite the line
			size_t last = 0;
			size_t next = 0;

			std::string delimiter = ";";
			std::string tmp_buffer[3];
			int i = 0;

			while ((next = line.find(delimiter, last)) != std::string::npos)
			{
				tmp_buffer[i++] = line.substr(last, next - last);
				last = next + 1;
			}
			tmp_buffer[i] = line.substr(last);
			(*result).push_back(new Stock(tmp_buffer[0], stod(tmp_buffer[1]), stod(tmp_buffer[2])));
		}
	}
	else {
		
		//TODO throw exeption
	}
	for (int i = 0; i < (*result).size(); i++)
		std::cout << ((*result)[i])->getSymbol() << " " << ((*result)[i])->getPrice() << " " << ((*result)[i])->getChange() << std::endl;

	return result;
}

void Scanner::removeDualStocks()
{
	int counter = 0;
	std::time_t rawtime;
	std::tm* timeinfo;
	char queryTime[80];

	std::time(&rawtime);
	timeinfo = std::localtime(&rawtime);
	std::strftime(queryTime, 80, "%Y%m%d %H:%M:%S", timeinfo);

	std::condition_variable cv;
	std::mutex m;

	for (int i = 0; i < this->getShorts()->size; i++)
	{
		this->getHistoricalInstance()->reqHistoricalBarData(UniqueID::getUniqueID(), ContractType::CFD(),
															queryTime,"1 M", "1 D", "BID",true, false, cv);
		std::unique_lock<std::mutex> lck(m);
		cv.wait(lck);
		 
		

	}
}