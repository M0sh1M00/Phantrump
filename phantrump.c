// MADE BY OSCAR HOUSTON 7/9/2021

// shoutout to SFML for being a real one

#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <assert.h> 
#include <string>
#include <ws2tcpip.h>
#include <fcntl.h>


#pragma comment (lib, "ws2_32.lib")

using namespace std;

#define TERRA 1
#define AMPHIBIOUS 2
#define AERIAL 3
#define INCOGNITO 4

#define TOTALCARDS 30
#define CARDBANKSIZE 25

#define STARTINGCARDS 8

#define TRUE 1
#define FALSE 0

#define SCREENWIDTH 1400
#define SCREENHEIGHT 800

#define A2WIDTH 220//238 //140*1.7//84//140   25.25% is PS
#define A2HEIGHT 308//336 //198*1.7//109//198   25.25%

#define A2WIDTHHIGHLIGHTED 241    // 27.75% IN PS
#define A2HEIGHTHIGHLIGHTED 338   // 27.75%

#define BYTESOFGAMEDATA 6

//gamestates
#define CARD_PLACING 1
#define PLAYER_1_ATK 2
#define PLAYER_2_ATK 3

#define NORMAL_DISPLAY 1
#define ENLARGED_DISPLAY 2
#define ON_BOARD_DISPLAY 3
#define ENLARGED_DISPLAY_TEMP 4

#define DISCARD_DISPLAY_SCREEN 1
#define NORMAL_DISPLAY_SCREEN 2
#define INFORMATION_DISPLAY_SCREEN 3

struct Texture_Struct {
    sf::Texture Board_Cards;
    sf::Texture Elements;
    sf::Texture Background;

    sf::Texture S_Card_Backside;

    sf::Texture S_Vriska_1;
    sf::Texture S_Phantom_2;
    sf::Texture S_Kanelf_3;
    sf::Texture S_Gaxx_4;
    sf::Texture S_Shellbow_5;
    sf::Texture S_Marshan_6;
    sf::Texture S_Traria_7;
    sf::Texture S_Raorm_8;
    sf::Texture S_Krei_9;
    sf::Texture S_Sponk_10;
    sf::Texture S_Spurtle_11;
    sf::Texture S_Mosbie_12;
    sf::Texture S_Qiggly_13;
    sf::Texture S_Lani_14;
    sf::Texture S_Blatoud_15;
    sf::Texture S_Sledstac_16;
    sf::Texture S_Gunin_17;
    sf::Texture S_Dotal_18;
    sf::Texture S_Spakie_19;
    sf::Texture S_Smorbib_20;
    sf::Texture S_Shweed_21;
    sf::Texture S_Thakell_22;
    sf::Texture S_Zage_23;
    sf::Texture S_Cludogo_24;
    sf::Texture S_Beiglu_25;
    sf::Texture S_Clybok_26;
    sf::Texture S_Togarsaw_27;
    sf::Texture S_Slock_28;
    sf::Texture S_Caeseliar_29;
    sf::Texture S_Omnia_30;

    sf::Texture M_Vriska_1;
    sf::Texture M_Phantom_2;
    sf::Texture M_Kanelf_3;
    sf::Texture M_Gaxx_4;
    sf::Texture M_Shellbow_5;
    sf::Texture M_Marshan_6;
    sf::Texture M_Traria_7;
    sf::Texture M_Raorm_8;
    sf::Texture M_Krei_9;
    sf::Texture M_Sponk_10;
    sf::Texture M_Spurtle_11;
    sf::Texture M_Mosbie_12;
    sf::Texture M_Qiggly_13;
    sf::Texture M_Lani_14;
    sf::Texture M_Blatoud_15;
    sf::Texture M_Sledstac_16;
    sf::Texture M_Gunin_17;
    sf::Texture M_Dotal_18;
    sf::Texture M_Spakie_19;
    sf::Texture M_Smorbib_20;
    sf::Texture M_Shweed_21;
    sf::Texture M_Thakell_22;
    sf::Texture M_Zage_23;
    sf::Texture M_Cludogo_24;
    sf::Texture M_Beiglu_25;
    sf::Texture M_Clybok_26;
    sf::Texture M_Togarsaw_27;
    sf::Texture M_Slock_28;
    sf::Texture M_Caeseliar_29;
    sf::Texture M_Omnia_30;

    sf::Texture L_Vriska_1;
    sf::Texture L_Phantom_2;
    sf::Texture L_Kanelf_3;
    sf::Texture L_Gaxx_4;
    sf::Texture L_Shellbow_5;
    sf::Texture L_Marshan_6;
    sf::Texture L_Traria_7;
    sf::Texture L_Raorm_8;
    sf::Texture L_Krei_9;
    sf::Texture L_Sponk_10;
    sf::Texture L_Spurtle_11;
    sf::Texture L_Mosbie_12;
    sf::Texture L_Qiggly_13;
    sf::Texture L_Lani_14;
    sf::Texture L_Blatoud_15;
    sf::Texture L_Sledstac_16;
    sf::Texture L_Gunin_17;
    sf::Texture L_Dotal_18;
    sf::Texture L_Spakie_19;
    sf::Texture L_Smorbib_20;
    sf::Texture L_Shweed_21;
    sf::Texture L_Thakell_22;
    sf::Texture L_Zage_23;
    sf::Texture L_Cludogo_24;
    sf::Texture L_Beiglu_25;
    sf::Texture L_Clybok_26;
    sf::Texture L_Togarsaw_27;
    sf::Texture L_Slock_28;
    sf::Texture L_Caeseliar_29;
    sf::Texture L_Omnia_30;

};

struct Game_Board {

    struct Inventory* player1_Ter = NULL;
    struct Inventory* player1_Amp = NULL;
    struct Inventory* player1_Aer = NULL;

    struct Inventory* player2_Ter = NULL;
    struct Inventory* player2_Amp = NULL;
    struct Inventory* player2_Aer = NULL;

    sf::RectangleShape board_image;
    sf::RectangleShape elements;

    sf::RectangleShape background;

    sf::RectangleShape selecting_image; // when a card is click highlight possible board movements in yellow
};

struct Inventory {

    int card_num;

    int x_coord = 0;
    int y_coord = 0;
    
    int power = 0;
    int agility = 0;
    int defence = 0;
    int freakiness = 0;
    int intelligence = 0;

    int element = 1;
    
    int display_type = 1; //1 is normal, 2 is enlarged (happens when mouse is over) and 3 is when the card is in play (skip over it in functions)

    int selected = FALSE;

    sf::RectangleShape card_image;

