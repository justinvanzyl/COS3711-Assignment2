#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <QDate>
#include <QTime>
#include <QStringList>

class Transaction {
public:
    enum TransactionType {Withdrawal, Deposit};
    Transaction();
    Transaction(QDate d, QTime t, double a, TransactionType tt);
    static const QStringList sm_TransactionType;
    QString toString() const;

    QDate getDate() const;
    QTime getTime() const;
    double getAmount() const;
    QString getType() const;

    void setDate(QDate d);
    void setTime(QTime t);
    void setAmount(double a);
    void setType(QString tt);

    ~Transaction();

private:
    QDate date;
    QTime time;
    double amount;
    TransactionType type;
};


#endif // TRANSACTION_H
