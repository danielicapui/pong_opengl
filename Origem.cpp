#include "Grafico.h"
#include "Utills.h"
#include <istream>
//compile g++ -o program program.cpp -lopengl32 -lglew32 -lfreeglut -lglu32
//g++ - o grafo.exe Origem.cpp Grafico.cpp Utills.cpp - lopengl32 - lfreeglut - lglew32 - lglu32

int main(int argc, char** argv) {
	//tamanho da janela, pegamos no Grafico.cpp
	int x= getWidth(), y= getHeight(),intervalo =getIntervalo();
	glutInit(&argc, argv);
	
	///configurações de janela
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB| GLUT_DEPTH);

	glutInitWindowSize(x,y);
	glutInitWindowPosition(10,10);

	//nome da janela
	glutCreateWindow("Pong game");
	///fim
	
	///configurações de funcionalidades
	//exibe a função de callback void
	glutDisplayFunc(draw_pong);

	//atualiza o tamanho de tela
	//glutReshapeFunc(AlteraTamanhoJanela);

	//controla atualizações no teclado
	glutKeyboardFunc(keyboard_manage);
	
	//inicia um temporizador. após 33ms ativa a funcao timer
	//glutTimerFunc(33, timer, 1);
	glutTimerFunc(intervalo,update_pong,0);
	//motion do mouse
	//glutMotionFunc(MoveMouseBotaoPressionado);

	//caso mova o mouse
	//glutPassiveMotionFunc(MoveMouse);

	//controla atualizações no mouse
	//glutMouseFunc(GerenciaMouse);

	//controla a atualizações de teclas especias como home e setas
	glutSpecialFunc(special_manage);
	//glClearColor(1.0, 1.0, 1.0, 0.0);
	///fim
	
	//inicialização do loop
	Inicializa();
	glutMainLoop();
	return 0;
}
