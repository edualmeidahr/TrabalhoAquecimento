#include <algorithm>
#include <iostream>
#include "TFIDF.hpp"


int main() {

    std::string nomeArquivoEntrada = "input/1.txt"; // Nome do arquivo para leitura
    std::string nomeArquivoSaida = "livro_processado.txt"; // Nome do arquivo de saída

    // Lê o livro e processa

    lerStopWords("input/stopwords.txt");

    //Livro 1: A mão e a luva

    std::vector<std::string> livro = lerLivro("input/A mao e a luva.txt");
    std::unordered_map<std::string, int> tf = processarDocumento(livro);
    std::vector<std::unordered_map<std::string, int> > documentos;
    documentos.push_back(tf);

    //Livro 2: biblia

    livro = lerLivro("input/biblia.txt");
    tf = processarDocumento(livro);
    documentos.push_back(tf);

    //Livro 3: DomCasmurro

    livro = lerLivro("input/DomCasmurro.txt");
    tf = processarDocumento(livro);
    documentos.push_back(tf);

    //Livro 4: quincas borba

    livro = lerLivro("input/quincas borba.txt");
    tf = processarDocumento(livro);
    documentos.push_back(tf);

    //Livro 5: Semana_Machado_Assis

    livro = lerLivro("input/Semana_Machado_Assis.txt");
    tf = processarDocumento(livro);
    documentos.push_back(tf);

    //Livro 6: terremoto

    livro = lerLivro("input/terremoto.txt");
    tf = processarDocumento(livro);
    documentos.push_back(tf);


    //Calcular IDF
    std::unordered_map<std::string, double> idf = calcularIDF(documentos);


    // Salva o resultado processado em um arquivo na pasta "output"
    //salvarLivroProcessado(livro, nomeArquivoSaida);

    std::string prefrase = {"No dia 23 de Março deste presente anno de 1748 pelas 6"}; // digitar a frase
    std::string frase = removerStopWords(removePontuacaoPadronizaMinuscula(prefrase));

    std::istringstream stream(frase);
    std::string palavra;
    std::vector<std::string> posfrase;

    while (stream >> palavra) {
        posfrase.push_back(palavra);
    }


    // Supõe que 'documentos' é um vetor onde cada elemento é um mapa de TF de um documento.
    std::vector<std::pair<int, double> > relevancias;

    for (size_t i = 0; i < documentos.size(); ++i) {
        double relevancia = calcularRelevancia(documentos[i], idf, posfrase);
        relevancias.push_back({i, relevancia});
    }

    // Ordenar os documentos por relevância em ordem decrescente
    std::sort(relevancias.begin(), relevancias.end(),
              [](const std::pair<int, double> &a, const std::pair<int, double> &b) {
                  return a.second > b.second;
              });

    //Exibir frase pesquisada

    std::cout << "Frase pesquisada: " << prefrase << std::endl;


    // Exibir os documentos ordenados por relevância
    for (const auto &[docIndex, relevancia]: relevancias) {
        std::cout << "Livro: " << NomeLivro(docIndex)  << " - Relevancia: " << relevancia << std::endl;
    }


    return 0;
}
