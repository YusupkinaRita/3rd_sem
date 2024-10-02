#include <iostream>
#include <cstdint>

class BitField{
    private:
        size_t _size_mem; //сколько элементов в массиве
        uint16_t* _mem;
        size_t _size_bit;
        size_t Get_mem_index(size_t n) const{
            if(n>=_size_bit)
            throw "Bit out of range";
            return n/(sizeof(uint16_t)*8);
        } //вернуть индекс для конкретного бита в каком элементе этот бит
        uint16_t Get_mask(size_t n) const{
            uint16_t m=1<<(n%(sizeof(uint16_t)*8));
            return m;
        }

    public:
        BitField(size_t size_bit){
            _size_bit=size_bit;
            if(size_bit%(sizeof(uint16_t)*8)==0)
                _size_mem=size_bit/(sizeof(uint16_t)*8);
            else
            _size_mem=size_bit/(sizeof(uint16_t)*8)+1;//(size_bit%(sizeof(uint16_t)*8)!=0);
            _mem=new uint16_t[_size_mem];
            for(int i=0;i<_size_mem;i++)
            _mem[i]=0;
        }
        BitField(const BitField& tmp){
            _size_bit=tmp._size_bit;
            _size_mem=tmp._size_mem;
            _mem=new uint16_t[_size_mem];
            for (size_t i =0;i<_size_mem;i++){
                _mem[i]=tmp._mem[i];

            }
        }

        BitField& operator=(const BitField& tmp){
            if(_size_bit!=tmp._size_bit){
                delete[] _mem;
                _size_bit=tmp._size_bit;
                _size_mem=tmp._size_mem;
                _mem=new uint16_t[_size_mem];
            }
            for(size_t i=0;i<_size_mem;i++){
                _mem[i]=tmp._mem[i];
            }
            return *this;
            
        }
        ~BitField(){
            delete[] _mem;
            _mem=nullptr;
        }
        size_t Get_size() const{
            return _size_mem;
        }
         size_t Get_bit_size() const{
            return _size_bit;
        }
        uint16_t Get_bit(size_t n) const{
            if(n>=_size_bit)
            throw "Bit out of range";
            return ((Get_mask(n)&_mem[Get_mem_index(n)])!=0);
    


        } // вывести бит по индексу
        void Cer_bit(size_t n){
            //if(Get_bit(n)!=0)
            //_mem[Get_mem_index(n)]^=Get_mask(n);
            _mem[Get_mem_index(n)]&=(~Get_mask(n));
        } //присв n биту значение 0
        void Set_bit(size_t n){
            if(n>=_size_bit)
            throw "Bit out of range";
            _mem[Get_mem_index(n)] |= Get_mask(n);
        }

        BitField& operator~(){
            for(size_t i =0;i<_size_mem;i++)
            _mem[i]=~_mem[i];
        return *this;
        }


        friend std::ostream& operator<<(std::ostream& os, const BitField& tmp){
            for(int i=0;i<tmp._size_bit;i++){
                uint16_t x=tmp.Get_bit(i);
                os<<x;
            }
        
        return os;
        };
};
// перегрузка оператора вывода в консоль: вывести все биты в битовом поле
