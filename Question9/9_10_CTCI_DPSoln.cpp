#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Box
{
        int l,b,h;
    public:
        Box(int l,int b , int h):l(l),b(b),h(h) {};
        int getHeight()
        {
            return this->h;
        }
        bool canBeAbove(Box &other)
        {
            return (this->b < other.b && this->l < other.l && this->h < other.h);
        }
};
typedef map<Box*,vector<Box> > boxMap;

int stackHeight(vector<Box>* stackPtr)
{
   int height=0;
   vector<Box>::iterator bit;
   for(bit= stackPtr->begin();bit!=stackPtr->end();bit++)
   {
        height+=bit->getHeight();
   }
    return height; 
}

vector<Box>* createStack(vector<Box>* boxes,Box *bottom,boxMap &bMap)
{
    if(bMap.count(bottom)!=0 && bottom!=NULL)
    {
        return &bMap[bottom];
    }
    int maxHeight = 0;
    vector<Box>* maxStackPtr=NULL;
    for (int i=0;i<boxes->size();i++)
    {
        Box* b = &boxes->at(i); 
        if (b->canBeAbove(*bottom))
        {
            vector<Box>* newStack = createStack(boxes,b,bMap);
            int newHeight = stackHeight(newStack);
            if(newHeight > maxHeight)
            {
                maxStackPtr = newStack;
                maxHeight = newHeight;
            }
        }
    }
    //maxStackPtr will be NULL for the case where bottom box is the largest one
    if (maxStackPtr == NULL)
    {
        maxStackPtr = new vector<Box>;
    } 
    if( bottom != NULL)
    {
        maxStackPtr->push_back(*bottom);
        bMap[bottom] = *maxStackPtr;
    }
    return maxStackPtr;
}

int main()
{
    vector<Box>* vbox = new vector<Box>;
    Box* bottom = new Box(4,6,7);
    vbox->push_back(*bottom);
    vbox->push_back(Box(1,2,3));
    vbox->push_back(Box(4,5,6));
    vbox->push_back(Box(10,12,32));
    boxMap bMap;
    vbox = createStack(vbox,bottom,bMap);
    cout<<"The maximum possible height of stack is :"<<stackHeight(vbox)<<"\n";
    return 0;
}
