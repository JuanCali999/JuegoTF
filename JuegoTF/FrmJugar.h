#pragma once
#include"FrmJugar.h"
#include"FrmMain.h"
#include"FrmNiveldos.h"
namespace JuegoTF {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for FrmJugar
	/// </summary>
	public ref class FrmJugar : public System::Windows::Forms::Form
	{
	public:
		FrmJugar(void)
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
		~FrmJugar()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnNivel1;
	protected:
	private: System::Windows::Forms::Button^ btnNivel2;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FrmJugar::typeid));
			this->btnNivel1 = (gcnew System::Windows::Forms::Button());
			this->btnNivel2 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// btnNivel1
			// 
			this->btnNivel1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnNivel1->Font = (gcnew System::Drawing::Font(L"Stencil", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnNivel1->ForeColor = System::Drawing::SystemColors::ControlText;
			this->btnNivel1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnNivel1.Image")));
			this->btnNivel1->Location = System::Drawing::Point(189, 139);
			this->btnNivel1->Name = L"btnNivel1";
			this->btnNivel1->Size = System::Drawing::Size(178, 109);
			this->btnNivel1->TabIndex = 0;
			this->btnNivel1->Text = L"Nivel 1";
			this->btnNivel1->UseVisualStyleBackColor = true;
			this->btnNivel1->Click += gcnew System::EventHandler(this, &FrmJugar::btnNivel1_Click);
			// 
			// btnNivel2
			// 
			this->btnNivel2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->btnNivel2->Font = (gcnew System::Drawing::Font(L"Stencil", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnNivel2->ForeColor = System::Drawing::Color::Gold;
			this->btnNivel2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnNivel2.Image")));
			this->btnNivel2->Location = System::Drawing::Point(189, 398);
			this->btnNivel2->Name = L"btnNivel2";
			this->btnNivel2->Size = System::Drawing::Size(178, 109);
			this->btnNivel2->TabIndex = 1;
			this->btnNivel2->Text = L"Nivel 2";
			this->btnNivel2->UseVisualStyleBackColor = true;
			this->btnNivel2->Click += gcnew System::EventHandler(this, &FrmJugar::btnNivel2_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(-2, 254);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(548, 259);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 2;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(-1, 0);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(546, 264);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox2->TabIndex = 3;
			this->pictureBox2->TabStop = false;
			// 
			// FrmJugar
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(545, 512);
			this->Controls->Add(this->btnNivel2);
			this->Controls->Add(this->btnNivel1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->pictureBox2);
			this->Name = L"FrmJugar";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"FrmJugar";
			this->Load += gcnew System::EventHandler(this, &FrmJugar::FrmJugar_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void FrmJugar_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void btnNivel1_Click(System::Object^ sender, System::EventArgs^ e) {
		FrmMain^ frmNivel1 = gcnew FrmMain();
		this->Visible = false;
		frmNivel1->ShowDialog();
		this->Visible = true;
	}
	private: System::Void btnNivel2_Click(System::Object^ sender, System::EventArgs^ e) {
		FrmNiveldos^ frmNiveles2 = gcnew FrmNiveldos();
		this->Visible = false;
		frmNiveles2->ShowDialog();
		this->Visible = true;
	}
	};
}
