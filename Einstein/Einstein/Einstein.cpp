
// Einstein.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

#include "../../BioNet.h"

using std::cout;
using std::endl;

int main()
{
	cout << "Hello, World!" << endl;

	//BioNet<float> b = BioNet<float>(-1, 1, false, string("matrix"));
	BioNet<float> b = BioNet<float>();

	b.resize(5);
	b.setEdge(3, 2, 3);
	for (int i = 0; i < b.size(); ++i)
	{
		for (int j = 0; j < b.size(); ++j)
		{
			float min = b.getMinWeight();
			float max = b.getMaxWeight();
			cout << "Show Edge: [" << i << ", " << j << "]: " << b.getEdge(i,j) << endl;

			//Assert::IsTrue(b.getEdge(i, j) >= min);
			//Assert::IsTrue(b.getEdge(i, j) <= max);
		}
	}

	// Carlos A reviewed the line below
	cout << "Carlos Cepero" << endl;
	cout << "Howard Gil" << endl;
    return 0;
}

