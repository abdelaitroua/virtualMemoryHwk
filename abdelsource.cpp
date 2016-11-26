#include<iostream>
#include<fstream>
#include<sstream>
#include<bitset>
#include<queue>
#include<cmath>

using namespace std;


void main() {

	ifstream infile;
	infile.open("data.dat");
	int val;
	string data;
	int pageSize, offset, limit;
	int pageFault = 0;
	int i = 0;
	int min = 0;

	//string data;

	cout << "Please enter page size" << endl;
	cin >> pageSize;
	offset = int(log2(pageSize));
	limit = pow(2, (32 - offset));
	vector <int> pageTable(limit);

	// grabing the addresses
	while (infile >> val >> data)
	{
		// validating input
		if (data.length() > 8) {
			cout << "Bad address" << endl;
		}

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

		// For loop to search if int value exist in table
		// if yes retun yes
		// if not pagefault++ and swap using fifo if table is full
		// if  (hexdata >= 0 && hexdata <= 2^25)

	//	cout << address << endl;
		// index value to accomplish FIFO
		
		bool firsttime = true;
		if (firsttime) {
			pageTable[0] = address;
			firsttime = false;
		}



		else {
			cout << "while pagetable" << endl;
			for (vector<int>::iterator it = pageTable.begin(); it != pageTable.end(); it++) {
				cout << "for iterator" << endl;
				if (address == *it) {
					break;
				}
				else {
					pageFault++;
					if (pageTable.size() < limit) {
						pageTable[i] = address;
						i++;
					}
					else {
						if (min == limit) {
							min = 0;
						}
						pageTable[min] = address;
						min++;
				    	}
				}
			}
		}
	}
	cout << pageFault << endl;
	system("pause");
}
		
