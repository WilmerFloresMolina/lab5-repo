#include "pieza.h"
#include <iostream>
#include <cstdlib>
#include <math.h>
#include <ncurses.h>
#include <fstream>

using std::cout;
using std::cin;
using std::cerr;
using std::endl;


void CreandoMatriz (char** m);
void llenadodelTablero (char** m);
void liberar_Memoria(char** m);
void Imprimir (char** m);

void jugador1 (char**m,char* movi);
int movimiento(char* movi);

void jugador2 (char**tablero,char* movi);
int ganador (char**tablero);


int main(int argc, char const *argv[]){

	char** tablero = new char*[8];
	char* movi = new char[5];
	CreandoMatriz(tablero);
	llenadodelTablero(tablero);
	bool jugando = true;
	int jugador =1;


	while (jugando){

		if(jugador==1){
			initscr();
			clear();
			clear();
			printw ("\n jugador 1\n");
			Imprimir (tablero);
			move (30,0);
			printw ("\n Ingrese la pieza a mover\n");
			getstr(movi);
			printw ("\n Hola\n");
			getch();
			
			clear();

		
			pieza x(movi);
			int validacion = movimiento(movi);
			refresh();
			mvprintw(0,0,"[%d] ",validacion);
			refresh();
			getch();
			if(validacion==1){
				clear();
				refresh();
				getch();
			//////////////////////////////////////	
				jugador1(tablero,movi);
				Imprimir (tablero);
				if(ganador (tablero)==1){
					clear(); 
					refresh();
					printw ("\n jugador1 gano :)\n");
					getch();


					jugando=false;

				}
				jugador=2;	
			}else{
				clear();
				move(31,0);
				printw ("\n movimiento invalido\n");

				getch();

			}
			getch();

		}


		if(jugador==2){
			initscr();
			clear();
			clear();
			printw ("\n jugador 2\n");
			Imprimir (tablero);
			move (30,0);
			printw ("\n Ingrese la pieza a mover\n");
			getstr(movi);
			printw ("\n Hola\n");
			getch();
			
			clear();
			pieza x(movi);
			int validacion = movimiento(movi);
			refresh();
			mvprintw(0,0,"[%d] ",validacion);
			refresh();
			getch();
			if(validacion==1){
				clear();
				refresh();
				getch();
			//////////////////////////////////////	
				jugador2(tablero,movi);
				Imprimir (tablero);
				if(ganador (tablero)==2){
					clear(); 
					refresh();
					printw ("\n jugador2 gano :)\n");
					getch();


					jugando=false;

				}
				jugador=1;	
			}else{
				clear();
				move(31,0);
				printw ("\n movimiento invalido\n");

				getch();

			}
			getch();

		}




	}
	
	initscr();
	clear();
	refresh();
	getch();
	Imprimir(tablero);
	getch();
	liberar_Memoria(tablero);
	endwin();

	
	return 0;
}


void CreandoMatriz (char** m){

	for (int i =0; i<8 ;i++){
		m[i]=new char[8];
	}
}


void llenadodelTablero (char** m){
	for(int i =0; i<8;i++){
		for(int j =0 ;j<8 ;j++){
			m[i][j]=' ';
		}

	}	

	m[0][1]='N';
	m[0][3]='N';
	m[0][5]='N';
	m[0][7]='N';
	m[1][0]='N';
	m[1][2]='N';
	m[1][4]='N';
	m[1][6]='N';
	m[2][1]='N';
	m[2][3]='N';
	m[2][5]='N';
	m[2][7]='N';


	m[7][0]='B';
	m[7][2]='B';
	m[7][4]='B';
	m[7][6]='B';
	m[6][1]='B';
	m[6][3]='B';
	m[6][5]='B';
	m[6][7]='B';
	m[5][0]='B';
	m[5][2]='B';
	m[5][4]='B';
	m[5][6]='B';

}


void liberar_Memoria(char** m){


	for(int i =0 ; i <8 ;i++){
		delete[] m[i];

	}

	delete[] m;

}


void Imprimir (char** m){
			

	printw( "  A   B   C   D   E   F   G   H");
	for(int i =0; i<8;i++){

		printw ("\n%d",i);
			for(int j =0 ;j<8 ;j++){

				printw ( "[%c] ", m[i][j] );
			}
		printw ("\n");
	}	

}

