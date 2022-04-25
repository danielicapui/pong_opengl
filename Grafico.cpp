#include "Grafico.h"
// classe raquete implementação
Raquete::Raquete(int width_, int height_, int speed_, GLfloat x_, GLfloat y_)
{
	this->width = width_;
	this->height = height_;
	this->speed = speed_;
	this->position[0] = x_;
	this->position[1] = y_;
	this->position[2] = 0.0f;
}
Raquete::Raquete(int width_, int height_, int speed_, GLfloat x_, GLfloat y_, GLfloat z_)
{
	this->width = width_;
	this->height = height_;
	this->speed = speed_;
	this->position[0] = x_;
	this->position[1] = y_;
	this->position[2] = z_;
}
void Raquete::setHeight(int height_)
{
	this->height = height_;
}
void Raquete::setWidth(int width_)
{
	this->width = width_;
}
void Raquete::setSpeed(int speed_)
{
	this->speed = speed_;
}
void Raquete::setPosition(GLfloat x_, GLfloat y_)
{
	this->position[0] = x_;
	this->position[1] = y_;
}
int Raquete::getHeight()
{
	return this->height;
}
int Raquete::getWidth()
{
	return this->width;
}
int Raquete::getSpeed()
{
	return this->speed;
}
GLfloat* Raquete::getPosition()
{
	return this->position;
}
GLfloat Raquete::getPosition(int index_)
{
	if (index_ >= 0 && index_ <= 2)
		return this->position[index_];
	else
		return -1;
}
void Raquete::showRaquete()
{
	std::cout << "posição x:" << this->getPosition(0) << " posição de y:" << this->getPosition(1) << " posição de z:" << this->getPosition(2) << std::endl;
	std::cout << "\n" << std::endl;
	std::cout << " width:" << this->getWidth() << " height:" << this->getHeight() << " speed:" << this->getSpeed();
}
//fim da classe Raquete

//class Bola
Bola::Bola(int speed_, int size_, GLfloat x_pos_, GLfloat y_pos_, GLfloat x_dir_, GLfloat y_dir_)
{
	this->speed = speed_;
	this->size = size_;
	this->position[0] = x_pos_;
	this->position[1] = y_pos_;
	this->position[2] = 0.0;
	this->direction[0] = x_dir_;
	this->direction[1] = y_dir_;
	this->direction[2] = 0.0;
}
Bola::Bola(int speed_, int size_, GLfloat x_pos_, GLfloat y_pos_,GLfloat z_pos_, GLfloat x_dir_, GLfloat y_dir_,GLfloat z_dir_)
{
	this->speed = speed_;
	this->size = size_;
	this->position[0] = x_pos_;
	this->position[1] = y_pos_;
	this->position[2] =z_pos_;
	this->direction[0] = x_dir_;
	this->direction[1] = y_dir_;
	this->direction[2] = z_dir_;
}
int Bola::getSize()
{
	return this->size;
}
int Bola::getSpeed()
{
	return this->speed;
}
GLfloat* Bola::getDirection()
{
	return this->direction;
}
GLfloat Bola::getDirection(int index)
{
	return this->direction[index];
}
GLfloat* Bola::getPosition()
{
	return this->position;
}
GLfloat Bola::getPosition(int index)
{
	return this->position[index];
}
void Bola::setSize(int size_)
{
	this->size = size_;
}
void Bola::setSpeed(int speed_)
{
	this->speed = speed_;
}
void Bola::setDirection(GLfloat x_dir_, GLfloat y_dir_)
{
	this->direction[0] = x_dir_;
	this->direction[1] = y_dir_;
}
void Bola::setPosition(GLfloat x_pos_, GLfloat y_pos_)
{
	this->position[0] = x_pos_;
	this->position[1] = y_pos_;
}
void Bola::showBola()
{
	std::cout<< "posição x:" << this->getPosition(0) << " posição de y:" << this->getPosition(1) << " posição de z:" << this->getPosition(2) << std::endl;
	std::cout<< "\n" <<std::endl;
	std::cout<< " size:" << this->getSize() << " speed:"<< this->getSpeed()<<std::endl;
	std::cout << "direção x:" << this->getDirection(0) << " direção y:" << this->getDirection(1) << " direção z:" << this->getDirection(2) << std::endl;
}
//cores
GLfloat r = 1.0, g = 0.5, b = 0.0;
/*posição do quadrado*/
GLfloat x = 0.0f, y = 0.05f;
GLfloat xf, yf, win;

GLint view_w, view_h;
//texto
char texto[30];

///jogo pong
//tamanho de tela e frames
	int width = 600;
	int height = 700;
	int intervalo = 1000/60;
//pontuação
	int score_p1 = 0;
	int score_p2 = 0;