    //sf::RectangleShape card_graphics; ADD ACTUAL GRAPHICS HERE

    struct Inventory* next;
};

struct EmptyCard {

    int x_coord;
    int y_coord;

    sf::RectangleShape card_graphics;
};

void Switch_Highlighted_Image(struct Texture_Struct* textures, struct Inventory * selected_card, int highlighted){
    //highlighted means its the med image so switch to small image
    if (highlighted == TRUE) {//add ==1 after selected card num
        if (selected_card->card_num == 1) { selected_card->card_image.setTexture(&textures->S_Vriska_1, true); return; }
        if (selected_card->card_num == 2) { selected_card->card_image.setTexture(&textures->S_Phantom_2, true); return; }
        if (selected_card->card_num == 3) { selected_card->card_image.setTexture(&textures->S_Kanelf_3, true); return; }
        if (selected_card->card_num == 4) { selected_card->card_image.setTexture(&textures->S_Gaxx_4, true); return; }
        if (selected_card->card_num == 5) { selected_card->card_image.setTexture(&textures->S_Shellbow_5, true); return; }
        if (selected_card->card_num == 6) { selected_card->card_image.setTexture(&textures->S_Marshan_6, true); return; }
        if (selected_card->card_num == 7) { selected_card->card_image.setTexture(&textures->S_Traria_7, true); return; }
        if (selected_card->card_num == 8) { selected_card->card_image.setTexture(&textures->S_Raorm_8, true); return; }
        if (selected_card->card_num == 9) { selected_card->card_image.setTexture(&textures->S_Krei_9, true); return; }
        if (selected_card->card_num == 10) { selected_card->card_image.setTexture(&textures->S_Sponk_10, true); return; }
        if (selected_card->card_num == 11) { selected_card->card_image.setTexture(&textures->S_Spurtle_11, true); return; }
        if (selected_card->card_num == 12) { selected_card->card_image.setTexture(&textures->S_Mosbie_12, true); return; }
        if (selected_card->card_num == 13) { selected_card->card_image.setTexture(&textures->S_Qiggly_13, true); return; }
        if (selected_card->card_num == 14) { selected_card->card_image.setTexture(&textures->S_Lani_14, true); return; }
        if (selected_card->card_num == 15) { selected_card->card_image.setTexture(&textures->S_Blatoud_15, true); return; }
        if (selected_card->card_num == 16) { selected_card->card_image.setTexture(&textures->S_Sledstac_16, true); return; }
        if (selected_card->card_num == 17) { selected_card->card_image.setTexture(&textures->S_Gunin_17, true); return; }
        if (selected_card->card_num == 18) { selected_card->card_image.setTexture(&textures->S_Dotal_18, true); return; }
        if (selected_card->card_num == 19) { selected_card->card_image.setTexture(&textures->S_Spakie_19, true); return; }
        if (selected_card->card_num == 20) { selected_card->card_image.setTexture(&textures->S_Smorbib_20, true); return; }
        if (selected_card->card_num == 21) { selected_card->card_image.setTexture(&textures->S_Shweed_21, true); return; }
        if (selected_card->card_num == 22) { selected_card->card_image.setTexture(&textures->S_Thakell_22, true); return; }
        if (selected_card->card_num == 23) { selected_card->card_image.setTexture(&textures->S_Zage_23, true); return; }
        if (selected_card->card_num == 24) { selected_card->card_image.setTexture(&textures->S_Cludogo_24, true); return; }
        if (selected_card->card_num == 25) { selected_card->card_image.setTexture(&textures->S_Beiglu_25, true); return; }
        if (selected_card->card_num == 26) { selected_card->card_image.setTexture(&textures->S_Clybok_26, true); return; }
        if (selected_card->card_num == 27) { selected_card->card_image.setTexture(&textures->S_Togarsaw_27, true); return; }
        if (selected_card->card_num == 28) { selected_card->card_image.setTexture(&textures->S_Slock_28, true); return; }
        if (selected_card->card_num == 29) { selected_card->card_image.setTexture(&textures->S_Caeseliar_29, true); return; }
        if (selected_card->card_num == 30) { selected_card->card_image.setTexture(&textures->S_Omnia_30, true); return; }
    }
    else{
        if (selected_card->card_num == 1) { selected_card->card_image.setTexture(&textures->M_Vriska_1, true); return; }
        if (selected_card->card_num == 2) { selected_card->card_image.setTexture(&textures->M_Phantom_2, true); return; }
        if (selected_card->card_num == 3) { selected_card->card_image.setTexture(&textures->M_Kanelf_3, true); return; }
        if (selected_card->card_num == 4) { selected_card->card_image.setTexture(&textures->M_Gaxx_4, true); return; }
        if (selected_card->card_num == 5) { selected_card->card_image.setTexture(&textures->M_Shellbow_5, true); return; }
        if (selected_card->card_num == 6) { selected_card->card_image.setTexture(&textures->M_Marshan_6, true); return; }
        if (selected_card->card_num == 7) { selected_card->card_image.setTexture(&textures->M_Traria_7, true); return; }
        if (selected_card->card_num == 8) { selected_card->card_image.setTexture(&textures->M_Raorm_8, true); return; }
        if (selected_card->card_num == 9) { selected_card->card_image.setTexture(&textures->M_Krei_9, true); return; }
        if (selected_card->card_num == 10) { selected_card->card_image.setTexture(&textures->M_Sponk_10, true); return; }
        if (selected_card->card_num == 11) { selected_card->card_image.setTexture(&textures->M_Spurtle_11, true); return; }
        if (selected_card->card_num == 12) { selected_card->card_image.setTexture(&textures->M_Mosbie_12, true); return; }
        if (selected_card->card_num == 13) { selected_card->card_image.setTexture(&textures->M_Qiggly_13, true); return; }
        if (selected_card->card_num == 14) { selected_card->card_image.setTexture(&textures->M_Lani_14, true); return; }
        if (selected_card->card_num == 15) { selected_card->card_image.setTexture(&textures->M_Blatoud_15, true); return; }
        if (selected_card->card_num == 16) { selected_card->card_image.setTexture(&textures->M_Sledstac_16, true); return; }
        if (selected_card->card_num == 17) { selected_card->card_image.setTexture(&textures->M_Gunin_17, true); return; }
        if (selected_card->card_num == 18) { selected_card->card_image.setTexture(&textures->M_Dotal_18, true); return; }
        if (selected_card->card_num == 19) { selected_card->card_image.setTexture(&textures->M_Spakie_19, true); return; }
        if (selected_card->card_num == 20) { selected_card->card_image.setTexture(&textures->M_Smorbib_20, true); return; }
        if (selected_card->card_num == 21) { selected_card->card_image.setTexture(&textures->M_Shweed_21, true); return; }
        if (selected_card->card_num == 22) { selected_card->card_image.setTexture(&textures->M_Thakell_22, true); return; }
        if (selected_card->card_num == 23) { selected_card->card_image.setTexture(&textures->M_Zage_23, true); return; }
        if (selected_card->card_num == 24) { selected_card->card_image.setTexture(&textures->M_Cludogo_24, true); return; }
        if (selected_card->card_num == 25) { selected_card->card_image.setTexture(&textures->M_Beiglu_25, true); return; }
        if (selected_card->card_num == 26) { selected_card->card_image.setTexture(&textures->M_Clybok_26, true); return; }
        if (selected_card->card_num == 27) { selected_card->card_image.setTexture(&textures->M_Togarsaw_27, true); return; }
        if (selected_card->card_num == 28) { selected_card->card_image.setTexture(&textures->M_Slock_28, true); return; }
        if (selected_card->card_num == 29) { selected_card->card_image.setTexture(&textures->M_Caeseliar_29, true); return; }
        if (selected_card->card_num == 30) { selected_card->card_image.setTexture(&textures->M_Omnia_30, true); return; }
    }




    return;
}

