/*
	Proyecto Final 2017-2
	Laboratorio de Computaci�n Gr�fica
	Cuarto de juegos

	Integrantes:
	Miranda Castro Ana Karen
	Torres Camacho Ismene Donaji

*/



#include "texture.h"
#include "figuras.h"
#include "Camera.h"
#include "cmodel/CModel.h"

static GLuint ciudad_display_list;	//Display List for the Monito

float posX = 0, posY = 2.5, posZ = -3.5, rotRodIzq = 0;
float giroMonito = 0;
float rotMusIzq = 0;
float rotBraIzq = 0;
float rotBraIzqEn = 0;
float rotBraDer = 0;
float rotBraDerEn = 0;
float rotV = 0.0;
float rotD = 0.0;
float MovJ = 0.0;
boolean actJ = FALSE;
boolean actJ1 = TRUE;


//Carga de Figuras

#define MAX_FRAMES 10
int i_max_steps = 25;
int i_curr_steps = 0;
typedef struct _frame
{
	//Variables para GUARDAR Key Frames
	float posX;		//Variable para PosicionX
	float posY;		//Variable para PosicionY
	float posZ;		//Variable para PosicionZ
	float incX;		//Variable para IncrementoX
	float incY;		//Variable para IncrementoY
	float incZ;		//Variable para IncrementoZ
	float rotRodIzq;
	float rotMusIzq;
	float rotMusIzqInc;
	float rotBraIzq;
	float rotBraIzqInc;
	float rotBraIzqEn;
	float rotBraIzqEnInc;
	float rotBraDer;
	float rotBraDerInc;
	float rotBraDerEn;
	float rotBraDerEnInc;
	float rotInc;
	float giroMonito;
	float giroMonitoInc;

}FRAME;

FRAME KeyFrame[MAX_FRAMES];
int FrameIndex = 0;			//introducir datos
bool play = false;
int playIndex = 0;


int w = 500, h = 500;
int frame = 0, time, timebase = 0;
char s[30];

CCamera objCamera;	//Create objet Camera

GLfloat g_lookupdown = 0.0f;    // Look Position In The Z-Axis (NEW) 

int font = (int)GLUT_BITMAP_HELVETICA_18;

//Variables para ultima posicion de la camara
float LastPosition[8];

//luces

GLfloat LightAmbient[] = { 0.0f, 0.0f, 0.0f, 1.0f }; 			// Ambient Light Values negro
GLfloat LightDiffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };				// Diffuse Light Values blanco
GLfloat LightSpecular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values blanco
bool	light = false;

