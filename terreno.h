#include <GL/glut.h>
#include <iostream>
// #include <GL/glut.h>
// #include <math.h>

using namespace std;

class Terreno {
    private:

    public:

        //Desenha um chão verde "gramado" ;)
        void chao(float esq, float dir){
            glBegin(GL_QUADS);
                glColor3f(0,0.8,0.4); // chão verde claro
                glVertex2f(esq,0);
                glColor3f(0.3,0.2,0.05); // chão marrom
                glVertex2f(esq,esq);
                glColor3f(0,0.35,0); //verde escuro
                glVertex2f(dir,esq);
                glVertex2f(dir,0);
            glEnd();       
        }

        //Desenha uma estrada cinzentada 
        void estrada(float posicaoY, float largura, float esq, float dir){
            glBegin(GL_QUADS);
                glColor3f(0.3,0.3,0.3);//estrada cinzentada
                glVertex2f(esq, posicaoY);
                glVertex2f(esq, posicaoY+largura);
                glVertex2f(dir, posicaoY+largura);
                glVertex2f(dir,posicaoY);                
            glEnd();
            
            //linhas tracejadas da pista
            glEnable(GL_LINE_STIPPLE);
            glLineWidth(1);
            glLineStipple(1, 0x0F0F); //estilo do tracejado
            glColor3f(1, 1, 0);
            glBegin(GL_LINES);
                glVertex2f(esq, posicaoY+(largura/2));
                glVertex2f(dir, posicaoY+(largura/2));
            glEnd();
        }


        /** Desenha uma montanha com base na forma de um triangulo
        * montanha( float x, float y, float altura, float largura )
        */
        void montanha(float x, float y, float altura, float largura){
            glBegin(GL_TRIANGLES);
                glColor3f(0.4, 0.4, 0.4);//cinza escuro
                // glColor3f(0.7, 0.7, 0.7);//cinza claro
                glVertex2f(x, y);
                glColor3f(0.75, 0.75, 0.75);//falsa neve
                glVertex2f(x+(largura/2), y+altura);
                glColor3f(0.5, 0.5, 0.5);//cinza escuro
                glVertex2f(x+largura, y);
            glEnd();
        }

};


