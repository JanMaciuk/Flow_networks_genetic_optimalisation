#pragma once

#include "Evaluator.h"
#include "GeneticAlgorithm.h"
#include <random>
#include <vector>

using namespace std;

const int GA_populationSize = 150;
const float GA_crossProb = 0.9;
const float GA_mutProb = 0.001;

class COptimizer
{
public:
	COptimizer(CLFLnetEvaluator &cEvaluator);

	void vInitialize();
	void vRunIteration();

	vector<int> *pvGetCurrentBest() { return &v_current_best; }
	~COptimizer();

private:
	void v_fill_randomly(vector<int> &vSolution);

	CLFLnetEvaluator &c_evaluator;
	GeneticAlgorithm c_genetic_algorithm;

	double d_current_best_fitness;
	vector<int> v_current_best;

	mt19937 c_rand_engine;
};//class COptimizer