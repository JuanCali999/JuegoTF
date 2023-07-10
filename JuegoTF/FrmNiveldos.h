#pragma once
#include "ControllerNivelDificil.h"
namespace JuegoTF {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;
	/// <summary>
	/// Summary for FrmNiveldos
	/// </summary>
	public ref class FrmNiveldos : public System::Windows::Forms::Form
	{
	public:
		FrmNiveldos(void)
		{
			srand(time(NULL));
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			g = panel1->CreateGraphics();
			space = BufferedGraphicsManager::Current;
			buffer = space->Allocate(g, panel1->ClientRectangle);
			//bitmap
			bmpHero = gcnew Bitmap("sprites/gold.png");
			bmpMap = gcnew Bitmap("sprites/mundo2.png");
			bmpEnemy = gcnew Bitmap("sprites/enemigoGrande1.png");
			bmpMoney = gcnew Bitmap("sprites/monedas.png");
			bmpAlly = gcnew Bitmap("sprites/a.png");
			bmpBullet = gcnew Bitmap("sprites/fuegoff.png");
			//bmpCambio = gcnew Bitmap("personaje2.png");
			spTheme2 = gcnew SoundPlayer("music.wav");
			//control
			controlN = new ControllerNivelDificil(bmpMap, bmpHero, bmpEnemy);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FrmNiveldos()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ lblDinero2;
	protected:

	private: System::Windows::Forms::Label^ lblText2;
	private: System::Windows::Forms::Label^ lblVidas;
	private: System::Windows::Forms::Label^ lvlText1;
	private: System::Windows::Forms::Timer^ tmrNiveldos;

	private: System::Windows::Forms::Timer^ tmrMoney;
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
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
		ControllerNivelDificil* controlN;
		SoundPlayer^ spTheme2;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->lblDinero2 = (gcnew System::Windows::Forms::Label());
			this->lblText2 = (gcnew System::Windows::Forms::Label());
			this->lblVidas = (gcnew System::Windows::Forms::Label());
			this->lvlText1 = (gcnew System::Windows::Forms::Label());
			this->tmrNiveldos = (gcnew System::Windows::Forms::Timer(this->components));
			this->tmrMoney = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->lblDinero2);
			this->panel1->Controls->Add(this->lblText2);
			this->panel1->Controls->Add(this->lblVidas);
			this->panel1->Controls->Add(this->lvlText1);
			this->panel1->Location = System::Drawing::Point(6, 5);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(566, 889);
			this->panel1->TabIndex = 0;
			// 
			// lblDinero2
			// 
			this->lblDinero2->AutoSize = true;
			this->lblDinero2->Location = System::Drawing::Point(440, 13);
			this->lblDinero2->Name = L"lblDinero2";
			this->lblDinero2->Size = System::Drawing::Size(35, 13);
			this->lblDinero2->TabIndex = 3;
			this->lblDinero2->Text = L"label4";
			// 
			// lblText2
			// 
			this->lblText2->AutoSize = true;
			this->lblText2->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->lblText2->Location = System::Drawing::Point(384, 13);
			this->lblText2->Name = L"lblText2";
			this->lblText2->Size = System::Drawing::Size(41, 13);
			this->lblText2->TabIndex = 2;
			this->lblText2->Text = L"Dinero:";
			// 
			// lblVidas
			// 
			this->lblVidas->AutoSize = true;
			this->lblVidas->Location = System::Drawing::Point(50, 13);
			this->lblVidas->Name = L"lblVidas";
			this->lblVidas->Size = System::Drawing::Size(35, 13);
			this->lblVidas->TabIndex = 1;
			this->lblVidas->Text = L"label2";
			// 
			// lvlText1
			// 
			this->lvlText1->AutoSize = true;
			this->lvlText1->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->lvlText1->Location = System::Drawing::Point(9, 13);
			this->lvlText1->Name = L"lvlText1";
			this->lvlText1->Size = System::Drawing::Size(31, 13);
			this->lvlText1->TabIndex = 0;
			this->lvlText1->Text = L"Vida:";
			// 
			// tmrNiveldos
			// 
			this->tmrNiveldos->Enabled = true;
			this->tmrNiveldos->Tick += gcnew System::EventHandler(this, &FrmNiveldos::tmrNiveldos_Tick);
			// 
			// tmrMoney
			// 
			this->tmrMoney->Enabled = true;
			this->tmrMoney->Interval = 3000;
			this->tmrMoney->Tick += gcnew System::EventHandler(this, &FrmNiveldos::tmrMoney_Tick);
			// 
			// FrmNiveldos
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(566, 889);
			this->Controls->Add(this->panel1);
			this->Name = L"FrmNiveldos";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"FrmNiveldos";
			this->Load += gcnew System::EventHandler(this, &FrmNiveldos::FrmNiveldos_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FrmNiveldos::FrmNiveldos_KeyDown);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void tmrNiveldos_Tick(System::Object^ sender, System::EventArgs^ e) {
		//clear
		buffer->Graphics->Clear(Color::WhiteSmoke);
		//collision
		controlN->collision(buffer->Graphics);
		//mover
		controlN->moveEnemyMoney(buffer->Graphics);
		//Draw
		controlN->draw(buffer->Graphics, bmpMap, bmpHero, bmpEnemy, bmpMoney, bmpAlly, bmpBullet);
		//Render
		buffer->Render(g);
		lblVidas->Text = Convert::ToString(controlN->getHero()->getVida());
		lblDinero2->Text = Convert::ToString(controlN->getContMoney());
		if (controlN->getHero()->getVida() == 0) {
			tmrNiveldos->Enabled = false;
			MessageBox::Show("Perdiste el juego");
		}
		if (controlN->getContMoney() == 30) {
			tmrNiveldos->Enabled = false;
			MessageBox::Show("Ganaste");
		}
		if (controlN->getHero()->getCoin() < -3) {
			tmrNiveldos->Enabled = false;
			MessageBox::Show("Perdiste tu dinero \n Game Over");
			_sleep(4000);
			spTheme2->Stop();
		}
	}
private: System::Void FrmNiveldos_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	switch (e->KeyCode)
	{
	case Keys::A:controlN->getHero()->move(buffer->Graphics, 'A', controlN->getMap());
		break;
	case Keys::D:controlN->getHero()->move(buffer->Graphics, 'D', controlN->getMap());
		break;
	case Keys::W:controlN->getHero()->move(buffer->Graphics, 'W', controlN->getMap());
		break;
	case Keys::S:controlN->getHero()->move(buffer->Graphics, 'S', controlN->getMap());
		break;
	case Keys::P: bmpHero = gcnew Bitmap("personajen2c.png");
		controlN->getHero()->setDxHero(); controlN->getHero()->setDyHero(); controlN->decreasedxEnemy(); controlN->decreasedyEnemy();
		controlN->getHero()->decreaseHp(); controlN->getHero()->decreaceCoinN2(); controlN->setAmountN2(); break;
	case Keys::O: bmpHero = gcnew Bitmap("gold.png"); controlN->getHero()->setInitalidxdyhero(); controlN->setIncreacedxdyenemy(); controlN->setAmountN2I(); break;
	case Keys::M: controlN->addAlly(bmpAlly); break;
	case Keys::Escape: Close();
	case Keys::Space: Bullets* b = new Bullets(controlN->getHero()->getX(), controlN->getHero()->getY(), bmpBullet->Width, bmpBullet->Height, controlN->getHero()->getDirection()); controlN->addBullet(b); break;
	}
}
private: System::Void tmrMoney_Tick(System::Object^ sender, System::EventArgs^ e) {
	if (tmrMoney->Interval == 3000) {
		controlN->addMoney(bmpMoney);
		//control_dificil->addMoney(bmpMoney);
	}
	if (controlN->getsizeMoney() == 20) {
		tmrMoney->Enabled = false;
	}
}
private: System::Void FrmNiveldos_Load(System::Object^ sender, System::EventArgs^ e) {
	spTheme2->Play();
}
};
}