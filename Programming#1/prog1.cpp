// this will cause due to path to the input files and the change in name of the workspace, make sure before test it
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <fstream>
#include "prog1.hpp"
using namespace std;
std::vector<unsigned> findMatches(const std::string& s, const std:: string& target);
int solveWeightedIntervalScheduling(const std::string& filename);
struct Schedule schedule;
std::vector<int> findP(std::vector<int> start,std::vector <int> finish, std::vector <int> weight);

// Part1: FindMatches
std::vector<unsigned> findMatches(const std::string& s, const std:: string& target){
    int n = s.length();
    int m = target.length();
    std::vector<unsigned> matches;
    int index;
    bool check;
    
    for(int x = 0; x < n; x++){
        if(s[x] == target[0]){
            index = x;
            check = true;
            for(int y = 1; y < m; y++){
                if(s[x+y] == target[y])
                    check = true;
                else{
                    check = false;
                    break; // need to break when mismatching occurs to move on
                }
            }
            if(check){
                matches.push_back(index);
                x += (m-1);
            }
        }
    }

    /* When there is no matching string, it will just return empty vector - I think that makes more sense instead of putting any strange value to signify
    if(matches.empty())
        matches.push_back(99999999);
    */
   
    // Returning the  vecotr of integers containing the matching starting indices
    return matches;
}

///========================================================================
// Part2: Weighted Interval Scheduling
int solveWeightedIntervalScheduling(const std::string& filename){  
    // Read the input files and put the values into the struct Schedule
    ifstream inFile;
    inFile.open(filename);

    if(!inFile){
        cout << "Unable to open the file: " << filename;
        exit(1);
    }

    std::vector<Schedule> schedule1;
    schedule1.push_back(Schedule(0,0,0));

    int x, y, z;
    while(inFile >> x >> y >> z){
        schedule1.push_back(Schedule(x,y,z));
    }
    inFile.close();

    int n = schedule1.size();

    // Sort the Scheulde by the finish time (correspondingly,the start and weight as well)
    sort(schedule1.begin(), schedule1.end(), sortFinish);

    // Find the P  which yield the former possible interval which can be chosen
    std::vector<int> p, v_start, v_finish, v_weight;
    // I orinignally passed vector of struct, std::vector<Schedule> schedule1, into the findP's parameter but
    // it was impossible to run the helper function in the unit testing with such parameters; thus, I am using alternative
    for(int i = 0; i < n; i++){
        v_start.push_back(schedule1[i].start);
        v_finish.push_back(schedule1[i].finish);
        v_weight.push_back(schedule1[i].weight);
    }
    p = findP(v_start, v_finish, v_weight);

    // Find the optimal weight based on P and weight - Dynamic Prgramming
    std::vector<int> opt;
    opt.push_back(0);

    for(int i = 1; i < n; i++){
        opt.push_back(max((schedule1[i].weight + opt[p[i]]), opt[i-1]));
    }
    //cout << "Optimal Weight: ";
    return opt[n-1];
}

std::vector<int> findP(std::vector<int> start, std::vector <int> finish, std::vector<int> weight){
    std::vector<int> p_helper;
    p_helper.push_back(0);
    int n = start.size();

    // Find the least difference between the interval's finish time and the start time
    // in order to decide what would be the closest interval that is possible to choose
    for(int i = 1; i < n; i++){
        int min = std::numeric_limits<int>::max();
        int index = 0;
        int j_weight = 0;
        for(int j = 1; j < n; j++){
            // same start and finish time will collide; thus > instead of >=
            if(start[i] > finish[j] && i != j){
                if(min > start[i] - finish[j]){ // >=, >=
                    min = start[i] - finish[j];
                    index = j;
                    j_weight = weight[j];
                }
                else if(min == start[i] - finish[j]){
                    if(weight[j] > j_weight){
                        index = j;
                        j_weight = weight[j];
                    }
                }
            }
        }
        p_helper.push_back(index);
    }
    return p_helper;
}




