#ifndef CELL_H
#define CELL_H
#include <string>

enum class CellType {
    TEXT,
    NUMBER,
};

class Cell
{
private:
    double m_number; // числовое значение
    std::string m_text; // текстовое значение
    CellType m_type; // тип ячейки (по умолчанию ячейка предназначена для текста)
public:
    Cell(); //конструктор по умолчанию
    Cell(double number_, const std::string& text_, CellType type_); // конструктор инициализации
    Cell(const Cell& other_); // конструктор копирования

    // селекторы
    [[nodiscard]] double getNumber() const;
    [[nodiscard]] const std::string& getText() const;
    [[nodiscard]] CellType getType() const;

    // модификаторы
    void setNumber(int number_); // Установка числового значения
    void setText(const std::string& text_);  // Установка текстового значения
    void setType(CellType type_);

    void printParams() const; // Вывод ячейки на экран
};

#endif // CELL_H
