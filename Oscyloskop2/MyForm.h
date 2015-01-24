#pragma once
#include "Windows.h"
#include "Oscyl.h"
#include "Com.h"
#include "Pakiet.h"
#include <string.h>
#include <iostream>
#include <msclr\marshal.h>
#include <time.h>

using namespace System;





namespace Oscyloskop2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Drawing::Drawing2D;
	using namespace msclr::interop;

	

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	private: System::Windows::Forms::Button^  przyciskCzytajPort;


	

	
	


	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::PictureBox^  pictureBox2;

	private: System::Windows::Forms::Timer^  timer1;
	private: System::ComponentModel::IContainer^  components;
	 
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::PictureBox^  kutas;
			 
	public: 
		int flag;
		// pointer do obiektu typu oscyl
		Oscyl *oscyl;
		Com *com;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  indykatorLiczbyPakietow;

	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  indykatorCzasuOdOstatniegoPakietu;

	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  indykatorSredniegoCzasuPomiedzyPakietami;
	private: System::Windows::Forms::TextBox^  indykatorSredniegoCzasuNaAnalize;


	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::TextBox^  indykatorSredniegoCzasuNaRendering;

	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::PictureBox^  indykatorPoczatkuPakietu;


	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::PictureBox^  indykatorAnalizyPakietu;

	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::PictureBox^  indykatorRenderowaniaWykresu;
	private: System::Windows::Forms::TextBox^  wejscieIleRazyPrzeszukiwac;


	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Button^  przyciskUwolnijPort;
	private: System::Windows::Forms::Button^  przyciskZatrzymaj;


	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::RichTextBox^  poleProbkiZOstatniegoPakietu;

	private: System::Windows::Forms::TextBox^  indykatorLiczbaProbekWOstatnimPakiecie;

	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::TextBox^  indykatorSredniaLiczbaProbek;

	private: System::Windows::Forms::Label^  label15;
	private: System::Windows::Forms::Button^  przyciskWznow;
	private: System::Windows::Forms::TextBox^  wejsciePortCom;

	public: 

		Pakiet *pakiet;
	

		MyForm(void)
		{
			
			// to jest stala i trzeba ja przekazac przez referencje ;)
			this->obecnyPort = "\\\\.\\COM9";
			// mozna tez podac do testu plik z danymi ;)
			this->com = new Com(this->obecnyPort);
			this->com->otwurzPort();
			this->pakiet = new Pakiet();
			this->pakiet->setCom(this->com);
			
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			timer1->Enabled = true;
			this->flag = 1;

			this->pobierajPakiety = true;

			
			
		}

	protected:

		LPCSTR obecnyPort;
		
		bool pobierajPakiety;

		clock_t czasOstatniegoPakietu;

		int sredniCzasMiedzyPakietami;
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->przyciskCzytajPort = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->kutas = (gcnew System::Windows::Forms::PictureBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->indykatorLiczbyPakietow = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->indykatorCzasuOdOstatniegoPakietu = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->indykatorSredniegoCzasuPomiedzyPakietami = (gcnew System::Windows::Forms::TextBox());
			this->indykatorSredniegoCzasuNaAnalize = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->indykatorSredniegoCzasuNaRendering = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->indykatorPoczatkuPakietu = (gcnew System::Windows::Forms::PictureBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->indykatorAnalizyPakietu = (gcnew System::Windows::Forms::PictureBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->indykatorRenderowaniaWykresu = (gcnew System::Windows::Forms::PictureBox());
			this->wejscieIleRazyPrzeszukiwac = (gcnew System::Windows::Forms::TextBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->przyciskUwolnijPort = (gcnew System::Windows::Forms::Button());
			this->przyciskZatrzymaj = (gcnew System::Windows::Forms::Button());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->poleProbkiZOstatniegoPakietu = (gcnew System::Windows::Forms::RichTextBox());
			this->indykatorLiczbaProbekWOstatnimPakiecie = (gcnew System::Windows::Forms::TextBox());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->indykatorSredniaLiczbaProbek = (gcnew System::Windows::Forms::TextBox());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->przyciskWznow = (gcnew System::Windows::Forms::Button());
			this->wejsciePortCom = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->kutas))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->indykatorPoczatkuPakietu))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->indykatorAnalizyPakietu))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->indykatorRenderowaniaWykresu))->BeginInit();
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Interval = 1;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// przyciskCzytajPort
			// 
			this->przyciskCzytajPort->Location = System::Drawing::Point(1329, 70);
			this->przyciskCzytajPort->Name = L"przyciskCzytajPort";
			this->przyciskCzytajPort->Size = System::Drawing::Size(125, 23);
			this->przyciskCzytajPort->TabIndex = 2;
			this->przyciskCzytajPort->Text = L"Czytaj z portu";
			this->przyciskCzytajPort->UseVisualStyleBackColor = true;
			this->przyciskCzytajPort->Click += gcnew System::EventHandler(this, &MyForm::przyciskCzytajPort_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(1269, 106);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(170, 13);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Port COM (Domyslnie: \\\\.\\COM9 ):";
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(940, 196);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->ReadOnly = true;
			this->richTextBox1->Size = System::Drawing::Size(127, 214);
			this->richTextBox1->TabIndex = 5;
			this->richTextBox1->Text = L"";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(948, 169);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(93, 13);
			this->label2->TabIndex = 6;
			this->label2->Text = L"dane z portu COM";
			// 
			// pictureBox2
			// 
			this->pictureBox2->Location = System::Drawing::Point(957, 447);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(53, 44);
			this->pictureBox2->TabIndex = 7;
			this->pictureBox2->TabStop = false;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(954, 431);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(288, 13);
			this->label3->TabIndex = 8;
			this->label3->Text = L"Stan portu COM - zielony aktywny , czerwony - nie aktywny ";
			// 
			// kutas
			// 
			this->kutas->Location = System::Drawing::Point(12, 12);
			this->kutas->Name = L"kutas";
			this->kutas->Size = System::Drawing::Size(900, 512);
			this->kutas->TabIndex = 9;
			this->kutas->TabStop = false;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(951, 495);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(146, 13);
			this->label4->TabIndex = 10;
			this->label4->Text = L"Liczba odebranych pakietow:";
			this->label4->Click += gcnew System::EventHandler(this, &MyForm::label4_Click);
			// 
			// indykatorLiczbyPakietow
			// 
			this->indykatorLiczbyPakietow->Location = System::Drawing::Point(954, 521);
			this->indykatorLiczbyPakietow->Name = L"indykatorLiczbyPakietow";
			this->indykatorLiczbyPakietow->ReadOnly = true;
			this->indykatorLiczbyPakietow->Size = System::Drawing::Size(100, 20);
			this->indykatorLiczbyPakietow->TabIndex = 11;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(951, 557);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(217, 13);
			this->label5->TabIndex = 12;
			this->label5->Text = L"Czas od ostatniego odebranego pakietu (ms)";
			// 
			// indykatorCzasuOdOstatniegoPakietu
			// 
			this->indykatorCzasuOdOstatniegoPakietu->Location = System::Drawing::Point(954, 585);
			this->indykatorCzasuOdOstatniegoPakietu->Name = L"indykatorCzasuOdOstatniegoPakietu";
			this->indykatorCzasuOdOstatniegoPakietu->ReadOnly = true;
			this->indykatorCzasuOdOstatniegoPakietu->Size = System::Drawing::Size(100, 20);
			this->indykatorCzasuOdOstatniegoPakietu->TabIndex = 13;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(954, 620);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(172, 13);
			this->label6->TabIndex = 14;
			this->label6->Text = L"Sredni czas na pomiedzy pakietami";
			this->label6->Click += gcnew System::EventHandler(this, &MyForm::label6_Click);
			// 
			// indykatorSredniegoCzasuPomiedzyPakietami
			// 
			this->indykatorSredniegoCzasuPomiedzyPakietami->Location = System::Drawing::Point(954, 649);
			this->indykatorSredniegoCzasuPomiedzyPakietami->Name = L"indykatorSredniegoCzasuPomiedzyPakietami";
			this->indykatorSredniegoCzasuPomiedzyPakietami->ReadOnly = true;
			this->indykatorSredniegoCzasuPomiedzyPakietami->Size = System::Drawing::Size(100, 20);
			this->indykatorSredniegoCzasuPomiedzyPakietami->TabIndex = 15;
			// 
			// indykatorSredniegoCzasuNaAnalize
			// 
			this->indykatorSredniegoCzasuNaAnalize->Location = System::Drawing::Point(954, 712);
			this->indykatorSredniegoCzasuNaAnalize->Name = L"indykatorSredniegoCzasuNaAnalize";
			this->indykatorSredniegoCzasuNaAnalize->ReadOnly = true;
			this->indykatorSredniegoCzasuNaAnalize->Size = System::Drawing::Size(100, 20);
			this->indykatorSredniegoCzasuNaAnalize->TabIndex = 17;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(954, 683);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(416, 13);
			this->label7->TabIndex = 16;
			this->label7->Text = L"Sredni czas na analize pakietu ( czas od odebrania do stwierdzenia czy jest popra" 
				L"wny )";
			// 
			// indykatorSredniegoCzasuNaRendering
			// 
			this->indykatorSredniegoCzasuNaRendering->Location = System::Drawing::Point(954, 779);
			this->indykatorSredniegoCzasuNaRendering->Name = L"indykatorSredniegoCzasuNaRendering";
			this->indykatorSredniegoCzasuNaRendering->ReadOnly = true;
			this->indykatorSredniegoCzasuNaRendering->Size = System::Drawing::Size(100, 20);
			this->indykatorSredniegoCzasuNaRendering->TabIndex = 19;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(954, 750);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(186, 13);
			this->label8->TabIndex = 18;
			this->label8->Text = L"Œredni czas na renderowanie wykresu";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(1283, 431);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(168, 13);
			this->label9->TabIndex = 21;
			this->label9->Text = L"Oczekiwanie na pocz¹tek pakietu";
			// 
			// indykatorPoczatkuPakietu
			// 
			this->indykatorPoczatkuPakietu->Location = System::Drawing::Point(1286, 447);
			this->indykatorPoczatkuPakietu->Name = L"indykatorPoczatkuPakietu";
			this->indykatorPoczatkuPakietu->Size = System::Drawing::Size(33, 27);
			this->indykatorPoczatkuPakietu->TabIndex = 20;
			this->indykatorPoczatkuPakietu->TabStop = false;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(1283, 482);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(78, 13);
			this->label10->TabIndex = 23;
			this->label10->Text = L"analiza pakietu";
			// 
			// indykatorAnalizyPakietu
			// 
			this->indykatorAnalizyPakietu->Location = System::Drawing::Point(1286, 498);
			this->indykatorAnalizyPakietu->Name = L"indykatorAnalizyPakietu";
			this->indykatorAnalizyPakietu->Size = System::Drawing::Size(33, 27);
			this->indykatorAnalizyPakietu->TabIndex = 22;
			this->indykatorAnalizyPakietu->TabStop = false;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(1286, 533);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(148, 13);
			this->label11->TabIndex = 25;
			this->label11->Text = L"Renderowane wykresu i siatki";
			this->label11->Click += gcnew System::EventHandler(this, &MyForm::label11_Click);
			// 
			// indykatorRenderowaniaWykresu
			// 
			this->indykatorRenderowaniaWykresu->Location = System::Drawing::Point(1289, 549);
			this->indykatorRenderowaniaWykresu->Name = L"indykatorRenderowaniaWykresu";
			this->indykatorRenderowaniaWykresu->Size = System::Drawing::Size(33, 27);
			this->indykatorRenderowaniaWykresu->TabIndex = 24;
			this->indykatorRenderowaniaWykresu->TabStop = false;
			// 
			// wejscieIleRazyPrzeszukiwac
			// 
			this->wejscieIleRazyPrzeszukiwac->Location = System::Drawing::Point(1284, 335);
			this->wejscieIleRazyPrzeszukiwac->Name = L"wejscieIleRazyPrzeszukiwac";
			this->wejscieIleRazyPrzeszukiwac->Size = System::Drawing::Size(100, 20);
			this->wejscieIleRazyPrzeszukiwac->TabIndex = 27;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(1281, 309);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(332, 13);
			this->label12->TabIndex = 26;
			this->label12->Text = L"Ile razy przeczesywac port w poszukiwaniu pocztku pakieru na obieg";
			// 
			// przyciskUwolnijPort
			// 
			this->przyciskUwolnijPort->Location = System::Drawing::Point(1329, 21);
			this->przyciskUwolnijPort->Name = L"przyciskUwolnijPort";
			this->przyciskUwolnijPort->Size = System::Drawing::Size(125, 23);
			this->przyciskUwolnijPort->TabIndex = 28;
			this->przyciskUwolnijPort->Text = L"Uwolnij port";
			this->przyciskUwolnijPort->UseVisualStyleBackColor = true;
			this->przyciskUwolnijPort->Click += gcnew System::EventHandler(this, &MyForm::przyciskUwolnijPort_Click);
			// 
			// przyciskZatrzymaj
			// 
			this->przyciskZatrzymaj->Location = System::Drawing::Point(1181, 21);
			this->przyciskZatrzymaj->Name = L"przyciskZatrzymaj";
			this->przyciskZatrzymaj->Size = System::Drawing::Size(125, 23);
			this->przyciskZatrzymaj->TabIndex = 29;
			this->przyciskZatrzymaj->Text = L"Zatrzymaj";
			this->przyciskZatrzymaj->UseVisualStyleBackColor = true;
			this->przyciskZatrzymaj->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(1088, 168);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(135, 13);
			this->label13->TabIndex = 31;
			this->label13->Text = L"Probki z ostatniego pakietu";
			// 
			// poleProbkiZOstatniegoPakietu
			// 
			this->poleProbkiZOstatniegoPakietu->Location = System::Drawing::Point(1091, 196);
			this->poleProbkiZOstatniegoPakietu->Name = L"poleProbkiZOstatniegoPakietu";
			this->poleProbkiZOstatniegoPakietu->ReadOnly = true;
			this->poleProbkiZOstatniegoPakietu->Size = System::Drawing::Size(164, 214);
			this->poleProbkiZOstatniegoPakietu->TabIndex = 30;
			this->poleProbkiZOstatniegoPakietu->Text = L"";
			// 
			// indykatorLiczbaProbekWOstatnimPakiecie
			// 
			this->indykatorLiczbaProbekWOstatnimPakiecie->Location = System::Drawing::Point(1284, 195);
			this->indykatorLiczbaProbekWOstatnimPakiecie->Name = L"indykatorLiczbaProbekWOstatnimPakiecie";
			this->indykatorLiczbaProbekWOstatnimPakiecie->ReadOnly = true;
			this->indykatorLiczbaProbekWOstatnimPakiecie->Size = System::Drawing::Size(100, 20);
			this->indykatorLiczbaProbekWOstatnimPakiecie->TabIndex = 33;
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(1281, 169);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(170, 13);
			this->label14->TabIndex = 32;
			this->label14->Text = L"Liczba probek w ostatnim pakiecie";
			// 
			// indykatorSredniaLiczbaProbek
			// 
			this->indykatorSredniaLiczbaProbek->Location = System::Drawing::Point(1284, 258);
			this->indykatorSredniaLiczbaProbek->Name = L"indykatorSredniaLiczbaProbek";
			this->indykatorSredniaLiczbaProbek->ReadOnly = true;
			this->indykatorSredniaLiczbaProbek->Size = System::Drawing::Size(100, 20);
			this->indykatorSredniaLiczbaProbek->TabIndex = 35;
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(1281, 232);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(163, 13);
			this->label15->TabIndex = 34;
			this->label15->Text = L"Œrednia liczba próbek w pakiecie";
			// 
			// przyciskWznow
			// 
			this->przyciskWznow->Location = System::Drawing::Point(1181, 70);
			this->przyciskWznow->Name = L"przyciskWznow";
			this->przyciskWznow->Size = System::Drawing::Size(125, 23);
			this->przyciskWznow->TabIndex = 36;
			this->przyciskWznow->Text = L"Wznów";
			this->przyciskWznow->UseVisualStyleBackColor = true;
			this->przyciskWznow->Click += gcnew System::EventHandler(this, &MyForm::przyciskWznow_Click);
			// 
			// wejsciePortCom
			// 
			this->wejsciePortCom->Location = System::Drawing::Point(1329, 132);
			this->wejsciePortCom->Name = L"wejsciePortCom";
			this->wejsciePortCom->Size = System::Drawing::Size(100, 20);
			this->wejsciePortCom->TabIndex = 37;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1491, 800);
			this->Controls->Add(this->wejsciePortCom);
			this->Controls->Add(this->przyciskWznow);
			this->Controls->Add(this->indykatorSredniaLiczbaProbek);
			this->Controls->Add(this->label15);
			this->Controls->Add(this->indykatorLiczbaProbekWOstatnimPakiecie);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->poleProbkiZOstatniegoPakietu);
			this->Controls->Add(this->przyciskZatrzymaj);
			this->Controls->Add(this->przyciskUwolnijPort);
			this->Controls->Add(this->wejscieIleRazyPrzeszukiwac);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->indykatorRenderowaniaWykresu);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->indykatorAnalizyPakietu);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->indykatorPoczatkuPakietu);
			this->Controls->Add(this->indykatorSredniegoCzasuNaRendering);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->indykatorSredniegoCzasuNaAnalize);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->indykatorSredniegoCzasuPomiedzyPakietami);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->indykatorCzasuOdOstatniegoPakietu);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->indykatorLiczbyPakietow);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->kutas);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->przyciskCzytajPort);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->kutas))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->indykatorPoczatkuPakietu))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->indykatorAnalizyPakietu))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->indykatorRenderowaniaWykresu))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {

				 // iniclajalizacja pola do rysowania
				 this->kutas->Image = gcnew Bitmap(this->kutas->Width,this->kutas->Height);
				 this->oscyl = new Oscyl(this->kutas->Width,this->kutas->Height,100,100);

				 this->pictureBox2->Image = gcnew Bitmap(this->pictureBox2->Width,this->pictureBox2->Height);
				// @todo na resize okna na pewno trzeba bedzie na nowo rysowac plansze

				indykatorPoczatkuPakietu->Image = gcnew Bitmap(this->indykatorPoczatkuPakietu->Width,this->indykatorPoczatkuPakietu->Height);
				indykatorAnalizyPakietu->Image = gcnew Bitmap(this->indykatorAnalizyPakietu->Width,this->indykatorAnalizyPakietu->Height);
				indykatorRenderowaniaWykresu->Image = gcnew Bitmap(this->indykatorRenderowaniaWykresu->Width,this->indykatorRenderowaniaWykresu->Height);
				
				//this->wejsciePortCom->Text = System::Convert::ToString((LPCSTR)this->obecnyPort);

			 }

   
	/*
	timer tick event , funkcja jest odpalana automarycznie co jakis czas ( nie wiem jeszcze jak startowac tym czasem )
	pobiera dane z bufora danych i rysuje na ekranie wykres
	@todo zamiast korzystac z tego eventu to moze lepiej zrobic w¹tek ?
	*/
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {

				 // wylaczamy timer na czas obslugi zdarzenia
				 timer1->Enabled = false;
	

	
	if (this->com->getStanUchwytu() == true)
	{
	
		pictureBox2->BackColor = Drawing::Color::Green;

		indykatorPoczatkuPakietu->BackColor = Drawing::Color::Red;
		indykatorAnalizyPakietu->BackColor = Drawing::Color::Red;
		indykatorRenderowaniaWykresu->BackColor = Drawing::Color::Red;

		/*Graphics ^ pg = Graphics::FromImage(pictureBox2->Image);

					 Pen^ pn = gcnew Pen(Color::Green);
					Point StartPoint = Point(10,10);
				     Point EndPoint = Point(20,20);
					 this->pictureBox2->Refresh();*/

		
		if(this->pobierajPakiety)
		{
			indykatorPoczatkuPakietu->BackColor = Drawing::Color::Green;
			indykatorPoczatkuPakietu->Refresh();


		int limit = 100;
		bool poprawny =   this->pakiet->pobierzPakiet(limit);
		//bool poprawny = false;
			
		this->indykatorCzasuOdOstatniegoPakietu->Text = System::Convert::ToString(int(clock() - this->czasOstatniegoPakietu));

			if(poprawny)
			{
				this->indykatorLiczbyPakietow->Text = System::Convert::ToString(this->pakiet->liczbaPakietow);


				indykatorPoczatkuPakietu->BackColor = Drawing::Color::Red;
				indykatorPoczatkuPakietu->Refresh();

				indykatorAnalizyPakietu->BackColor = Drawing::Color::Green;
				indykatorAnalizyPakietu->Refresh();

				clock_t przerwaMiedzyPakietami = clock() - this->czasOstatniegoPakietu;
				this->sredniCzasMiedzyPakietami = ((this->sredniCzasMiedzyPakietami*(this->pakiet->liczbaPakietow-1)) + (int)przerwaMiedzyPakietami)/this->pakiet->liczbaPakietow;

				this->indykatorSredniegoCzasuPomiedzyPakietami->Text = System::Convert::ToString(this->sredniCzasMiedzyPakietami);
				this->indykatorSredniaLiczbaProbek->Text = System::Convert::ToString(this->pakiet->sredniaLiczbaProbek);
				this->czasOstatniegoPakietu = clock();
				unsigned char* c = this->pakiet->getProbki();
					this->oscyl->zaladujProbki(c,this->pakiet->getPrzeliczonaIloscProbek());

					indykatorAnalizyPakietu->BackColor = Drawing::Color::Red;
					indykatorAnalizyPakietu->Refresh();

					
    // kutas->Refresh();

				// podglad przychodzacych danych w osobnym okienku w formacie ASCII
				  // this->wyplujDaneZComaDoOkienka();
		
					this->wyplujOstatnieProbki(this->pakiet->getProbki(),this->pakiet->getPrzeliczonaIloscProbek());

	
	
					
					

					

					//this->kutas->Image = gcnew Bitmap(this->oscyl->displayMaxX,this->oscyl->displayMaxY);
					// wyrysowanie wykresu z bierzacego bufora
					indykatorRenderowaniaWykresu->BackColor = Drawing::Color::Green;
					indykatorRenderowaniaWykresu->Refresh();
						this->rysujWykres();

					this->rysujSiatke();
					indykatorRenderowaniaWykresu->BackColor = Drawing::Color::Red;
				    indykatorRenderowaniaWykresu->Refresh();

					this->kutas->Refresh();
			}

		}

	}
	else
	{
		pictureBox2->BackColor = Drawing::Color::Red;
	}

	

	timer1->Enabled = true;

	
	


			 }

			 void wyplujOstatnieProbki(unsigned char* probki, int ileProbek)
			 {
				   this->poleProbkiZOstatniegoPakietu->Clear();
				   this->indykatorLiczbaProbekWOstatnimPakiecie->Text = System::Convert::ToString(ileProbek);
				   for(int i = 0 ; i < ileProbek ; i++)
				   {
					   this->poleProbkiZOstatniegoPakietu->AppendText(System::Convert::ToString(probki[i]));
					   this->poleProbkiZOstatniegoPakietu->AppendText("\r\n");

						   
				   }
			 }

			 void wyplujDaneZComaDoOkienka()
			 {
				/* std::string str = std::string( this->oscyl->probki);
				// konwersja na system string
				String^ str2 = gcnew String(str.c_str());
				// jeszcze sprawdzenie czy rozmiar pola nie zostal przekroczony, jesli tak to wyczyscic
				

				 if ( (this->richTextBox1->SelectedText->Length + str2->Length) > this->richTextBox1->MaxLength )
					 this->richTextBox1->Clear();
				   else
						 // @see http://msdn.microsoft.com/pl-pl/library/system.windows.forms.textboxbase.appendtext(v=vs.110).aspx?cs-save-lang=1&cs-lang=cpp#code-snippet-1
				this->richTextBox1->AppendText(str2);*/

				 // @todo przydaloby sie jeszcze jakis auto-scroll zeby to za tymi danymi latalo na dul
			 }

			 void rysujSiatke()
			 {
				 Graphics ^ pg = Graphics::FromImage(kutas->Image);
				 Pen^ pn = gcnew Pen(Color::Black);

				 // w poziomie od srodka
				 int srodek = (int)this->oscyl->displayMaxY/2;
				 for(int i=0;i<srodek; i+=this->oscyl->spaceY)
				 {
					 // na przemian jedna wyzej , jedna nizej
					 Point StartPoint = Point(1,srodek + i);
				     Point EndPoint = Point(this->oscyl->displayMaxX,srodek + i);
					 pg->DrawLine(pn,StartPoint,EndPoint);

					 Point StartPoin2t = Point(1,srodek - i);
				     Point EndPoint2 = Point(this->oscyl->displayMaxX,srodek - i);
					 pg->DrawLine(pn,StartPoin2t,EndPoint2);
				 }
				
				 // w pionie
				 int srodekWPoziom = (int)this->oscyl->displayMaxX/2;
				 for(int i=0;i<srodekWPoziom;i+=this->oscyl->spaceX)
				 {
					 Point StartPoint = Point(srodekWPoziom + i,this->oscyl->displayMaxY);
				     Point EndPoint = Point(srodekWPoziom + i,1);
					 pg->DrawLine(pn,StartPoint,EndPoint);

					 Point StartPoint2 = Point(srodekWPoziom - i,this->oscyl->displayMaxY);
				     Point EndPoint2 = Point(srodekWPoziom - i,1);
					 pg->DrawLine(pn,StartPoint2,EndPoint2);
				 }

			 }

			 void rysujWykres()
			 {
				 
				 Pen^ pn = gcnew Pen(Color::Green);

				 int x = 1;


				 /*for(int i = 0; i < sizeof(this->oscyl->fakeBuffer)-1; i += this->oscyl->ilePomijac)
				 {
					 Point StartPoint = Point(x,100 + this->oscyl->fakeBuffer[i]);
				     Point EndPoint = Point(x + this->oscyl->ilePixeliProbka,100 + this->oscyl->fakeBuffer[i+1]);
					 pg->DrawLine(pn,StartPoint,EndPoint);

					 x += this->oscyl->ilePixeliProbka;
				 }*/

				 /*Point StartPoint = Point(100,100);
				     Point EndPoint = Point(200,200);
					 pg->DrawLine(pn,StartPoint,EndPoint);*/

				
				 GraphicsPath^ path = gcnew GraphicsPath;

				 for(int i = 0; i < this->oscyl->liczbaProbek - 1; i += this->oscyl->ilePomijac)
				 {
					 
					 PointF StartPoint = PointF(x,this->oscyl->displayMaxY - (this->oscyl->probki[i]*this->oscyl->mnoznikWysokosciowy));
					 PointF EndPoint = PointF(x + this->oscyl->ilePixeliProbka,this->oscyl->displayMaxY - (this->oscyl->probki[i+1]*this->oscyl->mnoznikWysokosciowy));
					 //pg->DrawLine(pn,StartPoint,EndPoint);

					 path->AddLine(StartPoint,EndPoint);

					 x += this->oscyl->ilePixeliProbka;
				 }

				 this->kutas->Image = gcnew Bitmap(this->oscyl->displayMaxX,this->oscyl->displayMaxY);
				 //Graphics ^ pg = Graphics::FromImage(kutas->Image);
				 Bitmap^ image = gcnew Bitmap(this->oscyl->displayMaxX,this->oscyl->displayMaxY);
				 Graphics ^ pg = Graphics::FromImage(image);
				 // @see https://msdn.microsoft.com/en-us/library/system.drawing.graphics.drawpath(v=vs.110).aspx
				 pg->DrawPath(pn,path);
				 kutas->Image = image;

				// kutas->Refresh();
			 }

			 bool To_CharStar(String^ source, char*& target)
				{
				  int len = (source->Length+1) * 2;
				  target = new char[len];
				  pin_ptr<const wchar_t> wch = PtrToStringChars(source);
				  return wcstombs(target, wch, len) != -1;
				}

	

private: System::Void label4_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void label6_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void label9_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void label11_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {

			  this->pobierajPakiety = false;
		 }
private: System::Void przyciskWznow_Click(System::Object^  sender, System::EventArgs^  e) {

			 this->pobierajPakiety = true;
		 }
private: System::Void przyciskUwolnijPort_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->com->zwolnijPort();
		 }
private: System::Void przyciskCzytajPort_Click(System::Object^  sender, System::EventArgs^  e) {

			 String^ text = this->wejsciePortCom->Text;
			// marshal_context context;

			  char *TBtext;
			  To_CharStar(text, TBtext);

			 LPCSTR port = TBtext;
			 if(this->com->getStanUchwytu())
			 {
				  this->com->zwolnijPort();
			 }
			
			 this->com->setNumerPortu(port);

			 this->com->otwurzPort();
		 }
};

	
	
}
