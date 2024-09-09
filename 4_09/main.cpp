#include <iostream>
#include <random>
#include <chrono>
#include "Array_handler.h"
int main(){
    Array_handler array_handler=Array_handler(5);
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    for (int i=0;i<10000;i++){
        array_handler.Append_array(rand()%100);
    }
    std::cout<<array_handler.Get_index_elem(18)<<std::endl;


    
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << std::endl;
    return 0;

}