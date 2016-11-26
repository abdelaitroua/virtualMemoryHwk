#include<iostream>
#include<fstream>
#include<sstream>
#include<bitset>
#include<vector>
#include<cmath>

using namespace std;


void main() {

	ifstream infile;
	infile.open("data.dat");
	int val;
	string data;
	int pageSize, offset, limit;
	int pageFault = 1;
	int wasFound = 0;
	// index for how many address are added to table untill full
	int i = 0;
	// variable used to track fifo replacement
	int min = 0;
	// handling first time we check table
	bool firsttime = true;

	cout << "Please enter page size" << endl;
	cin >> pageSize;
	offset = int(log2(pageSize));
	limit = pow(2, (32 - offset));
	int *pageTable;
	pageTable= new int[limit];

	// grabing the addresses
	while (infile >> val >> data)
	{
		// validating input
		if (data.length() > 8) {
			cout << "Bad address" << endl;
		}
		else {
			//data = "0x" + data;
			data.insert(0, "0x");

			//function to convert to binary 
			stringstream ss;
			ss << hex << data;
			unsigned n;
			ss >> n;
			bitset<32> addr(n);

			// storing binary as string
			string binary = addr.to_string();

			// shift right by number offset bits
			int stringindex = 32 - offset;
			binary.erase(stringindex, offset);

			//converting binary string to integer value
			int address = stoi(binary, nullptr, 2);
			
			if (firsttime) {
				pageTable[0] = address;
				i++;
				firsttime = false;
			}

			else {
				bool found = false;
				// start forloop to search pageTable
				for (int j = 0; j < i; j ++) {
					//searching if i already have the address in the page table
					if (address == pageTable[j]) {
						found = true;
						wasFound++;
						break;
					}
				}// end serach forloop

					if (!found){
						// we have a page fault
						pageFault++;
						// adding addresses to page table while it is not full
						if (i < limit) {
							pageTable[i] = address;
							i++;
						}
						// making sure that min is not equal to table max size
						else {
							if (min == limit) {
								min = 0;
							}
							// when page table is full we use fifo to replace old addresses
							pageTable[min] = address;
							min++;
						}
					}
				}
			}
		}
		
	cout << "For page size : " << pageSize << " we have " << pageFault << " Page Faults "  << endl;
	cout <<" We found: "<<  wasFound << endl;
	system("pause");
}
		
