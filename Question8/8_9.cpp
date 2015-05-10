#include<iostream>
#include<vector>
#include<map>
using namepsace std;
class Entry {
    protected: 
        // all files/dirs will have a parent as a Directory only
        // Dir is taken to be a pointer as parent can beNULL as well in which case we cant use references.
        Directory* parent;
        long created;
        long lastupdated;
        long lastAccessed;
        String name;
    public: 
        Entry(String n, Directory *p) 
        {
            name = n;
            parent = p;
            created = System.currentTimeMillis();
            lastupdated = System.currentTimeMillis();
            lastAccessed = System.currentTimeMillis();
        }
        boolean delete() 
        {
            if (parent == null) return false;
            return parent->deleteEntry(this);
        }
        virtual int size() = ;
        String getFullPath() 
        {
            if (parent == null) return name;
            else 
                return parent->getFullPath() + "/" + name;
        }
        /* Getters and setters. */
        long getCreationTime() { return created; }
        long getLastUpdatedTime() { return lastupdated; }
        long getLastAccessedTime() { return lastAccessed; }
        void changeName(String n) { name = n; }
        String getName() { return name; }
};

 public class File:public Entry 
{
    private: 
        String content;
        int size;
    public:
         File(String n, Directory p, int sz):Entry(n,p) 
         {
            size = sz;
         }
        int size() { return size; }
        String getContents() { return content; }
        void setContents(String c) { content = c; }
 };

class Directory:public Entry 
{
    protected: 
        vector<Entry> contents;
    public: 
        Directory(String n, Directory p):Entry(n,p) 
        {
            contents = new vector<Entry>;
        }
    public: 
        int size() 
        {
            int size = 0;
            vector<Entry>::iterator e;
            for (e= contents.begin();e!=contents.end();e++)
            {
                size += e->size();
            }
            return size;
        }
        int numberOfFiles() 
        {
             int count = 0;
             vector<Entry>::iterator e;
             for (e=contents.begin();e!=contents.end();e++)
             {
                // for typeid .. include <typeinfo> 
                if (typeid(*e) == typeid(Directory)) 
                {
                     count++; // Directory counts as a file
                     Directory* d = static_cast<Directory*>e;
                     count += d->numberOfFiles();
                } 
                else if (typeid(*e)==typeid(File)) 
                {
                     count++;
                }
             }
             return count;
        }

        boolean deleteEntry(Entry &entry) 
        {
            //user erase remove idiom as there us no remove in vector.. only erase by position
            contents.erase(remove(contents.begin(),contents.end(),*entry),contents.end());
        }

        void addEntry(Entry &entry) 
        {
            contents.push_back(entry);
        }
     protected:
         vector<Entry>& getContents() { return contents; }
};


