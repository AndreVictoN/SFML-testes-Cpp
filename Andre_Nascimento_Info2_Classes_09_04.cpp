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
public:
	sf::CircleShape bola;
	int x;
	int y;
	int a;
	int b;
	int c;
	int d;
	int vx;
	int vy;
	int va;
	int vb;
	int vc;
	int vd;
};

int main()
{
    //Define a janela de desenho.
	sf::RenderWindow window(sf::VideoMode(640, 480), "SFML works!");

    window.setFramerateLimit(60); // Limita o frame hate.

    std::vector <Bola> bolas;

    std::srand(std::time(nullptr));

    Bola Bola1;
    Bola1.bola.setRadius(30.f); //Define com o nome shape um objeto do tipo circulo de raio 30.
    Bola1.bola.setFillColor(sf::Color::Green); //Seta a cor pra verde.
    Bola1.x = std::rand() % 630; // Variáveis para a posição do circulo.
    Bola1.y = std::rand() % 470; // Variáveis para a posição do circulo.
    Bola1.vx = 10;
    Bola1.vy = 10;

    bolas.push_back(Bola1);

    Bola Bola2;
    Bola2.bola.setRadius(30.f);
    Bola2.bola.setFillColor(sf::Color::Blue);
    Bola2.a = std::rand() % 630;
    Bola2.b = std::rand() % 470;
    Bola2.va = 10;
    Bola2.vb = 10;

    bolas.push_back(Bola2);

    Bola Bola3;
    Bola3.bola.setRadius(30.f);
    Bola3.bola.setFillColor(sf::Color::Magenta);
    Bola3.c = std::rand() % 630;
    Bola3.d = std::rand() % 470;
    Bola3.vc = 10;
    Bola3.vd = 10;

    bolas.push_back(Bola3);



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
        Bola1.x = Bola1.x + Bola1.vx;
        Bola1.y = Bola1.y + Bola1.vy;
        Bola2.a = Bola2.a + Bola2.va;
        Bola2.b = Bola2.b + Bola2.vb;
        Bola3.c = Bola3.c + Bola3.vc;
        Bola3.d = Bola3.d + Bola3.vd;

        if((Bola1.x >= window.getSize().x - Bola1.bola.getRadius()*2) || (Bola1.x <=0)){
        	Bola1.vx = -Bola1.vx;
        }
        if((Bola1.y >= window.getSize().y - Bola1.bola.getRadius()*2) || (Bola1.y <=0)){
        	Bola1.vy = -Bola1.vy;
        }

        Bola1.bola.setPosition(Bola1.x, Bola1.y);

        if((Bola2.a >= window.getSize().x - Bola2.bola.getRadius()*2) || (Bola2.a <=0)){
        	Bola2.va = -Bola2.va;
        }
        if((Bola2.b >= window.getSize().y - Bola2.bola.getRadius()*2) || (Bola2.b <=0)){
        	Bola2.vb = -Bola2.vb;
        }

        Bola2.bola.setPosition(Bola2.a, Bola2.b);

        if((Bola3.c >= window.getSize().x - Bola3.bola.getRadius()*2) || (Bola3.c <=0)){
        	Bola3.vc = -Bola3.vc;
        }
        if((Bola3.d >= window.getSize().y - Bola3.bola.getRadius()*2) || (Bola3.d <=0)){
        	Bola3.vd = -Bola3.vd;
        }

        Bola3.bola.setPosition(Bola3.c, Bola3.d);

        //Desenha a tela.
        window.clear();
        window.draw(Bola1.bola);
        window.draw(Bola2.bola);
        window.draw(Bola3.bola);
        window.display();


    } //Fim do loop do jogo.

    return 0;
}
