//******** PRACTICAL WORK GRAPHICAL & MULTIMEDIA SYSTEMS (Engineering School - UAB)
//******** Basic Environment VS2013 MULTIWINDOW with MFC interface and Status Bar
//******** Ferran Poveda, Marc Vivet, Carme Julià, Débora Gil, Enric Martí (February 2018)
// escena.cpp : Here we define the code of the functions to draw objects and scenes using 
//                 OpenGL drawing commands. 


#include "stdafx.h"
#include "material.h"
#include "escena.h"

//ROBOT
	//FLOOR BASE VERTEX
GLfloat vertA[3] = { 10.0, 10.0, 0.0 };
GLfloat vertB[3] = { 10.0,-10.0, 0.0 };
GLfloat vertC[3] = {-10.0, 10.0, 0.0 };
GLfloat vertD[3] = {-10.0,-10.0, 0.0 };
	//CEILING BASE VERTEX
GLfloat vertE[3] = { 10.0, 10.0, 5.0 };
GLfloat vertF[3] = { 10.0,-10.0, 5.0 };
GLfloat vertG[3] = {-10.0, 10.0, 5.0 };
GLfloat vertH[3] = {-10.0,-10.0, 5.0 };

	//CONE
GLdouble coneBase = 2;
GLdouble coneHeight = 12.5;

	//FINGER 1
//Vertical Base
GLfloat vertFVBA1[3] = { 0.25, 0.5, 0.0 };
GLfloat vertFVBB1[3] = { 0.25,-0.5, 0.0 };
GLfloat vertFVBC1[3] = {-0.25, 0.5, 0.0 };
GLfloat vertFVBD1[3] = {-0.25,-0.5, 0.0 };
//Vertical Top
GLfloat vertFVTA1[3] = { 0.25, 0.5, 4.0 };
GLfloat vertFVTB1[3] = { 0.25,-0.5, 4.0 };
GLfloat vertFVTC1[3] = {-0.25, 0.5, 4.0 };
GLfloat vertFVTD1[3] = {-0.25,-0.5, 4.0 }; 
//Horizontal Base
GLfloat vertFHBA1[3] = { 1.75, 0.5, 3.5 };
GLfloat vertFHBB1[3] = { 1.75,-0.5, 3.5 };
GLfloat vertFHBC1[3] = {-0.25, 0.5, 3.5 };
GLfloat vertFHBD1[3] = {-0.25,-0.5, 3.5 };
//Horizontal Top
GLfloat vertFHTA1[3] = { 1.75, 0.5, 4.0 };
GLfloat vertFHTB1[3] = { 1.75,-0.5, 4.0 };
GLfloat vertFHTC1[3] = {-0.25, 0.5, 4.0 };
GLfloat vertFHTD1[3] = {-0.25,-0.5, 4.0 };

	//FINGER 2
//Vertical Base
GLfloat vertFVBA2[3] = { 0.25, 0.5, 0.0 };
GLfloat vertFVBB2[3] = { 0.25,-0.5, 0.0 };
GLfloat vertFVBC2[3] = { -0.25, 0.5, 0.0 };
GLfloat vertFVBD2[3] = { -0.25,-0.5, 0.0 };
//Vertical Top
GLfloat vertFVTA2[3] = { 0.25, 0.5, 4.0 };
GLfloat vertFVTB2[3] = { 0.25,-0.5, 4.0 };
GLfloat vertFVTC2[3] = { -0.25, 0.5, 4.0 };
GLfloat vertFVTD2[3] = { -0.25,-0.5, 4.0 };
//Horizontal Base
GLfloat vertFHBA2[3] = { 1.75, 0.5, 3.5 };
GLfloat vertFHBB2[3] = { 1.75,-0.5, 3.5 };
GLfloat vertFHBC2[3] = { -0.25, 0.5, 3.5 };
GLfloat vertFHBD2[3] = { -0.25,-0.5, 3.5 };
//Horizontal Top
GLfloat vertFHTA2[3] = { 1.75, 0.5, 4.0 };
GLfloat vertFHTB2[3] = { 1.75,-0.5, 4.0 };
GLfloat vertFHTC2[3] = { -0.25, 0.5, 4.0 };
GLfloat vertFHTD2[3] = { -0.25,-0.5, 4.0 };

// TEXTURES: Vector texture names
GLuint texturID[NUM_MAX_TEXTURES] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

// dibuixa_EscenaGL: To draw a scene with OpenGL commands
void dibuixa_EscenaGL(char objecte, CColor col_object, bool ref_mat, bool sw_mat[4], bool textur)
{
	float altfar = 0;

	switch (objecte)
	{
// Truck drawing
	case ROBOT:
		glDisable(GL_TEXTURE_2D);
		robot(textur, texturID);
		break;
		
// Truck drawing
	case TRUCK:
		glDisable(GL_TEXTURE_2D);
		sea();
		truck(textur, texturID);
		break;

// To draw 3DS object
	case OBJ3DS:
		// Definition of reflexion properties (emission, ambient, diffuse, specular) of materials.
		SeleccionaColor(ref_mat, sw_mat, col_object);
		// To draw the 3DS object with textures (OBJECTE3DST) or without it (OBJECTE3DS)
		if (textur) glCallList(OBJECTE3DST);
			else glCallList(OBJECTE3DS);
		break;

// To draw OBJ object
	case OBJOBJ:
		// Definition of reflexion properties (emission, ambient, diffuse, specular) of materials.
		SeleccionaColor(ref_mat, sw_mat, col_object);
		// OBJ Object: To draw the OBJ object.
		glCallList(OBJECTEOBJ);
		break;

// To draw other objects
	default:
		// Definition of reflexion properties (emission, ambient, diffuse, specular) of materials.
		SeleccionaColor(ref_mat, sw_mat, col_object);
		dibuixa(objecte);
		break;
	}

// To send graphic commads to screen (OpenGL deprecated command)
	glFlush();

}


