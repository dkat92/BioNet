// Turing.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "CSVHandler.h"
#include <string>
#include "../../exception/Exception.h"
#include "../../adj/AdjList.h"

using std::cout;
using std::endl;
using BioNet::Exception;

int main()
{
	string fileName = "C:\\Users\\student\\Desktop\\BioNet\\data\\Basic\\mostextreme\\mostextreme.csv";
	BioNet::Reader r(fileName);
	BioNet::Net<float> bioNet(-0.5, 0.5, true);
	r.readFile<CSVHandler, float>(bioNet, fileName);

	//Verify node names
	if (bioNet.getNode(0).compare("\"A\"") != 0) {
		cout << "Error on node A" << endl;
	}

	if (bioNet.getNode(1).compare("\"B\"") != 0) {
		cout << "Error on node B" << endl;
	}

	if (bioNet.getNode(2).compare("\"C\"") != 0) {
		cout << "Error on node C" << endl;
	}

	if (bioNet.getNode(3).compare("\"D\"") != 0) {
		cout << "Error on node D" << endl;
	}

	if (bioNet.getNode(4).compare("\"E\"") != 0) {
		cout << "Error on node E" << endl;
	}

	//Verify Edge's Weight
	float adjMatrix[5][5] = { 
							{ 0.5,-0.5,-0.5,-0.5,-0.5 },
							{ -0.5,0.5,0.5,0.5,0.5 }, 
							{ -0.5,0.5,0.5,0.5,0.5 }, 
							{ -0.5,0.5,0.5,0.5,0.5 }, 
							{ -0.5,0.5,0.5,0.5,0.5 } 
	};

	for (int row = 0; row < 5; ++row) 
		for (int col = 0; col < 5; ++col) 
			if (!(bioNet.getEdge(row, col) > adjMatrix[row][col] - .001 && bioNet.getEdge(row, col) < adjMatrix[row][col] + .001))
				cout << "Edge at " << row << " ," << col << " is incorrect. Recieved: " << bioNet.getEdge(row, col) << " Expected: "  << adjMatrix[row][col] << endl;
	//Test Exceptions

	try 
	{
		string fakeFile = "C:\\Users\\student\\Desktop\\BioNet\\data\\Basic\\FakeFile\\fakefile.csv";
		BioNet::Reader r(fakeFile);
		BioNet::Net<float> fakeBioNet(-0.5, 0.5, true);
		r.readFile<CSVHandler, float>(fakeBioNet, fakeFile);
		cout << "Shoud have revieved an error for opening a non existant file but did not" << endl;
	}
	catch (Exception & bioexcept)
	{
		cout << "Recieved expected exception for bad file\n" << bioexcept.what() <<  endl;
	}

	try
	{
		string brokenFile = "C:\\Users\\student\\Desktop\\BioNet\\data\\Basic\\BrokenFile\\brokenfile.csv";
		BioNet::Reader r(brokenFile);
		BioNet::Net<float> brokenBioNet(-0.5, 0.5, true);
		r.readFile<CSVHandler, float>(brokenBioNet, brokenFile);
		cout << "Shoud have revieved an error for opening an improperly formated file but did not" << endl;

	}
	catch (Exception & bioexcept)
	{
		cout << "Recieved expected exception for improperly formatted file file:\n" << bioexcept.what() << endl;

	}

    return 0;
}
