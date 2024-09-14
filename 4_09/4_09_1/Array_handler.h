#include <random>
#include <iostream>
#include<cstdint>
#include<cstring>

class Array_handler{
private:
    int8_t* _array;
    int8_t _max;
    int8_t _min;
    long long _size;
    long long _count;
public:
Array_handler(long long size=10){
    _size=size;
    _array=new int8_t[_size];
    _max=INT8_MIN;
    _min=INT8_MAX;
    _count=0;

}
void Append_array(int8_t new_elem){
    if(_count==_size){
    _size=_size*5;
    int8_t* temp_arr=new int8_t[_size];
    std::memcpy(temp_arr,_array,_size*sizeof(int8_t));
    delete[] _array;
    _array=temp_arr;
    }
    _array[_count]=new_elem;

    if(_array[_count]>_max)
    _max=_array[_count];
    if(_array[_count]<_min)
    _min=_array[_count];
    _count++;
    

}
int8_t Get_max(){
    return _max;
}
int8_t Get_min(){

    return _min;
}


long long Get_index_elem(int8_t x){
    for(long long i=0;i<_count;i++){
        if(x==_array[i]){
            return i;
        }
    }
    return -1;
}
~Array_handler(){
    delete[]_array;

}

};