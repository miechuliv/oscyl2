#ifndef PAKIET_H
#define PAKIET_H
#include "Windows.h"
#include "Com.h"
using namespace System;

/*
klasa odpowiedzialna za obsluge pakietow
*/

class Pakiet
{

	  public:

	  bool pakietPoprawny;


	  /*
	  
	  */
	  bool pobierzPakiet(int jakDlugoSzukacPoczatku)
	  {
		  for(int i = 0 ; i < jakDlugoSzukacPoczatku; i++)
		  {
			  if(this->szukajPoczatkuPakietu() && this->sprawdzPoprawnoscPakietu())
			  {
				  if(this->pakietPoprawny)
				  {
					  return true;
				  }
				  
			  }
		  }

		  return false;
	  };

	  int getPrzeliczonaIloscProbek()
	  {
		  return this->przeliczonaIloscProbek;
	  }

	  void setCom(Com *com)
	  {
		  this->com = com;
	  };

	  Pakiet()
	  {
		  this->pakietPoprawny  = false;
	  };

	  unsigned char* getProbki()
	  {
		 return this->probki;
	  }

	private:
	

	Com *com;

	unsigned char poczatekPakietu[2];

	unsigned char podstawaCzasu[1];

	unsigned char tryb[1];

	unsigned char iloscProbek[2];

	unsigned char *probki;

	unsigned char koniecPakietu[2];

	int przeliczonaIloscProbek;

	bool szukajPoczatkuPakietu()
	{
		this->com->czytajDoBuffera(this->poczatekPakietu,sizeof(this->poczatekPakietu));

		if(this->sprawdzCzyPoczatekPakieru(this->poczatekPakietu))
		{
			this->zaladujPakiet();
			return true;
		}

		return false;
	}; 

	// sprawdza czy trafilismy na bajty startu
	bool sprawdzCzyPoczatekPakieru(unsigned char dane[2])
	{
		if((int)dane[0] == 7 && (int)dane[1] == 1)
		{
			return true;
		}

		return false;
	}

	bool sprawdzPoprawnoscPakietu()
	{
		if((int)this->koniecPakietu[0] == 3 && (int)this->koniecPakietu[1] == 4)
		{
			this->pakietPoprawny = true;
		}
		else
		{
			this->pakietPoprawny = false;
		}

		return this->pakietPoprawny;
	}

	void zaladujPakiet()
	{
		this->czytajPodstaweCzasu();
		//this->czytajTryb();
		this->czytajIleProbek();

		this->przeliczonaIloscProbek = this->obliczIloscProbek(this->iloscProbek);
		this->probki = new unsigned char[this->przeliczonaIloscProbek];
		this->czytajProbki();

		this->czytajKoniecPakietu();
	}

	int obliczIloscProbek(unsigned char dane[2])
	{

		char binaryString[16];
		unsigned int dzielnik = 128;
		unsigned int z;
		for(int i = 0  ; i < 8 ; i++ )
		{
			if((dane[0]/dzielnik) >= 1)
			{
				binaryString[i] = 1;
				dane[0] -= dzielnik;
			}
			else
			{
				binaryString[i] = 0;
			}

			dzielnik /= 2;

			z = i;
		}

		dzielnik = 128;
		for(int i = z+1  ; i <= 8 + z  ; i++ )
		{
			if((dane[1]/dzielnik) >= 1)
			{
				binaryString[i] = 1;
				dane[1] -= dzielnik;
			}
			else
			{
				binaryString[i] = 0;
			}

			dzielnik /= 2;
		}

		int wynik = 0;
		unsigned int mnoznik = 32768;
		// zlaczamy dwa bajty razem
		for(int i =  0 ; i < sizeof(binaryString); i++)
		{
			if((int)binaryString[i] > 0)
			{
				wynik += mnoznik;
			}

			mnoznik /= 2;
		}

		return wynik;

	}

	void czytajPodstaweCzasu()
	{
		this->com->czytajDoBuffera(this->podstawaCzasu,sizeof(this->podstawaCzasu));
	}

	void czytajTryb()
	{
		this->com->czytajDoBuffera(this->tryb,sizeof(this->tryb));
	}

	void czytajIleProbek()
	{
		this->com->czytajDoBuffera(this->iloscProbek,sizeof(this->iloscProbek));
	}

	void czytajProbki()
	{
		this->com->czytajDoBuffera(this->probki,this->przeliczonaIloscProbek);
	}

	void czytajKoniecPakietu()
	{
		this->com->czytajDoBuffera(this->koniecPakietu,sizeof(this->koniecPakietu));
	}

	

};
#endif 
