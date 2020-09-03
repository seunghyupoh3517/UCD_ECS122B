// ECS122B Programming Assignment#2 .cpp
#include <iostream>
#include <tuple>
#include <vector>
#include <cmath>
#include <cstdio>
#include <fstream>
#include "prog2.hpp"
using namespace std;
// Part#1: DP Optimization and Subset Sum
unsigned findOptSubsetSum(unsigned W,
    const std::vector<unsigned>& weights);

// Part#2: Improving Auxiliary Space of Subset Sum
std::vector<std::vector<unsigned> > findOptSubsetSum2(
        unsigned W,
        const std::vector<unsigned>& weights,
        unsigned x);

// Part#3: Brute-Force Subset Sum
std::tuple<bool, std::vector<unsigned> > findOptSubsetSumBF(
    const std::vector<int>& weights);

// Part#4: Brute-Force Independent Set
std::vector<unsigned> findMaxIndSetBF(const std::string& graphData);

unsigned findOptSubsetSum(unsigned W, const std::vector<unsigned>& weights){
    unsigned n = weights.size();
    unsigned OPT[n+1][W+1];
    for(int i = 0; i <= W; i++)
        OPT[0][i] = 0;
  
    for(unsigned i = 1; i <= n; i++){
        for(unsigned j = 0; j <= W; j++){
            if(j < weights[i-1])
                OPT[i][j] = OPT[i-1][j];        
            else // weights[i-1] because the given inputs index starts from 0 unlike the example from slides has one-indexing
                OPT[i][j] = max(OPT[i-1][j], weights[i-1] + OPT[i-1][j - weights[i-1]]);
        }
    }
    return OPT[n][W];
}


std::vector<std::vector<unsigned> > findOptSubsetSum2(unsigned W, const std::vector<unsigned>& weights, unsigned x){
    std::vector<std::vector<unsigned> > OPT;
    std::vector<unsigned> previous_row; 
    std::vector<unsigned> curr_row;

    int i = W;
    while(i >= 0){
        previous_row.push_back(0);
        curr_row.push_back(0);
        i--;
    }
    
    // Same as Part#1, Just keep in mind that OPT[n-1][W], n-1 refers to previous_row 
    // x refers to n
    for(unsigned i = 0; i < x; i ++){
        for(unsigned j = 1; j <= W; j++){
            if(j < weights[i])
                curr_row[j] = previous_row[j]; 
            else
                curr_row[j] = max(previous_row[j], weights[i] + previous_row[j - weights[i]]);
        }
        if(i!=x-1)
            previous_row = curr_row;
    }

    OPT.push_back(previous_row); 
    OPT.push_back(curr_row);
    return OPT;
}

std::tuple<bool, std::vector<unsigned> > findOptSubsetSumBF(const std::vector<int>& weights){
    tuple<bool, std::vector<unsigned> > result;
    std::vector<unsigned> indices;
    bool check = false;

    unsigned n = weights.size();
    unsigned p_n = pow(2, n);

    // checking the memebership of the problem & this excludes empty set - no need to verify |S| != 0
    std::vector<unsigned> temp;
    for(int i = 0; i < p_n; i++){
        int sum = 0;
        for(int j = 0; j < n; j++){
            if(i & (1 << j)){
                sum += weights[j];
                temp.push_back(j);
            }
        }
        // in case when it loop does't fall into if statement and no expansion in temp 
        if(sum == 0 && temp.size()!= 0){
            check = true;
            indices = temp;
            result = make_tuple(check, indices);
            return result;
        }
        // reset the temp vector to empty vector - could've declare temp under the loop i but thought clear() would be better than declaration every time
        else
            temp.clear();
    }

    result = make_tuple(check, indices);
    return result;
    }

std::vector<unsigned> findMaxIndSetBF(const std::string& graphData){
    // fscanf(): type specifiers - use it when reading the input from the file next time :)
    std::vector<unsigned> result;
    ifstream inFile;
    inFile.open(graphData);

    // Read first line which is # of vertices
    unsigned x, y, n;
    inFile >> x;
    n = x;
    unsigned p_n = pow(2, n);

    // Read undirected edge 
    unsigned edge[n][n]; 
    for(int i=0; i < n; i++)
        for(int j =0; j < n;j++)
            edge[i][j] = 0;

    while(inFile >> x >> y){  
        edge[x][y] = 1;
        edge[y][x] = 1;
    }
    
    // Quite similar with Part#3, check all the posible subset of vertices and if the subset is independent set return it
    // if the current subset (temp) is independent set - but have to return optimal = maximum # of vertices
    size_t optimal = 0;
    for(int i = 0; i < p_n; i++){
        std::vector<unsigned> temp;
        bool check = false;
        for(int j = 0; j < n; j++){
            if(i & (1 << j)){
                temp.push_back(j);
            }
        }

        for(int j = 0; j < temp.size()-1; j++){
            for(int k = j+1; k < temp.size(); k++){
                if(edge[temp[j]][temp[k]] == 0)
                    check = true;
                else{
                    check = false;
                    break;
                }
            }
            if(!check)
                break;
        }

        if(check && optimal < temp.size()){
            optimal = max(optimal, temp.size());
            result = temp;
        }
    }

    // if no independent set, return empty vector
    return result;
}