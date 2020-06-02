/** FAETERJ Petrópolis - periodo 2016-2
* TRABALHO DA DISCIPLINA ICG (Introdução a Computação Gráfica)
* Professora Sicilia Judice
* Alunos:
*       Bruno Leonardo da Silva Coelho
*       Rafael Mota da Costa
*/

#include <GL/glut.h>
#include <math.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include "predio.h"
#include "ceu.h" //classe ceu
#include "terreno.h" //classe terreno
#include "carro.h" //classe Carro
#include "arvore.h" //classe Arvore

using namespace std;

//GLOBAIS
float minX = -700, maxX = 700;
float minY = -700, maxY = 700; //valores para Ortho abicissa
float e=0.15;//escala de projeção

//variaveis para transformações na projeção e alguns objetos da tela
GLfloat dx=-280, dy=0; //Translação da projeção
bool menu = false;

//nossos carros parametros: x, y, tamanho, cor
Carro car1(-(maxX * 0.53), dy - 25, 5, "amarelo");
Carro car2(-(maxX * 0.53), dy - 31, 5, "azul"); 
Carro car3(-(maxX * 0.53), dy - 37, 5, "vermelho"); 

//FUNÇÕES
//escreve um texto na tela
void textoNaTela(float x, float y, char *texto){
    glRasterPos2f(x, y);
    while(*texto)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *texto++);
        // GLUT_BITMAP_HELVETICA_10
        // GLUT_BITMAP_TIMES_ROMAN_10
        // GLUT_BITMAP_9_BY_15
}

