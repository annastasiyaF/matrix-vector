#include <iostream>
//матрица - вектор строк

template <class T>
class Vector{
protected:
    T* _array;//динамич массив
    size_t _size;
    size_t _startIndex;//первый индекс с которого начинается матрица
public:
    Vector(size_t size, size_t startIndex = 0){
        _size = size;
        _array = new T[_size];
        _startIndex = startIndex;
        for(size_t i=0; i<size;i++){
            _array[i]=0;
        }
    }
    Vector() : Vector(0, 0) {}
    //рассмотреть выделение памяти, проконтролить чтобы старт идекс был не больше размера, размер не 0
    Vector(const Vector& tmp) : _size(tmp._size), _startIndex(tmp._startIndex) {
        _array = new T[_size];
        for (size_t i = 0; i < _size; ++i) {
            _array[i] = tmp._array[i];
        }
    }
    //контруктор перемещения РАЗОБРАТЬСЯ САМИ 
    Vector(Vector&& moved) : _size(moved._size), _startIndex(moved._startIndex) {
        _array = moved._array;
        moved._array = nullptr;
        moved._size = 0;
        moved._startIndex = 0;
    }
    ~Vector() {
        delete[] _array;
    } 
    size_t GetSize() const{
        return _size;
    }
    size_t GetsizeIndex() const{
        return _startIndex;
    }
    T& At(size_t pos){
        if(pos>=_size)
        throw"error";
        return _array[pos];
    }
    
    T& operator[](size_t position)const{
        return _array[position];
    }
    Vector& operator=(const Vector& tmp){ //оператор присваивания
        if(_size!=tmp._size){
        delete [] _array;
        _array=new T [tmp._size];
        }
        _size=tmp._size;
        _startIndex=tmp._startIndex;
        for(size_t i=0;i<_size;i++){
            _array[i]=tmp._array[i];
        }
        return *this;
    } 
    Vector& operator=(Vector&& tmp){
        if(_size!=tmp._size){
            delete [] _array;
            _array=new T [tmp._size];
        }
        _size=tmp._size;
        _startIndex=tmp._startIndex;
        for(size_t i=0;i<_size;i++){
            _array[i]=tmp._array[i];
        }
        delete[] tmp._array;
        tmp._array=nullptr;
        return *this;

    }
    Vector operator+(const T& tmp){
        Vector result(_size, _startIndex);
        for (size_t i = 0; i < _size; ++i) {
            result._array[i] = _array[i] + tmp;
        }
        return result;
    }
    Vector operator-(const T& tmp){
        Vector result(_size, _startIndex);
        for (size_t i = 0; i < _size; ++i) {
            result._array[i] = _array[i] - tmp;
        }
        return result;
    }
    T operator*(const Vector tmp){
        T result = 0;
        for (size_t i = 0; i < _size; ++i) {
            result += _array[i] * tmp._array[i];
        }
        return result;
    }
    Vector operator+(const Vector& tmp){
        if(_startIndex == tmp._startIndex){
            Vector result = Vector(_size, _startIndex);
                for (int i = 0; i < _size - _startIndex; i++){
                    result[i] = _array[i] + tmp._array[i];
                }
                return result;
        }
        else if (_startIndex > tmp._startIndex){
            Vector result = Vector(_size, tmp._startIndex);
            for (int i = 0; i < _startIndex - tmp._startIndex; i++){
                result[i] = tmp._array[i];
            }
            for (int i = _startIndex - tmp._startIndex; i < _size - tmp._startIndex; i++){
                result[i] = _array[i - _startIndex - tmp._startIndex] + tmp._array[i];
            }
            return result;
        }
        else{
            Vector result = Vector(_size, _startIndex);
            for (int i = 0; i < tmp._startIndex - _startIndex; i++){
                result[i] = _array[i];
            }
            for (int i = tmp._startIndex - _startIndex; i < _size - _startIndex; i++){
                result[i] = _array[i] + tmp._array[i - tmp._startIndex - _startIndex];
            }
            return result;
        }
    }
    Vector operator-(const Vector& tmp){
        if(_startIndex == tmp._startIndex){
            Vector res = Vector(_size, _startIndex);
            for (int i = 0; i < _size - _startIndex; i++){
                res[i] = _array[i] - tmp._array[i];
            }
            return res;
        }
        else if (_startIndex > tmp._startIndex){
            Vector res = Vector(_size, tmp._startIndex);
            for (int i = 0; i < _startIndex - tmp._startIndex; i++){
                res[i] = tmp._array[i] * (-1);
            }
            for (int i = _startIndex - tmp._startIndex; i < _size - tmp._startIndex; i++){
                res[i] = _array[i - _startIndex - tmp._startIndex] - tmp._array[i];
            }
            return res;
        }
        else{
            Vector res = Vector(_size, _startIndex);
            for (int i = 0; i < tmp._startIndex - _startIndex; i++){
                res[i] = _array[i];
            }
            for (int i = tmp._startIndex - _startIndex; i < _size - _startIndex; i++){
                res[i] = _array[i] - tmp._array[i - tmp._startIndex - _startIndex];
            }
            return res;
        }
    }
    T operator* (const Vector& tmp){
        if(sizeof(_array[0])!=sizeof(tmp._array[0])||_size!=tmp._size)
            throw "error";
        T result=0;
        for(size_t i=_startIndex;i<_size;i++){
            result+=_array[i]*tmp._array[i];
        }
        return result;
    }
    Vector operator*(int elem){
        Vector res = Vector(*this);
        for (int i = 0; i < _size; i++){
            _array[i] *= elem;
        }
        return res;
    }
    friend std::ostream& operator<<(std::ostream& os, const Vector& vect){
        os<<"(";
        for(int i=0; i<vect._size;i++){
            if(vect._startIndex>i)
                os<<0<<", ";
            else{
                os<<vect._array[i - vect._startIndex];
                if(i+1!=vect._size+vect.GetsizeIndex()){
                    os<<", ";
                }
            }
        }
        os<<")";
        return os;
    }

     friend std::istream& operator>>(std::istream& istr, Vector& vec){
        T current;
        for (size_t i=0;i< vec._size;i++){
            std::cout<<"elem n"<<i+vec._startIndex<<": ";
            istr>>current;
            vec._array[i]=current;
        }
        return istr;
    }
};