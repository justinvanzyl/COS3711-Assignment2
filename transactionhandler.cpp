#include "transactionhandler.h"

#include <QTextStream>
#include <QFile>

QTextStream cout(stdout);

TransactionHandler::TransactionHandler() {
    transactionList = TransactionList::getInstance();
}

void TransactionHandler::makeDeposit(double a) {
    Transaction *newTransaction = new Transaction(QDate::currentDate(),
                                                  QTime::currentTime(),
                                                  a,
                                                  Transaction::TransactionType(Transaction::sm_TransactionType.indexOf("Deposit")));
    transactionList->addTransaction(newTransaction);
    cout << newTransaction->toString() << Qt::endl;
}

void TransactionHandler::makeWithdrawal(double a) {
    Transaction *newWithdrawal = new Transaction(QDate::currentDate(),
                                                 QTime::currentTime(),
                                                 a,
                                                 Transaction::TransactionType(Transaction::sm_TransactionType.indexOf("Withdrawal")));
    transactionList->addTransaction(newWithdrawal);
    cout << newWithdrawal->toString() << Qt::endl;
}

bool TransactionHandler::writeToFile() {
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
