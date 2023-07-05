#pragma once
#include"FrmMain.h"
#include"FrmNiveldos.h"
#include"FrmJugar.h"
#include "FrmInstruciones.h"
#include "FrmCreditos.h"
namespace JuegoTF {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for FrmMenu
	/// </summary>
	public ref class FrmMenu : public System::Windows::Forms::Form
	{
	public:
		FrmMenu(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FrmMenu()
		{
			if (components)
			{
				delete components;
			}
		}



	private: System::Windows::Forms::Button^ btnInstrucciones;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Button^ btnJugar;
	private: System::Windows::Forms::Button^ btnCreditos;
	private: System::Windows::Forms::Button^ btnSalir;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	protected:

	protected:


	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FrmMenu::typeid));
			this->btnInstrucciones = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->btnJugar = (gcnew System::Windows::Forms::Button());
			this->btnCreditos = (gcnew System::Windows::Forms::Button());
			this->btnSalir = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// btnInstrucciones
			// 
			this->btnInstrucciones->Font = (gcnew System::Drawing::Font(L"Stencil", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnInstrucciones->ForeColor = System::Drawing::SystemColors::MenuHighlight;
			this->btnInstrucciones->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnInstrucciones.Image")));
			this->btnInstrucciones->Location = System::Drawing::Point(454, 288);
			this->btnInstrucciones->Name = L"btnInstrucciones";
			this->btnInstrucciones->Size = System::Drawing::Size(209, 104);
			this->btnInstrucciones->TabIndex = 3;
			this->btnInstrucciones->Text = L"Instrucciones";
			this->btnInstrucciones->UseVisualStyleBackColor = true;
			this->btnInstrucciones->Click += gcnew System::EventHandler(this, &FrmMenu::btnInstrucciones_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(4, 3);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(893, 576);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 4;
			this->pictureBox1->TabStop = false;
			// 
			// btnJugar
			// 
			this->btnJugar->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->btnJugar->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->btnJugar->Font = (gcnew System::Drawing::Font(L"Stencil", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnJugar->ForeColor = System::Drawing::Color::MidnightBlue;
			this->btnJugar->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnJugar.Image")));
			this->btnJugar->Location = System::Drawing::Point(26, 287);
			this->btnJugar->Name = L"btnJugar";
			this->btnJugar->Size = System::Drawing::Size(209, 104);
			this->btnJugar->TabIndex = 5;
			this->btnJugar->Text = L"JUGAR";
			this->btnJugar->UseVisualStyleBackColor = false;
			this->btnJugar->Click += gcnew System::EventHandler(this, &FrmMenu::btnJugar_Click);
			// 
			// btnCreditos
			// 
			this->btnCreditos->Font = (gcnew System::Drawing::Font(L"Stencil", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnCreditos->ForeColor = System::Drawing::Color::OliveDrab;
			this->btnCreditos->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnCreditos.Image")));
			this->btnCreditos->Location = System::Drawing::Point(240, 410);
			this->btnCreditos->Name = L"btnCreditos";
			this->btnCreditos->Size = System::Drawing::Size(209, 104);
			this->btnCreditos->TabIndex = 6;
			this->btnCreditos->Text = L"CREDITOS";
			this->btnCreditos->UseVisualStyleBackColor = true;
			this->btnCreditos->Click += gcnew System::EventHandler(this, &FrmMenu::btnCreditos_Click);
			// 
			// btnSalir
			// 
			this->btnSalir->Font = (gcnew System::Drawing::Font(L"Stencil", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSalir->ForeColor = System::Drawing::SystemColors::Info;
			this->btnSalir->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnSalir.Image")));
			this->btnSalir->Location = System::Drawing::Point(665, 413);
			this->btnSalir->Name = L"btnSalir";
			this->btnSalir->Size = System::Drawing::Size(209, 98);
			this->btnSalir->TabIndex = 7;
			this->btnSalir->Text = L"SALIR";
			this->btnSalir->UseVisualStyleBackColor = true;
			this->btnSalir->Click += gcnew System::EventHandler(this, &FrmMenu::btnSalir_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::NavajoWhite;
			this->label1->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::Orange;
			this->label1->Location = System::Drawing::Point(73, 68);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(251, 33);
			this->label1->TabIndex = 8;
			this->label1->Text = L"PROGRMACIÓN II";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::NavajoWhite;
			this->label2->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::Orange;
			this->label2->Location = System::Drawing::Point(138, 172);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(99, 27);
			this->label2->TabIndex = 9;
			this->label2->Text = L"GRUPO 5";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::NavajoWhite;
			this->label3->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::Orange;
			this->label3->Location = System::Drawing::Point(108, 120);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(163, 27);
			this->label3->TabIndex = 10;
			this->label3->Text = L"TRABAJO FINAL";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"label4.Image")));
			this->label4->Location = System::Drawing::Point(384, 68);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(53, 27);
			this->label4->TabIndex = 11;
			this->label4->Text = L"UPC";
			// 
			// FrmMenu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(900, 582);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->btnSalir);
			this->Controls->Add(this->btnCreditos);
			this->Controls->Add(this->btnJugar);
			this->Controls->Add(this->btnInstrucciones);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"FrmMenu";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"FrmMenu";
			this->Load += gcnew System::EventHandler(this, &FrmMenu::FrmMenu_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void FrmMenu_Load(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void btnJugar_Click(System::Object^ sender, System::EventArgs^ e) {
	FrmJugar^ frmJugar = gcnew FrmJugar();
	this->Visible = false;
	frmJugar->ShowDialog();
	this->Visible = true;
}
private: System::Void btnSalir_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
private: System::Void btnInstrucciones_Click(System::Object^ sender, System::EventArgs^ e) {
	FrmInstruciones^ frmInstrucciones = gcnew FrmInstruciones();
	this->Visible = false;
	frmInstrucciones->ShowDialog();
	this->Visible = true;
}
private: System::Void btnCreditos_Click(System::Object^ sender, System::EventArgs^ e) {
	FrmCreditos^ frmICreditos = gcnew FrmCreditos();
	this->Visible = false;
	frmICreditos->ShowDialog();
	this->Visible = true;
}
};
}
