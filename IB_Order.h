#pragma once
#include "IOrder.h"
#include "IB_Fun_Adapter.h"


class IB_Order: public IB_Fun_Adapter, public IOrder
{
   
};