GLfloat LightAmbient1[] = { 1.0f, 0.0f, 0.0f, 1.0f }; 			// Ambient Light Values 
GLfloat LightDiffuse1[] = { 0.5f, 0.0f, 0.8f, 1.0f };				// Diffuse Light Values 
GLfloat LightSpecular1[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values blanco
bool	light1 = false;
GLfloat LightPosition1[] = { 0.0f, 0.0f, 1.0f, 0.0f };

//bronze
GLfloat mat_ambient[] = { 0.2125, 0.1275, 0.054, 1.0 };					// Color background
GLfloat mat_diffuse[] = { 0.714, 0.4284, 0.18144 , 1.0 };					// Object Color main 
GLfloat mat_specular[] = { 0.3935, 0.2719, 0.1667, 1.0 };				// Specular color
GLfloat mat_shininess[] = { 0.2 * 128 };


//RUBY
GLfloat mat_Rambient[] = { 0.1745, 0.01175, 0.01175, 1.0 };					// Color background
GLfloat mat_Rdiffuse[] = { 0.61424,  0.04136, 0.04136, 1.0 };					// Object Color main 
GLfloat mat_Rspecular[] = { 0.727811, 0.626959, 0.626959, 1.0 };				// Specular color
GLfloat mat_Rshininess[] = { 0.6 * 128 };


CTexture text1;
CTexture text3;	//Flecha
CTexture text4;	//Pavimento
CTexture text5;	//Pasto01
CTexture text6;	//Casa01


CTexture textLibroCG;
CTexture textLibrolit;
CTexture textLibrolit1;
 
//Teztura puerta
CTexture textPuerta;
CTexture textPuerta_princ;
CFiguras cono;



float abrirPuerta = 0;


CFiguras fig1;
CFiguras fig2;
CFiguras fig3;
CFiguras fig4;	//Pasto01
CFiguras fig5;	//Casa01
CFiguras fig6;
CFiguras fig7;	//Para crear Monito


//Muebles 3ds
//CModel Mesa;
CModel sillon;
CModel sillon2;
CModel silla1;
CModel silla2;
CModel silla3;
CModel silla4;


//Casa
CFiguras techoCasa;
CFiguras pisoCasa;
CFiguras cubo;
CFiguras sky;

CTexture interior1;
CTexture interior2;
CTexture interior3;
CTexture interior4;
CTexture textTecho;
CTexture textTecho1;
CTexture textPiso;
CTexture ventana_prueba;
CTexture textCuadro1;
CTexture textCuadro2;


//Lampara
CFiguras lampara;
CTexture textLampara;

//Chimenea
CTexture Ladrillo_Ch;
CTexture exterior;

CTexture Ladrillo_sqrt;
CTexture fire_ch;
//Dodecaedro
CTexture Dodecaedro;


//// Mesa 
//Figura para mesa
CFiguras Base1;
//Textura Madera
CTexture MaderaBase1;
CTexture Madera;

void ciudad(){

	glPushMatrix(); //Camino1
	glTranslatef(23.5, 0.0, 0.0);
	glScalef(40, 0.1, 7);
	glDisable(GL_LIGHTING);
	fig3.prisma2(text4.GLindex, 0);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Camino2
	glTranslatef(-10, 0.0, 0.0);
	glScalef(40, 0.1, 7);
	glDisable(GL_LIGHTING);
	fig3.prisma2(text4.GLindex, 0);
	glEnable(GL_LIGHTING);
	glPopMatrix();
}

//Muebles Casa
void VentiladorT(){
	glPushMatrix();

		//material bronze
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
		glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
		glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

		glRotatef(rotV, 0, 1, 0);
		glPushMatrix();//Centro						   			
			fig7.esfera(0.75, 15, 15, 0);

			glPushMatrix();//Soporte										
				fig7.cilindro(0.15, 4.5, 15, 0);
				glPushMatrix();//Helices
					fig7.prisma(0.1, 15, 1.0, 0, 0, 0, 0, 0, 0);
				glPopMatrix();

				glPushMatrix();//Helices						
					glRotatef(22.5, 0, 1, 0);
					fig7.prisma(0.1, 15, 0.3, 0, 0, 0, 0, 0, 0);
				glPopMatrix();

				glPushMatrix();//Helices						
					glRotatef(45, 0, 1, 0);
					fig7.prisma(0.1, 15, 1.0, 0, 0, 0, 0, 0, 0);
				glPopMatrix();

				glPushMatrix();//Helices						
					glRotatef(67.5, 0, 1, 0);
					fig7.prisma(0.1, 15, 0.3, 0, 0, 0, 0, 0, 0);
				glPopMatrix();

				glPushMatrix();//Helices						
					glRotatef(90, 0, 1, 0);
					fig7.prisma(0.1, 15, 1.0, 0, 0, 0, 0, 0, 0);
				glPopMatrix();

				glPushMatrix();//Helices						
					glRotatef(112.5, 0, 1, 0);
					fig7.prisma(0.1, 15, 0.3, 0, 0, 0, 0, 0, 0);
				glPopMatrix();

				glPushMatrix();//Helices						
					glRotatef(135, 0, 1, 0);
					fig7.prisma(0.1, 15, 1.0, 0, 0, 0, 0, 0, 0);
				glPopMatrix();

				glPushMatrix();//Helices						
					glRotatef(157.5, 0, 1, 0);
					fig7.prisma(0.1, 15, 0.3, 0, 0, 0, 0, 0, 0);
				glPopMatrix();
			glPopMatrix(); //soporte
		glPopMatrix(); //centro
	glPopMatrix();//ventilador	
}
void Librero() {
	
	glPushMatrix();
		glTranslatef(-5.5, -20, 35);
		glRotatef(90, 1, 0, 0);
		fig5.prisma(1.0, 6.0, 50.0, MaderaBase1.GLindex, 0, 0, 0, 0, 0);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(-5.5, -20, 65);
		glRotatef(90, 1, 0, 0);
		fig5.prisma(1.0, 6.0, 50.0, MaderaBase1.GLindex, 0, 0, 0, 0, 0);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(-5.5, -20, 57.5);
		glRotatef(90, 1, 0, 0);
		fig5.prisma(0.5, 6.0, 50.0, MaderaBase1.GLindex, 0, 0, 0, 0, 0);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(-5.5, -20, 42.5);
		glRotatef(90, 1, 0, 0);
		fig5.prisma(0.5, 6.0, 50.0, MaderaBase1.GLindex, 0, 0, 0, 0, 0);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(-5.5, -45, 50);
		fig5.prisma(0.5, 6.0, 31.0, MaderaBase1.GLindex, 0, 0, 0, 0, 0);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(-5.5, 5, 50);
		fig5.prisma(0.5, 6.0, 31.0, MaderaBase1.GLindex, 0, 0, 0, 0, 0);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(-5.5, -20, 50);
		fig5.prisma(0.5, 6.0, 30.0, MaderaBase1.GLindex, 0, 0, 0, 0, 0);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(-5.5, -30, 50);
		fig5.prisma(0.5, 6.0, 30.0, MaderaBase1.GLindex, 0, 0, 0, 0, 0);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(-5.5, -10, 39);
		fig5.prisma(0.5, 6.0, 7.5, MaderaBase1.GLindex, 0, 0, 0, 0, 0);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(-5.5, -10, 61);
		fig5.prisma(0.5, 6.0, 7.5, MaderaBase1.GLindex, 0, 0, 0, 0, 0);
	glPopMatrix();
}
void Chimenea(void) {
	glPushMatrix();
		glTranslatef(82.8, 6.6, -50);
		fig5.prisma(17.0, 1.0, 10.0, Ladrillo_Ch.GLindex, 0, 0, 0, 0, 0);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(82, 0, -50);
		fig5.prisma(4.6, 0.6, 3.4, fire_ch.GLindex, 0, 0, 0, 0, 0);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(82, 2.2, -50);
		glRotatef(90, 1, 0, 0);
		glScalef(1, 6, 8);
		glEnable(GL_ALPHA_TEST);
		glAlphaFunc(GL_GREATER, 0.1);
			fig5.prisma2(Ladrillo_sqrt.GLindex, Ladrillo_sqrt.GLindex);
		glDisable(GL_ALPHA_TEST);
		glEnable(GL_LIGHTING);
	glPopMatrix();

}
void ventana()
{
	//Ventana_transparencia
	glPushMatrix();
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); //segundo hay varias GL_ONE			

	glBindTexture(GL_TEXTURE_2D, ventana_prueba.GLindex);
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	//VENTANA 
	glNormal3f(0.0, 0.0, -1.0); //normal sobre el eje -z
	glTexCoord2f(0.0, 0.0);	glVertex3f(5.85, 0.0, 4.2);
	glTexCoord2f(1.0, 0.0);	glVertex3f(8.2, 0.0, 4.2);
	glTexCoord2f(1.0, 1.0);	glVertex3f(8.2, 2.5, 4.2);
	glTexCoord2f(0.0, 1.0);	glVertex3f(5.85, 2.5, 4.2);
	glEnd();
	glDisable(GL_BLEND);
	glPopMatrix();
}
void Mesa ()
{

	glPushMatrix(); 
				glTranslatef(1.75, 1.55, -1.5);
				Base1.prisma3(0.05, 2.0, 1.0,Madera.GLindex);//Mesa

				glPushMatrix(); 
					glTranslatef(-0.25,-0.85,0);
					Base1.prisma3(0.1, 0.1,0.5,MaderaBase1.GLindex);//Base Pata 1

					glTranslatef(0.0,0.40, 0.30);
					Base1.prisma3(0.9, 0.1, 0.1,MaderaBase1.GLindex);//pata A

					glTranslatef(0.0,0.0, -0.50);
					Base1.prisma3(0.9, 0.1, 0.1,MaderaBase1.GLindex);//Pata B

				glPopMatrix();

				glPushMatrix(); 
					glTranslatef(0.25,-0.85, 0);
					Base1.prisma3(0.1, 0.1, 0.5 ,MaderaBase1.GLindex);//Base Pata 2						
					
					glTranslatef(0.0,0.40,0.30);
					Base1.prisma3(0.9,0.1,0.1,MaderaBase1.GLindex);//Pata A

					glTranslatef(0.0,0.0, -0.50);
					Base1.prisma3(0.9, 0.1, 0.1,MaderaBase1.GLindex);//Pata B
				
				glPopMatrix();


	glPopMatrix();		  			
	}
void cuadro(void) {
	glPushMatrix();
		glTranslatef(0, 0, 0);
		cubo.prisma3(5, 0.1, 10, textCuadro1.GLindex);
	glPopMatrix();
	return;
}
void poster(void) {
	glPushMatrix();
	glTranslatef(0, 0, 0);
	cubo.prisma(5, 0.07, 5, textCuadro2.GLindex, 0, 0, 0, 0, 0);
	glPopMatrix();
	return;
}
void book(GLuint textura3) {
	glPushMatrix();
	cubo.prisma(1, 1, 1, textura3, 0, 0, 0, 0, 0);
	glPopMatrix();
}

