// void addTransaction(string& date, double amount) {
//         Node* newTransaction = new Node(date, amount);
//         if (head == nullptr) {
//             head = newTransaction;
//         } else {
//             Node* current = head;
//             while (current->next != nullptr) {
//                 current = current->next;
//             }
//             current->next = newTransaction;
//         }

//         if (size >= 10) {
//             removeFirstTransaction();
//         } else {
//             size++;
//         }
//     }

//     void removeFirstTransaction() {
//         if (head == nullptr) {
//             return;
//         }
//         Node* temp = head;
//         head = head->next;
//         delete temp;
//         size--;
//     }

//     void printTransactions() {
//         Node* current = head;
//         while (current != nullptr) {
//             cout << "Date: " << current->date << ", Amount: " << current->amount << endl;
//             current = current->next;
//         }
//     }