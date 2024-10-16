#ifndef TFIDF_HPP
#define TFIDF_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <cctype>
#include <string>
#include <filesystem> // Necessário para manipulação de diretórios
#include <unordered_set>

std::string removePontuacaoPadronizaMinuscula(const std::string& linhaLivro);
std::unordered_set<std::string> lerStopWords(const std::string& nomeArquivo);
std::string removerStopWords(const std::string& linhaLivro, const std::unordered_set<std::string>& stopwords);
std::vector<std::string> lerLivro(const std::string& nomeArquivo);
void salvarLivroProcessado(const std::vector<std::string>& livro, const std::string& nomeArquivoSaida);



#endif // TFIDF_HPP