// dibuixa: This functions draws simple objects defined in GLUT library (glutSolid*()), accrding to obj parameter.
void dibuixa(char obj)
{
	switch(obj)
	{

// Cube
	case CUBE:
//		glColor3f(1.0,1.0,1.0);
		glPushMatrix();
		  glScalef(5.0f,5.0f,5.0f);
		  glutSolidCube(1.0);
		glPopMatrix();
		break;

// Sphere
	case SPHERE:
//		glColor3f(1.0,1.0,1.0);	
		glPushMatrix();
		  glScalef(5.0f,5.0f,5.0f);
		  //glutSolidSphere(1.0,40,40);
		  gluEsfera(1.0, 40, 40);
		glPopMatrix();
		break;

// Teapot
	case TEAPOT:
//		glColor3f(1.0,1.0,1.0);
		glPushMatrix();
		  glScalef(5.0f,5.0f,5.0f);
		  glutSolidTeapot(0.5);
		glPopMatrix();
		break;

	}

}


// OBJECTE Truck with texture images if tectxture is switched on
// Truck: Parameters:
//    - textu: Flag of textures switxhed on/off.
//    - VTextu: Image texture vector.
void truck(bool textu,GLuint VTextu[NUM_MAX_TEXTURES])
{

glPushMatrix();
  glTranslatef(0.0f,0.0f,20.0f);

 // ENGINE
 // Carrosseria texture
	if (textu)  
		{	GLfloat sPlane[4] = { 0.05f, 0.0f, 0.00f, 0.250f };
		  	GLfloat tPlane[4] = { 0.00f, 0.05f, 0.1f, 0.00f };
// Switch on planxa texture
			glBindTexture(GL_TEXTURE_2D,VTextu[5]) ;
			glEnable(GL_TEXTURE_2D);
			glTexGenfv(GL_S, GL_OBJECT_PLANE, sPlane);
			glTexGenfv(GL_T, GL_OBJECT_PLANE, tPlane);
			
			glTexGeni(GL_S,GL_TEXTURE_GEN_MODE,GL_OBJECT_LINEAR);
			glTexGeni(GL_T,GL_TEXTURE_GEN_MODE,GL_OBJECT_LINEAR);
			glEnable(GL_TEXTURE_GEN_S);
			glEnable(GL_TEXTURE_GEN_T);

		}

// Color carrosseria without texture
	glColor4f(0.5f,0.7f,1.0f,0.5f); 

	glPushMatrix();		
		glScalef(2.0f, 4.4f, 2.0f);
		glutSolidCube(10.0f);
	glPopMatrix();

// CABIN
// Lower cabin
	glPushMatrix();
		glTranslatef(0.0f,32.0f,0.0f);
		glScalef(4.0f, 2.0f, 2.0f);
		glutSolidCube(10.0f);
	glPopMatrix();

// Upper cabin
	glPushMatrix();
		glTranslatef(0.0f,32.0f,15.0f);
		glScalef(2.0f, 2.0f, 1.0f);
		glutSolidCube(10.0f);
	glPopMatrix();

// Rear cabin
	glPushMatrix();
		glTranslatef(0.0f,49.5f,12.5f);
		glScalef(4.0f, 1.5f, 4.5f);
		glutSolidCube(10.0f);
	glPopMatrix();

// CORNERS
// Left corner
	glPushMatrix() ;
	  glTranslatef(10.0f,22.0f,-10.0f);

  	  glBegin(GL_QUADS);  // Face with 4 sides
	 	glNormal3f(200.0f, 200.0f, 0.0f);
		glVertex3f(10.0f ,  0.0f , 0.0f ); //P1
		glVertex3f(10.0f , 0.0f , 20.0f ); //P2
		glVertex3f(0.0f , -10.0f ,20.0f ); //P3
		glVertex3f(0.0f ,  -10.0f ,0.0f ); //P4
	  glEnd();

	  glBegin(GL_POLYGON);  // Lower triangle
		glNormal3f(0.0f, 0.0f, -200.0f);
		glVertex3f(0.0f ,  0.0f , 0.0f );  // T1
		glVertex3f(10.0f ,  0.0f ,0.0f );  // P1
		glVertex3f(0.0f , -10.0f , 0.0f ); // P4
	  glEnd();

	  glBegin(GL_POLYGON);  // Triangle de dalt
		glNormal3f(0.0f, 0.0f, 200.0f);
		glVertex3f(0.0f ,  0.0f , 20.0f );	// T2
	    glVertex3f(0.0f , -10.0f , 20.0f ); // P3
		glVertex3f(10.0f ,  0.0f, 20.0f );  // P2
	  glEnd();
	glPopMatrix();

// Right corner
	glPushMatrix() ;
	  glTranslatef(-10.0f,22.0f,-10.0f);
	  glRotatef(-90.0f,0.0f,0.0f,1.0f);

  	  glBegin(GL_QUADS);  // Face with 4 sides
	 	glNormal3f(200.0f, 200.0f, 0.0f);
		glVertex3f(10.0f ,  0.0f , 0.0f ); //P1
		glVertex3f(10.0f , 0.0f , 20.0f ); //P2
		glVertex3f(0.0f , -10.0f ,20.0f ); //P3
		glVertex3f(0.0f ,  -10.0f ,0.0f ); //P4
	  glEnd();

	  glBegin(GL_POLYGON);  // Lower triangle
		glNormal3f(0.0f, 0.0f, -200.0f);
		glVertex3f(0.0f ,  0.0f , 0.0f );  // T1
		glVertex3f(10.0f ,  0.0f ,0.0f );  // P1
		glVertex3f(0.0f , -10.0f , 0.0f ); // P4
	  glEnd();

	  glBegin(GL_POLYGON);  // Upper triangle
		glNormal3f(0.0f, 0.0f, 200.0f);
		glVertex3f(0.0f ,  0.0f , 20.0f );	// T2
	    glVertex3f(0.0f , -10.0f , 20.0f ); // P3
		glVertex3f(10.0f ,  0.0f, 20.0f );  // P2
	  glEnd();
	glPopMatrix();


// WHEEL PROTECTIONS
// Wheel protections texture (metall)
//	if (textu)
//		{				
//			glBindTexture(GL_TEXTURE_2D,VTextu[5]) ;
//			glEnable(GL_TEXTURE_2D) ;
//			glTexGeni(GL_S,GL_TEXTURE_GEN_MODE,GL_SPHERE_MAP);
//			glTexGeni(GL_T,GL_TEXTURE_GEN_MODE,GL_SPHERE_MAP);
//			glTexGeni(GL_S,GL_TEXTURE_GEN_MODE,GL_OBJECT_LINEAR);
//			glTexGeni(GL_T,GL_TEXTURE_GEN_MODE,GL_OBJECT_LINEAR);
//			}

// Wheel protections color without texture
	glColor4f(0.5f,0.7f,1.0f,0.5f);

// Protection of left wheel
	glPushMatrix();		
		glTranslatef(10.0f, 0.0f, 3.0f);
		glBegin(GL_QUADS);
		//  glNormal3f(200.0f, 200.0f, 0.0f);
			glVertex3f(7.0f , -5.0f , 0.0f );
			glVertex3f(7.0f , 5.0f , 0.0f );
			glVertex3f(0.0f , 5.0f , 0.0f );
			glVertex3f(0.0f , -5.0f , 0.0f );

			glVertex3f(7.0f , -12.0f , -8.0f );
			glVertex3f(7.0f , -5.0f , 0.0f );
			glVertex3f(0.0f , -5.0f , 0.0f );
			glVertex3f(0.0f , -12.0f , -8.0f );

			glVertex3f(0.0f , 15.0f , -10.0f );
			glVertex3f(0.0f , 5.0f , 0.0f );
			glVertex3f(7.0f , 5.0f , 0.0f );
			glVertex3f(7.0f , 15.0f , -10.0f );

			glVertex3f(7.5f , -5.0f , -3.0f );
			glVertex3f(7.5f , 5.0f , -3.0f );
			glVertex3f(7.0f , 5.0f , 0.0f );
			glVertex3f(7.0f , -5.0f , 0.0f );
				
			glVertex3f(7.5f , -12.0f , -8.0f );
			glVertex3f(7.5f , -5.0f , -3.0f );
			glVertex3f(7.0f , -5.0f , 0.0f );
			glVertex3f(7.0f , -12.0f , -8.0f );
				
			glVertex3f(7.0f , 15.0f , -10.0f );
			glVertex3f(7.0f , 5.0f , 0.0f );
			glVertex3f(7.5f , 5.0f , -3.0f );
			glVertex3f(7.5f , 15.0f , -10.0f );

		glEnd();
	glPopMatrix();

// Protection of right wheel
	glPushMatrix();		
		glTranslatef(-16.0f, 0.0f, 3.0f);
		glBegin(GL_QUADS);
		//  glNormal3f(200.0f, 200.0f, 0.0f);
			glVertex3f(7.0f , -5.0f , 0.0f );
			glVertex3f(7.0f , 5.0f , 0.0f );
			glVertex3f(0.0f , 5.0f , 0.0f );
			glVertex3f(0.0f , -5.0f , 0.0f );

			glVertex3f(7.0f , -12.0f , -8.0f );
			glVertex3f(7.0f , -5.0f , 0.0f );
			glVertex3f(0.0f , -5.0f , 0.0f );
			glVertex3f(0.0f , -12.0f , -8.0f );

			glVertex3f(0.0f , 15.0f , -10.0f );
			glVertex3f(0.0f , 5.0f , 0.0f );
			glVertex3f(7.0f , 5.0f , 0.0f );
			glVertex3f(7.0f , 15.0f , -10.0f );

			glVertex3f(7.5f , -5.0f , -3.0f );
			glVertex3f(7.5f , 5.0f , -3.0f );
			glVertex3f(7.0f , 5.0f , 0.0f );
			glVertex3f(7.0f , -5.0f , 0.0f );
				
			glVertex3f(7.5f , -12.0f , -8.0f );
			glVertex3f(7.5f , -5.0f , -3.0f );
			glVertex3f(7.0f , -5.0f , 0.0f );
			glVertex3f(7.0f , -12.0f , -8.0f );
				
			glVertex3f(7.0f , 15.0f , -10.0f );
			glVertex3f(7.0f , 5.0f , 0.0f );
			glVertex3f(7.5f , 5.0f , -3.0f );
			glVertex3f(7.5f , 15.0f , -10.0f );
		glEnd();
	glPopMatrix();

// Engine Rack Texture
	if (textu)  
		{	GLfloat sPlane[4] = { 0.05f, 0.25f, 0.00f, 0.00f };
		  	GLfloat tPlane[4] = { 0.00f, 0.25f, 0.05f, 0.00f };
// Switch on texture
			glBindTexture(GL_TEXTURE_2D,VTextu[3]) ;
	
			glTexGenfv(GL_S, GL_OBJECT_PLANE, sPlane);
			glTexGenfv(GL_T, GL_OBJECT_PLANE, tPlane);
			
			glTexGeni(GL_S,GL_TEXTURE_GEN_MODE,GL_OBJECT_LINEAR);
			glTexGeni(GL_T,GL_TEXTURE_GEN_MODE,GL_OBJECT_LINEAR);
			glEnable(GL_TEXTURE_GEN_S);
			glEnable(GL_TEXTURE_GEN_T);
			glEnable(GL_TEXTURE_2D);
		}

// Engine Rack Color without texture
	glColor4f(0.5f,0.7f,1.0f,0.5f);	

// Engine Rack
	glPushMatrix();
		glTranslatef(0.0f,-22.0f,0.0f);
		glBegin(GL_QUADS);
		    glNormal3f(0.0f,-1.0f,0.0f);	
			glTexCoord2f(0.0f,0.0f);
			glVertex3f(-10.0f , -2.0f , -10.0f );
			glTexCoord2f(1.0f,0.00f);
			glVertex3f(10.0f , -2.0f , -10.0f );
			glTexCoord2f(1.0f,1.0);
			glVertex3f(10.0f , -2.0f , 10.0f );
			glTexCoord2f(0.0f,1.0f);	
			glVertex3f(-10.0f , -2.0f , 10.0f );
		glEnd();
	glPopMatrix();

// Switch off texture
	if (textu) glDisable(GL_TEXTURE_2D);

// Axe color without texture
	glColor4f(0.1f,0.4f,1.0f,0.5f);

// Front axle
	glPushMatrix();
	  glTranslatef(0.0f,0.0f,-10.0f);
	  glRotatef(90.0f,0.0f,1.0f,0.0f);
  	  glTranslatef(0.0f,0.0f,-13.0f);
	  gluCilindre(2,2,26.0f,6,1);
	glPopMatrix();
	
// Front right wheel 
	glPushMatrix();
		glTranslatef(-10.0f,0.0f,-10.0f);
		neumatic(textu,VTextu);
	glPopMatrix();

// Front left wheel
	glPushMatrix();
		glTranslatef(17.0f,0.0f,-10.0f);
		neumatic(textu,VTextu);
	glPopMatrix();

// Switch off texture
	if (textu) glDisable(GL_TEXTURE_2D);

// LIGHTHOUSES	
// Color lighthouses without texture
	glColor4f(1.0f,0.0f,0.0f,0.5f);

// Left Lighthouse	
	glPushMatrix();
		glTranslatef(-13.5f,-17.0f,-8.0f);
		glScalef(7.0f, 2.0f, 4.0f);
		glutSolidCube(1.0f);
	glPopMatrix();

// Right Lighthouse
	glPushMatrix();
		glTranslatef(13.5f,-17.0f,-8.0f);
		glScalef(7.0f, 2.0f, 4.0f);
		glRotatef(90.0f,1.0f,0.0f,0.0f); // To the texture
		glutSolidCube(1.0f);
	glPopMatrix();

// Front Lighthouse texture
	  if (textu)  
		{	GLfloat sPlane[4] = { 0.15f, 0.0f, 0.0f, 0.5f };
	  		GLfloat tPlane[4] = { 0.0f, 0.35f, 0.25f, 0.15f };
// Switch on texture
			glBindTexture(GL_TEXTURE_2D,VTextu[4]) ;
	
			glTexGenfv(GL_S, GL_OBJECT_PLANE, sPlane);
			glTexGenfv(GL_T, GL_OBJECT_PLANE, tPlane);
				
			glTexGeni(GL_S,GL_TEXTURE_GEN_MODE,GL_OBJECT_LINEAR);
			glTexGeni(GL_T,GL_TEXTURE_GEN_MODE,GL_OBJECT_LINEAR);
			glEnable(GL_TEXTURE_GEN_S);
			glEnable(GL_TEXTURE_GEN_T);
			glEnable(GL_TEXTURE_2D);
			}

// Front lighthouse color without texture
	glColor4f(1.0f,1.0f,1.0f,0.5f);

// Right Front lighthouse
	glPushMatrix();
		glTranslatef(-13.5f,-16.5f,-8.0f);
		glBegin(GL_QUADS);
			glNormal3f(0.0f,-1.0f,0.0f);	
			glTexCoord2f(0.0f,0.0f);
			glVertex3f(-3.5f , -2.0f , -2.0f );
			glTexCoord2f(1.0f,0.00f);
			glVertex3f(3.5f , -2.0f , -2.0f );
			glTexCoord2f(1.0f,1.0);
			glVertex3f(3.5f , -2.0f , 2.0f );
			glTexCoord2f(0.0f,1.0f);	
			glVertex3f(-3.5f , -2.0f , 2.0f );
		glEnd();	
	glPopMatrix();

// Left Front lighthouse
	glPushMatrix();
		glTranslatef(13.5f,-16.5f,-8.0f);
		glBegin(GL_QUADS);
			glNormal3f(0.0f,-1.0f,0.0f);	
			glTexCoord2f(0.0f,0.0f);
			glVertex3f(-3.5f , -2.0f , -2.0f );
			glTexCoord2f(1.0f,0.00f);
			glVertex3f(3.5f , -2.0f , -2.0f );
		glTexCoord2f(1.0f,1.0);
			glVertex3f(3.5f , -2.0f , 2.0f );
			glTexCoord2f(0.0f,1.0f);	
			glVertex3f(-3.5f , -2.0f , 2.0f );
		glEnd();
	glPopMatrix();

// Switch off texture
	if (textu) glDisable(GL_TEXTURE_2D);

// VIDRE CABINA (SENSE TEXTURA)
// Activar transparència
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);

