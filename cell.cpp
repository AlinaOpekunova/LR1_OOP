#include "cell.h"
#include <iostream>
#include <string>

// конструктор по умолчанию
Cell::Cell()
{
    m_number = 0;
    m_text = "";
    m_type = CellType::TEXT;
}

// Конструктор инициализации
Cell::Cell(double number_, const std::string &text_, CellType type_)
{
    setNumber(number_);
    setText(text_);
    setType(type_);
    std::cout << "Initialization constructor worked here!\n";
}

// Конструктор копирования
Cell::Cell(const Cell &other_) :
    m_number(other_.m_number), m_text(std::move(other_.m_text)), m_type(other_.m_type)
{
    std::cout << "Copy constructor worked here!\n";
}

//селекторы
double Cell::getNumber() const { // возращает числовое значение, толькл если тип ячейки CellType::NUMBER
    if (m_type != CellType::NUMBER) {
        throw "Error!It is not possible to get a number, it may be a text data type...\n";
    }
    return m_number;
}

const std::string& Cell::getText() const { // возращает текстовое значение

    if (m_type != CellType::TEXT) {
        throw "Error!It is not possible to get a text value, it may be a number data type...\n";
    }
    return m_text;
}

CellType Cell::getType() const { // возращает тип ячейки
    return m_type;
}

void Cell::setNumber(int number_) { // Установка числового значения (первый модификатор)
    if(m_type == CellType::NUMBER){
        m_number = number_;
    }
    else { throw "Error!\n";};
}

void Cell::setType(CellType type_) { // Устанавливает тип ячейки
    m_type = type_;
}

void Cell::setText(const std::string& text_) { // Установка текстового значения (второй модификатор)
    int i=0;
    bool flag=false;
    std::string s=text_;
    std::string::size_type sz;

    if(text_.empty()) { // Если ничего не введено, то есть пустая строка
        m_text = "";
        m_number = 0;
        setType(CellType::TEXT);
    }
    else {
        while((i<sz)&&(flag==false)){ // проверяем есть ли в строке буквы (цикл перестанет работать, если найдена буква или конец строки)
            if((text_[i] >= 'A' && text_[i] <= 'Z') || (text_[i] >= 'a' && text_[i] <= 'z')){
                 flag=true;
            };
            i++;
        }

        if (flag==true){ // если в строке есть буквы, то тогда ячейка предназначена для текста
            m_text = text_;
            m_number = 0;
            setType(CellType::TEXT);
        }
        else { // иначе ячейка предназначена для записи чисел
            i = s.find_first_of(','); // десятичное число может быть написано как 1,5 и 1.5
            if (i!=-1){
                s = s.replace(i,1,1,'.');
            }
            else{s=text_;};
            // устанавливаем числовое значение ячейки и меняем ее тип
            m_number = std::stod (s,&sz);
            setType(CellType::NUMBER);
        }
    }
}

void Cell::printParams() const { // Вывод ячейки на экран
    if(m_type == CellType::NUMBER){
        std::cout << m_number << "\n";
    }
    else {
        std::cout << m_text << "\n";
    };
}
