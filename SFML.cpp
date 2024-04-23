/*
 * SFML.cpp
 *
 *  Created on: 9 de abr. de 2024
 *      Author: user
 */

#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>

int main()
{
    //Define a janela de desenho.
	sf::RenderWindow window(sf::VideoMode(640, 480), "SFML works!");

    window.setFramerateLimit(60); // Limita o frame hate.

    //Define com o nome shape um objeto do tipo circulo de raio 30.
    sf::CircleShape shape(30.f);
    shape.setFillColor(sf::Color::Green); //Seta a cor pra verde.

    std::srand(std::time(nullptr));

    int x= std::rand() % 640; // Vari�veis para a posi��o do circulo.
    int y= std::rand() % 480; // Vari�veis para a posi��o do circulo.
    int vx = 10, vy = 10;

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
        x = x + vx;
        y = y + vy;

        if((x >= window.getSize().x - shape.getRadius()*2) || (x <= 0)){
        	vx = -vx;
        }
        if((y >= window.getSize().y - shape.getRadius()*2) || (y <= 0)){
        	vy = -vy;
        }

        shape.setPosition(x, y);

        //Desenha a tela.
        window.clear();
        window.draw(shape);
        window.display();
    } //Fim do loop do jogo.

    return 0;
}

