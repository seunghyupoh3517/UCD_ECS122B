#include <iostream>
#include <vector>
using namespace std;
#ifndef PROG1_HPP
#define PROG1_HPP

std::vector<unsigned> findMatches(const std::string& s,
                                  const std::string& target);

// Assumes contents of @filename are properly formatted.
int solveWeightedIntervalScheduling(const std::string& filename);

struct Schedule {
	int start;
	int finish;
	int weight;
	Schedule() :  start(), finish(), weight(){}
	Schedule(int s_start, int s_finish, int s_weight) : start(s_start), finish(s_finish), weight(s_weight) {}
};

static bool sortFinish(const Schedule &a, const Schedule &b){
    return (a.finish < b.finish);
};

// Orignially passing the vector of struct, std::vector<int> findP(std::vector<Scheudle> schedule)
// + weight, to make sure it chooses the greater weight of interval when there are intervals with same start, finish time to choose 
std::vector<int> findP(std::vector<int> start,std::vector <int> finish,std::vector<int> weight);

#endif  // PROG1_HPP

