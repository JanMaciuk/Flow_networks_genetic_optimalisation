#pragma once
#include <vector>
#include "Evaluator.h"

using namespace std;

class Individual
{
public:

	Individual(vector<int> genotype, CLFLnetEvaluator* evaluatorPointer);
	Individual(const Individual& other);
	double getFitness();
	void mutate(float mutProb);
	vector<Individual*> cross(Individual* other);
	inline vector<int> getGenotype() { return genotype; }

private:

	vector<int> genotype;
	double fitness;
	CLFLnetEvaluator* evaluatorPointer;

};