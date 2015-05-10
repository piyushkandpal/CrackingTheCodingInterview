#include<iostream>
#include<queue>
#include <deque>

using namespace std;
template<typename T, typename Container=std::deque<T> >
class iterable_queue : public std::queue<T,Container>
{
    public:
        typedef typename Container::iterator iterator;
        typedef typename Container::const_iterator const_iterator;
        iterator begin() { return this->c.begin(); }
        iterator end() { return this->c.end(); }
        const_iterator begin() const { return this->c.begin(); }
        const_iterator end() const { return this->c.end(); }
};
/*
int main() {
    iterable_queue<int> int_queue;
    for(int i=0; i<10; ++i)
        int_queue.push(i);
    for(auto it=int_queue.begin(); it!=int_queue.end();++it)
        std::cout << *it << "\n";
    return 0;
}
*/
int main()
{
    queue<int>q;
    printf("pushing 1\n");
    q.push(1);
    printf("pushing 2\n");
    q.push(2);
    cout<<"q.front() == "<<q.front()<<endl;
    cout<<"q.back()== "<<q.back()<<endl;
    cout<<"q.size() == "<<q.size()<<endl;
    cout<<"q.empty() == "<<q.empty()<<endl;
    cout<<"popping "<<q.front();
    q.pop();
    cout<<"q.front() == "<<q.front()<<endl;
    cout<<"testing queue ieterator now... "<<endl;
    iterable_queue<int> iterQ;
    for (int i =0;i<6;i++)
        iterQ.push(i);
    iterable_queue<int>::iterator it;
    for(it=iterQ.begin();it!=iterQ.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
    return 1;
}
