#ifndef OOP_EXERCISE_05_RHOMBUS_H
#define OOP_EXERCISE_05_RHOMBUS_H

#include <iostream>
#include <utility>

template<class T>
struct TRhombus {
    std::pair<T, T> center;
    T vertDiag;
    T horDiag;

    TRhombus() : TRhombus(std::pair<T, T>{0, 0}, 0, 0) {}
    TRhombus(const std::pair<T, T>& c, const T& v, const T& h) : center(c), vertDiag(v), horDiag(h) {}
    TRhombus(const TRhombus& r) {
        center = r.center;
        vertDiag = r.vertDiag;
        horDiag = r.horDiag;
    }
    TRhombus& operator=(const TRhombus& r) {
        center = r.center;
        vertDiag = r.vertDiag;
        horDiag = r.horDiag;
        return(*this);
    }
};

template<class T>
T RhombusSquare (const TRhombus<T>& ob) {
    return(ob.vertDiag * ob.horDiag);
}

template<class T>
std::ostream& operator<<(std::ostream& os, const TRhombus<T>& rhombus) {
    os << "Координаты вершин: ";
    os << "(" << rhombus.center.first << ";" << (rhombus.center.second + rhombus.vertDiag / 2) << ") ";
    os << "(" << (rhombus.center.first + rhombus.horDiag / 2)  << ";" << rhombus.center.second << ") ";
    os << "(" << rhombus.center.first << ";" << (rhombus.center.second - rhombus.vertDiag / 2) << ") ";
    os << "(" << (rhombus.center.first - rhombus.horDiag / 2) << ";" << rhombus.center.second << ")";
    os << "\n";
    os << "Координаты центра: " << rhombus.center << "\n";
    os << "Площадь ромба: " << RhombusSquare<T>(rhombus) << "\n";
    return(os);
}

template<class T1, class T2>
std::ostream& operator<<(std::ostream& os, const std::pair<T1, T2>& p) {
	os << "(" << p.first << ", " << p.second << ")";
	return os;
}


#endif //OOP_EXERCISE_05_RHOMBUS_H