#include <SFML\Graphics.hpp>
#include <iostream>
#include "map.h" //подключили код с картой

using namespace std;
using namespace sf;//включаем пространство имен sf, чтобы постоянно не писать sf::
int main()
{
	RenderWindow window(VideoMode(960, 720), "Cube"); //создали окно
	window.setFramerateLimit(60); // количество кадров в секунду
	CircleShape square(70,4); // создали квадрат
	square.setFillColor(Color::White); // задали цвет`
	
	square.setPosition(300, 300);
	square.rotate(45);
	// создаю карту
	Image map_image; //создаем объект Image 
	map_image.loadFromFile("images/map.png");//загружаем в него файл

	Texture texture;//создаем объект Texture 
	texture.loadFromImage(map_image);//передаем в него объект Image(изображения)

	Sprite sprite;//создаем объект Sprite
	sprite.setTexture(texture);//передаём в него объект Texture 
	
// coздаю кубик
	Image cube_image; 
	cube_image.loadFromFile("images/cube.png");

	Texture cube_texture;
	cube_texture.loadFromImage(cube_image);

	Sprite cube_sprite;
	cube_sprite.setTexture(cube_texture);
    cube_sprite.setPosition(100, 50);//задаем начальные координаты появления спрайта
						
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();
		
		for (int i = 0; i < HEIGHT_MAP; i++)
			for (int j = 0; j < WIDTH_MAP; j++)
			{
				if (TileMap[i][j] == ' ')  sprite.setTextureRect(IntRect(0, 0, 32, 32)); //если встретили символ пробел, то рисуем 1й квадратик
				if ((TileMap[i][j] == '0')) sprite.setTextureRect(IntRect(64, 0, 32, 32));//если встретили символ 0, то рисуем 3й квадратик
				sprite.setPosition(j * 32, i * 32); // раскидыва квадратики, превращая в карту.
				window.draw(sprite);//выводим спрайт на экран
			}
		//window.draw(square);
		window.draw(cube_sprite);
		window.display();
	}

	return 0;
}