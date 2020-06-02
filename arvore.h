#include<iostream>
#include<stdlib.h>

using namespace std;

class Arvore{
    private:
        float posX;
        float posY;
        float altura;

	    //tronco
        void tronco( float x, float y, float alt){
            float largTr = alt/8;
            float altTr = alt/2;
            float bDir = posX + largTr;
            float pAlt = posY - altTr;
            //glColor3f(0.6,0.3,0);
			glColor3f(0.3,0.2,0.05);
            glBegin(GL_QUADS);
                glVertex2f(posX, posY);
                glVertex2f(bDir, posY);
                glVertex2f(bDir, pAlt);
                glVertex2f(posX, pAlt);
            glEnd();
            
        }

        //copa da arvore
        void copa(float px, float py, float alt){
            float copa = alt*0.25;
            float altCopa = alt-(alt/3);
            float ang, x, y, posC = px+((alt/8)/2);
			bool corCopa = true;
            glBegin(GL_POLYGON); 
            for (int i=0; i<360; i+=8){
				if (corCopa){
		        	glColor3f(0,0.6,0.3); //verde claro
				} else {
			        glColor3f(0,0.35,0); //verde escuro
				}
                ang = (i * M_PI)/180.0;
                x = cos(ang) * copa + posC;
                y = sin(ang) * copa + py;
                glVertex2f(x, y);
				corCopa = !corCopa;
            }
            glEnd();

            //contorno da copa
            glColor3f(0,0.8,0.2);
            glBegin(GL_LINE_LOOP); 
            for (int i=0; i<360; i+=8){
                ang = (i * M_PI)/180.0;
                x = cos(ang) * copa + posC;
                y = sin(ang) * copa + posY;
                glVertex2f(x, y);
            }
            glEnd();	
        }

        //desenha uma sombre primitiva embaixo do objeto
        void sombra(float posX, float posY, float raio){    
            glColor4f(0.5,0.5,0.5,0.2);//cinza claro
            float ang;
            float x, y;
            glBegin(GL_POLYGON); 
            for (int i=0; i<360; i+=6){
                ang = (i * M_PI)/180.0;
                x = cos(ang) * raio + posX;
                y = sin(ang) * raio + posY;
                glVertex2f(x, y);
            }
            glEnd();
            
        }

    
    public:
        //construtor
        Arvore(){};
        
        void setArvore(float x, float y, float tall){
            posX = x;
            posY = y;
            altura = tall;
			sombra(x, y-(tall/2), tall/4);
            tronco(x, y, tall);
            copa(x, y, tall);
        }
    
};