// Cabin glass color without texture
	glColor4f(0.3f,0.8f,0.7f,0.5f);

// Glass
	glPushMatrix() ;
	  glTranslatef(0.0f,22.0f,10.0f);
	  glRotatef(-90.0f,1.0f,0.0f,0.0f);
	  glRotatef(90.0f,0.0f,1.0f,0.0f);
	  glTranslatef(0.0f,00.0f,-10.0f);

   	  glBegin(GL_QUADS);  // Face with 4 sides
	 	glNormal3f(200.0f, 200.0f, 0.0f);
		glVertex3f(10.0f ,  0.0f , 0.0f ); //P1
		glVertex3f(10.0f , 0.0f , 20.0f ); //P2
		glVertex3f(0.0f , -10.0f ,20.0f ); //P3
		glVertex3f(0.0f ,  -10.0f ,0.0f ); //P4
	  glEnd();

	  glBegin(GL_POLYGON);  // Lower triangle
		glNormal3f(0.0f, 0.0f, -200.0f);
		glVertex3f(0.0f ,  0.0f , 0.0f );  // T1
		glVertex3f(10.0f ,  0.0f ,0.0f );  // P1
		glVertex3f(0.0f , -10.0f , 0.0f ); // P4
	  glEnd();

	  glBegin(GL_POLYGON);  // Upper triangle
		glNormal3f(0.0f, 0.0f, 200.0f);
		glVertex3f(0.0f ,  0.0f , 20.0f );	// T2
	    glVertex3f(0.0f , -10.0f , 20.0f ); // P3
		glVertex3f(10.0f ,  0.0f, 20.0f );  // P2
	  glEnd();
	glPopMatrix();

