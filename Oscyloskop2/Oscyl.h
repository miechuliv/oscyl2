#ifndef OSCYL_H
#define OSCYL_H
/*
	Klasa ogulnie odpowiedzialna za przetwarzanie danych odczytanych z portu
	Pytania:
	 jak bedzie wygladal nasz protokul wymanany danych?
	 jak ustalic czestotliwosc probkowania
	 jak ustalic podstawe czasu i inne ( ? ) parametery?
	 ta klasa bedzie to musiala wszystko przetworzyc zeby potem to wyrysowac w programie
*/
#include <math.h>
#define PI 3.14159265

class Oscyl
	{
		public:

		
		int liczbaProbek;
	// definiujemy buffer - do niego beda szczytywane dane
		// i +1 liczba bajtow do szczytania
		unsigned char *probki;

		// wysokosc wyswietlacza
		int displayMaxY;

		// szer.
		int displayMaxX;

		// odstep w wys miedzy liniami siatki
		int spaceY;

		// odstep w szer miedzy liniami siatki
		int spaceX;

		// co ile pikseli wyswietlac probke, to bedzie  zmieniac w zaleznosci od liczby probek 
		int ilePixeliProbka;

		// ile probek pomijac, = 1 znaczy nie pomijac,  to bedzie  zmieniac w zaleznosci od liczby probek 
		int ilePomijac;

		// buffer do testow zawierajacy wykreslonego sinusa 
		char fakeBuffer[255]; 

		// czy uzywac przygotowanego sinusa do testow
		bool usefakeBuffer;

		// przez ten wsp. mnozymy wartosc probki i wychodzi pozycja w pionie próbki na wyswietlaczy
		int mnoznikWysokosciowy;


		void zaladujProbki(unsigned char* probki, int liczbaProbek)
		{
			this->liczbaProbek = liczbaProbek;
			this->probki = probki;
			this->przeskalujWykres();
		}


		// @todo cos sie nie do konca dobrze skaluje
		// @todo trzeba bedzie przepisac ta funkcje aby byla bardziej precyzykna bo na razie to jest tak najprostrza metoda zrobione
		// na podstawie podanej ilosci probek , rozviagnie wykres tak aby zajal mozliwie caly wyswietlacz
		// funkcja sprawdza jakiego rozmiaru bufor probek uzywamay oraz ile jakies sa wymiary wyswietlacza
		// jesli probek jest wiecej niz pixeli w szerz to bedziemy pomijac co iles probek 
		// jesli probek jest mniej niz pixeli to bedziemy stawiac probke co iles pixeli i interpolowac wykres
		
		void przeskalujWykres()
		{
			if(this->liczbaProbek)
			{

				// mamy wicej probek niz pikseli na wyswietlaczu, co za tym idzie czesc probek mozemy odrzucic i wyswietlac np: tylko co dwie
				if(this->liczbaProbek > this->displayMaxX)
				{
					int ileRazyWiecejProbek = floor((float)(this->liczbaProbek/this->displayMaxX));
					if(ileRazyWiecejProbek)
					{
						this->ilePomijac = ileRazyWiecejProbek;	
					}
				}

				// mamy mniej probek niz pikseli , wzwiazku z tym bedziemy wyswitlac probke co iles pikseli
				if(this->liczbaProbek < this->displayMaxX)
				{
					int ileRazyWiecejPkiseli = floor((float)(this->displayMaxX/this->liczbaProbek));
					if(ileRazyWiecejPkiseli)
					{
						this->ilePixeliProbka = ileRazyWiecejPkiseli;	
					}
				}
			}
		}

		// konstruktor ma taka sama nazwe jak klasa w C++
		// 
		Oscyl(int displayMaxX, int displayMaxY, int spaceX, int spaceY)
		{
			
			/*this->i = bufferSize;
			int* pointer = &this->i;
			this->szBuff[pointer + 1];*/
			this->liczbaProbek = 0;
			this->displayMaxX = displayMaxX;
			this->displayMaxY = displayMaxY;
			this->spaceY = spaceX;
			this->spaceX = spaceY;
			this->ilePomijac = 1;
			this->ilePixeliProbka = 1;
			this->usefakeBuffer = false;
			this->mnoznikWysokosciowy = int(this->displayMaxY / 255 );

			/*for(int i=0; i<256; i++)
			{
				int val = (sin((i*(360/255))*PI/180)*50);
				this->fakeBuffer[i] = val;
			}*/
		}

		
		// @todo funkcja do interpolacji zeby miec ladniejsze wykresy ?


	};
#endif