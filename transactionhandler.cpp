#include "transactionhandler.h"

#include <QTextStream>
#include <QFile>

QTextStream cout(stdout);

TransactionHandler::TransactionHandler() {
    transactionList = TransactionList::getInstance();
}

void TransactionHandler::transact(QString tt, double a) {
    // convert "transaction type" string to enum:
    Transaction::TransactionType type;
    if (tt == "Deposit")
        type = Transaction::TransactionType::Deposit;
    else if (tt == "Withdrawal")
        type = Transaction::TransactionType::Withdrawal;
    else {
        //terminate early in case of error:
        //(mainly included to get rid of IDE warnings)
        cout << "error creating transaction" << Qt::endl;
        return;
    }

    Transaction *deposit = new Transaction(QDate::currentDate(),
                                           QTime::currentTime(),
                                           a,
                                           type);
    transactionList->addTransaction(deposit); // add to transaction list
    cout << deposit->toString() << Qt::endl; // write to console
}

bool TransactionHandler::toFile() {
    QFile outFile("transactions.txt");
    if (!outFile.open(QIODevice::WriteOnly))
        return false;
    QTextStream fout(&outFile);
    QList<Transaction*> outList = transactionList->returnList();
    for(int i = 0; i < outList.size(); i++)
        fout << outList.at(i)->toString() << Qt::endl;
    outFile.close();
    return true;
}

TransactionHandler::~TransactionHandler()
{}