// Switch off transparency
	glDisable(GL_BLEND);

// EXHAUST PIPE (WITHOUT TEXTURE)
// Exhaust Pipe color without texture
	glColor4f(1.0f,0.0f,0.0f,0.5f);

// Left Exhaust Pipe
	glPushMatrix();
		glTranslatef(18.0f,42.0f,10.0f);	
		gluCilindre(2,2,40.0f,12,1);	
	glPopMatrix();
	
// Right Exhaust Pipe
	glPushMatrix();
		glTranslatef(-18.0f,42.0f,10.0f);	
		gluCilindre(2, 2, 40.0f, 12, 1);
	glPopMatrix();

// BODYWORK
// Bodywork texture
	if (textu)
		{	GLfloat sPlane[4] = { 0.05f, 0.0f, 0.00f, 0.250f };
		  	GLfloat tPlane[4] = { 0.00f, 0.05f, 0.1f, 0.00f };

// Switch on texture
			glBindTexture(GL_TEXTURE_2D,VTextu[5]) ;
	
			glTexGenfv(GL_S, GL_OBJECT_PLANE, sPlane);
			glTexGenfv(GL_T, GL_OBJECT_PLANE, tPlane);
			
			glTexGeni(GL_S,GL_TEXTURE_GEN_MODE,GL_OBJECT_LINEAR);
			glTexGeni(GL_T,GL_TEXTURE_GEN_MODE,GL_OBJECT_LINEAR);
			glEnable(GL_TEXTURE_GEN_S);
			glEnable(GL_TEXTURE_GEN_T);
			glEnable(GL_TEXTURE_2D);
		}

