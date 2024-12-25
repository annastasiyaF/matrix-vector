#include "vector.h"

template <class T>
class Matrix: public Vector<Vector<T>>{
public: 
    Matrix(size_t n, bool flag = false) : Vector<Vector<T>>(n){
        if (flag){
            for (size_t i = 0; i < n; i++){
                this->_array[i] = Vector<T>(n, i);
            }
        }
        else{
            for (size_t i = 0; i < n; i++){
                this->_array[i] = Vector<T>(n);
            }
        }
    }
    Matrix(const Matrix& mt):Vector<Vector<T>>(mt){//конструктор копирования 
    }
    Matrix(const Vector<Vector<T>>& mt):  Vector<Vector<T>>(mt) {
    }
    Matrix& operator=(const Matrix& mt){//оператор присваивания
     if (this == &mt) {
            return *this;
        }
        delete[] this->_array; // освобождение памяти старого массива
        this->_size = mt._size; // копирование размеров и индекса начала
        this->_startIndex = mt._startIndex;//копирует размеры и индекс начала
        this->_array = new Vector<T>[this->_size]; // выделение памяти для нового массива
        for (size_t i = 0; i < this->_size; ++i) {
            this->_array[i] = mt._array[i]; // копирование элементов из mt
        }
        return *this;
    }
    Matrix operator+(const Matrix& mt){
        return Vector<Vector<T>>::operator+(mt);
    }
    Matrix operator-(const Matrix& mt){
        return Vector<Vector<T>>::operator-(mt);
    }
    
    Matrix operator*(const Matrix& mt) const {
    Matrix result(this->_size); // Инициализируем результирующую матрицу
    
    for (size_t i = 0; i < this->_size; ++i) {
        for (size_t j = 0; j < this->_size; ++j) {
            result._array[i][j] = 0; // Обязательная инициализация
            for (size_t k = 0; k < this->_size; ++k) {
                result._array[i][j] += this->_array[i][k] * mt._array[k][j];
            }
        }
    }
    return result;
}
   friend std::ostream& operator<<(std::ostream& os, const Matrix& matr){
        os<<"(";
        for(size_t i=0; i<matr._size;i++){
            for(size_t j=0; j<matr._size; j++){
               os<<matr._array[i][j];
               if(i!= matr._size-1 || j!= matr._size-1)
                    os<<", ";
            }
        }
        os<<")";
        return os;
    }

     friend std::istream& operator>>(std::istream& istr, Matrix& mat){
        
        for (size_t i=0;i< mat._size;i++){
            for (size_t j=0; j< mat._size; j++){
                std::cout<<"elem n"<<i<<": ";
                std::cout<<"elem m"<<j<<": ";
                istr>>mat._array[i][j];
                
            }
        }
        size_t nonZeroStart = mat._size;
        for(size_t i =0; i<mat._size; i++){
            bool allZero = true;
            for(size_t j = 0; j<mat._size; j++){
                if(mat._array[i][j] !=0){
                    allZero=false;
                    break;
                }
            }
            if (!allZero){
                nonZeroStart = i;
                break;
            }

        }
        mat._startIndex= nonZeroStart;
        return istr;
    }
};