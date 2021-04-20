#include <map>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

void New_Bus(map<string, vector<string>>& buses, map<string, vector<string>>& stops, string bus, vector<string> stop) {
	buses.insert({ bus,stop });
	for (auto i : stop) {
		if (stops.count(i) == 0)
			stops.insert({ i,{bus} });
		else
			stops.find(i)->second.push_back(bus);
	}
}

void Buses_For_Stop(map<string, vector<string>>& map, string stop) {
	if (map.count(stop) == 0)
		cout << "No stop" << endl;
	else {
		cout << "Stop " << map.find(stop)->first << ": ";
		for (auto i : map.find(stop)->second)
			cout << i << " ";
		cout << endl;
	}
}

void Stops_For_Bus(map<string, vector<string>>& buses, map<string, vector<string>>& stops, string bus) {
	if (buses.count(bus) == 0)
		cout << "No bus" << endl;
	else {
		vector<string> tmp = { bus };
		for (auto i : buses.find(bus)->second) {
			cout << "Stop " << i << ": ";
			for (auto j : stops[i]) {
				if (stops.find(i)->second != tmp)
				{if(j != bus) cout << j << ' ';}
				else
					cout << "No interchange";
			}
			cout << endl;
		}
	}
}

void All_Buses(map<string, vector<string>>& map) {
	if (map.empty())
		cout << "No buses" << endl;
	else {
		for (auto i : map) {
			cout << "Bus " << i.first << ": ";
			for (int j = 0; j < i.second.size(); j++)
				cout << i.second[j] << ' ';
			cout << endl;
		}
	}
}

int main()
{
	int N,m;
	string line, command, str1, tmp;
	map<string, vector<string>> buses;
	map<string, vector<string>> stops;
	vector<string> stop;
	cin >> N;
	for (int i = 0; i <= N; i++) {
		getline(cin, line);
		stringstream ss(line);
		ss >> command;
		if (ss.good())
			ss >> str1;
		if (command == "NEW_BUS") {
			ss >> m;
			while (ss.good()) {
				ss >> tmp;
				if (tmp != "\0")
					stop.push_back(tmp);
				tmp = '\0';
			}
			New_Bus(buses, stops, str1, stop);
			stop.clear();
		}
		if (command == "BUSES_FOR_STOP") {
			Buses_For_Stop(stops, str1);
		}

		if (command == "STOPS_FOR_BUS") {
			Stops_For_Bus(buses, stops, str1);
		}

		if (command == "ALL_BUSES") {
			All_Buses(buses);
		}
	}

	
}
