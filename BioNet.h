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
	bool directed;
	string networkType;

public:
	BioNet();
	BioNet(const float, const float, const bool=false, const string& = ADJ_MAT_KEY);
	~BioNet();

	void setRange(const float, const float);
	void setEdge(const int, const int, const float);
	void setNode(const int, const string &n);
	void deleteEdge(const int, const int);
	void deleteEdge(const string &l, const string &r);

	const float shortestPath(const int, const int);
	void resize(const int size);
	void clear();
	// Accessors
	const float getEdge(const int, const int);
	const string getNode(const int);
	const float getMinWeight() { return minweight; }
	const float getMaxWeight() { return maxweight; }
	const std::string & getNetworkType() { return networkType; }

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
	void convertToType(const string &);
	const float degree(const int);
	//void reserve(size_t);
	const size_t size();
	const int numberOfEdges();

   //
   ///////////////////////////////////////////////////////////////////////////////////////////////////////////

};



#endif



