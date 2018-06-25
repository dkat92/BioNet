#pragma once

#include "BioNet.h"
#include "IO.h"
#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;


class Writer : public IO {
protected:  // Accessible in Reader and classes that inherit from Reader
	//string _filename;

public:
	Writer(/*const string& fname,*/ string e, string p = "") : /*_filename(fname),*/ IO(p) {}
	virtual void writeFile(BioNet&, const string& fname) = 0; // Abstract virtual functions
						
	virtual void f() { cout << "F OF WRITER" << endl; }//{ cout << "BLANK READFILE FOR NOW" << endl; }
};