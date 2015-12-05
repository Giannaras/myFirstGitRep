/*
 * Main.cc
 *
 *  Created on: Nov 29, 2015
 *      Author: ioannis
 */

//#include <sys/time.h>
#include <ctime>
#include <chrono>
#include <iostream>
#include <deque>
#include <list>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdlib>  // use exit function
#include <math.h>   // pow, sqrt and other mathematical functions
#include <iomanip>  // std::setprecision
#include <stdlib.h>     /* atoi */
#include <stdio.h>
#include <sstream>
#include "TreeNode.h"

using namespace std;

enum ordering {preorder, inorder, postorder};
enum search_mode {breadth_first, depth_first, hill_climbing, best_first, Astar, shortest_paths, min_spanning_tree};
class Search_Description
{
public:
	ordering order;
	search_mode searching;
	string startnode;
	string goalnode;
	bool printnode;        // whether the visited node-name is printed
};

// Demo for company's test
int solution(long long int A[], int N){
	long long int posterior_sum = 0;
	long long int prior_sum = 0;
	int i,j;
	int index = -1;

	for(i =  N - 1; i-- > 0;){
		prior_sum = 0;
		posterior_sum = 0;
		for(j = i; j-- > 0;){
			prior_sum += A[j];
		}
		for(j = N; j-- > i+1;){
			posterior_sum += A[j];
		}
		if(prior_sum == posterior_sum){
			index = i;
			break;
		}
	}
	return index;
}

int main(){

	deque<int> my_first_queue;

	cout << "size of queue = " << my_first_queue.size() << endl;
	my_first_queue.push_back(2);
	my_first_queue.push_back(-1);
	my_first_queue.push_back(6);
	my_first_queue.push_back(8);
	my_first_queue.push_back(0);

	cout << "size of queue = " << my_first_queue.size() << endl;

	for(size_t i = 0; i < my_first_queue.size(); i++){
		cout << my_first_queue[i] << " ";
	}
	sort(my_first_queue.begin(), my_first_queue.end());
	cout << "\n" << endl;
	for(size_t i = 0; i < my_first_queue.size(); i++){
		cout << my_first_queue[i] << " ";
	}

	deque<string> M;
	M.push_back("Makis");
	M.push_back("Ntina");
	M.push_back("Panagiotis");
	M.push_back("Ioannis");
	cout << "\n" << endl;

	for(size_t i = 0; i < M.size(); i++){
		cout << M[i] << " ";
	}
	cout << "\n" << endl;
	// sort uses the default sorting criterium for strings - alphabetical
	sort(M.begin(), M.end());
	for(size_t i = 0; i < M.size(); i++){
		cout << M[i] << " ";
	}
	cout << "\n" << endl;



	// Playing with graphs

	// equilibrium indexing
	long long int A[8];
	A[0] = -1;
	A[1] = 3;
	A[2] = -4;
	A[3] = 5;
	A[4] = 1;
	A[5] = -6;
	A[6] = 2;
	A[7] = 1;

	long long int B[5] = {66, 32, 1, 0, 99};

	long long C[7] = {-7, 1, 5, 2, -4, 3, 0};

	long long D[5] = {99, 0, 66, 32, 1};


	//	clock_t start;
	//	double diff;
	//	start = clock();

	int equilibrium_index = solution(D, 5);

	//	diff = ( std::clock() - start ) / (double)CLOCKS_PER_SEC;

	cout << "equilibrium_index = " << equilibrium_index << endl;

	int upper_limit = 10000000;
	chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
	// Test speed of for loops
	for(int i = 0; i < upper_limit; i++){

	}
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	cout << "Elapsed time of old loop  = " << (std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()) << " usec" << endl;


	int i;
	chrono::steady_clock::time_point start2 = std::chrono::steady_clock::now();
	for(i = upper_limit; i -- > 0;){

	}
	std::chrono::steady_clock::time_point end2 = std::chrono::steady_clock::now();
	cout << "Elapsed time of new loop  = " << (std::chrono::duration_cast<std::chrono::microseconds>(end2 - start2).count()) << " usec" << endl;

	return 0;
}




