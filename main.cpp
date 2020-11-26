/*Segunda Avaliação de Computação Grafica –2020-2
//Professora: Catiúscia Borges
// Turma: 161
// Integrantes do grupo:
// Nome 01: Camila Silveira de Mendonça - 2017201332
*/
#include <GL/glut.h>
#include <stdio.h>
#include <cmath>
int objeto = 0;
float R = 0.35 , G = 0.75 , B = 0.55 ;
float xU = 50, xD = 350, xT = 350, xQ = 50, yU = 50, yD = 50, yT = 350, yQ = 350;
float dx = 200, dy = 200, r=150;

void LayoutTela (){
	//controle das cores     
	glBegin(GL_QUADS);
	//preto
		glColor3f(0 ,0 ,0); 
		glVertex2f( 400, 0);
		glVertex2f( 500, 0);
		glVertex2f( 500, 100);
		glVertex2f( 400, 100);
		
	//cinza
		glColor3f(0.5 ,0.5 ,0.5); 
		glVertex2f( 500, 0);
		glVertex2f( 600, 0);
		glVertex2f( 600, 100);
		glVertex2f( 500, 100);		
	
	//branco
		glColor3f(1 ,1 ,1); 
		glVertex2f( 600, 0);
		glVertex2f( 700, 0);
		glVertex2f( 700, 100);
		glVertex2f( 600, 100);		
	
	//vermelho
		glColor3f(1 ,0 ,0); 
		glVertex2f( 400, 100);
		glVertex2f( 500, 100);
		glVertex2f( 500, 200);
		glVertex2f( 400, 200);		
	
	//verde
		glColor3f(0 , 1 ,0); 
		glVertex2f( 500, 100);
		glVertex2f( 600, 100);
		glVertex2f( 600, 200);
		glVertex2f( 500, 200);		
	
	//azul
		glColor3f(0 ,0 ,1); 
		glVertex2f( 600, 100);
		glVertex2f( 700, 100);
		glVertex2f( 700, 200);
		glVertex2f( 600, 200);		
	
	//ciano
		glColor3f(0, 1, 1); 
		glVertex2f( 400, 200);
		glVertex2f( 500, 200);
		glVertex2f( 500, 300);
		glVertex2f( 400, 300);		
	
	//magenta
		glColor3f(1 ,0 ,1); 
		glVertex2f( 500, 200);
		glVertex2f( 600, 200);
		glVertex2f( 600, 300);
		glVertex2f( 500, 300);		
	
	//amarelo
		glColor3f(1 ,1 ,0); 
		glVertex2f( 600, 200);
		glVertex2f( 700, 200);
		glVertex2f( 700, 300);
		glVertex2f( 600, 300);
		
	glEnd();
	
	glColor3f(0.5,0.5,0.5);
	//quadrado
	glBegin(GL_QUADS);
		glVertex2f( 420, 320);
		glVertex2f( 480, 320);
		glVertex2f( 480, 380);
		glVertex2f( 420, 380);
	glEnd();
	
	//triangulo
	glBegin(GL_TRIANGLES);
		glVertex2f( 580, 320);
		glVertex2f( 580, 380);
		glVertex2f( 520, 380);
	glEnd();
	
	//círculo
	float x , y;
	glBegin(GL_LINES);
	for(x = -30 ; x <= 30 ; x++){
		y = pow( (30*30 - x*x) , 0.5 );
		glVertex2f( x + 650, y + 350);
		glVertex2f( x + 650, -y + 350);
	}
	glEnd();
	
	//contorno da area de desenho 
	glLineWidth(5);
	glColor3f(0,0,0);
	
	glBegin(GL_LINE_LOOP);
		glVertex2f( 0, 400);
		glVertex2f( 0, 0);
		glVertex2f( 400, 0);
		glVertex2f( 400, 400);
	glEnd();
	
	//contorno da area de controle
	glBegin(GL_LINE_STRIP);
		glVertex2f( 400, 0);
		glVertex2f( 700, 0);
		glVertex2f( 700, 400);
		glVertex2f( 400, 400);
	glEnd();
	
	glBegin(GL_LINES);
		glVertex2f( 500, 0);
		glVertex2f( 500, 400);
		
		glVertex2f( 600, 0);
		glVertex2f( 600, 400);
		
		glVertex2f( 400, 100);
		glVertex2f( 700, 100);
		
		glVertex2f( 400, 200);
		glVertex2f( 700, 200);
		
		glVertex2f( 400, 300);
		glVertex2f( 700, 300);
		
	glEnd();
}

void Quadrado(){
	glColor3f(R, G, B);
	glBegin(GL_QUADS);
	
		glVertex2f( xU, yU);
		glVertex2f( xD, yD);
		glVertex2f( xT, yT);
		glVertex2f( xQ, yQ);
	
	glEnd();
}

void Triangulo(){
	glColor3f(R, G, B);
	glBegin(GL_TRIANGLES);
	
		glVertex2f( xD, yD);
		glVertex2f( xT, yT);
		glVertex2f( xQ, yQ);
	
	glEnd();	
}

