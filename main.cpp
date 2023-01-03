#include <iostream>
using namespace std;

int lightedBuildings(int* buildings, int buildingsNum)
{
	int lighted = 0;
	int lightReduce = 0;
	for (int i = 0; i < buildingsNum; i++)
	{
		if (buildings[i] - lightReduce > 0 && i != 0)
		{
			lighted += (buildings[i] - lightReduce);
		}
		if (lightReduce <= buildings[i])
		{
			lightReduce = buildings[i];
		}
		else
		{
			if (lightReduce)
			{
				lightReduce--;
			}
		}
	}
	return lighted;
}

void printBuildings(int* buildings, int buildingsNum, char* buildingsColorScheme)//color scheme: 0 - unlit floor, 1 - lit space, 2 - unlit space, 3 - lit floor
{
	int height = buildings[0];
	for (int i = 1; i < buildingsNum; i++)
	{
		if (height < buildings[i])
		{
			height = buildings[i];
		}
	}
	for (int i = 0; i < buildingsNum; i++)
	{
		cout << buildingsColorScheme[1];
	}
	cout << endl;
	for (int i = height; i > 0; i--)//'i' is current height (starting from top == 'height')
	{
		int lightReduce = 0;
		for (int j = 0; j < buildingsNum; j++)
		{
			if (buildings[j] - i < 0)//empty space
			{
				if (lightReduce > 1)
				{
					cout << buildingsColorScheme[2];
				}
				else
				{
					cout << buildingsColorScheme[1];
				}
				if (lightReduce)
				{
					lightReduce--;
				}
			}
			else//building
			{
				if (lightReduce == 0 && j > 0)
				{
					cout << buildingsColorScheme[3];
				}
				else
				{
					cout << buildingsColorScheme[0];
					lightReduce--;
				}
				if (buildings[j] - i + 1 > lightReduce)
				{
					lightReduce = buildings[j] - i + 1;
				}
			}
		}
		cout << endl;
	}
}

int main()
{
	int buildingsNum;
	do
	{
		cin >> buildingsNum;
	} while (buildingsNum <= 0);
	
	//new buildings
	int* buildings = new int[buildingsNum];
	//

	for (int i = 0; i < buildingsNum; i++)
	{
		do
		{
			cin >> buildings[i];
		} while (buildings[i] < 0);
	}
	cout << lightedBuildings(buildings, buildingsNum) << endl;
	char buildingsColorScheme[] = { '#',92,'-','*' };//color scheme: 0 - unlit floor, 1 - lit space, 2 - unlit space, 3 - lit floor
	//char buildingsColorScheme[] = { 219,177,176,178 };
	printBuildings(buildings, buildingsNum, buildingsColorScheme);

	//delete buildings
	delete[] buildings;
	buildings = nullptr;
	//

	return 0;
}