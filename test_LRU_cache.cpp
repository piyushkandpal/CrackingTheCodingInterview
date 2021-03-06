#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

template<class K, class T>
struct LRUCacheEntry
{
    K key;
    T data;
    LRUCacheEntry* prev;
    LRUCacheEntry* next;
};

template<class K, class T>
class LRUCache
{
private:
    unordered_map< K, LRUCacheEntry<K,T>* >  _mapping;  // map key with LRUCacheEntry DLL Node
    vector<LRUCacheEntry<K,T>*>_freeEntries;           // vector of DLL Node pointers
    LRUCacheEntry<K,T> *head; 
    LRUCacheEntry<K,T> *tail;
    LRUCacheEntry<K,T> *entries;
public:
    LRUCache(size_t size)
    {
        entries = new LRUCacheEntry<K,T>[size];    // array of uninitialised DLL Nodes
        for (int i=0; i<size; i++)
            _freeEntries.push_back(entries+i);   // inside vector of DLL node pointers , point every pointer to a node in the array till (size) no of nodes
        head = new LRUCacheEntry<K,T>;
        tail = new LRUCacheEntry<K,T>;
        head->prev = NULL;
        head->next = tail;
        tail->next = NULL;
        tail->prev = head;
    }
    ~LRUCache()
    {
        delete head;
        delete tail;
        delete [] entries;
    }
    void put(K key, T data)
    {
        LRUCacheEntry<K,T>* node = _mapping[key];  // hash_map
        if(node)
        {
            // refresh the link list
            detach(node);
            node->data = data;  // new data for same key
            attach(node);
        }
        else{
            if ( _freeEntries.empty() )
            {
                node = tail->prev;
                detach(node);
                _mapping.erase(node->key); //hash_map api
                node->data = data;
                node->key = key;
                _mapping[key] = node;
                attach(node);
            }
            else{
                node = _freeEntries.back();
                _freeEntries.pop_back();
                node->key = key;
                node->data = data;
                _mapping[key] = node;
                attach(node); //attach it at the head
            }
        }
    }
T get(K key)
    {
        LRUCacheEntry<K,T>* node = _mapping[key];
        if(node)
        {
            detach(node);
            attach(node);
            return node->data;
        }
        else return NULL;
    }
private:
    void detach(LRUCacheEntry<K,T>* node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    void attach(LRUCacheEntry<K,T>* node)
    {
        node->next = head->next;
        node->prev = head;
        head->next = node;
        node->next->prev = node;
    }
};

int main()
{
    
}
