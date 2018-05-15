///   ПЕРЕДЕЛЫВАЮ, ТАК КАК НЕ РИСУЮТСЯ КУБИКИ

#include <SFML\Graphics.hpp>
#include <iostream>
#include <sstream>
#include "map.h" //ïîäêëþ÷èëè êîä ñ êàðòîé
;
using namespace std;
using namespace sf;//âêëþ÷àåì ïðîñòðàíñòâî èìåí sf, ÷òîáû ïîñòîÿííî íå ïèñàòü sf::
void menu(RenderWindow & window)
{
	Texture menuTexture1, menuTexture2, menuBackground;
	menuTexture1.loadFromFile("images/111.png");
	menuTexture2.loadFromFile("images/333.png");
	menuBackground.loadFromFile("images/cubes.jpg");
	Sprite menu1(menuTexture1), menu2(menuTexture2), menuBg(menuBackground);
	bool isMenu = 1;
	int menuNum = 0;
	menu1.setPosition(100, 30);
	menu2.setPosition(100, 150);
	menuBg.setPosition(345, 0);

	//////////////////////////////ÌÅÍÞ///////////////////
	while (isMenu)
	{
		menu1.setColor(Color::White);
		menu2.setColor(Color::White);
		menuNum = 0;
		window.clear(Color(129, 181, 221));

		if (IntRect(100, 30, 300, 50).contains(Mouse::getPosition(window))) { menu1.setColor(Color::Blue); menuNum = 1; }
		if (IntRect(100, 150, 300, 50).contains(Mouse::getPosition(window))) { menu2.setColor(Color::Blue); menuNum = 2; }

		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (menuNum == 1) isMenu = false;//åñëè íàæàëè ïåðâóþ êíîïêó, òî âûõîäèì èç ìåíþ 
			if (menuNum == 2) { window.close(); isMenu = false; }
		}
		window.draw(menuBg);
		window.draw(menu1);
		window.draw(menu2);

		window.display();
	}
	////////////////////////////////////////////////////
}
class Player
{
public:
	int playerScore;
	Player(string F)
	{
		playerScore = 0;
	}

};
void cube1(int a, int & score1, RenderWindow & window)
{
	float x = 100, y = 100;
	//соzдаю спрайты для первого кубика

	Image a1_image, a2_image, a3_image, a4_image, a5_image, a6_image;
	a1_image.loadFromFile("images/1.png");
	a2_image.loadFromFile("images/2.png");
	a3_image.loadFromFile("images/3.png");
	a4_image.loadFromFile("images/4.png");
	a5_image.loadFromFile("images/5.png");
	a6_image.loadFromFile("images/6.png");
	Texture a1_texture, a2_texture, a3_texture, a4_texture, a5_texture, a6_texture;
	a1_texture.loadFromImage(a1_image);
	a2_texture.loadFromImage(a2_image);
	a3_texture.loadFromImage(a3_image);
	a4_texture.loadFromImage(a4_image);
	a5_texture.loadFromImage(a5_image);
	a6_texture.loadFromImage(a6_image);
	Sprite a1_sprite, a2_sprite, a3_sprite, a4_sprite, a5_sprite, a6_sprite;
	a1_sprite.setTexture(a1_texture);
	a2_sprite.setTexture(a2_texture);
	a3_sprite.setTexture(a3_texture);
	a4_sprite.setTexture(a4_texture);
	a5_sprite.setTexture(a5_texture);
	a6_sprite.setTexture(a6_texture);
	a1_sprite.setPosition(x, y);
	a2_sprite.setPosition(x, y);
	a3_sprite.setPosition(x, y);
	a4_sprite.setPosition(x, y);
	a5_sprite.setPosition(x, y);
	a6_sprite.setPosition(x, y);

	//(time(0));
	// a = 1 + rand() % 6;
	score1 = 0;
	if (a == 1)
	{
		//for (x = 100; x < 270; x++)
		//{
			//for (y = 100; y < 270; y++)
			//{
			//	x += 40;
				//y += 40;
				//a1_sprite.setPosition(x, y);
				window.draw(a1_sprite);
			//}
		//}
		//a1_sprite.move(-0.1*time, 0);//происходит само движение персонажа влево
		//window.draw(a1_sprite);
		score1 += 1;
	}
	else
	{
		if (a == 2)
		{
			//for (x = 100; x < 270; x++)
			//{
				//for (y = 100; y < 270; y++)
				//{
				//	x += 40;
					//y += 40;
				///	//a2_sprite.setPosition(x, y);
					window.draw(a2_sprite);
				//}
			//}
			//a2_sprite.move(-0.1*time, 0);//происходит само движение персонажа влево
			//window.draw(a2_sprite);
			score1 += 2;
		}
		else
		{
			if (a == 3)
			{
				//for (x = 100; x < 270; x++)
				//{
				//	for (y = 100; y < 270; y++)
					//{
						//x += 40;
					//	y += 40;
						//a3_sprite.setPosition(x, y);
						window.draw(a3_sprite);
					//}
				//}
				//a3_sprite.move(-0.1*time, 0);//происходит само движение персонажа влево
				//window.draw(a3_sprite);
				score1 += 3;
			}
			else
			{
				if (a == 4)
				{
					//for (x = 100; x < 270; x++)
					//{
						//for (y = 100; y < 270; y++)
						//{
						//	x += 40;
						//	y += 40;
							//a4_sprite.setPosition(x, y);
							window.draw(a4_sprite);
						//}
					//}
					//a4_sprite.move(-0.1*time, 0);//происходит само движение персонажа влево
					//window.draw(a4_sprite);
					score1 += 4;
				}
				else
				{
					if (a == 5)
					{
						//for (x = 100; x < 270; x++)
						//{
						//	for (y = 100; y < 270; y++)
							//{
							//	x += 40;
							//	y += 40;
								//a5_sprite.setPosition(x, y);
								window.draw(a5_sprite);
							//}
						//}
						//a5_sprite.move(-0.1*time, 0);//происходит само движение персонажа влево
						//window.draw(a5_sprite);
						score1 += 5;
					}
					else
					{
						//for (x = 100; x < 270; x++)
						//{
							//for (y = 100; y < 270; y++)
							//{
							//	x += 40;
							//	y += 40;
							//	a6_sprite.setPosition(x, y);
								window.draw(a6_sprite);
							//}
						//}
						//a6_sprite.move(-0.1*time, 0);//происходит само движение персонажа влево
						//window.draw(a6_sprite);
						score1 += 6;
					}
				}
			}
		}
	}

}
void cube2(int b, int& score2, RenderWindow & window)
{
	Image b1_image, b2_image, b3_image, b4_image, b5_image, b6_image;
	b3_image.loadFromFile("images/3.png");
	b1_image.loadFromFile("images/1.png");
	b2_image.loadFromFile("images/2.png");
	b4_image.loadFromFile("images/4.png");
	b5_image.loadFromFile("images/5.png");
	b6_image.loadFromFile("images/6.png");
	Texture b1_texture, b2_texture, b3_texture, b4_texture, b5_texture, b6_texture;
	b1_texture.loadFromImage(b1_image);
	b2_texture.loadFromImage(b2_image);
	b3_texture.loadFromImage(b3_image);
	b4_texture.loadFromImage(b4_image);
	b5_texture.loadFromImage(b5_image);
	b6_texture.loadFromImage(b6_image);
	Sprite b1_sprite, b2_sprite, b3_sprite, b4_sprite, b5_sprite, b6_sprite;
	b1_sprite.setTexture(b1_texture);
	b2_sprite.setTexture(b2_texture);
	b3_sprite.setTexture(b3_texture);
	b4_sprite.setTexture(b4_texture);
	b5_sprite.setTexture(b5_texture);
	b6_sprite.setTexture(b6_texture);
	b1_sprite.setPosition(500, 250);
	b2_sprite.setPosition(500, 250);
	b3_sprite.setPosition(500, 250);
	b4_sprite.setPosition(500, 250);
	b5_sprite.setPosition(500, 250);
	b6_sprite.setPosition(500, 250);
	score2 = 0;
	if (b == 1)
	{
		window.draw(b1_sprite); score2 += 1;
	}
	else
	{
		if (b == 2)
		{
			window.draw(b2_sprite); score2 += 2;
		}
		else
		{
			if (b == 3)
			{
				window.draw(b3_sprite); score2 += 3;
			}
			else
			{
				if (b == 4)
				{
					window.draw(b4_sprite);  score2 += 4;
				}
				else
				{
					if (b == 5)
					{
						window.draw(b5_sprite);  score2 += 5;
					}
					else
					{
						window.draw(b6_sprite); score2 += 6;
					}
				}
			}
		}
	}

}

