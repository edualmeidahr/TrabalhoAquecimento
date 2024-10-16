#include <iostream>
#include "TFIDF.hpp"


int main() {
    std::string nomeArquivoEntrada = "input/biblia.txt"; // Nome do arquivo para leitura
    std::string nomeArquivoSaida = "livro_processado.txt"; // Nome do arquivo de saída

    // Lê o livro e processa
    std::vector<std::string> livro = lerLivro(nomeArquivoEntrada);

    // Salva o resultado processado em um arquivo na pasta "output"
    salvarLivroProcessado(livro, nomeArquivoSaida);

    return 0;
}
