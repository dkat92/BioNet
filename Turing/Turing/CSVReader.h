#pragma once
#include <string>
#include "..\..\BioNet.h"
#include <iostream>
#include <ios>
#include <vector>
using std::string;
using std::cin;
using std::cout;
using std::vector;

#include "../../Reader.h"
#include "../../Writer.h"

class CSVReader : public Reader, public Writer
{
public:
	CSVReader(/*const string &filename,*/string p="") : Reader(/*filename,*/p), Writer(/*filename,*/ p) {}
	~CSVReader();
	void readFile(BioNet &file, const string & fname);
	void writeFile(BioNet& file, const string& fname) {}
	string getDefaultExt() { return "csv"; }
//private:
	//string _filename;
private :
	vector<string> split(const string &s, char delim);
};

