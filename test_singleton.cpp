#include<iostream>
#include<list>
using namespace std;
class Singleton;
typedef std::pair<const char *,Singleton *> NameSingletonPair;
class Singleton 
{
    public:
        static void Register(const char* name, Singleton*);
        static Singleton* Instance();
    
    protected:
        static Singleton* Lookup(const char* name);
    
    private:
        static Singleton* _instance;
        static list<NameSingletonPair>* _registry;
};
Singleton* Singleton::_instance = 0;
Singleton* Singleton::Instance () 
{
    if (_instance == 0) 
    {
        cout<<"jnwkjws"<<endl;
        const char* singletonName = getenv("SINGLETON");
        // user or environment supplies this at startup
        //_instance = Lookup(singletonName);
        // Lookup returns 0 if there's no such singleton
        cout<<"Name =="<<singletonName<<endl;
    }
    return _instance;
}

void Singleton::Register(const char* name, Singleton*)
{
    Singleton::Instance();
}

class MySingleton:public Singleton
{
    public:
        MySingleton() 
        {
            Singleton::Register("MySingleton", this);
        }
};

static MySingleton theSingleton;
int main()
{   
    return 1;
}
