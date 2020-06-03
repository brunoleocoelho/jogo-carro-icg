#include <stdlib.h>
#include <iostream>
#include <string>
// #include <GL/glut.h>
// #include <math.h>

using namespace std;

class Carro {
    private:
        float posX;
        float posY;
        float comprimento;
        string cor;

    public:
        //Construtores
        Carro (){

        }
        
        Carro (float x, float y, float large, string color)
        {
            posX = x;
            posY = y;
            comprimento = large;
            cor = color;
            // Hatch();
        }

    //metodos
        /**
         * Aplica a cor do carro, conforme instanciado
         */
        void ApplicaCorCarro() {
            string cor = getCor();

            if(cor == "amarelo") {
                glColor3f(1, 1, 0);
            } 
            else if (cor == "azul") {
                glColor3f(0, 0, 1);
            } 
            else {
                glColor3f(1, 0, 0); //vermelho
            }
        }

        // void Roda(float posX, float posY, float raio)
        void Roda(float position, float raio)
        {    
            glColor3f(0, 0, 0);//preto
            float ang, calota = 0.5;
            float x, y;
            glBegin(GL_POLYGON); 
            for (int i=0; i<360; i+=10){
                ang = (i * M_PI)/180.0;
                x = cos(ang) * raio + position;
                y = sin(ang) * raio + posY;
                glVertex2f(x, y);
            }
            glEnd();

            glColor3f(0.7, 0.7, 0.7);//cinza
            glBegin(GL_POLYGON); 
            for (int i=0; i<360; i+=10){
                ang = (i * M_PI)/180.0;
                x = cos(ang) * (raio * calota) + position;
                y = sin(ang) * (raio * calota) + posY;
                glVertex2f(x, y);
            }
            glEnd();    
        }

        /** 
         * Desenho um carro Hatch 
         * cores disponíveis: azul, amarelo, vermelho
         */
        void Hatch()
        {
            float altura = comprimento * 0.3;

            ApplicaCorCarro();

            //chassi
            glBegin(GL_QUADS);
                glVertex2f(posX, posY);
                glVertex2f(posX, posY+altura);
                glVertex2f(posX+(comprimento*0.95), posY+altura);
                glVertex2f(posX+(comprimento), posY);                
            glEnd();
            //cabine
            glBegin(GL_QUADS);
                glVertex2f(posX, posY+altura);
                glVertex2f(posX+(comprimento*0.1), posY+(altura*1.6));
                glVertex2f(posX+(comprimento*0.6), posY+(altura*1.6));
                glVertex2f(posX+(comprimento*0.7), posY+altura);                
            glEnd();
            //vidros
            glColor3f(0.7, 0.8, 0.8);//cinza            
            glBegin(GL_QUADS);
                glVertex2f(posX+0.4, posY+altura);
                glVertex2f(posX+0.8, posY+(altura*1.45));
                glVertex2f(posX+(comprimento*0.55), posY+(altura*1.45));
                glVertex2f(posX+(comprimento*0.65), posY+altura);                
            glEnd();
            Roda(posX + (comprimento * 0.15), altura * 0.5); //traseira
            Roda(posX + (comprimento * 0.75), altura * 0.5);//dianteira
            
        }

        /**
         * Desenho um carro Sedan cores 
         * disponíveis: azul, amarelo, vermelho
         */
        void Sedan(){
            // Molda o Sedan a partir do hatch
            Hatch();
            
            // mala
            float altura = comprimento * 0.3;
            float malaTop = comprimento * 0.15;
            float malaDown = comprimento * 0.18;

            ApplicaCorCarro();
            glBegin(GL_QUADS);
                glVertex2f(posX, posY);
                glVertex2f(posX, posY+altura);
                glVertex2f(posX-malaTop, posY+altura);
                glVertex2f(posX-malaDown, posY);                
            glEnd();
        }

        //Getters
        float getPosX(){
            return posX;
        }

        float getPosY(){
            return posY;
        }
        
        float getComprimento(){
            return comprimento;
        }

        string getCor(){
            return cor;
        }

        //Setters
        void setPosX(float x){
            posX = x;
        }

        void setPosY(float y){
            posY = y;
        }

        void setComprimento(float large){
            comprimento = large;
        }

        void setCor(string color){
            cor = color;
        }
    
};
