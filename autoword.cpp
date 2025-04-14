#include "autoword.h"


Trie* getNewNode(void)
{
    struct Trie* node = new Trie;
    node->isendofWord = false;
    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        node->children[i] = nullptr;
    }
    return node;
}

void insert(Trie *root, std::string key)
{
    // Начинаем с корня дерева
    Trie* curent = root;
    // Проходим по каждому символу ключа
    for (int i = 0; i < key.length(); i++)
    {
        // получаем индекс символа
        int index = key[i] - 'a';
        // если дочернего узла нет создаем его
        if (curent->children[index] == nullptr)
        {
            curent->children[index] = getNewNode();
        }
        // переходим к следующему узлу
        curent = curent->children[index];
    }
    // устанавливаем флаг что это конец слова
    curent->isendofWord = true;
}

bool isEmpty(Trie *root)
{
    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        if (root->children[i])
        {
            std::cout << "Есть дочерний узел" << std::endl;
            return false;
        }
    }
    std::cout << "Нет дочернего узла" << std::endl;
    return true;
}

Trie* remove(Trie *root, std::string key, int depth)
{
    // Если дерево пустое - вернуть null
    if (!root)
    {
        return nullptr;
    }
    // Если дошли до конца узла
    if (depth == key.size())
    {
        // Этот узел больше не конец слова - снимаем метку
        if (root->isendofWord)
        {
            root->isendofWord = false;
        }
        // Если ключ не является префиксом удаляем его
        if (isEmpty(root))
        {
            delete root;
            root = nullptr;
        }
        return root;
    }
    int index = key[depth] - 'a';
    root->children[index] = remove(root->children[index], key, depth + 1);
    if (isEmpty(root) && root->isendofWord == false)
    {
        delete root;
        root = nullptr;
    }
    return root;
}

void collectWord(Trie *node, std::string key, std::string* res, int& count)
{
    if (node == nullptr)
    {
        return;
    }
    if (node->isendofWord)              // если текущиее слово конец узла
    {
        res[count++] = key;             // записываем наш ключ в результат
    }
    for (int i = 0; i < ALPHABET_SIZE; i++)     // обходим всех возможных детей
    {
        if (node->children[i] != nullptr)
        {
            char next = 'a' + i;
            collectWord(node->children[i], key + next, res, count);
        }
    }
}

Trie *findNode(Trie *root, std::string &key)        // поиск узла по ключу
{
    Trie* curent = root;
    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!curent->children[index])
        {
            return nullptr;
        }
        curent = curent->children[index];
    }
    return curent;
}

void getPrefix(Trie* root, std::string key)
{
    Trie* node = findNode(root, key);               // находим наш узел
    if (node == nullptr)
    {
        std::cout << "Префикс не найден - слов нет" << std::endl;
        return;
    }
    std::string results[20];
    int count = 0;
    collectWord(node, key, results, count);              // собираем слова
    if (count == 0)
    {
        std::cout << "Нет слов начинающихся с " << key << std::endl;
        return;
    }
    for (int i = 0; i < count; i++)
    {
        std::cout << "- " << results[i] << std::endl;
    }
}

