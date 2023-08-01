#pragma once

#include "Myform.h"

namespace Control_Inventario_Implementos {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;


    public ref class Form1 : public System::Windows::Forms::Form
    {
    public:
        Form1(void)
        {
            InitializeComponent();
        }

    protected:
        ~Form1()
        {
            if (components)
            {
                delete components;
            }
        }
    private: System::Windows::Forms::Label^ lbl_Title_Incio;
    private: System::Windows::Forms::Panel^ panel_Img_Inicio;
    protected:



    private: System::Windows::Forms::Button^ btn_Iniciar;
    private: System::Windows::Forms::Button^ btn_Salir;
    private: System::Windows::Forms::PictureBox^ pictureBox1;

    protected:
        bool dragging;
        Point offset;

    protected:

    protected:

    private:
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
            this->lbl_Title_Incio = (gcnew System::Windows::Forms::Label());
            this->panel_Img_Inicio = (gcnew System::Windows::Forms::Panel());
            this->btn_Iniciar = (gcnew System::Windows::Forms::Button());
            this->btn_Salir = (gcnew System::Windows::Forms::Button());
            this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
            this->SuspendLayout();
            // 
            // lbl_Title_Incio
            // 
            this->lbl_Title_Incio->AutoSize = true;
            this->lbl_Title_Incio->BackColor = System::Drawing::Color::Transparent;
            this->lbl_Title_Incio->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->lbl_Title_Incio->ForeColor = System::Drawing::SystemColors::ControlText;
            this->lbl_Title_Incio->Location = System::Drawing::Point(75, 87);
            this->lbl_Title_Incio->Name = L"lbl_Title_Incio";
            this->lbl_Title_Incio->Size = System::Drawing::Size(363, 38);
            this->lbl_Title_Incio->TabIndex = 0;
            this->lbl_Title_Incio->Text = L"Control de Inventario";
            this->lbl_Title_Incio->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // panel_Img_Inicio
            // 
            this->panel_Img_Inicio->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel_Img_Inicio.BackgroundImage")));
            this->panel_Img_Inicio->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
            this->panel_Img_Inicio->Location = System::Drawing::Point(568, 0);
            this->panel_Img_Inicio->Name = L"panel_Img_Inicio";
            this->panel_Img_Inicio->Size = System::Drawing::Size(258, 477);
            this->panel_Img_Inicio->TabIndex = 2;
            // 
            // btn_Iniciar
            // 
            this->btn_Iniciar->BackColor = System::Drawing::SystemColors::WindowFrame;
            this->btn_Iniciar->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btn_Iniciar->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->btn_Iniciar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->btn_Iniciar->ForeColor = System::Drawing::SystemColors::HighlightText;
            this->btn_Iniciar->Location = System::Drawing::Point(103, 343);
            this->btn_Iniciar->Name = L"btn_Iniciar";
            this->btn_Iniciar->Size = System::Drawing::Size(141, 46);
            this->btn_Iniciar->TabIndex = 1;
            this->btn_Iniciar->Text = L"Iniciar";
            this->btn_Iniciar->UseVisualStyleBackColor = false;
            this->btn_Iniciar->Click += gcnew System::EventHandler(this, &Form1::btn_Iniciar_Click);
            // 
            // btn_Salir
            // 
            this->btn_Salir->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btn_Salir->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btn_Salir->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->btn_Salir->Location = System::Drawing::Point(277, 343);
            this->btn_Salir->Name = L"btn_Salir";
            this->btn_Salir->Size = System::Drawing::Size(141, 46);
            this->btn_Salir->TabIndex = 3;
            this->btn_Salir->Text = L"Salir";
            this->btn_Salir->UseVisualStyleBackColor = true;
            this->btn_Salir->Click += gcnew System::EventHandler(this, &Form1::btn_Salir_Click);
            // 
            // pictureBox1
            // 
            this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
            this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
            this->pictureBox1->Location = System::Drawing::Point(153, 128);
            this->pictureBox1->Name = L"pictureBox1";
            this->pictureBox1->Size = System::Drawing::Size(219, 196);
            this->pictureBox1->TabIndex = 4;
            this->pictureBox1->TabStop = false;
            // 
            // Form1
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::SystemColors::ControlLightLight;
            this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
            this->ClientSize = System::Drawing::Size(825, 476);
            this->Controls->Add(this->pictureBox1);
            this->Controls->Add(this->btn_Salir);
            this->Controls->Add(this->lbl_Title_Incio);
            this->Controls->Add(this->panel_Img_Inicio);
            this->Controls->Add(this->btn_Iniciar);
            this->ForeColor = System::Drawing::SystemColors::ControlText;
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
            this->Name = L"Form1";
            this->Text = L"Control de Inventario";
            this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseDown);
            this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseMove);
            this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseUp);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion
    //Funciones
    //Crea la interfaz donde se ve el inventario
    private: System::Void btn_Iniciar_Click(System::Object^ sender, System::EventArgs^ e) {
        MyForm^ formularioCrud = gcnew MyForm();
        this->Visible = false;
        formularioCrud->ShowDialog();
        this->Visible = true;
    }

    //Termina la ejecución de la interfaz
    private: System::Void btn_Salir_Click(System::Object^ sender, System::EventArgs^ e) {
        Application::Exit();
    }

    //Funciones para mover la ventana con el mouse
    private: System::Void Form1_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
        dragging = true;
        offset.X = e->X;
        offset.Y = e->Y;
    }
    private: System::Void Form1_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
        if (dragging) {
            Point currentScreenPosition = PointToScreen(Point(e->X, e->Y));
            Location = Point(currentScreenPosition.X - offset.X, currentScreenPosition.Y - offset.Y);
        }
    }
    private: System::Void Form1_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
        dragging = false;
    }
  };
}
