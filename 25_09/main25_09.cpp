#include <iostream>
#include "BitField.h"

//a<<1 сдвиг влево на 1 бит, умножение на 2, добав 0 справа
//>> сдвиг вправо, добав нули слева
int main(){
    BitField bf=BitField(10);
    std::cout<<bf<<std::endl;
    for (int i=0;i<bf.Get_bit_size();i+=3){
        bf.Set_bit(i);
        std::cout<<bf<<std::endl;
    }
    //std::cout<<bf<<std::endl;
    




    return 0;
}