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
    std::memcpy(temp_arr,_array,_count*sizeof(int8_t));
    delete[] _array;
    _array=temp_arr;
    }
    if(Get_index_elem(new_elem)!=-1){
        long long ind_new_elem=Get_index_elem(new_elem)+1;
        std::memmove(&_array[ind_new_elem+1], &_array[ind_new_elem], (_count-ind_new_elem) * sizeof(int8_t));
        _array[ind_new_elem]=new_elem;

    }
    
    if(new_elem>_max){
        _max=new_elem;
        _array[_count]=new_elem;
        if(new_elem<_min)
            _min=new_elem;
    }
    else if(new_elem<_min){
        _min=new_elem;
        std::memmove(&_array[1], &_array[0], _count * sizeof(int8_t));
        _array[0]=new_elem;
    }
     

    //else if(Get_index_elem(new_elem)==-1){
    if(new_elem>_min&&new_elem<_max){
        long long left=0, right=_count-1;
    while (left <= right) {
        long long mid = left + (right - left) / 2;
        if(right-left!=1){
            if (_array[mid] < new_elem)
                left = mid + 1;
            else
                right = mid - 1;

            }
        else{
            long long mid_position=left+1;
            std::memmove(&_array[mid_position+1], &_array[mid_position], (_count-mid_position) * sizeof(int8_t));
            _array[mid_position]=new_elem;
            break;
        }
        }
    }
    //}
    //else{
      //  long long ind_new_elem=Get_index_elem(new_elem);
      //  std::memmove(&_array[ind_new_elem+1], &_array[ind_new_elem], _count * sizeof(int8_t));
       // _array[ind_new_elem]=new_elem;
    //}

    _count++;
    

}


int8_t Get_max(){
    return _max;
}
int8_t Get_min(){

    return _min;
}


long long Get_index_elem(int8_t x){
    long long left=0, right=_count-1;
    while (left <= right) {
        long long mid = left + (right - left) / 2;
    if (_array[mid] == x)
            return mid;
    if (_array[mid] < x)
        left = mid + 1;
    else
        right = mid - 1;

    }
    return -1;
}


~Array_handler(){
    delete[]_array;

}
void Print_arr(){
    for(long long i=0;i<_count;i++){
        std::cout<<_array[i];
    }
}

};