//raquetes
	int base=50;
	int altura =10;
	int velocidade = 5;
	Raquete jogador_1(base, altura, velocidade,width/2,0.0+altura);
	Raquete jogador_2(base,altura,velocidade,width/2,height-altura-10);
//bola
	int tamanho_bola =8;
	int velocidade_bola =3;
	Bola bola_1(velocidade_bola,tamanho_bola,width/2,height/2,0.0f,-1.0f);
/// fim do jogo

int getWidth()
{
	return width;
}
int getHeight()
{
	return height;
}
int getIntervalo()
{
	return intervalo;
}
Grafo grafo;
void create_quadrado(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(r, g, b);
	glBegin(GL_POLYGON);
		glPointSize(0.5);
		glVertex2f(x, x);
		glVertex2f(y, x);
		glVertex2f(y, y);
		glVertex2f(x, y);
	glEnd();
	int width=GLUT_SCREEN_WIDTH;
	int height = GLUT_SCREEN_HEIGHT;
	glTranslatef(0.0f, 0.95f, 0.0f);
	glBegin(GL_POLYGON);
		glVertex2f(x,x);
		glVertex2f(y, x);
		glVertex2f(y, y);
		glVertex2f(x, y);
	glEnd();
	glTranslatef(0.95f, 0.0f, 0.0f);
	glBegin(GL_POLYGON);
		glVertex2f(x, x);
		glVertex2f(y, x);
		glVertex2f(y, y);
		glVertex2f(x, y);
	glEnd();
	//glGetFloatv(GL_MODELVIEW_MATRIX, matrix);
	glTranslatef(0.0f, -0.95f, 0.0f);
	glBegin(GL_POLYGON);
		glVertex2f(x, x);
		glVertex2f(y, x);
		glVertex2f(y, y);
		glVertex2f(x, y);
	glEnd();
	glFlush();
}
void mostrar_figuras()
{
	glutDisplayFunc(create_quadrado);
}
void timer(int value)
{
	r = r + 0.01;
	g = g + 0.01;
	b = b + 0.01;
	if (r > 1) r = 0;
	if (g > 1) g = 0;
	if (b > 1) b = 0;
	glutPostRedisplay();
	glutTimerFunc(33, timer, 1);
}
void AlteraTamanhoJanela(GLsizei w, GLsizei h) {
	// Especifica as dimensões da Viewport
	glViewport(0, 0, w, h);
	view_w = w;
	view_h = h;

	// Inicializa o sistema de coordenadas
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-win, win, -win, win);
	gluOrtho2D(0.0f, 250.0f * w / h, 0.0f, 250.0f);
}
// Inicializa parâmetros de rendering
void Inicializa(void)
{
	// Define a cor de fundo da janela de visualização como preta
	enable2D(width, height);
	glColor3f(1.0f,1.0f,1.0f);
	//glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	xf = 50.0f;
	yf = 50.0f;
	win = 250.0f;
}
void InicializarGrafo(Grafo grafo_)
{
	grafo.setValues(grafo_);
}
int desenhou = 0;
GLfloat gfPosX = 0.0;
GLfloat gfDeltaX=.0001;
void Desenha(void)
{
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glClear(GL_COLOR_BUFFER_BIT);
	// Define a cor corrente
	glColor3f(1.0,1.0,1.0);
	glScalef(1.0, 1.0, 1.0);
	//std::vector<std::string> vertices = grafo.getVertices();
	glBegin(GL_LINES);
	glPointSize(200);
		glVertex3f(gfPosX, 0.25f, 0.0);
		glVertex3f(1.0 - gfPosX, 0.75f, 0.0);
	glEnd();
	//glBegin(GL_POINTS);
	//	for (int i = 1; i < vertices.size()+1; i++)
	//	{
	//		float theta = 2.0f * 3.14* i / vertices.size();
	//		float xx = r * std::cos(theta);
	//		float yy = r * std::sin(theta);
	//		//draw the point
	//		glVertex2f(xx + 0.2f, yy +0.2f);
	//		//glVertex2f(((GLfloat)(i+1)/10) + 0.0f, 0.0f);
	//	}
	////glVertex2f(xf, 0.0f);
	////glVertex2f(xf, yf);
	////glVertex2f(0.0f, yf);
	//glEnd();
	// Exibe a posi��o do mouse na janela
	glColor3f(1.0f, 1.0f, 1.0f);
	DesenhaTexto(texto);

	glutSwapBuffers();
	glFlush();
	gfPosX += gfDeltaX;
	if (gfPosX >= 1.0||gfPosX <= 0.0)
		gfDeltaX = -gfDeltaX;
	glutPostRedisplay();
}

