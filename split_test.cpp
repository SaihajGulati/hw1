#include "split.h"
#include <iostream>
#include <fstream>

using namespace std;

void printList(Node* curr)
{
    while (curr != nullptr)
    {
        cout << curr->value << endl;
        curr = curr->next;
    }
}

int main(int argc, char *argv[])
{
    ifstream ifile("list.txt");

    if(ifile.fail())
    {
        cout << "Couldn't open file" << endl;
        return 1;
    }
    
    int num = 0;
    
    ifile >> num;
    Node* head = new Node(num, nullptr);
    Node* curr = head;

    ifile >> num;
    //need starter head so have to print at end
    
    while(!ifile.fail())
    {
        curr->next = new Node(num, nullptr);
        curr = curr->next;
        ifile >> num;
    }
    

    /*Node* head = new Node(0, nullptr);
    Node* second = new Node(0, nullptr);
    Node* third = new Node(0, nullptr);
    Node* fourth = new Node(0, nullptr);
    Node* fifth = new Node(0, nullptr);

    head->value = 1;
    head->next = second;

    second->value = 2;
    second->next = third;

    third->value = 3;
    third->next = fourth;

    fourth->value = 4;
    fourth->next = fifth;

    fifth->value = 5;*/
    
    //printList(head);

    Node* odds = nullptr;
    Node* evens = nullptr;
    split(head, odds, evens);
    printList(evens);

    cout << endl;

    printList(odds);

    //destructing the linked lists (main one, evens one, and odds one)
    while (head != nullptr)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    while (evens != nullptr)
    {
        Node* temp = evens;
        evens = evens->next;
        delete temp;
    }

    while (odds != nullptr)
    {
        Node* temp = odds;
        odds = odds->next;
        delete temp;
    }
}
