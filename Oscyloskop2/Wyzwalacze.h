#ifndef WYZWALACZ_H
class Wyzwalacze
{
	/**
	szuka od poczatku probek zbocza rosnacego, zwraca nr probki w ktorej wykryto zbocze
	zbocze rosnace to x probki nastepujace po sobie gdzie kazda kolejna ma wartosc wieksza od poprzedniej
	oraz ruznica wartosci miedzy pierwsza poruwnymwana i ostatnie probka wynosi delta
	*/
	int wyzwalanieZboczemRosnacym(unsigned char* probki, int liczbaProbek, int liczbaProbekPoSobie, int delta)
	{
		for(int i=0; i < liczbaProbek - liczbaProbekPoSobie; i++)
		{
			
			int obecnaDelta = 0;
			// porownujemy x kolejnych probek
			for(int k = 0; k < liczbaProbekPoSobie; k++)
			{
				// jesli nastepna probka jest mniejsza od obecnej to przerywamy
				if(probki[i + k] > probki[i + k +1])
				{
					break;
				}

				// jesli jest wiecej to sumujemy roznice
				obecnaDelta += probki[i + k +1] - probki[i + k];


			}

			// jesli koncowa roznica jest wieksza lub rowna wymaganej to zwracamy numer probki
			if(obecnaDelta >= delta)
			{
				return i;
			}
		}
	}
};
#endif