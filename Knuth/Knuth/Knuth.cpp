// Knuth.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "string"
#include "../../BioNet.h"
#include "GMLReader.h"


#include <iostream>
using std::cout;
using std::endl;
int main()
{
	GMLReader gm("C:\\Users\\student\\Desktop\\BioNet\\data\\Basic\\three_triads\\three_triads_connect_green_red.gml");
	BioNet bn(-1,1);
	gm.ReadFile(bn, "C:\\Users\\student\\Desktop\\BioNet\\data\\Basic\\three_triads\\three_triads_connect_green_red.gml");

	//First Node Test
	if (strcmp(bn.getNode(0).c_str(), "A") != 0)
		cout << "Problem in First Node";
	//Forth Node Test
	if (strcmp(bn.getNode(3).c_str(), "D") != 0)
		cout << "Problem in 4th Node";
	//Last Node Test
	if (strcmp(bn.getNode(8).c_str(), "I") != 0)
		cout << "Problem in First Node";

	if (!(fabs(0.9 - bn.getEdge(0, 1)) < FLT_EPSILON))
		cout << "Problem in connection between first & second node";

	if (!(fabs(0.8 - bn.getEdge(0, 2)) < FLT_EPSILON))
		cout << "Problem in connection between first & third node";

	if (!(fabs(0.6 - bn.getEdge(3, 4)) < FLT_EPSILON))
		cout << "Problem in connection between 4th & 5th node";

	if (!(fabs(0.5 - bn.getEdge(3, 5)) < FLT_EPSILON))
		cout << "Problem in connection between 4th & 6th node";

	if (!(fabs(0.85 - bn.getEdge(7, 8)) < FLT_EPSILON))
		cout << "Problem in connection between 8th & 9th node";
	return 0;
}

