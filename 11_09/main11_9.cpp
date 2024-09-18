#include <iostream>
#include "Patient.h"
#include <chrono>
#include "Queue.h"
#include "Doctor.h"
int main(){
    Patient* patients=new Patient[10];
    Patient p1=Patient("hoho", "aha", "veevha", {std::chrono::month(1)/10/2024});
    Patient p2=Patient("hoho aha veevha", std::chrono::year_month_day{});
    Queue patient_queue;
    Doctor doc;
    while(true){
        //ввод пациентов
    }
    
    while (true){
        Patient* current=patient_queue.Get_next_patient();
        doc.Next(current );
        delete current;
    }







    return 0;
}