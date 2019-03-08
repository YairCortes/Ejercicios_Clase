/*Semestre 2017 - 2
NOMBRE: CORTÉS BENÍTEZ YAIR
GRUPO: 02
VERSION VISUALSTUDIO: 2017
PRACTICA: 5 (Brazo con dedos)
		BRAZO EL CUAL TIENE MOVIMIENTOS, ESTOS SE PUEDEN OBSERVAR AL OPRIMIR LAS SIGUIENTES TECLAS:
		(H-h): MOVIMIENTO DEL HOMBRO
		(C-c): MOVIMIENTO DEL CODO
		(M-m): MOVIMIENTO DE LA MUÑECA
		(Q-q): Movimiento de dedos (AQUI TUVE PROBLEMAS PARA DEFINIR LA ROTACION EXACTA DE LOS DEDOS
									Y SE MUEVEN PERO HACIA OTRO LADO, SALIENDOSE DE LA PALMA)
*/
#include "Main.h"

float transZ = -5.0f;
float transX = 0.0f;
float angleX = 0.0f;
float angleY = 0.0f;
int screenW = 0.0;
int screenH = 0.0;
float angHombro = 0.0f;
float angCodo = 0.0f;
float angMu = 0.0f;
float angDed = 0.0f;

GLfloat Position[]= { 0.0f, 3.0f, 0.0f, 1.0f };			// Light Position
GLfloat Position2[]= { 0.0f, 0.0f, -5.0f, 1.0f };			// Light Position

void InitGL ( void )     // Inicializamos parametros
{

	glShadeModel(GL_SMOOTH);							// Habilitamos Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing

	//Configuracion luz
	glLightfv(GL_LIGHT0, GL_POSITION, Position);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, Position2);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);


	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glEnable ( GL_COLOR_MATERIAL );
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void prisma(void)
{
	GLfloat vertice [8][3] = {
				{0.5 ,-0.5, 0.5},    //Coordenadas Vértice 0 V0
				{-0.5 ,-0.5, 0.5},    //Coordenadas Vértice 1 V1
				{-0.5 ,-0.5, -0.5},    //Coordenadas Vértice 2 V2
				{0.5 ,-0.5, -0.5},    //Coordenadas Vértice 3 V3
				{0.5 ,0.5, 0.5},    //Coordenadas Vértice 4 V4
				{0.5 ,0.5, -0.5},    //Coordenadas Vértice 5 V5
				{-0.5 ,0.5, -0.5},    //Coordenadas Vértice 6 V6
				{-0.5 ,0.5, 0.5},    //Coordenadas Vértice 7 V7
				};

		glBegin(GL_POLYGON);	//Front
			glNormal3f( 0.0f, 0.0f, 1.0f);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[1]);
		glEnd();

		glBegin(GL_POLYGON);	//Right
			glNormal3f( 1.0f, 0.0f, 0.0f);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[4]);
		glEnd();

		glBegin(GL_POLYGON);	//Back
			glNormal3f( 0.0f, 0.0f, -1.0f);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Left
			glNormal3f( -1.0f, 0.0f, 0.0f);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Bottom
			glNormal3f( 0.0f, -1.0f, 0.0f);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[2]);
			glVertex3fv(vertice[3]);
		glEnd();

		glBegin(GL_POLYGON);  //Top
			glNormal3f( 0.0f, 1.0f, 0.0f);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[7]);
		glEnd();
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer
	//glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(transX, 0.0f, transZ);
	glRotatef(angleY, 0.0, 1.0, 0.0);
	glRotatef(angleX, 1.0, 0.0, 0.0);
		//Poner Código Aquí.
	//HOMBRO(parteroja)
	glRotatef(angHombro, 0, 0, 1);
	glScalef(0.3, 0.5, 0.5);
	glColor3f(0.5, 0.0, 0.1);
	prisma();
	glScalef(3, 2, 1); //Se multiplica por el scalef anterior para que regrese a la escala anterior. (Se puede ocupar popMatrix
	//BICEP(parteazul)
	glTranslatef(0.5, 0, 0);
	glScalef(1, 0.5, 1);
	glColor3f(0, 0.2, 0.5);
	prisma();
	glScalef(1, 2, 1); //Para regresar a la escala original
	//CODO(partemorada)
	glTranslated(0.6, 0, 0);
	glRotatef(angCodo, 0, 0, 1); //Despues de la Traslacion debido a que si lo hacemos antes es como si el pibote estuviera en el bicep
	glScalef(0.2, 0.5, 1);
	glColor3f(0.1, 0.0, 0.8);
	prisma();
	glScalef(5, 2, 1);
	//ANTEBRAZO(parteblanca)
	glTranslatef(0.5, 0.0, 0);
	glScalef(0.8, 0.5, 0.5);
	glColor3f(1, 1, 1);
	prisma();
	glScalef(1.25, 2, 1);
	//MUÑECA(parteamarilla)
	glTranslatef(0.45, 0, 0);
	glRotatef(angMu, 0, 0, 1);
	glScalef(0.1, 0.5, 1);
	glColor3f(1, 1, 0);
	prisma();
	glScalef(10, 2, 1);
	//PALMA(parteAzulclaro)
	glTranslatef(0.35, 0, 0);
	glScalef(0.6, 0.5, 1);
	glColor3f(0, 1, 1);
	prisma();
	glScalef(1.66, 2, 1);
	//PULGAR
	glTranslatef(-0.2, 0.3, 0);
	glScalef(0.2, 0.07, 1);
	glColor3f(1, 0, 1);
	prisma();
	glScalef(5, 14.28, 1);
	//Falanje Pulgar
	glTranslatef(0, 0.035, 0);
	glRotatef(angDed, 1, 0, 0); //Dividir entre dos la Traslacion para agregar la rotacion del dedo pulgar
	glTranslatef(0, 0.035, 0);
	glScalef(0.2, 0.07, 1);
	glColor3f(0.2, 0.1, 0.8);
	prisma();
	glScalef(5, 14.28, 1);
	//INDICE
	glTranslatef(0.6, -0.15, 0);
	glRotatef(angDed, 1, 0, 0);
	glColor3f(0, 0.5, 0.1);
	glScalef(0.2, 0.07, 1);
	prisma();
	glScalef(5, 14.28, 1);
	//Indice2
	glTranslatef(0.30, 0, 0);
	glRotatef(angDed, 1, 0, 0);
	glScalef(0.4, 0.07, 1);
	glColor3f(1, 1, 1);
	prisma();
	glScalef(2.5, 14.28, 1);
	//MEDIO
	glTranslatef(-0.30,-0.13,0);
	glScalef(0.2, 0.07, 1);
	glColor3f(0.9, 0.1, 0.9);
	prisma();
	glScalef(5, 14.28, 1);
	//Medio2
	glTranslatef(0.35, 0, 0);
	glScalef(0.5, 0.07, 1);
	glColor3f(1, 0, 0.2);
	prisma();
	glScalef(2, 14.28, 1);
	//ANULAR
	glTranslatef(-0.35, -0.15, 0);
	glScalef(0.2, 0.07, 1);
	glColor3f(0, 0, 1);
	prisma();
	glScalef(5, 14.28, 1);
	//Anular2
	glTranslatef(0.34, 0, 0);
	glScalef(0.48, 0.075, 1);
	glColor3f(2, 0.1, 0);
	prisma();
	glScalef(2.08, 13.33, 1);
	//MEÑIQUE
	glTranslatef(-0.35, -0.16, 0);
	glScalef(0.2, 0.07, 1);
	glColor3f(1, 1, 0);
	prisma();
	glScalef(5, 14.28, 1);
	//Meñique2
	glTranslatef(0.25, 0, 0);
	glScalef(0.3, 0.07, 1);
	glColor3f(0, 1, 1);
	glColor3f(0.1, 0, 0.3);
	prisma();

	glutSwapBuffers ( );
  // Swap The Buffers
}

