# TF-IDF - AEDS II
![CAPA](https://github.com/edualmeidahr/TrabalhoAquecimentoAeds2/blob/main/img/GIF%20AEDS%202%20TFIDF.gif?raw=true)

## 1. Introdução
### 1.1 Objetivo do Projeto
O principal objetivo deste projeto é implementar um sistema de ranqueamento de documentos utilizando o algoritmo TF/IDF (Term Frequency - Inverse Document Frequency). Esse sistema é projetado para processar um conjunto de documentos, calcular a relevância de cada um deles em relação a uma frase de pesquisa específica e ranquear os documentos conforme essa relevância.

O TF/IDF é uma métrica amplamente utilizada em recuperação de informações e mineração de texto, pois quantifica a importância de um termo em relação a um documento específico e ao conjunto de documentos em análise. Neste projeto, a aplicação do TF/IDF envolve calcular a frequência de cada termo em documentos individuais (TF) e ponderar essa frequência em relação à distribuição do termo em todos os documentos (IDF), determinando a relevância de documentos para as frases fornecidas pelo usuário.

Além disso, a construção do sistema de ranqueamento explora conceitos fundamentais de estrutura de dados e análise de complexidade, como listas, filas, tabelas hash e métodos de ordenação. Esses elementos permitem organizar e processar os dados de maneira eficiente, garantindo que o sistema atenda a critérios de eficiência computacional exigidos.

### 1.2 Contexto e Motivação
A análise e o ranqueamento de documentos com base em palavras-chave e frases de pesquisa são essenciais para diversas aplicações, como buscadores, sistemas de recomendação e inteligência artificial. O algoritmo TF/IDF é particularmente valorizado nesses contextos, pois permite diferenciar termos comuns de termos importantes em um conjunto de documentos. Termos que aparecem frequentemente em um documento específico, mas raramente em outros, tendem a ser mais relevantes para aquele documento, enquanto termos presentes em todos os documentos (as *stopwords*) são considerados menos informativos.

Este trabalho busca não só ensinar os fundamentos do TF/IDF, mas também estimular a reflexão sobre a escolha de estruturas de dados e sua influência na eficiência de sistemas de busca e classificação. O ranqueamento de documentos oferece um campo ideal para entender melhor o processamento de textos e a recuperação de informações, permitindo uma aproximação prática com questões de desempenho e eficácia em algoritmos de grande importância.

## 2. Descrição do Problema

### 2.1 Estrutura e Análise dos Documentos
O projeto consiste em analisar grandes volumes de texto para identificar quais termos são mais relevantes em cada documento. A relevância de uma palavra é determinada pelo quanto ela contribui para o significado do texto e se destaca em relação a outros documentos. Esse processo é crucial para facilitar a busca e a análise temática em diferentes documentos.

Para essa análise, foram selecionadas seis entradas textuais distintas, cada uma representando um documento específico e armazenada em um arquivo `.txt`. Essas entradas incluem:
- [A Mão e a Luva](input/A%20mao%20e%20a%20luva.txt) - Romance de Machado de Assis.
- [Bíblia](input/biblia.txt)- Texto religioso MUITO extenso.
- [Dom Casmurro](input/DomCasmurro.txt) - Outra obra de Machado de Assis, famosa por seu enredo psicológico e complexidade de personagens.
- [Quincas Borba](input/quincas%20borba.txt) - Romance de Machado de Assis que explora temas filosóficos, especialmente o conceito de "Humanitismo".
- [Semana](input/Semana_Machado_Assis.txt) - Texto curto de Machado de Assis, com características de crônica sobre temas cotidianos e culturais.
- [Terremoto](input/terremoto.txt) - Documento histórico que descreve os danos e ruínas causadas por um terremoto que ocorreu na cidade de Valença e em outras regiões vizinhas em 1748.

Essas obras foram escolhidas para proporcionar uma base diversificada para o algoritmo TF-IDF. Este algoritmo avalia a importância de cada palavra em cada documento individual, considerando tanto sua frequência local (TF) quanto sua raridade global (IDF).

### 2.2 Resumo do Problema

O processo de análise e ranqueamento é dividido nas seguintes etapas:

- **Leitura dos Documentos**: Cada documento será lido e padronizado para análise, removendo caracteres especiais e pontuações, convertendo todas as palavras para letras minúsculas e eliminando *stopwords* (palavras comuns e pouco informativas). Os termos finais de cada documento são então armazenados para acesso e análise.

- **Cálculo do TF-IDF**: Para cada termo presente nos documentos, calcula-se a frequência de ocorrência no próprio documento e sua importância em relação ao conjunto. Isso ajuda a identificar quais termos são mais específicos ou relevantes para cada texto individualmente.

- **Ranqueamento de Documentos**: Com os valores de relevância calculados, os documentos são classificados com base na relevância para uma frase de pesquisa específica. Os documentos mais relevantes são identificados e ordenados, facilitando a busca e a identificação dos textos que mais correspondem aos termos pesquisados.

## 3. Estrutura do Código

### Função calcularIDF

A função calcularIDF calcula o valor IDF (Inverse Document Frequency) para cada termo presente em uma coleção de documentos. Esse valor representa a importância de um termo em relação a todos os documentos da coleção, sendo útil para ranqueamento de relevância em algoritmos como TF-IDF.

Primeiro, a função calcula quantos documentos contêm cada termo único, armazenando esses dados em um unordered_map.
Em seguida, o IDF de cada termo é calculado usando a fórmula log(totalDocumentos / numDocumentos), onde totalDocumentos é o número total de documentos e numDocumentos é o número de documentos em que o termo específico aparece.

Essa função retorna um mapa (unordered_map) que associa cada termo ao seu respectivo valor de IDF.

![calcularIDF](https://github.com/user-attachments/assets/b1d2b493-b40f-424e-b2c5-9de118c63553)

### Função lerLivro

A função lerLivro lê o conteúdo de um arquivo texto e retorna um vetor de strings, onde cada elemento do vetor representa uma linha processada do arquivo.

A função tenta abrir o arquivo especificado pelo parâmetro nomeArquivo. Em caso de falha, ela retorna um vetor vazio e exibe uma mensagem de erro.
Em seguida, a função lê cada linha do arquivo, remove pontuações, converte o texto para letras minúsculas, e remove palavras irrelevantes ("stop words").
Cada linha processada é adicionada ao vetor livro, que é retornado ao final da função.

Essa função facilita a manipulação do conteúdo de um livro, convertendo-o em uma estrutura mais organizada para processamento posterior.

![lerLivro](https://github.com/user-attachments/assets/d839efa3-7b13-4974-8f2a-6de364aeb249)

### Função NomeLivro

A função NomeLivro recebe um número inteiro e retorna o título de um livro correspondente a esse índice.

Um vetor estático de strings chamado livro armazena os títulos de diferentes livros.
A função usa o índice fornecido (numero) para acessar o título correspondente no vetor e retorna esse título.

Essa função permite obter o nome de um livro com base em um índice, facilitando a identificação de documentos durante o processamento.

![nomeLivro](https://github.com/user-attachments/assets/0592e8cc-3d9d-4a6e-a90b-c5955bd7b6e5)

### Função processarDocumento

A função processarDocumento calcula a frequência de termos em um documento específico, representado por um vetor de strings onde cada string é uma frase.

A função usa um unordered_map para armazenar a contagem de cada termo.
Para cada frase no documento, ela divide a frase em palavras e contabiliza a frequência de cada uma.
Como exemplo, se a palavra "deus" aparecer, a contagem dela é incrementada separadamente.

No final, a função retorna o mapa (unordered_map) com a contagem de cada termo, permitindo que a frequência de termos seja usada para o cálculo do TF (Term Frequency) em algoritmos de busca.

![processarDOcumento](https://github.com/user-attachments/assets/00705309-256d-43e3-9fb2-e57c31611062)

### Função calcularRelevancia

A função calcularRelevancia calcula a relevância de uma frase de pesquisa em relação a um documento, utilizando os valores de TF (Term Frequency) e IDF (Inverse Document Frequency). A relevância é calculada somando o produto de TF e IDF para cada termo presente tanto na frase de pesquisa quanto no documento.

Parâmetros:

tf: Um mapa contendo a frequência dos termos no documento.
idf: Um mapa contendo os valores de IDF para cada termo.
frasePesquisa: Um vetor de strings contendo os termos da frase de pesquisa.

Descrição:

A função percorre cada termo da frasePesquisa e verifica se ele está presente tanto no mapa tf quanto no idf.
Caso o termo exista em ambos, calcula-se o valor TF*IDF e soma-se à variável relevancia.
Retorna o valor da relevância total calculada para a frase de pesquisa no contexto do documento.

![calcularRelevancia](https://github.com/user-attachments/assets/39fbae3e-3ce0-4242-81c8-f1cb742f35e7)

### Função removePontuacaoPadronizaMinuscula

A função removePontuacaoPadronizaMinuscula remove a pontuação de uma linha e converte todos os caracteres para letras minúsculas. Isso padroniza o texto, facilitando o processamento posterior.

Parâmetros:

linhaLivro: Uma string representando uma linha do livro.
Descrição:

A função percorre cada caractere da string linhaLivro.
Se o caractere não for pontuação, ele é convertido para minúscula e adicionado à string linhaNormalizada.
Retorna a string normalizada, contendo apenas letras minúsculas e sem pontuação.

![removePontuação](https://github.com/user-attachments/assets/2fef2d50-35db-415e-a751-7da5a27359c7)

### Função lerStopWords

A função lerStopWords carrega uma lista de stopwords a partir de um arquivo de texto e armazena-as em um conjunto (unordered_set). Stopwords são palavras comuns (como "e", "de", "o") que são geralmente ignoradas em processos de análise de texto.

Parâmetros:

nomeArquivo: Nome do arquivo contendo as stopwords.
Descrição:

Abre o arquivo especificado. Caso ocorra um erro ao abrir, exibe uma mensagem e encerra o programa.
Lê cada palavra no arquivo e insere no conjunto stopwords.
Fecha o arquivo ao final do processo.

![lerStopWord](https://github.com/user-attachments/assets/00df442d-f87c-45bc-bdfd-d6802f725cc9)

### Função removerStopWords

A função removerStopWords remove as stopwords de uma linha de texto, retornando apenas as palavras relevantes.

Parâmetros:

linhaLivro: Uma string representando uma linha do livro.
Descrição:

A função usa um fluxo de string (istringstream) para dividir a linhaLivro em palavras.
Para cada palavra, verifica se ela não está presente no conjunto stopwords.
Se a palavra não for uma stopword, adiciona-a à string resultado.
Retorna a linha processada, contendo apenas palavras que não são stopwords.

![removerStopWord](https://github.com/user-attachments/assets/53ca1533-2c3b-4bdb-9592-dbc6bdf49d96)

### Função salvarLivroProcessado

A função salvarLivroProcessado salva o conteúdo de um livro processado em um arquivo de saída localizado na pasta "output", ela foi usada unicamente durante o teste dos documentos, de forma 
a saber se a remoção de stop words e a redução ocorreram de forma correta.

Parâmetros:

livro: Um vetor de strings, onde cada elemento representa uma linha processada do livro.
nomeArquivoSaida: O nome do arquivo de saída onde o livro processado será salvo.
Descrição:

Verifica se a pasta output existe; se não, cria a pasta.
Abre o arquivo de saída na pasta output com o nome especificado. Caso ocorra um erro ao abrir, exibe uma mensagem e encerra a função.
Escreve cada linha do vetor livro no arquivo.
Fecha o arquivo após a escrita e exibe a mensagem indicando o local do arquivo salvo.

![salvarLivroProcessado](https://github.com/user-attachments/assets/3ac9981c-5ffe-48a8-bf36-5b45a92595bf)


## 4. Desafios e Experiências

Os fundamentos de análise assintótica, estudados em AEDS I, foram essenciais para compreender os desafios de desempenho na primeira fase de implementação do projeto. Esse conhecimento mostrou como algoritmos com custos quadráticos O(n²) se tornam ineficientes para grandes entradas, impactando diretamente o tempo de execução.

Na primeira fase, isso ficou evidente na etapa de **remoção das stopwords**. Para textos “não muito grandes”, o código processava as palavras e removia as stopwords com relativa eficiência. No entanto, ao lidar com um documento extenso como a Bíblia, o comportamento do algoritmo mudou drasticamente: o custo quadrático tornou-se um obstáculo crítico, fazendo com que o código não fosse executado até o final devido ao alto tempo de processamento apenas para remover as stopwords.

```cpp  
    for (int i = 0; i < vectordocumento.size(); i++)
    {
        for (int j = 0; j < stopwords.size(); j++)
        {
            if (vectordocumento[i] == stopwords[j])
            {
                 vectordocumento.erase(vectordocumento.begin() + i);
            }
        }
    }
```


Esse cenário mostrou a importância da escolha de algoritmos e estruturas de dados apropriadas. A análise assintótica permitiu identificar a necessidade de otimizações e de métodos com menor complexidade, assegurando que o sistema pudesse lidar com grandes volumes de dados de maneira eficiente.

## 5. Conceitos Fundamentais

Para facilitar o entendimento dos principais conceitos utilizados, desenvolvemos imagens conceituais que ilustram o funcionamento dos itens abaixo. Esses conceitos são fundamentais para a aplicação do algoritmo TF-IDF e o ranqueamento de documentos, garantindo uma análise de relevância precisa para termos de pesquisa específicos.

- **Stopwords**: Palavras comuns que aparecem frequentemente em textos, mas que possuem pouco valor informativo (ex.: “de”, “a”, “e”). A remoção das stopwords permite focar nas palavras que realmente carregam o significado do texto.

  <img src="https://cdn.discordapp.com/attachments/1300123706013650966/1300949896731430953/STOPWORDS.png?ex=6722b381&is=67216201&hm=0542ecc7a7482cea75895c1d27846dfab84e34d9c250eb349664b13341a2f3e8&" alt="Stopwords" width="800" />

- **Term Frequency (TF)**: Refere-se à frequência com que um termo aparece em um documento específico. Esse valor representa a importância de um termo dentro de um único documento.

    <img src="https://cdn.discordapp.com/attachments/1187944026578624534/1301702019165323365/TF.png?ex=67256ff9&is=67241e79&hm=64caca2d63b363591b78ae92d0dce91f975682a46b5dec2b92cc944885961700&" alt="TF" width="800" />

- **Inverse Document Frequency (IDF)**: Mede a importância de um termo em relação ao conjunto total de documentos. Quanto mais raro for o termo nos documentos, maior será seu valor de IDF, destacando termos específicos.

    <img src="https://cdn.discordapp.com/attachments/1300123706013650966/1300949898186981418/IDF.png?ex=6722b382&is=67216202&hm=d294ed90dc2e436e4361b886019fe9be5576dacea3a5135b1a56c3baa45ff401&" alt="IDF" width="800" />
   
- **TF-IDF**: Combinação do TF e do IDF para quantificar a relevância de um termo em um documento específico. Esse valor ajuda a identificar as palavras-chave mais importantes para o conteúdo de cada documento.

     <img src="https://cdn.discordapp.com/attachments/1300123706013650966/1300949895166820485/Prancheta_1_copiar_2.png?ex=6722b381&is=67216201&hm=f02e0e1faf44ac186a14b6570158a6c9e1ae43a33adf890a25dc5778383ede77&" alt="IDF" width="800" />
- **Ranqueamento**: Processo de ordenação dos documentos de acordo com sua relevância para uma frase de pesquisa. Os valores de TF-IDF são somados para cada termo da frase de pesquisa, e os documentos são classificados do mais relevante ao menos relevante.
     <img src="https://cdn.discordapp.com/attachments/1300123706013650966/1300949895947223040/Prancheta_1_copiar_2-1.png?ex=6722b381&is=67216201&hm=5b65e4428fd467b66eb5925f14f7263aa45ff18718da322a2fa13c94cf89274e&" alt="RANQUEAMENTO" width="800" />
     
## 6. Conclusão
Este projeto forneceu uma experiência prática valiosa com o algoritmo TF-IDF, desde a implementação básica até a otimização para grandes volumes de texto. A análise dos conceitos de eficiência algorítmica demonstrou a importância de escolher estruturas de dados e métodos adequados para o processamento de texto em larga escala.

O sistema desenvolvido permite identificar rapidamente os documentos mais relevantes para frases de pesquisa, com um modelo eficiente e escalável para aplicação em recuperação de informações. Ao final, este trabalho reforçou a importância de otimizações, especialmente ao lidar com dados massivos, proporcionando uma base sólida para aprimoramentos futuros e aplicações em cenários reais.

## 7. Como utilizar

Este projeto utiliza um Makefile para simplificar o processo de compilação e execução. Siga os passos abaixo para compilar, rodar o programa e limpar arquivos temporários:

**Clone o repositório e navegue até o diretório do projeto:**
   ```bash
   git clone https://github.com/edualmeidahr/TrabalhoAquecimentoAeds2
   cd TrabalhoAquecimentoAeds2
   ```

No arquivo principal [main.cpp](src/main.cpp), você pode modificar a variável "prefrase" para definir a frase de pesquisa desejada.

Os comandos são:

Comando   | Utilidade
--------- | ------
```make clean``` | Remove os arquivos objetos e o executável gerados.
```make``` | Compila o código fonte e gera o executável.
```make run``` | Executa o programa compilado.


