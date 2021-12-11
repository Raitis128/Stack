#include <iostream>
#include <cstdlib>

using namespace std;

struct Node {
    int data; //Dati
    Node* next; //Adrese uz nakamo
};
//CREATE NODE
Node* CreateNode()
{
    Node* newNode; //apraktaa raditaju uz jauno mezglu
    newNode = new Node; //izdala atminju jaunajam mezglam
    newNode->next = NULL;//adrese next=NULL,jo mezgli nav savienoti
    cout << "\n\t\t\t\t\t\tType the number: ";
    cin >> newNode->data;//ievada datus mezgla
    return newNode;
}
//PRINT LIST
void PrintList(Node* head)
{
    Node* cur;
    cout << "\n\t\t\t\t\t\tList elements: ";
    cur = head; //pariet uz sarakta sakumu
    while (cur != NULL)//kamer tekoshai mezgls nav pedejais izdrukaa datus un pariet uz nakoho mezglu
    {
        cout << cur->data << " "; //izvadda datus
        cur = cur->next; //aiziet uz nakosho mezglu, iedot adresi nakoshajam mezglam
    }
}
//ADD FIRST
Node* AddFirst(Node* head, Node* newNode)
{
    newNode->next = head; // ievada sakmuma adresi
    return newNode; //atgriezh jauna mezgla adresi
}
// DELETE FIRST
Node* DeleteFirst(Node* head)
{
    Node* cur;
    cur = head->next;
    delete head;
    return cur;
}
// LIST LENGHT
int ListLenght(Node* head, int n)
{
    Node* cur;
    cur = head;
    while (cur)
    {
        n++;
        cur = cur->next;
    }
    return n;
}
// DELETE ALL
Node* DeleteAll(Node* head)
{
    if (head)
    {
        Node* cur;
        cur = head;
        while (cur->next != NULL)
        {
            cur = cur->next;
        }
        delete cur;
        cur = NULL;
        cout << "\n\t\t\t\t\t\tThe list has been deleted!";
    }
    else cout << "\n\t\t\t\t\t\tThe list is empty!";
    return NULL;
}

int main() {
    Node* head, * newNode, * temp, * temp2, * temp3;
    int x, y, n = 0, lenght;
    cout << "\t\t\t\t\t\tLinked list\n";
    head = CreateNode();
    do {
        system("cls");
        cout << "\n\t\t\t\t\t\tMenu\n";
        cout << "\t\t\t\t\t\t1. PrintList\n";
        cout << "\t\t\t\t\t\t2. AddFirst\n";
        cout << "\t\t\t\t\t\t3. DeleteFirst\n";
        cout << "\t\t\t\t\t\t4. ListLenght\n";
        cout << "\t\t\t\t\t\t5. DeleteAll\n";
        cout << "\t\t\t\t\t\t6. Info\n";
        cout << "\t\t\t\t\t\t0. Exit\n";
        cout << "\t\t\t\t\t\tAction: ";
        cin >> x;
        switch (x) {
            // PRINT LIST
        case 1:
            if (head)
                PrintList(head);
            else cout << "\t\t\t\t\t\tThe list is empty";
            system("pause>nul");
            break;
            // ADD FIRST
        case 2:
            newNode = CreateNode(); // izveido mezglu
            head = AddFirst(head, newNode); //jauns saraksta saakums
            system("pause>nul");
            break;
            // DELETE FIRST
        case 3:
            if (head)
            {
                head = DeleteFirst(head);
                cout << "\n\t\t\t\t\t\tYou have deleted the first element!";
            }
            else cout << "\n\t\t\t\t\t\tThe list is empty!";
            system("pause>nul");
            break;
            // LIST LENGHT
        case 4:
            lenght = ListLenght(head, n);
            if (lenght > 1)
                cout << "\n\t\t\t\t\t\tThis list have " << lenght << " elements!";
            else if (lenght == 1)
                cout << "\n\t\t\t\t\t\tThis list have " << lenght << " element!";
            else cout << "\n\t\t\t\t\t\tThis list is empty!";
            system("pause>nul");
            break;
            // DELETE ALL
        case 5:
            head = DeleteAll(head);
            system("pause>nul");
            break;
        case 6:
            cout << "\n\t\t\t\t\t\tAuthor: Raitis Izhiks\n\t\t\t\t\t\tVer: 1.0";
            system("pause>nul");
            break;
        case 0: cout << "\n\t\t\t\t\t\tExit!";
            break;

        default: cout << "\n\t\t\t\t\t\tThe action is wrong!";
            break;
        }
    } while (x != 0);
    return 0;
    system("pause>nul");
}