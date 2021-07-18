#include "transaction.h"

Transaction::Transaction() {}

Transaction::Transaction(QDate d, QTime t, double a, TransactionType tt)
    : date(d), time(t), amount(a), type(tt) {}

const QStringList Transaction::sm_TransactionType = (QStringList() << "Withdrawal" << "Deposit");


QString Transaction::toString() const {
    return QString("%1: R%2 on %3 at %4").arg(
                Transaction::sm_TransactionType.at(type),
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
    return Transaction::sm_TransactionType.at(type);
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
    type = Transaction::TransactionType(Transaction::sm_TransactionType.indexOf(tt));
}

Transaction::~Transaction() {

}