//Casa
void casa(void) {

	glPushMatrix(); //Paredes Interiores
	glTranslatef(0, 20, 0);
	fig1.pared_int(60.0, 85.0, 85.0, interior1.GLindex, interior2.GLindex, interior3.GLindex);
	glPopMatrix();

	glPushMatrix(); //Paredes Exteriores
	glTranslatef(0, 20, 0);
	fig1.pared_ext(60.3, 85.3, 85.3, exterior.GLindex);
	glPopMatrix();

	glPushMatrix();//Techo
	glTranslatef(0, 50, 0);
	techoCasa.techo(1, 90, 90, textTecho1.GLindex, textTecho.GLindex);
	glPopMatrix();

	glPushMatrix();//Piso
	glTranslatef(0, -10, 0);
	pisoCasa.piso(1, 85, 85, textPiso.GLindex);
	glPopMatrix();

	glPushMatrix();//Puerta		
	glTranslatef(33.5, 10, -42.7);
	glRotatef(abrirPuerta, 0, 1, 0);
	glTranslatef(5, -0.4, 0);
	pisoCasa.prisma(40, 8, 0.3, textPuerta_princ.GLindex, 0, 0, 0, 0, 0);
	glPopMatrix();

	glPushMatrix();//Pared frontal 1
	glTranslatef(-4.1, 14, -42.5);
	fig4.pared(47, 77, 0.3, interior4.GLindex, exterior.GLindex);
	glPopMatrix();

	glPushMatrix();//Pared frontal 2
	glTranslatef(37, 40, -42.5);
	fig4.pared(20.7, 11.5, 0.3, interior4.GLindex, exterior.GLindex);
	glPopMatrix();

	glPushMatrix();//Ventanas
	glTranslatef(-34, 37, -59.4);
	glScaled(8, 5, 4);
	ventana();
	glTranslatef(-2.3, 0, 0);
	ventana();
	glTranslatef(-2.3, 0, 0);
	ventana();
	glTranslatef(-2.3, 0, 0);
	ventana();
	glPopMatrix();


	return;
}





GLuint createDL()
{
	GLuint ciudadDL;
	//GLuint cieloDL;

	// Create the id for the list
	ciudadDL = glGenLists(1);
	// start list
	glNewList(ciudadDL, GL_COMPILE);
	// call the function that contains 
	// the rendering commands
	ciudad();
	//monito();
	// endList
	glEndList();

	return(ciudadDL);
}

void luces() {
	glLightfv(GL_LIGHT0, GL_AMBIENT, LightAmbient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, LightDiffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, LightSpecular);

	glLightfv(GL_LIGHT1, GL_AMBIENT, LightAmbient1);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, LightDiffuse1);
	glLightfv(GL_LIGHT1, GL_SPECULAR, LightSpecular1);
}

void InitGL(GLvoid)     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo	

	glEnable(GL_TEXTURE_2D);

	glShadeModel(GL_SMOOTH);


	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glEnable(GL_AUTO_NORMAL);
	glEnable(GL_NORMALIZE);

	text1.LoadBMP("01.bmp");
	text1.BuildGLTexture();
	text1.ReleaseImage();
	
	Ladrillo_Ch.LoadTGA("Chimenea/Ladrillo.tga");
	Ladrillo_Ch.BuildGLTexture();
	Ladrillo_Ch.ReleaseImage();

	Ladrillo_sqrt.LoadTGA("Chimenea/stonewall.tga");
	Ladrillo_sqrt.BuildGLTexture();
	Ladrillo_sqrt.ReleaseImage();

	fire_ch.LoadTGA("Chimenea/firech.tga");
	fire_ch.BuildGLTexture();
	fire_ch.ReleaseImage();

	//Texturas Casa--------------------------------------------------------------------------------------------------------------------

	//Paredes 
	interior1.LoadTGA("casa/verde_claro.tga");
	interior1.BuildGLTexture();
	interior1.ReleaseImage();

	interior2.LoadTGA("casa/pared_2.tga");
	interior2.BuildGLTexture();
	interior2.ReleaseImage();

	interior3.LoadTGA("casa/pared_3.tga");
	interior3.BuildGLTexture();
	interior3.ReleaseImage();

	interior4.LoadTGA("casa/pared_4.tga");
	interior4.BuildGLTexture();
	interior4.ReleaseImage();

	exterior.LoadTGA("casa/pared_exterior.tga");
	exterior.BuildGLTexture();
	exterior.ReleaseImage();

	//Techo
	textTecho.LoadBMP("casa/brick_3.bmp");
	textTecho.BuildGLTexture();
	textTecho.ReleaseImage();

	textTecho1.LoadTGA("casa/techo_1.tga");
	textTecho1.BuildGLTexture();
	textTecho1.ReleaseImage();

	//Piso
	textPiso.LoadTGA("casa/piso.tga");
	textPiso.BuildGLTexture();
	textPiso.ReleaseImage();

	//Ventana
	ventana_prueba.LoadTGA("Texturas/ventana_prueba.tga");
	ventana_prueba.BuildGLTexture();
	ventana_prueba.ReleaseImage();
	
	//Cuadros
	textCuadro1.LoadTGA("casa/cuadro1.tga");
	textCuadro1.BuildGLTexture();
	textCuadro1.ReleaseImage();

	textCuadro2.LoadTGA("casa/cuadro2.tga");
	textCuadro2.BuildGLTexture();
	textCuadro2.ReleaseImage();

	//Lampara
	textLampara.LoadBMP("casa/lampara.bmp");
	textLampara.BuildGLTexture();
	textLampara.ReleaseImage();

	//Juegos
	textLibroCG.LoadBMP("casa/codDaVinci.bmp");
	textLibroCG.BuildGLTexture();
	textLibroCG.ReleaseImage();

	textLibrolit.LoadBMP("casa/gamesofthrones.bmp");
	textLibrolit.BuildGLTexture();
	textLibrolit.ReleaseImage();

	textLibrolit1.LoadTGA("casa/hungergames.tga");
	textLibrolit1.BuildGLTexture();
	textLibrolit1.ReleaseImage();

	///////////////////////////////////////////
	//Cuidad
	text3.LoadTGA("city/arrow.tga");
	text3.BuildGLTexture();
	text3.ReleaseImage();

	text4.LoadTGA("city/pavimento.tga");
	text4.BuildGLTexture();
	text4.ReleaseImage();

	text5.LoadTGA("city/pasto01.tga");
	text5.BuildGLTexture();
	text5.ReleaseImage();

	text6.LoadTGA("city/casa01.tga");
	text6.BuildGLTexture();
	text6.ReleaseImage();
	//////////////////////////////////////////////
	//dodecaedro
	Dodecaedro.LoadTGA("12.tga");
	Dodecaedro.BuildGLTexture();
	Dodecaedro.ReleaseImage();

	//TextPuerta 
	textPuerta.LoadBMP("casa/door_3.bmp");
	textPuerta.BuildGLTexture();
	textPuerta.ReleaseImage();

	textPuerta_princ.LoadBMP("casa/door_3_4_puerta.bmp");
	textPuerta_princ.BuildGLTexture();
	textPuerta_princ.ReleaseImage();

	
	//Madera  texturas
	MaderaBase1.LoadTGA("Texturas/Madera_Base1.tga");
	MaderaBase1.BuildGLTexture();
	MaderaBase1.ReleaseImage();

	Madera.LoadTGA("Texturas/Madera.tga");
	Madera.BuildGLTexture();
	Madera.ReleaseImage();
	/////Mesa

	//..........................Modelos 3ds..........................//

	//Mesa._3dsLoad("Table 2.3ds");
	sillon._3dsLoad("Casa/sillon.3DS");
	sillon2._3dsLoad("Casa/sillon.3DS");
	

	silla1._3dsLoad("Modelos/silla1.3DS");
	silla2._3dsLoad("Modelos/silla2.3DS");
	silla3._3dsLoad("Modelos/silla3.3DS");
	silla4._3dsLoad("Modelos/silla4.3DS");
	//END NEW//////////////////////////////

	objCamera.Position_Camera(25, 2.5f, -10, 25, 2.5f, -11, 0, 1, 0);

	//NEW Crear una lista de dibujo
	ciudad_display_list = createDL();

	//NEW Iniciar variables de KeyFrames
	for (int i = 0; i<MAX_FRAMES; i++)
	{
		KeyFrame[i].posX = 0;
		KeyFrame[i].posY = 0;
		KeyFrame[i].posZ = 0;
		KeyFrame[i].incX = 0;
		KeyFrame[i].incY = 0;
		KeyFrame[i].incZ = 0;
		KeyFrame[i].rotRodIzq = 0;
		KeyFrame[i].rotMusIzq = 0;
		KeyFrame[i].rotMusIzqInc = 0;
		KeyFrame[i].rotBraIzq = 0;
		KeyFrame[i].rotBraIzqInc = 0;
		KeyFrame[i].rotBraDer = 0;
		KeyFrame[i].rotBraDerInc = 0;

		KeyFrame[i].rotBraIzqEn = 0;
		KeyFrame[i].rotBraIzqEnInc = 0;
		KeyFrame[i].rotBraDerEn = 0;
		KeyFrame[i].rotBraDerEnInc = 0;
		KeyFrame[i].rotInc = 0;
		KeyFrame[i].giroMonito = 0;
		KeyFrame[i].giroMonitoInc = 0;
	}
	//NEW//////////////////NEW//////////////////NEW//////////////////

}

