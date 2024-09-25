#pragma once
#include <iostream>
#include "Patient.h"
#include <cstring>



class Queue{
private:
Patient** _top_patient;//если топ заполнена то перекидываем вниз в начало, если мидл,то в топ в конец, если общ,то первого в конец мидла
Patient** _middle_patient;
Patient** _general_patient;
size_t _sT;
size_t _sM;
size_t _sG;
size_t _cT;
size_t _cM;
size_t _cG;
size_t _q_count;


public:
    Queue(){
        _top_patient=new Patient*[_sT];
        _middle_patient=new Patient*[_sM];
        _general_patient=new Patient*[_sG];
        _cT=0;
        _cM=0;
        _cG=0;
        _sT=10;
        _sM=10;
        _sG=10;
        _q_count=0;


    };
    Patient* Get_next_patient(){
        if(_q_count<_cT){

            Patient* temp=_top_patient[_q_count];
            _q_count++;
            //_cT--;
            //std::memmove(&_top_patient[0],&_top_patient[1], sizeof(Patient*)*_cT);
            return temp;
        }
        else{
            if((_q_count-_cT)<_cM){
                Patient* temp=_middle_patient[_q_count-_cT];
                _q_count++;
                //_cM--;
                //std::memmove(&_middle_patient[0],&_middle_patient[1], sizeof(Patient*)*_cM);
                return temp;
            }
            else{
                if(_q_count-_cT-_cM<_cG){
                    Patient* temp=_general_patient[_q_count-_cT-_cM];
                    _q_count++;
                    //_cG--;
                    //std::memmove(&_general_patient[0],&_general_patient[1], sizeof(Patient*)*_cG);
                    return temp;
                }
                else
                return 0;
            }

        }
    }
    void Append_patient(Patient* pat){
        if(pat->Get_estate()==I){
            if(_cT==_sT){
                if(_cM!=_sM){
                    std::memmove(&_middle_patient[1],&_middle_patient[0],sizeof(Patient*)*_cM);
                    _middle_patient[0]=pat;
                    _cM++;
                }
            

            }
            else{
                _top_patient[_cT]=pat;
                _cT++;

            }

        }
        if(pat->Get_estate()==II){
            if(_cM==_sM){
                if(_cG!=_sG){
                    std::memmove(&_general_patient[1],&_general_patient[0],sizeof(Patient*)*_cG);
                    _general_patient[0]=pat;
                    _cG++;
                }
                else if(_cT!=_sT){
                    Patient* temp=_middle_patient[0];
                    std::memmove(&_middle_patient[0],&_middle_patient[1],sizeof(Patient*)*_cM);
                    _middle_patient[_cM-1]=pat;

                    _top_patient[_cT]=temp;
                    _cT++;

                }
              


            }
            else{
                _middle_patient[_cM]=pat;
                _cM++;
                
            }
            
        }
        if(pat->Get_estate()==III){
            if(_cG==_sG){
                if(_cM!=_sM){
                    Patient* temp=_general_patient[0];
                    std::memmove(&_general_patient[0], &_general_patient[1],sizeof(Patient*)*_cG);
                    _general_patient[_cG-1]=pat;

                    _middle_patient[_cM]=temp;
                    _cM++;

                }
                

            }
            else{
                _general_patient[_cG]=pat;
                _cG++;
                
            }
            
        }


    }

    ~Queue(){
        delete[] _top_patient;
        delete[] _middle_patient;
        delete[] _general_patient;
    }



};