void GerenciaTeclado(unsigned char key, int x, int y)
{
	switch (key) 
	{
		case 'R':
		case 'r':// muda a cor corrente para vermelho
			glColor3f(1.0f, 0.0f, 0.0f);
			break;
		case 'G':
		case 'g':// muda a cor corrente para verde
			glColor3f(0.0f, 1.0f, 0.0f);
			break;
		case 'B':
		case 'b':// muda a cor corrente para azul
			glColor3f(0.0f, 0.0f, 1.0f);
			break;
	}
	glutPostRedisplay();
}

void GerenciaMouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON)
		if (state == GLUT_DOWN) {
			// Troca o tamanho do retângulo, que vai do centro da 
			// janela até a posição onde o usuário clicou com o mouse
			xf = ((2 * win * x) / view_w) - win;
			yf = (((2 * win) * (y - view_h)) / -view_h) - win;
		}
	glutPostRedisplay();
}

void TeclasEspeciais(int key, int x, int y)
{
	if (key == GLUT_KEY_UP) {
		win -= 20;
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluOrtho2D(-win, win, -win, win);
	}
	if (key == GLUT_KEY_DOWN) {
		win += 20;
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluOrtho2D(-win, win, -win, win);
	}
	glutPostRedisplay();
}

// Desenha um texto na janela GLUT
void DesenhaTexto(char* string)
{
	glPushMatrix();
	// Posi��o na tela onde o texto ser� colocado          
	glRasterPos2f(-win, win - (win * 0.08));
	// Exibe caracter a caracter
	while (*string)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, *string++);
	glPopMatrix();
}
// sobre a janela GLUT com um bot�o pressionado
void MoveMouseBotaoPressionado(int x, int y)
{
	sprintf_s(texto, "Botao pressionado: (%d,%d)", x, y);
	glutPostRedisplay();
}


