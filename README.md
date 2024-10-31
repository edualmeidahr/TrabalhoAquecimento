# TF-IDF - AEDS II
![CAPA](https://i.ibb.co/GQBHCGL/ezgif-3-d75e0f657b.gif)

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
- [A Mão e a Luva](/A%20mao%20e%20a%20luva.txt) - Romance de Machado de Assis.
- **Bíblia** - Texto religioso MUTIO extenso.
- **Dom Casmurro** - Outra obra de Machado de Assis, famosa por seu enredo psicológico e complexidade de personagens.
- **Quincas Borba** - Romance de Machado de Assis que explora temas filosóficos, especialmente o conceito de "Humanitismo".
- **Semana** - Texto curto de Machado de Assis, com características de crônica sobre temas cotidianos e culturais.
- **Terremoto** - Documento histórico que descreve os danos e ruínas causadas por um terremoto que ocorreu na cidade de Valença e em outras regiões vizinhas em 1748.

Essas obras foram escolhidas para proporcionar uma base diversificada para o algoritmo TF-IDF. Este algoritmo avalia a importância de cada palavra em cada documento individual, considerando tanto sua frequência local (TF) quanto sua raridade global (IDF).

### 2.2 Resumo do Problema

O processo de análise e ranqueamento é dividido nas seguintes etapas:

- **Leitura dos Documentos**: Cada documento será lido e padronizado para análise, removendo caracteres especiais e pontuações, convertendo todas as palavras para letras minúsculas e eliminando *stopwords* (palavras comuns e pouco informativas). Os termos finais de cada documento são então armazenados para acesso e análise.

- **Cálculo do TF-IDF**: Para cada termo presente nos documentos, calcula-se a frequência de ocorrência no próprio documento e sua importância em relação ao conjunto. Isso ajuda a identificar quais termos são mais específicos ou relevantes para cada texto individualmente.

- **Ranqueamento de Documentos**: Com os valores de relevância calculados, os documentos são classificados com base na relevância para uma frase de pesquisa específica. Os documentos mais relevantes são identificados e ordenados, facilitando a busca e a identificação dos textos que mais correspondem aos termos pesquisados.

## 3. Estrutura do Código

@bruneido

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

    <img src="https://media.discordapp.net/attachments/1300123706013650966/1300949897465298984/TF.png?ex=6722b382&is=67216202&hm=d0c2b69c87088730878770714ba74af1d7fbf7eb3c55f86216caf47c96294e36&=&format=webp&quality=lossless&width=1118&height=559" alt="TF" width="800" />

- **Inverse Document Frequency (IDF)**: Mede a importância de um termo em relação ao conjunto total de documentos. Quanto mais raro for o termo nos documentos, maior será seu valor de IDF, destacando termos específicos.

    <img src="https://cdn.discordapp.com/attachments/1300123706013650966/1300949898186981418/IDF.png?ex=6722b382&is=67216202&hm=d294ed90dc2e436e4361b886019fe9be5576dacea3a5135b1a56c3baa45ff401&" alt="IDF" width="800" />
   
- **TF-IDF**: Combinação do TF e do IDF para quantificar a relevância de um termo em um documento específico. Esse valor ajuda a identificar as palavras-chave mais importantes para o conteúdo de cada documento.

     <img src="https://cdn.discordapp.com/attachments/1300123706013650966/1300949895166820485/Prancheta_1_copiar_2.png?ex=6722b381&is=67216201&hm=f02e0e1faf44ac186a14b6570158a6c9e1ae43a33adf890a25dc5778383ede77&" alt="IDF" width="800" />
- **Ranqueamento**: Processo de ordenação dos documentos de acordo com sua relevância para uma frase de pesquisa. Os valores de TF-IDF são somados para cada termo da frase de pesquisa, e os documentos são classificados do mais relevante ao menos relevante.
     <img src="https://cdn.discordapp.com/attachments/1300123706013650966/1300949895947223040/Prancheta_1_copiar_2-1.png?ex=6722b381&is=67216201&hm=5b65e4428fd467b66eb5925f14f7263aa45ff18718da322a2fa13c94cf89274e&" alt="RANQUEAMENTO" width="800" />
     
## 6. Conclusão
*!@*@!*!@*colocar mais coisas.....
Este projeto forneceu uma experiência prática valiosa com o algoritmo TF-IDF, desde a implementação básica até a otimização para grandes volumes de texto. A análise dos conceitos de eficiência algorítmica demonstrou a importância de escolher estruturas de dados e métodos adequados para o processamento de texto em larga escala. Ao final, o sistema desenvolvido permite identificar rapidamente os documentos mais relevantes para frases de pesquisa, com um modelo eficiente e escalável para aplicação em recuperação de informações.
