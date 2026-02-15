#ifndef UNTITLED10_TEMPLATE_H
#define UNTITLED10_TEMPLATE_H
#endif //UNTITLED10_TEMPLATE_H
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <map>
#include <algorithm>
#define n 10
#define N 4


using namespace std;

template<typename T = double>
class Statistic{
public:
    T *data;
    int size;
public:
    Statistic<T>(int = 3);
    Statistic<T>(const Statistic<T>&);
    ~Statistic<T>();
    int getsize() const;
    const Statistic<T>& operator = (const Statistic<T>&);
    T& operator[] (int index);

//    template<typename T1>
//    friend ostream& operator<<(ostream& os, const Statistic<T1>&c);

    friend ostream & operator << (ostream& os, const Statistic<T>&c){
        for (int i = 0; i < c.size; ++i) {
            os << c.data[i] << "; ";
        }
        return os;
    }

    Statistic<T>& operator += (const Statistic<T>&);
    Statistic<T>& operator /= (const Statistic<T>&);
    bool operator>(const Statistic<T> &);
    bool operator<(const Statistic<T> &);

    T maxel();       //  T maxel(T* _data, int _size);
    T average();     //  T average(T* _data, int _size);
};

template<>
class Statistic<char*>{
public:
    char** data;
    int size;
public:
    Statistic(int = 3);
    Statistic(const Statistic<char*>&);
    virtual ~Statistic();
    int getsize() const;
    const Statistic<char*>& operator = (const Statistic<char*>&);
    char*& operator[] (int index);

    friend ostream& operator<<(ostream& os, const Statistic<char*>&c){
        for (int i = 0; i < c.size; ++i) {
            os << c.data[i] << "; ";
        }
        return os;
    }
};