# COS3711-Assignment2
This repo covers the first 3 questions of the assignment.
Instructions were as follows:

### Question 1
Create a graphical user interface that allows a user to deposit or withdraw an amount. Display the current date on the interface. 
Create a Transaction class that stores the date, time, amount, and type of transaction (deposit or withdrawal, implemented as an enum). Transactions should be handled as pointers.
Create a TransactionList class that keeps a single list of transactions. There should be only one instance of this list allowed, so implement it using the Singleton design pattern.
When the user clicks the Deposit or Withdrawal button, the transaction should be written to the transaction list. Display the transaction in a console window as well (this is as a check that the transaction is actually being created.
When the user clicks on the To file button, the list of transactions should be written to a human-readable text file.
Ensure that your graphical user interface class handles only the interface, and does not contain code that is used to manage the transaction list; create a separate class for this purpose.

### Question 2
Now replace the To file code with code that serializes the transaction list as XML using DOM, and writes this to file. Below is an example of the XML file that should be produced. Note that the transaction type has been serialized as a QString.

```<TransactionList>
 <transaction>
  <date>Thu Jul 20 2017</date>
  <time>13:04:06</time>
  <amount>1200.99</amount>
  <type>Deposit</type>
 </transaction>
 <transaction>
  <date>Thu Jul 20 2017</date>
  <time>13:04:16</time>
  <amount>505.05</amount>
  <type>Deposit</type>
 </transaction>
 <transaction>
  <date>Thu Jul 20 2017</date>
  <time>13:04:22</time>
  <amount>123.45</amount>
  <type>Withdrawal</type>
 </transaction>
</TransactionList>
```

### Question 3
Implement a sort class hierarchy to implement the Strategy pattern using the UML diagram as a guideline.

![UML diagram](/images/uml.png?raw=true )

Now create a factory method that will return an instance of the SelectionSort or InsertionSort classes depending on what the user chooses – use a combo box to allow the
user to choose which sort method to use. Ensure that the program does not crash should an unrecognised sort type be requested. Display a sorted transaction list (sorted by amounts) to the console; the original list should remain unsorted.
