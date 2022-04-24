#pragma once
#ifndef GRAFICO_H
#define GRAFICO_H
#include <windows.h>
#include <GL/glut.h>
#include <gl/GLU.h>
#include<iostream>
#include "Utills.h"
#include <cmath>
#include <limits>

void mostrar_figuras();//exibir as figuras
void timer(int value);//controle de tempo
void create_quadrado(void);//cria um quadrado
void AlteraTamanhoJanela(GLsizei, GLsizei);
void Desenha(void); //exibe na tela
void GerenciaTeclado(unsigned char, int, int); //controle de teclas ANSI
void GerenciaMouse(int, int, int, int); //função de controle de botões do mouse
void TeclasEspeciais(int, int, int); //função de controle teclas especiais
void Inicializa(void); //função de incializar opengl
//void Menu();
void MoveMouse(int,int); //função de movimento do mouse
void DesenhaTexto(char* string); //função de desenhar texto
void MoveMouseBotaoPressionado(int, int); //exibe o botão e posição presionado
void InicializarGrafo(Grafo); //modificar o programa

//pong lógica
class Raquete
{
	private:
		int width;
		int height;
		int speed;
		GLfloat position[3];
	public:
		//raquete 2d
		Raquete(int, int, int, GLfloat, GLfloat);
		//raquete 3d
		Raquete(int, int, int, GLfloat, GLfloat, GLfloat);
		int getWidth(); //return width
		int getHeight(); //return height
		int getSpeed(); //return speed
		GLfloat* getPosition(); //return x_pos,y_pos,z_pos
		GLfloat getPosition(int);//return position for index
		void setWidth(int);//set width
		void setHeight(int); //set Height
		void setSpeed(int);//set speed
		void setPosition(GLfloat, GLfloat);//set position x,y
		void showRaquete(); //mostrar tudo da raquete
};
class Bola
{
	private:
		int speed;
		int size;
		GLfloat direction[3];
		GLfloat position[3];
	public:
		//bola 2d
		Bola(int, int,GLfloat, GLfloat,GLfloat,GLfloat);
		//raquete 3d
		Bola(int, int,GLfloat, GLfloat, GLfloat,GLfloat,GLfloat,GLfloat);
		int getSize(); //return size
		int getSpeed(); //return speed
		GLfloat* getPosition(); //return x_pos,y_pos,z_pos
		GLfloat getPosition(int);//return position for index
		GLfloat* getDirection(); //return direction x,y,z
		GLfloat getDirection(int);//return direction for index
		void setSize(int);//set size
		void setSpeed(int);//set speed
		void setPosition(GLfloat, GLfloat);//set position x,y
		void setDirection(GLfloat, GLfloat);
		void showBola(); //mostrar tudo da raquete
};
int getHeight();//função que retona o valor global height
int getWidth(); //função que retorna o valor global width
int getIntervalo();//função que retorna o valor global intervalo
void draw_pong(void);//função de display
void update_pong(int); //função de atualzizaçaõ
void enable2D(int,int);//habilitar 2d
void draw_text(int,int,std::string);//desenhar placar
void draw_raquete(Raquete);//desenhar raquete
void keyboard_manage(unsigned char, int, int); //mover raquete jogador 1
void special_manage(int, int, int);//mover raquete jogador 2
void draw_bola(Bola);//desenha a bola
void update_bola();//atualizar a bola
void normalize_vector2d();//normaliza vetor
#endif