void Circulo(){
	float x , y;
	glBegin(GL_LINES);
	glColor3f(R, G, B);
	for(x = -r ; x <= r ; x++){
		y = pow( (r*r - x*x) , 0.5 );
		glVertex2f( x + dx, y + dy);
		glVertex2f( x + dx, -y + dy);
	}
	glEnd();
}

void redesenha(){
	glClearColor(0.85 , 0.85 , 0.95 , 1);
	glClear(GL_COLOR_BUFFER_BIT);
	if (objeto==1){
		Quadrado();
	}
	else if (objeto==2)
		Triangulo();
	else if (objeto==3)
		Circulo();
			
	LayoutTela();
	glFlush();
}

void Mouse(int button, int state, int x, int y){
	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP){
		//1ª coluna
		if (x > 400 && x < 500) {
			if(y < 100){
				R = 0;
				G = 0;
				B = 0;
			}
			else if( y < 200){
				R = 1;
				G = 0;
				B = 0;
			}
			else if ( y < 300){
				R = 0;
				G = 1;
				B = 1;
			}
			else{ 
				if (objeto == 1)
					objeto = 0;
				else
					objeto = 1;
			}
		}
		
		//2ª coluna
		if (x > 500 && x < 600) {
			if(y < 100){
				R = 0.5;
				G = 0.5;
				B = 0.5;
			}
			else if( y < 200){
				R = 0;
				G = 1;
				B = 0;
			}
			else if ( y < 300){
				R = 1;
				G = 0;
				B = 1;
			}
			else{ 
				if (objeto == 2)
					objeto = 0;
				else
					objeto = 2;
			}
		}
		
		//3ª coluna
		
		if (x > 600 && x < 700) {
			if(y < 100){
				R = 1;
				G = 1;
				B = 1;
			}
			else if( y < 200){
				R = 0;
				G = 0;
				B = 1;
			}
			else if ( y < 300){
				R = 1;
				G = 1;
				B = 0;
			}
			else{ 
				if (objeto == 3)
					objeto = 0;
				else
					objeto = 3;
			}
		}
	}
	
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_UP){
		R = 0.35; G = 0.75; B = 0.55 ;
		objeto = 0;
	}
	
	redesenha();
}

void teclado(unsigned char key, int x, int y){
	switch (key) {
		case 27:
			R = 0.35; G = 0.75; B = 0.55 ;
			objeto = 0;
		break;
		
		case 'P':
		case 'p':
			printf("Qual objeto deseja desenhar?\nDigite:\n1 - Para quadrado\n2 - Para triangulo\n3 - Para circulo\nR.: ");
			scanf("%d",&objeto);
			if(objeto==1){
				printf("Informe os valores entre 0 e 400.");
				printf("\nInsira os valores em sentido horário e começando pelo ponto do topo esquerdo.");
				printf("\nInforme o primeiro ponto:\nDigite o valor de x1: ");
				scanf("%f",&xU);
				
				printf("\nDigite o valor de y1: ");
				scanf("%f",&yU);
				
				
				printf("\nInforme o segundo ponto:\nDigite o valor de x2: ");
				scanf("%f",&xD);
				
				printf("\nDigite o valor de y2: ");
				scanf("%f",&yD);
				
				
				printf("\nInforme o terceiro ponto:\nDigite o valor de x3: ");
				scanf("%f",&xT);
				
				printf("\nDigite o valor de y3: ");
				scanf("%f",&yT);
				
				
				printf("\nInforme o quarto ponto:\nDigite o valor de x4: ");
				scanf("%f",&xQ);
				
				printf("\nDigite o valor de y4: ");
				scanf("%f",&yQ);
			}
			
			else if(objeto==2){
				printf("Informe os valores entre 0 e 400.");
				printf("\nInforme o primeiro ponto:\nDigite o valor de x1: ");
				scanf("%f",&xD);
				
				printf("\nDigite o valor de y1: ");
				scanf("%f",&yD);
				
				
				printf("\nInforme o segundo ponto:\nDigite o valor de x2: ");
				scanf("%f",&xT);
				
				printf("\nDigite o valor de y2: ");
				scanf("%f",&yT);
				
				
				printf("\nInforme o terceiro ponto:\nDigite o valor de x3: ");
				scanf("%f",&xQ);
				
				printf("\nDigite o valor de y3: ");
				scanf("%f",&yQ);
			}
			
			else if(objeto==3){
				printf("Informe os valores entre 0 e 190.");
				printf("\nInforme o valor do raio: ");
				scanf("%f",&r);
			}
		break;
	}	
	redesenha();
}

int main(int argc, char **argv){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(701,401);
	glutInitWindowPosition(200,50);
	glutCreateWindow("Paint");
	
	gluOrtho2D(0, 700, 400, 0);
	glutMouseFunc(Mouse);    
	glutDisplayFunc(redesenha);
	glutKeyboardFunc(teclado);
	
	glutMainLoop();
	
	return(0);
}
