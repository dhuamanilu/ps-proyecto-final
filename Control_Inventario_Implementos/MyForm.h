#pragma once
#include <iostream>
#include "form_cambio_datos.h"
#include "inventario.h"
#include <fstream>
#include <sstream>
#include <filesystem>
#include <chrono>
#include <vector>
#include <iostream>
#include <cstdlib>

//#include <windows.h>
//#include <pdh.h>
//#include <pdhmsg.h>


#using <mscorlib.dll>
using namespace System;
using namespace System::Collections::Generic;

namespace Control_Inventario_Implementos {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//inventario = new Inventario();
			
		}

	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ pnl_header;
	private: System::Windows::Forms::Label^ lbl_header;
	private: System::Windows::Forms::Button^ btn_Crear;
	private: System::Windows::Forms::Button^ btn_Salir;
	private: System::Windows::Forms::Label^ lbl_lista;
	private : std::string convertirSystemStringAStdString(System::String^ str)
	{
		array<Byte>^ byteArray = System::Text::Encoding::UTF8->GetBytes(str);
		pin_ptr<Byte> pinnedData = &byteArray[0];
		return std::string(reinterpret_cast<char*>(pinnedData), byteArray->Length);
	}
	protected:
		// Vector para almacenar los valores de tiempo de CPU y uso de memoria
		List<KeyValuePair<int, long>>^ cpu_values; // Pair de (tiempo, valor)
		List<KeyValuePair<int, unsigned long>>^ memory_values; // Pair de (tiempo, valor)
		int indiceVector = 0;
		int indiceMemoria = 0;
		bool dragging;
		Point offset;
		String^ id_selected;
		String^ nombre_selected;
		String^ tipo_selected;
		String^ cantidad_selected;
		String^ Proveedor_selected;
		String^ Modelo_selected;


	private: System::Windows::Forms::DataGridView^ grilla_Datos;
	private: System::Windows::Forms::Button^ btn_leer;
	private: System::Windows::Forms::Button^ btn_modificar;

	private: System::Windows::Forms::Button^ btn_borrar;
	private: System::Windows::Forms::Label^ lbl_seleccionado;

	protected:

	protected:

	protected:

	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			// Inicializar las listas
			cpu_values = gcnew List<KeyValuePair<int, long >>();
			memory_values = gcnew List<KeyValuePair<int, unsigned long>>();
			indiceVector = 0; // Inicializar el índice en 0
			indiceMemoria = 0; // Inicializar el índice en 0
			this->pnl_header = (gcnew System::Windows::Forms::Panel());
			this->lbl_header = (gcnew System::Windows::Forms::Label());
			this->btn_Crear = (gcnew System::Windows::Forms::Button());
			this->btn_Salir = (gcnew System::Windows::Forms::Button());
			this->lbl_lista = (gcnew System::Windows::Forms::Label());
			this->grilla_Datos = (gcnew System::Windows::Forms::DataGridView());
			this->btn_leer = (gcnew System::Windows::Forms::Button());
			this->btn_modificar = (gcnew System::Windows::Forms::Button());
			this->btn_borrar = (gcnew System::Windows::Forms::Button());
			this->lbl_seleccionado = (gcnew System::Windows::Forms::Label());
			this->pnl_header->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->grilla_Datos))->BeginInit();
			this->SuspendLayout();
			// 
			// pnl_header
			// 
			this->pnl_header->BackColor = System::Drawing::SystemColors::Highlight;
			this->pnl_header->Controls->Add(this->lbl_header);
			this->pnl_header->Location = System::Drawing::Point(-1, -1);
			this->pnl_header->Name = L"pnl_header";
			this->pnl_header->Size = System::Drawing::Size(785, 109);
			this->pnl_header->TabIndex = 0;
			// 
			// lbl_header
			// 
			this->lbl_header->AutoSize = true;
			this->lbl_header->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_header->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->lbl_header->Location = System::Drawing::Point(13, 31);
			this->lbl_header->Name = L"lbl_header";
			this->lbl_header->Size = System::Drawing::Size(441, 50);
			this->lbl_header->TabIndex = 0;
			this->lbl_header->Text = L"Implementos de Mina";
			// 
			// btn_Crear
			// 
			this->btn_Crear->BackColor = System::Drawing::Color::Transparent;
			this->btn_Crear->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_Crear->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_Crear->Location = System::Drawing::Point(21, 129);
			this->btn_Crear->Name = L"btn_Crear";
			this->btn_Crear->Size = System::Drawing::Size(136, 43);
			this->btn_Crear->TabIndex = 1;
			this->btn_Crear->Text = L"Agregar";
			this->btn_Crear->UseVisualStyleBackColor = false;
			this->btn_Crear->Click += gcnew System::EventHandler(this, &MyForm::btn_Crear_Click);
			// 
			// btn_Salir
			// 
			this->btn_Salir->BackColor = System::Drawing::Color::Transparent;
			this->btn_Salir->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_Salir->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_Salir->ForeColor = System::Drawing::Color::Black;
			this->btn_Salir->Location = System::Drawing::Point(163, 129);
			this->btn_Salir->Name = L"btn_Salir";
			this->btn_Salir->Size = System::Drawing::Size(136, 43);
			this->btn_Salir->TabIndex = 2;
			this->btn_Salir->Text = L"Salir";
			this->btn_Salir->UseVisualStyleBackColor = false;
			this->btn_Salir->Click += gcnew System::EventHandler(this, &MyForm::btn_Salir_Click);
			// 
			// lbl_lista
			// 
			this->lbl_lista->AutoSize = true;
			this->lbl_lista->BackColor = System::Drawing::Color::Transparent;
			this->lbl_lista->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lbl_lista->Location = System::Drawing::Point(15, 191);
			this->lbl_lista->Name = L"lbl_lista";
			this->lbl_lista->Size = System::Drawing::Size(180, 31);
			this->lbl_lista->TabIndex = 3;
			this->lbl_lista->Text = L"Implementos";
			// 
			// grilla_Datos
			// 
			this->grilla_Datos->BackgroundColor = System::Drawing::SystemColors::ControlLightLight;
			this->grilla_Datos->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->grilla_Datos->Location = System::Drawing::Point(65, 247);
			this->grilla_Datos->Name = L"grilla_Datos";
			this->grilla_Datos->RowHeadersWidth = 100;
			this->grilla_Datos->Size = System::Drawing::Size(656, 261);
			this->grilla_Datos->TabIndex = 4;
			this->grilla_Datos->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::grilla_Datos_CellClick);
			// 
			// btn_leer
			// 
			this->btn_leer->BackColor = System::Drawing::Color::ForestGreen;
			this->btn_leer->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_leer->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_leer->ForeColor = System::Drawing::Color::Transparent;
			this->btn_leer->Location = System::Drawing::Point(133, 549);
			this->btn_leer->Name = L"btn_leer";
			this->btn_leer->Size = System::Drawing::Size(159, 41);
			this->btn_leer->TabIndex = 5;
			this->btn_leer->Text = L"Leer";
			this->btn_leer->UseVisualStyleBackColor = false;
			this->btn_leer->Click += gcnew System::EventHandler(this, &MyForm::btn_leer_Click);
			// 
			// btn_modificar
			// 
			this->btn_modificar->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->btn_modificar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_modificar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_modificar->ForeColor = System::Drawing::Color::Transparent;
			this->btn_modificar->Location = System::Drawing::Point(308, 549);
			this->btn_modificar->Name = L"btn_modificar";
			this->btn_modificar->Size = System::Drawing::Size(159, 41);
			this->btn_modificar->TabIndex = 6;
			this->btn_modificar->Text = L"Modificar";
			this->btn_modificar->UseVisualStyleBackColor = false;
			this->btn_modificar->Click += gcnew System::EventHandler(this, &MyForm::btn_modificar_Click);
			// 
			// btn_borrar
			// 
			this->btn_borrar->BackColor = System::Drawing::Color::Firebrick;
			this->btn_borrar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_borrar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_borrar->ForeColor = System::Drawing::Color::Transparent;
			this->btn_borrar->Location = System::Drawing::Point(482, 549);
			this->btn_borrar->Name = L"btn_borrar";
			this->btn_borrar->Size = System::Drawing::Size(159, 41);
			this->btn_borrar->TabIndex = 7;
			this->btn_borrar->Text = L"Borrar";
			this->btn_borrar->UseVisualStyleBackColor = false;
			this->btn_borrar->Click += gcnew System::EventHandler(this, &MyForm::btn_borrar_Click);
			// 
			// lbl_seleccionado
			// 
			this->lbl_seleccionado->AutoSize = true;
			this->lbl_seleccionado->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lbl_seleccionado->Location = System::Drawing::Point(299, 197);
			this->lbl_seleccionado->Name = L"lbl_seleccionado";
			this->lbl_seleccionado->Size = System::Drawing::Size(154, 25);
			this->lbl_seleccionado->TabIndex = 8;
			this->lbl_seleccionado->Text = L"Seleccionado: ";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->ClientSize = System::Drawing::Size(784, 689);
			this->Controls->Add(this->lbl_seleccionado);
			this->Controls->Add(this->btn_borrar);
			this->Controls->Add(this->btn_modificar);
			this->Controls->Add(this->btn_leer);
			this->Controls->Add(this->grilla_Datos);
			this->Controls->Add(this->lbl_lista);
			this->Controls->Add(this->btn_Salir);
			this->Controls->Add(this->btn_Crear);
			this->Controls->Add(this->pnl_header);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseDown);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseMove);
			this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseUp);
			this->pnl_header->ResumeLayout(false);
			this->pnl_header->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->grilla_Datos))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	//Funciones para mover la ventana con el mouse
	private: System::Void MyForm_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		dragging = true;
		offset.X = e->X;
		offset.Y = e->Y;
	}

	private: System::Void MyForm_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (dragging) {
			Point currentScreenPosition = PointToScreen(Point(e->X, e->Y));
			Location = Point(currentScreenPosition.X - offset.X, currentScreenPosition.Y - offset.Y);
		}
	}
	private: System::Void MyForm_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		dragging = false;
	}
	private :
		// Función para guardar un implemento en el archivo CSV correspondiente
		void GuardarImplementoEnArchivo(int idArchivo, const Implemento& implemento)
		{
			// Crear la ruta completa al archivo CSV correspondiente
			std::string rutaArchivo = "archivos/archivo_" + std::to_string(idArchivo) + ".csv";


			// Abrir el archivo en modo de escritura
			std::ofstream archivo(rutaArchivo, std::ios::out); // std::ios::app para agregar al final del archivo

			if (!archivo.is_open())
			{
				// Manejar el caso en el que el archivo no se pueda abrir
				// Por ejemplo, lanzar una excepción o mostrar un mensaje de error
				return;
			}

			// Escribir el nuevo implemento en el archivo, separando los campos con comas
			archivo << implemento.getID() << ','
				<< implemento.getNombre() << ','
				<< implemento.getTipo() << ','
				<< implemento.getCantidad() << ','
				<< implemento.getProveedor() << ','
				<< implemento.getModelo() << '\n';

			// Cerrar el archivo
			archivo.close();
		}
		// Declaración de la función para leer un implemento desde el archivo CSV
		Implemento LeerImplementoDesdeArchivo(int idArchivo){
			Implemento implemento;

			// Crear la ruta completa al archivo CSV correspondiente
			std::string rutaArchivo = "archivos/archivo_" + std::to_string(idArchivo) + ".csv";

			// Abrir el archivo CSV
			std::ifstream archivo(rutaArchivo);
			
			if (!archivo.is_open()) {
				// Manejar el caso en el que el archivo no se pueda abrir
				// Por ejemplo, lanzar una excepción o retornar un implemento vacío
				implemento.setID(-1);
				return implemento;
			}
			
			// Leer una línea del archivo
			std::string linea;
			if (std::getline(archivo, linea)) {
				// Procesar la línea para obtener los campos separados por comas
				std::stringstream ss(linea);
				std::vector<std::string> campos;
				std::string campo;
				while (std::getline(ss, campo, ',')) {
					campos.push_back(campo);
				}

				// Verificar que la línea contenga la cantidad esperada de campos
				if (campos.size() == 6) {
					// Asignar los valores a los miembros del implemento
					implemento.setID(std::stoi(campos[0]));
					implemento.setNombre(campos[1]);
					implemento.setTipo(campos[2]);
					implemento.setCantidad(std::stoi(campos[3]));
					implemento.setProveedor(campos[4]);
					implemento.setModelo(campos[5]);
				}
			}
			archivo.close();

			return implemento;
		}


	private: Inventario ObtenerInventario() {
		Inventario inventario;
		std::string carpetaArchivos = "archivos/";

		for (const auto& archivo : std::filesystem::directory_iterator(carpetaArchivos)) {
			std::string nombreArchivo = archivo.path().filename().string();
			if (nombreArchivo.find("archivo_") == 0 && nombreArchivo.find(".csv") == nombreArchivo.length() - 4) {
				int idArchivo = std::stoi(nombreArchivo.substr(8, nombreArchivo.length() - 12));
				Implemento implemento = LeerImplementoDesdeArchivo(idArchivo);
				if (implemento.getID() != -1) {
					inventario.agregarImplemento(implemento);
				}
			}
		}
		return inventario;
	}
	private: void ActualizarGrilla() {
		Inventario inventario = ObtenerInventario();
		this->Consulta(inventario);
	}
	//Estructura como ejemplo de como para enviar datos a la grilla, lo cambian segun como envien los datos
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		ActualizarGrilla();
	}

	//Llenar la grilla de la ventana
	public: void Consulta(Inventario inventario) {
		DataTable^ dataTable = gcnew DataTable("Datos");
		dataTable->Columns->Add("ID", Int32::typeid);
		dataTable->Columns->Add("Nombre", String::typeid);
		dataTable->Columns->Add("Tipo", String::typeid);
		dataTable->Columns->Add("Cantidad", Int32::typeid);
		dataTable->Columns->Add("Proveedor", String::typeid);
		dataTable->Columns->Add("Modelo", String::typeid);
		
		std::vector<Implemento>& listaImplementos = inventario.obtenerListaImplementos();
		//Bucle para recorrer los datos
		for (const auto & implemento :listaImplementos){
			DataRow^ fila = dataTable->NewRow();
			fila["ID"] = implemento.getID();
			fila["Nombre"] = gcnew String(implemento.getNombre().c_str());
			fila["Tipo"] = gcnew String(implemento.getTipo().c_str());
			fila["Cantidad"] = implemento.getCantidad();
			fila["Proveedor"] = gcnew String(implemento.getProveedor().c_str());
			fila["Modelo"] = gcnew String(implemento.getModelo().c_str());
			dataTable->Rows->Add(fila);
		}

		this->grilla_Datos->DataSource = dataTable;
	}
	
	//Crea la ventana para llenar datos
	private: System::Void btn_Crear_Click(System::Object^ sender, System::EventArgs^ e) {
		auto start = std::chrono::high_resolution_clock::now(); //medir tiempo cpu inicio
		
		
		form_cambio_datos^ formularioCrud = gcnew form_cambio_datos();
		this->Visible = false;
		formularioCrud->ShowDialog();
		this->Visible = true;
		

		// Obtener los datos ingresados en el formulario de creación
		int nuevoID = System::Convert::ToInt32(formularioCrud->ID);
		std::string nuevoNombre = convertirSystemStringAStdString(formularioCrud->Nombre);
		std::string nuevoTipo = convertirSystemStringAStdString(formularioCrud->Tipo);
		int nuevaCantidad = System::Convert::ToInt32(formularioCrud->Cantidad);
		std::string nuevoProveedor = convertirSystemStringAStdString(formularioCrud->Proveedor);
		std::string nuevoModelo = convertirSystemStringAStdString(formularioCrud->Modelo);

		

		// Crear el nuevo implemento
		Implemento nuevoImplemento;
		nuevoImplemento.setID(nuevoID);
		nuevoImplemento.setNombre(nuevoNombre);
		nuevoImplemento.setTipo(nuevoTipo);
		nuevoImplemento.setCantidad(nuevaCantidad);
		nuevoImplemento.setProveedor(nuevoProveedor);
		nuevoImplemento.setModelo(nuevoModelo);

		// Guardar el nuevo implemento en el archivo CSV
		GuardarImplementoEnArchivo(nuevoID, nuevoImplemento);

		// Actualizar la grilla
		ActualizarGrilla();
		auto end = std::chrono::high_resolution_clock::now(); //medir tiempo final cpu
        long tiempoCPU = std::chrono::duration_cast<std::chrono::microseconds>
			(end - start).count(); //medir tiempo resultado cpu
		// Guardar el tiempo de CPU en el vector cpu_values
        cpu_values->Add(KeyValuePair<int, long>(indiceVector, tiempoCPU));
		indiceVector++;
		// Obtener el uso de memoria en kilobytes
    	unsigned long usoMemoria = obtenerUsoMemoria() / 1024;
    	// Agregar los valores al vector
    	memory_values->Add(KeyValuePair<int, unsigned long>(indiceMemoria, usoMemoria));
    	indiceMemoria++;
	}

	private: System::Void btn_Salir_Click(System::Object^ sender, System::EventArgs^ e) {
		// Guardar los datos del vector cpu_values en un archivo de texto
		GuardarDatosEnArchivoCPU("cpu.txt");
		GuardarDatosEnArchivoMemoria("memory.txt");

		std::ofstream file("imprimir.gnu");
		if (file.is_open()) {
			file<<"plot \"cpu.txt\" using 1:2 with linespoints title \'Tiempo de CPU utilizado\'"<<std::endl;
			file.close();
		}
		std::ofstream file2("imprimir2.gnu");
		if (file2.is_open()) {
			file2 << "plot \"memory.txt\" using 1:2 with linespoints title \'Uso de memoria\'" << std::endl;
			file2.close();
		}
		// llama a gnuplot para que grafique la CPU
		int statusCpu = system("gnuplot -persist imprimir.gnu");

		// llama a gnuplot para que grafique la memoria
		int statusMemory = system("gnuplot -persist imprimir2.gnu");

		// Cerrar la ventana después de generar las gráficas
		this->Close();
	}


	//Crea la ventana del formulario crud para leer sin los campos habilitados
	private: System::Void btn_leer_Click(System::Object^ sender, System::EventArgs^ e) {
		auto start = std::chrono::high_resolution_clock::now(); //medir tiempo cpu inicio
		if (id_selected) {
			form_cambio_datos^ formularioCrud = gcnew form_cambio_datos(
				id_selected,nombre_selected,tipo_selected,cantidad_selected,
				Proveedor_selected,Modelo_selected,true);
			this->Visible = false;
			formularioCrud->ShowDialog();
			//Consulta(datos) la vuelven a llamar para que se actualize la grilla
			this->Visible = true;
			ActualizarGrilla();
		}
		auto end = std::chrono::high_resolution_clock::now(); //medir tiempo final cpu
        	long tiempoCPU = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count(); //medir tiempo resultado cpu
		// Guardar el tiempo de CPU en el vector cpu_values
        	cpu_values->Add(KeyValuePair<int, long>(indiceVector, tiempoCPU));
		indiceVector++;
		// Obtener el uso de memoria en kilobytes
    		unsigned long usoMemoria = obtenerUsoMemoria() / 1024;
    		// Agregar los valores al vector
    		memory_values->Add(KeyValuePair<int, unsigned long>(indiceMemoria, usoMemoria));
    		indiceMemoria++;
	}

	//Crea la ventana del formulario crud para modificar con los campos habilitados
	private: System::Void btn_modificar_Click(System::Object^ sender, System::EventArgs^ e) {
		auto start = std::chrono::high_resolution_clock::now(); //medir tiempo inicio cpu
		if (id_selected) {
			form_cambio_datos^ formularioCrud = gcnew form_cambio_datos(
				id_selected, nombre_selected, tipo_selected, cantidad_selected, 
				Proveedor_selected, Modelo_selected,false);
			this->Visible = false;
			formularioCrud->ShowDialog();
			//Consulta(datos) la vuelven a llamar para que se actualize la grilla
			this->Visible = true;
			
			// Obtener los datos actualizados del formulario de modificación
			int nuevoID = System::Convert::ToInt32(formularioCrud->ID);
			std::string nuevoNombre = convertirSystemStringAStdString(formularioCrud->Nombre);
			std::string nuevoTipo = convertirSystemStringAStdString(formularioCrud->Tipo);
			int nuevaCantidad = System::Convert::ToInt32(formularioCrud->Cantidad);
			std::string nuevoProveedor = convertirSystemStringAStdString(formularioCrud->Proveedor);
			std::string nuevoModelo = convertirSystemStringAStdString(formularioCrud->Modelo);

			// Actualizar el implemento en el inventario
			Implemento implementoActualizado;
			// Obtener el implemento actual de tu inventario usando el ID seleccionado
			// Asignar los datos actualizados al implemento
			implementoActualizado.setID(nuevoID);
			implementoActualizado.setNombre(nuevoNombre);
			implementoActualizado.setTipo(nuevoTipo);
			implementoActualizado.setCantidad(nuevaCantidad);
			implementoActualizado.setProveedor(nuevoProveedor);
			implementoActualizado.setModelo(nuevoModelo);

			// Guardar el implemento actualizado en el archivo
			GuardarImplementoEnArchivo(nuevoID,implementoActualizado);

			ActualizarGrilla();
			// Mostrar nuevamente la ventana principal
			this->Visible = true;
		}
		auto end = std::chrono::high_resolution_clock::now(); //medir tiempo final cpu
        	long tiempoCPU = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count(); //medir tiempo resultado cpu
		// Guardar el tiempo de CPU en el vector cpu_values
        	cpu_values->Add(KeyValuePair<int, long>(indiceVector, tiempoCPU));
		indiceVector++;
		// Obtener el uso de memoria en kilobytes
    		unsigned long usoMemoria = obtenerUsoMemoria() / 1024;
    		// Agregar los valores al vector
    		memory_values->Add(KeyValuePair<int, unsigned long>(indiceMemoria, usoMemoria));
    		indiceMemoria++;
	}
	private: void BorrarSegunId(System::String^ idSeleccionado) {
		if (!String::IsNullOrEmpty(idSeleccionado)) {
			// Convertir el ID seleccionado a entero
			int idArchivo = System::Convert::ToInt32(idSeleccionado);

			// Crear la ruta completa al archivo CSV correspondiente
			std::string rutaArchivo = "archivos/archivo_" + std::to_string(idArchivo) + ".csv";

			// Eliminar el archivo correspondiente al implemento seleccionado
			std::remove(rutaArchivo.c_str());
		}
	}
	private: System::Void btn_borrar_Click(System::Object^ sender, System::EventArgs^ e) {
		auto start = std::chrono::high_resolution_clock::now(); //medir tiempo inicio cpu
		//Tienen los datos seleccionados en las variables
		//Borran los datos del archivo desde esta funcion
		BorrarSegunId(id_selected);
		ActualizarGrilla();
		this->Visible = true;
		auto end = std::chrono::high_resolution_clock::now(); //medir tiempo final cpu
        	long tiempoCPU = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count(); //medir tiempo resultado cpu
		// Guardar el tiempo de CPU en el vector cpu_values
       	cpu_values->Add(KeyValuePair<int, long>(indiceVector, tiempoCPU));
		indiceVector++;
		// Obtener el uso de memoria en kilobytes
    	unsigned long usoMemoria = obtenerUsoMemoria() / 1024;
    	// Agregar los valores al vector
    	memory_values->Add(KeyValuePair<int, unsigned long>(indiceMemoria, usoMemoria));
    	indiceMemoria++;
	}

	//Guarda los datos seleccionados de la grilla actual
	//Todos los datos se guardan en strings, ya lo castean segun necesiten
	private: System::Void grilla_Datos_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		if (e->RowIndex >= 0) {
			DataGridViewRow^ filaSeleccionada = grilla_Datos->Rows[e->RowIndex];
			String^ valorPrimeraCelda = filaSeleccionada->Cells[1]->Value->ToString();

			id_selected = filaSeleccionada->Cells[0]->Value->ToString();
			nombre_selected = filaSeleccionada->Cells[1]->Value->ToString();
			tipo_selected = filaSeleccionada->Cells[2]->Value->ToString();
			cantidad_selected = filaSeleccionada->Cells[3]->Value->ToString();
			Proveedor_selected = filaSeleccionada->Cells[4]->Value->ToString();
			Modelo_selected = filaSeleccionada->Cells[5]->Value->ToString();

			this->lbl_seleccionado->Text = "Seleccionado: " + valorPrimeraCelda;
		}
	}
	void GuardarDatosEnArchivoCPU(const std::string &archivo) {
		std::ofstream ofs(archivo, std::ios::app);
		if (!ofs.is_open())
		{
			std::cerr << "Error al abrir el archivo para escribir.\n";
			return;
		}
		
		for each (KeyValuePair<int, long > dato in cpu_values) {
			ofs << dato.Key << " " << dato.Value << "\n";
		}
	}

	void GuardarDatosEnArchivoMemoria(const std::string &archivo) {
		std::ofstream ofs(archivo, std::ios::app);
		if (!ofs.is_open())
		{
			std::cerr << "Error al abrir el archivo para escribir.\n";
			return;
		}
		
		for each (KeyValuePair<int, unsigned long> dato in memory_values) {
			ofs << dato.Key << " " << dato.Value << "\n";
		}
	}

	// Función para obtener el uso de memoria en tiempo de ejecución
	unsigned long obtenerUsoMemoria() {
		DH_STATUS status;
		PDH_FMT_COUNTERVALUE counterValue;

		// Abrir una consulta
		PDH_HQUERY query;
		status = PdhOpenQueryW(NULL, NULL, &query); // Utilizamos PdhOpenQueryW para cadenas anchas
		if (status != ERROR_SUCCESS) {
			//std::cerr << "Error al abrir la consulta PDH: " << status << std::endl;
			return 0;
		}

		// Agregar la consulta para obtener el contador de uso de memoria
		PDH_HCOUNTER counter;
		status = PdhAddCounterW(query, L"\\Process(??APP_WIN32_PROCESS??)\\Working Set", NULL, &counter); // Utilizamos PdhAddCounterW para cadenas anchas
		if (status != ERROR_SUCCESS) {
			//std::cerr << "Error al agregar el contador PDH: " << status << std::endl;
			PdhCloseQuery(query);
			return 0;
		}

		// Recopilar datos de la consulta
		status = PdhCollectQueryData(query);
		if (status != ERROR_SUCCESS) {
			//std::cerr << "Error al recopilar datos de la consulta PDH: " << status << std::endl;
			PdhCloseQuery(query);
			return 0;
		}

		// Obtener el valor del contador de uso de memoria
		status = PdhGetFormattedCounterValue(counter, PDH_FMT_LONG, NULL, &counterValue);
		if (status != ERROR_SUCCESS) {
			//std::cerr << "Error al obtener el valor del contador PDH: " << status << std::endl;
			PdhCloseQuery(query);
			return 0;
		}

		// Cerrar la consulta
		PdhCloseQuery(query);

		return static_cast<unsigned long>(counterValue.longValue / 1024); 
		
	}



	};
}
