#include <iostream>
#include <iomanip>

#include <string.h>
#include <ctime>
#include <vector>

#include "Card.h"
#include "Deck.h"
#include "Pile.h"
#include "Game.h"

#define FOUNDATIONS 7
//#include <SFML/Graphics.hpp>
//#include <SFML/Window.hpp>

//using namespace sf;
using namespace std;


//string filename(string, int);
/*
string filename(string s, int n){
    string a = "images/cards/" + s + "/" + to_string(n) + ".png";
    return a;
}
*/
Game game;
Deck deck;

Pile foundations[4];
Pile tableaus[7];

void moveCards(Pile&, Pile&, int);

int main(){

    deck.shuffleDeck();

    for (int i = 0; i < FOUNDATIONS; i++){
        for (int j = 0; j < i+1; j++){
            tableaus[i].addCard(&(deck.dealCard()));
        }
    }

    for (Pile tableau : tableaus){
        tableau.revealLast();
    }

    while (true){/*
        for (int i = 0; i < 13; i++){
            for (int j = 0; j < FOUNDATIONS; j++){
                if (tableaus[j].getSize() == 0){
                    cout << setw(19) << " ";
                }
                else if (tableaus[j].getSize() <= i){
                    cout << setw(19) << " ";
                }
                else{
                    cout << setw(19) << tableaus[j].getCard(i).printCard();
                }
            }
            cout << endl;
        }*/

        game.drawBoard(tableaus);

        int choosePile, toPile, quant;
        cin >> choosePile >> toPile >> quant;

        moveCards(tableaus[choosePile-1], tableaus[toPile-1], quant);
    }

/*    while(!gameFinished){
        printBoard(playingBoard);
        cin >> i >> j;
        cin >> ni >> nj;
        moveCard(playingBoard, i, j, ni, nj);
        revealCard(playingBoard[i-1][j-2]);
    }

    RenderWindow window(VideoMode(678, 848), "Solitaire!");

    Texture t1;
    //t1.loadFromFile("images/cards/hearts/2.png");
    t1.loadFromFile("images/cards/hearts/2.png");
    Sprite s(t1);

    Texture t2;
    t2.loadFromFile("images/bg.png");
    Sprite board(t2);

    bool isMove = false;
    float dx = 0, dy = 0;

    while ((!gameFinished) && (window.isOpen())){
        Vector2i pos = Mouse::getPosition(window);

        Event e;
        while (window.pollEvent(e)){
            if (e.type == Event::Closed)
                window.close();

            ///////drag and drop///////
            if (e.type == Event::MouseButtonPressed)
                if (e.key.code == Mouse::Left)
                    if (s.getGlobalBounds().contains(pos.x, pos.y)){
                        isMove = true;
                        dx = pos.x - s.getPosition().x;
                        dy = pos.y - s.getPosition().y;
                    }

            if (e.type == Event::MouseButtonReleased)
                if (e.key.code == Mouse::Left)
                    isMove = false;
        }

        if (isMove) s.setPosition(pos.x-dx, pos.y-dy);

        window.clear();
        window.draw(board);
        window.draw(s);
        window.display();
    }
*/
    return 0;
}

void moveCards(Pile &dealer, Pile &receiver, int cards){
    int j = cards;
    for (int i = 0; i < cards; i++){
        receiver.addCard(&(dealer.getCard(dealer.getSize()-cards)));
        //if (dealer.getSize() > 0)
        dealer.removeCard(cards);
    }
    dealer.revealLast();
}
