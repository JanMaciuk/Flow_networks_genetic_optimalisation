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

Generowanie losowych œcie¿ek w mutacji i pocz¹tkowej populacji:
	Czy losowaæ analogicznie jak w v_fill_randomly?

Czy sensownie generuje miejsce krzy¿owania? (funkcja w myMath)

Czy mo¿emy za³o¿yæ ¿e popsize jest parzyste? bo w krzy¿owaniu dodajemy po 2 osobniki do nowej populacji
Na razie jeœli nie jest parzyste to zwiêksze rozmiar populacji o 1 dodaj¹c obydwa osobniki, ale mogê te¿ dodawaæ jedynie pierwsze dziecko
*/