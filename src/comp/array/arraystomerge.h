#ifndef COMP_ARRAY_ARRAYSTOMERGE_H
#define COMP_ARRAY_ARRAYSTOMERGE_H
#include "../../common/CommonLibs.hpp"
#include "../containerstomerge.h"

#define _CAPACITY_VALUE 8	// TODO: modify this number
#define CAPACITY_VALUE 8	// TODO: modify this number

namespace myarray {
class ArraysToMerge : public ContainersToMerge {
	/* 	turn vector<vector> to 1D array 
	 * 	faster and smaller(RAM)
	 */ 
private:
	vertexid_t *edges{};
	char *labels{};
	int size;
	int capacity;

	vertexid_t *index{};
	vertexid_t *addr{};
	int arraySize;
	int arrayCapacity;

	int numEdges;
	vertexid_t *resEdges;
	char *resLabels;

public:
	ArraysToMerge();
	// getters and setters
	inline bool isEmpty() {return !arraySize;}
	void mergeKArrays();

	// virtual function
	void addOneContainer() override;
	void addOneEdge(vertexid_t edge,char label) override;
	int getNumEdges() override {return numEdges;}
	void merge() override;
	vertexid_t* getEdgesFirstAddr() override {return resEdges;}
	char* getLabelsFirstAddr() override {return resLabels;}
	void clear() override;
};
}
#endif
