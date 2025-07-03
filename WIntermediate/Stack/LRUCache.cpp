#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Node
{
public:
    int key;
    int value;
    Node *next;
    Node *prev;

public:
    Node(int key_, int value_)
    {
        key = key_;
        value = value_;
        next = nullptr;
        prev = nullptr;
    }
};

class LRUCache
{
public:
    int capacity;
    unordered_map<int, Node *> cache;
    int size = 0;
    Node *head;
    Node *tail;

    LRUCache(int capacity_)
    {
        cache.clear();
        capacity = capacity_;
        size = 0;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    void insertAfterHead(Node *&nodeAddress)
    {
        nodeAddress->next = head->next;
        head->next = nodeAddress;
        nodeAddress->prev = head;
        nodeAddress->next->prev = nodeAddress;
    }

    void deleteBeforeTail(Node *&nodeAddress)
    {
        nodeAddress->prev->next = nodeAddress->next;
        nodeAddress->next->prev = nodeAddress->prev;
    }

    int get(int key)
    {
        if (cache.find(key) == cache.end())
            return -1;
        Node *nodeAddress = cache[key];
        deleteBeforeTail(nodeAddress);
        insertAfterHead(nodeAddress);
        return nodeAddress->value;
    }

    void put(int key, int value)
    {
        if (cache.find(key) != cache.end())
        {
            Node *nodeAddress = cache[key];
            nodeAddress->value = value;
            deleteBeforeTail(nodeAddress);
            insertAfterHead(nodeAddress);
        }
        else
        {
            if (size >= capacity)
            {
                Node *nodeToRemove = tail->prev;
                cache.erase(nodeToRemove->key);
                deleteBeforeTail(tail->prev);
                delete nodeToRemove;
                size--;
            }

            Node *newNode = new Node(key, value);
            insertAfterHead(newNode);
            cache[key] = newNode;
            size++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */