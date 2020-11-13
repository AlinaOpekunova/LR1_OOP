#include "formulacell.h"

FormulaCell::FormulaCell()
{

}

double FormulaCell::getSumRange(int x1, int x2, int y1, int y2)
{
    double sum=0;
    for (int i=x1;i<=x2;i++) {
        for (int j=y1;j<=y2;j++) {
            if(Cell::getType()==CellType::NUMBER){
                sum+=Cell::getNumber();
            }
        }
    }
    return sum;
}

double FormulaCell::getAverageRange(int x1, int x2, int y1, int y2)
{
    double k=0, sum=0;
    for (int i=x1;i<=x2;i++) {
        for (int j=y1;j<=y2;j++) {
            if(Cell::getType()==CellType::NUMBER){
                sum+=Cell::getNumber();
                k++;
            }
        }
    }
    return sum/k;
}

double FormulaCell::getMultiplicationRange(int x1, int x2, int y1, int y2)
{
    double mult=0;
    for (int i=x1;i<=x2;i++) {
        for (int j=y1;j<=y2;j++) {
            if(Cell::getType()==CellType::NUMBER){
                mult*=Cell::getNumber();
            }
        }
    }
    return mult;
}

const std::string &FormulaCell::getText() const {return Cell::getText();}

