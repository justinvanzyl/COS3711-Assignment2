#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    ui->dateDisplay->setText(QDate::currentDate().toString()); // updates the date display
    ui->amountDoubleSpinBox->setMaximum(100000.00); // increases max. value to R100 000.00

    connect(ui->depositButton, SIGNAL(released()), this, SLOT(depositButtonReleased()));
    connect(ui->withdrawalButton, SIGNAL(released()), this, SLOT(withdrawalButtonReleased()));
    connect(ui->toFileButton, SIGNAL(released()), this, SLOT(toFileButtonReleased()));
    connect(ui->sortButton, SIGNAL(released()), this, SLOT(sortButtonReleased()));
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::depositButtonReleased() {
    handler.transact("Deposit", ui->amountDoubleSpinBox->value());
    ui->amountDoubleSpinBox->setValue(0); //reset the amount spinbox
}

void MainWindow::withdrawalButtonReleased() {
    handler.transact("Withdrawal", ui->amountDoubleSpinBox->value());
    ui->amountDoubleSpinBox->setValue(0); //reset the amount spinbox
}

void MainWindow::toFileButtonReleased() {
    QString msg;
    if (handler.toFile()) //toFile() returns true on successful write operation
        msg = "Transactions successfully saved to file";
    else
        msg = "Could not save transactions to file";
    QMessageBox::information(0, "Saving transactions to file", msg);
}

void MainWindow::sortButtonReleased() {
    if (!handler.sort(ui->sortComboBox->currentText()))
        QMessageBox::critical(0, "Sort error", "Invalid sort method");
}

/*
I was having a problem where button signals were firing twice.
It turns out that if slots are named "on_depositButton_released()" (or similar),
Qt autoconnects the signal and slot! I manually connected them, so each was
connected twice and therefore each slot executed twice.
Not sure if you knew about this functionality, i thought it was interesting.
*/

