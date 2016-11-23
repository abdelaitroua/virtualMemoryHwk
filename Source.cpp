#include<iostream>
#include<fstream>
#include<sstream>
#include<bitset>

using namespace std;


void main(){

	ifstream infile;
	infile.open("data.dat");
	string val, tempdata;
	//int pageSize, offset;
	//cout << "Please enter page size";
	//cin >> pageSize;
//	offset = log2(pageSize);
	
	while ( infile >> val >> hex >> tempdata)
	{
		
		//cout << tempdata << endl;

		bitset<32> addr(string(tempdata));
		//addr = data;
		//function to convert to binary 
		//(data)
		//data = data << offset;
		// shift right by offset (shiftBits = log2(pageSize))
		// For loop to store page number in vector 
		cout << addr << endl;
		
	}



}