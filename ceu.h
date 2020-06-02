#include <iostream>
#include<string>
// #include <GL/glut.h>
// #include <math.h>

using namespace std;

class Ceu{
    private:
        bool dia;
        
        void ceuDia(){
            glClear(GL_COLOR_BUFFER_BIT);
            glClearColor(0.3, 0.7, 1, 1);
            // glClearColor(0.22, 0.69, 0.87, 1); //outra opção
        }

        void ceuNoite(){
            glClear(GL_COLOR_BUFFER_BIT);
            glClearColor(0, 0, 0, 1);
        }


    public:
        //Construtores
        Ceu(){
            dia = true;
         }
        
        Ceu(bool dia){
            if(!dia){
                setDia(false);
            }
        }
        //desenha o sol
        void sol(float posX, float posY, float raio){
            if (dia){
                glColor3f(1,1,0);//amarelo
                float ang;
                float x, y;
                glBegin(GL_POLYGON); 
                for (int i=0; i<360; i+=10){
                    ang = (i * M_PI)/180.0;
                    x = cos(ang) * raio + posX;
                    y = sin(ang) * raio + posY;
                    glVertex2f(x, y);
                }
                glEnd();    
                    
            }    
        }

        //desenha a lua
        void lua(float posX, float posY, float raio){    
            if (!dia){
                glColor3f(0.85,0.85,0.95);//cinza claro
                float ang;
                float x, y;
                glBegin(GL_POLYGON); 
                for (int i=0; i<360; i+=10){
                    ang = (i * M_PI)/180.0;
                    x = cos(ang) * raio + posX;
                    y = sin(ang) * raio + posY;
                    glVertex2f(x, y);
                }
                glEnd();                    
            }
        }

		void nuvem(float posX, float posY, float comprimento){
            if (dia){
				float ang;
                float x, y; 
				float raio1 = comprimento/3;
				float raio2 = comprimento/4;
				float raio3 = comprimento/5;


                glBegin(GL_POLYGON); 
                for (int i=0; i<360; i+=10){
		            glColor3f(1, 1, 1);//branco
                    ang = (i * M_PI)/180.0;
                    x = cos(ang) * raio1 + posX;
                    y = sin(ang) * raio1 + posY;
                    glVertex2f(x, y);
                }
                glEnd();  

                glBegin(GL_POLYGON); 
                for (int i=0; i<360; i+=10){
		            glColor3f(1, 1, 1);//branco
                    ang = (i * M_PI)/180.0;
                    x = cos(ang) * raio3 + posX+(comprimento * 0.3);
                    y = sin(ang) * raio3 + posY-0.9;
                    glVertex2f(x, y);
                }
                glEnd();

                glBegin(GL_POLYGON); 
                for (int i=0; i<360; i+=10){
		            glColor3f(0.98, 0.98, 0.98);//cinza claro
                    ang = (i * M_PI)/180.0;
                    x = cos(ang) * raio3 + posX-(comprimento * 0.4);
                    y = sin(ang) * raio3 + posY+0.5;
                    glVertex2f(x, y);
                }
                glEnd();

                glBegin(GL_POLYGON); 
                for (int i=0; i<360; i+=10){
		            glColor3f(1, 1, 1);//branco
                    ang = (i * M_PI)/180.0;
                    x = cos(ang) * raio2 + posX-(comprimento * 0.4);
                    y = sin(ang) * raio2 + posY;
                    glVertex2f(x, y);
                }
                glEnd();

                glBegin(GL_POLYGON); 
                for (int i=0; i<360; i+=10){
		            glColor3f(0.98, 0.98, 0.98);//cinza claro
                    ang = (i * M_PI)/180.0;
                    x = cos(ang) * raio3 + posX+(comprimento * 0.4);
                    y = sin(ang) * raio3 + posY+0.5;
                    glVertex2f(x, y);
                }
                glEnd();

                glBegin(GL_POLYGON); 
                for (int i=0; i<360; i+=10){
		            glColor3f(1, 1, 1);//branco
                    ang = (i * M_PI)/180.0;
                    x = cos(ang) * raio2 + posX+(comprimento * 0.3);
                    y = sin(ang) * raio2 + posY-0.9;
                    glVertex2f(x, y);
                }
                glEnd();

                glBegin(GL_POLYGON); 
                for (int i=0; i<360; i+=10){
		            glColor3f(1, 1, 1);//branco
                    ang = (i * M_PI)/180.0;
                    x = cos(ang) * raio3 + posX+(comprimento * 0.6);
                    y = sin(ang) * raio3 + posY+0.6;
                    glVertex2f(x, y);
                }
                glEnd();
    
            }
		}

        //Getters
        bool getDia(){
            return dia;
        }

        //setters
        void setDia(bool v_f){
            dia = v_f;
            if (dia){
                ceuDia();
            } else {
                ceuNoite();
            }
        }
};

