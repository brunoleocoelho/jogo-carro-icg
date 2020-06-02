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
            Hatch();
        }

    //metodos
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

        /** Desenho um carro Hatch
        *   cores disponíveis: azul, amarelo, vermelho
        */
        void Hatch()
        {
            float altura = comprimento * 0.3;
            if(getCor() == "amarelo"){
                glColor3f(1, 1, 0);
            } else if (getCor() == "azul"){
                glColor3f(0, 0, 1);
            } else {
                glColor3f(1, 0, 0); //vermelho
            }
            //chassi
            glBegin(GL_QUADS);
                glVertex2f(posX, posY);
                glVertex2f(posX, posY+altura);
                glVertex2f(posX+comprimento, posY+altura);
                glVertex2f(posX+comprimento, posY);                
            glEnd();
            //cabine
            glBegin(GL_QUADS);
                glVertex2f(posX, posY+altura);
                glVertex2f(posX, posY+(altura*1.6));
                glVertex2f(posX+(comprimento*0.6), posY+(altura*1.6));
                glVertex2f(posX+(comprimento*0.7), posY+altura);                
            glEnd();
            //vidros
            glColor3f(0.7, 0.8, 0.8);//cinza            
            glBegin(GL_QUADS);
                glVertex2f(posX+0.4, posY+altura);
                glVertex2f(posX+0.4, posY+(altura*1.45));
                glVertex2f(posX+(comprimento*0.55), posY+(altura*1.45));
                glVertex2f(posX+(comprimento*0.65), posY+altura);                
            glEnd();
            Roda(posX + (comprimento * 0.2), altura * 0.5); //traseira
            Roda(posX + (comprimento * 0.8), altura * 0.5);//dianteira
            
        }

        // /** Desenho um carro Sedan
        // *   cores disponíveis: azul, amarelo, vermelho
        // */
        // void Sedan(){
        // }

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
