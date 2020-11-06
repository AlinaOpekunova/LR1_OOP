/*БИВ193 Опекунова Алина
 * Вариант 15
Будущих бухгалтеров отталкивает сложность электронных таблиц.
Разработайте для них програму с минимальным функционалом:
хранение числовых и текстовых данных в таблице с изменяемым размером.
1) Ячейка электронной таблицы: числовое или текстовое значение, может быть пустой.
2) Таблица (двумерный массив ячеек): методы вычисления суммы и среднего
   арифметического всех числовых данных в произвольном столбце*/
#include "mainwindow.h"

#include <QApplication>

#include <iostream>
#include <string>
#include<assert.h>

#include "cell.h"
#include "cell.cpp"
#include "table.h"
#include "table.cpp"
using namespace std;

namespace TestTests {

constexpr double TEST_NUMBER = 10;
constexpr double SIZE_TEST1 = 1;
constexpr double SIZE_TEST2 = 2;
const std::string TEST_STRING = "test";
Cell TEST1(TEST_NUMBER,TEST_STRING,CellType::NUMBER);
Cell TEST2(TEST_NUMBER,TEST_STRING,CellType::TEXT);

void testDefaultConstructor() { // тестирование конструктора по умолчанию
    Cell testObject1; // тестирование ячейки, которая предназначена для числа
    Cell testObject2; // тестирование ячейки, которая предназначена для текста
    assert(testObject1.getNumber() == TEST_NUMBER);
    assert(testObject1.getText() == "");
    assert(testObject1.getType() == CellType::NUMBER);
    assert(testObject2.getNumber() == TEST_NUMBER);
    assert(testObject2.getText() == TEST_STRING);
    assert(testObject2.getType() == CellType::TEXT);
    cout << "Testing of the default Cell constructor was successful." << "\n";
}

void testInitConstructor() { // тестирование конструктора инициализации
    Cell testObject(TEST_NUMBER, TEST_STRING,CellType::NUMBER);
    assert(testObject.getNumber() == TEST_NUMBER);
    assert(testObject.getText() == TEST_STRING);
    assert(testObject.getType() == CellType::NUMBER);
    cout << "Testing of the initialization Cell constructor was successful" << "\n";
}

void testCopyConstructor() { // тестирование конструктора копирования
    Cell testObject1(TEST_NUMBER,TEST_STRING,CellType::NUMBER);
    Cell testObject2(testObject1);
    assert(TEST_NUMBER == testObject2.getNumber());
    assert(TEST_STRING == testObject2.getText());
    assert(CellType::NUMBER == testObject2.getType());
    cout << "Testing of the copy Cell constructor was successful." << "\n";
}

void testInitTableConstructor() { // тестирование конструктора инициализации
    Table testObject(SIZE_TEST2, SIZE_TEST2);
    assert(testObject.getLength() == SIZE_TEST2);
    assert(testObject.getWidth() == SIZE_TEST2);
    cout << "Testing of the initialization Table constructor was successful" << "\n";
}

void testCopyTableConstructor() { // тестирование конструктора копирования
    Table testObject1(SIZE_TEST1, SIZE_TEST2);
    testObject1.setCell(SIZE_TEST1,SIZE_TEST1,TEST1);
    testObject1.setCell(SIZE_TEST1,SIZE_TEST2,TEST2);
    Table testObject2(testObject1);
    assert(testObject2.getCell(SIZE_TEST1,SIZE_TEST1).getText()==TEST1.getText());
    assert(testObject2.getCell(SIZE_TEST1,SIZE_TEST1).getNumber()==TEST1.getNumber());
    assert(testObject2.getCell(SIZE_TEST1,SIZE_TEST1).getType()==TEST1.getType());
    assert(testObject2.getCell(SIZE_TEST1,SIZE_TEST2).getText()==TEST2.getText());
    assert(testObject2.getCell(SIZE_TEST1,SIZE_TEST2).getNumber()==TEST2.getNumber());
    assert(testObject2.getCell(SIZE_TEST1,SIZE_TEST2).getType()==TEST2.getType());
    cout << "Testing of the copy Table constructor was successful." << "\n";
}

void printTable(){ // Функция последовательного и пронумерованного вывода элементов коллекции на экран
    Table testObject(SIZE_TEST1, SIZE_TEST2);
    testObject.setCell(SIZE_TEST1,SIZE_TEST1,TEST1);
    testObject.setCell(SIZE_TEST1,SIZE_TEST2,TEST2);
    std::cout << "Print a collection of " << testObject.getSize() << "elements (A table " << testObject.getWidth() << " * " << testObject.getLength()<< ").\n";
    for (int i=0;i<SIZE_TEST1;i++){
        for(int j=0;j<SIZE_TEST2;j++){
            std::cout << "Cell [" << i << "]" << "[" << j << "]\n";
            testObject.getCell(i,j).printParams();
            std::cout << "\n";
        }
    }
}

}

int main() {
    TestTests::testDefaultConstructor();
    TestTests::testInitConstructor();
    TestTests::testCopyConstructor();
    TestTests::testInitTableConstructor();
    TestTests::testCopyTableConstructor();
    TestTests::printTable();
    cout << "All tests are passed." << "\n";
    return 0;
}
    /*
    int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();}
    */