// Color porta-eix motriu sense textura
	glColor4f(0.5f,0.7f,1.0f,0.5f);

// Porta-eix motriu mig
	glPushMatrix();
	  glTranslatef(0.0f,82.0f,-5.0f);
	  glScalef(1.0f, 5.0f, 1.0f);
	  glutSolidCube(10.0f);
	glPopMatrix();

	if (textu) glDisable(GL_TEXTURE_2D);

// Conjunt eixos i rodes eix mig
	glPushMatrix();
// Desplaçament Eix Mig
	  glTranslatef(0.0f,72.0f,0.0f);

// Axe color withou texture
	  glColor4f(0.1f,0.4f,1.0f,0.5f);

// Front Middle Axe
	  glPushMatrix();
	    glTranslatef(0.0f,0.0f,-10.0f);
	    glRotatef(90.0f,0.0f,1.0f,0.0f);
	    glTranslatef(0.0f,0.0f,-13.0f);
		gluCilindre(2, 2, 26.0f, 6, 1);
	  glPopMatrix();
	
// Roda Dreta Davantera Eix Mig Davanter
	  glPushMatrix();
	    glTranslatef(-10.0f,0.0f,-10.0f);
	    neumatic(textu,VTextu);
	  glPopMatrix();

// Roda Esquerra Davantera Eix Mig Davanter
	  glPushMatrix();
	    glTranslatef(17.0f,0.0f,-10.0f);
	    neumatic(textu,VTextu);
	  glPopMatrix();

// Switch off texture
	if (textu) glDisable(GL_TEXTURE_2D);

// Distance btween the two axes
	  glTranslatef(0.0f,25.0f,0.0f);

// Axe color without texture
	  glColor4f(0.1f,0.4f,1.0f,0.5f);

// Rear Middle Axe
	  glPushMatrix();
	    glTranslatef(0.0f,0.0f,-10.0f);
	    glRotatef(90.0f,0.0f,1.0f,0.0f);
	    glTranslatef(0.0f,0.0f,-13.0f);
		gluCilindre(2, 2, 26.0f, 6, 1);
	  glPopMatrix();
	
// Roda Dreta Davantera Eix Mig Darrera
	  glPushMatrix();
	    glTranslatef(-10.0f,0.0f,-10.0f);
	    neumatic(textu,VTextu);
	  glPopMatrix();

// Roda Esquerra Davantera Eix Mig Darrera
	  glPushMatrix();
	    glTranslatef(17.0f,0.0f,-10.0f);
	    neumatic(textu,VTextu);
	  glPopMatrix();

// End axes set and middle axe wheels
    glPopMatrix();

// Switch off texture
	if (textu) glDisable(GL_TEXTURE_2D);
		
// TOW	
// Bodywork texture
	if (textu)
		{	GLfloat sPlane[4] = { 0.05f, 0.0f, 0.00f, 0.250f };
		  	GLfloat tPlane[4] = { 0.00f, 0.05f, 0.1f, 0.00f };

// Switch on texture
			glBindTexture(GL_TEXTURE_2D,VTextu[5]);
	
			glTexGenfv(GL_S, GL_OBJECT_PLANE, sPlane);
			glTexGenfv(GL_T, GL_OBJECT_PLANE, tPlane);
			
			glTexGeni(GL_S,GL_TEXTURE_GEN_MODE,GL_OBJECT_LINEAR);
			glTexGeni(GL_T,GL_TEXTURE_GEN_MODE,GL_OBJECT_LINEAR);
			glEnable(GL_TEXTURE_GEN_S);
			glEnable(GL_TEXTURE_GEN_T);
			glEnable(GL_TEXTURE_2D);
		}


// Color plataforma sense textura
	glColor4f(0.5f,0.7f,1.0f,0.5f);

// Plataform
	glPushMatrix();
		glTranslatef(0.0f,127.0f,4.0f);
		glScalef(3.0f, 14.0f, 0.8f);
		glutSolidCube(10.0f);
	glPopMatrix();

// Tank texture
	if (textu)
		{	glBindTexture(GL_TEXTURE_2D,VTextu[6]);
			glTexGeni(GL_S,GL_TEXTURE_GEN_MODE,GL_OBJECT_LINEAR);
			glTexGeni(GL_T,GL_TEXTURE_GEN_MODE,GL_OBJECT_LINEAR);
			glEnable(GL_TEXTURE_2D);			
		}

// Tank color without texture
	glColor4f(0.9f,0.9f,1.0f,0.5f);

// Tank
	glPushMatrix();
	  glTranslatef(0.0f,60.0f,20.0f);
	  glScalef(0.75f,1.0f,0.5f);
	  glRotatef(270.0f,1.0f,0.0f,0.0f);
// Front Part
	  gluCilindre(20, 25, 5.0f, 25, 1);
	  glPushMatrix();
	  	glRotatef(180.0f,1.0f,0.0f,0.0f);
		gluDisc(0.0f, 20.0f, 25, 1);	
	  glPopMatrix();
// Central Part
	  glTranslatef(0.0f,0.0f,5.0f);
	  gluCilindre(25, 25, 125.0f, 25, 1);
// Rear Part
	  glPushMatrix();
		glTranslatef(0.0f,0.0f,125.0f);
		gluCilindre(25, 20, 5.0f, 25, 1);
		glTranslatef(0.0f,0.0f,5.0f);
		gluDisc(0.0f, 20.0f, 25, 1);	
	  glPopMatrix();
	glPopMatrix();

// Switch off texture
//	if (textu) glDisable(GL_TEXTURE_2D);

