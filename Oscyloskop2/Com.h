#ifndef COM_H
#define COM_H
#include "Windows.h"
using namespace System;

/*
klasa odpowiedzialna za polaczenia z comem i odczyt danych do bufera
*/

class Com
{
	protected:
		// np: COM1
		LPCSTR numerPortu;
		// uchwyt do "pliku" czyli do coma , z tego uchwytu bedziemy czytac dane
				 // gdly uzywam emulatora, uzywam com9 do odczytu a com 10 do zapisu
				 // uwaga! funkcja nie czyta dwu cyfrowych portow, com11 zostanie zinterpretowany jako com1!
		HANDLE uchwyt;
		DCB config;
		bool stanUchwytu;
		bool portOtwarty;

	public:
		DCB getConfig(){
			return this->config;	
		};

		HANDLE getUchwyt()
		{
				return this->uchwyt;
		};

		LPCSTR getNumerPortu()
		{
				
				return this->numerPortu;
		};

		void setNumerPortu(LPCSTR numerPortu)
		{	
			// @todo sprawdzanie poprawnosci numeru portu 
			this->numerPortu = numerPortu;		
		};

		//@todo zmienic konfiguracje na asynchroniczna ?
		bool otwurzPort()
		{
			this->uchwyt = CreateFileA(this->numerPortu, GENERIC_READ, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
			// wazne! jesli nie ustawie timeoutow to przy probie odczytu i braku danych na porcie funkcja odczytu bedzie czekac tak dlugo az przyjda dane co  zablokuje program
			COMMTIMEOUTS timeouts;
			timeouts. ReadTotalTimeoutConstant = 10;
			timeouts.ReadIntervalTimeout = 10;
			timeouts.ReadTotalTimeoutMultiplier = 1;
			COMMTIMEOUTS* pointer = &timeouts;
			SetCommTimeouts(this->uchwyt,pointer);
			//this->uchwyt = CreateFileA(this->numerPortu, GENERIC_READ, 0, 0, OPEN_EXISTING, FILE_FLAG_OVERLAPPED, 0);
			

			// sprawdzamy stan uchwytu do coma
			// przekazujemy przez referencje obiekty config - ktory bedzie zawieral szczytana konfiguracje coma
			GetCommState(this->uchwyt,&this->config);

		// jesli uchwyt jest OK (np: nikt go juz nie otworzyl)
			this->portOtwarty = true;
			return this->getStanUchwytu();

		}

		bool getStanUchwytu()
		{
			// jesli uchwyt jest OK (np: nikt go juz nie otworzyl)
			if (this->portOtwarty == true && this->uchwyt != INVALID_HANDLE_VALUE)
		{
			this->stanUchwytu = true;
		}
		else
		{
			this->stanUchwytu = false;
		}

		return this->stanUchwytu;
		}

		void czytajDoBuffera(unsigned char* buffer, int i)
		{
			// czytanie z uchwytu coma do bufera
		// @see http://msdn.microsoft.com/en-us/library/windows/desktop/aa365467%28v=vs.85%29.aspx
			if(this->stanUchwytu)
			{
				//DWORD myBytesRead = 0;
				DWORD myBytesRead = NULL;
				//OVERLAPPED* ov = new OVERLAPPED;
				//ov.INTERNAL = 
				ReadFile(this->uchwyt, buffer, i, &myBytesRead, NULL);
			}
				
		};

		Com(LPCSTR numerPortu)
		{
			this->portOtwarty = false;
			this->setNumerPortu(numerPortu);
		}

		//constructor
		void zwolnijPort()
		{
			// zmkniecie uchwytu do coma ,uchwyt trzeba zwolnic zawsze na koniec programu aby uniknac problemu
			CloseHandle(this->uchwyt);
			this->stanUchwytu = false;
			this->portOtwarty = false;
		}

		// destructor
		// @see http://www.learncpp.com/cpp-tutorial/86-destructors/
		~Com()
		{
			this->zwolnijPort();
			
		}
};
#endif 