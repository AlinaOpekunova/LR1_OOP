#ifndef FORMULACELL_H
#define FORMULACELL_H

#include "cell.h"

class FormulaCell: public Cell{
private:
    int x1,y1; // указатель на начало диапазона
    int x2,y2; // указатель на конец диапазона
public:
    FormulaCell();
    double getSumRange(int x1, int x2, int y1, int y2); // операция суммы
    double getAverageRange (int x1, int x2, int y1, int y2); // операция среднего значения
    double getMultiplicationRange (int x1, int x2, int y1, int y2); // операция произведения
    const std::string& getText() const override;
};

#endif // FORMULACELL_H
