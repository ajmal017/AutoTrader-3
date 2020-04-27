#pragma once
#include <string>

class Stock
{
public:
	Stock(std::string s, double p, double c) :symbol(s), price(p), change(c) {};
	std::string getSymbol() {return symbol ; }
	double getPrice() {return price;}
	double getChange() { return change;}
private:
	std::string symbol;
	double price;
	double change;
};

