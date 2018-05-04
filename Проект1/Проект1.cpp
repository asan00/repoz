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
	Text textscore1(" ", font, 40), textscore2(" ", font, 40), textknopka1(" ", font, 40), textknopka2(" ", font, 40), textwin(" ", font, 100);
	textscore1.setStyle(Text::Bold);
	textscore2.setStyle(Text::Bold);
	textknopka1.setStyle(Text::Bold);
	textknopka2.setStyle(Text::Bold);
	textwin.setStyle(Text::Bold);

	int score1(0), score2(0), summscore = 0;
	int etap(0); // ýòàï èãðû

				 // ñîçäàþ êàðòó
	Image map_image; //ñîçäàåì îáúåêò Image 
	map_image.loadFromFile("images/map.png");//çàãðóæàåì â íåãî ôàéë
	Texture texture;//ñîçäàåì îáúåêò Texture 
	texture.loadFromImage(map_image);//ïåðåäàåì â íåãî îáúåêò Image(èçîáðàæåíèÿ)
	Sprite sprite;//ñîçäàåì îáúåêò Sprite
	sprite.setTexture(texture);//ïåðåäà¸ì â íåãî îáúåêò Texture 

							   //ñîzäàþ ñïðàéòû äëÿ ïåðâîãî êóáèêà

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

	//ñîzäàþ ñïðàéòû äëÿ âòîðîãî êóáèêà

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

		if (a == 1)
		{
			if (Keyboard::isKeyPressed(Keyboard::Space)) { //åñëè íàæàòà êëàâèøà ñòðåëêà âëåâî èëè àíãë áóêâà À
				for (x = -250; x < 270; x++)
				{
					for (y = -250; y < 270; y++)
					{
						x += 40;
						y += 40;
						a1_sprite.setPosition(x, y);
						window.draw(a1_sprite);
					}
				}
				//a1_sprite.move(-0.1*time, 0);//ïðîèñõîäèò ñàìî äâèæåíèå ïåðñîíàæà âëåâî
			}
			window.draw(a1_sprite);
			score1 += 1;

		}
		else
		{
			if (a == 2)
			{
				if (Keyboard::isKeyPressed(Keyboard::Space)) { //åñëè íàæàòà êëàâèøà ñòðåëêà âëåâî èëè àíãë áóêâà À
					for (x = -250; x < 270; x++)
					{
						for (y = -250; y < 270; y++)
						{
							x += 40;
							y += 40;
							a2_sprite.setPosition(x, y);
							window.draw(a2_sprite);
						}
					}
					//a2_sprite.move(-0.1*time, 0);//ïðîèñõîäèò ñàìî äâèæåíèå ïåðñîíàæà âëåâî
				}

				window.draw(a2_sprite);
				score1 += 2;
			}
			else
			{
				if (a == 3)
				{
					if (Keyboard::isKeyPressed(Keyboard::Space)) { //åñëè íàæàòà êëàâèøà ñòðåëêà âëåâî èëè àíãë áóêâà À
						for (x = -250; x < 270; x++)
						{
							for (y = -250; y < 270; y++)
							{
								x += 40;
								y += 40;
								a3_sprite.setPosition(x, y);
								window.draw(a3_sprite);
							}
						}
						//a3_sprite.move(-0.1*time, 0);//ïðîèñõîäèò ñàìî äâèæåíèå ïåðñîíàæà âëåâî
					}

					window.draw(a3_sprite);
					score1 += 3;
				}
				else
				{
					if (a == 4)
					{
						if (Keyboard::isKeyPressed(Keyboard::Space)) { //åñëè íàæàòà êëàâèøà ñòðåëêà âëåâî èëè àíãë áóêâà À
							for (x = -250; x < 270; x++)
							{
								for (y = -250; y < 270; y++)
								{
									x += 40;
									y += 40;
									a4_sprite.setPosition(x, y);
									window.draw(a4_sprite);
								}
							}
							//a4_sprite.move(-0.1*time, 0);//ïðîèñõîäèò ñàìî äâèæåíèå ïåðñîíàæà âëåâî
						}

						window.draw(a4_sprite);
						score1 += 4;
					}
					else
					{
						if (a == 5)
						{
							if (Keyboard::isKeyPressed(Keyboard::Space)) { //åñëè íàæàòà êëàâèøà ñòðåëêà âëåâî èëè àíãë áóêâà À
								for (x = -250; x < 270; x++)
								{
									for (y = -250; y < 270; y++)
									{
										x += 40;
										y += 40;
										a5_sprite.setPosition(x, y);
										window.draw(a5_sprite);
									}
								}
								//a5_sprite.move(-0.1*time, 0);//ïðîèñõîäèò ñàìî äâèæåíèå ïåðñîíàæà âëåâî
							}

							window.draw(a5_sprite);
							score1 += 5;
						}
						else
						{
							if (Keyboard::isKeyPressed(Keyboard::Space)) { //åñëè íàæàòà êëàâèøà ñòðåëêà âëåâî èëè àíãë áóêâà À
								for (x = -250; x < 270; x++)
								{
									for (y = -250; y < 270; y++)
									{
										x += 40;
										y += 40;
										a6_sprite.setPosition(x, y);
										window.draw(a6_sprite);
									}
								}
								//a6_sprite.move(-0.1*time, 0);//ïðîèñõîäèò ñàìî äâèæåíèå ïåðñîíàæà âëåâî
							}

							window.draw(a6_sprite);
							score1 += 6;
						}
					}
				}
			}
		}

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
		summscore = score1 + score2;


		std::ostringstream playerScoreString;    // îáúÿâèëè ïåðåìåííóþ
		playerScoreString << summscore;		//çàíåñëè â íåå ÷èñëî çäîðîâüÿ, òî åñòü ôîðìèðóåì ñòðîêó
		text.setString("Score:" + playerScoreString.str());//çàäàåì ñòðîêó òåêñòó è âûçûâàåì ñôîðìèðîâàííóþ âûøå ñòðîêó ìåòîäîì .str() 
		text.setPosition(165, 200);//çàäàåì ïîçèöèþ òåêñòà, îòñòóïàÿ îò öåíòðà êàìåðû
		window.draw(text);//ðèñóþ ýòîò òåêñò
		window.display();
	}

	return 0;
}