bool timer(int c)
{
	static sf::Clock clock;
	if (clock.getElapsedTime().asSeconds() > c)
	{
		return true;
		clock.restart();
	}
	return false;
}
void drawcubes(int &score1, int &score2, RenderWindow & window)
{
	int a = 1 + rand() % 6;
	int b = 1 + rand() % 6;
	cube1(a, score1, window);
	cube2(b, score2, window);
}

int main()
{
	RenderWindow window(VideoMode(960, 720), "Cube"); //ñîçäàëè îêíî
	window.setFramerateLimit(60); // êîëè÷åñòâî êàäðîâ â ñåêóíäó
	float CurrentFrame = 0;//õðàíèò òåêóùèé êàäð
	Clock clock;
	float x = -250, y = -250;
	menu(window);//âûçîâ ìåíþ

	Font font;
	font.loadFromFile("images/CyrilicOld.ttf");
	Text textscore1(" ", font, 40), textscore2(" ", font, 40), textknopka1("Бросок ", font, 40), textknopka2("Стоп ", font, 40), textwin(" ", font, 100);
	int score1(0), score2(0), summscore = 0;
	int etap(0); // ýòàï èãðû
textknopka1.setPosition(1020, 150);
	textknopka2.setPosition(1020, 250);
	textscore1.setPosition(600, 500);
	textscore2.setPosition(600, 560);			 // ñîçäàþ êàðòó
	Image map_image; //ñîçäàåì îáúåêò Image 
	map_image.loadFromFile("images/map.png");//çàãðóæàåì â íåãî ôàéë
	Texture texture;//ñîçäàåì îáúåêò Texture 
	texture.loadFromImage(map_image);//ïåðåäàåì â íåãî îáúåêò Image(èçîáðàæåíèÿ)
	Sprite sprite;//ñîçäàåì îáúåêò Sprite
	sprite.setTexture(texture);//ïåðåäà¸ì â íåãî îáúåêò Texture 

		int stavka = 0;
	int money1 = 100, money2 = 100;					   //ñîzäàþ ñïðàéòû äëÿ ïåðâîãî êóáèêà



	srand(time(0));
	int a = 1 + rand() % 6;
	int b = 1 + rand() % 6;

	while (window.isOpen())
	{
		// Îáðàáàòûâàåì ñîáûòèÿ â öèêëå.
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 400;
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
				if (TileMap[i][j] == ' ')  sprite.setTextureRect(IntRect(0, 0, 32, 32)); //åñëè âñòðåòèëè ñèìâîë ïðîáåë, òî ðèñóåì 1é êâàäðàòèê
				if ((TileMap[i][j] == '0')) sprite.setTextureRect(IntRect(64, 0, 32, 32));//åñëè âñòðåòèëè ñèìâîë 0, òî ðèñóåì 3é êâàäðàòèê
				sprite.setPosition(j * 32, i * 32); // ðàñêèäûâà êâàäðàòèêè, ïðåâðàùàÿ â êàðòó.
				window.draw(sprite);//âûâîäèì ñïðàéò íà ýêðàí
			}
		window.draw(text);
if (event.mouseButton.button == Mouse::Left && event.type == Event::MouseButtonPressed)
{ drawcubes(score1, score2, window); 
		window.display(); Sleep(1000);
		summscore1 = score1 + score2;
}
		if (event.mouseButton.button == Mouse::Right && event.type == Event::MouseButtonPressed)
		{
			drawcubes(score1, score2, window); 
			window.display(); Sleep(1000);
						summscore2 = score1 + score2;
		}
		if (summscore1 > summscore2)
				{
					if (stavka != 0) { money1 += stavka; money2 -= stavka; stavka = 0; }
					textwin.setString(" Выиграл игрок 1!");
				}
				if (summscore1 < summscore2)
				{
					if (stavka != 0) { money1 -= stavka; money2 += stavka; stavka = 0; }
					textwin.setString(" Выиграл игрок 2!");
				}
				if (summscore1 == summscore2)
				{
					textwin.setString("Ничья!");
					stavka = 0;
				}


score1string << summscore1; score2string << summscore2;
			//çàíåñëè â íåå ÷èñëî çäîðîâüÿ, òî åñòü ôîðìèðóåì ñòðîêó
		textscore1.setString("Cчёт первого: " + score1string.str());
			textscore2.setString("Счёт второго:  " + score2string.str());
		window.draw(text);//ðèñóþ ýòîò òåêñò
		window.display();
	}

	return 0;
}













