#pragma once
#define ALPHABET_SIZE 26
#include <string>
#include <iostream>

struct Trie
{
    Trie* children[ALPHABET_SIZE];
    bool isendofWord;
    int count;
    Trie()
    {
        isendofWord = false;
        for (int i = 0; i < ALPHABET_SIZE; i++)
        {
            children[i] = nullptr;
        }
        count = 0;
    }
};

Trie* getNewNode(void);                                                     // Возвращает новый узел с пустыми детьми
void insert(Trie* root, std::string key);                                   // Вставка в дерево
bool isEmpty(Trie* root);                                                   // Определяет что поддерево пусто и узел является листом
Trie* remove(Trie* root, std::string key, int depth = 0);                   // Удаление из дерева

void collectWord(Trie* node, std::string key, std::string* res, int& count);    // собирает все слова 
Trie* findNode(Trie* root, std::string& key);                                   // поиск узла по ключу
void getPrefix(Trie* root, std::string key);                                    // главная функция автодополнения введенного слова