void reshape ( int width , int height )   // Creamos funcion Reshape
{
  if (height==0)										// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);
	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista
	//glOrtho(-5,5,-5,5,0.2,20);	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	//glLoadIdentity();									
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
		case 'w':
		case 'W':
			transZ +=0.2f;
			break;
		case 's':
		case 'S':
			transZ -=0.2f;
			break;
		case 'a':
		case 'A':
			transX +=0.2f;
			break;
		case 'd':
		case 'D':
			transX -=0.2f;
			break;
		case 'H':
			if (angHombro < 90)
				angHombro += 2.0f;
			break;
		case 'h':
			if (angHombro > -30)
				angHombro -= 2.0f;
			break;
		case 'c':
			if (angCodo < 90)
				angCodo += 2.0f;
			break;
		case 'C':
			if (angCodo > 0)
				angCodo -= 2.0f;
			break;
		case 'm':
			if (angMu < 90)
				angMu += 2.0f;
			break;
		case 'M':
			if (angMu > 0)
				angMu -= 2.0f;
			break;

		case 'q':
			if (angDed < 90)
				angDed += 2.0f;
			break;

		case 'Q':
			if (angDed > 0)
				angDed -= 2.0f;
			break;

		case 27:        // Cuando Esc es presionado...
			exit(0);   // Salimos del programa
			break;
		default:        // Cualquier otra
			break;
  }
	glutPostRedisplay();
}

void arrow_keys ( int a_keys, int x, int y )  // Funcion para manejo de teclas especiales (arrow keys)
{
  switch ( a_keys ) {
    case GLUT_KEY_UP:		// Presionamos tecla ARRIBA...
		angleX +=2.0f;
		break;
    case GLUT_KEY_DOWN:		// Presionamos tecla ABAJO...
		angleX -=2.0f;
		break;
	case GLUT_KEY_LEFT:
		angleY +=2.0f;
		break;
	case GLUT_KEY_RIGHT:
		angleY -=2.0f;
		break;
    default:
      break;
  }
  glutPostRedisplay();
}


int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  screenW = glutGet(GLUT_SCREEN_WIDTH);
  screenH = glutGet(GLUT_SCREEN_HEIGHT);
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 5"); // Nombre de la Ventana
  printf("Resolution H: %i \n", screenW);
  printf("Resolution V: %i \n", screenH);
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutMainLoop        ( );          // 

  return 0;
}