void jugador1 (char**tablero,char* movi){

	int x1 = movi[0]-65;
	int y1 = movi[1]-48;
	int x2 = movi[2]-65;
	int y2 = movi[3]-48;
	initscr();
	clear();
	refresh();
	mvprintw(0,0,"[%d] ",x1);
	mvprintw(1,0,"[%d] ",y1);
	mvprintw(2,0,"[%d] ",x2);
	mvprintw(3,0,"[%d] ",y2);
	getch();
	if(tablero[y2][x2]==' '){
		if(tablero[y1][x1]=='B'){
			int tempy =y2;
			int tempx = x2;

	        int cont =1;
	        try {

		      /*  if( (tablero[y2-1][x2-1]=='N')&& (cont=1)){
		        	tablero[y2][x2]='B';
		        	tablero[y2-1][x2-1]=' ';
		        	tablero[y1][x1]=' ';
		        	cont++;
		        }*/
		        if( (tablero[y2+1][x2+1]=='N')&& (cont=1)){
		        	tablero[y2][x2]='B';
		        	tablero[y2+1][x2+1]=' ';
		        	tablero[y1][x1]=' ';
		        	cont++;
		        }
		        if( (tablero[y2+1][x2-1]=='N')&& (cont=1)){
		        	tablero[y2][x2]='B';
		        	tablero[y2+1][x2-1]=' ';
		        	tablero[y1][x1]=' ';
		        	cont++;
		        }

		      /*  if( (tablero[y2-1][x2+1]=='N')&& (cont=1)){
		        	tablero[y2][x2]='B';
		        	tablero[y2-1][x2+1]=' ';
		        	tablero[y1][x1]=' ';
		        	cont++;
		        }*/

		    }catch (const char* msg) {
		    	cerr << msg << endl;
 			}
 			 if( (cont==1)){
		        	tablero[y2][x2]='B';
		        	tablero[y1][x1]=' ';

		    }



		}

	}






}

void jugador2 (char**tablero,char* movi){

	int x1 = movi[0]-65;
	int y1 = movi[1]-48;
	int x2 = movi[2]-65;
	int y2 = movi[3]-48;
	initscr();
	clear();
	refresh();
	mvprintw(0,0,"[%d] ",x1);
	mvprintw(1,0,"[%d] ",y1);
	mvprintw(2,0,"[%d] ",x2);
	mvprintw(3,0,"[%d] ",y2);
	getch();
	if(tablero[y2][x2]==' '){
		if(tablero[y1][x1]=='N'){
			int cont =1;
	        try {

		       if( (tablero[y2-1][x2-1]=='B')&& (cont=1)){
		        	tablero[y2][x2]='N';
		        	tablero[y2-1][x2-1]=' ';
		        	tablero[y1][x1]=' ';
		        	cont++;
		        }

		        if( (tablero[y2-1][x2+1]=='B')&& (cont=1)){
		        	tablero[y2][x2]='N';
		        	tablero[y2-1][x2+1]=' ';
		        	tablero[y1][x1]=' ';
		        	cont++;
		        }

		     }catch (const char* msg) {
		    	cerr << msg << endl;
 			}

 			if( (cont==1)){
		        	tablero[y2][x2]='N';
		        	tablero[y1][x1]=' ';

		    }




		}

	}


	





}

int movimiento(char* movi){
	int x1= 0;
	int x2= 0;
	int y1=0;
	int y2=0;
	x1 = movi[0]-65;
	y1 = movi[1]-48;
	x2 = movi[2]-65;
	y2 = movi[3]-48;
	int cordenadax = abs(x2-x1);
	int cordenaday = abs(y2-y1);
	int cordenadax2 = x2-x1;
	int cordenaday2 = y2-y1;
	if(cordenaday == cordenadax){
		return 1;
	}
	else{
		return 0;
	}
}

int ganador (char**tablero){
	int x =0;
	int cont =0;
	int cont2=0;
	for(int i =0;i<8;i++){
		for(int j=0;j<8;j++){
			if(tablero[i][j]=='B'){
				cont++;

			}


		}
	}
	if(cont==0){
		x=1;
	}

	for(int i =0;i<8;i++){
		for(int j=0;j<8;j++){
			if(tablero[i][j]=='N'){
				cont2++;

			}


		}
	}
	if(cont2==0){
		x=2;
	}

	return x;
}
