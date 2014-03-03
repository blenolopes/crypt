/*
 * crypt v0.1b
 * -----------
 *
 * por  : bleno vinicius
 * www  : www.blenolopes.com
 *
 * .[ info ].
 *
 * Simples programa que usa o operador ~ para "criptografar"
 * caracteres em um arquivo em disco.
 * Compilado em FreeBSD 6.0 Release
 * Usando GCC 3.4.4
 * 
 * .[ compilando... ].
 *
 * ~$ gcc crypt.c -o crypt
 * ~$ ./crypt
 * ~$
 *
 */

//
// includes...
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//
// defines...
//

#define VERSION		"0.1 beta"

//
// funcoes...
//

void usage(void);
void crypt(void);
void error(const char *msg);

//
// int main(int argc, char *argv[]);
// -- funcao pricipal do programa, uso
//    de argumentos para controle de
//    fluxo em execucao!
//

int main(int argc, char *argv[]) {

	// variaveis...
	FILE *fp_origem;
	FILE *fp_destino;
	char c;

	// argumentos...
	if((argc > 3) || (argc == 1)) usage();
	
	printf("\n");
        printf("-- crypt %s\n", VERSION);
        printf("-- por: bleno vinicius\n");
        printf("-- mail : blenolopes@gmail.com\n");

	// controle dos arquivos...
	fp_origem  = fopen(argv[1], "r");
	if(!fp_origem) error("arquivo de origem nao encontrado!\n");

	fp_destino = fopen(argv[2], "w");
	if(!fp_destino) error("impossivel criar arquivo de destino!\n");

	// a besteira
	printf("\n[o] Processando... ");  
	while((c = fgetc(fp_origem)) != EOF) {
		fputc(~c, fp_destino);	// o tal '~'
	}
	printf("OK!\n\n");

	return 0;
}

//
// void usage(void);
// -- instrucoes para uso do programa.
//

void usage(void) {
	printf("\n");
	printf("-- crypt %s\n", VERSION);
	printf("-- por: bleno vinicius\n");
	printf("-- mail : blenolopes@gmail.com\n");
	printf("uso: crypt [origem] [destino]\n");
	printf("     * [origem]  : arquivo nao criptografado!\n");
	printf("     * [destino] : resultado da criptografia!\n");
	printf("\n");

	exit(0);
}

//
// void error(const char *msg);
// -- controle de erros gerados pelo programa,
//    uso de funcao propria para manter compatibilidade
//    entre S.O.'s e compiladores.
// 

void error(const char *msg) {
	printf("\n");
	printf("[o] ERROR: %s", msg);
	printf("\n");

	exit(1);
}

//
// _EOF_
// 23:10:12 em 15.06.2007
//
