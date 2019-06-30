//
// Created by guihang on 2019/6/9.
//
#include "art.h"
#include <unordered_map>
#include <algorithm>

using namespace std;

ART::ART(){
	//TODO
}

ART::~ART() {
	//TODO

}

//非递归的方法
// ## hash在哪里？
Node *ART::insert(vector<Edge *> &v) {
    if (v.empty()) return nullptr;
    Node *parent = root;
    for (auto &i : v) {
        Node *child = findChild(parent, i);
        if (!child) {
            child = new Node();
            child->data = new Edge(*i);
            child->parent = parent;
            // insert new child to the front of the children
            child->next = parent->children;
            parent->children = child;
        }
        parent = child;
    }
    parent->leafNum++;
    return parent;
}

void ART::insert(vector<Edge *> v, Node *root, int begin) {
    if (v.size() <= begin) {
        root->leafNum++;                    //mark leaf, if node->leafNum>=1, the node is a leaf.
        return;
    }
    Node *child = nullptr;
    // if not find , insert new node to the front of the children
    if (!(child = findChild(root, v[begin]))) {
        child = new Node();
        child->data = new Edge(*v[begin]);
        child->parent = root;

        // insert new child to the front of the children
        child->next = root->children;
        root->children = child;
    }
    // node->childrenNum++;

    // insert deeper
    insert(v, child, ++begin);
}

vector<Edge *> ART::retrieveFromLeaf(Node *node) const {
    vector<Edge *> v;
    while (node->data != nullptr) {
        v.push_back(node->data);
        node = node->parent;
    }
    return v;
}

void ART::del(Node *leaf) {
    if (leaf == nullptr)
        return;
    Node *node = leaf->parent;

    // 要删除的图只有一个叶子结点并且叶子结点没有孩子
    if (leaf->leafNum == 1 && leaf->children == nullptr) {

        if (leaf->parent->children->equal(leaf)) {                  // 如果待删除的是头结点
            if (leaf->next) {                                           //如果有后继
                leaf->parent->children = leaf->next;
            } else {                                                    // 如果没有后继
                leaf->parent->children = nullptr;
            }

            delete leaf;
        } else {                                                    // 如果待删除的不是头结点
            Node *before = leaf->parent->children;                      //找到待删除的之前的结点
            while (!before->next->equal(leaf)) {
                before = before->next;
            }
            before->next = leaf->next;
            delete leaf;
        }
    } else {                                                        // 如果leaf大于1 或者Leaf还有孩子，LeafNum - 1
        leaf->leafNum--;
        return;
    }

    while (node->parent && node->leafNum == 0 && node->children == nullptr) {
        Node *temp = node;
        if (node->parent->children->equal(node)) {
            if (node->next) {
                node->parent->children = node->next;
            } else {
                node->parent->children = nullptr;
            }
            delete node;
        } else {
            Node *before = node->parent->children;
            while (!before->next->equal(node)) {
                before = before->next;
            }
            before->next = node->next;
            delete node;
        }
        node = temp->parent;
    }
}

void ART::DFS(Node *node) {
    if (node->children) {
        DFS(node->children);
    }
    if (node->next) {
        DFS(node->next);
    }
    //access the edge info
}

Node *ART::findChild(Node *parent, Edge *child) {
    if (!parent || !child) return nullptr;
    Node *children = parent->children;
    while (children) {
        if (children->equal(child)) return children;
        children = children->next;\
    }
    return nullptr;
}

PEGraph * ART::convertToPEGraph(vector<Edge *> &v) const {
    PEGraph* peGraph = new PEGraph;
    std::unordered_map<vertexid_t, EdgeArray> graph;

    for(auto & edge : v){
        if(graph.find(edge->src)==graph.end()){
            graph[edge->src].addOneEdge(edge->des, edge->label);
        }
    }

    // todo should we sort the graph?

    peGraph->setGraph(graph);
    return peGraph;
}

vector<Edge *> ART::convertToVector(PEGraph *pegraph) {
    vector<Edge *> v;
    for(auto it = pegraph->getGraph().begin(); it!=pegraph->getGraph().end();it++){
//        Edge * edge = new Edge()
        int size = it->second.getSize();
        vertexid_t* edges = it->second.getEdges();
        label_t* labels = it->second.getLabels();
        Edge* edge;
        for (int i = 0; i < size; ++i) {
            edge = new Edge(it->first, labels[i], edges[i]);
            v.push_back(edge);
            delete edge;
        }
    }
    return v;
}

void ART::update(PEGraph_Pointer graph_pointer, PEGraph *pegraph) {
    Node *node = m[graph_pointer];
    del(node);
    vector<Edge *> v = convertToVector(pegraph);
    // todo we can sort v before insert
    Node *leaf = insert(v);
    m[graph_pointer] = leaf;
}


PEGraph * ART::retrieve(PEGraph_Pointer graph_pointer) {
    if (m.find(graph_pointer)!= m.end()){
        Node* node = m[graph_pointer];
        vector<Edge *> v = retrieveFromLeaf(node);
        return convertToPEGraph(v);
    }
    return nullptr;
}

void ART::edgeSort(vector<vector<Edge *>> &edges) {
    unordered_map<Edge, int> sortBase;
    for (auto &graph : edges) {
        for (auto &edge : graph) {
            if (sortBase.find(*edge) == sortBase.end()) {
                sortBase[*edge] = 1;
            } else {
                sortBase[*edge]++;
            }
        }
    }

    for (auto &graph : edges) {
        sort(graph.begin(), graph.end(), [&sortBase](const Edge *lhs, const Edge *rhs) -> bool {
            return sortBase[*lhs] > sortBase[*rhs];
        });
    }
}

void ART::loadGraphStore(const string &file_singleton) {

}

void ART::addOneSingleton(vertexid_t t) {
    GraphStore::addOneSingleton(t);
}

bool ART::isSingleton(vertexid_t vid) {
    return GraphStore::isSingleton(vid);
}

void ART::print(ostream &str) const {

}





//ART::ART(){}
