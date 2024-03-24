#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//area de declaração
void menu();
void coletarRespostas();
void bilheteria();
void questionarioTema1();
void questionarioTema2();
void questionarioTema3();
void questionarioTema4();
void pagamento();

int main(){
    // variavel que armazena a escolha do tema
    int escolha;
    // chamada do menu
    menu();
    printf("escolha qual obra acessar (usando os numeros correspondentes).\n");
    scanf("%d", &escolha);

    //estrutura para decidir qual tema foi selecionado e mostrar a descriçao do tema
    switch (escolha)
    {
    case 1:
      bilheteria();
        printf("100 anos da Semana de Arte Moderna e uma exposicao comemorativa que celebra o centenario da Semana de Arte Moderna de 1922, um evento historico que marcou profundamente o cenario artistico e cultural do Brasil. Essa semana, que ocorreu entre 11 e 18 de fevereiro de 1922, na cidade de São Paulo, foi um marco na história da arte brasileira, pois introduziu movimentos artísticos vanguardistas e provocou uma mudança significativa na maneira como a arte era concebida e apreciada no país.\n\n");
      questionarioTema1();
        break;
    case 2:
      bilheteria();
        printf("150 Anos de Santos Dumont e uma exposicao comemorativa que celebra o 150 aniversario do nascimento de Alberto Santos - Dumont, um dos mais notaveis ??inventores e pioneiros da aviacao.\n\n");
      questionarioTema2();
        break;
    case 3:
      bilheteria();
        printf("Os Jogos Olimpicos de Paris 2024 representam um evento esportivo global de importancia excepcional. A cidade de Paris, que ja sediou as Olimpiadas em 1900 e 1924, tera a honra de receber novamente atletas de todo o mundo para esta competicao marcante.\n\n");
      questionarioTema3();
        break;
    case 4:
      bilheteria();
        printf("As mudanças climaticas referem-se às alteracoes de longo prazo nos padroes climaticos da Terra, particularmente as tendências em temperaturas medias globais e regionais, padroes de precipitacao, eventos climaticos extremos e outros fatores relacionados ao clima. Essas mudancas climaticas tem sido um tema central de discussao nas ultimas decadas devido ao aumento das evidencias cientificas que apontam para um aquecimento global induzido pelas atividades humanas.\n\n");
      questionarioTema4();
        break;
      //se o usuario adicionar um valo inexisteste o programa reseta e faz novamente a pergunta
    default:
        printf("\nERRO:CARACTER INCOMPATIVEL\n\n");//retorna um erro se o usario digitar um valor invalido
      getchar();
      main();


    }

  coletarRespostas();
  printf("REINICIANDO EM 3.2.1.\n");
  main(); //faz o terminal não fechar

  return 0;

}