void Get_Card_Bank(int card_bank[CARDBANKSIZE]) {

    /* Fills a CARDBANKSIZE long array with non repeating random integers between 1 and TOTALCARDS */

    int counter = 0;
    int iterater = 0;
    int random_num = rand() % TOTALCARDS + 1;
    //card_bank[counter] = random_num;
    while (counter != CARDBANKSIZE) {
        random_num = rand() % TOTALCARDS + 1;
        while (iterater != counter+1) {
            if (random_num != card_bank[iterater]) {
                iterater++;
            }
            else {
                random_num = rand() % TOTALCARDS + 1;
                iterater = 0;
            }
        }
        iterater = 0;
        if (counter != CARDBANKSIZE) {
            card_bank[counter] = random_num;
        }
        counter++;
    }
}
void Print_Linked_List(struct Inventory* list) {

    struct Inventory* cur_node = list;
    while (cur_node->next != NULL) {
    
        cout << cur_node->card_num << endl;
        cur_node = cur_node->next;

    }
    cout << cur_node->card_num << endl;

}

void Print_Array(int parsed_array[], int size) {
    int i = 0;
    while (i != size) {

        cout << parsed_array[i] << endl;
        i++;

    }
    cout << parsed_array[i] << endl;

}
void Starting_Cards(int card_bank[CARDBANKSIZE], struct Inventory * player1_cards, struct Inventory* player2_cards, struct Inventory* card_pile) {

    /* Organises both players cards and the total card bank into linked lists */
    //Print_Array(card_bank, CARDBANKSIZE);
    sf::RectangleShape card(sf::Vector2f(A2WIDTH, A2HEIGHT));
    //card.setFillColor(sf::Color::Red);

    int counter = 0;

    player1_cards->card_num = card_bank[counter];
    player1_cards->next = NULL;
    
    player1_cards->card_image = card; //= card(sf::Vector2f(A2WIDTH, A2HEIGHT));


    player1_cards->card_image.setPosition(0, 0);
    
    counter++;
    while (counter != STARTINGCARDS) {
        
        struct Inventory* new_card = new struct Inventory;//(struct Inventory*)malloc(sizeof(struct Inventory));
        new_card->next = NULL;
        new_card->card_num = card_bank[counter];

        struct Inventory* cur_node = player1_cards;

        while (cur_node->next != NULL) {
            cur_node = cur_node->next;
        }
        cur_node->next = new_card;

        counter++;
    }
    //Print_Linked_List(player1_cards);
    player2_cards->card_num = card_bank[counter];
    player2_cards->next = NULL;
    counter++;
    while (counter != (STARTINGCARDS+ STARTINGCARDS)) {

        struct Inventory* new_card = new struct Inventory;//(struct Inventory*)malloc(sizeof(struct Inventory));
        new_card->next = NULL;
        new_card->card_num = card_bank[counter];

        struct Inventory* cur_node = player2_cards;

        while (cur_node->next != NULL) {
            cur_node = cur_node->next;
        }
        cur_node->next = new_card;

        counter++;
    }
    //Print_Linked_List(player2_cards);

    card_pile->card_num = card_bank[counter];
    card_pile->next = NULL;
    counter++;

    while (counter != CARDBANKSIZE) {

        struct Inventory* new_card = new struct Inventory; //(struct Inventory*)malloc(sizeof(struct Inventory));
        new_card->next = NULL;
        new_card->card_num = card_bank[counter];

        struct Inventory* cur_node = card_pile;

        while (cur_node->next != NULL) {
            cur_node = cur_node->next;
        }
        cur_node->next = new_card;

        counter++;

    }
}

