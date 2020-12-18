#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"cell.h"
#include"formulacell.h"
#include"table.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void on_pushButton_clicked(Table *table_);
    void on_pushButton_2_clicked(Table *table_);
    void on_pushButton_3_clicked(Table *table_);
    void on_pushButton_4_clicked(Table *table_);
    void on_pushButton_5_clicked(FormulaCell formula_);
    void on_pushButton_6_clicked(FormulaCell formula_);
    void on_pushButton_7_clicked(FormulaCell formula_);
    Table* on_pushButton_8_clicked();
    FormulaCell* on_pushButton_9_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
