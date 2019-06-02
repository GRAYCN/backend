//
// Created by guihang on 2019/5/30.
//

#include "hashGraphStore.h"

PEGraph* hashGraphStore::retrieve(PEGraph_Pointer graph_pointer){

    map<PEGraph_Pointer, edgeSet*> ::iterator it
            = graphMap.find(graph_pointer);
    edgeSet* edges = it -> second;
//    todo  construct PEGraph* using edgeSet*
    PEGraph* peGraph;
    vector<Edge*> graph = edges->graph;
    for (int i = 0; i < graph.size(); ++i) {

    }
    return  peGraph;
}

void hashGraphStore::update(PEGraph_Pointer graph_pointer, PEGraph* pegraph){
    map<PEGraph_Pointer, edgeSet*> ::iterator it
            = graphMap.find(graph_pointer);
    delete it -> second;
    it -> second = NULL;
//    todo convert pegraph* to edgeSet*
    edgeSet* edgeSet;

    graphMap[graph_pointer] = edgeSet;
}

hashGraphStore::hashGraphStore(){
    //  used test data temporarily
}

hashGraphStore::~hashGraphStore(){

}