// Textura planxa
	if (textu)  
		{	
			GLfloat sPlane[4] = { 0.05f, 0.0f, 0.00f, 0.250f };
		  	GLfloat tPlane[4] = { 0.00f, 0.05f, 0.1f, 0.00f };
// Switch on texture
			glBindTexture(GL_TEXTURE_2D,VTextu[5]) ;
	
			glTexGenfv(GL_S, GL_OBJECT_PLANE, sPlane);
			glTexGenfv(GL_T, GL_OBJECT_PLANE, tPlane);
			
			glTexGeni(GL_S,GL_TEXTURE_GEN_MODE,GL_OBJECT_LINEAR);
			glTexGeni(GL_T,GL_TEXTURE_GEN_MODE,GL_OBJECT_LINEAR);
			glEnable(GL_TEXTURE_GEN_S);
			glEnable(GL_TEXTURE_GEN_T);
			glEnable(GL_TEXTURE_2D);
		}

// Color porta-eix motriu
	glColor4f(0.5f,0.7f,1.0f,0.5f);

// Porta-eix motriu darrera
	glPushMatrix();
	  glTranslatef(0.0f,172.0f,-5.0f);
	  glScalef(1.0f, 5.0f, 1.0f);
	  glutSolidCube(10.0f);
	glPopMatrix();

// Desactivar textura
	if (textu) glDisable(GL_TEXTURE_2D);

// Conjunt eixos i rodes eix darrera
	glPushMatrix();

// Desplaçament Eix Darrera
	  glTranslatef(0.0f,162.0f,0.0f);

// Color eix sense textura
	  glColor4f(0.1f,0.4f,1.0f,0.5f);

// Eix Darrera Davanter
	  glPushMatrix();
	    glTranslatef(0.0f,0.0f,-10.0f);
	    glRotatef(90.0f,0.0f,1.0f,0.0f);
	    glTranslatef(0.0f,0.0f,-13.0f);
		gluCilindre(2, 2, 26.0f, 6, 1);
	  glPopMatrix();
	
// Roda Dreta Davantera Eix Darrera Davanter
	  glPushMatrix();
	    glTranslatef(-10.0f,0.0f,-10.0f);
	    neumatic(textu,VTextu);
	  glPopMatrix();

// Roda Esquerra Davantera Eix Darrera Davanter
	  glPushMatrix();
	    glTranslatef(17.0f,0.0f,-10.0f);
	    neumatic(textu,VTextu);
	  glPopMatrix();

// Desactivar textura
	if (textu) glDisable(GL_TEXTURE_2D);

// Desplaçament entre dos eixos
	  glTranslatef(0.0f,25.0f,0.0f);

// Color eix sense textura
	  glColor4f(0.1f,0.4f,1.0f,0.5f);

// Eix Darrera Darrera
	  glPushMatrix();
		glTranslatef(0.0f,0.0f,-10.0f);
	 	glRotatef(90.0f,0.0f,1.0f,0.0f);
		glTranslatef(0.0f,0.0f,-13.0f);
		gluCilindre(2, 2, 26.0f, 6, 1);
	  glPopMatrix();
	
// Roda Dreta Davantera Eix Darrera Darrera
	  glPushMatrix();
	    glTranslatef(-10.0f,0.0f,-10.0f);
	    neumatic(textu,VTextu);
	  glPopMatrix();

// Roda Esquerra Davantera Eix Darrera Darrera
	  glPushMatrix();
	    glTranslatef(17.0f,0.0f,-10.0f);
	    neumatic(textu,VTextu);
	  glPopMatrix();
// Fi conjunt eixos i rodes eix darrera
	glPopMatrix();

// Fi dibuix Truck
glPopMatrix();

// Restaurar textura[0]
if (textu)
	{	glBindTexture(GL_TEXTURE_2D,VTextu[0]);
//		glTexGeni(GL_S,GL_TEXTURE_GEN_MODE,GL_OBJECT_LINEAR);
//		glTexGeni(GL_T,GL_TEXTURE_GEN_MODE,GL_OBJECT_LINEAR);
		glEnable(GL_TEXTURE_2D);			
	}
}

// Wheel drawing
// neumatic: Paràmetres:
//    - textur: Flag if textures switched on or off.
//    - VTextur: Image vector texture.
void neumatic(bool textur, GLuint VTextur[NUM_MAX_TEXTURES])
{
// Textura tire
	if (textur)  
		{	
// Switch on tire texture
			glBindTexture(GL_TEXTURE_2D,VTextur[1]) ;
			
			glTexGeni(GL_S,GL_TEXTURE_GEN_MODE,GL_OBJECT_LINEAR);
			glTexGeni(GL_T,GL_TEXTURE_GEN_MODE,GL_OBJECT_LINEAR);
			glEnable(GL_TEXTURE_2D);
		}

// Tire Color without texture
	glColor4f(0.2f,0.2f,0.2f,0.5f);	

	glPushMatrix();
// Upper Tire Top
	  glRotatef(90.0f,0.0f,1.0f,0.0f);
	  gluDisc(5.0f, 10.0f, RESOLUCIO_RODA, 1);

// Dibuix de la llanta
	  llanta(textur,VTextur);

// Textura neumàtic
	  if (textur)  
		{	
// Switch on tire texture
			glBindTexture(GL_TEXTURE_2D,VTextur[1]) ;	
			glTexGeni(GL_S,GL_TEXTURE_GEN_MODE,GL_OBJECT_LINEAR);
			glTexGeni(GL_T,GL_TEXTURE_GEN_MODE,GL_OBJECT_LINEAR);
			glEnable(GL_TEXTURE_2D);
		}

// Tire Color without texture
	glColor4f(0.2f,0.2f,0.2f,0.5f);	

// Tire Thick
	  glTranslatef(0.0f,0.0f,-6.0f);
	  gluCilindre(10, 10, 6.0f, RESOLUCIO_RODA, 1);
// Tire Upper Top
	  glRotatef(180.0f,0.0f,1.0f,0.0f);
	  gluDisc(5.0f, 10.0f, RESOLUCIO_RODA, 1);
// Tire drawing
	  llanta(textur,VTextur);
	glPopMatrix();

// Switch off textures
//	if (textur) glDisable(GL_TEXTURE_2D);

}

