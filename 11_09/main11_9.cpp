#include <iostream>
#include "Patient.h"
#include <chrono>
#include "Queue.h"
#include "Doctor.h"
#include <cstring>
int main(){
    Patient p1=Patient("hoho", "aha", "veevha", {std::chrono::month(1)/10/2024}, II);
    Patient p2=Patient("hoho aha veevha", std::chrono::year_month_day{}, I);
    Queue patient_queue;
    Doctor doc;
    for(int i=0; i<1;i++){
        std::string name;
        std::string surname;
        std::string patr;
        Estate estate;
        int state;
        std::cout<<"enter name:"<<std::endl;
        std::cin>>name;
        std::cout<<"enter surname:"<<std::endl;
        std::cin>>surname;
        std::cout<<"enter patr:"<<std::endl;
        std::cin>>patr;
        int year;
        std::cout<<"enter year:"<<std::endl;
        std::cin>>year;
        int month;
        std::cout<<"enter month:"<<std::endl;
        std::cin>>month;
        int day;
        std::cout<<"enter day:"<<std::endl;
        std::cin>>day;
        
        std::cout<<"enter esate:"<<std::endl;
        std::cin>>state;
        switch (state)
        {
        case 1: estate=I;
            break;
        case 2:estate=II;
            break;
        case 3:estate=III;
            break;
        
        }
        Patient pat=Patient(name,surname,patr,{std::chrono::month(month)/day/year},estate);
        patient_queue.Append_patient(&p1);

        //ввод пациентов
    }
    
    for(int i=0;i<1;i++){
        Patient* current=patient_queue.Get_next_patient();
        doc.Next(current );
        delete current;
    }







    return 0;
}