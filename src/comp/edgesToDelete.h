#ifndef COMP_EDGESTODELETE_H
#define COMP_EDGESTODELETE_H
#include "../common/CommonLibs.hpp"
#include "myalgorithm.h"

#define CAPACITY_VALUE 8

class EdgesToDelete {
	private:	
		vertexid_t *edges;
		label_t *labels;
		int size;
		int capacity;
		int realNumEdges; // exclude duplicate edges

	public:	
		EdgesToDelete();
		~EdgesToDelete(){}
		void clear();

    vertexid_t *getEdges() const {
        return edges;
    }

    label_t *getLabels() const {
        return labels;
    }

    int getRealNumEdges() const {
        return realNumEdges;
    }

    void addOneEdge(vertexid_t edge,label_t label);
		void merge();

};

#endif
