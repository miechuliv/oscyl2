#pragma once
#include "Windows.h"
#include "Oscyl.h"
#include "Com.h"
#include "Pakiet.h"
#include <string.h>
#include <iostream>
using namespace System;





namespace Oscyloskop2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Drawing::Drawing2D;

	

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{

	

	
	
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::ComboBox^  comboBox1;
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
	
		Pakiet *pakiet;
	

		MyForm(void)
		{
			this->oscyl = new Oscyl(548,287,20,30);
			// to jest stala i trzeba ja przekazac przez referencje ;)
			LPCSTR port = "\\\\.\\COM11";
			// mozna tez podac do testu plik z danymi ;)
			this->com = new Com(port);
			this->com->otwurzPort();
			this->pakiet = new Pakiet();
			this->pakiet->setCom(this->com);
			
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			timer1->Enabled = true;
			this->flag = 1;

			
			
		}

	protected:
		
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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->kutas = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->kutas))->BeginInit();
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Interval = 1;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(802, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(125, 23);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Czytaj z portu";
			this->button1->UseVisualStyleBackColor = true;
			
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(802, 81);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 21);
			this->comboBox1->TabIndex = 3;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(799, 53);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(56, 13);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Port COM:";
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(743, 194);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->ReadOnly = true;
			this->richTextBox1->Size = System::Drawing::Size(180, 278);
			this->richTextBox1->TabIndex = 5;
			this->richTextBox1->Text = L"";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(743, 168);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(93, 13);
			this->label2->TabIndex = 6;
			this->label2->Text = L"dane z portu COM";
			// 
			// pictureBox2
			// 
			this->pictureBox2->Location = System::Drawing::Point(656, 137);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(53, 44);
			this->pictureBox2->TabIndex = 7;
			this->pictureBox2->TabStop = false;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(653, 121);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(288, 13);
			this->label3->TabIndex = 8;
			this->label3->Text = L"Stan portu COM - zielony aktywny , czerwony - nie aktywny ";
			// 
			// kutas
			// 
			this->kutas->Location = System::Drawing::Point(74, 12);
			this->kutas->Name = L"kutas";
			this->kutas->Size = System::Drawing::Size(544, 327);
			this->kutas->TabIndex = 9;
			this->kutas->TabStop = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(953, 552);
			this->Controls->Add(this->kutas);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->kutas))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {

				 // iniclajalizacja pola do rysowania
				 this->kutas->Image = gcnew Bitmap(this->oscyl->displayMaxX,this->oscyl->displayMaxY);
				 this->pictureBox2->Image = gcnew Bitmap(30,30);
				// @todo na resize okna na pewno trzeba bedzie na nowo rysowac plansze
				
				
				 

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

		/*Graphics ^ pg = Graphics::FromImage(pictureBox2->Image);

					 Pen^ pn = gcnew Pen(Color::Green);
					Point StartPoint = Point(10,10);
				     Point EndPoint = Point(20,20);
					 this->pictureBox2->Refresh();*/

		

		int limit = 100000;
		bool poprawny =   this->pakiet->pobierzPakiet(limit);
		//bool poprawny = false;
			

			if(poprawny)
			{
				unsigned char* c = this->pakiet->getProbki();
					this->oscyl->zaladujProbki(c,this->pakiet->getPrzeliczonaIloscProbek());

					
    // kutas->Refresh();

				// podglad przychodzacych danych w osobnym okienku w formacie ASCII
				  // this->wyplujDaneZComaDoOkienka();
		
		

	
	
					
					

					

					//this->kutas->Image = gcnew Bitmap(this->oscyl->displayMaxX,this->oscyl->displayMaxY);
					// wyrysowanie wykresu z bierzacego bufora
						this->rysujWykres();

					this->rysujSiatke();

					//this->kutas->Refresh();
			}

	}
	else
	{
		pictureBox2->BackColor = Drawing::Color::Red;
	}

	

	timer1->Enabled = true;

	
	


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
				 // w poziomie 
				 for(int i=this->oscyl->spaceY;i<this->oscyl->displayMaxY;i+=this->oscyl->spaceY)
				 {
					 Point StartPoint = Point(1,i);
				     Point EndPoint = Point(this->oscyl->displayMaxX,i);
					 pg->DrawLine(pn,StartPoint,EndPoint);
				 }
				
				 // w pionie
				 for(int i=this->oscyl->spaceX;i<this->oscyl->displayMaxX;i+=this->oscyl->spaceX)
				 {
					 Point StartPoint = Point(i,this->oscyl->displayMaxY);
				     Point EndPoint = Point(i,1);
					 pg->DrawLine(pn,StartPoint,EndPoint);
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
					 // @todo jak wyrenderowac je w jednym poleceniu , bo renderowanie ich osobno zabiera za duzo czasu -  dlategor wykres co chwila znika
					 // mozna by zrobic jeszcze co innego , chowac obrazek na czas renderowania i go pokazywac
					 PointF StartPoint = PointF(x,this->oscyl->displayMaxY - this->oscyl->probki[i]);
					 PointF EndPoint = PointF(x + this->oscyl->ilePixeliProbka,this->oscyl->displayMaxY - this->oscyl->probki[i+1]);
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
			 }


	

};

	
	
}
