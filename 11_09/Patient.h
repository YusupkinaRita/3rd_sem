#pragma once
#include <iostream>
#include <cstring>
#include <chrono>


enum Gender{male, female};
enum Estate{I, II, III};//первый в первую и тп

struct Diagnos{
std::string description;
std::string drugs;
};

class Patient{
private:
    std::string _name;
    std::string _surname;
    std::string _patronomyc;
    std::chrono::year_month_day _born_date;
//UUID _uuid;
    Gender _gender;
    Estate _state;
    void Define_gender(){
        if(_patronomyc.back()=='a')
        _gender=female;
        else _gender=male;
        
    };
   // void Generate_id();
    void Determine_fio(std::string fio){
        size_t ind1=fio.find(' ');
        size_t ind2=fio.find(' ',ind1+1);
        _surname=fio.substr(0,ind1);
        _name=fio.substr(ind1+1,ind2-ind1-1);
        _patronomyc=fio.substr(ind2+1);

    };
    std::string _health_problem;
    Diagnos* _diagnos;
public:
    Patient(){

    };
    Patient(std::string surname, std::string name, std::string patr,std::chrono::year_month_day born_date){
        _surname=surname;
        _name=name;
        _patronomyc=patr;
        _born_date=born_date;
        Define_gender();
    };
    Patient(std::string fio, std::chrono::year_month_day born_date){
        Determine_fio(fio);
        _born_date=born_date;
        Define_gender();
    };

    std::string Get_health_problem(){
        return _health_problem;

    }
    Estate Get_estate(){
        return _state;

    }





};