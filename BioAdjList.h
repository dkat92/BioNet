#pragma once
#include "BioAdj.h"
#include "BioList.h"
#include <vector>
#include <string>
#include <map>
using std::vector;
using std::string;
using std::map;


class BioAdjList : public BioAdj
{
private:
	vector<BioList> network;
	map<string, int> names;
public:
	void setEdge(int, int, float);
	void setEdge(string, string, float);
	float getEdge(int, int);
	float getEdge(string, string);
	void setNode(int, string);
	string getNode(int);
};