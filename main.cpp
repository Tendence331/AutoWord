#include <iostream>
#include "autoword.h"
using namespace std;

int main()
{
    Trie* root = new Trie();
    insert(root, "actor");
    insert(root, "actress");
    insert(root, "actual");
    insert(root, "apple");
    insert(root, "appliance");
    insert(root, "application");
    insert(root, "apply");
    insert(root, "bandit");
    insert(root, "banker");
    insert(root, "banner");
    insert(root, "bar");
    insert(root, "broken");
    
    string key;
    while (true)
    {
        cout << "Введите слово либо его начало: ";
        cin >> key;

        if (key == "exit")
        {
            cout << "Выход из программы";
            break;
        }
        getPrefix(root, key);    
    }

    return 0;
}

