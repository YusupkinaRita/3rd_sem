#include <iostream>
#include "Patient.h"
#include <chrono>
int main(){
    Patient* patients=new Patient[10];
    Patient p1=Patient("hoho", "aha", "veevha", std::chrono::year_month_day{});
    Patient p2=Patient("hoho aha veevha", std::chrono::year_month_day{});
    







    return 0;
}