#include<iostream>
#include<fstream>
#include<sstream>
#include<bitset>

using namespace std;


void main(){

	ifstream infile;
	infile.open("data.dat");
	string val, tempdata;
	int pageSize, offset;
	//cout << "Please enter page size";
	//cin >> pageSize;
	pageSize = 128;
	offset = log2(pageSize);
	
	while ( infile >> val >> tempdata)
	{
		cout << tempdata << endl;
		stringstream ss;
		ss << hex << tempdata;
		unsigned n;
		ss >> n;
		bitset<32> addr(n);
		addr = addr >> offset;
		cout << addr << endl;
		cout << hex << addr.to_ulong() << endl;
		//function to convert to binary 
		//(data)
		//data = data << offset;
		// shift right by offset (shiftBits = log2(pageSize))
		// For loop to store page number in vector 		
	}



}
