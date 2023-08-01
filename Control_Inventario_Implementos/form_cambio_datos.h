#pragma once

namespace Control_Inventario_Implementos {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	public ref class form_cambio_datos : public System::Windows::Forms::Form
	{
	public:
		form_cambio_datos(void)
		{
			InitializeComponent();
		}

		form_cambio_datos(String^ id, String^ nombre, String^ tipo, String^ cantidad, String^ Proveedor, String^ Modelo, bool write)
		{
			InitializeComponent();
			this->textBox_id->Text = id;
			this->textBox_nombre->Text = nombre;
			this->textBox_tipo->Text = tipo;
			this->textBox_cantidad->Text = cantidad;
			this->textBox_proveedor->Text = Proveedor;
			this->textBox_modelo->Text = Modelo;
			bloquearEntradas(write);
		}

	protected:

		~form_cambio_datos()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ lbl_id;
	private: System::Windows::Forms::Label^ lbl_nombre;
	private: System::Windows::Forms::Label^ lbl_principal;
	private: System::Windows::Forms::Label^ lbl_cantidad;
	private: System::Windows::Forms::Label^ lbl_tipo;
	private: System::Windows::Forms::Label^ lbl_proveedor;
	private: System::Windows::Forms::Label^ lbl_modelo;
	private: System::Windows::Forms::Button^ btn_aceptar;
	private: System::Windows::Forms::Button^ btn_regresar;
	private: System::Windows::Forms::TextBox^ textBox_id;
	private: System::Windows::Forms::TextBox^ textBox_nombre;
	private: System::Windows::Forms::TextBox^ textBox_tipo;
	private: System::Windows::Forms::TextBox^ textBox_cantidad;
	private: System::Windows::Forms::TextBox^ textBox_proveedor;
	private: System::Windows::Forms::TextBox^ textBox_modelo;

	protected:
		bool dragging;
		Point offset;

