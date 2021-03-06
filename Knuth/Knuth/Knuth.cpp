// Knuth.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "string"
#include "Net.h"
#include "GMLHandler.h"
#include "List.h"
#include "AdjList.h"
#include "Reader.h"
#include "Writer.h"

#include<vector>
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

using namespace BioNet;

int main()
{
	char ch;


	string fname = "three_triads_connect_green_red.gml";
	Reader gm(fname);
	Net bn(-1,1, false, "BioAdjListInt");
	Reader::readFile<GMLHandler>(bn, fname);

	//First Node Test
	if (strcmp(bn.getNode(0).c_str(), "A") != 0)
		cout << "In 1st node got "<< bn.getNode(0) << "instead of A" << "\n";
	//Forth Node Test
	if (strcmp(bn.getNode(3).c_str(), "D") != 0)
		cout << "In 4th node got " << bn.getNode(3) << "instead of D" << "\n";
	//Last Node Test
	if (strcmp(bn.getNode(8).c_str(), "I") != 0)
		cout << "In Last node got " << bn.getNode(8) << "instead of I" << "\n";

	if (!(fabs(0.9 - bn.getEdge(0, 1)) < FLT_EPSILON))
		cout << "Problem in connection between first & second node. Got "<< bn.getEdge(0, 1)<<"instead of 0.9"<< "\n";

	if (!(fabs(0.8 - bn.getEdge(0, 2)) < FLT_EPSILON))
		cout << "Problem in connection between first & third node. Got " << bn.getEdge(0, 2) << "instead of 0.8" << "\n";

	if (!(fabs(0.6 - bn.getEdge(3, 4)) < FLT_EPSILON))
		cout << "Problem in connection between 4th & 5th node. Got " << bn.getEdge(3, 4) << "instead of 0.6" << "\n";

	if (!(fabs(0.5 - bn.getEdge(3, 5)) < FLT_EPSILON))
		cout << "Problem in connection between 4th & 6th node. Got " << bn.getEdge(3, 5) << "instead of 0.5" << "\n";

	if (!(fabs(0.85 - bn.getEdge(7, 8)) < FLT_EPSILON))
		cout << "Problem in connection between 8th & 9th node. Got" << bn.getEdge(7, 8) << "instead of 0.85" << endl;
	
	string path;
	path = "three_triads_connect_green_red_test_target.gml";
	gm.readFile<GMLHandler>(bn, path);
	path = "three_triads_connect_green_red_test_source.gml";
	gm.readFile<GMLHandler>(bn, path);
	path = "three_triads_connect_green_red_test_label.gml";
	gm.readFile<GMLHandler>(bn, path);
	path = "three_triads_connect_green_red_ID.gml";
	gm.readFile<GMLHandler>(bn, path);
	path = "three_triads_connect_green_red_boundary_test_weight2.gml";
	gm.readFile<GMLHandler>(bn, path);
	path = "three_triads_connect_green_red_boundary_test_weight1.gml";
	gm.readFile<GMLHandler>(bn, path);

	///////////// ----------BioList tests ------------//////////////
	string str = "B";
	List<int> bl(str);

	bl.deleteEdge("C");
	/*if (bl.deleteNode("C")) {
		cout << "this was found and deleted";
	}
	else
	{
		cout << "delete failed";
	}*/
	if (bl.insertFront(0.9, "A")) {
		cout << "this node was inserted";
	}
	else
	{
		cout << "insertFront failed";
	}

	if (bl.search("D")) {
		cout << "this node was located";
	}
	else
	{
		cout << "Search failed..!!";
	}
	bl.clear();
	if (bl.search("A"))
		cout << "clear failed !!";

	if (bl.setWeight("G", 0.5))
	{
		cout << "weight set";
	}
	else {
		cout << "error occured while setting weight";
	}


	///////////// ----------BioList tests end ------------//////////////

	///-----BioAdjList tests---------------------///
	
	bn.setNode(0, "A");
	bn.setNode(1, "B");
	bn.setNode(2, "C");

	bn.setEdge(0, 1, 0.1);
	bn.setEdge(0, 2, 0.2);
	bn.setEdge(1, 2, 0.15);

	cout<< "First Node should be A:" << bn.getNode(0);

	cout<< "2nd node should be B: " << bn.getNode(1);

	cout << "Edge between B and C should be 0.15: " << bn.getEdge(1, 2);

	
	///-----BioAdjList tests end---------------------///
	cin.get(ch);
	return 0;
	
}

