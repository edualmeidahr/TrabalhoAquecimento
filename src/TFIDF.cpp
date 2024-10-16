#include "TFIDF.hpp"

std::string removePontuacaoPadronizaMinuscula(const std::string& linhaLivro) {
    std::string linhaNormalizada;

    // Processa cada caractere na string
    for (char c : linhaLivro) {
        if (!ispunct(c)) { // Se não for pontuação
            // Converte para minúscula e adiciona ao resultado normalizado
            linhaNormalizada.push_back(tolower(c));
        }
    }

    return linhaNormalizada;
}


std::unordered_set<std::string> lerStopWords(const std::string& nomeArquivo){
    std::unordered_set<std::string> stopwords;
    std::ifstream arquivo(nomeArquivo);
    std::string palavra;

    if(!arquivo.is_open()){
        std::cerr << "Erro ao abrir o arquivo de stopwords: " << nomeArquivo << std::endl;
        return stopwords;
    }

    while(std::getline(arquivo, palavra)){
        if(!palavra.empty()){
            stopwords.insert(palavra);
        }
    }
    arquivo.close();
    return stopwords;

}


// Função para remover as stopwords de cada livro
std::string removerStopWords(const std::string& linhaLivro, const std::unordered_set<std::string>& stopwords) {
    std::istringstream stream(linhaLivro);
    std::string palavra;
    std::string resultado;

    // Itera sobre cada palavra no texto
    while (stream >> palavra) {
        // Verifica se a palavra não está na lista de stopwords
        if (stopwords.find(palavra) == stopwords.end()) {
            // Se não for uma stopword, adiciona ao resultado
            if (!resultado.empty()) {
                resultado += " "; // Adiciona um espaço antes da próxima palavra
            }
            resultado += palavra;
        }
    }

    return resultado;
}


// Função para ler um arquivo contendo um livro e retornar um vetor de strings
std::vector<std::string> lerLivro(const std::string& nomeArquivo) {
    std::ifstream arquivo(nomeArquivo);
    std::string linha; // String para armazenar cada linha do arquivo
    std::vector<std::string> livro; // Vetor de strings para armazenar as linhas do arquivo
    std::unordered_set<std::string> stopwords = lerStopWords("input/stopwords.txt");

    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo: " << nomeArquivo << std::endl;
        return livro; // Retorna um vetor vazio em caso de erro
    }

    while (std::getline(arquivo, linha)) {
        // Remove pontuação e padroniza para minúscula
        std::string linhaProcessada = removePontuacaoPadronizaMinuscula(linha);
        linhaProcessada = removerStopWords(linhaProcessada, stopwords);
        // Adiciona a linha processada ao vetor, se não estiver vazia
        if (!linhaProcessada.empty()) {
            livro.push_back(linhaProcessada);
        }
    }

    arquivo.close();
    return livro;
}


// Função para salvar o conteúdo processado em um arquivo
void salvarLivroProcessado(const std::vector<std::string>& livro, const std::string& nomeArquivoSaida) {
    // Verifica se a pasta "output" existe, caso contrário, cria
    std::filesystem::create_directory("output");

    // Cria o arquivo na pasta "output"
    std::ofstream arquivoSaida("output/" + nomeArquivoSaida);
    if (!arquivoSaida.is_open()) {
        std::cerr << "Erro ao criar o arquivo de saída: " << nomeArquivoSaida << std::endl;
        return;
    }

    // Escreve cada linha do vetor no arquivo
    for (const auto& linha : livro) {
        arquivoSaida << linha << std::endl;
    }

    arquivoSaida.close();
    std::cout << "Arquivo salvo em: output/" << nomeArquivoSaida << std::endl;
}