// Wheel tire drawing
// llanta: Paràmeters:
//    - textur: Flag of textures if switched on or not.
//    - VTextur: Image texture Vector.
void llanta(bool textur, GLuint VTextur[NUM_MAX_TEXTURES])
{

// Tire Texture
	if (textur)  
		{	GLfloat sPlane[4] = { 0.0f, -0.1f, 0.5f, 0.5f };
		  	GLfloat tPlane[4] = { 0.1f, 0.0f, 0.5f, 0.5f };
// Texture Switch on
			glBindTexture(GL_TEXTURE_2D,VTextur[2]) ;
			glEnable(GL_TEXTURE_2D) ;
		
			glTexGenfv(GL_S, GL_OBJECT_PLANE, sPlane);
			glTexGenfv(GL_T, GL_OBJECT_PLANE, tPlane);
			
			glTexGeni(GL_S,GL_TEXTURE_GEN_MODE,GL_OBJECT_LINEAR) ;
			glTexGeni(GL_T,GL_TEXTURE_GEN_MODE,GL_OBJECT_LINEAR) ;
			glEnable(GL_TEXTURE_GEN_S) ;
			glEnable(GL_TEXTURE_GEN_T) ;
		}

// Tire drawing (disk of 5 radius of light color)
	glColor4f(0.7f,0.7f,0.7f,0.5f);	
	gluDisc(0.0f, 5.0f, RESOLUCIO_RODA, 1);

}

// Ondulated sea
void sea(void)
{
	int i, j, step, it1, it2;
	//     GLfloat pi=3.14159;
	float angle, delay;

	//aigua plana
	/*	glColor3f(0.5,0.4,0.9);
	glNormal3f(0.0,0.0,1.0);
	glBegin(GL_POLYGON);
	glVertex3f(-250,-250,0);
	glVertex3f(250,-250,0);
	glVertex3f(250,250,0);
	glVertex3f(-250,250,0);
	glEnd();*/

// Ondulated water simulated from sinusoidal normal vectors
	step = 5;
	delay = 0;
	it1 = 0;

//   SeleccionaMaterial(MAT_DEFAULT);	
	float h = 2 * pi*step / 500;
	for (j = -250; j<250 - step; j = j + step)
	{

		delay = 1.0*h*it1;

		it2 = 0;
		glColor3f(0.5f, 0.4f, 0.9f);
		for (i = -250; i<250 - step; i = i + step)
		{
			glBegin(GL_POLYGON);
			angle = 1.0*it2*h * 15;
			glNormal3f(-cos(angle), 0, 1);
			glVertex3f(i, j, 0);

			angle = 1.0*(it2 + 1)*h * 15;
			glNormal3f(-cos(angle), 0, 1);
			glVertex3f(i + step, j, 0);

			angle = 1.0*(it2 + 1)*h * 15;
			glNormal3f(-cos(angle), 0, 1);
			glVertex3f(i + step, j + step, 0);
			glEnd();

			glBegin(GL_POLYGON);
			angle = 1.0*it2*h * 15;
			glNormal3f(-cos(angle), 0, 1);
			glVertex3f(i, j, 0);

			angle = 1.0*(it2 + 1)*h * 15;
			glNormal3f(-cos(angle), 0, 1);
			glVertex3f(i + step, j + step, 0);

			angle = 1.0*it2*h * 15;
			glNormal3f(-cos(angle), 0, 1);
			glVertex3f(i, j + step, 0);
			glEnd();
			it2++;
		}
		it1++;
	}

}