void pintaTexto(float x, float y, float z, void *font, char *string)
{

	char *c;     //Almacena los caracteres a escribir
	glRasterPos3f(x, y, z);	//Posicion apartir del centro de la ventana
							//glWindowPos2i(150,100);
	for (c = string; *c != '\0'; c++) //Condicion de fin de cadena
	{
		glutBitmapCharacter(font, *c); //imprime
	}
}

void display(void){  // Creamos la funcion donde se dibuja

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glPushMatrix();

	//CONTROL DE LUCES
		luces();
		if (light)
			glEnable(GL_LIGHT0);
		else
			glDisable(GL_LIGHT0);

		glEnable(GL_LIGHTING);
	//FIN DE CONTROL DE LUCES

	glRotatef(g_lookupdown, 1.0f, 0, 0);
	gluLookAt(objCamera.mPos.x, objCamera.mPos.y, objCamera.mPos.z,
		objCamera.mView.x, objCamera.mView.y, objCamera.mView.z,
		objCamera.mUp.x, objCamera.mUp.y, objCamera.mUp.z);
	
	glPushMatrix();
		glPushMatrix(); //Creamos cielo
		glDisable(GL_LIGHTING);
		glTranslatef(0, 60, 0);
		fig1.skybox(130.0, 130.0, 130.0, text1.GLindex);
		glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //-------------------------------Creamos Silla1
		glTranslatef(30, 0, -19);
		glScalef(0.10,0.08,0.09);
		silla1.GLrender(NULL,_SHADED,1.0);
	glPopMatrix();	

	glPushMatrix(); //-------------------------------Creamos Silla2
		glTranslatef(30, 0, -13);
		glRotated(180,0,1,0);
		glScalef(0.03,0.03,0.03);
		silla2.GLrender(NULL,_SHADED,1.0);
	glPopMatrix();

	glPushMatrix(); //-------------------------------Creamos Silla3
		glTranslatef(34.7, 0, -16);
		glScalef(0.1,0.1,0.1);
		silla3.GLrender(NULL,_SHADED,1.0);
	glPopMatrix();

	glPushMatrix(); //-------------------------------Creamos Silla4
		glTranslatef(25.0, 0, -16);
		glScalef(0.03,0.03,0.03);
		glRotated(90,0,1,0);
		silla4.GLrender(NULL,_SHADED,1.0);
	glPopMatrix();
	
	glPushMatrix();//------------------Creamos  Mesa
		glTranslatef(25, -1, -13);
		glScalef(3,2,2);
		Mesa();
	glPopMatrix();

	glPushMatrix(); //-------------------------------Creamos chimenea
		glTranslatef(1, 1, 1);
		glScalef(0.5, 0.5, 0.5);
		Chimenea();
		glEnable(GL_LIGHTING);
	glPopMatrix();


	glPushMatrix();//--------------------------------dibuja poster 
		glTranslatef(42.75, 4, -15);
			poster();
		glEnable(GL_LIGHTING);
	glPopMatrix();	

	glPushMatrix();//...........................dibuja cuadro 
		glTranslatef(17.3, 4, -15);
			cuadro();
		glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();//------------------------------dodecaedro
		glTranslatef(28.5, 2.29, -16);
		glScalef(0.08, 0.08, 0.08);
		glRotatef(rotD * 2, 0, 1, 0);
		glRotatef(rotD, 1, 0, 0);
		glRotatef(rotD, 1, 0, 0);
		//glDisable(GL_LIGHTING);
		fig5.dodecaedro(Dodecaedro.GLindex, 0);
		glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();//ventilador y luz de techo
		glRotatef(0, 0, 1, 0);
		glTranslatef(30, 7.5, -15);
			glPushMatrix();
			glTranslatef(0, -2, 0);
			glScalef(1.2, 1.2, 1.2);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_Rdiffuse);
			glMaterialfv(GL_FRONT, GL_AMBIENT, mat_Rambient);
			glMaterialfv(GL_FRONT, GL_SPECULAR, mat_Rspecular);
			glMaterialfv(GL_FRONT, GL_SHININESS, mat_Rshininess);

			glLightfv(GL_LIGHT1, GL_POSITION, LightPosition1);			
			lampara.cono(2.0, 0.4, 100, textLampara.GLindex);

			glDisable(GL_LIGHTING);
			if (light1)
				glEnable(GL_LIGHT1);
			else
				glDisable(GL_LIGHT1);
			glEnable(GL_LIGHTING);
		glPopMatrix();
		glScalef(0.3, 0.3, 0.3);
		VentiladorT();
	glPopMatrix();

	glPushMatrix();//...........................Crea sillon 3ds
		glTranslatef(33.5, 0, -23);
		glScalef(0.04, 0.04, 0.06);
		glRotated(90,0,1,0);
		sillon.GLrender(NULL, _SHADED, 1.0);
		glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();//...........................Crea sillon2 3ds
		glTranslatef(38, 0, -27);
		glScalef(0.06, 0.04, 0.04);
		sillon.GLrender(NULL, _SHADED, 1.0);
		glEnable(GL_LIGHTING);
	glPopMatrix();
	/*
	glPushMatrix();//...........................Crea libro 1
		glTranslatef(20, 1.85, -26);
		glScalef(1, 0.1, 0.66);
		glDisable(GL_LIGHTING);
		book(textLibroCG.GLindex);
		glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();//...........................Crea Libro 2
		glTranslatef(19, 1.85, -26);
		glScalef(1, 0.1, 0.66);
		glRotatef(25, 0, 1, 0);
		glDisable(GL_LIGHTING);
		book(textLibrolit.GLindex);
		glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();//...........................Crea libro 3
		glTranslatef(20.8, 1.85, -27);
		glScalef(1, 0.1, 0.66);
		glRotatef(-60, 0, 1, 0);
		book(textLibrolit1.GLindex);
		glEnable(GL_LIGHTING);
	glPopMatrix();*/
		
	glPushMatrix();//----------------------Carretera
		glEnable(GL_COLOR_MATERIAL);
		glColor3f(1, 1, 1);
		glCallList(ciudad_display_list);
		glDisable(GL_COLOR_MATERIAL);
	glPopMatrix();

	
	glPushMatrix();//-----------------------Casa
		glScalef(1.0, 0.5, 1.0);
		glTranslatef(30, 3, -17.2);
		glRotatef(180, 0, 1, 0);
		glDisable(GL_LIGHTING);
		glScalef(0.3, 0.3, 0.3);
			casa();
		glEnable(GL_LIGHTING);
	glPushMatrix();
	
	glPushMatrix();//-----------------------librero
		glRotatef(180, 0, 1, 0);
		glTranslatef(-36.5, 22, -65.5);
		glScalef(.7, .7, .7);
			Librero();
	glPopMatrix();


	glPopMatrix();


	glEnable(GL_LIGHTING);
	glPopMatrix();


	glColor3f(1.0, 1.0, 1.0);

	glPopMatrix();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_LIGHTING);
	glColor3f(1.0, 0.0, 0.0);
	pintaTexto(-11, 12.0, -14.0, (void *)font, "Proyecto Laboratorio");
	pintaTexto(-11, 8.5, -14, (void *)font, s);
	glColor3f(1.0, 1.0, 1.0);
	glEnable(GL_LIGHTING);
	glEnable(GL_TEXTURE_2D);

	glutSwapBuffers();
}

