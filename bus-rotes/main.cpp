#include <cassert>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>

using namespace std;

class BusRoutes {
private:
    struct NewBusRecord {
        string bus_name;
        set<string> stops;
    };

    using DataSet = set<string>;
    using DataMap = map<string, DataSet>;

    DataMap buses_;
    DataMap stops_;

    DataSet GetBusesForStop(const string& stop) const {
        DataSet buses;
        if (stops_.empty() || stops_.count(stop) == 0) {
            return buses;
        }
        buses = stops_.at(stop);
        return buses;
    }

    DataSet GetStopsForBus(const string& bus_name) const {
        DataSet stops;
        if (buses_.empty() || buses_.count(bus_name) == 0) {
            return stops;
        }
        stops = buses_.at(bus_name);
        return stops;
    }

    DataMap GetAllBuses() const {
        DataMap all_buses;
        if (buses_.empty()) {
            return all_buses;
        }
        all_buses = buses_;
        return all_buses;
    }

    DataMap GetAllStops() const {
        DataMap all_stops;
        if (stops_.empty()) {
            return all_stops;
        }
        all_stops = stops_;
        return all_stops;
    }

    void PrintResult(const set<string>& data, const string& result_type, const string& result_name) const {
        if (data.empty()) {
            cout << "No " << result_type << " for " << result_name << endl;
            return;
        }
        cout << result_type << ' ' << result_name << ": ";
        bool first = true;
        for (const string& value : data) {
            if (first) {
                first = false;
            }
            else {
                cout << ' ';
            }
            cout << value;
        }
        cout << endl;
    }

public:

    void NewBus(const NewBusRecord& bus_record) {
        if (bus_record.bus_name.empty() || bus_record.stops.empty()) {
            return;
        }
        for (const string& stop_name : bus_record.stops) {
            buses_[bus_record.bus_name].insert(stop_name);
            stops_[stop_name].insert(bus_record.bus_name);
        }
    }

    NewBusRecord ParseNewBusRecord(istringstream& command) {
        NewBusRecord result;
        command >> result.bus_name;

        unsigned stops_count;
        command >> stops_count;

        for (unsigned i = 0; i < stops_count; ++i) {
            string stop_name;
            command >> stop_name;
            result.stops.insert(stop_name);
        }

        return result;
    }

    void PrintBusesForStop(const string& stop_name) const {
        PrintResult(GetBusesForStop(stop_name), "Stop", stop_name);
    }

    void PrintStopsForBus(const string& bus_name) const {
        PrintResult(GetStopsForBus(bus_name), "Bus", bus_name);
    }

    void PrintAllBuses() const {
        bool found = false;
        for (const auto& [bus_name, stops] : GetAllBuses()) {
            found = true;
            PrintResult(stops, "Bus", bus_name);
        }
        if (!found) {
            cout << "No buses";
        }
        cout << endl;
    }

    void PrintAllStops() const {
        bool found = false;
        for (const auto& [stop_name, buses] : GetAllStops()) {
            found = true;
            PrintResult(buses, "Stop", stop_name);
        }
        if (!found) {
            cout << "No stops";
        }
        cout << endl;
    }
};

int main() {
    BusRoutes bus_rotes;
    string line;

    while (getline(cin, line)) {

        istringstream command(line);

        string action;
        command >> action;

        if (action == "NEW_BUS"s) {
            bus_rotes.NewBus(bus_rotes.ParseNewBusRecord(command));
        }
        else if (action == "BUSES_FOR_STOP"s) {
            string stop;
            command >> stop;
            bus_rotes.PrintBusesForStop(stop);
        }
        else if (action == "STOPS_FOR_BUS"s) {
            string bus;
            command >> bus;
            bus_rotes.PrintStopsForBus(bus);
        }
        else if (action == "ALL_BUSES"s) {
            bus_rotes.PrintAllBuses();
        }
        else if (action == "ALL_STOPS"s) {
            bus_rotes.PrintAllStops();
        }
        else if (action == "EXIT"s) {
            break;
        }
    }
}
