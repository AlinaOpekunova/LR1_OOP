#include <fstream>
#include <iostream>

#include "table.h"

Table::Table(const int row,const int col) { // конструктор инициализации (размер колекции как параметр)
    if (row > 0 && col > 0) {
        cell = new Cell *[row]; // создание массива указателей
        for (int i = 0; i < row; i++) {
            cell[i] = new Cell [col]; // инициализация указателей (выделение памяти для массива типа Cell)
        };
    }
    else {
        throw "Error! Initialization failed...\n";}
}

void Table::setCell(const int x, const int y, Cell &Cell) { // констуктор копирования
    if ((x >= 0) && (x < row) && (y >= 0) && (y < col)){
        cell[x][y] = Cell;
    }
    else
        throw "Error! Copying can't be done!\n";
}

Cell Table::getCell(const int x, const int y) const { // метод доступа к элементу по индексу
    if ((x >= 0) && (x < row) && (y >= 0) && (y < col))
        return cell[x][y];
    else
        throw "Error! Element is not available!\n";
}

int Table::getLength() const { // возвращает число строк
    return  row;
};

int Table::getWidth() const { // возвращает число столбцов
    return col;
}

int Table::getSize() const { // возвращает размерность таблицы (общее количество ячеек)
    return row*col;
}

void Table::saveTable(const Table& table_, const std::string filename) const { // метод, принимающий путь к файлу и сохраняющий в него содержимое коллекции
    std::ofstream file;
    file.open(filename,std::ios::app);
    file << table_.getWidth() << "\n" << table_.getLength() << "\n";
    for (int i=0; i<table_.getWidth();i++){
        for (int j=0; j<table_.getLength(); j++){
            if(table_.getCell(i,j).getType() == CellType::TEXT){
                file << table_.getCell(i,j).getText() <<"\n";
            }
            else {
                file << table_.getCell(i,j).getNumber() <<"\n";
            }
        }
    }
    file.close();
}

void Table::loadTable(const std::string filename) const { // метод, принимающий путь к файлу и загружающий из него содержимое коллекции
    double n, m;
    std::ifstream file;
    file.open(filename,std::ios::out);
    std::string str;
    Cell** cell=NULL;
    if (!file)
        throw "File error - can't open to read data!";
    else{
        while(1){
            file >> n >> m;
            cell= new Cell *[n];
            for (int i=0; i<n;i++){
                cell[i] = new Cell [m];
                for (int j=0; j<m; j++){
                    file >> str;
                    cell.getCell(i,j).setText() = str;
                }
            }

        }
        file.close();
    }
}

double Table::getSum(const int m) const { // метод, возвращающий сумму всех числовых данных элементов в произвольном столбце
    double sum=0;
    for (int i=0; i<col;i++){
        if (i==m){
            for(int j=0;j<row;j++){
                if(cell[j][m].getType() == CellType::NUMBER){
                    sum += cell[j][m].getNumber();}
            }
        }
    }
    return sum;
}

double Table::getAverage(const int m) const { // метод, возвращающий среднее арифметическое всех числовых данных элементов в произвольном столбце
    double sum=0,k=0;
    for (int i=0; i<col;i++){
        if (i==m){
            for(int j=0;j<row;j++){
                if(cell[j][m].getType() == CellType::NUMBER){
                    sum += cell[j][m].getNumber();
                    k++;
                }
            }
        }
    }
    return sum/k;
}

bool Table::operator ==(const Table &&other_) const
{
    if(row != other_.getLength()||col != other_.getWidth()){
        return false;
    }
    else {
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(cell != other_.getCell(i,j)) return false;
            }
        }
        return true;
    }
}

Table::~Table() { // деструктор
    if(cell){
        for(int i = 0; i < row; i++) {
            delete [] cell[i]; // уничтожение массивов типа Cell
            cell[i] = NULL;
        };
        delete[]cell;
    }
};