void Create_Card_Graphics(struct EmptyCard empty_card_array[16]) {
    //0 - 7 are top, 8-15 are bottom    
    sf::RectangleShape card(sf::Vector2f(A2WIDTH, A2HEIGHT));
    card.setFillColor(sf::Color::Green);

    int card_buffer = (SCREENWIDTH - (7 * 1.2 * ((SCREENWIDTH - (SCREENWIDTH / 6)) / 8)) - A2WIDTH)/2;
    //cout << card_buffer << endl;
    for (int i = 0; i != 8; i++) {
        //struct EmptyCard * NewCard = (struct EmptyCard*)malloc(sizeof(struct EmptyCard));
        struct EmptyCard NewCard;
        
        NewCard.x_coord = card_buffer +(i*1.2*((SCREENWIDTH- (SCREENWIDTH/6))/8));
        NewCard.y_coord = card_buffer;//+ (1.18 * ((SCREENWIDTH - (SCREENWIDTH / 6)) / 8));
        NewCard.card_graphics = card;
        NewCard.card_graphics.setPosition(NewCard.x_coord, NewCard.y_coord);

        empty_card_array[i] = NewCard;
    }
    for (int i = 0; i != 8; i++) {
        //struct EmptyCard * NewCard = (struct EmptyCard*)malloc(sizeof(struct EmptyCard));
        struct EmptyCard NewCard;
        
        NewCard.x_coord = card_buffer + (i * 1.2 * ((SCREENWIDTH - (SCREENWIDTH / 6)) / 8));
        NewCard.y_coord = SCREENHEIGHT- card_buffer -(A2HEIGHT);
        NewCard.card_graphics = card;
        NewCard.card_graphics.setPosition(NewCard.x_coord, NewCard.y_coord);

        empty_card_array[i+8] = NewCard;
    }
    //cout << empty_card_array[7].x_coord + A2WIDTH * 1.4 << endl;

}
void Initialise_Graphics(struct Texture_Struct* textures, struct Inventory* player1_cards, struct Inventory* player2_cards, struct Inventory* card_pile, struct Game_Board* game_board) {

    if (!textures->S_Vriska_1.loadFromFile("Graphics/Cards/Small/S_1_Vriska.png")) { cout << "TEXTURE ERROR" << endl; }
    if (!textures->M_Vriska_1.loadFromFile("Graphics/Cards/Medium/M_1_Vriska.png")) { cout << "TEXTURE ERROR" << endl; }
    if (!textures->L_Vriska_1.loadFromFile("Graphics/Cards/Large/L_1_Vriska.png")) { cout << "TEXTURE ERROR" << endl; }

    if (!textures->S_Phantom_2.loadFromFile("Graphics/Cards/Small/S_2_Phantom.png")) { cout << "TEXTURE ERROR" << endl; }
    if (!textures->M_Phantom_2.loadFromFile("Graphics/Cards/Medium/M_2_Phantom.png")) { cout << "TEXTURE ERROR" << endl; }
    if (!textures->L_Phantom_2.loadFromFile("Graphics/Cards/Large/L_2_Phantom.png")) { cout << "TEXTURE ERROR" << endl; }

    if (!textures->S_Kanelf_3.loadFromFile("Graphics/Cards/Small/S_3_Kanelf.png")) { cout << "TEXTURE ERROR" << endl; }
    if (!textures->M_Kanelf_3.loadFromFile("Graphics/Cards/Medium/M_3_Kanelf.png")) { cout << "TEXTURE ERROR" << endl; }
    if (!textures->L_Kanelf_3.loadFromFile("Graphics/Cards/Large/L_3_Kanelf.png")) { cout << "TEXTURE ERROR" << endl; }

    if (!textures->S_Gaxx_4.loadFromFile("Graphics/Cards/Small/S_4_Gaxx.png")) { cout << "TEXTURE ERROR" << endl; }
    if (!textures->M_Gaxx_4.loadFromFile("Graphics/Cards/Medium/M_4_Gaxx.png")) { cout << "TEXTURE ERROR" << endl; }
    if (!textures->L_Gaxx_4.loadFromFile("Graphics/Cards/Large/L_4_Gaxx.png")) { cout << "TEXTURE ERROR" << endl; }

    if (!textures->S_Shellbow_5.loadFromFile("Graphics/Cards/Small/S_5_Shellbow.png")) { cout << "TEXTURE ERROR" << endl; }
    if (!textures->M_Shellbow_5.loadFromFile("Graphics/Cards/Medium/M_5_Shellbow.png")) { cout << "TEXTURE ERROR" << endl; }
    if (!textures->L_Shellbow_5.loadFromFile("Graphics/Cards/Large/L_5_Shellbow.png")) { cout << "TEXTURE ERROR" << endl; }

    if (!textures->S_Marshan_6.loadFromFile("Graphics/Cards/Small/S_6_Marshan.png")) { cout << "TEXTURE ERROR" << endl; }
    if (!textures->M_Marshan_6.loadFromFile("Graphics/Cards/Medium/M_6_Marshan.png")) { cout << "TEXTURE ERROR" << endl; }
    if (!textures->L_Marshan_6.loadFromFile("Graphics/Cards/Large/L_6_Marshan.png")) { cout << "TEXTURE ERROR" << endl; }

    if (!textures->S_Traria_7.loadFromFile("Graphics/Cards/Small/S_7_Traria.png")) { cout << "TEXTURE ERROR" << endl; }
    if (!textures->M_Traria_7.loadFromFile("Graphics/Cards/Medium/M_7_Traria.png")) { cout << "TEXTURE ERROR" << endl; }
    if (!textures->L_Traria_7.loadFromFile("Graphics/Cards/Large/L_7_Traria.png")) { cout << "TEXTURE ERROR" << endl; }

    if (!textures->S_Raorm_8.loadFromFile("Graphics/Cards/Small/S_8_Raorm.png")) { cout << "TEXTURE ERROR" << endl; }
    if (!textures->M_Raorm_8.loadFromFile("Graphics/Cards/Medium/M_8_Raorm.png")) { cout << "TEXTURE ERROR" << endl; }
    if (!textures->L_Raorm_8.loadFromFile("Graphics/Cards/Large/L_8_Raorm.png")) { cout << "TEXTURE ERROR" << endl; }

    if (!textures->S_Krei_9.loadFromFile("Graphics/Cards/Small/S_9_Krei.png")) { cout << "TEXTURE ERROR" << endl; }
    if (!textures->M_Krei_9.loadFromFile("Graphics/Cards/Medium/M_9_Krei.png")) { cout << "TEXTURE ERROR" << endl; }
    if (!textures->L_Krei_9.loadFromFile("Graphics/Cards/Large/L_9_Krei.png")) { cout << "TEXTURE ERROR" << endl; }

    if (!textures->S_Sponk_10.loadFromFile("Graphics/Cards/Small/S_10_Sponk.png")) { cout << "TEXTURE ERROR" << endl; }
    if (!textures->M_Sponk_10.loadFromFile("Graphics/Cards/Medium/M_10_Sponk.png")) { cout << "TEXTURE ERROR" << endl; }
    if (!textures->L_Sponk_10.loadFromFile("Graphics/Cards/Large/L_10_Sponk.png")) { cout << "TEXTURE ERROR" << endl; }

    if (!textures->S_Spurtle_11.loadFromFile("Graphics/Cards/Small/S_11_Spurtle.png")) { cout << "TEXTURE ERROR" << endl; }
    if (!textures->M_Spurtle_11.loadFromFile("Graphics/Cards/Medium/M_11_Spurtle.png")) { cout << "TEXTURE ERROR" << endl; }
    if (!textures->L_Spurtle_11.loadFromFile("Graphics/Cards/Large/L_11_Spurtle.png")) { cout << "TEXTURE ERROR" << endl; }

    if (!textures->S_Mosbie_12.loadFromFile("Graphics/Cards/Small/S_12_Mosbie.png")) { cout << "TEXTURE ERROR" << endl; }
    if (!textures->M_Mosbie_12.loadFromFile("Graphics/Cards/Medium/M_12_Mosbie.png")) { cout << "TEXTURE ERROR" << endl; }
    if (!textures->L_Mosbie_12.loadFromFile("Graphics/Cards/Large/L_12_Mosbie.png")) { cout << "TEXTURE ERROR" << endl; }

    if (!textures->S_Qiggly_13.loadFromFile("Graphics/Cards/Small/S_13_Qiggly.png")) { cout << "TEXTURE ERROR" << endl; }
    if (!textures->M_Qiggly_13.loadFromFile("Graphics/Cards/Medium/M_13_Qiggly.png")) { cout << "TEXTURE ERROR" << endl; }
    if (!textures->L_Qiggly_13.loadFromFile("Graphics/Cards/Large/L_13_Qiggly.png")) { cout << "TEXTURE ERROR" << endl; }

    if (!textures->S_Lani_14.loadFromFile("Graphics/Cards/Small/S_14_Lani.png")) { cout << "TEXTURE ERROR" << endl; }
    if (!textures->M_Lani_14.loadFromFile("Graphics/Cards/Medium/M_14_Lani.png")) { cout << "TEXTURE ERROR" << endl; }
    if (!textures->L_Lani_14.loadFromFile("Graphics/Cards/Large/L_14_Lani.png")) { cout << "TEXTURE ERROR" << endl; }

    if (!textures->S_Blatoud_15.loadFromFile("Graphics/Cards/Small/S_15_Blatoud.png")) { cout << "TEXTURE ERROR" << endl; }
    if (!textures->M_Blatoud_15.loadFromFile("Graphics/Cards/Medium/M_15_Blatoud.png")) { cout << "TEXTURE ERROR" << endl; }
    if (!textures->L_Blatoud_15.loadFromFile("Graphics/Cards/Large/L_15_Blatoud.png")) { cout << "TEXTURE ERROR" << endl; }

    if (!textures->S_Sledstac_16.loadFromFile("Graphics/Cards/Small/S_16_Sledstac.png")) { cout << "TEXTURE ERROR" << endl; }
    if (!textures->M_Sledstac_16.loadFromFile("Graphics/Cards/Medium/M_16_Sledstac.png")) { cout << "TEXTURE ERROR" << endl; }
    if (!textures->L_Sledstac_16.loadFromFile("Graphics/Cards/Large/L_16_Sledstac.png")) { cout << "TEXTURE ERROR" << endl; }

    if (!textures->S_Gunin_17.loadFromFile("Graphics/Cards/Small/S_17_Gunin.png")) { cout << "TEXTURE ERROR" << endl; }
    if (!textures->M_Gunin_17.loadFromFile("Graphics/Cards/Medium/M_17_Gunin.png")) { cout << "TEXTURE ERROR" << endl; }
    if (!textures->L_Gunin_17.loadFromFile("Graphics/Cards/Large/L_17_Gunin.png")) { cout << "TEXTURE ERROR" << endl; }

    if (!textures->S_Dotal_18.loadFromFile("Graphics/Cards/Small/S_18_Dotal.png")) { cout << "TEXTURE ERROR" << endl; }
    if (!textures->M_Dotal_18.loadFromFile("Graphics/Cards/Medium/M_18_Dotal.png")) { cout << "TEXTURE ERROR" << endl; }
    if (!textures->L_Dotal_18.loadFromFile("Graphics/Cards/Large/L_18_Dotal.png")) { cout << "TEXTURE ERROR" << endl; }

    if (!textures->S_Spakie_19.loadFromFile("Graphics/Cards/Small/S_19_Spakie.png")) { cout << "TEXTURE ERROR" << endl; }
    if (!textures->M_Spakie_19.loadFromFile("Graphics/Cards/Medium/M_19_Spakie.png")) { cout << "TEXTURE ERROR" << endl; }
    if (!textures->L_Spakie_19.loadFromFile("Graphics/Cards/Large/L_19_Spakie.png")) { cout << "TEXTURE ERROR" << endl; }

    if (!textures->S_Smorbib_20.loadFromFile("Graphics/Cards/Small/S_20_Smorbib.png")) { cout << "TEXTURE ERROR" << endl; }
    if (!textures->M_Smorbib_20.loadFromFile("Graphics/Cards/Medium/M_20_Smorbib.png")) { cout << "TEXTURE ERROR" << endl; }
    if (!textures->L_Smorbib_20.loadFromFile("Graphics/Cards/Large/L_20_Smorbib.png")) { cout << "TEXTURE ERROR" << endl; }

    if (!textures->S_Shweed_21.loadFromFile("Graphics/Cards/Small/S_21_Shweed.png")) { cout << "TEXTURE ERROR" << endl; }
    if (!textures->M_Shweed_21.loadFromFile("Graphics/Cards/Medium/M_21_Shweed.png")) { cout << "TEXTURE ERROR" << endl; }
    if (!textures->L_Shweed_21.loadFromFile("Graphics/Cards/Large/L_21_Shweed.png")) { cout << "TEXTURE ERROR" << endl; }

    if (!textures->S_Thakell_22.loadFromFile("Graphics/Cards/Small/S_22_Thakell.png")) { cout << "TEXTURE ERROR" << endl; }
    if (!textures->M_Thakell_22.loadFromFile("Graphics/Cards/Medium/M_22_Thakell.png")) { cout << "TEXTURE ERROR" << endl; }
    if (!textures->L_Thakell_22.loadFromFile("Graphics/Cards/Large/L_22_Thakell.png")) { cout << "TEXTURE ERROR" << endl; }

    if (!textures->S_Zage_23.loadFromFile("Graphics/Cards/Small/S_23_Zage.png")) { cout << "TEXTURE ERROR" << endl; }
    if (!textures->M_Zage_23.loadFromFile("Graphics/Cards/Medium/M_23_Zage.png")) { cout << "TEXTURE ERROR" << endl; }
    if (!textures->L_Zage_23.loadFromFile("Graphics/Cards/Large/L_23_Zage.png")) { cout << "TEXTURE ERROR" << endl; }

    if (!textures->S_Cludogo_24.loadFromFile("Graphics/Cards/Small/S_24_Cludogo.png")) { cout << "TEXTURE ERROR" << endl; }
    if (!textures->M_Cludogo_24.loadFromFile("Graphics/Cards/Medium/M_24_Cludogo.png")) { cout << "TEXTURE ERROR" << endl; }
    if (!textures->L_Cludogo_24.loadFromFile("Graphics/Cards/Large/L_24_Cludogo.png")) { cout << "TEXTURE ERROR" << endl; }

    if (!textures->S_Beiglu_25.loadFromFile("Graphics/Cards/Small/S_25_Beiglu.png")) { cout << "TEXTURE ERROR" << endl; }
    if (!textures->M_Beiglu_25.loadFromFile("Graphics/Cards/Medium/M_25_Beiglu.png")) { cout << "TEXTURE ERROR" << endl; }
    if (!textures->L_Beiglu_25.loadFromFile("Graphics/Cards/Large/L_25_Beiglu.png")) { cout << "TEXTURE ERROR" << endl; }

    if (!textures->S_Clybok_26.loadFromFile("Graphics/Cards/Small/S_26_Clybok.png")) { cout << "TEXTURE ERROR" << endl; }
    if (!textures->M_Clybok_26.loadFromFile("Graphics/Cards/Medium/M_26_Clybok.png")) { cout << "TEXTURE ERROR" << endl; }
    if (!textures->L_Clybok_26.loadFromFile("Graphics/Cards/Large/L_26_Clybok.png")) { cout << "TEXTURE ERROR" << endl; }

    if (!textures->S_Togarsaw_27.loadFromFile("Graphics/Cards/Small/S_27_Togarsaw.png")) { cout << "TEXTURE ERROR" << endl; }
    if (!textures->M_Togarsaw_27.loadFromFile("Graphics/Cards/Medium/M_27_Togarsaw.png")) { cout << "TEXTURE ERROR" << endl; }
    if (!textures->L_Togarsaw_27.loadFromFile("Graphics/Cards/Large/L_27_Togarsaw.png")) { cout << "TEXTURE ERROR" << endl; }

    if (!textures->S_Slock_28.loadFromFile("Graphics/Cards/Small/S_28_Slock.png")) { cout << "TEXTURE ERROR" << endl; }
    if (!textures->M_Slock_28.loadFromFile("Graphics/Cards/Medium/M_28_Slock.png")) { cout << "TEXTURE ERROR" << endl; }
    if (!textures->L_Slock_28.loadFromFile("Graphics/Cards/Large/L_28_Slock.png")) { cout << "TEXTURE ERROR" << endl; }

    if (!textures->S_Caeseliar_29.loadFromFile("Graphics/Cards/Small/S_29_Caeseliar.png")) { cout << "TEXTURE ERROR" << endl; }
    if (!textures->M_Caeseliar_29.loadFromFile("Graphics/Cards/Medium/M_29_Caeseliar.png")) { cout << "TEXTURE ERROR" << endl; }
    if (!textures->L_Caeseliar_29.loadFromFile("Graphics/Cards/Large/L_29_Caeseliar.png")) { cout << "TEXTURE ERROR" << endl; }

    if (!textures->S_Omnia_30.loadFromFile("Graphics/Cards/Small/S_30_Omnia.png")) { cout << "TEXTURE ERROR" << endl; }
    if (!textures->M_Omnia_30.loadFromFile("Graphics/Cards/Medium/M_30_Omnia.png")) { cout << "TEXTURE ERROR" << endl; }
    if (!textures->L_Omnia_30.loadFromFile("Graphics/Cards/Large/L_30_Omnia.png")) { cout << "TEXTURE ERROR" << endl; }


    if (!textures->S_Card_Backside.loadFromFile("Graphics/Cards/Small/TopTrumpBackside.png")) { cout << "TEXTURE ERROR" << endl; }

    //Board and background
    if (!textures->Board_Cards.loadFromFile("Graphics/Board/Game_Board_Cards.png")) { cout << "TEXTURE ERROR" << endl; }
    if (!textures->Elements.loadFromFile("Graphics/Board/Elements.png")) { cout << "TEXTURE ERROR" << endl; }
    if (!textures->Background.loadFromFile("Graphics/Board/Background.png")) { cout << "TEXTURE ERROR" << endl; }

    struct Inventory* curnode = player1_cards;
    while (curnode != NULL) {
        //curnode->card_image.setTexture(&textures->S_Sledstac_16, true);
        Switch_Highlighted_Image(textures, curnode, TRUE);
        curnode = curnode->next;
    }
    curnode = player2_cards;
    while (curnode != NULL) {
        curnode->card_image.setTexture(&textures->S_Card_Backside, true);
        curnode = curnode->next;
    }

    game_board->board_image.setTexture(&textures->Board_Cards, true);
    game_board->elements.setTexture(&textures->Elements, true);
    game_board->background.setTexture(&textures->Background, true);
}
void Set_Board_Position(struct Game_Board* game_board) {

    int new_height = (A2HEIGHT * 2) + (A2WIDTH / 2);//(A2HEIGHT * 3) + (A2HEIGHT / 2);
    int new_width = (A2WIDTH * 3) + (A2WIDTH / 2);
    //sf::RectangleShape card(sf::Vector2f(new_width, new_height));
    printf("height: %d, width: %d\n",new_height,new_width);
    sf::RectangleShape board(sf::Vector2f(new_width, new_height));
    int board_pos_x = (SCREENWIDTH / 2) - (new_width / 2);
    //board.setFillColor(sf::Color::Red);
    board.setPosition(board_pos_x, 0);
    game_board->board_image = board;
    game_board->elements = board;

    sf::RectangleShape background(sf::Vector2f(SCREENWIDTH, SCREENHEIGHT));
    game_board->background = background;
}

