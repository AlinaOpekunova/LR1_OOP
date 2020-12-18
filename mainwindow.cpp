#include "mainwindow.h"
#include "ui_mainwindow.h"

#include"cell.h"
#include"table.h"
#include"formulacell.h"

#include <QString>
#include<iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked(Table *table_) {//загрузка таблицы из файла
    QString toSetText;
    auto filename = ui->lineEdit_2->text().toStdString();

    table_->loadTable(filename);
    ui->tableWidget->setColumnCount(table_->getLength()); // Указываем число колонок
    ui->tableWidget->setRowCount(table_->getWidth()); // Указываем число строк
    ui->tableWidget->setShowGrid(true); // Включаем сетку
}

void MainWindow::on_pushButton_2_clicked(Table *table_) {//сохранение таблицы в файл
    QString toSetText;
    auto filename = ui->lineEdit_3->text().toStdString();
    table_->saveTable(*table_,filename);

}

void MainWindow::on_pushButton_3_clicked(Table *table_){//получение суммы ячеек в указанном столбце
    QString toSetText;

    int m = ui->lineEdit->text().toInt();
    ui->lineEdit_5->setText(toSetText.setNum(table_->getSum(m)));
}

void MainWindow::on_pushButton_4_clicked(Table *table_){//получение среднего значения ячеек в указанном столбце
    QString toSetText;

    int n = ui->lineEdit_4->text().toInt();
    ui->lineEdit_6->setText(toSetText.setNum(table_->getAverage(n)));
}

void MainWindow::on_pushButton_5_clicked(FormulaCell formula_){//получение суммы диапазона ячеек
    QString toSetText;
    auto i1 = formula_.getXOne();
    auto i2 = formula_.getXTwo();
    auto j1 = formula_.getYOne();
    auto j2 = formula_.getYTwo();

    ui->lineEdit_11->setText(toSetText.setNum(formula_.getSumRange(i1,i2,j1,j2)));
}

void MainWindow::on_pushButton_6_clicked(FormulaCell formula_){//получение произведения диапазона ячеек
    QString toSetText;
    auto i1 = formula_.getXOne();
    auto i2 = formula_.getXTwo();
    auto j1 = formula_.getYOne();
    auto j2 = formula_.getYTwo();

    ui->lineEdit_12->setText(toSetText.setNum(formula_.getMultiplicationRange(i1,i2,j1,j2)));
}

void MainWindow::on_pushButton_7_clicked(FormulaCell formula_) {//получение среднего диапазона ячеек
    QString toSetText;
    auto i1 = formula_.getXOne();
    auto i2 = formula_.getXTwo();
    auto j1 = formula_.getYOne();
    auto j2 = formula_.getYTwo();

    ui->lineEdit_13->setText(toSetText.setNum(formula_.getAverageRange(i1,i2,j1,j2)));
}

Table* MainWindow::on_pushButton_8_clicked() {//создание новой таблицы
    QString toSetText;
    auto n = ui->lineEdit_14->text().toInt();
    auto m = ui->lineEdit_15->text().toInt();
    Table *table_ = new Table(n,m);
    table_->setWidth(m);
    table_->setLength(n);

    ui->tableWidget->setColumnCount(table_->getWidth()); // Указываем число колонок
    ui->tableWidget->setRowCount(table_->getLength()); // Указываем число строк
    ui->tableWidget->setShowGrid(true); // Включаем сетку
    return table_;
}

 FormulaCell* MainWindow::on_pushButton_9_clicked() { //создание ячейки с формулой
    auto i1 = ui->lineEdit_7->text().toInt();
    auto i2 = ui->lineEdit_8->text().toInt();
    auto j1 = ui->lineEdit_9->text().toInt();
    auto j2 = ui->lineEdit_10->text().toInt();

    FormulaCell *formula_= new FormulaCell(i1,i2,j1,j2);
    return formula_;
}

