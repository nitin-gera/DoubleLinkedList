#include <iostream>

using namespace std;

#pragma pack(1)
struct node
{
    node*   prev;
    int     value;
    node*   next;
};

static node *HEAD = nullptr;

void AddNode(int value)
{
    node    *temp = new node;
    temp->prev = nullptr;
    temp->value = value;
    temp->next = nullptr;

    if(HEAD == nullptr)     /// This is the first node
    {
        HEAD = temp;
    }
    else
    {
        node *runner = HEAD;

        while(runner->next != nullptr)
        {
            runner = runner->next;
        }

        temp->prev = runner;
        runner->next = temp;
    }
}

void RemoveNode(int value)
{
    if(HEAD == nullptr) /// No node in list
    {
        cout << "List is Empty" << endl;
        return;
    }

    node *runner = HEAD;

    bool found_flag(false);
    while(runner != nullptr)
    {
        if(runner->value == value)
        {
            if(runner->prev == nullptr && runner->next == nullptr)
            {
                HEAD = nullptr;
            }
            else if(runner->prev == nullptr)    /// First node
            {
                HEAD = runner->next;
                HEAD->prev = nullptr;
            }
            else if(runner->next == nullptr)    /// Last node
            {
                runner->prev->next = nullptr;
            }
            else
            {
                runner->prev->next = runner->next;
                runner->next->prev = runner->prev;
            }

            break;
        }

        found_flag = true;
        delete runner;

        runner = runner->next;
    }

    if(!found_flag)
    {
        cout << "Number not present in list" << endl;
    }
}

void PrintList()
{
    node *runner = HEAD;

    cout << "List:" << endl;
    while(runner != nullptr)
    {
        cout << runner->value << "->";
        runner = runner->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    int ch (0);
    do
    {
        cout << "1. Add node" <<endl;
        cout << "2. Delete node" << endl;
        cout << "3. Print" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice:";
        cin >> ch;

        cout << "----------------------------------------" << endl;

        switch (ch)
        {
        case 1:
        {
            int val;
            cout << "Enter Value:";
            cin >> val;

            AddNode(val);
        }
            break;

        case 2:
        {
            int val;
            cout << "Enter Value:";
            cin >> val;

            RemoveNode(val);
        }
            break;

        case 3:
            PrintList();
            break;

        case 0:
            exit(0);

        default:
            break;
        }
    }while (ch != 0);

    return 0;
}
