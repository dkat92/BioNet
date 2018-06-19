#ifndef BIONET_H
#define BIONET_H

#include <string>
using std::string;

class BioNet {

   ////////////////////////////////////////////////////////////////////////////////////////////////////////////
   // MORNING COHORT EINSTEIN
   //
   //
   ///////////////////////////////////////////////////////////////////////////////////////////////////////////
private:
	float minweight;
	float minweight;
	float network[5][5];
	string names[5];

public:
	BioNet();
	BioNet(float, float);
	~BioNet();

	void setRange();
	void setNetwork(int, int, float);
	void setName(int, string);
	// Accessors
	float getNetwork(int, int);
	string getName(int);
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
   //
   ///////////////////////////////////////////////////////////////////////////////////////////////////////////

};



#endif



