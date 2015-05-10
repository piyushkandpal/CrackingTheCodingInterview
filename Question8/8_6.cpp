#include<iostream>
#include<vector>
using namespace std;
class Edge
{
    enum Type{inner,outer,flat};
    Piece parent;
    int index; // index into the Piece.edges
    static Type type;
    Edge attached_to;
    //assumed it is already provided
    bool fitsWith(Edge &edge) {...};
    static bool isFlat(Edge &e)
    {
        return (e.type == flat) 
    }
};
Edge::Type Edge::type = Edge::flat;

class Piece
{
    Edge edges[4];
    bool isCorner() {};
};

bool Piece::isCorner()
{
    // find if edges have 2 flat edges
    int count = count(edges,edges+3,Edge::isFlat);
}
class Puzzle
{
    private:
        vector<Piece> pieces;/* Remaining pieces left to put away*/
        vector<vector<Piece> >solution;
        // better to use linked lists here as we need to add remove frequently
        vector<Edge> inners,outers,flats;
        vector<Piece> corners;
        //list<Edge> inners,outers,flats;
        //list.push_back,pop_back,push_front,pop_front,remove(val),erase(it)
    public:
        void sort(){};
        void solve(){};
};

void Puzzle::sort()
{
    vector<Piece>::iterator p;
    for(p=pieces.begin();p!=pieces.end();p++)
    {
        if(*p.isCorner())
            corners.push_back(*p);
        for(int i =0;i<4;i++)
        {
            if (*p.edges[i].type == Edge::inner)
               inners.push_back(*p.edges[i])

            if (*p.edges[i].type == Edge::outer)
                outers.push_back(*p.edges[i])

        }
    }
}

void Puzzle::solve()
{
    // Pick any corber to start with
    // Loop will iterate in a spiral fashion until puzzle is full
    Edge currentEdge = getExposedEdge(corner[0]);
    while (currentEdge!=NULL)
    {
        vector<Edge> opposites = currentEdge.type == Edge::inner? outers:inners;
        vector<Edge>::iterator fittingEdge;
        for(fittingEdge=opposites.begin();fittingEdge!=opposites.end();fittingEdge++)
        {
            if (currentEdge.fitsWith(*fittingEdge))
            {
                attachEdges(currentEdge,*fittingEdge);
                removeFromList(currentEdge);
                removeFromList(*fittingEdge);
                //get Next edge
                currentEdge = nextExposedEdge(fittingEdge);
                break;
            }
        }
    }
}

void removeFromList(Edge &edge)

{
    // we dont match flat edges hence we dont remove them from list
    if (edge.type == Edge::flat)
        return;
    vector<Edge> edges = (edge.type == Edge::inner?&inners:&outers);
    // erase-remove-idiom
    // vec.erase(std::remove(vec.begin(), vec.end(), 8), vec.end());
    edges.erase(remove(edges.begin(),erase.end(),edge));
}

Edge& nextExposedEdge(Edge &edge)
{
    int next_index = (edge.index+2)%4;
    Edge next_edge = edge.parent.edges[next_index];
    if isExposed(next_edge)
    {
        return next_edge;
    }
    return getExposedEdge(edge.parent);
}

void attachEdges(Edge &e1,Edge &e2)
{
    e1.attached_to = e2;
    e2.attached_to = e1;
}

bool isExposed(Edge &e)
{
    return (e.attached_to==NULL) && (e.type!=flat);
}

Edge& getExposedEdge(Piece &p)
{
    for(int i =0;i<4;i++)
    {
        if isExposed(p.edges[i])
            return &p.edges[i];
    }
    return NULL;
}



