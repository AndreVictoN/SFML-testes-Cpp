/*
 * Andre_Nascimento_Info2_Classes_09_04.cpp
 *
 *  Created on: 15 de abr. de 2024
 *      Author: Revii
 */

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <iostream>
#include <ctime>
#include <vector>

class Bola{
private:
	sf::Color cor;
	sf::CircleShape shape;

public:
	int x,y,vx,vy,raio;

	Bola(){
		x = y = vx = vy = 0;
		raio = 30;
		cor = sf::Color::White;

		this->shape.setRadius(raio);
		this->shape.setPosition(x,y);
		this->shape.setFillColor(cor);
		this->shape.setOutlineColor(sf::Color::White);
		this->shape.setOutlineThickness(0.6f);
	}

	Bola(int x, int y, int vx, int vy, sf::Color cor, int raio){
		this->x = x;
		this->y = y;
		this->vx = vx;
		this->vy = vy;
		this->raio = raio;
		this->cor = cor;

		this->shape.setRadius(raio);
		this->shape.setPosition(x,y);
		this->shape.setFillColor(cor);
		this->shape.setOutlineColor(sf::Color::Black);
		this->shape.setOutlineThickness(0.6f);
	}

	void mover(){
		x = x + vx;
		y = y + vy;

		if((x >= 640 - shape.getRadius() * 2) || (x <= 0)){
			vx = -vx;
		}
		if((y >= 480 - shape.getRadius() * 2) || (y <= 0)){
			vy = -vy;
		}

		this->shape.setPosition(x,y);
	}

	void draw(sf::RenderWindow &window){
		window.draw(shape);
	}
};

Bola criarbolinha(){
	int x = std::rand() % 600;
	int y = std::rand() % 400;
	int vx = 10;
	int vy = 10;
	int raio = 30;

	std::vector <sf::Color> cores;
	cores.push_back(sf::Color::Magenta);
	cores.push_back(sf::Color::Blue);
	cores.push_back(sf::Color::Black);
	cores.push_back(sf::Color::Red);
	cores.push_back(sf::Color::Green);
	cores.push_back(sf::Color::Cyan);

	sf::Color cor(cores[std::rand() % 7]);

	Bola Bola(x,y,vx,vy,cor,raio);
	return Bola;
}

int main()
{
    //Define a janela de desenho.
	sf::RenderWindow window(sf::VideoMode(640, 480), "SFML works!");

    window.setFramerateLimit(60); // Limita o frame hate.

    std::vector <Bola> bolas;

    std::srand(std::time(nullptr));

    for(int i = 0; i < 3; i++){
    	Bola bola = criarbolinha();
    	bolas.push_back(bola);
    }

    while (window.isOpen()) // Loop do jogo.
    {
    	//Pega os eventos tipo fechar a janela ou
    	//Digitar um tecla ou clicar o mouse.
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        //Atualiza os objetos do 'mundo'
        for(int i = 0; i < 3; i++){
        	bolas.at(i).mover();
        }

        //Desenha a tela.
        window.clear(sf::Color::White);
        for(int i = 0; i < 3; i++){
        	bolas.at(i).draw(window);
        }
        window.display();


    } //Fim do loop do jogo.

    return 0;
}