void Set_Card_Positions(struct Inventory* player1_cards, struct Inventory* player2_cards, struct EmptyCard empty_card_array[16]) {
    //Print_Linked_List(player1_cards);
    
    //Setup xcoords and ycoords
    int buffer = 25; // empty space in top right corner
    int card_room = 60; // y distance between cards

    sf::RectangleShape card(sf::Vector2f(A2WIDTH, A2HEIGHT));

    struct Inventory* curnode = player1_cards;
    int i = 0;
    while (curnode != NULL) {
        curnode->x_coord = buffer;
        curnode->y_coord = buffer + (card_room * i);
        curnode->card_image = card;
        curnode->card_image.setPosition(curnode->x_coord, curnode->y_coord);
        curnode = curnode->next;
        i++;
        
    }


    curnode = player2_cards;
    i = 0;
    while (curnode != NULL) {
        curnode->x_coord = SCREENWIDTH-buffer-A2WIDTH;
        curnode->y_coord = buffer + (card_room * i);
        curnode->card_image = card;
        curnode->card_image.setPosition(curnode->x_coord, curnode->y_coord);
        curnode = curnode->next;
        i++;

    }
    
}
void Get_Highlighted_Card(sf::RenderWindow& window, struct Inventory* player1_cards) {
    //UNUSED ATM
    struct Inventory* highlighted_card = NULL;

    sf::Vector2f mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));
    sf::FloatRect bounds;
    struct Inventory* curnode = player1_cards;
    while (curnode != NULL) {
        bounds = curnode->card_image.getGlobalBounds();

        // check all cards in list
        if (bounds.contains(mouse))
        {
            highlighted_card = curnode;
            
            // mouse is on sprite!
        }
        curnode->card_image.setSize(sf::Vector2f(A2WIDTH, A2HEIGHT));
        curnode = curnode->next;
    }
    if (highlighted_card != NULL) {
        highlighted_card->card_image.setSize(sf::Vector2f(A2WIDTH * 1.2, A2HEIGHT * 1.2));
    }
}

