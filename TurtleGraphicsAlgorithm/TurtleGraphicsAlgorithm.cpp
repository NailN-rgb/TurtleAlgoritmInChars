#include <iostream>

std::string Transformation(std::string axiom, std::string newf);
std::string Diverge(std::string axiom, int startedQuef, int lastQuef);
std::string MainCalculations(std::string axiom, std::string newF, int counterOfF, int positions[]);

std::string Axiom = "F++F++F";
std::string Newf = "F-F++F-F";

int numsOfIteration = 3;

int main()
{
	int StartedmoveVector[2] = { 1, 0 }; // 1 - xCordinate, 0 - yCoorditate;

	
	for (int i = 0; i < numsOfIteration; i++)
	{
		Axiom = Transformation(Axiom, Newf);
	}
	system("pause");
}

std::string Transformation(std::string axiom, std::string newf)
{
	int size = axiom.size(); //7 for first iteration


	int counterOfFindingF = 0;
	int *positionsOfF;

	for (int i = 0; i < size; i++)
	{
		if (axiom[i] == 'F')
		{
			counterOfFindingF++;
		}
	}
	
	positionsOfF = new int[counterOfFindingF];
	int locator = 0;
	
	for (int i = 0; i < size; i++)
	{
		if (axiom[i] == 'F')
		{
			positionsOfF[locator] = i;
			locator++;

			if (locator > counterOfFindingF)
			{
				
			}
		}
	}

	
	
	return MainCalculations(axiom, newf, counterOfFindingF, positionsOfF);
	
}

std::string Diverge(std::string axiom, int startedQuef, int lastQuef)
{
	std::string Returner = "";

	if (startedQuef == 0)
	{
		for (int i = 0; i < lastQuef; i++)
		{
			Returner += axiom[i];
		}
	}
	else
	{
		std::string Temp;

		for (int i = startedQuef; i < lastQuef; i++)
		{
			Temp += axiom[i];
		}
		Returner = Temp;
	}

	return Returner;
}

std:: string MainCalculations(std::string axiom, std::string newF, int counterOfF, int positions[])
{
	std::string beforeDivergeString;
	std::string afterDivergeString;

	int startedPOint;

	for (int i = 0; i < counterOfF; i++)
	{
		if (i == 0)
		{
			startedPOint = 0;
		}
		else
		{
			startedPOint = positions[i];
		}


		beforeDivergeString = Diverge(axiom, 0, startedPOint);
		afterDivergeString = Diverge(axiom, startedPOint + 1, (size(axiom)));



		for (int i = 0; i < counterOfF; i++)
		{
			positions[i] += size(newF) - 1;
		}
		axiom = beforeDivergeString + newF + afterDivergeString;
	}

	std::cout << axiom << std::endl << std::endl;
	return axiom;
}


