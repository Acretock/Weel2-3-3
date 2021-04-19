#include <map>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

void New_Bus(map<string, string>& buses, map<string, string>& stops, string bus, vector<string> stop) {

}

void Buses_For_Stop(map<string, string>& map, string stop) {
	
}

void Stops_For_Bus(map<string, string>& map, string bus) {

}

void All_Buses(map<string, string>& map) {

}

int main()
{
	int N,m;
	string line, command, str1, tmp;
	map<string, string> buses;
	map<string, string> stops;
	vector<string> stop;
	cin >> N;
	for (int i = 0; i <= N; i++) {
		getline(cin, line);
		stringstream ss(line);
		ss >> command;
		ss >> str1;
		if (command == "NEW_BUS") {
			ss >> m;
			while (ss.good()) {
				ss >> tmp;
				stop.push_back(tmp);
			}
			New_Bus(buses,stops, str1, stop);
			stop.clear();
		}
		if (command == "BUSES_FOR_STOP") {
			//Buses_For_Stop(map, str1);
		}
	}

	
}