struct Inventory* Get_Selected_Card(sf::RenderWindow& window, struct Inventory* player1_cards, struct Texture_Struct * textures) {

    struct Inventory* selected_card = NULL;

    sf::Vector2f mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));
    sf::FloatRect bounds;
    struct Inventory* curnode = player1_cards;
    while (curnode != NULL) {
        bounds = curnode->card_image.getGlobalBounds();

        // check all cards in list
        if (bounds.contains(mouse))
        {
            selected_card = curnode;

            // mouse is on sprite!
        }

        curnode = curnode->next;
    }
    curnode = player1_cards;
    while (curnode != NULL) {
        bounds = curnode->card_image.getGlobalBounds();
        if (curnode != selected_card && curnode->display_type == ENLARGED_DISPLAY) {
            Switch_Highlighted_Image(textures, curnode, TRUE); //true means it is highlighted
            curnode->card_image.setSize(sf::Vector2f(A2WIDTH, A2HEIGHT));
            curnode->card_image.setPosition(curnode->x_coord, curnode->y_coord);
            curnode->display_type = NORMAL_DISPLAY;
        }
        if(curnode->display_type == ENLARGED_DISPLAY && bounds.contains(mouse)){
            selected_card = curnode;
        }
        curnode = curnode->next;
    }
    if (selected_card != NULL) {
        Switch_Highlighted_Image(textures, selected_card, FALSE); 
        selected_card->card_image.setSize(sf::Vector2f(A2WIDTHHIGHLIGHTED, A2HEIGHTHIGHLIGHTED));
        selected_card->card_image.setPosition(  (selected_card->x_coord) - ((A2WIDTHHIGHLIGHTED-A2WIDTH)/2), (selected_card->y_coord) - ((A2HEIGHTHIGHLIGHTED - A2HEIGHT) / 2));
        selected_card->display_type = ENLARGED_DISPLAY;
        //selected_card->card_image.setSize(sf::Vector2f(A2WIDTH * 1.2, A2HEIGHT * 1.2));
        return selected_card;
    }
    else {
        return NULL;
    }


}

