#pragma once

#include <vector>
#include <string>
#include "BioAdj.h"

using std::vector;
using std::string;

class BioAdjMat : public BioAdj
{
private:
	vector<vector<float>> matrix;
	vector<string> names;

public:
	BioAdjMat(int size) {
		names.resize(size);
		matrix.resize(size);
		for (auto n : matrix)
			n.resize(size);
	}
	~BioAdjMat() {}

	virtual void setEdge(int, int, float);
	virtual void setEdge(string, string, float);
	virtual float getEdge(int, int);
	virtual float getEdge(string, string);
	virtual void setNode(int, string);
	virtual string getNode(int);
	virtual int size();
	virtual void resize(int);
	int findNodeIndex(const string&);
	void deleteEdge(const string &, const string &);
	void deleteEdge(int, int);
	void deleteNode(const string &);
	void deleteNode(int);
};