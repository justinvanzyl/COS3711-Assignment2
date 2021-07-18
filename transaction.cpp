#include "transaction.h"

Transaction::Transaction() {}

Transaction::Transaction(QDate d, QTime t, double a, TransactionType tt)
    : date(d), time(t), amount(a), type(tt) {}

QString Transaction::toString() const {
    return QString("%1: R%2 on %3 at %4").arg(
                getType(), //calls getType in order to get a string
                QString::number(amount),
                date.toString(),
                time.toString());
}

QDate Transaction::getDate() const {
 return date;
}

QTime Transaction::getTime() const {
    return time;
}

double Transaction::getAmount() const {
   return amount;
}

QString Transaction::getType() const {
    switch (type) { // returns string versions of enum values:
        case Withdrawal:
            return "Withdrawal";
        case Deposit:
            return "Deposit";
    }
}

void Transaction::setDate(QDate d) {
    date = d;
}

void Transaction::setTime(QTime t) {
    time = t;
}

void Transaction::setAmount(double a) {
    amount = a;
}

void Transaction::setType(QString tt) {
    if (tt == "Withdrawal") // 'converts' strings to enum values:
            type =  Withdrawal;
    else if (tt == "Deposit")
            type = Deposit;
}

Transaction::~Transaction() {}
