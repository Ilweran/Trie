/*
 * main.cpp
 *
 *  Created on: Aug 4, 2019
 *      Author: eugene
 */
#include "trie.h"

#include <iostream>
#include <string>
//#include <complex>
#include <cmath>
using namespace std;

#define CLS (cout << "\033[2J") //Clear screen
#define PROMPT (cout << "****************** Please choose figure ******************\n\n")
#define INPUTERROR (cout << "!!!!!!!Can't recognize input sequence!!!!!!!\a"\
							<< "\nHit Enter to try out once more...")
#define DESCRIPTION (cout << "Type:\n"\
							<< "* 'right triangle' to draw right triangle,\n"\
							<< "* 'isosceles triangle' to draw isosceles triangle,\n"\
							<< "* 'square' to draw square,\n"\
							<< "* 'rectangle' to draw rectangle,\n")
#define LOCATE(z,s) (cout << "\033[" << z << ';' << s << 'H')
					//Position the cursor in row z and column s


int main()
{

	while(true)
	{
		CLS;
		LOCATE(1,1);
		cout << "\033[32m"; //Text color: green
		PROMPT;
		DESCRIPTION;
		cout << endl;
		cout << "> ";




		LOCATE(30,25);
		cout << "\nPress ENTER to continue or CTRL^C to terminate...";
		cin.sync();
		cin.clear();
		cin.get();
	}


	return 0;
}