void display(){
     glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    Ceu sky;
    sky.setDia(true);
    sky.sol(35, 45, 5);
	//parametros da nuvem x, y, comprimento
	sky.nuvem(-350, 28, 12);
	sky.nuvem(-295, 22, 20);
	sky.nuvem(-240, 40, 18);
	sky.nuvem(-180, 46, 15);
	sky.nuvem(-100, 30, 13);
	sky.nuvem(-60, 50, 15);
	sky.nuvem(-15, 36, 11);
	sky.nuvem(-14, 32, 15);
	sky.nuvem(14, 32, 14);
	sky.nuvem(55, 24, 30);

    Terreno ground;
    ground.chao(minX, maxX);
    
    //parametros montanhas: x, y, altura, largura
    ground.montanha(-360, -1, 20, 65);
    ground.montanha(-270, -1, 11, 40);
    ground.montanha(-310, -1, 11, 44);
    ground.montanha(-200, -1, 16, 55);
    ground.montanha(-220, -1, 10, 40);
    ground.montanha(-170, -1, 9, 45);
    ground.montanha(-120, -1, 16, 47);
    ground.montanha(-80, -1, 20, 85);
    ground.montanha(-90, -1, 8, 28);
    ground.montanha(-20, -1, 13, 45);
    ground.montanha(110, -1, 12, 55);
    ground.montanha(55, -1, 9, 28);
    ground.montanha(130, -1, 10, 40);
    ground.montanha(90, -1, 10, 44);
    ground.montanha(37, -1, 13, 37);
    ground.montanha(250, -1, 20, 80);
    ground.montanha(190, -1, 9, 45);
    ground.montanha(220, -1, 10, 40);
    ground.montanha(165, -1, 13, 47);
    ground.montanha(-329, -2, 17, 37);
    ground.montanha(-260, -2, 13, 55);
    ground.montanha(-150, -2, 10, 45);
    ground.montanha(-125, -2, 9, 28);
    ground.montanha(145, -2, 7, 34);
    ground.montanha(83, -2, 10, 40);
    ground.montanha(189, -2, 10, 50);  
    ground.montanha(-290, -3, 13, 55);
    ground.montanha(23, -4, 12, 33);
    ground.montanha(0, -4, 15, 50);
    ground.montanha(240, -4, 16, 37);
    ground.montanha(309, -4, 14, 47);
    ground.montanha(290, -4, 15, 37);
    
    // parametros de estrada: posicaoY, largura, esq, dir
    ground.estrada(-40, 18, minX, maxX);

    glPushMatrix();
        glTranslatef(-350, -10, 1);
        umPredio();
    glPopMatrix();
 
    glPushMatrix();
        glTranslatef(-300, -8, 1);
        umPredio();
    glPopMatrix();
    
    glPushMatrix();
        glTranslatef(-250, -5, 1);
        umPredio();
    glPopMatrix();
    
    glPushMatrix();
        glTranslatef(-200, -10, 1);
        umPredio();
    glPopMatrix();
    
    glPushMatrix();
        glTranslatef(-150, -5, 1);
        umPredio();
    glPopMatrix();
    
   
    
    ;
    
    glPushMatrix();
        glTranslatef(0, -5, 1);
        umPredio();
    glPopMatrix();
    
    
    
    
    
    glPushMatrix();
        glTranslatef(150, -10, 1);
        umPredio();
    glPopMatrix();
    
 
    
    glPushMatrix();
        glTranslatef(250, -8, 1);
        umPredio();
    glPopMatrix();
    
    glPushMatrix();
        glTranslatef(300, -7, 1);
        umPredio();
    glPopMatrix();
    
    glPushMatrix();
        glTranslatef(350, -5, 1);
        umPredio();
    glPopMatrix();
    
    glPushMatrix();
        glTranslatef(270, -8, 1);
        umPredio();
    glPopMatrix();
    
    glPushMatrix();
        glTranslatef(300, -4, 1);
        umPredio();
    glPopMatrix();
    
    glPushMatrix();
        glTranslatef(450, -10, 1);
        umPredio();
    glPopMatrix();
    
    
    glPushMatrix();
        glTranslatef(-230, -47, 1);
        umPredio();
    glPopMatrix();
    
    
     
     glPushMatrix();
        glTranslatef(-155, -47, 1);
        umPredio();
    glPopMatrix();
     
     
     
     glPushMatrix();
        glTranslatef(-80, -47, 1);
        umPredio();
    glPopMatrix();
     

     glPushMatrix();
        glTranslatef(50, -47, 1);
        umPredio();
    glPopMatrix();
     
     
     
     glPushMatrix();
        glTranslatef(200, -47, 1);
        umPredio();
    glPopMatrix();
     
     glPushMatrix();
        glTranslatef(300, -47, 1);
        umPredio();
    glPopMatrix();
    
    glPushMatrix();
        glTranslatef(350, -47, 1);
        umPredio();
    glPopMatrix();
     
     glPushMatrix();
        glTranslatef(365, -47, 1);
        umPredio();
    glPopMatrix();
     
     glPushMatrix();
        glTranslatef(380, -47, 1);
        umPredio();
    glPopMatrix();
     
     glPushMatrix();
        glTranslatef(395, -47, 1);
        umPredio();
    glPopMatrix();
     
     glPushMatrix();
        glTranslatef(430, -47, 1);
        umPredio();
    glPopMatrix();
     
     glPushMatrix();
        glTranslatef(425, -12, 1);
        umPredio();
    glPopMatrix();
    
     
     glPushMatrix();
        glTranslatef(410, -10, 1);
        umPredio();
    glPopMatrix();     
     
     
        //glScalef(2,0.6,1);

    car1.Hatch();
    car2.Hatch();
    car3.Hatch();

    cout << car1.getCor() << ": tam=" << car1.getComprimento() << 
        ", x=" << car1.getPosX() << ", y=" << car1.getPosY() << endl; //linha teste

    cout << car2.getCor() << ": tam=" << car2.getComprimento() << 
        ", x=" << car2.getPosX() << ", y=" << car2.getPosY() << endl; //linha teste

    cout << car3.getCor() << ": tam=" << car3.getComprimento() << 
        ", x=" << car3.getPosX() << ", y=" << car3.getPosY() << endl; //linha teste

    //criando arvores
    Arvore tree;
        //acima da estrada
        tree.setArvore(-290, -12, 12);
        tree.setArvore(-282, -11, 11);
        tree.setArvore(-368, -11, 11);
        tree.setArvore(-335, -10, 17);
        tree.setArvore(-240, -10, 17);
        tree.setArvore(-215, -10, 17);
        tree.setArvore(-225, -10, 10);
        tree.setArvore(-190, -8, 17);
        tree.setArvore(-180, -11, 12);
        tree.setArvore(-165, -9, 17);
        tree.setArvore(-135, -10, 17);
        tree.setArvore(-125, -6, 17);
        tree.setArvore(-85, -10, 12);
        tree.setArvore(-65, -6, 15);
        tree.setArvore(-35, -9, 18);
        tree.setArvore(-25, -11, 8);
        tree.setArvore(-10, -12, 10);
        tree.setArvore(15, -10, 17);
        tree.setArvore(25, -8, 14);
        tree.setArvore(35, -10, 17);
        tree.setArvore(60, -8, 19);
        tree.setArvore(80, -10, 8);
        tree.setArvore(90, -12, 14);
        tree.setArvore(110, -10, 17);
        tree.setArvore(135, -8, 20);
        tree.setArvore(165, -10, 17);
        tree.setArvore(185, -8, 15);
        tree.setArvore(260, -10, 8);
        tree.setArvore(280, -11, 15);
        tree.setArvore(315, -10, 17);
        tree.setArvore(335, -11, 14);
        tree.setArvore(365, -8, 20);
        tree.setArvore(385, -10, 17);
        tree.setArvore(335, -10, 17);
        tree.setArvore(335, -10, 17);
        tree.setArvore(335, -10, 17);
        
        tree.setArvore(-290, -11, 11);
        tree.setArvore(-282, -11, 11);
        tree.setArvore(-314, -12, 11);
        tree.setArvore(-270, -10, 15);
        tree.setArvore(215, -12, 12);
        tree.setArvore(225, -14, 11);
        tree.setArvore(208, -15, 10);
        tree.setArvore(235, -13, 13);
        //abaixo da estrada
        tree.setArvore(-300, -42, 13);
        tree.setArvore(-312, -41, 12);
        tree.setArvore(-324, -42, 11);
        tree.setArvore(-289, -40, 10);
        tree.setArvore(-280, -40, 10);
        tree.setArvore(-260, -42, 10);
        tree.setArvore(-270, -42, 10);
        tree.setArvore(-250, -40, 10);
        tree.setArvore(-220, -42, 10);
        tree.setArvore(-210, -44, 10);
        tree.setArvore(-185, -44, 10);
        tree.setArvore(-177, -42, 10);
        tree.setArvore(-145, -44, 10);
        tree.setArvore(-138, -46, 10);
        tree.setArvore(-162, -42, 10);
        tree.setArvore(-120, -44, 10);
        tree.setArvore(-100, -42, 10);
        tree.setArvore(-90, -42, 10);
        tree.setArvore(-50, -44, 10);
        tree.setArvore(-20, -40, 10);
        tree.setArvore(-0, -46, 10);
        tree.setArvore(-10, -42, 10);
        tree.setArvore(20, -44, 10);
        tree.setArvore(40, -46, 10);
        tree.setArvore(30, -42, 10);
        tree.setArvore(25, -41, 10);
        tree.setArvore(70, -42, 10);
        tree.setArvore(82, -46, 10);
        tree.setArvore(90, -44, 10);
        tree.setArvore(100, -42, 10);
        tree.setArvore(120, -44, 10);
        tree.setArvore(128, -42, 10);
        tree.setArvore(170, -42, 10);
        tree.setArvore(250, -44, 10);
        tree.setArvore(188, -41, 10);
        tree.setArvore(160, -48, 10);
        tree.setArvore(410, -44, 10);
        tree.setArvore(420, -46, 10);
        tree.setArvore(440, -44, 10);
        tree.setArvore(460, -42, 10);
        
        
     
     
        
        tree.setArvore(280, -40, 10);
        tree.setArvore(324, -42, 13);
        tree.setArvore(312, -41, 12);
        tree.setArvore(334, -42, 11);
        tree.setArvore(220, -41, 10);
        tree.setArvore(228, -43, 13);

    //Ao iniciar exibe um texto de ajuda, e ao chegar na outra cidade exibe o SUCESSO
    if (dx <= -270 || menu){
        glColor3f(1, 1, 1);
        textoNaTela(dx, dy, "VAMOS VIAJAR DE CARRO!!");
        glColor3f(1, 0.2, 0.2);
        textoNaTela(dx, dy-10, "'Seta Direita' para comecar a viagem!!");
        textoNaTela(dx, dy-20, "Pg UP = Zoom IN, Pg Down = Zoom Out");
        textoNaTela(dx, dy-30, "H = abrir este menu");
        textoNaTela(dx, dy-40, "ESC = sair");
        // textoNaTela(maxX * 0.8, dy * 0.8, "Seu carro eh VERMELHO. Acelere com a Seta Direita");
    } else if (dx >= 360){
        glColor3f(1, 0, 0);
        textoNaTela(dx, dy, "PARABENS!! VOCE CHEGOU AO DESTINO!");
    }

    glutSwapBuffers();//Ultima função
}

