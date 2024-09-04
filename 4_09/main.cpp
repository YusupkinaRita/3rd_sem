#include <iostream>
#include <random>
#include "Array_handler.h"
int main(){
    Array_handler array_handler=Array_handler(5);
    for (int i=0;i<20000;i++){
        array_handler.Append_array(rand()%100);
    }
    std::cout<<array_handler.Get_index_elem(18)<<std::endl;


    return 0;

}