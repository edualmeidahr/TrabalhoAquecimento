#include "TFIDF.hpp"

double calcularRelevancia(const std::unordered_map<std::string, int> &tf,
                          const std::unordered_map<std::string, double> &idf,
                          const std::vector<std::string> &frasePesquisa) {
    double relevancia = 0.0;

    // Itera sobre cada termo da frase de pesquisa
    for (const auto &termo: frasePesquisa) {
        // Verifica se o termo está presente no TF e no IDF
        auto itTF = tf.find(termo);
        auto itIDF = idf.find(termo);

        // Se o termo existe tanto em TF quanto em IDF, calcula o valor TF*IDF
        if (itTF != tf.end() && itIDF != idf.end()) {
            double tfValue = static_cast<double>(itTF->second);
            double idfValue = itIDF->second;
            relevancia += tfValue * idfValue;
        }
    }

    return relevancia;
}

std::string removePontuacaoPadronizaMinuscula(const std::string &linhaLivro) {
    std::string linhaNormalizada;

    // Processa cada caractere na string
    for (char c: linhaLivro) {
        if (!ispunct(c)) {
            // Se não for pontuação
            // Converte para minúscula e adiciona ao resultado normalizado
            linhaNormalizada.push_back(tolower(c));
        }
    }

    return linhaNormalizada;
}


void lerStopWords(const std::string &nomeArquivo) {
    std::unordered_set<std::string> stopwords;
    std::ifstream arquivo(nomeArquivo);
    std::string palavra;

    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo de stopwords: " << nomeArquivo << std::endl;
        exit(EXIT_FAILURE);
    }

    while (std::getline(arquivo, palavra)) {
        if (!palavra.empty()) {
            stopwords.insert(palavra);
        }
    }
    arquivo.close();
}


// Função para remover as stopwords de cada livro
std::string removerStopWords(const std::string &linhaLivro) {
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
std::vector<std::string> lerLivro(const std::string &nomeArquivo) {
    std::ifstream arquivo(nomeArquivo);
    std::string linha; // String para armazenar cada linha do arquivo
    std::vector<std::string> livro; // Vetor de strings para armazenar as linhas do arquivo

    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo: " << nomeArquivo << std::endl;
        return livro; // Retorna um vetor vazio em caso de erro
    }

    while (std::getline(arquivo, linha)) {
        // Remove pontuação e padroniza para minúscula
        std::string linhaProcessada = removePontuacaoPadronizaMinuscula(linha);
        linhaProcessada = removerStopWords(linhaProcessada);
        // Adiciona a linha processada ao vetor, se não estiver vazia
        if (!linhaProcessada.empty()) {
            livro.push_back(linhaProcessada);
        }
    }

    arquivo.close();
    return livro;
}

std::unordered_map<std::string, int> processarDocumento(const std::vector<std::string> &termosDocumento) {
    std::unordered_map<std::string, int> tf;

    // Calcula a frequência de cada termo no documento
    for (const auto &frase: termosDocumento) {
        std::istringstream iss(frase); // Cria um fluxo de string para separar as palavras
        std::string termo;

        // Extrai cada termo da frase
        while (iss >> termo) {
            tf[termo]++;
        }
    }


    //Imprime o map
    // for (const auto &par: tf) {
    //     std::cout << par.first << ": " << par.second << std::endl;
    //     // par.first é a chave (termo), par.second é o valor (frequência)
    // }

    return tf;
}

std::unordered_map<std::string, double> calcularIDF(
    const std::vector<std::unordered_map<std::string, int> > &documentos) {
    std::unordered_map<std::string, int> documentoComTermo;
    int totalDocumentos = documentos.size();


    // Contar quantos documentos contêm cada termo
    for (const auto &doc: documentos) {
        std::set<std::string> termosUnicos; // Usado para contar termos únicos por documento
        for (const auto &[termo, _]: doc) {
            termosUnicos.insert(termo);
        }
        for (const auto &termo: termosUnicos) {
            documentoComTermo[termo]++;
        }
    }

    // Calcular o IDF para cada termo
    std::unordered_map<std::string, double> idf;
    for (const auto &[termo, numDocumentos]: documentoComTermo) {
        idf[termo] = log(static_cast<double>(totalDocumentos) / numDocumentos);
    }

    //Imprimir IDF de cada termo
    // std::cout << "IDF dos Termos:\n";
    // for (const auto &[termo, valor]: idf) {
    //     std::cout << "  Termo: \"" << termo << "\", IDF: " << valor << "\n";
    // }

    return idf;
}


// Função para salvar o conteúdo processado em um arquivo
void salvarLivroProcessado(const std::vector<std::string> &livro, const std::string &nomeArquivoSaida) {
    // Verifica se a pasta "output" existe, caso contrário, cria
    std::filesystem::create_directory("output");

    // Cria o arquivo na pasta "output"
    std::ofstream arquivoSaida("output/" + nomeArquivoSaida);
    if (!arquivoSaida.is_open()) {
        std::cerr << "Erro ao criar o arquivo de saída: " << nomeArquivoSaida << std::endl;
        return;
    }

    // Escreve cada linha do vetor no arquivo
    for (const auto &linha: livro) {
        arquivoSaida << linha << std::endl;
    }

    arquivoSaida.close();
    std::cout << "Arquivo salvo em: output/" << nomeArquivoSaida << std::endl;
}
