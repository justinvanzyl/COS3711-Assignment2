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
    void depositButtonReleased();
    void withdrawalButtonReleased();
    void toFileButtonReleased();
    void sortButtonReleased();

private:
    Ui::MainWindow *ui;
    TransactionHandler handler;
};
#endif // MAINWINDOW_H