void animacion(){
	fig3.text_izq -= 0.01;
	fig3.text_der -= 0.01;
	if (fig3.text_izq<-1)
		fig3.text_izq = 0;
	if (fig3.text_der<0)
		fig3.text_der = 1;

	//Movimiento del dado
	if (rotV<360)
	{
		rotV++;
		rotD++;
	}
	else
	{
		rotV = 0;
		rotD = 0;
	}
	if (actJ1)
	{
		MovJ = MovJ + 0.2;
		if (MovJ>8)
		{
			actJ1 = FALSE;
			actJ = TRUE;

			//rotD++;
		}
	}
	if (actJ)
	{
		MovJ = MovJ - 0.2;
		if (MovJ<0)
		{
			actJ = FALSE;
			actJ1 = TRUE;
			//rotD=0;
		}
	}
	if (play)
	{

		if (i_curr_steps >= i_max_steps) //end of animation between frames?
		{
			playIndex++;
			if (playIndex>FrameIndex - 2)	//end of total animation?
			{
				printf("termina anim\n");
				playIndex = 0;
				play = false;
			}
			else //Next frame interpolations
			{
				i_curr_steps = 0; //Reset counter
								  //Interpolation
				KeyFrame[playIndex].incX = (KeyFrame[playIndex + 1].posX - KeyFrame[playIndex].posX) / i_max_steps;		//100 frames
				KeyFrame[playIndex].incY = (KeyFrame[playIndex + 1].posY - KeyFrame[playIndex].posY) / i_max_steps;		//100 frames
				KeyFrame[playIndex].incZ = (KeyFrame[playIndex + 1].posZ - KeyFrame[playIndex].posZ) / i_max_steps;		//100 frames
				KeyFrame[playIndex].rotInc = (KeyFrame[playIndex + 1].rotRodIzq - KeyFrame[playIndex].rotRodIzq) / i_max_steps;		//100 frames
				KeyFrame[playIndex].giroMonitoInc = (KeyFrame[playIndex + 1].giroMonito - KeyFrame[playIndex].giroMonito) / i_max_steps;		//100 frames
				KeyFrame[playIndex].rotMusIzqInc = (KeyFrame[playIndex + 1].rotMusIzq - KeyFrame[playIndex].rotMusIzq) / i_max_steps;
				KeyFrame[playIndex].rotBraIzqInc = (KeyFrame[playIndex + 1].rotBraIzq - KeyFrame[playIndex].rotBraIzq) / i_max_steps;
				KeyFrame[playIndex].rotBraDerInc = (KeyFrame[playIndex + 1].rotBraDer - KeyFrame[playIndex].rotBraDer) / i_max_steps;

				KeyFrame[playIndex].rotBraIzqEnInc = (KeyFrame[playIndex + 1].rotBraIzqEn - KeyFrame[playIndex].rotBraIzqEn) / i_max_steps;
				KeyFrame[playIndex].rotBraDerEnInc = (KeyFrame[playIndex + 1].rotBraDerEn - KeyFrame[playIndex].rotBraDerEn) / i_max_steps;
			}
		}
		else
		{
			posX += KeyFrame[playIndex].incX;
			posY += KeyFrame[playIndex].incY;
			posZ += KeyFrame[playIndex].incZ;


			rotRodIzq += KeyFrame[playIndex].rotInc;
			giroMonito += KeyFrame[playIndex].giroMonitoInc;
			rotMusIzq += KeyFrame[playIndex].rotMusIzqInc;
			rotBraIzq += KeyFrame[playIndex].rotBraIzqInc;
			rotBraDer += KeyFrame[playIndex].rotBraDerInc;

			rotBraIzqEn += KeyFrame[playIndex].rotBraIzqEnInc;
			rotBraDerEn += KeyFrame[playIndex].rotBraDerEnInc;
			i_curr_steps++;
		}

	}

	frame++;
	time = glutGet(GLUT_ELAPSED_TIME);
	if (time - timebase > 1000) {
		sprintf(s, "FPS:%4.2f", frame*1000.0 / (time - timebase));
		timebase = time;
		frame = 0;
	}

	glutPostRedisplay();
}

