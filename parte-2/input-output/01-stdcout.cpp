#include <iostream>

// existem variaveis pre defininidas, a primeira que vamos conhecer é a std::cout
// em C++, podemos sobrecarregar operadores, por exemplo, podemos determinar o que acontece ao somar pessoa + pessoa
// o mesmo aconteceu para determinar o que acontece quando usamos std::cout com o operador << e uma string

int main() {

    std::cout << "Hello World!";

    // também foi determinado o que acontece quando somamos essa variavel a diferenes tipos

    std::cout << 4; // aqui temos um inteiro

    // claro que também podemos utilizar variaveis ao inves de literais, no exemplo anterior temos um literal inteiro

    int idade = 20;
    std::cout << idade;

    // Agora vamos ver o que acontece quando usamos o std::cout seguido de duas strings com o operador <<
    // nesse caso como estamos usando o mesmo operador varias vezes, a precedencia é da esquerda para direita
    // isso acontece sem problemas pois o que está entre parenteses retorna uma referência para o std::cout
    // então depois de imprimir "Hello" o operador << é chamado novamente com o std::cout para imprimir a string " World!"

    //(std::cout << "Hello" )<< " World!";
    std::cout << "Hello" << " World!";

    // tente analisar e compreender o exemplo abaixo
    int x{ 5 };
    std::cout << "x is equal to: " << x;

    // tudo que fizemos até agora não utilizou nenhuma quebra de linha, e poderiamos fazer uso do caractere de escape \n, mas o C++ nos fornece outra forma de fazer isso. Vamos comparar as duas
    // ambas produzem o mesmo resultado, mas a std::endl faz duas coisas, ela quebra a linha e também limpa o buffer de saída
    // aqui vale a gente pensar na variavel std::cout como um metrô, que passa de tempo em tempo, e pega todos os passageiros até o seu limite máximo
    // quando o metrô fica cheio, ele sai sai da estação com todos os passageiros e imprime tudo que estava no metrô
    // porém se o metrô não encher, ele pode demorar para sair da estação
    // é ai que o std::endl entra, ele força o metrô a sair da estação, mesmo que não esteja cheio
    // isso pode ser util em alguns casos, mas também pode ser um problema, pois se cada passageiro forçar o metro a sair da estação, ele vai sempre viajar vazio, o que não é eficiente
    // por isso vamos dar preferência por utilizar \n

    std::cout << "Hello World!\n";
    std::cout << "Hello World!" << std::endl;

    return 0;
}