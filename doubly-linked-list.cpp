#include <iostream>
#include "clsDbLinkedList.h"

using namespace std;

int main() {

    clsDbLinkedList <int> MydblLinkedList;

    MydblLinkedList.InsertAtBeginning(5);
    MydblLinkedList.InsertAtBeginning(4);
    MydblLinkedList.InsertAtBeginning(3);
    MydblLinkedList.InsertAtBeginning(2);
    MydblLinkedList.InsertAtBeginning(1);

    cout << "\nLinked List Content:\n";
    MydblLinkedList.PrintList();

    MydblLinkedList.InsertAfter(4, 500);

    cout << "\nAfter Insert: " << "\n";
    MydblLinkedList.PrintList();

    system("pause>0");
}