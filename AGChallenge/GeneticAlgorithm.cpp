#include "GeneticAlgorithm.h"

GeneticAlgorithm::GeneticAlgorithm(int populationSize, float crossProb, float mutProb, CLFLnetEvaluator* evaluatorPointer)
{
	this->crossProb = crossProb;
	this->mutProb = mutProb;
	this->evaluatorPointer = evaluatorPointer;

	for (int i = 0; i < populationSize; i++)
	{
		vector<int> genotype;	// Filling the initial population with random individuals
		for (int j = 0; j < evaluatorPointer->iGetNumberOfBits(); j++)
		{
			genotype.push_back(lRand(evaluatorPointer->iGetNumberOfValues(j)));
		}
		population.push_back(new Individual(genotype,evaluatorPointer));
	}
}

Individual* GeneticAlgorithm::runOneIteration()
{
	vector<Individual*> parents, newPopulation;
	while (newPopulation.size() < population.size()) // while new population is not full, keep adding individuals
	{
		// Selection of Individuals to cross:
		for (int i = 0; i <= 1; i++) // exectue twice, choose two parents
		{
			Individual* candidate1 = population.at(rangeRand(0, population.size() - 1));
			Individual* candidate2 = population.at(rangeRand(0, population.size() - 1));
			Individual* parent = candidate1->getFitness() > candidate2->getFitness() ? candidate1 : candidate2; // if candidate1 is better than candidate2, parent1 = candidate1, else parent1 = candidate2
			parents.push_back(parent);
		}

		// Crossing:
		if (dRand() < crossProb) // if crossover happens
		{
			vector<Individual*> children = parents.at(0)->cross(parents.at(1)); // cross parents and add children to the new population
			newPopulation.push_back(children.at(0));
			newPopulation.push_back(children.at(1));
		}
		else // if crossover doesn't happen
		{
			newPopulation.push_back(new Individual(*parents.at(0))); // simply add copies of parents to the new population
			newPopulation.push_back(new Individual(*parents.at(1)));
		}
	} // end of while (newPopulation.size() < population.size())

	// Mutation:
	for (int i = 0; i < newPopulation.size(); i++) // mutate each individual in the new population
	{
		newPopulation.at(i)->mutate(mutProb); // mutation probability is checked for each gene inside the mutate function
	}
	// delete the old population:
	for (int i = 0; i < population.size(); i++)
	{
		delete population.at(i);
	}

	population = newPopulation; // replace old population with the new one

	// Find the best individual to return:
	Individual* bestIndividual = population.at(0);
	for (int i = 1; i < population.size(); i++)
	{
		if (population.at(i)->getFitness() > bestIndividual->getFitness()) { bestIndividual = population.at(i); }
	}
	return bestIndividual;
}