void reshape(int width, int height)   // Creamos funcion Reshape
{
	if (height == 0)										// Prevenir division entre cero
	{
		height = 1;
	}

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista

	glFrustum(-0.1, 0.1, -0.1, 0.1, 0.1, 170.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y)  // Create Keyboard Function
{
	switch (key) {
	case 'w':   //Movimientos de camara
	case 'W':
		objCamera.Move_Camera(CAMERASPEED + 0.2);
		printf("\nMoveCamera mPos.X: %f",objCamera.mPos.x);
		LastPosition[0]= objCamera.mPos.x;
		printf("\nMoveCamera mPos.y: %f",objCamera.mPos.y);
		LastPosition[1]= objCamera.mPos.y;
		printf("\nMoveCamera mPos.z: %f",objCamera.mPos.z);
		LastPosition[2]= objCamera.mPos.z;
		printf("\nViewCamera mView.x: %f",objCamera.mView.x);
		LastPosition[3]=objCamera.mView.x;
		printf("\nViewCamera mView.y: %f",objCamera.mView.y);
		LastPosition[4]=objCamera.mView.y;
		printf("\nViewCamera mView.z: %f",objCamera.mView.z);
		LastPosition[5]=objCamera.mView.z;
		printf("\npCamera mUp.x: %f",objCamera.mUp.x);
		LastPosition[6]=objCamera.mUp.x;
		printf("\npCamera mUp.y: %f",objCamera.mUp.y);
		LastPosition[7]=objCamera.mUp.y;
		printf("\npCamera mUp.z: %f",objCamera.mUp.z);
		LastPosition[8]=objCamera.mUp.z;

		printf("\n");

		break;

	case 's':
	case 'S':
		objCamera.Move_Camera(-(CAMERASPEED + 0.2));
		printf("\nMoveCamera mPos.X: %f",objCamera.mPos.x);
		printf("\nMoveCamera mPos.X: %f",objCamera.mPos.x);
		LastPosition[0]= objCamera.mPos.x;
		printf("\nMoveCamera mPos.y: %f",objCamera.mPos.y);
		LastPosition[1]= objCamera.mPos.y;
		printf("\nMoveCamera mPos.z: %f",objCamera.mPos.z);
		LastPosition[2]= objCamera.mPos.z;
		printf("\nViewCamera mView.x: %f",objCamera.mView.x);
		LastPosition[3]=objCamera.mView.x;
		printf("\nViewCamera mView.y: %f",objCamera.mView.y);
		LastPosition[4]=objCamera.mView.y;
		printf("\nViewCamera mView.z: %f",objCamera.mView.z);
		LastPosition[5]=objCamera.mView.z;
		printf("\npCamera mUp.x: %f",objCamera.mUp.x);
		LastPosition[6]=objCamera.mUp.x;
		printf("\npCamera mUp.y: %f",objCamera.mUp.y);
		LastPosition[7]=objCamera.mUp.y;
		printf("\npCamera mUp.z: %f",objCamera.mUp.z);
		LastPosition[8]=objCamera.mUp.z;

		printf("\n");
		break;

	case 'a':
	case 'A':
		objCamera.Strafe_Camera(-(CAMERASPEED + 0.4));
		printf("\nMoveCamera mPos.X: %f",objCamera.mPos.x);
		LastPosition[0]= objCamera.mPos.x;
		printf("\nMoveCamera mPos.y: %f",objCamera.mPos.y);
		LastPosition[1]= objCamera.mPos.y;
		printf("\nMoveCamera mPos.z: %f",objCamera.mPos.z);
		LastPosition[2]= objCamera.mPos.z;
		printf("\nViewCamera mView.x: %f",objCamera.mView.x);
		LastPosition[3]=objCamera.mView.x;
		printf("\nViewCamera mView.y: %f",objCamera.mView.y);
		LastPosition[4]=objCamera.mView.y;
		printf("\nViewCamera mView.z: %f",objCamera.mView.z);
		LastPosition[5]=objCamera.mView.z;
		printf("\npCamera mUp.x: %f",objCamera.mUp.x);
		LastPosition[6]=objCamera.mUp.x;
		printf("\npCamera mUp.y: %f",objCamera.mUp.y);
		LastPosition[7]=objCamera.mUp.y;
		printf("\npCamera mUp.z: %f",objCamera.mUp.z);
		LastPosition[8]=objCamera.mUp.z;
		printf("\n");
		break;

	case 'd':
	case 'D':
		objCamera.Strafe_Camera(CAMERASPEED + 0.4);
		printf("\nMoveCamera mPos.X: %f",objCamera.mPos.x);
		LastPosition[0]= objCamera.mPos.x;
		printf("\nMoveCamera mPos.y: %f",objCamera.mPos.y);
		LastPosition[1]= objCamera.mPos.y;
		printf("\nMoveCamera mPos.z: %f",objCamera.mPos.z);
		LastPosition[2]= objCamera.mPos.z;
		printf("\nViewCamera mView.x: %f",objCamera.mView.x);
		LastPosition[3]=objCamera.mView.x;
		printf("\nViewCamera mView.y: %f",objCamera.mView.y);
		LastPosition[4]=objCamera.mView.y;
		printf("\nViewCamera mView.z: %f",objCamera.mView.z);
		LastPosition[5]=objCamera.mView.z;
		printf("\npCamera mUp.x: %f",objCamera.mUp.x);
		LastPosition[6]=objCamera.mUp.x;
		printf("\npCamera mUp.y: %f",objCamera.mUp.y);
		LastPosition[7]=objCamera.mUp.y;
		printf("\npCamera mUp.z: %f",objCamera.mUp.z);
		LastPosition[8]=objCamera.mUp.z;
		printf("\n");
		break;

	case 'k':		//
	case 'K':
		if (FrameIndex<MAX_FRAMES)
		{
			printf("frameindex %d\n", FrameIndex);

			KeyFrame[FrameIndex].posX = posX;
			KeyFrame[FrameIndex].posY = posY;
			KeyFrame[FrameIndex].posZ = posZ;

			KeyFrame[FrameIndex].rotRodIzq = rotRodIzq;
			KeyFrame[FrameIndex].giroMonito = giroMonito;
			KeyFrame[FrameIndex].rotMusIzq = rotMusIzq;
			KeyFrame[FrameIndex].rotBraIzq = rotBraIzq;
			KeyFrame[FrameIndex].rotBraDer = rotBraDer;

			KeyFrame[FrameIndex].rotBraIzqEn = rotBraIzqEn;
			KeyFrame[FrameIndex].rotBraDerEn = rotBraDerEn;


			FrameIndex++;
		}

		break;

	case 'l':
	case 'L':
		if (play == false && (FrameIndex>1))
		{

			posX = KeyFrame[0].posX;
			posY = KeyFrame[0].posY;
			posZ = KeyFrame[0].posZ;

			rotRodIzq = KeyFrame[0].rotRodIzq;
			giroMonito = KeyFrame[0].giroMonito;
			rotMusIzq = KeyFrame[0].rotMusIzq;
			rotBraIzq = KeyFrame[0].rotBraIzq;
			rotBraDer = KeyFrame[0].rotBraDer;



			//First Interpolation
			KeyFrame[playIndex].incX = (KeyFrame[playIndex + 1].posX - KeyFrame[playIndex].posX) / i_max_steps;		//100 frames
			KeyFrame[playIndex].incY = (KeyFrame[playIndex + 1].posY - KeyFrame[playIndex].posY) / i_max_steps;		//100 frames
			KeyFrame[playIndex].incZ = (KeyFrame[playIndex + 1].posZ - KeyFrame[playIndex].posZ) / i_max_steps;		//100 frames
			KeyFrame[playIndex].rotInc = (KeyFrame[playIndex + 1].rotRodIzq - KeyFrame[playIndex].rotRodIzq) / i_max_steps;		//100 frames
			KeyFrame[playIndex].giroMonitoInc = (KeyFrame[playIndex + 1].giroMonito - KeyFrame[playIndex].giroMonito) / i_max_steps;		//100 frames
			KeyFrame[playIndex].rotMusIzqInc = (KeyFrame[playIndex + 1].rotMusIzq - KeyFrame[playIndex].rotMusIzq) / i_max_steps;		//100 frames
			KeyFrame[playIndex].rotBraIzqInc = (KeyFrame[playIndex + 1].rotBraIzq - KeyFrame[playIndex].rotBraIzq) / i_max_steps;
			KeyFrame[playIndex].rotBraDerInc = (KeyFrame[playIndex + 1].rotBraDer - KeyFrame[playIndex].rotBraDer) / i_max_steps;
			KeyFrame[playIndex].rotBraIzqEnInc = (KeyFrame[playIndex + 1].rotBraIzqEn - KeyFrame[playIndex].rotBraIzqEn) / i_max_steps;
			KeyFrame[playIndex].rotBraDerEnInc = (KeyFrame[playIndex + 1].rotBraDerEn - KeyFrame[playIndex].rotBraDerEn) / i_max_steps;

			play = true;
			playIndex = 0;
			i_curr_steps = 0;
		}
		else
		{
			play = false;
		}
		break;

	case 'Z':
		light = !light;
		if (light)
			printf("encender luz 0\n");
		else
			printf("apagar luz 0\n");
		break;
	case 'z':
		light1 = !light1;
		if (light1)
			printf("encender luz 1\n");
		else
			printf("apagar luz 1\n");
		break;

	case '2':
		objCamera.Position_Camera(33, 3.5f, -16, 25, -3.5f, -16, 0, 1, 0);
		break;
	case '3':
		glRotatef(g_lookupdown, 1.0f, 0, 0);
		objCamera.Position_Camera(LastPosition[0],LastPosition[1],LastPosition[2], LastPosition[3], LastPosition[4],LastPosition[5],LastPosition[6],LastPosition[7], LastPosition[8]);
		break;
	case 27:        // Cuando Esc es presionado...
		exit(0);   // Salimos del programa
		break;
	default:        // Cualquier otra
		break;
	}

	glutPostRedisplay();
}

void arrow_keys(int a_keys, int x, int y)  // Funcion para manejo de teclas especiales (arrow keys)
{
	switch (a_keys) {
	case GLUT_KEY_PAGE_UP:
		objCamera.UpDown_Camera(CAMERASPEED);	
		printf("\nMoveCamera mPos.X: %f",objCamera.mPos.x);
		LastPosition[0]= objCamera.mPos.x;
		printf("\nMoveCamera mPos.y: %f",objCamera.mPos.y);
		LastPosition[1]= objCamera.mPos.y;
		printf("\nMoveCamera mPos.z: %f",objCamera.mPos.z);
		LastPosition[2]= objCamera.mPos.z;
		printf("\nViewCamera mView.x: %f",objCamera.mView.x);
		LastPosition[3]=objCamera.mView.x;
		printf("\nViewCamera mView.y: %f",objCamera.mView.y);
		LastPosition[4]=objCamera.mView.y;
		printf("\nViewCamera mView.z: %f",objCamera.mView.z);
		LastPosition[5]=objCamera.mView.z;
		printf("\npCamera mUp.x: %f",objCamera.mUp.x);
		LastPosition[6]=objCamera.mUp.x;
		printf("\npCamera mUp.y: %f",objCamera.mUp.y);
		LastPosition[7]=objCamera.mUp.y;
		printf("\npCamera mUp.z: %f",objCamera.mUp.z);
		LastPosition[8]=objCamera.mUp.z;

		printf("\n");
		break;

	case GLUT_KEY_PAGE_DOWN:
		objCamera.UpDown_Camera(-CAMERASPEED);
		printf("\nMoveCamera mPos.X: %f",objCamera.mPos.x);
		LastPosition[0]= objCamera.mPos.x;
		printf("\nMoveCamera mPos.y: %f",objCamera.mPos.y);
		LastPosition[1]= objCamera.mPos.y;
		printf("\nMoveCamera mPos.z: %f",objCamera.mPos.z);
		LastPosition[2]= objCamera.mPos.z;
		printf("\nViewCamera mView.x: %f",objCamera.mView.x);
		LastPosition[3]=objCamera.mView.x;
		printf("\nViewCamera mView.y: %f",objCamera.mView.y);
		LastPosition[4]=objCamera.mView.y;
		printf("\nViewCamera mView.z: %f",objCamera.mView.z);
		LastPosition[5]=objCamera.mView.z;
		printf("\npCamera mUp.x: %f",objCamera.mUp.x);
		LastPosition[6]=objCamera.mUp.x;
		printf("\npCamera mUp.y: %f",objCamera.mUp.y);
		LastPosition[7]=objCamera.mUp.y;
		printf("\npCamera mUp.z: %f",objCamera.mUp.z);
		LastPosition[8]=objCamera.mUp.z;
		printf("\n");
		break;

	case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		g_lookupdown -= 1.0f;
		printf("\nglookupdown: %f",g_lookupdown);
		printf("\nMoveCamera mPos.X: %f",objCamera.mPos.x);
		LastPosition[0]= objCamera.mPos.x;
		printf("\nMoveCamera mPos.y: %f",objCamera.mPos.y);
		LastPosition[1]= objCamera.mPos.y;
		printf("\nMoveCamera mPos.z: %f",objCamera.mPos.z);
		LastPosition[2]= objCamera.mPos.z;
		printf("\nViewCamera mView.x: %f",objCamera.mView.x);
		LastPosition[3]=objCamera.mView.x;
		printf("\nViewCamera mView.y: %f",objCamera.mView.y);
		LastPosition[4]=objCamera.mView.y;
		printf("\nViewCamera mView.z: %f",objCamera.mView.z);
		LastPosition[5]=objCamera.mView.z;
		printf("\npCamera mUp.x: %f",objCamera.mUp.x);
		LastPosition[6]=objCamera.mUp.x;
		printf("\npCamera mUp.y: %f",objCamera.mUp.y);
		LastPosition[7]=objCamera.mUp.y;
		printf("\npCamera mUp.z: %f",objCamera.mUp.z);
		LastPosition[8]=objCamera.mUp.z;
		printf("\n");
		break;

	case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		g_lookupdown += 1.0f;
		printf("\nglookupdown: %f",g_lookupdown);
		printf("\nMoveCamera mPos.X: %f",objCamera.mPos.x);
		LastPosition[0]= objCamera.mPos.x;
		printf("\nMoveCamera mPos.y: %f",objCamera.mPos.y);
		LastPosition[1]= objCamera.mPos.y;
		printf("\nMoveCamera mPos.z: %f",objCamera.mPos.z);
		LastPosition[2]= objCamera.mPos.z;
		printf("\nViewCamera mView.x: %f",objCamera.mView.x);
		LastPosition[3]=objCamera.mView.x;
		printf("\nViewCamera mView.y: %f",objCamera.mView.y);
		LastPosition[4]=objCamera.mView.y;
		printf("\nViewCamera mView.z: %f",objCamera.mView.z);
		LastPosition[5]=objCamera.mView.z;
		printf("\npCamera mUp.x: %f",objCamera.mUp.x);
		LastPosition[6]=objCamera.mUp.x;
		printf("\npCamera mUp.y: %f",objCamera.mUp.y);
		LastPosition[7]=objCamera.mUp.y;
		printf("\npCamera mUp.z: %f",objCamera.mUp.z);
		LastPosition[8]=objCamera.mUp.z;
		printf("\n");
		break;

	case GLUT_KEY_LEFT:
		objCamera.Rotate_View(-CAMERASPEED);
		printf("\nMoveCamera mPos.X: %f",objCamera.mPos.x);
		LastPosition[0]= objCamera.mPos.x;
		printf("\nMoveCamera mPos.y: %f",objCamera.mPos.y);
		LastPosition[1]= objCamera.mPos.y;
		printf("\nMoveCamera mPos.z: %f",objCamera.mPos.z);
		LastPosition[2]= objCamera.mPos.z;
		printf("\nViewCamera mView.x: %f",objCamera.mView.x);
		LastPosition[3]=objCamera.mView.x;
		printf("\nViewCamera mView.y: %f",objCamera.mView.y);
		LastPosition[4]=objCamera.mView.y;
		printf("\nViewCamera mView.z: %f",objCamera.mView.z);
		LastPosition[5]=objCamera.mView.z;
		printf("\npCamera mUp.x: %f",objCamera.mUp.x);
		LastPosition[6]=objCamera.mUp.x;
		printf("\npCamera mUp.y: %f",objCamera.mUp.y);
		LastPosition[7]=objCamera.mUp.y;
		printf("\npCamera mUp.z: %f",objCamera.mUp.z);
		LastPosition[8]=objCamera.mUp.z;
		printf("\n");
		break;

	case GLUT_KEY_RIGHT:
		objCamera.Rotate_View(CAMERASPEED);
		printf("\nMoveCamera mPos.X: %f",objCamera.mPos.x);
		LastPosition[0]= objCamera.mPos.x;
		printf("\nMoveCamera mPos.y: %f",objCamera.mPos.y);
		LastPosition[1]= objCamera.mPos.y;
		printf("\nMoveCamera mPos.z: %f",objCamera.mPos.z);
		LastPosition[2]= objCamera.mPos.z;
		printf("\nViewCamera mView.x: %f",objCamera.mView.x);
		LastPosition[3]=objCamera.mView.x;
		printf("\nViewCamera mView.y: %f",objCamera.mView.y);
		LastPosition[4]=objCamera.mView.y;
		printf("\nViewCamera mView.z: %f",objCamera.mView.z);
		LastPosition[5]=objCamera.mView.z;
		printf("\npCamera mUp.x: %f",objCamera.mUp.x);
		LastPosition[6]=objCamera.mUp.x;
		printf("\npCamera mUp.y: %f",objCamera.mUp.y);
		LastPosition[7]=objCamera.mUp.y;
		printf("\npCamera mUp.z: %f",objCamera.mUp.z);
		LastPosition[8]=objCamera.mUp.z;
		printf("\n");
		break;

	default:
		break;
	}
	glutPostRedisplay();
}

void menuKeyFrame(int id)
{
	switch (id)
	{
	case 0:
		if (FrameIndex<MAX_FRAMES)
		{
			printf("frameindex %d\n", FrameIndex);

			KeyFrame[FrameIndex].posX = posX;
			KeyFrame[FrameIndex].posY = posY;
			KeyFrame[FrameIndex].posZ = posZ;

			KeyFrame[FrameIndex].rotRodIzq = rotRodIzq;
			KeyFrame[FrameIndex].giroMonito = giroMonito;
			KeyFrame[FrameIndex].rotMusIzq = rotMusIzq;
			KeyFrame[FrameIndex].rotBraIzq = rotBraIzq;
			KeyFrame[FrameIndex].rotBraDer = rotBraDer;
			KeyFrame[FrameIndex].rotBraIzqEn = rotBraIzqEn;
			KeyFrame[FrameIndex].rotBraDerEn = rotBraDerEn;


			FrameIndex++;
		}


		break;

	case 1:
		if (play == false && FrameIndex >1)
		{

			posX = KeyFrame[0].posX;
			posY = KeyFrame[0].posY;
			posZ = KeyFrame[0].posZ;

			rotRodIzq = KeyFrame[0].rotRodIzq;
			giroMonito = KeyFrame[0].giroMonito;
			rotMusIzq = KeyFrame[0].rotMusIzq;
			rotBraIzq = KeyFrame[0].rotBraIzq;
			rotBraDer = KeyFrame[0].rotBraDer;
			//First Interpolation
			KeyFrame[playIndex].incX = (KeyFrame[playIndex + 1].posX - KeyFrame[playIndex].posX) / i_max_steps;		//100 frames
			KeyFrame[playIndex].incY = (KeyFrame[playIndex + 1].posY - KeyFrame[playIndex].posY) / i_max_steps;		//100 frames
			KeyFrame[playIndex].incZ = (KeyFrame[playIndex + 1].posZ - KeyFrame[playIndex].posZ) / i_max_steps;		//100 frames
			KeyFrame[playIndex].rotInc = (KeyFrame[playIndex + 1].rotRodIzq - KeyFrame[playIndex].rotRodIzq) / i_max_steps;		//100 frames
			KeyFrame[playIndex].giroMonitoInc = (KeyFrame[playIndex + 1].giroMonito - KeyFrame[playIndex].giroMonito) / i_max_steps;		//100 frames
			KeyFrame[playIndex].rotMusIzqInc = (KeyFrame[playIndex + 1].rotMusIzq - KeyFrame[playIndex].rotMusIzq) / i_max_steps;
			KeyFrame[playIndex].rotBraIzqInc = (KeyFrame[playIndex + 1].rotBraIzq - KeyFrame[playIndex].rotBraIzq) / i_max_steps;
			KeyFrame[playIndex].rotBraDerInc = (KeyFrame[playIndex + 1].rotBraDer - KeyFrame[playIndex].rotBraDer) / i_max_steps;
			KeyFrame[playIndex].rotBraIzqEnInc = (KeyFrame[playIndex + 1].rotBraIzqEn - KeyFrame[playIndex].rotBraIzqEn) / i_max_steps;
			KeyFrame[playIndex].rotBraDerEnInc = (KeyFrame[playIndex + 1].rotBraDerEn - KeyFrame[playIndex].rotBraDerEn) / i_max_steps;
			play = true;
			playIndex = 0;
			i_curr_steps = 0;
		}
		else
		{
			play = false;
		}
		break;


	}
}

void menu(int id)
{
	/*switch (id)
	{
	case 1:
	g_fanimacion^= true; //Activamos/desactivamos la animac�on
	break;


	}*/
}

int main(int argc, char** argv)   // Main Function
{
	int submenu;
	glutInit(&argc, argv); // Inicializamos OpenGL
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
	glutInitWindowSize(800, 600);	// Tama�o de la Ventana
	glutInitWindowPosition(0, 0);	//Posicion de la Ventana
	glutCreateWindow("Proyecto Final"); // Nombre de la Ventana
									 //glutFullScreen     ( );         // Full Screen
	InitGL();						// Parametros iniciales de la aplicacion
	glutDisplayFunc(display);  //Indicamos a Glut funci�n de dibujo
	glutReshapeFunc(reshape);	//Indicamos a Glut funci�n en caso de cambio de tamano
	glutKeyboardFunc(keyboard);	//Indicamos a Glut funci�n de manejo de teclado
	glutSpecialFunc(arrow_keys);	//Otras
	glutIdleFunc(animacion);

	submenu = glutCreateMenu(menuKeyFrame);
	glutAddMenuEntry("Guardar KeyFrame", 0);
	glutAddMenuEntry("Reproducir Animacion", 1);
	glutCreateMenu(menu);
	glutAddSubMenu("Animacion Monito", submenu);
	//glutAddMenuEntry	  ("Animacion Carro", 1);

	glutAttachMenu(GLUT_RIGHT_BUTTON);


	glutMainLoop();          // 

	return 0;
}
