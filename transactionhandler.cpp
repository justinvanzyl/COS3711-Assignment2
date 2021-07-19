#include "transactionhandler.h"

#include <QTextStream>
#include <QFile>
#include <QDomDocument>

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
        cout << "error creating transaction" << Qt::endl;
        return;
    }

    Transaction *transaction = new Transaction(QDate::currentDate(),
                                           QTime::currentTime(),
                                           a,
                                           type);
    transactionList->addTransaction(transaction); // add to transaction list
    cout << transaction->toString() << Qt::endl; // write to console
}

bool TransactionHandler::toFile() {
    QList<Transaction*> outList = transactionList->returnList();

    // create a DOM document and add nodes for each transaction:
    QDomDocument doc;
    QDomElement root = doc.createElement("TransactionList");
    doc.appendChild(root);

    for (int i = 0; i < outList.size(); i++) {
        QDomElement transactionTag = doc.createElement("transaction");
        root.appendChild(transactionTag);

        QDomElement dateTag = doc.createElement("date");
        transactionTag.appendChild(dateTag);
        QDomText dateString = doc.createTextNode(outList.at(i)->getDate().toString());
        dateTag.appendChild(dateString);

        QDomElement timeTag = doc.createElement("time");
        transactionTag.appendChild(timeTag);
        QDomText timeString = doc.createTextNode(outList.at(i)->getTime().toString());
        timeTag.appendChild(timeString);

        QDomElement amountTag = doc.createElement("amount");
        transactionTag.appendChild(amountTag);
        QDomText amountString = doc.createTextNode(QString::number(outList.at(i)->getAmount()));
        amountTag.appendChild(amountString);

        QDomElement typeTag = doc.createElement("type");
        transactionTag.appendChild(typeTag);
        QDomText typeString = doc.createTextNode(outList.at(i)->getType());
        typeTag.appendChild(typeString);
    }

    // write the DOM document to an XML file:
    QFile outFile("transactions.xml");
    if (!outFile.open(QIODevice::WriteOnly))
        return false;
    QTextStream fout(&outFile);
    fout << doc.toString();
    outFile.close();
    return true;
}


bool TransactionHandler::sort(QString sortType) {
    // create a SortFactory and use it to initialize a Sort:
    SortFactory* factory = new SortFactory();
    Sort* sortObject = factory->setSort(sortType, transactionList->returnList());
    delete factory;

    // exit early if an invalid sort-type is given:
    if (sortObject == NULL)
        return false;

    // sort the list and output it to console:
    sortObject->sort();
    QList<Transaction*> sortedList = sortObject->getList();
    cout << "----- RESULTS OF " << sortType.toUpper() << ": -----"  << Qt::endl;
    for (int i = 0; i < sortedList.size(); i++)
        cout << sortedList[i]->toString() << Qt::endl;
    return true;
}

TransactionHandler::~TransactionHandler() {}
