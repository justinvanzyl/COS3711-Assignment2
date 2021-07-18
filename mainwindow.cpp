#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    ui->dateDisplay->setText(QDate::currentDate().toString());
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_depositButton_released() {
    th.makeDeposit(ui->amountDoubleSpinBox->value());
    ui->amountDoubleSpinBox->setValue(0);
}

void MainWindow::on_withdrawalButton_released() {
    th.makeWithdrawal(ui->amountDoubleSpinBox->value());
    ui->amountDoubleSpinBox->setValue(0);
}

void MainWindow::on_toFileButton_released() {
    QString msg;
    if (th.writeToFile())
        msg = "Transactions successfully saved to file";
    else
        msg = "Could not save transactions to file";
    QMessageBox::information(0, "Saving transactions to file", msg);
}

