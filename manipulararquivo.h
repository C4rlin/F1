#ifndef MANIPULARARQUIVO_H
#define MANIPULARARQUIVO_H
#include<QString>
#include<fstream>
#include<QStringList>
#include <piloto.h>
#include <vector>

namespace ce{
class ManipularArquivo
{
    //Atributos
private:
    QString nomeDoArquivo;
    std::vector<Piloto> listaDePilotosF1;
public:
    ManipularArquivo(QString nomeDoArquivo);
    void buscarDadosNoArquivo();
    const std::vector<Piloto> getListaDePilotosF1()const;
};
}
#endif // MANIPULARARQUIVO_H
