//#include <stdlib.h>
//#include <iostream>
//#include <string>

void umPredio(){
   //Telhado
    glColor4f(0.545,0.271,0.075,1);
    glBegin(GL_TRIANGLES);
      glVertex2f(-6,4); // canto inferior esquerdo
      glVertex2f(0,9);  // canto superior
      glVertex2f(6,4);  // canto inferior direito
    glEnd();
    
    //Base da Casa
    glColor4f(0.690,0.769,0.871,1);
    glBegin(GL_QUADS); // base da casa
      glVertex2f(-5,-10); //canto inferior esquerdo      
      glVertex2f(-5,4);  //canto superior esquerdo      
      glVertex2f(5,4);  //canto superior direito 
      glVertex2f(5,-10);  //canto inferior direito
     glEnd(); 
    
    //Batente Porta 1 DIR
    glColor4f(0.545,0.271,0.075,1);
    glBegin(GL_QUADS); 
      glVertex2f(0.1,-10); //canto inferior esquerdo      
      glVertex2f(0.1,-5.5);  //canto superior esquerdo      
      glVertex2f(2.5,-5.5);  //canto superior direito 
      glVertex2f(2.5,-10);  //canto inferior direito
     glEnd(); 
    
    //Porta 1
    glColor4f(0.80,0.33,0.33,1);
    glBegin(GL_QUADS); 
      glVertex2f(0.3,-9.8); //canto inferior esquerdo      
      glVertex2f(0.3,-5.7);  //canto superior esquerdo      
      glVertex2f(2.3,-5.7);  //canto superior direito 
      glVertex2f(2.3,-9.8);  //canto inferior direito
     glEnd(); 
     
     //Batente Porta 2  ESQ     
    glColor4f(0.545,0.271,0.075,1);
    glBegin(GL_QUADS); 
      glVertex2f(-2.4,-10); //canto inferior esquerdo      
      glVertex2f(-2.4,-5.5);  //canto superior esquerdo      
      glVertex2f(-0,-5.5);  //canto superior direito 
      glVertex2f(-0,-10);  //canto inferior direito
     glEnd(); 
    
    //Porta 2
    glColor4f(0.80,0.33,0.33,1);
    glBegin(GL_QUADS); 
      glVertex2f(-2.2,-9.8); //canto inferior esquerdo      
      glVertex2f(-2.2,-5.7);  //canto superior esquerdo      
      glVertex2f(-0.2,-5.7);  //canto superior direito 
      glVertex2f(-0.2,-9.8);  //canto inferior direito
     glEnd(); 
    
    ///Lampada
    float ang2,x2,y2;
    glColor4f(0.86,0.86,0.86,1);
    glBegin(GL_POLYGON);
      for(int i=0;i<360;i+=1)
      {
              ang2 = ( i* M_PI)/360.0;
              x2 = cos(ang2)*0.7-0; // primeiro n° largura, segundo n° negativo move para a esquerda 
              y2 = sin(ang2)*0.7-4.8; //primeiro n° altura, segundo n° negativo move para a baixo 
              glVertex2f(x2,y2);
      }       
    glEnd();
    
    //Maçaneta
    float ang1,x1,y1;
    glColor4f(1,0.84,0,1);
    glBegin(GL_POLYGON);
      for(int i=0;i<360;i+=1)
      {
              ang1 = ( i* M_PI)/180.0;
              x1 = cos(ang1)*0.2-0.6; // primeiro n° tamanho, segundo n° negativo move para a esquerda 
              y1 = sin(ang1)*0.2-8; //primeiro n° tamanho, segundo n° negativo move para a baixo 
              glVertex2f(x1,y1);
      }       
    glEnd();
    
    //Maçaneta
    float ang3,x3,y3;
    glColor4f(1,0.84,0,1);
    glBegin(GL_POLYGON);
      for(int i=0;i<360;i+=1)
      {
              ang3 = ( i* M_PI)/180.0;
              x3 = cos(ang3)*0.2+0.6; // primeiro n° tamanho, segundo n° negativo move para a esquerda 
              y3 = sin(ang3)*0.2-8; //primeiro n° tamanho, segundo n° negativo move para a baixo 
              glVertex2f(x3,y3);
      }       
    glEnd();
    //Batente Janela Esq 1
    glColor4f(0.545,0.271,0.075,1);
    glBegin(GL_QUADS); 
      glVertex2f(-4.3,0.7); //canto inferior esquerdo      
      glVertex2f(-4.3,3.1);  //canto superior esquerdo      
      glVertex2f(-1.5,3.1);  //canto superior direito 
      glVertex2f(-1.5,0.7);  //canto inferior direito
     glEnd(); 
    
     //Janela Esq 1
    glColor4f(0.80,1,1,1);
    glBegin(GL_QUADS); 
      glVertex2f(-4,1); //canto inferior esquerdo      
      glVertex2f(-4,2.8);  //canto superior esquerdo      
      glVertex2f(-1.8,2.8);  //canto superior direito 
      glVertex2f(-1.8,1);  //canto inferior direito
     glEnd(); 
    
     //Batente Janela Esq 2
    glColor4f(0.545,0.271,0.075,1);
    glBegin(GL_QUADS); 
      glVertex2f(-4.3,-2.1); //canto inferior esquerdo      
      glVertex2f(-4.3,0.3);  //canto superior esquerdo      
      glVertex2f(-1.5,0.3);  //canto superior direito 
      glVertex2f(-1.5,-2.1);  //canto inferior direito
     glEnd(); 
    
     //Janela Esq 2
    glColor4f(0.80,1,1,1);
    glBegin(GL_QUADS); 
      glVertex2f(-4,-1.8); //canto inferior esquerdo      
      glVertex2f(-4,-0);  //canto superior esquerdo      
      glVertex2f(-1.8,-0);  //canto superior direito 
      glVertex2f(-1.8,-1.8);  //canto inferior direito
     glEnd();
      
     //Batente Janela Esq 3
    glColor4f(0.545,0.271,0.075,1);
    glBegin(GL_QUADS); 
      glVertex2f(-4.3,-4.9); //canto inferior esquerdo      
      glVertex2f(-4.3,-2.5);  //canto superior esquerdo      
      glVertex2f(-1.5,-2.5);  //canto superior direito 
      glVertex2f(-1.5,-4.9);  //canto inferior direito
     glEnd(); 
     
      //Janela Esq 3
    glColor4f(0.80,1,1,1);
    glBegin(GL_QUADS); 
      glVertex2f(-4,-4.6); //canto inferior esquerdo      
      glVertex2f(-4,-2.8);  //canto superior esquerdo      
      glVertex2f(-1.8,-2.8);  //canto superior direito 
      glVertex2f(-1.8,-4.6);  //canto inferior direito
     glEnd();
     
    //Batente Janela Dir
    glColor4f(0.545,0.271,0.075,1);
    glBegin(GL_QUADS); 
      glVertex2f(4.3,0.7); //canto inferior direito      
      glVertex2f(4.3,3.1);  //canto superior esquerdo      
      glVertex2f(1.5,3.1);  //canto superior direito 
      glVertex2f(1.5,0.7);  //canto inferior direito
     glEnd();
     
     //Janela Dir
    glColor4f(0.80,1,1.0,1);
    glBegin(GL_QUADS); 
      glVertex2f(4,1); //canto inferior esquerdo      
      glVertex2f(4,2.8);  //canto superior esquerdo      
      glVertex2f(1.8,2.8);  //canto superior direito 
      glVertex2f(1.8,1);  //canto inferior direito
     glEnd(); 
    
     //Batente Janela Dir 2
    glColor4f(0.545,0.271,0.075,1);
    glBegin(GL_QUADS); 
      glVertex2f(4.3,-2.1); //canto inferior direito      
      glVertex2f(4.3,0.3);  //canto superior esquerdo      
      glVertex2f(1.5,0.3);  //canto superior direito 
      glVertex2f(1.5,-2.1);  //canto inferior direito
     glEnd();
    
     //Janela Dir 2
    glColor4f(0.80,1,1.0,1);
    glBegin(GL_QUADS); 
      glVertex2f(4,-1.8); //canto inferior esquerdo      
      glVertex2f(4,-0);  //canto superior esquerdo      
      glVertex2f(1.8,-0);  //canto superior direito 
      glVertex2f(1.8,-1.8);  //canto inferior direito
     glEnd(); 
     
     //Batente Janela Dir 3
    glColor4f(0.545,0.271,0.075,1);
    glBegin(GL_QUADS); 
      glVertex2f(4.3,-4.9); //canto inferior direito      
      glVertex2f(4.3,-2.5);  //canto superior esquerdo      
      glVertex2f(1.5,-2.5);  //canto superior direito 
      glVertex2f(1.5,-4.9);  //canto inferior direito
     glEnd();
     
     //Janela Dir 3
    glColor4f(0.80,1,1.0,1);
    glBegin(GL_QUADS); 
      glVertex2f(4,-4.6); //canto inferior esquerdo      
      glVertex2f(4,-2.8);  //canto superior esquerdo      
      glVertex2f(1.8,-2.8);  //canto superior direito 
      glVertex2f(1.8,-4.6);  //canto inferior direito
     glEnd(); 
    
     //Luz
    glColor4f(1,0.84,0,0.3);
    glBegin(GL_QUADS); 
      glVertex2f(-1.9,-10); //canto inferior esquerdo      
      glVertex2f(-0.6,-4.8);  //canto superior esquerdo      
      glVertex2f(0.6,-4.8);  //canto superior direito 
      glVertex2f(1.9,-10);  //canto inferior direito
     glEnd(); 
 
            glEnd();      
}
      
      
