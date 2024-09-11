#include <iostream>
#include <cstring>
#include <chrono>

enum Gender{male, female};

class Patient{
private:
std::string _name;
std::string _surname;
std::string _patronomyc;
std::chrono::year_month_day _born_date;
UUID _uuid;
Gender _gender;
void Define_gender();
void Generate_id();
void Determine_fio(std::string fio);
std::string _health_problem;
Diagnos* _diagnos;//description drugs структура
public:
Patient(std::string surname, std::string name, std::string patr,std::chrono::year_month_day born_date);
Patient(std::string fio, std::chrono::year_month_day born_date);





};