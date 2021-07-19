#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <QDate>
#include <QTime>
#include <QStringList>
#include <QObject>

class Transaction {
public:
    // enumerator for our 2 types of transactions:
    enum TransactionType {
        Withdrawal,
        Deposit
    }; // must be declared ahead of first use (constructor)

    // constructors:
    Transaction();
    Transaction(QDate d, QTime t, double a, TransactionType tt);

    // getters:
    QDate getDate() const;
    QTime getTime() const;
    double getAmount() const;
    QString getType() const;

    // setters:
    void setDate(QDate d);
    void setTime(QTime t);
    void setAmount(double a);
    void setType(QString tt);

    // output object state as text:
    QString toString() const;

    // destructor:
    ~Transaction();

private:
    QDate date;
    QTime time;
    double amount;
    TransactionType type;
};


#endif // TRANSACTION_H
