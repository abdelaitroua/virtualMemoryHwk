
#include<iostream>
#include<fstream>
#include<sstream>
#include<bitset>

using namespace std;


void main() {

	ifstream infile;
	infile.open("data.dat");
	int val;
	string data;
	

    //string data;
	//int pageSize, offset;
	//cout << "Please enter page size";
	//cin >> pageSize;
	//	offset = log2(pageSize);

	while (infile >> val >> data)
	{
		//data = "0x" + data;
		data.insert(0, "0x");

		//function to convert to binary 
		stringstream ss;
		ss << hex << data;
		unsigned n;
		ss >> n;
		bitset<32> address(n);
		
	

		//(data)
		//data = data << offset;
		// shift right by offset (shiftBits = log2(pageSize))
		// For loop to store page number in vector 
		string binary = address.to_string();
		// shift right by number offset bits
		int offset = 3;
		int stringindex = 32 - offset;
		binary.erase(stringindex, offset);

		//converting binary string to integer
		int hexdata = stoi (binary, nullptr, 2);

		// attempting to convert int to hex
		
				//char buffer[33];
				//scanf_s("%d", &hexdata);
				//_itoa_s(hexdata, buffer, 16);
				//	printf("hexadecimal: %s\n", buffer);
				
				//ss << hex << address.to_ulong() << endl;
				//ss >> hexdata;
				//stringstream res;
				//res << hex << uppercase << address.to_ulong();
		

		cout << data << endl << binary << endl  << hexdata << endl;
		

	}


} 
