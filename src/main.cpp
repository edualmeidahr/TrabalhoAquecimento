#include <iostream>
#include "TFIDF.hpp"


int main() {
    std::string nomeArquivoEntrada = "input/biblia.txt"; // Nome do arquivo para leitura
    std::string nomeArquivoSaida = "livro_processado.txt"; // Nome do arquivo de saída

    // Lê o livro e processa
    std::vector<std::string> livro = lerLivro(nomeArquivoEntrada);
    std::unordered_map<std::string, int> tf = processarDocumento(livro);
    std::vector<std::unordered_map<std::string, int>> documentos;
    documentos.push_back(tf);
    std::unordered_map<std::string, double> idf = calcularIDF(documentos);



    // Salva o resultado processado em um arquivo na pasta "output"
    salvarLivroProcessado(livro, nomeArquivoSaida);

    return 0;
}