// OBJECTE Robot with texture images if tectxture is switched on
// Robot: Parameters:
//    - textu: Flag of textures switxhed on/off.
//    - VTextu: Image texture vector.
void robot(bool textu, GLuint VTextu[NUM_MAX_TEXTURES]) 
{
	//FOOT
	glPushMatrix();
	glTranslated(0.0, 0.0, 0.0);
		glBegin(GL_QUADS);
		glColor3f(0.0, 0.0, 1.0);
		// Floor Face
			glVertex3fv(vertA); //P1
			glVertex3fv(vertB); //P2
			glVertex3fv(vertD); //P3
			glVertex3fv(vertC); //P4
		// 1 side Face
			glVertex3fv(vertA); //P1
			glVertex3fv(vertB); //P2
			glVertex3fv(vertF); //P3
			glVertex3fv(vertE); //P4
		// 2 side Face
			glVertex3fv(vertA); //P1
			glVertex3fv(vertC); //P2
			glVertex3fv(vertG); //P3
			glVertex3fv(vertE); //P4
		// 3 side Face
			glVertex3fv(vertC); //P1
			glVertex3fv(vertD); //P2
			glVertex3fv(vertH); //P3
			glVertex3fv(vertG); //P4
		// 4 side Face
			glVertex3fv(vertB); //P1
			glVertex3fv(vertD); //P2
			glVertex3fv(vertH); //P3
			glVertex3fv(vertF); //P4
		// Ceiling Face
			glVertex3fv(vertE); //P1
			glVertex3fv(vertF); //P2
			glVertex3fv(vertH); //P3
			glVertex3fv(vertG); //P4
		glEnd();
	glPopMatrix();
	
	//LEG
	glPushMatrix();
		glTranslated(0.0, 0.0, 5.0);
		glColor3f(1.0, 0.0, 1.0);
		glutSolidCone(coneBase, coneHeight, 40, 40);
	glPopMatrix();

	//ARM
	glPushMatrix();
		glTranslated(0.0, 0.0, 17.5);
		glColor3f(0.5, 0.5, 0.5);
		glRotatef(90.0, 1.0, 0.0, 0.0);
		glutSolidCylinder(0.5, 15, 40, 40);
	glPopMatrix();
		
	//ELBOW
	glPushMatrix();
		glTranslated(0.0, 0.0, 17.5);
		glColor3f(1.0, 0.0, 0.0);
		glutSolidSphere(2, 40, 40);
	glPopMatrix();

	////////////////////////////////////////////////////////CLAMP - UPPER GREEN FINGER
	glPushMatrix();
		glColor3f(0.0, 0.5, 0.0);
		glTranslated(0.0, -15.0, 17.5);
		glRotatef(-90.0, 0.0, 0.0, 1.0);
		glRotatef(45.0, 0.0, 1.0, 0.0);
		glBegin(GL_QUADS);
		// Vertical Floor Face
			glVertex3fv(vertFVBA2); //P1
			glVertex3fv(vertFVBB2); //P2
			glVertex3fv(vertFVBD2); //P3
			glVertex3fv(vertFVBC2); //P4
									// Vertical 1 Side Face
			glVertex3fv(vertFVBA2); //P1
			glVertex3fv(vertFVBB2); //P2
			glVertex3fv(vertFVTB2); //P3
			glVertex3fv(vertFVTA2); //P4
									// Vertical 2 Side Face
			glVertex3fv(vertFVBA2); //P1
			glVertex3fv(vertFVBC2); //P2
			glVertex3fv(vertFVTC2); //P3
			glVertex3fv(vertFVTA2); //P4
									// Vertical 3 Side Face
			glVertex3fv(vertFVBC2); //P1
			glVertex3fv(vertFVBD2); //P2
			glVertex3fv(vertFVTD2); //P3
			glVertex3fv(vertFVTC2); //P4
									// Vertical 4 Side Face
			glVertex3fv(vertFVBB2); //P1
			glVertex3fv(vertFVBD2); //P2
			glVertex3fv(vertFVTD2); //P3
			glVertex3fv(vertFVTB2); //P4
									// Vertical Ceiling Face
			glVertex3fv(vertFVTA2); //P1
			glVertex3fv(vertFVTB2); //P2
			glVertex3fv(vertFVTD2); //P3
			glVertex3fv(vertFVTC2); //P4

			// Horizontal Floor Face
			glVertex3fv(vertFHBA2); //P1
			glVertex3fv(vertFHBB2); //P2
			glVertex3fv(vertFHBD2); //P3
			glVertex3fv(vertFHBC2); //P4
									// Horizontal 1 Side Face
			glVertex3fv(vertFHBA2); //P1
			glVertex3fv(vertFHBB2); //P2
			glVertex3fv(vertFHTB2); //P3
			glVertex3fv(vertFHTA2); //P4
									// Horizontal 2 Side Face
			glVertex3fv(vertFHBA2); //P1
			glVertex3fv(vertFHBC2); //P2
			glVertex3fv(vertFHTC2); //P3
			glVertex3fv(vertFHTA2); //P4
									// Horizontal 3 Side Face
			glVertex3fv(vertFHBC2); //P1
			glVertex3fv(vertFHBD2); //P2
			glVertex3fv(vertFHTD2); //P3
			glVertex3fv(vertFHTC2); //P4
									// Horizontal 4 Side Face
			glVertex3fv(vertFHBB2); //P1
			glVertex3fv(vertFHBD2); //P2
			glVertex3fv(vertFHTD2); //P3
			glVertex3fv(vertFHTB2); //P4
									// Horizontal Ceiling Face
			glVertex3fv(vertFHTA2); //P1
			glVertex3fv(vertFHTB2); //P2
			glVertex3fv(vertFHTD2); //P3
			glVertex3fv(vertFHTC2); //P4
		glEnd();
	glPopMatrix();

	////////////////////////////////////////////////////////CLAMP - LOWER BLUE FINGER
	glPushMatrix();
		glColor3f(0.0, 0.0, 0.5);
		glTranslated(0.0, -15.0, 17.5);
		glRotatef(90.0, 0.0, 0.0, 1.0);
		glRotatef(-135.0, 0.0, 1.0, 0.0);
		glBegin(GL_QUADS);

			// Vertical Floor Face
			glVertex3fv(vertFVBA1); //P1
			glVertex3fv(vertFVBB1); //P2
			glVertex3fv(vertFVBD1); //P3
			glVertex3fv(vertFVBC1); //P4
									// Vertical 1 Side Face
			glVertex3fv(vertFVBA1); //P1
			glVertex3fv(vertFVBB1); //P2
			glVertex3fv(vertFVTB1); //P3
			glVertex3fv(vertFVTA1); //P4
									// Vertical 2 Side Face
			glVertex3fv(vertFVBA1); //P1
			glVertex3fv(vertFVBC1); //P2
			glVertex3fv(vertFVTC1); //P3
			glVertex3fv(vertFVTA1); //P4
									// Vertical 3 Side Face
			glVertex3fv(vertFVBC1); //P1
			glVertex3fv(vertFVBD1); //P2
			glVertex3fv(vertFVTD1); //P3
			glVertex3fv(vertFVTC1); //P4
									// Vertical 4 Side Face
			glVertex3fv(vertFVBB1); //P1
			glVertex3fv(vertFVBD1); //P2
			glVertex3fv(vertFVTD1); //P3
			glVertex3fv(vertFVTB1); //P4
									// Vertical Ceiling Face
			glVertex3fv(vertFVTA1); //P1
			glVertex3fv(vertFVTB1); //P2
			glVertex3fv(vertFVTD1); //P3
			glVertex3fv(vertFVTC1); //P4

									// Horizontal Floor Face
			glVertex3fv(vertFHBA1); //P1
			glVertex3fv(vertFHBB1); //P2
			glVertex3fv(vertFHBD1); //P3
			glVertex3fv(vertFHBC1); //P4
									// Horizontal 1 Side Face
			glVertex3fv(vertFHBA1); //P1
			glVertex3fv(vertFHBB1); //P2
			glVertex3fv(vertFHTB1); //P3
			glVertex3fv(vertFHTA1); //P4
									// Horizontal 2 Side Face
			glVertex3fv(vertFHBA1); //P1
			glVertex3fv(vertFHBC1); //P2
			glVertex3fv(vertFHTC1); //P3
			glVertex3fv(vertFHTA1); //P4
									// Horizontal 3 Side Face
			glVertex3fv(vertFHBC1); //P1
			glVertex3fv(vertFHBD1); //P2
			glVertex3fv(vertFHTD1); //P3
			glVertex3fv(vertFHTC1); //P4
									// Horizontal 4 Side Face
			glVertex3fv(vertFHBB1); //P1
			glVertex3fv(vertFHBD1); //P2
			glVertex3fv(vertFHTD1); //P3
			glVertex3fv(vertFHTB1); //P4
									// Horizontal Ceiling Face
			glVertex3fv(vertFHTA1); //P1
			glVertex3fv(vertFHTB1); //P2
			glVertex3fv(vertFHTD1); //P3
			glVertex3fv(vertFHTC1); //P4
		glEnd();
	glPopMatrix();

	//WRIST
	glPushMatrix();
		glTranslated(0.0, -15.0, 17.5);
		glColor3f(1.0, 0.0, 0.0);
		glutSolidSphere(1, 40, 40);
	glPopMatrix();

}