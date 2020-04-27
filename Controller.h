#pragma once
class Scanner;
class Time;
class Trade;
#include "Stock.h"
#include <iostream> 
#include <vector> 

class Controller
{

private:
	Scanner* itsScanner;
	Time* itsTime;
	std::vector<Trade*> trades;


};

