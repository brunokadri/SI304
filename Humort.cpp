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
		printf("A depress�o � coisa muito s�ria, cont�nua e complexa. Estar triste � estar atento a si pr�prio, � estar desapontado com algu�m, com v�rios ou consigo mesmo, � estar um pouco cansado de certas repeti��es, � descobrir-se fr�gil num dia qualquer, sem raz�o aparente - as raz�es t�m essa mania de serem discretas.\n");
	}
	else if((humor > 0.04) && (humor <= 0.08 ))
	{
		printf("As dificuldades da vida de maneira alguma servem pra ficarmos abalados, abatidos ou depressivos, mas devem servir de est�mulo para n�s vencermos e conquistarmos.\n");
	}
	else if((humor > 0.08) && (humor <= 0.16 ))
	{
		printf("Sorria para o espelho. Cuide-se. Ame-se!\n");
	}
	else if((humor > 0.16) && (humor <= 0.32 ))
	{
		printf("Volta teu rosto sempre na dire��o do sol e ent�o as sombras ficar�o para tr�s.\n");
	}
	return;
}

void dicas (int humor)
{
	if (humor <= 0.04)
	{
		printf("N�o pense que as pessoas n�o se importe com voc�, evite ficar perto de janelas e materiais cortantes, procure seu terapeuta imediatamente\n");
	}
	else if((humor > 0.04) && (humor <= 0.08 ))
	{
		printf("Saia um pouco da cama, converse com algu�m, evite ficar em lugares mal iluminados.\n");
	}
	else if((humor > 0.08) && (humor <= 0.16 ))
	{
		printf("Abrace alg�m hoje, tenha contato f�sico e social.\n");
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

printf("Ol� %s, vamos verificar o seu humor, por favor responda as perguntas a serguir: \n", nome);
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

printf("4 - A vida �?\n");
printf("1 - ...bonita, eh bonita e eh bonita!!\n 2 - ...boa na maior parte do tempo.\n 3 - ...feliz em certas circunstancias.\n 4 - ...um po�o de solidao.\n");
scanf("%d",&opc);
if((opc>4)||(opc<1)) {
	printf("N�o existe essa opcao, recomece o teste!");
	return 0;
}
else
	felicimometro+=escolha(opc,felicimometro);




printf("%s, escolha as informa��es que voc� deseja que sejam geradas: ");
printf("[1] Gr�fico\n");
printf("[2] Dicas\n");
printf("[3] Frase de autoajuda\n\n");

printf("Escolha uma das tr�s op��es, digite o seu n�mero correspondente e confira o que foi gerado!\n");
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


printf("Pronto! Voce terminou o teste, volte amanh�.\n");
	
return 0;
}
