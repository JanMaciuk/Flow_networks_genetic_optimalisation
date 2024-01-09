#pragma once
#include <vector>
#include "Individual.h"

using namespace std;

class GeneticAlgorithm
{
public:

	GeneticAlgorithm(int populationSize, float crossProb, float mutProb, CLFLnetEvaluator* evaluatorPointer);

	Individual* runOneIteration(); // run one generation and return the best individual

private:
	vector<Individual*> population;
	float crossProb;
	float mutProb;
	CLFLnetEvaluator* evaluatorPointer;

};

/*
Potencjalne pytania:

Generowanie losowych �cie�ek w mutacji i pocz�tkowej populacji:
	Czy losowa� analogicznie jak w v_fill_randomly?

Czy sensownie generuje miejsce krzy�owania? (funkcja w myMath)

Czy mo�emy za�o�y� �e popsize jest parzyste? bo w krzy�owaniu dodajemy po 2 osobniki do nowej populacji
Na razie je�li nie jest parzyste to zwi�ksze rozmiar populacji o 1 dodaj�c obydwa osobniki, ale mog� te� dodawa� jedynie pierwsze dziecko
*/