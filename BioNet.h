#ifndef BIONET_H
#define BIONET_H
#include <string>
#include <vector>
#include <typeindex>
#include "BioAdj.h"
using std::string;
using std::pair;
using std::vector;
using std::type_index;


#define NETWORK_SIZE 5  //converting network/names to vectors - EINSTEIN
class BioNet {
   ////////////////////////////////////////////////////////////////////////////////////////////////////////////
   // MORNING COHORT EINSTEIN
   //
   //
private:
	float minweight;
	float maxweight;
	BioAdj* network;
	bool directed;//

public:
	BioNet();
	BioNet(float, float, bool=false, string = "matrix");
	~BioNet();

	void setRange(float, float);
	void setEdge(int, int, float);
	void setNode(int, string);
	void deleteEdge(int, int);
	void deleteEdge(string, string);

	float shortestPath(int, int);
	void resize(int size);
	void clear();
	// Accessors
	float getEdge(int, int);
	string getNode(int);
	float getMinWeight() { return minweight; }
	float getMaxWeight() { return maxweight; }

   ///////////////////////////////////////////////////////////////////////////////////////////////////////////

   ////////////////////////////////////////////////////////////////////////////////////////////////////////////
   // MORNING COHORT TURING
   //
   //
   ///////////////////////////////////////////////////////////////////////////////////////////////////////////

   ////////////////////////////////////////////////////////////////////////////////////////////////////////////
   // AFTERNOON COHORT KNUTH
   //
   //
   ///////////////////////////////////////////////////////////////////////////////////////////////////////////

   ////////////////////////////////////////////////////////////////////////////////////////////////////////////
   // AFTERNOON COHORT DIJKSTRA
   //
	void convertToType(string);
	float degree(int);
	//void reserve(size_t);
	size_t size();
	int numberOfEdges();

   //
   ///////////////////////////////////////////////////////////////////////////////////////////////////////////

};



#endif



