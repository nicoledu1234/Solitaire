#ifndef CARD_H
#define CARD_H
#include <iostream>


class Card{
    public:
        friend bool operator<(Card& obj1, Card& obj2);
        friend bool operator>(Card& obj1, Card& obj2);

        Card();

        std::string getSuit();
        std::string getFace();
        std::string getColour();
        bool getOnboard();
        bool getRevealed();
        int getNumber();

        void setSuit(const std::string);
        void setFace(const std::string);
        void setOnboard(const bool);
        void setRevealed(const bool);
        void setNumber(const int);
        void setColour(const std::string);

        std::string printCard();

    private:
        std::string suit;
        std::string face;
        std::string colour;
        bool revealed, onboard;
        int number;
};

#endif // CARD_H
