#ifndef LISTTOMERGE_H
#define LISTTOMERGE_H
#include "edgelist.h"
#include "../containerstomerge.h"

namespace mylist {

class ListsToMerge : public ContainersToMerge {
	private:
		EdgeList *lists;	
		int numOfLists;
		int capacityOfLists;
		int numEdges;	// exclude duplicate edges
		
		// store result
		vertexid_t *edges;
		char *labels;

	public:
		ListsToMerge();
		// getters and setters
		inline bool isEmpty() {return !numOfLists;}
		void mergeKLists();

		// virtual functions
		void addOneContainer() override;
		void addOneEdge(vertexid_t edge,char label) override;
		int getNumEdges() override {return numEdges;}
		void merge() override;
		vertexid_t* getEdgesFirstAddr() override {return edges;}
		char* getLabelsFirstAddr() override {return labels;}
		void clear() override;

};	
}
#endif
