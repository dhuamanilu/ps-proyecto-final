#pragma once
#include "implemento.h"
#include <vector>

class Inventario {
public:
    Inventario::Inventario() {}

    Inventario::~Inventario() {}

    void Inventario::agregarImplemento(const Implemento& implemento) {
        listaImplementos.push_back(implemento);
    }

    bool Inventario::borrarImplemento(int ID) {
        for (auto it = listaImplementos.begin(); it != listaImplementos.end(); ++it) {
            if (it->getID() == ID) {
                listaImplementos.erase(it);
                return true;
            }
        }
        return false;
    }

    Implemento* Inventario::buscarImplemento(int ID) {
        for (auto& implemento : listaImplementos) {
            if (implemento.getID() == ID) {
                return &implemento;
            }
        }
        return nullptr;
    }

    std::vector<Implemento>& Inventario::obtenerListaImplementos() {
        return listaImplementos;
    }

private:
    std::vector<Implemento> listaImplementos;  
};

