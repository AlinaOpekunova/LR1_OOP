#ifndef TABLE_H
#define TABLE_H

#include "cell.h"

class Table {
    Cell **cell; // ссылка на ячейку
    int row,col; // размерность таблицы  (число строк и столбцов)
public:
    Table()=default;
    Table(const int row, const int col); // конструктор инициализации (размер колекции как параметр)
    void setCell(const int x, const int y, Cell &Cell); // конструктор копирования

    Cell getCell(const int x, const int y) const;// метод доступа к элементу по индексу
    int getLength() const; // возвращает число строк
    int getWidth() const; // возвращает число столбцов
    int getSize() const;// метод, возвращающий количество хранящихся в коллекции объектов

    void saveTable(const Table& table_, const std::string filename)const;// метод, принимающий путь к файлу и сохраняющий в него содержимое коллекции
    void loadTable(const std::string filename)const;// метод, принимающий путь к файлу и загружающий из него содержимое коллекции

    double getSum(const int n) const; // метод, возвращающий сумму всех числовых данных элементов в произвольном столбце
    double getAverage(const int m) const; // метод, возвращающий среднее арифметическое всех числовых данных элементов в произвольном столбце

    bool operator ==(const Table &&other_) const; //функция проверки двух коллекций на равенство, попарно сравнивающая их объекты

    ~Table(); // деструктор
};

#endif // TABLE_H
