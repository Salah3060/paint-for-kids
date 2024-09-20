/*
See "version.h" for version info and copyright information
This file was last modified on 05.16.1999
*/

#include "colors.h"
#include <fstream>
using namespace std;
bool operator==(color a, color b) {

	return ((a.ucRed == b.ucRed) && (a.ucGreen == b.ucGreen) && (a.ucBlue == b.ucBlue));

}

bool operator!=(color a, color b) {

	return !(a == b);

}
