#include "Individual.h"


Individual::Individual(vector<int> genotype, CLFLnetEvaluator* evaluatorPointer)
{
	this->genotype = genotype;					// The actual solution carried by the individual
	this->evaluatorPointer = evaluatorPointer;	// Pointer to the evaluator instance that will be used for fitness calculation
	fitness = NULL;								// Fitness is calculated only when needed
}

Individual::Individual(const Individual& other)
{
	genotype = other.genotype;
	evaluatorPointer = other.evaluatorPointer;
	fitness = other.fitness;
}

double Individual::getFitness()
{
	if (fitness == NULL) { fitness = evaluatorPointer->dEvaluate(&genotype); }
	return fitness;
}

void Individual::mutate(float mutProb)
{
	for (int i = 0; i < genotype.size(); i++) // For each gene roll if mutation should happen or not
	{
		if (dRand() < mutProb) 
		{
			genotype.at(i) = lRand(evaluatorPointer->iGetNumberOfValues(i));
			fitness = NULL; // If solution mutated, fitness needs to be recalculated
		}
	}
}

vector<Individual*> Individual::cross(Individual* other)
{
	// randomize crossover point:
	int crossIndex = rangeRand(1, genotype.size() - 1);
	vector<int> genotype1, genotype2;
	for (int i = 0; i < genotype.size(); i++)
	{
		if (i < crossIndex)
		{
			genotype1.push_back(genotype.at(i));
			genotype2.push_back(other->genotype.at(i));
		}
		else
		{
			genotype1.push_back(other->genotype.at(i));
			genotype2.push_back(genotype.at(i));
		}
	}
	Individual* child1 = new Individual(genotype1, evaluatorPointer);
	Individual* child2 = new Individual(genotype2, evaluatorPointer);
	return vector<Individual*>{child1, child2};
}