void Draw_Card_Outlines(sf::RenderWindow &window, struct EmptyCard empty_card_array[16]) {
    for (int i = 0; i != 16; i++) {
        window.draw(empty_card_array[i].card_graphics);
    }
}

void Draw_Board(sf::RenderWindow& window, struct Game_Board* game_board) {
    window.draw(game_board->background);
    window.draw(game_board->board_image);
    //add selector here
    window.draw(game_board->elements);
}


void Draw_Cards(sf::RenderWindow& window, struct Inventory* player1_cards, struct Inventory* player2_cards) {
    struct Inventory* selected_card = NULL;

    struct Inventory* curnode = player1_cards;
    while (curnode != NULL) {
        
        
        if (curnode->display_type == ENLARGED_DISPLAY) {
            selected_card = curnode;
        }
        else {
            window.draw(curnode->card_image);

        }
        curnode = curnode->next;
    }
    if (selected_card != NULL) {
        //selected_card->card_image.setSize(sf::Vector2f(A2WIDTHHIGHLIGHTED, A2HEIGHTHIGHLIGHTED));
        window.draw(selected_card->card_image);
    }

    curnode = player2_cards;
    while (curnode != NULL) {
        window.draw(curnode->card_image);
        curnode = curnode->next;
    }

    /*
    for (int i = 0; i != 8; i++) {
        window.draw(player1_cards->card_image);
    }
    */
}


