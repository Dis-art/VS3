#ifndef _R_H_
#define _R_H_

#include <iostream> 
#include <string>
#include "../Operation.h"

class RequestConfigurationOperation : public Operation
{
public:
    string requestConfigurationData;
    void execute();
};

#endif