// menu principal
void menu() {
    printf("\n");
    system("color A");    //system(“color XY”);

    printf("\t   ####   ####  ##     ##  #######   ########  ##     ##\n");
    printf("\t   ## ## ## ##  ##     ##  ##        ##        ##     ##\n");
    printf("\t   ##   #   ##  ##     ##  ########  ########  ##     ##\n");
    printf("\t   ##       ##  ##     ##        ##  ##        ##     ##\n");
    printf("\t   ##       ##  ##     ##        ##  ##        ##     ##\n");
    printf("\t   ##       ##  #########  ########  ########  #########\n\n");


    printf("           ======================SEJA BEM VINDO=================\n\n");
    printf("1) 100 anos da semana de arte moderna.\n");
    printf("2) 150 anos de Santos Dumont\n");
    printf("3) Jogos olimpicos de Paris 2024\n");
    printf("4) Mudancas Climaticas\n\n");

}
// Função para coletar respostas dos visitantes
void coletarRespostas() {
  char palavras[30] = "";
  int numero;

    printf("-------------------------AVALIE A OBRA-------------------------\n");
    printf("4) EXCELENTE\n");
    printf("3) OTIMO\n");
    printf("2) BOM\n");
    printf("1) RUIM\n");

  printf("Deixe o seu feedback da obra: ");
      scanf("%d", &numero);

  switch (numero) {
    case 1:
      printf("Obra avaliada como: RUIM\n");
      strcpy(palavras,"RUIM");
      break;
    case 2:
      printf("Obra avaliada como: BOM\n");
      strcpy(palavras,"BOM");
      break;
    case 3:
      printf("Você escolheu: OTIMO\n");
      strcpy(palavras,"OTIMO");
      break;
    case 4:
      printf("Obra avaliada como: EXCELENTE\n");
      strcpy(palavras,"EXCELENTE");
      break;
    default:
      printf("ERRO:(Numero invalido)\n");
  }

  FILE *file;
  file = fopen("avaliacoes.csv", "a");

  if(file == NULL){
    printf("Arquivo nao pode ser aberto\n");
    exit(1);
  }

  fputs(palavras, file);

  fclose(file);

  }
  // Função para gerar bilheteria
  void bilheteria(){   // valor dos ingressos
      float entrada = 80, meia_entrada = 40, isencao = 0;
      float quant = 0;
      char pag;
      int test;
      printf("================BILHETERIA================\n");
      printf("Entrada Cheia:R$%0.2f Adultos\nMeia Entrada:R$%0.2f Estudantes\nIsencao:R$%0.2f Criancas ate 6 anos e idosos a partir de 60 anos\n\n",entrada, meia_entrada, isencao);
      printf("Quantidade de ingressos para Entrada cheia:");
      scanf("%f", &quant);
      test = quant;
    if(test == quant){
    entrada = entrada * quant;
    } else{
      bilheteria();
      getchar();
    }

      printf("Quantidade de ingressos para Meia entrada:");
      scanf("%f", &quant);
      meia_entrada = meia_entrada * quant;
      printf("Quantidade de ingressos para Isencao:");
      scanf("%f", &quant);
      isencao = isencao * quant;
      quant = entrada + meia_entrada; //nessa linha a var quant deixa de ser a quantidade de ingressos e vira o total das entradas
    printf("Valor Total:R$%0.2f\n",quant);

    printf("Pressione [D] para pagamento com [DEBITO]\n");
    printf("Pressione [C] para pagamento com [CREDITO]\n");
    printf("Pressione [P] para pagamento com [PIX]\n");
    printf("Pressione [R] para pagamento com [DINHEIRO]\n");
    scanf("%s", &pag);
    if(pag == 'D' || pag =='d' || pag =='c'|| pag =='C' || pag =='p' || pag =='P' || pag =='R' || pag =='r'){
      printf("COMPRA COMFIRMADA COM SUCESSO.\n");
    printf("APROVEITE A OBRA!\n\n\n");
    }else{
      printf("ERRO, VOLTARNDO A BILHETERIA\n");
      bilheteria();
      getchar();
    }

  }

  // Função para gerar um questionario do tema 1
  void questionarioTema1() {
      //variavel para guardar as respostas
      int r1 = 0;
      int r2 = 0;
      int r3 = 0;
      int r4 = 0;
      int r5 = 0;
      int con;

      int acertos = 0;

      printf("PREENCHA O QUESTIONARIO ABAIXO:\n\n");

      printf("1-Quando ocorreu a Semana de Arte Moderna de 1922?\n");
      printf("[1] Em 1910.\n");
      printf("[2] Em 1922.\n");
      printf("[3] Em 1930.\n");
      printf("[4] Em 1940.\n");
      scanf("%d", &r1);
    // switch que soma 2 pontos para cada resposta correta
    switch(r1){
      case 1:
        acertos = acertos +0;
      break;
      case 2:
        acertos = acertos + 2;
      break;
      case 3:
        acertos = acertos +0;
      break;
      case 4:
        acertos = acertos +0;
      break;
      default:
        printf("ERRO, TENTE NOVAMENTE.\n");
      main();
      break;
    }
      printf("2-Qual cidade brasileira sediou a Semana de Arte Moderna de 1922?\n");
      printf("[1] Rio de Janeiro.\n");
      printf("[2] São Paulo.\n");
      printf("[3] Belo Horizonte.\n");
      printf("[4] Salvador.\n");
      scanf("%d", &r2);
    switch(r2){
      case 1:
        acertos = acertos +0;
      break;
      case 2:
        acertos = acertos + 2;
      break;
      case 3:
        acertos = acertos +0;
      break;
      case 4:
        acertos = acertos +0;
      break;
      default:
        printf("ERRO, TENTE NOVAMENTE.\n");
      main();
      break;
    }
      printf("3-Qual foi o objetivo principal da Semana de Arte Moderna de 1922?\n");
      printf("[1] Promover a arte tradicional.\n");
      printf("[2] Celebrar a arte classica.\n");
      printf("[3] Romper com as tradicoes artisticas e promover a modernidade.\n");
      printf("[4] Destacar o realismo na arte.\n");
      scanf("%d", &r3);
    switch(r3){
      case 1:
        acertos = acertos +0;
      break;
      case 2:
        acertos = acertos + 0;
      break;
      case 3:
        acertos = acertos +2;
      break;
      case 4:
        acertos = acertos +0;
      break;
      default:
        printf("ERRO, TENTE NOVAMENTE.\n");
      main();
      break;
    }
      printf("4-Quem foi um dos artistas e escritores notaveis que participaram da Semana de Arte Moderna de 1922?\n");
      printf("[1] Leonardo da Vinci.\n");
      printf("[2] Machado de Assis.\n");
      printf("[3] Tarsila do Amaral.\n");
      printf("[4] Vincent van Gogh.\n");
      scanf("%d", &r4);
    switch(r4){
      case 1:
        acertos = acertos +0;
      break;
      case 2:
        acertos = acertos + 0;
      break;
      case 3:
        acertos = acertos +2;
      break;
      case 4:
        acertos = acertos +0;
      break;
      default:
        printf("ERRO, TENTE NOVAMENTE.\n");
      main();
      break;
    }
      printf("5-Qual movimento artistico influenciou a Semana de Arte Moderna de 1922?\n");
      printf("[1] Renascimento.\n");
      printf("[2] Impressionismo.\n");
      printf("[3] Cubismo.\n");
      printf("[4] Barroco.\n");
      scanf("%d", &r5);
    switch(r5){
      case 1:
        acertos = acertos +0;
      break;
      case 2:
        acertos = acertos + 0;
      break;
      case 3:
        acertos = acertos +2;
      break;
      case 4:
        acertos = acertos +0;
      break;
      default:
        printf("ERRO, TENTE NOVAMENTE.\n");
      main();
      break;
    }
      //lógica real de análise de respostas aqui
       printf("Nota:%d/10\n ", acertos);

      /*Respostas:

  b) Em 1922.
  b) São Paulo.
  c) Romper com as tradições artísticas e promover a modernidade.
  c) Tarsila do Amaral.
  c) Cubismo.*/
  }
  // Função para gerar um questionario do tema 2
  void questionarioTema2() {
      //variavel para guardar as respostas
      int r1, r2, r3, r4, r5;
      int acertos = 0;
      printf("PREENCHA O QUESTIONARIO ABAIXO:\n\n");
      printf("1-Quando ocorre o 150 aniversario do nascimento de Santos Dumont?\n");
      printf("[1] 2022.\n");
      printf("[2] 2023.\n");
      printf("[3] 2024.\n");
      printf("[4] 2025.\n");
      scanf("%d", &r1);
    switch(r1){
      case 1:
        acertos = acertos +2;
      break;
      case 2:
        acertos = acertos + 0;
      break;
      case 3:
        acertos = acertos +0;
      break;
      case 4:
        acertos = acertos +0;
      break;
      default:
        printf("ERRO, TENTE NOVAMENTE.\n");
      main();
      break;
    }
      printf("2-Qual pais é conhecido como o local de nascimento de Santos Dumont?\n");
      printf("[1] Brasil.\n");
      printf("[2] Franca.\n");
      printf("[3] Estados Unidos.\n");
      printf("[4] Reino Unido.\n");
      scanf("%d", &r2);
    switch(r2){
      case 1:
        acertos = acertos +2;
      break;
      case 2:
        acertos = acertos + 0;
      break;
      case 3:
        acertos = acertos +0;
      break;
      case 4:
        acertos = acertos +0;
      break;
      default:
        printf("ERRO, TENTE NOVAMENTE.\n");
      main();
      break;
    }
      printf("3-Qual e a principal contribuição de Santos Dumont para a aviacao?\n");
      printf("[1] Desenvolvimento do primeiro aviao a jato.\n");
      printf("[2] Criacao do primeiro dirigivel controlavel.\n");
      printf("[3] Invencao do helicoptero.\n");
      printf("[4] Construcao do primeiro aviao de papel.\n");
      scanf("%d", &r3);
    switch(r3){
      case 1:
        acertos = acertos +0;
      break;
      case 2:
        acertos = acertos + 2;
      break;
      case 3:
        acertos = acertos +0;
      break;
      case 4:
        acertos = acertos +0;
      break;
      default:
        printf("ERRO, TENTE NOVAMENTE.\n");
      main();
      break;
    }
      printf("4-Qual aeronave ficou famosa pelo voo do 14-Bis de Santos Dumont?\n");
      printf("[1] Demoiselle.\n");
      printf("[2] 14-Bis.\n");
      printf("[3] Spirit of St. Louis.\n");
      printf("[4] Wright Flyer.\n");
      scanf("%d", &r4);
    switch(r4){
      case 1:
        acertos = acertos +0;
      break;
      case 2:
        acertos = acertos + 2;
      break;
      case 3:
        acertos = acertos +0;
      break;
      case 4:
        acertos = acertos +0;
      break;
      default:
        printf("ERRO, TENTE NOVAMENTE.\n");
      main();
      break;
    }
      printf("5-Qual e a designacao oficial do titulo que Santos Dumont ganhou da Federacao Aeronautica Internacional (FAI) por seus feitos pioneiros?\n");
      printf("[1] Premio Nobel da Fisica.\n");
      printf("[2] Pai da Aviacao.\n");
      printf("[3] Ordem do Merito Aeronautico.\n");
      printf("[4] Membro Honorario da NASA.\n");
      scanf("%d", &r5);
    switch(r5){
      case 1:
        acertos = acertos +0;
      break;
      case 2:
        acertos = acertos + 2;
      break;
      case 3:
        acertos = acertos +0;
      break;
      case 4:
        acertos = acertos +0;
      break;
      default:
        printf("ERRO, TENTE NOVAMENTE.\n");
      main();
      break;
    }
    //lógica real de análise de respostas aqui
     printf("Nota:%d/10\n ", acertos);

      /*Respostas:

  a) 2022
  a) Brasil
  b) Criação do primeiro dirigível controlável
  b) 14-Bis
  b) Pai da Aviação*/

  }
  // Função para gerar um questionario do tema 3
  void questionarioTema3() {
      //variavel para guardar as respostas
      int r1, r2, r3, r4, r5;
      int acertos = 0;
      printf("PREENCHA O QUESTIONARIO ABAIXO:\n\n");
      printf("1-Onde serao realizados os Jogos Olimpicos de Paris 2024?\n");
      printf("[1] Paris, Franca.\n");
      printf("[2] Londres, Reino Unido.\n");
      printf("[3] Los Angeles, EUA.\n");
      printf("[4] Rio de Janeiro, Brasil.\n");
      scanf("%d", &r1);
    switch(r1){
      case 1:
        acertos = acertos +2;
      break;
      case 2:
        acertos = acertos + 0;
      break;
      case 3:
        acertos = acertos +0;
      break;
      case 4:
        acertos = acertos +0;
      break;
      default:
        printf("ERRO, TENTE NOVAMENTE.\n");
      main();
      break;
    }
      printf("2-Qual e a data de inicio prevista para os Jogos Olimpicos de Paris 2024?\n");
      printf("[1] Julho de 2022.\n");
      printf("[2] Agosto de 2023.\n");
      printf("[3] Julho de 2024.\n");
      printf("[4] Agosto de 2024.\n");
      scanf("%d", &r2);
    switch(r2){
      case 1:
        acertos = acertos +0;
      break;
      case 2:
        acertos = acertos + 0;
      break;
      case 3:
        acertos = acertos +2;
      break;
      case 4:
        acertos = acertos +0;
      break;
      default:
        printf("ERRO, TENTE NOVAMENTE.\n");
      main();
      break;
    }
      printf("3-Qual esporte fara sua estreia olimpica nos Jogos de Paris 2024?\n");
      printf("[1] Basquete.\n");
      printf("[2] Skate park.\n");
      printf("[3] Natacao sincronizada.\n");
      printf("[4] Esgrima.\n");
      scanf("%d", &r3);
    switch(r3){
      case 1:
        acertos = acertos +0;
      break;
      case 2:
        acertos = acertos + 2;
      break;
      case 3:
        acertos = acertos +0;
      break;
      case 4:
        acertos = acertos +0;
      break;
      default:
        printf("ERRO, TENTE NOVAMENTE.\n");
      main();
      break;
    }
      printf("4-Qual e o nome da mascote oficial dos Jogos Olimpicos de Paris 2024?\n");
      printf("[1] Pierre.\n");
      printf("[2] Remi.\n");
      printf("[3] Jules.\n");
      printf("[4] Celine.\n");
      scanf("%d", &r4);
    switch(r4){
      case 1:
        acertos = acertos +2;
      break;
      case 2:
        acertos = acertos + 0;
      break;
      case 3:
        acertos = acertos +0;
      break;
      case 4:
        acertos = acertos +0;
      break;
      default:
        printf("ERRO, TENTE NOVAMENTE.\n");
      main();
      break;
    }
      printf("5-O que a cidade de Paris sediou pela ultima vez antes dos Jogos de 2024?\n");
      printf("[1] Copa do Mundo de Futebol.\n");
      printf("[2] Jogos Olimpicos de Verao.\n");
      printf("[3] Jogos Olimpicos de Inverno.\n");
      printf("[4] Copa do Mundo de Rugby.\n");
      scanf("%d", &r5);
    switch(r5){
      case 1:
        acertos = acertos +0;
      break;
      case 2:
        acertos = acertos + 2;
      break;
      case 3:
        acertos = acertos +0;
      break;
      case 4:
        acertos = acertos +0;
      break;
      default:
        printf("ERRO, TENTE NOVAMENTE.\n");
      main();
      break;
    }
    //lógica real de análise de respostas aqui
     printf("Nota:%d/10\n ", acertos);

      /*Respostas:

  a) Paris, França
  c) Julho de 2024
  b) Skate park
  a) Pierre
  b) Jogos Olímpicos de Verão*/


  }
  // Função para gerar um questionario do tema 4
  void questionarioTema4() {
      //variavel para guardar as respostas
      int r1, r2, r3, r4, r5;
      int acertos = 0;
      printf("PREENCHA O QUESTIONARIO ABAIXO:\n\n");
      printf("1-O que causa as mudanças climaticas globais?\n");
      printf("[1] Atividade vulcanica.\n");
      printf("[2] A inclinacao do eixo da Terra.\n");
      printf("[3] A emissao de gases de efeito estufa de origem humana.\n");
      printf("[4] Mudancas na orbita da Terra.\n");
      scanf("%d", &r1);
    switch(r1){
      case 1:
        acertos = acertos +0;
      break;
      case 2:
        acertos = acertos + 0;
      break;
      case 3:
        acertos = acertos +2;
      break;
      case 4:
        acertos = acertos +0;
      break;
      default:
        printf("ERRO, TENTE NOVAMENTE.\n");
      main();
      break;
    }
      printf("2-Qual e o principal gas de efeito estufa liberado pela atividade humana?\n");
      printf("[1] Oxigenio (O2).\n");
      printf("[2] Nitrogenio (N2).\n");
      printf("[3] Dioxido de carbono (CO2).\n");
      printf("[4] Metano (CH4).\n");
      scanf("%d", &r2);
    switch(r2){
      case 1:
        acertos = acertos +0;
      break;
      case 2:
        acertos = acertos + 0;
      break;
      case 3:
        acertos = acertos +2;
      break;
      case 4:
        acertos = acertos +0;
      break;
      default:
        printf("ERRO, TENTE NOVAMENTE.\n");
      main();
      break;
    }
      printf("3-Qual e o impacto das mudancas climaticas na elevacao do nivel do mar?\n");
      printf("[1] Reducao do nivel do mar.\n");
      printf("[2] Estabilidade do nivel do mar.\n");
      printf("[3] Aumento do nivel do mar devido ao derretimento das calotas de gelo e expansao termica da agua do mar.\n");
      printf("[4] Aumento do nível do mar devido à escassez de agua doce.\n");
      scanf("%d", &r3);
    switch(r3){
      case 1:
        acertos = acertos +0;
      break;
      case 2:
        acertos = acertos + 0;
      break;
      case 3:
        acertos = acertos +2;
      break;
      case 4:
        acertos = acertos +0;
      break;
      default:
        printf("ERRO, TENTE NOVAMENTE.\n");
      main();
      break;
    }
      printf("4-Quais sao alguns dos efeitos das mudanças climaticas no meio ambiente?\n");
      printf("[1] Diminuição das ondas de calor.\n");
      printf("[2] Aumento na biodiversidade.\n");
      printf("[3] Acidificacao dos oceanos.\n");
      printf("[4] Diminuicao das tempestades e furacoes.\n");
      scanf("%d", &r4);
    switch(r4){
      case 1:
        acertos = acertos +0;
      break;
      case 2:
        acertos = acertos + 0;
      break;
      case 3:
        acertos = acertos +2;
      break;
      case 4:
        acertos = acertos +0;
      break;
      default:
        printf("ERRO, TENTE NOVAMENTE.\n");
      main();
      break;
    }
      printf("5-O que os Acordos de Paris visam alcancar em relacao às mudancas climaticas?\n");
      printf("[1] Aumentar as emissoes de gases de efeito estufa\n");
      printf("[2] Manter o aquecimento global abaixo de 1,5 graus Celsius em relacao aos niveis pre-industriais.\n");
      printf("[3] Promover o uso intensivo de combustiveis fosseis.\n");
      printf("[4] Ignorar os desafios das mudanças climaticas.\n");
      scanf("%d", &r5);
    switch(r5){
      case 1:
        acertos = acertos +0;
      break;
      case 2:
        acertos = acertos + 2;
      break;
      case 3:
        acertos = acertos +0;
      break;
      case 4:
        acertos = acertos +0;
      break;
      default:
        printf("ERRO, TENTE NOVAMENTE.\n");
      main();
      break;
    }
     printf("Nota:%d/10\n ", acertos);

      /*Respostas:

  c) A emissão de gases de efeito estufa de origem humana
  c) Dióxido de carbono (CO2)
  c) Aumento do nível do mar devido ao derretimento das calotas de gelo e expansão térmica da água do mar
  c) Acidificação dos oceanos
  b) Manter o aquecimento global abaixo de 1,5 graus Celsius em relação aos níveis pré-industriais*/

  }
