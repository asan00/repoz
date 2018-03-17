#include <SFML\Graphics.hpp>
#include <iostream>
#include "map.h" //���������� ��� � ������

using namespace std;
using namespace sf;//�������� ������������ ���� sf, ����� ��������� �� ������ sf::
int main()
{
	RenderWindow window(VideoMode(960, 720), "Cube"); //������� ����
	window.setFramerateLimit(60); // ���������� ������ � �������
	CircleShape square(70,4); // ������� �������
	square.setFillColor(Color::White); // ������ ����`
	
	square.setPosition(300, 300);
	square.rotate(45);
	// ������ �����
	Image map_image; //������� ������ Image 
	map_image.loadFromFile("images/map.png");//��������� � ���� ����

	Texture texture;//������� ������ Texture 
	texture.loadFromImage(map_image);//�������� � ���� ������ Image(�����������)

	Sprite sprite;//������� ������ Sprite
	sprite.setTexture(texture);//������� � ���� ������ Texture 
	
// co���� �����
	Image cube_image; 
	cube_image.loadFromFile("images/cube.png");

	Texture cube_texture;
	cube_texture.loadFromImage(cube_image);

	Sprite cube_sprite;
	cube_sprite.setTexture(cube_texture);
    cube_sprite.setPosition(100, 50);//������ ��������� ���������� ��������� �������
						
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
				if (TileMap[i][j] == ' ')  sprite.setTextureRect(IntRect(0, 0, 32, 32)); //���� ��������� ������ ������, �� ������ 1� ���������
				if ((TileMap[i][j] == '0')) sprite.setTextureRect(IntRect(64, 0, 32, 32));//���� ��������� ������ 0, �� ������ 3� ���������
				sprite.setPosition(j * 32, i * 32); // ��������� ����������, ��������� � �����.
				window.draw(sprite);//������� ������ �� �����
			}
		//window.draw(square);
		window.draw(cube_sprite);
		window.display();
	}

	return 0;
}