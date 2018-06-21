// Knuth.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "string"
#include "../../BioNet.h"
#include "GMLReader.h"


#include <iostream>
using std::cout;
using std::cin;
using std::endl;
int main()
{
	char ch;
	GMLReader gm("C:\\Users\\student\\Desktop\\BioNet\\data\\Basic\\three_triads\\three_triads_connect_green_red.gml");
	BioNet bn(-1,1);
	gm.ReadFile(bn, "C:\\Users\\student\\Desktop\\BioNet\\data\\Basic\\three_triads\\three_triads_connect_green_red.gml");

	//First Node Test
	if (strcmp(bn.getNode(0).c_str(), "A") != 0)
		cout << "In 1st node got "<< bn.getNode(0) << "instead of A" << endl;
	//Forth Node Test
	if (strcmp(bn.getNode(3).c_str(), "D") != 0)
		cout << "In 4th node got " << bn.getNode(3) << "instead of D" << endl;
	//Last Node Test
	if (strcmp(bn.getNode(8).c_str(), "I") != 0)
		cout << "In Last node got " << bn.getNode(8) << "instead of I" << endl;

	if (!(fabs(0.9 - bn.getEdge(0, 1)) < FLT_EPSILON))
		cout << "Problem in connection between first & second node. Got "<< bn.getEdge(0, 1)<<"instead of 0.9"<< endl;

	if (!(fabs(0.8 - bn.getEdge(0, 2)) < FLT_EPSILON))
		cout << "Problem in connection between first & third node. Got " << bn.getEdge(0, 2) << "instead of 0.8" << endl;

	if (!(fabs(0.6 - bn.getEdge(3, 4)) < FLT_EPSILON))
		cout << "Problem in connection between 4th & 5th node. Got " << bn.getEdge(3, 4) << "instead of 0.6" << endl;

	if (!(fabs(0.5 - bn.getEdge(3, 5)) < FLT_EPSILON))
		cout << "Problem in connection between 4th & 6th node. Got " << bn.getEdge(3, 5) << "instead of 0.5" << endl;

	if (!(fabs(0.85 - bn.getEdge(7, 8)) < FLT_EPSILON))
		cout << "Problem in connection between 8th & 9th node. Got" << bn.getEdge(7, 8) << "instead of 0.85" << endl;
	
	gm.ReadFile(bn, "C:\\Users\\student\\Desktop\\BioNet\\data\\Basic\\three_triads\\three_triads_connect_green_red_test_target.gml");
	gm.ReadFile(bn, "C:\\Users\\student\\Desktop\\BioNet\\data\\Basic\\three_triads\\three_triads_connect_green_red_test_source.gml");
	gm.ReadFile(bn, "C:\\Users\\student\\Desktop\\BioNet\\data\\Basic\\three_triads\\three_triads_connect_green_red_test_label.gml");
	gm.ReadFile(bn, "C:\\Users\\student\\Desktop\\BioNet\\data\\Basic\\three_triads\\three_triads_connect_green_red_ID.gml");
	gm.ReadFile(bn, "C:\\Users\\student\\Desktop\\BioNet\\data\\Basic\\three_triads\\three_triads_connect_green_red_boundary_test_weight2.gml");
	gm.ReadFile(bn, "C:\\Users\\student\\Desktop\\BioNet\\data\\Basic\\three_triads\\three_triads_connect_green_red_boundary_test_weight2.gml");

	cin.get(ch);
	return 0;
}

