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
	vertexid_t *edges;	// edges = new vertexid_t[capacity];
	char *labels;		// labels = new char[capacity];
	int size;			// size = total number of edges
	int capacity;		// capacity = 2 * size

	vertexid_t *index;	// calculate offset of each array. index = new vertexid_t[arrayCapacity];
	vertexid_t *addr;	// store the firstAddr of each array. addr = new vertexid_t[arrayCapacity];
	int arraySize; 		// arraySize = number of arrays 
	int arrayCapacity;	// arrayCapacity = 2 * arraySize

	int numEdges;		// exclude duplicate edges (numEdges <= size)
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
