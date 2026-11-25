#include <iostream>

int main() {

    // agora vamos falar sobre o std::cin que é uma variavel pre definida que nos permite ler dados do teclado
    // ela é do tipo std::istream, só que ao invés do operador << vamos utilizar o operador >>, que aqui é ocnhecido como operador de extração
    // esse operador nos permite ler dados de diferentes tipos, como inteiros, strings, etc, e armazenar esses dados em variaveis
    // a diferença nesses operadores provavelmente foi pensada para facilitar a leitura do código, facilitando a diferenciação entre o que é saida e o que é entrada de dados

    int idade;
    std::cout << "Digite sua idade: ";
    std::cin >> idade;
    std::cout << "Sua idade é: " << idade << std::endl;

    // claro, podemos também utilizar a std::cin para ler mais de um dado
    std::cout << "Digite dois numeros separados por espaco: ";
    int a, b;
    std::cin >> a >> b;
    std::cout << "Os numeros digitados foram: " << a << " e " << b << '\n';

    // diferentemente do scanf do C, nós não precisamos informar o tipo do dado que vamos ler, porque o compilador determina isso automaticamente, baseado no tipo da variavel que estamos utilizando para armazenar o dado lido

    // nós vimos que o processo de saida de dados é na verdade realizado em 2 etapas, primeiro o dado é armazenado em um buffer, e depois esse buffer é esvaziado, imprimindo o dado na tela
    // o std::cin também utiliza um buffer, mas nesse caso o buffer é preenchido com dados do terminal, e o buffer é esvaziado quando o usuário aperta a tecla enter
    // isso afeta como o codigo abaixo funciona

    std::cout << "Digite dois numeros: ";
    int x;
    std::cin >> x;
    int y;
    std::cin >> y;

    // ao executar o codigo acima, se o usuário digitar "4\n" o buffer do std::cin vai conter o caractere '4' e o caractere '\n', que é o caractere de quebra de linha
    // então o std::cin vai ler o caractere '4' do buffer e armazenar na variavel x, e o caractere '\n' fica lá, a limpeza de buffer não acontece automaticamente
    // depois o usuário vai digitar "5\n", quando der enter, o buffer vai receber o caractere '5' e o caractere '\n', ficando com o conteudo "\n5\n"
    // e então o std::cin vai ler o buffer, para encontrar o que deve ser armazenado na variavel y
    // mas o '\n' não atraplha pois existe uma regra do operador >> que sempre ignora e descarta os espaços em branco iniciais (' ', '\t', '\n'), então o std::cin vai descartar o '\n' e ler o '5' e armazenar na variavel y

    // agora vamos analisar o que acontece se o usuário digitar "4 5\n", nesse caso o buffer vai receber o conteudo "4 5\n", e o std::cin vai ler o '4' e armazenar na variavel x, e depois vai ignorar o espaço em branco, ler o '5' e armazenar na variavel y
    // o que é importante notar é que o segundo std::cin não vai esperar o usuário fornecer uma entrada, ele vai direto no buffer
    // isso acontece, quando realizamos essa operaçõa o buffer é analisado, e havendo dados no buffer eles são lidos, se o buffer estiver vazio, ou só contiver caracteres que são ignorados, o std::cin vai esperar o usuário fornecer uma entrada

    return 0;
}