	private:
		String^ id_selected;
		String^ nombre_selected;
		String^ tipo_selected;
		String^ cantidad_selected;
		String^ Proveedor_selected;
		String^ Modelo_selected;
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->lbl_principal = (gcnew System::Windows::Forms::Label());
			this->lbl_id = (gcnew System::Windows::Forms::Label());
			this->lbl_nombre = (gcnew System::Windows::Forms::Label());
			this->lbl_cantidad = (gcnew System::Windows::Forms::Label());
			this->lbl_tipo = (gcnew System::Windows::Forms::Label());
			this->lbl_proveedor = (gcnew System::Windows::Forms::Label());
			this->lbl_modelo = (gcnew System::Windows::Forms::Label());
			this->btn_aceptar = (gcnew System::Windows::Forms::Button());
			this->btn_regresar = (gcnew System::Windows::Forms::Button());
			this->textBox_id = (gcnew System::Windows::Forms::TextBox());
			this->textBox_nombre = (gcnew System::Windows::Forms::TextBox());
			this->textBox_tipo = (gcnew System::Windows::Forms::TextBox());
			this->textBox_cantidad = (gcnew System::Windows::Forms::TextBox());
			this->textBox_proveedor = (gcnew System::Windows::Forms::TextBox());
			this->textBox_modelo = (gcnew System::Windows::Forms::TextBox());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::LightSeaGreen;
			this->panel1->Controls->Add(this->lbl_principal);
			this->panel1->Location = System::Drawing::Point(-1, -1);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(601, 57);
			this->panel1->TabIndex = 0;
			// 
			// lbl_principal
			// 
			this->lbl_principal->AutoSize = true;
			this->lbl_principal->BackColor = System::Drawing::Color::LightSeaGreen;
			this->lbl_principal->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_principal->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->lbl_principal->Location = System::Drawing::Point(14, 14);
			this->lbl_principal->Name = L"lbl_principal";
			this->lbl_principal->Size = System::Drawing::Size(140, 29);
			this->lbl_principal->TabIndex = 0;
			this->lbl_principal->Text = L"Implemento";
			// 
			// lbl_id
			// 
			this->lbl_id->AutoSize = true;
			this->lbl_id->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_id->Location = System::Drawing::Point(13, 82);
			this->lbl_id->Name = L"lbl_id";
			this->lbl_id->Size = System::Drawing::Size(29, 25);
			this->lbl_id->TabIndex = 1;
			this->lbl_id->Text = L"Id";
			// 
			// lbl_nombre
			// 
			this->lbl_nombre->AutoSize = true;
			this->lbl_nombre->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_nombre->Location = System::Drawing::Point(13, 125);
			this->lbl_nombre->Name = L"lbl_nombre";
			this->lbl_nombre->Size = System::Drawing::Size(87, 25);
			this->lbl_nombre->TabIndex = 2;
			this->lbl_nombre->Text = L"Nombre";
			// 
			// lbl_cantidad
			// 
			this->lbl_cantidad->AutoSize = true;
			this->lbl_cantidad->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_cantidad->Location = System::Drawing::Point(13, 212);
			this->lbl_cantidad->Name = L"lbl_cantidad";
			this->lbl_cantidad->Size = System::Drawing::Size(98, 25);
			this->lbl_cantidad->TabIndex = 3;
			this->lbl_cantidad->Text = L"Cantidad";
			// 
			// lbl_tipo
			// 
			this->lbl_tipo->AutoSize = true;
			this->lbl_tipo->Cursor = System::Windows::Forms::Cursors::Default;
			this->lbl_tipo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_tipo->Location = System::Drawing::Point(13, 169);
			this->lbl_tipo->Name = L"lbl_tipo";
			this->lbl_tipo->Size = System::Drawing::Size(54, 25);
			this->lbl_tipo->TabIndex = 4;
			this->lbl_tipo->Text = L"Tipo";
			// 
			// lbl_proveedor
			// 
			this->lbl_proveedor->AutoSize = true;
			this->lbl_proveedor->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_proveedor->Location = System::Drawing::Point(13, 255);
			this->lbl_proveedor->Name = L"lbl_proveedor";
			this->lbl_proveedor->Size = System::Drawing::Size(111, 25);
			this->lbl_proveedor->TabIndex = 5;
			this->lbl_proveedor->Text = L"Proveedor";
			// 
			// lbl_modelo
			// 
			this->lbl_modelo->AutoSize = true;
			this->lbl_modelo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_modelo->Location = System::Drawing::Point(12, 299);
			this->lbl_modelo->Name = L"lbl_modelo";
			this->lbl_modelo->Size = System::Drawing::Size(83, 25);
			this->lbl_modelo->TabIndex = 6;
			this->lbl_modelo->Text = L"Modelo";
			// 
			// btn_aceptar
			// 
			this->btn_aceptar->BackColor = System::Drawing::Color::MediumSeaGreen;
			this->btn_aceptar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_aceptar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_aceptar->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->btn_aceptar->Location = System::Drawing::Point(146, 366);
			this->btn_aceptar->Name = L"btn_aceptar";
			this->btn_aceptar->Size = System::Drawing::Size(142, 41);
			this->btn_aceptar->TabIndex = 7;
			this->btn_aceptar->Text = L"Aceptar";
			this->btn_aceptar->UseVisualStyleBackColor = false;
			this->btn_aceptar->Click += gcnew System::EventHandler(this, &form_cambio_datos::btn_aceptar_Click);
			// 
			// btn_regresar
			// 
			this->btn_regresar->BackColor = System::Drawing::Color::Firebrick;
			this->btn_regresar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_regresar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_regresar->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->btn_regresar->Location = System::Drawing::Point(294, 366);
			this->btn_regresar->Name = L"btn_regresar";
			this->btn_regresar->Size = System::Drawing::Size(142, 41);
			this->btn_regresar->TabIndex = 8;
			this->btn_regresar->Text = L"Regresar";
			this->btn_regresar->UseVisualStyleBackColor = false;
			this->btn_regresar->Click += gcnew System::EventHandler(this, &form_cambio_datos::btn_regresar_Click);
			// 
			// textBox_id
			// 
			this->textBox_id->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox_id->Location = System::Drawing::Point(135, 81);
			this->textBox_id->Name = L"textBox_id";
			this->textBox_id->Size = System::Drawing::Size(118, 26);
			this->textBox_id->TabIndex = 9;
			// 
			// textBox_nombre
			// 
			this->textBox_nombre->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox_nombre->Location = System::Drawing::Point(135, 124);
			this->textBox_nombre->Name = L"textBox_nombre";
			this->textBox_nombre->Size = System::Drawing::Size(355, 26);
			this->textBox_nombre->TabIndex = 10;
			// 
			// textBox_tipo
			// 
			this->textBox_tipo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox_tipo->Location = System::Drawing::Point(135, 168);
			this->textBox_tipo->Name = L"textBox_tipo";
			this->textBox_tipo->Size = System::Drawing::Size(355, 26);
			this->textBox_tipo->TabIndex = 11;
			// 
			// textBox_cantidad
			// 
			this->textBox_cantidad->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox_cantidad->Location = System::Drawing::Point(135, 213);
			this->textBox_cantidad->Name = L"textBox_cantidad";
			this->textBox_cantidad->Size = System::Drawing::Size(118, 26);
			this->textBox_cantidad->TabIndex = 12;
			// 
			// textBox_proveedor
			// 
			this->textBox_proveedor->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox_proveedor->Location = System::Drawing::Point(135, 254);
			this->textBox_proveedor->Name = L"textBox_proveedor";
			this->textBox_proveedor->Size = System::Drawing::Size(355, 26);
			this->textBox_proveedor->TabIndex = 13;
			// 
			// textBox_modelo
			// 
			this->textBox_modelo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox_modelo->Location = System::Drawing::Point(135, 298);
			this->textBox_modelo->Name = L"textBox_modelo";
			this->textBox_modelo->Size = System::Drawing::Size(355, 26);
			this->textBox_modelo->TabIndex = 14;
			// 
			// form_cambio_datos
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->ClientSize = System::Drawing::Size(598, 445);
			this->Controls->Add(this->textBox_modelo);
			this->Controls->Add(this->textBox_proveedor);
			this->Controls->Add(this->textBox_cantidad);
			this->Controls->Add(this->textBox_tipo);
			this->Controls->Add(this->textBox_nombre);
			this->Controls->Add(this->textBox_id);
			this->Controls->Add(this->btn_regresar);
			this->Controls->Add(this->btn_aceptar);
			this->Controls->Add(this->lbl_modelo);
			this->Controls->Add(this->lbl_proveedor);
			this->Controls->Add(this->lbl_tipo);
			this->Controls->Add(this->lbl_cantidad);
			this->Controls->Add(this->lbl_nombre);
			this->Controls->Add(this->lbl_id);
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"form_cambio_datos";
			this->Text = L"form_cambio_datos";
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &form_cambio_datos::form_cambio_datos_MouseDown);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &form_cambio_datos::form_cambio_datos_MouseMove);
			this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &form_cambio_datos::form_cambio_datos_MouseUp);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	//Capturamos los datos ingresados si se apreta aceptar
	//Los capturo todos com String, dependiendo de cada dato se castea
	//En esta funcion se deberia agregar o modificar los archivos con los datos antes de que cierre la ventana
	private: System::Void btn_aceptar_Click(System::Object^ sender, System::EventArgs^ e) {
		id_selected = this->textBox_id->Text;
		nombre_selected = this->textBox_nombre->Text;
		tipo_selected = this->textBox_tipo->Text;
		cantidad_selected = this->textBox_cantidad->Text;
		Proveedor_selected = this->textBox_proveedor->Text;
		Modelo_selected = this->textBox_modelo->Text;


		this->Close();
	}

	//Cierra la ventana y vuelve a la anterior
	private: System::Void btn_regresar_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}

	//Funcion para bloquear las entradas de texto si solo se creo para leer
	private: Void bloquearEntradas(bool write){
		if (write) {
			textBox_id->Enabled = false;
			textBox_nombre->Enabled = false;
			textBox_tipo->Enabled = false;
			textBox_cantidad->Enabled = false;
			textBox_proveedor->Enabled = false;
			textBox_modelo->Enabled = false;
			btn_aceptar->Enabled = false;
		}
	}



	//Getters por si se necesitan en otra clase
	public:
		String^ GetIdSelected() {
			return this->id_selected;
		}

		String^ GetNombreSelected() {
			return this->nombre_selected;
		}

		String^ GetTipoSelected() {
			return this->tipo_selected;
		}

		String^ GetCantidadSelected() {
			return this->cantidad_selected;
		}

		String^ GetProveedorSelected() {
			return this->Proveedor_selected;
		}

		String^ GetModeloSelected() {
			return this->Modelo_selected;
		}
	//Funciones para mover la ventana con el mouse
	private: System::Void form_cambio_datos_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		dragging = true;
		offset.X = e->X;
		offset.Y = e->Y;
	}
	private: System::Void form_cambio_datos_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (dragging) {
			Point currentScreenPosition = PointToScreen(Point(e->X, e->Y));
			Location = Point(currentScreenPosition.X - offset.X, currentScreenPosition.Y - offset.Y);
		}
	}
	private: System::Void form_cambio_datos_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		dragging = false;
	}
};
}
