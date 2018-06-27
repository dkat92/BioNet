#pragma once

#include "BioNet.h"
#include "IO.h"
#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;


class Writer : public IO {

public:
	Writer(string p = IO::getDefaultPath()) : IO(p) {}
	
	template <typename R, typename T>
	void writeFile(BioNet<T>& bn, string& fname, bool useDefault = true) 
	{
		fname = (useDefault ? defaultPath : "") + fname;
		R::doWrite(bn, fname);
	}; 
};