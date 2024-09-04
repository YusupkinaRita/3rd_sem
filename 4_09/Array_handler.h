#include <random>
#include <iostream>
#include<cstdint>
#include<cstring>

class Array_handler{
private:
    int* _array;
    int _max;
    int _min;
    int _size;
    int _count;
public:
Array_handler(int size=10){
    _size=size;
    _array=new int[_size];
    int max=INT32_MIN;
    int min=INT32_MAX;
    _count=0;

}
void Append_array(int new_elem){
    if(_count==_size){
    _size=_size*2;
    int* temp_arr=new int[_size];
    std::memcpy(temp_arr,_array,_size*sizeof(int));
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
int Get_max(){
    return _max;
}
int Get_min(){

    return _min;
}


int Get_index_elem(int x){
    for(int i=0;i<_count;i++){
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