#include<iostream>
#include<vector>
#include<map>
#include<list>
#include<algorithm>
// for std::find
using namespace std;

template<typename K,typename V>
class Hash
{
    private:
        const int MAX_SIZE=10;
        list<Cell<K,V> > *items;
    public:
        Hash()
        {
            items = new list<Cell<K,V> >[MAX_SIZE];
            
        }
        int hashCodeOfKey(K& key)
        {
            //TBD implementation of toString in Cell 
            return (key.toString().size())%items.size()
        }
        void put(K key,V value)
        {
            int x = hashCodeOfKey(key);
            if(items[x].size()==0)
            {

            }
            list<Cell<K,V> > collided = items[x];
            //look for items with same key and replace it.
            // bool found = (std::find(my_var.begin(), my_var.end(), my_variable) != my_var.end());
            // You need to include <algorithm>. It should work on standard containers, vectors lists, etc...
            for (int i=0;i<MAX_SIZE;i++)
            {
                list<Cell<K,V> >::iterator it;
                for(it = collided.begin();it!=collided.end();it++)
                {
                    if((*it).equivalent(key))
                    {
                        return collided.remove(*it);
                        break;
                    }
                }
                Cell<K,V> cell = new Cell<K,V>(key,value);
                collided.push_back(cell);
            }
        }
           
        V get(const K& key) const
        {
            int x = hashCodeOfKey(key);
            if(items[x].size==0)
                return NULL;
            list<Cell<K,V> > clist = items[x];
            list<Cell<K,V> >::iterator citer;
            for( citer=clist.begin();citer!=clist.end();citer++)
            {
                if((*citer).equivalent(key))
                {
                    return (*citer).getValue();
                }
            }
            return NULL;
        }

};

template<typename K,typename V>
class Cell
{
    private:
        K key;
        V value;
    public:
        Cell(K key,V value)
        {
            this->key=key;
            this->value=value;
        }
        bool equivalent(Cell<K,V> c)
        {
            return c.equivalent(c.getKey());
        }
        bool equivalent(K k)
        {
            return key.equals(k);//equals method has to be implemented by class Key
        }
        K getKey()
        {
            return key;
        }
        V getValue()
        {
            return value;
        }
};
/*
 * 19 }
 * Another common implementation for a hash table is to use a binary search tree as the
 * underlying data structure. Retrieving an element will no longer be 0(1) (although,
 * technically, it's not 0(1) if there are many collisions), but it prevents us from creating an
 * unnecessarily large array to hold items.
 * CrackingTheCodinglnterview*/
