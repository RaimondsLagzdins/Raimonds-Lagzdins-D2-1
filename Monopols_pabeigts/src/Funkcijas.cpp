#include <iostream>
#include <sstream>
using namespace std;

int StringToInt(string temporary){

    int convertedString;
    stringstream pagaidu(temporary);
    pagaidu >> convertedString;

    return convertedString;

}

