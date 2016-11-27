#include<iostream>
#include<fstream>
#include<sstream>
#include<bitset>
#include<vector>

using namespace std;


void main() {
	
	int pageSize[] = { 128,256,512,1024,2048,4096 };
	for (int i = 0; i < 6; i++)
	{
		int pageFault = 1;//compulsory or first load
		int offset = int(log2(pageSize[i]));
		int min = 0;
		int limit = pow(int(2), (32 - offset));
		cout << limit << endl;
		vector<int> pageTable;
		ifstream infile;
		infile.open("data.dat");
		while (!infile.eof())
		{
			int val;
			string data;
			infile >> val;
			infile >> data;
			stringstream ss;
			ss << hex << data;
			unsigned n;
			ss >> n;
			bitset<32> addr(n);
			addr = addr >> offset;
			unsigned int address = addr.to_ulong();
			if (pageTable.empty()) {
				pageTable.push_back(address);
			}
			else
			{
				bool found = false;
				for (int i = 0; i < pageTable.size(); i++)
				{
					if (address == pageTable[i]) {
						found = true;
						break;
					}
				}
				if (!found) {
					pageFault++;
					if (pageTable.size()<limit)
					{
						pageTable.push_back(address);
					}
					else
					{
						if (min==limit-1)
						{
							min = 0;
						}
						pageTable[min] = address;
						min++;
					}
				}
			}
		}
		cout << "For pagesize  " << pageSize[i] << "  we have  " << pageFault << " page faults" << endl;
	}
}