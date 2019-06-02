//
// Created by guihang on 2019/5/30.
//

#ifndef BACKEND_HASHGRAPHSTORE_H
#define BACKEND_HASHGRAPHSTORE_H

#include <CommonLibs.hpp>
#include <graphstore.h>

struct Edge{
    int source;
    int destination;
    char label;
};

class edgeSet
{
private:
    int edgeNum;
    vector<Edge*> graph;
public:

};

class hashGraphStore : public GraphStore{
public:
    PEGraph* retrieve(PEGraph_Pointer graph_pointer);

    void update(PEGraph_Pointer graph_pointer, PEGraph* pegraph);

    hashGraphStore();

    ~hashGraphStore();

private:

    map<PEGraph_Pointer, edgeSet*> graphMap;        // map from PEGraph_Pointer to the edge set in a PEgraph.
};



#endif //BACKEND_HASHGRAPHSTORE_H
