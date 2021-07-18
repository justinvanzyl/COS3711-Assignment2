#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "transactionhandler.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_depositButton_released();
    void on_withdrawalButton_released();
    void on_toFileButton_released();

private:
    Ui::MainWindow *ui;
    TransactionHandler th;
};
#endif // MAINWINDOW_H
