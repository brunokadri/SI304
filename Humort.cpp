#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 500 /* tamanho maximo para a matriz
e, consequentemente, para a figura, em pixels)*/
int ma[max][max];
int i, j;

void autoajuda (int humor)
{
	if (humor <= 0.04)
	{
		printf("A depressão é coisa muito séria, contínua e complexa. Estar triste é estar atento a si próprio, é estar desapontado com alguém, com vários ou consigo mesmo, é estar um pouco cansado de certas repetições, é descobrir-se frágil num dia qualquer, sem razão aparente - as razões têm essa mania de serem discretas.\n");
	}
	else if((humor > 0.04) && (humor <= 0.08 ))
	{
		printf("As dificuldades da vida de maneira alguma servem pra ficarmos abalados, abatidos ou depressivos, mas devem servir de estímulo para nós vencermos e conquistarmos.\n");
	}
	else if((humor > 0.08) && (humor <= 0.16 ))
	{
		printf("Sorria para o espelho. Cuide-se. Ame-se!\n");
	}
	else if((humor > 0.16) && (humor <= 0.32 ))
	{
		printf("Volta teu rosto sempre na direção do sol e então as sombras ficarão para trás.\n");
	}
	return;
}

void dicas (int humor)
{
	if (humor <= 0.04)
	{
		printf("Não pense que as pessoas não se importe com você, evite ficar perto de janelas e materiais cortantes, procure seu terapeuta imediatamente\n");
	}
	else if((humor > 0.04) && (humor <= 0.08 ))
	{
		printf("Saia um pouco da cama, converse com alguém, evite ficar em lugares mal iluminados.\n");
	}
	else if((humor > 0.08) && (humor <= 0.16 ))
	{
		printf("Abrace algém hoje, tenha contato físico e social.\n");
	}
	else if((humor > 0.16) && (humor <= 0.32 ))
	{
		printf("Contagie mais pessoas com esse seu bom humor!\n");
	}
	return;
}
void desenhaBordas() {
	for(i=0;i<max;i++){
      	ma[0][i]=0;
        ma[max-1][i]=0;
        ma[i][0]=0;
        ma[i][max-1]=0;
    }
    return;
}

void luznofimdotunel (float luz) {

for(i=0;i<max;i++) {
	for(j=0;j<max;j++) {
		if(i>j)
			ma[i][j] = 1;
		else if (i<luz*j)
			ma[i][j]=1;
		else 
			ma[i][j]=0;		
		}
	}
	return;
}
void salvaluz() {

	FILE * fp;
	fp = fopen("luznofimdotunel.pbm","w");
	fprintf(fp,"P1\n");
    fprintf(fp,"%d %d\n",max,max);
	for(i=0;i<max;i++) {
		for(j=0;j<max;j++) {
		fprintf(fp,"%d", ma[i][j]);
		}
	fprintf(fp,"\n");
	}
	return;
}
float escolha(int opcao, float termometro) {
	switch (opcao) {
		case 1:
			termometro=termometro+0.01;
			break;
		case 2:
			termometro+=0.02;
			break;
		case 3: 
			termometro+=0.04;
			break;
		case 4:
			termometro+=0.05;
			break;
				
	}
	return termometro;
}



int main(){
int opc, menugera;
float felicimometro=0.0;
char nome[20];

printf("Digite seu nome: ");
scanf("%s",&nome);

printf("Olá %s, vamos verificar o seu humor, por favor responda as perguntas a serguir: \n", nome);
printf("Vamos comecar!\n");
printf("1 - Voce ja sorriu hoje?\n");
printf(" 1 - Sim, mais de uma vez!\n 2 - Sim, uma vez!\n 3 - Talvez uma vez, sei la :(\n 4 - Nao costumo sorrir.\n");
scanf("%d",&opc);
if((opc>4)||(opc<1)) {
	printf("Nao existe essa opcao, recomece o teste!");
	return 0;
}
else
	felicimometro+=escolha(opc,felicimometro);

printf("2 - Quantas pessoas voce abracou hoje?\n");
printf("1 - Quatro ou mais!\n 2 - Duas ou tres\n 3 - Abracei minha vozinha no natal passado, vale?\n 4 - Nao gosto de abracos.\n");
scanf("%d",&opc);
if((opc>4)||(opc<1)) {
	printf("Nao existe essa opcao, recomece o teste!");
	return 0;
}
else
	felicimometro+=escolha(opc,felicimometro);

printf("3 - Como esta o dia hoje?\n");
printf("1 - Muito bonito, bom pra passear la fora\n 2 - Eh, ate que esta bom.\n 3 - Ontem estava melhor.\n 4 - Nao sei, nao sair pra ver\n");
scanf("%d",&opc);
if((opc>4)||(opc<1)) {
	printf("Nao existe essa opcao, recomece o teste!");
	return 0;
}
else
	felicimometro+=escolha(opc,felicimometro);

printf("4 - A vida é?\n");
printf("1 - ...bonita, eh bonita e eh bonita!!\n 2 - ...boa na maior parte do tempo.\n 3 - ...feliz em certas circunstancias.\n 4 - ...um poço de solidao.\n");
scanf("%d",&opc);
if((opc>4)||(opc<1)) {
	printf("Não existe essa opcao, recomece o teste!");
	return 0;
}
else
	felicimometro+=escolha(opc,felicimometro);




printf("%s, escolha as informações que você deseja que sejam geradas: ");
printf("[1] Gráfico\n");
printf("[2] Dicas\n");
printf("[3] Frase de autoajuda\n\n");

printf("Escolha uma das três opções, digite o seu número correspondente e confira o que foi gerado!\n");
scanf("%d",&menugera);

switch (menugera)
{
	case 1:
		desenhaBordas();
		luznofimdotunel(felicimometro);
		salvaluz();
		break;
	case 2:
		dicas(felicimometro);
		break;
	case 3:
		autoajuda(felicimometro);
		break;		
}


printf("Pronto! Voce terminou o teste, volte amanhã.\n");
	
return 0;
}
