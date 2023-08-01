#pragma once
#include <string>

class Implemento {
public:
    Implemento::Implemento() : ID(0), nombre(""), tipo(""), cantidad(0), proveedor(""), modelo("") {}

    Implemento::Implemento(int ID, const std::string& nombre, const std::string& tipo, int cantidad, const std::string& proveedor, const std::string& modelo)
        : ID(ID), nombre(nombre), tipo(tipo), cantidad(cantidad), proveedor(proveedor), modelo(modelo) {}

    Implemento::~Implemento() {}

    int Implemento::getID() const {
        return ID;
    }
    void Implemento::setID(int i)  {
        ID=i;
    }
    std::string Implemento::getNombre() const {
        return nombre;
    }
    void Implemento::setNombre(std::string nom) {
        nombre =nom;
    }
    std::string Implemento::getTipo() const {
        return tipo;
    }
    void Implemento::setTipo(std::string tip) {
        tipo = tip;
    }
    int Implemento::getCantidad() const {
        return cantidad;
    }
    void Implemento::setCantidad(int cant) {
       cantidad=cant;
    }
    std::string Implemento::getProveedor() const {
        return proveedor;
    }
    void Implemento::setProveedor(std::string prov) {
        proveedor=prov;
    }
    std::string Implemento::getModelo() const {
        return modelo;
    }
    void Implemento::setModelo(std::string mod) {
        modelo=mod;
    }


private:
    int ID;
    std::string nombre;
    std::string tipo;
    int cantidad;
    std::string proveedor;
    std::string modelo;
};
