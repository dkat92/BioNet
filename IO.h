#pragma once


#include <string>
using std::string;
class IO {
protected:
	string defaultPath;
	//static string defaultExt ;
public:
	IO(string path = "") : defaultPath(path) { };

	//Accessor
	virtual string getDefaultExt() = 0;
	//virtual void setDefaultExt(string e) = 0;
	string getDefaultPath() { return defaultPath;  }
	void setDefaultPath(string p) { defaultPath = p; }
	
};