int main() {

    cout << "Waiting for connection . . ." << endl;

    //SET UP SERVER

    //intialise winsock
    WSADATA wsData;

    WORD ver = MAKEWORD(2, 2);

    int wsOk = WSAStartup(ver, &wsData);

    if (wsOk != 0) {
        cerr << "cant intialise winsock, quitting )= " << endl;
        return 1;

    }

    //create socket

    SOCKET listening = socket(AF_INET, SOCK_STREAM, 0);

    if (listening == INVALID_SOCKET) {

        cerr << "cant create socket, quitting" << endl;
    }

    fd_set current_sockets, ready_sockets;
    FD_ZERO(&current_sockets);
    FD_SET(listening, &current_sockets);

    //bind to an ip address and port

    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(54000);
    hint.sin_addr.S_un.S_addr = INADDR_ANY;

    bind(listening, (sockaddr*)&hint, sizeof(hint));

    // tell winsock the socket is for listening
    listen(listening, SOMAXCONN);

    //wait for a connection

    sockaddr_in client;
    int clientSize = sizeof(client);
    SOCKET clientSocket = accept(listening, (sockaddr*)&client, &clientSize);

    if (clientSocket == INVALID_SOCKET) {

        cerr << "cant accept socket, quitting" << endl;
        return 1;
    }

    char host[NI_MAXHOST]; //clients remote name
    char service[NI_MAXHOST]; //Port the client is connected on

    ZeroMemory(host, NI_MAXHOST); //TO PORT TO MAC USE memset(host, 0, NI_MAXHOST); instead
    ZeroMemory(service, NI_MAXSERV);

    if (getnameinfo((sockaddr*)&client, sizeof(client), host, NI_MAXHOST, service, NI_MAXSERV, 0) == 0) {
        cout << host << " (1) connected on port " << service << endl;
    }
    else {
        inet_ntop(AF_INET, &client.sin_addr, host, NI_MAXHOST);
        cout << host << " (2) connected on port " <<
            ntohs(client.sin_port) << endl;
    }

    //close listening socket

    closesocket(listening);


    //this goes in game loop later
    string userInput;

    char buf[4096];



    //SET UP GAME

    assert(STARTINGCARDS + STARTINGCARDS > 0);

    //Intialise Variables
    srand(time(NULL));

    int card_bank[CARDBANKSIZE] = { 0 };

    struct Inventory* player1_cards = new struct Inventory;//(struct Inventory*) malloc(sizeof(struct Inventory));
    struct Inventory* player2_cards = new struct Inventory;//(struct Inventory*)malloc(sizeof(struct Inventory));
    struct Inventory* discard_pile = new struct Inventory; //(struct Inventory*)malloc(sizeof(struct Inventory));
    struct Inventory* card_pile = new struct Inventory;//(struct Inventory*)malloc(sizeof(struct Inventory));

    discard_pile = NULL;

    //int game_board_array[2][3] = { 0 }; //This is for sending to client/server NOT for the gamelogic
    int gamestate = CARD_PLACING;
    int game_data[BYTESOFGAMEDATA] = {2};
    //struct Inventory* game_board_linked_list[2][3] = { NULL };
    //int both_players_ready = FALSE;
    int player_1_ready = FALSE;
    int player_2_ready = FALSE;
    int game_display_information = NORMAL_DISPLAY_SCREEN;

    struct Inventory* card_selected = NULL;
    struct EmptyCard empty_card_array[16];
    struct Texture_Struct *textures = new struct Texture_Struct;

    struct Game_Board* game_board = new struct Game_Board;//(struct Inventory*)malloc(sizeof(struct Inventory));

    //Game Logic Functions
    Get_Card_Bank(card_bank);
    Starting_Cards(card_bank, player1_cards, player2_cards, card_pile);
    Create_Card_Graphics(empty_card_array);
    Print_Linked_List(player1_cards);
    Set_Card_Positions(player1_cards, player2_cards, empty_card_array);
    Set_Board_Position(game_board);

    Initialise_Graphics(textures, player1_cards, player2_cards, card_pile, game_board);

    //Setup Game Window
    sf::RenderWindow window(sf::VideoMode(SCREENWIDTH, SCREENHEIGHT), "Phantrumps", sf::Style::Titlebar | sf::Style::Close);
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    //sf::RenderWindow window(sf::VideoMode(800, 600), "SFML shapes", sf::Style::Default, settings);
    //sf::RenderWindow window(sf::VideoMode(SCREENWIDTH, SCREENHEIGHT), "Phantrumps");
    //sf::RenderWindow window(sf::VideoMode(SCREENWIDTH, SCREENHEIGHT), "Phantrumps", sf::Style::Fullscreen);
    int ret;

    //Game Loop
    while (window.isOpen())
    {


        if (gamestate == CARD_PLACING) {
            if (player_1_ready == TRUE && player_2_ready == TRUE) {
            
            }
            else {
            
                //stuff player 1 does when they arnt ready - check if ready button is clicked so can send info to player 2
            
            }
            if (player_2_ready == FALSE) {
                //listen for socket then say player 2 is ready
            }

        
        }
        else if (gamestate == PLAYER_1_ATK) {
            //do shit then send socket data
        
        }
        else if (gamestate == PLAYER_2_ATK) {
            //wait for recieved socket data
        }




        //win check

        if (player1_cards == NULL) {
            //do something        
        }
        else if (player2_cards == NULL) {
            //do something else
        }



        struct timeval timeout;
        timeout.tv_sec = 0;
        timeout.tv_usec = 0;
        //fcntl(sock, F_SETFL, fcntl(sock, F_GETFL) | O_NONBLOCK);

        fd_set rds;
        FD_ZERO(&rds);
        FD_SET(clientSocket, &rds);
        ret = select(clientSocket + 1, &rds, NULL, NULL, &timeout);
        //IF RET IS 0 THERE IS NO DATA, IF IT IS 1 THERE IS DATA, IF IT IS -1 THERE IS ERROR
        // THIS TOOK WAY TO FUKCING LONG
        //printf("Ret is: %d\n", ret);

        //wait for client
        if (FD_ISSET(clientSocket, &rds)) {
            
            
            ZeroMemory(buf, 4096);
            int bytesReceived = recv(clientSocket, buf, 4096, 0);
            //buf is client Data

            //Errors
            if (bytesReceived == SOCKET_ERROR) {cerr << "Client quit program or Socket error occured, quitting program " << endl;break; }
            if (bytesReceived == 0) {cout << "client disconnected " << endl; break;}

            //Sending Data
            printf("Client> %s\n", buf);
            string userInput = "Hello World!";
            cout << userInput.size() << endl;
            //send(clientSocket, userInput.c_str(), userInput.size() + 1, 0);
            send(clientSocket, (char*)game_data, BYTESOFGAMEDATA+ 1, 0);
        }
        else if(ret == -1) {
            cout << "ret is -1 ERROR\n" << endl;
            WSACleanup();
            closesocket(clientSocket);
        }
        /*
        sf::Vector2f mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));
        // retrieve the bounding box of the sprite
        
        sf::FloatRect bounds;
        struct Inventory* curnode = player1_cards;
        while (curnode != NULL) {
            bounds = curnode->card_image.getGlobalBounds();
            // check all cards in list
            if (bounds.contains(mouse))
            {
                cout << "test" << endl;
                curnode->display_type = ENLARGED_DISPLAY;
                curnode->card_image.setSize(sf::Vector2f(A2WIDTH*1.2, A2HEIGHT*1.2));
                break;
                // mouse is on sprite!
            }
            else {
                curnode->display_type = NORMAL_DISPLAY;
                curnode->card_image.setSize(sf::Vector2f(A2WIDTH, A2HEIGHT));
            }
            curnode = curnode->next;
        }
        */
        //Get_Highlighted_Card(window, player1_cards);
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            else if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    card_selected = Get_Selected_Card(window, player1_cards, textures);
                    if (card_selected != NULL) {

                        //Put into board

                    }
                    /*
                    sf::Vector2f mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                    // retrieve the bounding box of the sprite
                    sf::FloatRect bounds;
                    struct Inventory* curnode = player1_cards;
                    while (curnode != NULL) {
                        bounds = curnode->card_image.getGlobalBounds();
                        // check all cards in list
                        if (bounds.contains(mouse))
                        {
                            cout << "test" << endl;
                            break;
                            // mouse is on sprite!
                        }
                        curnode = curnode->next;
                    }
                    //std::cout << "the right button was pressed" << std::endl;
                    //std::cout << "mouse x: " << event.mouseButton.x << std::endl;
                    //std::cout << "mouse y: " << event.mouseButton.y << std::endl;
                    */
                }
            }



        }

        window.clear();
        //cout << "test" << endl;
        //Set_Card_Positions(player1_cards, empty_card_array);

        //DO DRAWINGS
        
        Draw_Card_Outlines(window, empty_card_array);
        Draw_Board(window, game_board);
        Draw_Cards(window, player1_cards, player2_cards);
        

        if (game_display_information == DISCARD_DISPLAY_SCREEN) {
        
        }
        else if (game_display_information == INFORMATION_DISPLAY_SCREEN) {
        
        }
        window.display();


    } //while loop: accept and echo back to client


    //close socket

    closesocket(clientSocket);

    //shutdown winsock
    WSACleanup();

}