void projecao(void) {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho((minX*e)+ dx, (maxX*e)+ dx, (minY*e) + dy, (maxY*e) + dy, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

//função de reshape padrão deste programa
void reshape (int w, int h){
    glViewport (0,0,w,h);
    //cálculo de projeção da janela
    if (w <= h) { 
        cout << "reshape if used" << endl; // test line
        minX = (-700 * h)/w;
        maxX *= (700 * h)/w;
        minY = -700;
        maxY = 700;
    }
    else {
        cout << "reshape else used" << endl; //test line
        minX = -700;
        maxX = 700;
        minY = (-700 * h)/w;
        maxY = (700 * h)/w;
    }
    //test lines para visualizar a dimensão da janela e proporção
    cout << "Inicio\n minX=" << minX << "\n maxX=" << maxX 
            << "\n minY=" << minY << "\n maxY=" << maxY << "\n"
            << " w=" << w << "\n h=" << h << endl;
    projecao();
}   

void special (int tecla, int x, int y)
{
    switch (tecla)
    {
        //move os carros
        case GLUT_KEY_RIGHT:
            cout << "Right dx=" << dx << "\n";
            if (dx <= 370){
                if (car3.getPosX() > dx){
                    dx = car3.getPosX();
                } 
//				else {
//                    //dx += 4.5;					
//                }
                car1.setPosX( car1.getPosX()+0.68);
                car2.setPosX( car2.getPosX()+0.67);
                car3.setPosX( car3.getPosX()+0.7);
                projecao();
            }
            break;
        //ZOOM OUT
        case GLUT_KEY_PAGE_DOWN:
            cout << "PG-DOWN e=" << e << "\n";
            if ((e+0.05)<=0.50){
                e += 0.02;
                projecao();
            }
            break;
        //ZOOM IN
        case GLUT_KEY_PAGE_UP:
            cout << "PG-UP e=" << e << "\n";
            if ((e-0.03)>=0.10){
                e -= 0.02;
                projecao();
            }
            break;
    }
    glutPostRedisplay();
}

void keyboard( unsigned char tecla, int x, int y ) {
    switch (tecla){
        case 27:  //ESC sai do programa
            exit(0);
            break;
        case 'h':
        case 'H': 
            menu = !menu;
            break;
    }
    glutPostRedisplay();
}

void init(void) {
    glEnable(GL_BLEND); //habilita a função de transparencia
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA); //definindo a função de transparencia
}


int main(int argc, char *argv[]) {
    //Criação da janela
    glutInit(&argc, argv);
    glutInitWindowSize(800,400);
    glutInitWindowPosition(200,200);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("PROJETO FINAL ICG 2016-2");
    
    //CallBacks
    glutDisplayFunc (display);
    glutReshapeFunc(reshape);    
    glutSpecialFunc( special ); //teclas especiais
    glutKeyboardFunc(keyboard); //teclas da tab ASCII

    init();
    glutMainLoop();

    return EXIT_SUCCESS;
}
