// Space: 158 ms, faster than 81.38% of C++ online submissions
//  Time: 56.1 MB, less than 99.89% of C++ online submissions
class UndergroundSystem {
public:
    inline size_t key(int i,int j) {return (size_t) i << 32 | (unsigned int) j;}
    
    UndergroundSystem() {
        numOfCities = 0;
    }
    
    // T: O(1)
    void checkIn(int id, string stationName, int t) {
        int station;
        
        if(stationsID.find(stationName) == stationsID.end()){
            stationsID[stationName] = numOfCities;
            numOfCities++;
        }
        
        station = stationsID[stationName];
        
        customerCheckIn[id] = {station, t};
    }
    
    // T: O(1)
    void checkOut(int id, string stationName, int t) {
        size_t travelID;
        int startStation, endStation, startTime;
        
        if(stationsID.find(stationName) == stationsID.end()){
            stationsID[stationName] = numOfCities;
            numOfCities++;
        }
        
        startStation = customerCheckIn[id].first;
        endStation = stationsID[stationName];
        travelID = key(startStation, endStation);
        
        travelInformation[travelID] = {travelInformation[travelID].first + t - 
                                       customerCheckIn[id].second, 
                                       travelInformation[travelID].second + 1};
        
        customerCheckIn.erase(id);
    }
    
    // T: O(1)
    double getAverageTime(string startStation, string endStation) {
        size_t travelID;
        int start, end;
        
        start = stationsID[startStation];
        end = stationsID[endStation];
        travelID = key(start, end);
                
        return (double)travelInformation[travelID].first / 
               (double)travelInformation[travelID].second;
    }
    
private:
    int numOfCities;
    //            cust     station time
    unordered_map<int, pair<int, int>> customerCheckIn;
    unordered_map<string, int> stationsID;
    //                    tot time  num of occur
    unordered_map<size_t, pair<int, int>> travelInformation;
};



/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
