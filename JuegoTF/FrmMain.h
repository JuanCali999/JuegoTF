#pragma once
#include "Controller.h"
namespace JuegoTF {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;
	/// <summary>
	/// Summary for FrmMain
	/// </summary>
	public ref class FrmMain : public System::Windows::Forms::Form
	{
	public:
		FrmMain(void)
		{
			srand(time(NULL));
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			//buffer
			g = pnlCanvas->CreateGraphics();
			space = BufferedGraphicsManager::Current;
			buffer = space->Allocate(g, pnlCanvas->ClientRectangle);
			//bitmap
			bmpHero = gcnew Bitmap("sprites/gold.png");
			bmpMap = gcnew Bitmap("sprites/mundo1.png");
			bmpEnemy = gcnew Bitmap("sprites/proton.png");
			bmpMoney = gcnew Bitmap("sprites/monedas.png");
			bmpAlly = gcnew Bitmap("sprites/a.png");
			bmpBullet = gcnew Bitmap("sprites/fuegoff.png");
			//bmpCambio = gcnew Bitmap("personaje2.png");
			//sOUNTRACK
			spTheme = gcnew SoundPlayer("musicn1.wav");
			//control
			control = new Controller(bmpMap, bmpHero, bmpEnemy);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FrmMain()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ pnlCanvas;
	private: System::Windows::Forms::Timer^ tmrMain;
	private: System::ComponentModel::IContainer^ components;
	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		//buffer
		Graphics^ g;
		BufferedGraphicsContext^ space;
		BufferedGraphics^ buffer;
		//bitmap
		Bitmap^ bmpHero;		
		Bitmap^ bmpMap;
		Bitmap^ bmpEnemy;
		Bitmap^ bmpMoney;
		Bitmap^ bmpAlly;
		Bitmap^ bmpBullet;
		//Sountrack
		SoundPlayer^ spTheme;

		//Bitmap^ bmpCambio;
	private: System::Windows::Forms::Timer^ tmrMoney;
	private: System::Windows::Forms::Label^ lblDinero;
	private: System::Windows::Forms::Label^ lblTextDinero;
	private: System::Windows::Forms::Label^ lblVidas;
	private: System::Windows::Forms::Label^ lblTextVida;



		   //controller
		Controller* control;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->pnlCanvas = (gcnew System::Windows::Forms::Panel());
			this->lblDinero = (gcnew System::Windows::Forms::Label());
			this->lblTextDinero = (gcnew System::Windows::Forms::Label());
			this->lblVidas = (gcnew System::Windows::Forms::Label());
			this->lblTextVida = (gcnew System::Windows::Forms::Label());
			this->tmrMain = (gcnew System::Windows::Forms::Timer(this->components));
			this->tmrMoney = (gcnew System::Windows::Forms::Timer(this->components));
			this->pnlCanvas->SuspendLayout();
			this->SuspendLayout();
			// 
			// pnlCanvas
			// 
			this->pnlCanvas->Controls->Add(this->lblDinero);
			this->pnlCanvas->Controls->Add(this->lblTextDinero);
			this->pnlCanvas->Controls->Add(this->lblVidas);
			this->pnlCanvas->Controls->Add(this->lblTextVida);
			this->pnlCanvas->Location = System::Drawing::Point(5, 4);
			this->pnlCanvas->Name = L"pnlCanvas";
			this->pnlCanvas->Size = System::Drawing::Size(540, 840);
			this->pnlCanvas->TabIndex = 0;
			// 
			// lblDinero
			// 
			this->lblDinero->AutoSize = true;
			this->lblDinero->Location = System::Drawing::Point(457, 8);
			this->lblDinero->Name = L"lblDinero";
			this->lblDinero->Size = System::Drawing::Size(73, 13);
			this->lblDinero->TabIndex = 3;
			this->lblDinero->Text = L"mostrar dinero";
			// 
			// lblTextDinero
			// 
			this->lblTextDinero->AutoSize = true;
			this->lblTextDinero->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->lblTextDinero->Location = System::Drawing::Point(413, 8);
			this->lblTextDinero->Name = L"lblTextDinero";
			this->lblTextDinero->Size = System::Drawing::Size(38, 13);
			this->lblTextDinero->TabIndex = 2;
			this->lblTextDinero->Text = L"Dinero";
			// 
			// lblVidas
			// 
			this->lblVidas->AutoSize = true;
			this->lblVidas->Location = System::Drawing::Point(47, 8);
			this->lblVidas->Name = L"lblVidas";
			this->lblVidas->Size = System::Drawing::Size(66, 13);
			this->lblVidas->TabIndex = 1;
			this->lblVidas->Text = L"mostar vidas";
			// 
			// lblTextVida
			// 
			this->lblTextVida->AutoSize = true;
			this->lblTextVida->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->lblTextVida->Location = System::Drawing::Point(6, 8);
			this->lblTextVida->Name = L"lblTextVida";
			this->lblTextVida->Size = System::Drawing::Size(39, 13);
			this->lblTextVida->TabIndex = 0;
			this->lblTextVida->Text = L"VIDAS";
			// 
			// tmrMain
			// 
			this->tmrMain->Enabled = true;
			this->tmrMain->Tick += gcnew System::EventHandler(this, &FrmMain::tmrMain_Tick);
			// 
			// tmrMoney
			// 
			this->tmrMoney->Enabled = true;
			this->tmrMoney->Interval = 3000;
			this->tmrMoney->Tick += gcnew System::EventHandler(this, &FrmMain::tmrMoney_Tick);
			// 
			// FrmMain
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(550, 850);
			this->Controls->Add(this->pnlCanvas);
			this->Name = L"FrmMain";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"FrmMain";
			this->Load += gcnew System::EventHandler(this, &FrmMain::FrmMain_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FrmMain::FrmMain_KeyDown);
			this->pnlCanvas->ResumeLayout(false);
			this->pnlCanvas->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void tmrMain_Tick(System::Object^ sender, System::EventArgs^ e) {
		//clear
		buffer->Graphics->Clear(Color::WhiteSmoke);
		//collision
		control->collision(buffer->Graphics);
		//mover
		control->moveEnemyMoney(buffer->Graphics);
		//Draw
		control->draw(buffer->Graphics, bmpMap,bmpHero , bmpEnemy,bmpMoney,bmpAlly,bmpBullet);
		//Render
		buffer->Render(g);
		lblVidas->Text = Convert::ToString(control->getHero()->getVida());
		lblDinero->Text = Convert::ToString(control->getContMoney());
		if (control->getHero()->getVida() == 0) {
			tmrMain->Enabled = false;
			MessageBox::Show("Perdiste el juego");
			_sleep(5000);
			spTheme->Stop();
		}
		if (control->getContMoney() == 20) {
			tmrMain->Enabled = false;
			MessageBox::Show("Ganaste");
			_sleep(5000);
			spTheme->Stop();
		}
		if (control->getHero()->getCoin() < -5) {
			tmrMain->Enabled = false;
			MessageBox::Show("Perdiste tu dinero \n  Game Over...");
			_sleep(5000);
			spTheme->Stop();
		}
	}
	private: System::Void FrmMain_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode)
		{
		case Keys::A:control->getHero()->move(buffer->Graphics, 'A', control->getMap());
			break;
		case Keys::D:control->getHero()->move(buffer->Graphics, 'D', control->getMap());
			break;
		case Keys::W:control->getHero()->move(buffer->Graphics, 'W', control->getMap());
			break;
		case Keys::S:control->getHero()->move(buffer->Graphics, 'S', control->getMap());
			break;
		case Keys::M: control->addAlly(bmpAlly); break;
		case Keys::Escape: Close();
		case Keys::Space: control->addBullet(bmpBullet); break;
		}
	}
private: System::Void tmrMoney_Tick(System::Object^ sender, System::EventArgs^ e) {
	if (tmrMoney->Interval == 3000) {
		control->addMoney(bmpMoney);
		//control_dificil->addMoney(bmpMoney);
	}
	if (control->getsizeMoney() == 20) {
		tmrMoney->Enabled = false;
	}
}
private: System::Void FrmMain_Load(System::Object^ sender, System::EventArgs^ e) {
	//spTheme->Play();
}
};
}
