//
// Created by guihang on 2019/6/9.
//
#include <art.h>

Node* ART::insert(vector<Edge>& v){
    if (v.empty()) return nullptr;
    Node* parent = &root;
    for (int i = 0; i < v.size(); ++i) {
        Node* child = findChild(parent, &v[i]);
        if (!child) {
            child = new Node();
            child->data = new Edge(v[i]);
            child->parent = parent;
            // insert new child to the front of the children
            child->next = parent->children;
            parent->children = child;
        }
        parent = child;
    }
    return parent;
}

void ART::insert(vector<Edge> v, Edge root, int begin){
    if (v.size() <= begin) {
        node->leafNum++;                    //mark leaf, if node->leafNum>=1, the node is a leaf.
        return;
    }
    Node* child = nullptr;
    // if not find , insert new node to the front of the children
    if (!(child = findChild(node, &v[begin]))) {
        child = new Node();
        child->data = new Edge(v[begin]);
        child->parent = node;

        // insert new child to the front of the children
        child->next = node->children;
        node->children = child;
    }
    // node->childrenNum++;

    // insert deeper
    insert(v, child, ++begin);
}

vector<Edge*> ART::retrieve(Node* node){
    vector<Edge*> v;
    while (node->Edge != nullptr){
        v.push_back(node->Edge);
        node = node->parent;
    }
    return v;
}

void ART::del(Node* leaf){
    if(leaf == nullptr)
        return;
    Node* node = leaf->parent;
    //Node* temp = node;
    if (leaf->leafNum == 1 && leaf->children==nullptr)
    {

        if (leaf->parent->children->equal(leaf))
        {
            if (leaf->next) {                                       // 1.1.1 if the node has next
                leaf->parent->children = leaf->next;
            } else {                                                // 1.1.2 if the node does not have next
                leaf->parent->children = NULL;
            }

            delete leaf;
            leaf = nullptr;
        }else{
            Node* before = leaf->parent->children;                                    // before is the node before the node to be deleted
            while (!before->next->equal(leaf)) {
                before = before->next;
            }
            before->next = leaf->next;
            delete leaf;
            leaf = nullptr;
        }
    }else{
        leaf->leafNum--;
        return;
    }

    while (node->parent && node->leafNum==0 && !node->children)
    {
        Node* parent = node->parent;

        if (node->parent->children->equal(node))
        {
            if (node->next) {                                       // 1.1.1 if the node has next
                node->parent->children = node->next;
            } else {                                                // 1.1.2 if the node does not have next
                node->parent->children = NULL;
            }
            delete node;
            node = nullptr;
        }else{
            Node* before = node;                                    // before is the node before the node to be deleted
            while (!before->next->equal(node)) {
                before = before->next;
            }
            before->next = node->next;
            delete node;
            node = nullptr;
        }
        node = node->parent;
    }
    return;
}

void ART::DFS(Node *node){
    if(node->children){
        DFS(node->children);
    }
    if(node->next){
        DFS(node->next);
    }
    printf("%s\n", node->toString());
}

Node* ART::findChild(Node* parent, Edge* child){
    if (!parent || !child) return nullptr;
    Node *children = parent->children;
    while (children)
    {
        if (children->equal(child)) return children;
        children = children->next;
    }
    return nullptr;
}


PEGraph* ART::retrieve(PEGraph_Pointer graph_pointer){
    Node* node = m[graph_pointer];
    vector<Edge*> v =  retrieve(node);
    return convertToPEGraph(v);
}

void ART::update(PEGraph_Pointer graph_pointer, PEGraph* pegraph){
    Node* node = m[graph_pointer];
    del(node);
    vector<Edge*> v = convertToVector(pegraph);
    Node* leaf = insert(v);
    m[graph_pointer] = leaf;
}

PEGraph* ART::convertToPEGraph(vector<Edge*>& v){
    //todo
}

vector<Edge*> ART::convertToVector(PEGraph* pegraph){
    //todo
}