void MoveMouse(int x, int y)
{
	sprintf_s(texto, "(%d %d)", x, y);
	glutPostRedisplay();
}
//*---------------------------------------------------------------------------------------------------------------*
//----------------------------------------------------------------------------------------------------------------*
//----------------------------------------------------------------------------------------------------------------*
//* pong lógica de desenho
void draw_pong(void)
{
	// limpar a tela.
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	//jogador_1.showRaquete();
	//jogador_2.showRaquete();
	// desenho das raquetes
	draw_raquete(jogador_1);
	draw_raquete(jogador_2);
	//desenho da bola
	draw_bola(bola_1);
	//desenho da pontuação no centro da tela
	//int x_pos = (((int)width/2)-80),y_pos=(height-15);
	int x_pos = 5,y_pos=(((int)height/2)+15);
	//int x_pos = 15, y_pos =height-15;
	std::string msg="Jogador 1:"+std::to_string(score_p1) + " <placar> Jogador 2:" + std::to_string(score_p2);
	draw_text(x_pos, y_pos, msg);
	// similar ao flush + eficiente
	glutSwapBuffers();
}
//função de atualização
void update_pong(int value)
{
	//atualizar posição da bola
	update_bola();
	//atualizações de terra em 1000/60 frames
	glutTimerFunc(intervalo, update_pong, 0);

	//obriga o redesenho da cena
	glutPostRedisplay();
}
void enable2D(int width_,int height_)
{
	//define a área de onde desenhar
	glViewport(0, 0, width_, height_);
	//avisam ao opengl que todas operações tem impacto na câmera
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//avisa o tipo de janela no caso 2D
	glOrtho(0.0f, width_, 0.0f, height_, 0.0f, 1.0f);
	//avisa ao opengl que todas operações tem impacto na cena, 'o que é desenhando'
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void draw_text(int x_, int y_, std::string conteudo)
{
	glPushMatrix();
	glRasterPos2d(x_, y_);
	//converte para aceita o parâmetro
	char* msg = (char*)conteudo.c_str();
	while (*msg)
	{
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, *msg++);
	}
	glPopMatrix();
}
void draw_bola(Bola bola_)
{
	glColor4f(1.0f, 0.0f, 1.0f, 0.0f);//purple
	glBegin(GL_QUAD_STRIP);
		glVertex2f(bola_.getPosition(0), bola_.getPosition(1));
		glVertex2f(bola_.getPosition(0),bola_.getSize()+bola_.getPosition(1));
		glVertex2f(bola_.getPosition(0)+bola_.getSize(), bola_.getPosition(1));
		glVertex2f(bola_.getPosition(0)+bola_.getSize(),bola_.getPosition(1)+bola_.getSize());
	glEnd();
}
void draw_raquete(Raquete raquete_)
{
	glColor3f(r, g, b);
	//[250,10] 1
	//[270,10] 2
	//[250,20] 3
	//[270,20] 4
	glBegin(GL_QUAD_STRIP);
		glVertex2f(raquete_.getPosition(0),raquete_.getPosition(1));
		glVertex2f(raquete_.getPosition(0)+raquete_.getWidth(), raquete_.getPosition(1));
		glVertex2f(raquete_.getPosition(0),raquete_.getPosition(1)+raquete_.getHeight());
		glVertex2f(raquete_.getPosition(0)+raquete_.getWidth(), raquete_.getPosition(1)+raquete_.getHeight());
	glEnd();
}
void keyboard_manage(unsigned char key_, int x_, int y_)
{
	switch (key_) 
	{
		case 'A':
		case 'a':// muda a cor corrente para vermelho
			 if(jogador_1.getPosition(0) >0)
				jogador_1.setPosition(jogador_1.getPosition(0)-jogador_1.getSpeed(), jogador_1.getPosition(1));
			break;
		case 'D':
		case 'd':// muda a cor corrente para verde
			if (jogador_1.getPosition(0) < width - jogador_1.getWidth())
				jogador_1.setPosition(jogador_1.getPosition(0)+jogador_1.getSpeed(), jogador_1.getPosition(1));
			break;
	}
}
void special_manage(int key_, int x_, int y_)
{
	if (key_ == GLUT_KEY_LEFT)
	{
		if(jogador_2.getPosition(0)>0)
			jogador_2.setPosition(jogador_2.getPosition(0)-jogador_2.getSpeed(), jogador_2.getPosition(1));
	}
	if (key_== GLUT_KEY_RIGHT) 
	{
		if(jogador_2.getPosition(0)<width-jogador_2.getWidth())
			jogador_2.setPosition(jogador_2.getPosition(0)+jogador_2.getSpeed(), jogador_2.getPosition(1));
	}
	if (key_ == GLUT_KEY_F1)
		exit(0);
}
void normalize_vector2d()
{
	GLfloat x_dir = bola_1.getDirection(0), y_dir = bola_1.getDirection(1);
	GLfloat tam = std::sqrt((x_dir * x_dir) + (y_dir * y_dir));
	if (tam != 0.0f)
	{
		tam = 1.0f / tam;
		bola_1.setDirection(x_dir * tam, y_dir * tam);
	}
}
void update_bola()
{
	GLfloat x_ = bola_1.getPosition(0), x_dir = bola_1.getDirection(0);
	GLfloat y_ = bola_1.getPosition(1),y_dir=bola_1.getDirection(1);
	int speed_ = bola_1.getSpeed();
	//std::cout << "valor de x:" << x_ << std::endl;
	//std::cout << "valor de y:" << y_ << std::endl;
	//std::cout << "valor de dx:" << x_dir << std::endl;
	//std::cout << "valor de dy:" << y_dir<< std::endl;
	x_ += x_dir * speed_;
	y_ += y_dir * speed_;
	bola_1.setPosition(x_,y_);

	if(y_<jogador_1.getPosition(1) + jogador_1.getHeight() && y_>jogador_1.getPosition(1) && x_<jogador_1.getPosition(0) + jogador_1.getWidth() && x_>jogador_1.getPosition(0))
	{
		GLfloat m = ((x_ - jogador_1.getPosition(0)) / jogador_1.getWidth()) - 0.5f;
		y_dir =std::fabs(y_dir);
		x_dir = m;
		bola_1.setDirection(x_dir, y_dir);
	}
	//verifica se a bola bateu no jogador 2
	if (y_ > jogador_2.getPosition(1) && y_ < jogador_2.getPosition(1) + jogador_2.getHeight() && x_<jogador_2.getPosition(0) + jogador_2.getWidth() && x_>jogador_2.getPosition(0))
	{
		GLfloat m = ((x_ - jogador_2.getPosition(0)) / jogador_2.getWidth()) - 0.5f;
		y_dir =-std::fabs(y_dir);
		x_dir = m;
		bola_1.setDirection(x_dir, y_dir);
	}
	//verifica se a bola bateu no lado esquerdo da tela
	if (x_<=0)
	{
		x_dir =std::fabs(x_dir);
		bola_1.setDirection(x_dir,y_dir);
	}
	//vertifica se a bola bateu no lado direito da tela
	if (x_ >=width)
	{
		x_dir =-std::fabs(x_dir);
		bola_1.setDirection(x_dir, y_dir);
	}
	//verifica se a bola bateu em cima e adiciona pontos ao j1
	if (y_>=height) {
		score_p1++;
		x_ = getWidth() / 2;
		y_ = getHeight() / 2;
		x_dir =-std::fabs(x_dir);
		y_dir =-1;
		bola_1.setPosition(x_,y_);
		bola_1.setDirection(x_dir, y_dir);
	}
	//verifica se a bola bateu em baixo e adiciona pontos ao j2
	if (y_<=0) {
		score_p2++;
		x_ =getWidth() / 2;
		y_ = getHeight() / 2;
		x_dir =std::fabs(x_dir);
		y_dir =1;
		bola_1.setPosition(x_, y_);
		bola_1.setDirection(x_dir, y_dir);
	}
	normalize_vector2d();
}