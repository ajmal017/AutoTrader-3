#pragma once

class UniqueID
{
public:
	static int getUniqueID() { return id++; }
private:
	int static id;
};

int UniqueID::id = 0;