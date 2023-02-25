#include <bits/stdc++.h>
#include<SFML/Graphics.hpp>
#include "MainMenu.h"
#include<fstream>
using namespace std;
using namespace sf;
int wWidth = 800 , wHeight = 600;
vector<pair<double,double> > bullarray;
int main()
{
    float x = 0;
    float y = 0;
    RenderWindow MENU(VideoMode(wWidth,wHeight), "Space");
    MainMenu mainMenu(MENU.getSize().x, MENU.getSize().y);
    RectangleShape background;
    background.setSize(Vector2f(wWidth,wHeight));
    Texture Maintexture;
    Maintexture.loadFromFile("data/images/menuBack.jpg");
    //Sprite bg(Maintexture);
    background.setTexture(&Maintexture);


    while(MENU.isOpen()){
        Event event;

        while(MENU.pollEvent(event)){
            if(event.type == Event::Closed){
                MENU.close();
            } //modification
            if(event.type == Event :: KeyReleased)
            {
                if(event.key.code == Keyboard :: Up)
                {
                    mainMenu.MoveUp();
                    break;
                }
                if(event.key.code == Keyboard :: Down)
                {
                    mainMenu.MoveDown();
                    break;
                }
                if(event.key.code == Keyboard :: Return)
                {
                   RenderWindow Play(VideoMode(800,600), "SPACE__IMAPACT");
                   RenderWindow OPTIONS(VideoMode(800,600), "Options");
                   RenderWindow ABOUT(VideoMode(800,600), "About");
                   int x = mainMenu.MainMenuPressed();
                   if(x == 0)
                   {
                       while(Play.isOpen())
                       {
                           Event avent;
                           while(Play.pollEvent(avent))
                           {
                               if(avent.type == Event::Closed)
                               {
                                   Play.close();
                               }


                               if(avent.type == Event::KeyPressed)
                               {
                                   if(avent.key.code == Keyboard::Escape)
                                   {
                                       Play.close();
                                   }
                               }
                           }




                           OPTIONS.close();
                           ABOUT.close();
                           Play.clear();



                           // Play.draw(firebul);

                           Play.display();


                       }
                   } //
                       if(x == 1)
                   {
                       while(OPTIONS.isOpen())
                       {
                           Event avent;
                           while(OPTIONS.pollEvent(avent))
                           {
                               if(avent.type == Event::Closed)
                               {
                                   OPTIONS.close();
                               }
                               if(avent.type == Event::KeyPressed)
                               {
                                   if(avent.key.code == Keyboard::Escape)
                                   {
                                       OPTIONS.close();
                                   }
                               }
                           }
                           Play.close();
                           OPTIONS.clear();
                           ABOUT.close();

                          OPTIONS.display();


                       }
                   }
                       if(x == 2)
                   {
                       while(ABOUT.isOpen())
                       {
                           Event avent;
                           while(ABOUT.pollEvent(avent))
                           {
                               if(avent.type == Event::Closed)
                               {
                                   ABOUT.close();
                               }
                               if(avent.type == Event::KeyPressed)
                               {
                                   if(avent.key.code == Keyboard::Escape)
                                   {
                                       ABOUT.close();
                                   }
                               }
                           }
                            Play.close();
                           OPTIONS.clear();
                           ABOUT.clear();

                           ABOUT.display();


                       }
                   }
                       if(x == 3)

                      MENU.close();
                      break;
                   //


                }
            }
        }

        MENU.clear();
        MENU.draw(background);
        mainMenu.draw(MENU);
        MENU.display();

       //modification

}
}
