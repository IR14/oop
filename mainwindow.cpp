#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ingredient.h"
#include "recipe.h"
#include "QString"
#include <string.h>
#include <iostream>

#define input_filename "C:\\Users\\IR14\\Desktop\\restaurant\\input.txt"
#define output_filename "C:\\Users\\IR14\\Desktop\\restaurant\\output.txt"

Recipe recipe;

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

void MainWindow::on_pushButton_Read_clicked(){
    recipe.read_file(input_filename);
}

void MainWindow::on_pushButton_Save_clicked(){
    recipe.save_file(output_filename);
}

void MainWindow::on_pushButton_Add_clicked(){
    std::string name = ui->lineEdit_Name->text().toStdString();
    std::string operation = ui->lineEdit_Operation->text().toStdString();
    std::string unit = ui->lineEdit_Unit->text().toStdString();
    int time = ui->lineEdit_Time->text().toInt();
    int quantity = ui->lineEdit_Quantity->text().toInt();

    Ingredient ingredient(name, unit, operation, time, quantity);
    recipe.add_unit(ingredient);

    ui->lineEdit_Name->setText("");
    ui->lineEdit_Operation->setText("");
    ui->lineEdit_Unit->setText("");
    ui->lineEdit_Time->setText("");
    ui->lineEdit_Quantity->setText("");
}

void MainWindow::on_pushButton_Delete_clicked(){
    int position = ui->lineEdit_Position->text().toInt();
    if (position < 0 || position > recipe.get_size() - 1)
        ui->lineEdit_Position->setText("Stack overflow");
    else {
        ui->lineEdit_Position->setText("");
        recipe.rm_unit(position);
    }
}

void MainWindow::on_pushButton_Clear_clicked(){
    recipe.rm_all();
}

void MainWindow::on_pushButton_Show_clicked()
{
    QString help_set;
    std::string temp;
    ui->listWidget->clear();
    for (int i=0; i< recipe.get_size(); i++) {
        recipe.get_unit(0);

        temp = recipe.get_unit(i).get_name()+", "
                +recipe.get_unit(i).get_unit()+", "
                +recipe.get_unit(i).get_operation()+", "
                +std::to_string(recipe.get_unit(i).get_time())+", "
                +std::to_string(recipe.get_unit(i).get_quantity());

        std::cout << temp << std::endl;
        ui->listWidget->addItem(temp.c_str());
    }
}
