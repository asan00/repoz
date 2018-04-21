#include <SFML\Graphics.hpp>
#include <iostream>
#include "map.h" //подключили код с картой
#include <Windows.h>
#include <sstream>
#include <string>
;
using namespace std;
using namespace sf;//включаем пространство имен sf, чтобы постоянно не писать sf::
void menu(RenderWindow & window, int &etap, Event event,  Sprite about, Font font, int menunumber)
{
	Text menu1("Начать", font, 40), menu2("Об игре", font, 40), menu3("Выход", font, 40), menu4("Назад", font, 30), kosti("Кости", font, 100);
	// Задаём позиции для кнопок меню
	menu1.setPosition(976, 200);
	menu2.setPosition(976, 320);
	menu3.setPosition(976, 440);
	menu4.setPosition(850, 0);
	kosti.setPosition(250, 100);
	// Контур и цвет
	kosti.setOutlineThickness(2);
	kosti.setOutlineColor(Color::Black);
	menu1.setFillColor(Color::Yellow);	// После отведения курсора меняем на изначальный цвет
	menu2.setFillColor(Color::Yellow);
	menu3.setFillColor(Color::Yellow);
	menu4.setFillColor(Color::Yellow);
	menunumber = 0;
	if (IntRect(menu1.getGlobalBounds()).contains(Mouse::getPosition(window))) { menu1.setFillColor(Color::Blue); menunumber = 1; }
	if (IntRect(menu2.getGlobalBounds()).contains(Mouse::getPosition(window))) { menu2.setFillColor(Color::Blue); menunumber = 2; }
	if (IntRect(menu3.getGlobalBounds()).contains(Mouse::getPosition(window))) { menu3.setFillColor(Color::Blue); menunumber = 3; }
	if (etap == -2) { if (IntRect(menu4.getGlobalBounds()).contains(Mouse::getPosition(window))) { menu4.setFillColor(Color::Blue); menunumber = 4; } } // Выделение кнопки "Назад" для пункта с правилами
	if (Mouse::isButtonPressed(Mouse::Left))
	{
		if (menunumber == 1) { etap = 0; }// Если нажали кнопку "Начать", то выходим из меню и попадаем в игру
		if (menunumber == 2) { etap = -2; } // Если нажали кнопку "Об игре", то открываются правила
		if (menunumber == 3) { window.close(); }// Если нажали кнопку "Выход", то выходим из приложения
		if (menunumber == 4) { etap = -1; }// Если нажали кнопку "Назад", то выходим из пунка "Об игре"
	}
	if (event.type == Event::Closed) // Закрытие меню по крестику
		window.close();
	
	// Этап = -1? Рисуем компоненты меню
	if (etap == -1)
	{
		window.draw(menu1);
		window.draw(menu2);
		window.draw(menu3);
		window.draw(kosti);
	}
	// Этап = -2? Рисуем правила и кнопку "Назад"
	if (etap == -2)
	{
		window.draw(about);
		window.draw(menu4);
	}
	window.display();
}
void cube1(int a, int score1, RenderWindow & window)
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
	srand(time(0));
 // a = 1 + rand() % 6;
  score1 = 0;
	if (a == 1)
	{
			//for (x = -250; x < 270; x++)
			//{
				//for (y = -250; y < 270; y++)
				//{
					//x += 80;
					//y += 80;
					//a1_sprite.setPosition(x, y);
					window.draw(a1_sprite);
				//}
		//	}
			//a1_sprite.move(-0.1*time, 0);//происходит само движение персонажа влево
		//window.draw(a1_sprite);
		score1 += 1;
	}
	else
	{
		if (a == 2)
		{
				//for (x = -250; x < 270; x++)
				//{
					//for (y = -250; y < 270; y++)
					//{
					//	x += 80;
						//y += 80;
						//a2_sprite.setPosition(x, y);
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
					///for (x = -250; x < 270; x++)
					//{
					//	for (y = -250; y < 270; y++)
						//{
						//	x += 80;
						//	y += 80;
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
						//for (x = -250; x < 270; x++)
						//{
						//	for (y = -250; y < 270; y++)
							//{
							//	x += 80;
							//	y += 80;
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
							//for (x = -250; x < 270; x++)
							//{
							//	for (y = -250; y < 270; y++)
								//{
								//	x += 80;
								//	y += 80;
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
							//for (x = -250; x < 270; x++)
							//{
							//	for (y = -250; y < 270; y++)
							//	{
							//		x += 80;
								//	y += 80;
									//a6_sprite.setPosition(x, y);
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
void cube2(int b, int score2, RenderWindow & window)
{
	float x = 100, y = 100;
	//соzдаю спрайты для второго кубика

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
    // b = 1 + rand() % 6;
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


int main()
{
	//Окно
	RenderWindow window(VideoMode(1280, 720), "Cube"); //создали окно
	window.setFramerateLimit(60); // количество кадров в секунду
	//float CurrentFrame = 0;//хранит текущий кадр
	//Clock clock;
	float x = 100, y = 100;
	// Текст
	Font font;
	font.loadFromFile("images/CyrilicOld.ttf");
	Text textsummscore1(" ", font, 40), textsummscore2(" ", font, 40), textknopka1("Бросить", font, 40), textknopka2("Стоп", font, 40);
	Text textwin(" ", font, 100), textEnd("", font, 65), textRestart("Рестарт", font, 40), textExit("Выйти", font, 40);
	Text textOk("Ок", font, 40), textst("+", font, 40), textnest("-", font, 40), textstavka("", font, 40), textMoney1("", font, 40), textMoney2("", font, 40);
	/*textsummscore1.setStyle(Text::Bold);
	textsummscore2.setStyle(Text::Bold);
	textknopka1.setStyle(Text::Bold);
	textknopka2.setStyle(Text::Bold);
	textwin.setStyle(Text::Bold);*/

	// Картинки
	Texture  abouttexture; // Объявление фона
	//backtexture.loadFromFile("images/cubes.png");		// Загрузка задника
	abouttexture.loadFromFile("images/about.png");
	Sprite  about;
	//backGround.setTexture(backtexture);
	about.setTexture(abouttexture);

	// Задаю позицию для всех кнопок и надписей
	// Для кнопок "Бросать" и "Стоп"
	textknopka1.setPosition(976, 150);
	textknopka2.setPosition(976, 250);
	// Для кнопок счёта очков
	textsummscore1.setPosition(976, 30);
	textsummscore2.setPosition(976, 90);
	// Для завершающих строк
	textwin.setPosition(200, 250);
	textEnd.setPosition(200, 250);
	// Для кнопок "Рестарт" и "Выход"
	textRestart.setPosition(976, 300);
	textExit.setPosition(976, 400);
	// Для денег
	textMoney1.setPosition(976, 500);
	textMoney2.setPosition(976, 560);
	// Для ставок
	textstavka.setPosition(976, 150);
	textst.setPosition(1058, 181);
	textnest.setPosition(981, 180);
	textOk.setPosition(1100, 185);

	int score1 = 0, score2 = 0, summscore1 = 0, summscore2 = 0;
	int etap(-1); // этап игры
	int menunumber=0;
	int stavka=0;
	int money1 = 100, money2 = 100;

	// создаю карту
	Image map_image; //создаем объект Image 
	map_image.loadFromFile("images/map.png");//загружаем в него файл
	Texture texture;//создаем объект Texture 
	texture.loadFromImage(map_image);//передаем в него объект Image(изображения)
	Sprite sprite;//создаем объект Sprite
	sprite.setTexture(texture);//передаём в него объект Texture 

	
	srand(time(0));
	//int a = 1 + rand() % 6;
	//int b = 1 + rand() % 6;

	while (window.isOpen())
	{
		// Обрабатываем события в цикле.
		//float time = clock.getElapsedTime().asMicroseconds();
		//clock.restart();
	//	time = time / 400;
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed) // Закрытие по крестику.
				window.close();
			window.clear();
		}

			for (int i = 0; i < HEIGHT_MAP; i++)
				for (int j = 0; j < WIDTH_MAP; j++)
				{
					if (TileMap[i][j] == ' ')  sprite.setTextureRect(IntRect(0, 0, 32, 32)); //если встретили символ пробел, то рисуем 1й квадратик
					if ((TileMap[i][j] == '0')) sprite.setTextureRect(IntRect(64, 0, 32, 32));//если встретили символ 0, то рисуем 3й квадратик
					sprite.setPosition(j * 32, i * 32); // раскидыва квадратики, превращая в карту.
					window.draw(sprite);//выводим спрайт на экран
				}
			// Если этап "Меню", то вызываем меню
			if (etap == -1 || etap == -2)
			{
				menu(window, etap, event, about, font, menunumber);
			}

			// Если этап "Игра"
			if (etap != -1 && etap != -2)
			{
				menunumber = 0; // Обнуляем переменную для кнопок
				if (etap == 0)
				{
					window.draw(textOk);
					//cube1(a, score1, window);
					//cube2(b, score2, window);
					//summscore1 = summscore2;
					etap = 1;
				}
				// Возвращаем цвет кнопкам
				textknopka1.setFillColor(Color::Yellow);
				textknopka2.setFillColor(Color::Yellow);
				textRestart.setFillColor(Color::Yellow);
				textExit.setFillColor(Color::Yellow);
				textst.setFillColor(Color::Yellow);
				textnest.setFillColor(Color::Yellow);
				textOk.setFillColor(Color::Yellow);

				if (etap == 1) // Для ставки на данный тур ( этап = 1)
				{
					if (IntRect(textst.getGlobalBounds()).contains(Mouse::getPosition(window))) { textst.setFillColor(Color::Blue); menunumber = 1; }
					if (IntRect(textnest.getGlobalBounds()).contains(Mouse::getPosition(window))) { textnest.setFillColor(Color::Blue); menunumber = 2; }
					if (IntRect(textOk.getGlobalBounds()).contains(Mouse::getPosition(window))) { textOk.setFillColor(Color::Blue); menunumber = 3; }
					if (event.mouseButton.button == Mouse::Left && event.type == Event::MouseButtonPressed)
					{
						if (menunumber == 1)
						{
							if (stavka != 20 && money1 > stavka && money2 > stavka) // Ставка не больше 20 и ставка не больше баланса игроков
								stavka += 1;
						}
						if (menunumber == 2)
						{
							if (stavka != 0 && money1 != 0) // Ставка не меньше 0 и баланс не 0
								stavka -= 1;
						}
						if (menunumber == 3 && stavka != 0) // Подтверждение ставки
							etap = 2;
					}
				}

				// Если курсор попал в область кнопки, то делаю её синей
				if (etap == 2 || etap == 3) // Игрок бросает кубики( этап = 2 )
				{
					if (IntRect(textknopka1.getGlobalBounds()).contains(Mouse::getPosition(window))) { textknopka1.setFillColor(Color::Blue); menunumber = 4; } // Для кнопок
					if (IntRect(textknopka2.getGlobalBounds()).contains(Mouse::getPosition(window))) { textknopka2.setFillColor(Color::Blue); menunumber = 5; } // "Взять" и "Стоп"
				}
				if (etap == 4 || etap == 5) // Когда закончились деньги или тур ( этап = 4 или этап = 5 )
				{
					if (IntRect(textRestart.getGlobalBounds()).contains(Mouse::getPosition(window))) { textRestart.setFillColor(Color::Blue); menunumber = 6; } // Для кнопок
					if (IntRect(textExit.getGlobalBounds()).contains(Mouse::getPosition(window))) { textExit.setFillColor(Color::Blue); menunumber = 7; } // "Рестарt" и "Выход"
				}

				if (event.mouseButton.button == Mouse::Left && event.type == Event::MouseButtonPressed)
				{
					if (etap == 2)
					{
						switch (menunumber)
						{
						case 4:
						{    // Если кнопка "Кидать", то кидаем
							int a = 1 + rand() % 6;
							int b = 1 + rand() % 6;
							cube1(a, score1, window);
							cube2(b, score2, window);
							summscore1 = score1 + score2;
						}

						case 5: // Если кнопка "Стоп", то переходим к 3 этапу
							etap = 3;
						
						}
					}
				}
				//Этап игры = 3? Игрок 2 кидает кубики. После этого наступает 4 этап
				if (event.mouseButton.button == Mouse::Left && event.type == Event::MouseButtonPressed)
				{
					if (etap == 3)
					{
						switch (menunumber)
						{
						case 4:
						{// Если кнопка "Кидать", то кидаем
							int a = 1 + rand() % 6;
							int b = 1 + rand() % 6;
							cube1(a, score1, window);
							cube2(b, score2, window);
							summscore2 = score1 + score2;
						}
						case 5: // Если кнопка "Стоп", то переходим к 4 этапу
							etap = 4; //break;
						}
					}
				}

				
				// 4 этап - это вывод победителя этой игры

				if (etap == 4)
				{
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
					if (!money1 || !money2) // Если денег не осталось, то переходим к 5 этапу
					{
						etap = 5; // 5 этап - это вывод игрока у которого закончились деньги
						if (!money1)
							textEnd.setString("          У игрока1\n закончились деньги!");
						if (!money2)
							textEnd.setString("          У игрока2\n закончились деньги!");
					}
					// После вывода победителя игры можно нажать "РЕСТАРТ" или "ВЫЙТИ". Нажимаем "РЕСТАРТ" и всё обнуляется. Остаются только деньги.
					if (etap == 4)
					{
						if (event.mouseButton.button == Mouse::Left && event.type == Event::MouseButtonPressed && menunumber == 7)
						{
							stavka = 0;
							etap = -1;
							summscore1 = summscore2 = 0;
							money1 = money2 = 100;
						}
						if (event.mouseButton.button == Mouse::Left && event.type == Event::MouseButtonPressed && menunumber == 6)
						{
							stavka = 0;
							etap = 0;
							summscore1 = summscore2 = 0;
						}
					}
				}
				
				/*if (event.type == Event::Closed) // Закрытие по крестику.
					window.close();*/
	
				// У кого-то не осталось денег? Выходим из игры или перезапускаем игру, обнуляя все очки и начисляя деньги.
				if (etap == 5)
				{
					if (event.mouseButton.button == Mouse::Left && event.type == Event::MouseButtonPressed && menunumber == 7)
					{
						etap = -1;
						summscore1 = summscore2 = 0;
						money1 = money2 = 100;
					}
					if (event.mouseButton.button == Mouse::Left && event.type == Event::MouseButtonPressed && menunumber == 6)
					{
						etap = 0;
						summscore1 = summscore2 = 0;
						money1 = money2 = 100;
					}
				}



				// Работа с текстом
				std::ostringstream summscore1String, summscore2String, Money1string, Money2string, stavkastring;
				summscore1String << summscore1; summscore2String << summscore2;
				Money1string << money1; Money2string << money2;
				stavkastring << stavka;
				textsummscore1.setString("Cчёт первого: " + summscore1String.str());
				textsummscore2.setString("Счёт второго:  " + summscore2String.str());
				textMoney1.setString("Деньги 1: " + Money1string.str());
				textMoney2.setString("Деньги 2: \n" + Money1string.str());
				textstavka.setString("Ставка:\n    " + stavkastring.str());

				// Очистка экрана
				//window.clear();
				// Рисуем для ставок
				if (etap == 1)
				{
					window.draw(textst);
					window.draw(textnest);
					window.draw(textstavka);
					window.draw(textOk);
				}
				// Отрисовка кнопок при 2 этапе
				if (etap == 2)
				{
					window.draw(textknopka1);
					window.draw(textknopka2);
				}
				// Этап 5? Рисуем победителя 
				if (etap == 4 || etap == 5)
				{
					if (etap == 4)
					{
						window.draw(textwin);
					}
					if (etap == 5)
						window.draw(textEnd);

					window.draw(textRestart);
					window.draw(textExit);
				}
				window.draw(textMoney1);
				window.draw(textMoney2);
				window.display();
			//}
		}
	}
		
			
	return 0;
}







		