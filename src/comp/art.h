/*
 * art.h
 *
 *  Created on: May 22, 2019
 *      Author: zqzuo
 */

#ifndef COMP_ART_H_
#define COMP_ART_H_

#include "graphstore.h"
#include <map>

struct Edge {
    int src;
    int des;
    char label;
    int frequency;
    Edge() {};
    Edge(int src, char label, int des) : src(src), label(label), des(des), frequency(frequency) {};
    Edge(const Edge& edge) {
        this->src = edge.src;
        this->des = edge.des;
        this->label = edge.label;
    }
    bool equal(Edge* other) {
        if (!other) return false;
        return this->src == other->src && this->des == other->des && this->label == other->label;
    }
};

struct Node {
    Edge* data;
    Node* parent;
    Node* children;
    Node* next;
    int leafNum;
    Node() : parent(nullptr), children(nullptr), data(nullptr), next(nullptr), leafNum(0) {};
    bool equal(Node* other) {
        if (!other)return false;
        return this->data->equal(other->data);
    }
    bool equal(Edge* other) {
        if (!other)return false;
        return this->data->equal(other);
    }
    void toString(){
        cout<<this->data->src<<" "<<this->data->label<< " "<<this->data->des<<endl;
    }
};

class ART: public GraphStore {

public:
	~ART(){}

	PEGraph* retrieve(PEGraph_Pointer graph_pointer);

    void update(PEGraph_Pointer graph_pointer, PEGraph* pegraph);

    Node* insert(vector<Edge>& v);

    void insert(vector<Edge> v, Edge root, int begin);

    vector<Edge*> retrieve(Node* node);

    void del(Node* leaf);

    void DFS(Node *node);

    Node* findChild(Node* parent, Edge* child);

    PEGraph* convertToPEGraph(vector<Edge*>& v);

    vector<Edge*> convertToVector(PEGraph* pegraph);

private:
    Node* root;
    map<PEGraph_Pointer, PEGraph*> m;
};




#endif /* COMP_ART_H_ */
