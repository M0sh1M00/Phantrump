// MADE BY OSCAR HOUSTON

#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <assert.h> 
#include <string>
#include <ws2tcpip.h>
#include <fcntl.h>
#include <fstream>


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

#define SCREENWIDTH 1350
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

#define ANIMATION_RUNNING 1
#define ANIMATION_NOT_RUNNING 0

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

    sf::Texture Ready_Button;
    sf::Texture Discard_Button;
    sf::Texture Show_Button;
    sf::Texture Inspect_Button;

    sf::Texture Power_Button;
    sf::Texture Defence_Button;
    sf::Texture Intelligence_Button;
    sf::Texture Freakiness_Button;
    sf::Texture Agility_Button;


    //buttons
    sf::Texture Ready_Lit;
    sf::Texture Ready_Unlit;

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

struct Animation_Screen {

    struct Inventory* player1_Card = NULL;
    struct Inventory* player2_Card = NULL;

    sf::RectangleShape player1_Card_image;
    sf::RectangleShape player2_Card_image;

    sf::RectangleShape background_image;
    sf::RectangleShape icon_image;

    sf::Text player1_text;
    sf::Text player2_text;

    int attacktype;

    //add fonts and other stuff here l8r



};

struct Game_Board {

    struct Inventory* player1_Ter = NULL;
    struct Inventory* player1_Amp = NULL;
    struct Inventory* player1_Aer = NULL;

    struct Inventory* player2_Ter = NULL;
    struct Inventory* player2_Amp = NULL;
    struct Inventory* player2_Aer = NULL;

    sf::RectangleShape player1_Ter_image;
    sf::RectangleShape player1_Amp_image;
    sf::RectangleShape player1_Aer_image;

    sf::RectangleShape ready_button_image;
    sf::RectangleShape discard_button_image;
    sf::RectangleShape inspect_button_image;
    sf::RectangleShape show_button_image;


    sf::RectangleShape power_button_image;
    sf::RectangleShape defence_button_image;
    sf::RectangleShape intelligence_button_image;
    sf::RectangleShape freakiness_button_image;
    sf::RectangleShape agility_button_image;

    int player1_Ter_image_x_coord;
    int player1_Amp_image_x_coord;
    int player1_Aer_image_x_coord;

    int player1_y_coord;
    int player2_y_coord;

    sf::RectangleShape player2_Ter_image;
    sf::RectangleShape player2_Amp_image;
    sf::RectangleShape player2_Aer_image;

    sf::RectangleShape board_image;
    sf::RectangleShape elements;

    sf::RectangleShape background;

    //sf::RectangleShape selecting_image; // when a card is click highlight possible board movements in yellow
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

    int element = TERRA;
    
    int display_type = 1; //1 is normal, 2 is enlarged (happens when mouse is over) and 3 is when the card is in play (skip over it in functions)

    int selected = FALSE;

    sf::RectangleShape card_image;

    int on_board = FALSE;

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

    if (!textures->Ready_Button.loadFromFile("Graphics/Buttons/Ready_Unlit.png")) { cout << "TEXTURE ERROR" << endl; }
    if (!textures->Discard_Button.loadFromFile("Graphics/Buttons/Discard_Unlit.png")) { cout << "TEXTURE ERROR" << endl; }
    if (!textures->Show_Button.loadFromFile("Graphics/Buttons/Show_Unlit.png")) { cout << "TEXTURE ERROR" << endl; }
    if (!textures->Inspect_Button.loadFromFile("Graphics/Buttons/Inspect_Unlit.png")) { cout << "TEXTURE ERROR" << endl; }

    if (!textures->Power_Button.loadFromFile("Graphics/Buttons/Power_Unlit.png")) { cout << "TEXTURE ERROR" << endl; }
    if (!textures->Defence_Button.loadFromFile("Graphics/Buttons/Defence_Unlit.png")) { cout << "TEXTURE ERROR" << endl; }
    if (!textures->Agility_Button.loadFromFile("Graphics/Buttons/Agility_Unlit.png")) { cout << "TEXTURE ERROR" << endl; }
    if (!textures->Freakiness_Button.loadFromFile("Graphics/Buttons/Freakiness_Unlit.png")) { cout << "TEXTURE ERROR" << endl; }
    if (!textures->Intelligence_Button.loadFromFile("Graphics/Buttons/Intelligence_Unlit.png")) { cout << "TEXTURE ERROR" << endl; }

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

    game_board->ready_button_image.setTexture(&textures->Ready_Button, true);
    game_board->discard_button_image.setTexture(&textures->Discard_Button, true);
    game_board->show_button_image.setTexture(&textures->Show_Button, true);
    game_board->inspect_button_image.setTexture(&textures->Inspect_Button, true);

    game_board->power_button_image.setTexture(&textures->Power_Button, true);
    game_board->defence_button_image.setTexture(&textures->Defence_Button, true);
    game_board->freakiness_button_image.setTexture(&textures->Freakiness_Button, true);
    game_board->intelligence_button_image.setTexture(&textures->Intelligence_Button, true);
    game_board->agility_button_image.setTexture(&textures->Agility_Button, true);

    game_board->board_image.setTexture(&textures->Board_Cards, true);
    game_board->elements.setTexture(&textures->Elements, true);
    game_board->background.setTexture(&textures->Background, true);
}
void Get_Card_Data_Two(struct Inventory* curnode, int card_num) {
    string file_path = "Card_Data/card.txt";
    int counter;
    file_path.insert(14, std::to_string(card_num));
    string line;

    ifstream myfile(file_path);
    if (myfile.is_open())
    {
        counter = 0;
        while (getline(myfile, line)) {
            cout << line << endl;
            if (counter == 0) {
                //name
            }
            if (counter == 1) {
                //element
                curnode->element = std::stoi(line);
            }
            if (counter == 2) {
                curnode->agility = std::stoi(line);
            }
            if (counter == 3) {
                curnode->intelligence = std::stoi(line);
            }
            if (counter == 4) {
                curnode->power = std::stoi(line);
            }
            if (counter == 5) {
                curnode->defence = std::stoi(line);
            }
            if (counter == 6) {
                curnode->freakiness = std::stoi(line);
            }
            counter++;
        }
        myfile.close();
    }
    else cout << "Unable to open file";

}
void Get_Card_Data(struct Inventory* player1_cards, struct Inventory* player2_cards, struct Inventory* card_pile) {
    
    struct Inventory* curnode = player1_cards;
    while (curnode != NULL) {
        Get_Card_Data_Two(curnode, curnode->card_num);
        curnode = curnode->next;
    }
    curnode = player2_cards;
    while (curnode != NULL) {
        Get_Card_Data_Two(curnode, curnode->card_num);
        curnode = curnode->next;
    }


}
void Setup_Animation(struct Animation_Screen* animation_screen) {
    //60% size from original
    int ypos = (SCREENHEIGHT - 731) / 2;

    sf::RectangleShape card(sf::Vector2f(522, 731));
    animation_screen->player1_Card_image = card;
    animation_screen->player2_Card_image = card;

    animation_screen->player1_Card_image.setPosition(ypos, ypos);
    animation_screen->player2_Card_image.setPosition(SCREENWIDTH- ypos -522, ypos);
    cout << "test" << endl;

}
void Setup_Buttons(struct Game_Board* game_board) {

    int new_height = (A2HEIGHT * 2) + (A2WIDTH / 2);//(A2HEIGHT * 3) + (A2HEIGHT / 2);
    int new_width = (A2WIDTH * 3) + (A2WIDTH / 2);
    printf("height: %d, width: %d\n", new_height, new_width);
    sf::RectangleShape button(sf::Vector2f(154, 50));
    int board_pos_x = (SCREENWIDTH / 2) - (new_width / 2);

    game_board->ready_button_image = button;
    game_board->discard_button_image = button;
    game_board->inspect_button_image = button;
    game_board->show_button_image = button;
    //154 is width of image
    game_board->ready_button_image.setPosition(20 + board_pos_x, new_height);
    game_board->discard_button_image.setPosition(20 + board_pos_x+((new_width/4)*1), new_height);
    game_board->inspect_button_image.setPosition(20 + board_pos_x + ((new_width / 4) * 2), new_height);
    game_board->show_button_image.setPosition(20 + board_pos_x + ((new_width / 4) * 3), new_height);

    sf::RectangleShape button2(sf::Vector2f(50, 50));

    game_board->power_button_image = button2;
    game_board->defence_button_image = button2;
    game_board->freakiness_button_image = button2;
    game_board->agility_button_image = button2;
    game_board->intelligence_button_image = button2;

    game_board->power_button_image.setPosition(40 + board_pos_x + ((new_width / 5) * 2), ((new_height/2) -25));
    game_board->defence_button_image.setPosition(40 + board_pos_x + ((new_width / 5) * 3), ((new_height / 2) - 25));
    game_board->freakiness_button_image.setPosition(40 + board_pos_x + ((new_width / 5) * 4), ((new_height / 2) - 25));
    game_board->agility_button_image.setPosition(40 + board_pos_x + ((new_width / 5) * 0), ((new_height / 2) - 25));
    game_board->intelligence_button_image.setPosition(40 + board_pos_x + ((new_width / 5) * 1), ((new_height / 2) - 25));
}

void Set_Board_Position(struct Game_Board* game_board) {

    int new_height = (A2HEIGHT * 2) + (A2WIDTH / 2);//(A2HEIGHT * 3) + (A2HEIGHT / 2);
    int new_width = (A2WIDTH * 3) + (A2WIDTH / 2);
    printf("height: %d, width: %d\n",new_height,new_width);
    sf::RectangleShape board(sf::Vector2f(new_width, new_height));
    int board_pos_x = (SCREENWIDTH / 2) - (new_width / 2);
    //board.setFillColor(sf::Color::Red);
    board.setPosition(board_pos_x, 0);
    game_board->board_image = board;
    game_board->elements = board;


    //REDO THIS SECTION IN A FUTURE UPDATE - MAKE IT NOT HARDCODED
    sf::RectangleShape card(sf::Vector2f(A2WIDTH, A2HEIGHT));
    card.setFillColor(sf::Color::Yellow);

    sf::RectangleShape card2(sf::Vector2f(A2WIDTH, A2HEIGHT));

    game_board->player1_Ter_image = card;
    game_board->player1_Amp_image = card;
    game_board->player1_Aer_image = card;

    game_board->player2_Ter_image = card2;
    game_board->player2_Amp_image = card2;
    game_board->player2_Aer_image = card2;

    game_board->player1_Ter_image_x_coord = board_pos_x + 21;
    game_board->player1_Amp_image_x_coord = board_pos_x + 21 + 34 + A2WIDTH;
    game_board->player1_Aer_image_x_coord = board_pos_x + 21 + (34 * 2) + (A2WIDTH * 2);

    //game_board->player2_Ter_image_x_coord = board_pos_x + 21;
    //game_board->player2_Amp_image_x_coord = board_pos_x + 21 + 34 + A2WIDTH;
    //game_board->player2_Aer_image_x_coord = board_pos_x + 21 + (34 * 2) + (A2WIDTH * 2);

    game_board->player1_y_coord = 16 + 79 + A2HEIGHT;
    game_board->player2_y_coord = 16;
    //game_board->player1_Amp_image_y_coord = 16 + 79 + A2HEIGHT;
    //game_board->player1_Aer_image_y_coord = 16 + 79 + A2HEIGHT;

    game_board->player1_Ter_image.setPosition(game_board->player1_Ter_image_x_coord, game_board->player1_y_coord);
    game_board->player1_Amp_image.setPosition(game_board->player1_Amp_image_x_coord, game_board->player1_y_coord);
    game_board->player1_Aer_image.setPosition(game_board->player1_Aer_image_x_coord, game_board->player1_y_coord);

    game_board->player2_Ter_image.setPosition(game_board->player1_Ter_image_x_coord, game_board->player2_y_coord);
    game_board->player2_Amp_image.setPosition(game_board->player1_Amp_image_x_coord, game_board->player2_y_coord);
    game_board->player2_Aer_image.setPosition(game_board->player1_Aer_image_x_coord, game_board->player2_y_coord);

    //game_board->player1_Ter_image.setPosition(board_pos_x + new_width /(21), new_height /16);

    sf::RectangleShape background(sf::Vector2f(SCREENWIDTH, SCREENHEIGHT));
    game_board->background = background;
}

void Set_Card_Positions(struct Inventory* player1_cards, struct Inventory* player2_cards) {
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
struct Inventory* Get_Enemy_Card_To_Attack(sf::RenderWindow& window, struct Game_Board* game_board) {
    sf::Vector2f mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));
    sf::FloatRect bounds;
    bounds = game_board->player2_Ter_image.getGlobalBounds();
    if (bounds.contains(mouse)) {
        return game_board->player2_Ter;
    }
    bounds = game_board->player2_Amp_image.getGlobalBounds();
    if (bounds.contains(mouse)) {
        return game_board->player2_Amp;
    }
    bounds = game_board->player2_Aer_image.getGlobalBounds();
    if (bounds.contains(mouse)) {
        return game_board->player2_Aer;
    }
    return NULL;
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
        //cout << selected_card->element << endl;
        //selected_card->card_image.setSize(sf::Vector2f(A2WIDTH * 1.2, A2HEIGHT * 1.2));
        return selected_card;
    }
    else {
        return NULL;
    }


}


void Transfer_Ply2_Cards_To_Board(uint32_t player2_array[3], struct Inventory* player2_cards, struct Game_Board* game_board) {
    struct Inventory* curnode = player2_cards;
    // Terra
    if(player2_array[0] != 0) {
        while (curnode != NULL) {
            //cout << curnode->card_num <<" <- card | compare against-> " << player2_array[0] << endl;
            if (curnode->card_num == player2_array[0]) {
                game_board->player2_Ter = curnode;
                cout << "SUCESS1" << endl;
            }
            curnode = curnode->next;
        }
    }
    else {
        game_board->player2_Ter = NULL;
    }
    curnode = player2_cards;
    if (player2_array[1] != 0) {
        while (curnode != NULL) {
            if (curnode->card_num == player2_array[1]) {
                game_board->player2_Amp = curnode;
                cout << "SUCESS2" << endl;
            }
            curnode = curnode->next;
        }
    }
    else {
        game_board->player2_Amp = NULL;
    }
    curnode = player2_cards;
    if (player2_array[2] != 0) {
        while (curnode != NULL) {
            if (curnode->card_num == player2_array[2]) {
                game_board->player2_Aer = curnode;
                cout << "SUCESS3" << endl;
            }
            curnode = curnode->next;
        }
    }
    else {
        game_board->player2_Aer = NULL;
    }

    return;



}



int Check_If_Card_Board_Available(sf::RenderWindow& window, struct Game_Board* game_board, struct Inventory* card_selected) {
    sf::Vector2f mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));
    sf::FloatRect bounds;
    bounds = game_board->player1_Ter_image.getGlobalBounds();
    if ((card_selected->element == TERRA || card_selected->element == INCOGNITO) && game_board->player1_Ter == NULL) {
        if (bounds.contains(mouse)) {return TRUE; }
    }
    bounds = game_board->player1_Amp_image.getGlobalBounds();
    if ((card_selected->element == AMPHIBIOUS || card_selected->element == INCOGNITO) && game_board->player1_Amp == NULL) {
        if (bounds.contains(mouse)) { return TRUE; }
    }
    bounds = game_board->player1_Aer_image.getGlobalBounds();
    if ((card_selected->element == AERIAL || card_selected->element == INCOGNITO) && game_board->player1_Aer == NULL) {
        if (bounds.contains(mouse)) { return TRUE; }
    }
    return FALSE;

}
struct Inventory* Put_Card_At_Back(struct Inventory* player1_cards, int card_number) {
    struct Inventory* curnode = player1_cards;
    struct Inventory* selected_card = NULL;
    if (curnode->next == NULL) {
        return player1_cards;
        //do nothing
    }
    /*if (curnode->card_num == card_number) {
        selected_card = curnode;
        player1_cards = selected_card->next;
    }*/
    while (curnode->next != NULL) {
        if (curnode->next->card_num == card_number) {
            selected_card = curnode->next;
            if (curnode->next->next != NULL) {
                curnode->next = curnode->next->next;
            }
        }
        curnode = curnode->next;
    }
    if (selected_card == NULL) {
        selected_card = player1_cards;
        struct Inventory* new_ll = player1_cards->next;
        curnode->next = selected_card;
        selected_card->next = NULL;
        return new_ll;
    }
    curnode->next = selected_card;
    selected_card->next = NULL;
    
    //Print_Linked_List(player1_cards);
    return player1_cards;
}

int Clicked_Empty_Pos(sf::RenderWindow& window, struct Game_Board* game_board) {

    sf::Vector2f mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));
    sf::FloatRect bounds;
    bounds = game_board->player2_Ter_image.getGlobalBounds();
    if (bounds.contains(mouse)) {
        return 1;
    }
    bounds = game_board->player2_Amp_image.getGlobalBounds();
    if (bounds.contains(mouse)) {
        return 1;
    }
    bounds = game_board->player2_Aer_image.getGlobalBounds();
    if (bounds.contains(mouse)) {
        return 1;
    }
    return 0;

}

int Find_Winner(struct Inventory* card_attacking, struct Inventory* card_attacked, int attack_type) {
    // 0: tie 1: player1 wins 2: player2 wins

    //agility

    if (attack_type == 1) {
        if (card_attacking->agility > card_attacked->agility) {
            return 1;
        }
        else if (card_attacking->agility < card_attacked->agility) {
            return 2;
        }
        return 0;
    }

    //add loser discard pile

}

void Set_New_Position(struct Inventory* player1_cards) {
    //reorganise LL so all on board cards are at the end
    // 
    //Setup xcoords and ycoords
    int buffer = 25; // empty space in top right corner
    int card_room = 60; // y distance between cards

    //sf::RectangleShape card(sf::Vector2f(A2WIDTH, A2HEIGHT));

    struct Inventory* curnode = player1_cards;
    int i = 0;
    while (curnode != NULL) {
        if (curnode->on_board == FALSE) {
            curnode->x_coord = buffer;
            curnode->y_coord = buffer + (card_room * i);
            //curnode->card_image = card;
            if (curnode->display_type == ENLARGED_DISPLAY) {
                curnode->card_image.setPosition((curnode->x_coord) - ((A2WIDTHHIGHLIGHTED - A2WIDTH) / 2), (curnode->y_coord) - ((A2HEIGHTHIGHLIGHTED - A2HEIGHT) / 2));
            }
            else {
                curnode->card_image.setPosition(curnode->x_coord, curnode->y_coord);
            }
        }
        curnode = curnode->next;
        i++;

    }

    //Print_Linked_List(player1_cards);
}
int Is_Card_Selected_On_Board(struct Game_Board* game_board, struct Inventory* selected_card) {
    if (game_board->player1_Ter == selected_card) {
        return 1;
    }
    if (game_board->player1_Amp == selected_card) {
        return 1;
    }
    if (game_board->player1_Aer == selected_card) {
        return 1;
    }



}
struct Inventory* Remove_From_Board(sf::RenderWindow& window, struct Game_Board* game_board, struct Inventory* player1_cards) {
    sf::Vector2f mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));

    struct Inventory* card_selected = NULL;

    if (game_board->player1_Ter_image.getGlobalBounds().contains(mouse)) {
        card_selected = game_board->player1_Ter;
        game_board->player1_Ter = NULL;
    }
    else if (game_board->player1_Amp_image.getGlobalBounds().contains(mouse)) {
        card_selected = game_board->player1_Amp;
        game_board->player1_Amp = NULL;
    }
    else if (game_board->player1_Aer_image.getGlobalBounds().contains(mouse)) {
        card_selected = game_board->player1_Aer;
        game_board->player1_Aer = NULL;
    }

    if (card_selected != NULL) {
        int card_number = card_selected->card_num;
        card_selected->on_board = FALSE;
        if (player1_cards->on_board == TRUE) {
            //if first card is on board

        }
        else {
            //there are cards that are not on the board

            //remove instance of card_selected
            struct Inventory* curnode = player1_cards;
            struct Inventory* prevnode = player1_cards;

            if (curnode->next == NULL) {
                //if there is only 1 card
                return player1_cards;
            }
            /*
            if (curnode->next->next == NULL) {
                //if there are only 2 cards REDO THIS
                if (player1_cards->on_board == TRUE) {
                    if (player1_cards->card_num == card_number) {
                        return player1_cards;
                    }
                    else {
                        card_selected->next = player1_cards;
                        card_selected->next->next = NULL;
                        return card_selected;
                    }
                }
                return player1_cards;
            }
            */
            //remove the card from the list
            /*
            cout << "test1" << endl;
            while (curnode->next->next != NULL) {

                if (curnode->next->card_num == card_number) {
                    curnode->next = curnode->next->next;
                    if (curnode->next->next == NULL) { break; }
                }
                curnode = curnode->next;

            }
            cout << "test2" << endl;
            */

            // If head node itself holds the key to be deleted 
            if (curnode != NULL && curnode->card_num == card_number)
            {
                return curnode;
            }

            // Search for the key to be deleted, keep track of the 
            // previous node as we need to change 'prev->next' 
            while (curnode != NULL && curnode->card_num != card_number)
            {
                prevnode = curnode;
                curnode = curnode->next;
            }
            prevnode->next = curnode->next;

            /*
            if (curnode->next->card_num == card_number) {
                curnode->next = curnode->next->next;

            }
            */

            //ADD MORE EDGE CASES ABOVE
            curnode = player1_cards;
            while (curnode != NULL) {
                if (curnode->on_board == TRUE) {
                    //cout << "!!!!!!!!!!!!!!!!!" << endl;
                    Print_Linked_List(player1_cards);
                    //struct Inventory* tempnode = curnode->next;
                    prevnode->next = card_selected;
                    card_selected->next = curnode;
                    //card_selected->next = player1_cards;
                    return player1_cards;



                }
                prevnode = curnode;
                curnode = curnode->next;
            }
            prevnode->next = card_selected;
            card_selected->next = curnode;

        }

    }
    return player1_cards;

}
void Set_Card_To_Board(sf::RenderWindow& window, struct Game_Board* game_board, struct Inventory* card_selected) {

    sf::Vector2f mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));

    if (game_board->player1_Ter_image.getGlobalBounds().contains(mouse)) {
        game_board->player1_Ter = card_selected;


        card_selected->x_coord = game_board->player1_Ter_image_x_coord;
        card_selected->y_coord = game_board->player1_y_coord;
        
        card_selected->card_image.setPosition(card_selected->x_coord, card_selected->y_coord);
    }
    else if (game_board->player1_Amp_image.getGlobalBounds().contains(mouse)) {
        game_board->player1_Amp = card_selected;


        card_selected->x_coord = game_board->player1_Amp_image_x_coord;
        card_selected->y_coord = game_board->player1_y_coord;

        card_selected->card_image.setPosition(card_selected->x_coord, card_selected->y_coord);
    }
    else if (game_board->player1_Aer_image.getGlobalBounds().contains(mouse)) {
        game_board->player1_Aer = card_selected;


        card_selected->x_coord = game_board->player1_Aer_image_x_coord;
        card_selected->y_coord = game_board->player1_y_coord;

        card_selected->card_image.setPosition(card_selected->x_coord, card_selected->y_coord);
    }

    //reorg player1 cards


}

void Draw_Card_Outlines(sf::RenderWindow &window, struct EmptyCard empty_card_array[16]) {
    for (int i = 0; i != 16; i++) {
        window.draw(empty_card_array[i].card_graphics);
    }
}
void Draw_Selected_Board(sf::RenderWindow& window, struct Game_Board* game_board, struct Inventory* card_selected) {
    if (card_selected->element == TERRA || card_selected->element == INCOGNITO) {
        window.draw(game_board->player1_Ter_image);
    }
    if (card_selected->element == AMPHIBIOUS || card_selected->element == INCOGNITO) {
        window.draw(game_board->player1_Amp_image);
    }
    if (card_selected->element == AERIAL || card_selected->element == INCOGNITO) {
        window.draw(game_board->player1_Aer_image);
    }


}
void Draw_Board(sf::RenderWindow& window, struct Game_Board* game_board, struct Inventory * card_selected) {
    window.draw(game_board->background);
    window.draw(game_board->board_image);
    //add selector here
    if (card_selected != NULL) {
        Draw_Selected_Board(window, game_board, card_selected);

    }

    window.draw(game_board->elements);
    

    window.draw(game_board->player2_Ter_image);
    window.draw(game_board->player2_Amp_image);
    window.draw(game_board->player2_Aer_image);


    window.draw(game_board->ready_button_image);
    window.draw(game_board->show_button_image);
    window.draw(game_board->discard_button_image);
    window.draw(game_board->inspect_button_image);

    window.draw(game_board->power_button_image);
    window.draw(game_board->defence_button_image);
    window.draw(game_board->agility_button_image);
    window.draw(game_board->freakiness_button_image);
    window.draw(game_board->intelligence_button_image);
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
    struct Inventory* discard_pile = NULL;// new struct Inventory; //(struct Inventory*)malloc(sizeof(struct Inventory));
    struct Inventory* card_pile = new struct Inventory;//(struct Inventory*)malloc(sizeof(struct Inventory));

    //discard_pile = NULL;

    //int game_board_array[2][3] = { 0 }; //This is for sending to client/server NOT for the gamelogic
    int gamestate = CARD_PLACING;
    uint32_t  initial_game_data[STARTINGCARDS];
    //struct Inventory* game_board_linked_list[2][3] = { NULL };
    //int both_players_ready = FALSE;
    int player_1_ready = FALSE;
    int player_2_ready = FALSE;
    int game_display_information = NORMAL_DISPLAY_SCREEN;
    int attack_type = 0;
    struct Inventory* card_to_attack = NULL;
    int winner;
    int animation_status = ANIMATION_NOT_RUNNING;

    struct Inventory* card_selected = NULL;
    struct EmptyCard empty_card_array[16];
    struct Texture_Struct *textures = new struct Texture_Struct;
    struct Animation_Screen* animation_screen = new struct Animation_Screen;

    //TEMPORARY


    

    //TEMPORARY


    struct Game_Board* game_board = new struct Game_Board;//(struct Inventory*)malloc(sizeof(struct Inventory));

    //Game Logic Functions
    Get_Card_Bank(card_bank);
    Starting_Cards(card_bank, player1_cards, player2_cards, card_pile);
    Create_Card_Graphics(empty_card_array);
    Print_Linked_List(player1_cards);
    Set_Card_Positions(player1_cards, player2_cards);
    Set_Board_Position(game_board);
    Setup_Animation(animation_screen);
    Setup_Buttons(game_board);

    Initialise_Graphics(textures, player1_cards, player2_cards, card_pile, game_board);
    Get_Card_Data(player1_cards, player2_cards, card_pile);

    animation_screen->player1_Card_image.setTexture(&textures->L_Vriska_1, true);
    animation_screen->player2_Card_image.setTexture(&textures->L_Vriska_1, true);

    //Setup Game Window
    //sf::RenderWindow window(sf::VideoMode(SCREENWIDTH, SCREENHEIGHT), "Phantrumps", sf::Style::Titlebar | sf::Style::Close);
    
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    //sf::RenderWindow window(sf::VideoMode(800, 600), "SFML shapes", sf::Style::Default, settings);
    sf::RenderWindow window(sf::VideoMode(SCREENWIDTH, SCREENHEIGHT), "Phantrumps - Host");
    window.setFramerateLimit(60);
    sf::View view = window.getDefaultView();
    //sf::RenderWindow window(sf::VideoMode(SCREENWIDTH, SCREENHEIGHT), "Phantrumps", sf::Style::Fullscreen);
    struct Inventory* curnode = player2_cards;
    for (int i = 0; curnode != NULL; i++) {
        initial_game_data[i] = curnode->card_num;
        cout << "Ply2 card: " << initial_game_data[i] << " i: " << i << endl;
        curnode = curnode->next;
    }
    //uint32_t  conv_initial_game_data[STARTINGCARDS];
    //for (int i = 0; i!= STARTINGCARDS; i++) {
    //    conv_initial_game_data[i] = htonl(initial_game_data[i]);
    //}
    send(clientSocket, (char*)initial_game_data, STARTINGCARDS*sizeof(uint32_t), 0);

    //send(clientSocket, (char*)initial_game_data, BYTESOFGAMEDATA + 1, 0);

    int ret;
    int turn_type = 0;

    //Game Loop
    while (window.isOpen())
    {


        if (gamestate == CARD_PLACING) {
            
            //else {
            
                //stuff player 1 does when they arnt ready - check if ready button is clicked so can send info to player 2
            
            //}
            if (player_2_ready == FALSE) {
                struct timeval timeout;
                timeout.tv_sec = 0;
                timeout.tv_usec = 0;
                fd_set rds;
                FD_ZERO(&rds);
                FD_SET(clientSocket, &rds);
                ret = select(clientSocket + 1, &rds, NULL, NULL, &timeout);
                if (FD_ISSET(clientSocket, &rds)) {
                    uint32_t player2_array[3];
                    ZeroMemory((char*)player2_array, 3*sizeof(uint32_t));
                    int bytesReceived = recv(clientSocket, (char*)player2_array, 3*sizeof(uint32_t), 0);
                    if (bytesReceived == SOCKET_ERROR) { cerr << "Client quit program or Socket error occured, quitting program " << endl; break; }
                    if (bytesReceived == 0) { cout << "client disconnected " << endl; break; }
                    player_2_ready = TRUE;
                    //Sending Data
                    //i dont think i need to send anything tbh

                    //buf should be [card1, card2, card3] on player2s board
                    cout << player2_array[0] << endl;
                    cout << player2_array[1] << endl;
                    cout << player2_array[2] << endl;

                    Transfer_Ply2_Cards_To_Board(player2_array, player2_cards, game_board);
                    //cout << "TEST213" << endl;
                    //if (game_board->player2_Ter == NULL) { cout << "bruh" << endl; }
                    //cout << game_board->player2_Ter->card_num << endl;
                    //cout << game_board->player2_Amp->card_num << endl;
                    //cout << game_board->player2_Aer->card_num << endl;
                }
                else if (ret == -1) {
                    cout << "ret is -1 ERROR\n" << endl;
                    WSACleanup();
                    closesocket(clientSocket);
                }
                //listen for socket then say player 2 is ready
            }
            if (player_1_ready == TRUE && player_2_ready == TRUE) {
                uint32_t tell_player2_next_move[1]; // if 1 its player2 attacking, if 2 its player1 attking
                if (turn_type == 0) {
                    gamestate = PLAYER_1_ATK;
                    tell_player2_next_move[0] = 0;
                   
                }
                else if (turn_type == 1) {
                    gamestate = PLAYER_2_ATK;
                    tell_player2_next_move[0] = 1;

                }
                player_1_ready = FALSE;
                player_2_ready = FALSE;

                

                send(clientSocket, (char*)tell_player2_next_move, 1 * sizeof(uint32_t), 0);
                cout << "FINISHED CARD PLACING PHASE " << endl;
            }

        
        }
        if (gamestate == PLAYER_1_ATK) {
            //do shit then send socket data
            /*
            if (turn_type == 0) {
                gamestate = PLAYER_2_ATK;
            }
            else if (turn_type == 1) {
                turn_type = 0;
                gamestate = CARD_PLACING;
            }
            */
        }
        if (gamestate == PLAYER_2_ATK+3) {
            //wait for recieved socket data

            if (player_2_ready == FALSE) {
                struct timeval timeout;
                timeout.tv_sec = 0;
                timeout.tv_usec = 0;
                fd_set rds;
                FD_ZERO(&rds);
                FD_SET(clientSocket, &rds);
                ret = select(clientSocket + 1, &rds, NULL, NULL, &timeout);
                if (FD_ISSET(clientSocket, &rds)) {
                    uint32_t player2_array[3];
                    ZeroMemory((char*)player2_array, 3 * sizeof(uint32_t));
                    int bytesReceived = recv(clientSocket, (char*)player2_array, 3 * sizeof(uint32_t), 0);
                    if (bytesReceived == SOCKET_ERROR) { cerr << "Client quit program or Socket error occured, quitting program " << endl; break; }
                    if (bytesReceived == 0) { cout << "client disconnected " << endl; break; }

                    player_2_ready = TRUE;
                    //Sending Data
                    //i dont think i need to send anything tbh

                    //buf should be [card lane doing attacking with, card lane attacking, attack type]

                    //after done
                    if (turn_type == 1) {

                        //send back player2 board plus known player 1 board: e.g. [4, 23, 3, 0, 1, 0]

                        gamestate = PLAYER_1_ATK;
                    }
                    else if (turn_type == 0) {
                        turn_type = 1;

                        //send player2 board plus discard pile - needs to be 28 big, card val is 0 if there is no card in discard

                        gamestate = CARD_PLACING;
                    }

                }
                else if (ret == -1) {
                    cout << "ret is -1 ERROR\n" << endl;
                    WSACleanup();
                    closesocket(clientSocket);
                }
                //listen for socket then say player 2 is ready
            }

        }




        //win check

        if (player1_cards == NULL) {
            //do something        
        }
        else if (player2_cards == NULL) {
            //do something else
        }


        /*
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
            //send(clientSocket, (char*)game_data, BYTESOFGAMEDATA+ 1, 0);
        }
        else if(ret == -1) {
            cout << "ret is -1 ERROR\n" << endl;
            WSACleanup();
            closesocket(clientSocket);
        }
        */
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
            else if (event.type == sf::Event::Resized) {
                // resize my view
                view.setSize({
                        static_cast<float>(event.size.width),
                        static_cast<float>(event.size.height)
                    });
                window.setView(view);
                // and align shape
            }
            else if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Right) {
                    if (player_1_ready == FALSE) {
                        Remove_From_Board(window, game_board, player1_cards);
                        Set_New_Position(player1_cards);
                    }

                }
                else if (event.mouseButton.button == sf::Mouse::Left)
                {
                    //attack_type = 0;
                    //clicking buttons
                    sf::Vector2f mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                    sf::FloatRect bounds;

                    bounds = game_board->ready_button_image.getGlobalBounds();
                    if (bounds.contains(mouse)) {
                        if (gamestate = CARD_PLACING && player_1_ready == FALSE) {
                            player_1_ready = TRUE;
                        }
                    }

                    if (gamestate == PLAYER_1_ATK) {
                        
                        if (card_selected != NULL) {
                            if (Is_Card_Selected_On_Board(game_board, card_selected) == TRUE) {
                                if (attack_type == 0) {
                                    attack_type = 1; // Attack_Type_Clicked();//set 0 normally, set back to 0 after round has ended or a new card has been s
                                }
                            }



                        }
                        if (attack_type != 0) {
                            cout << "donelol1" << endl;
                            card_to_attack = Get_Enemy_Card_To_Attack(window, game_board);
                            cout << "donelol2" << endl;
                            //cout << card_to_attack->card_num << endl;
                            //card_to_attack num is element
                            if(card_to_attack != NULL){

                                // 0: tie 1: player1 wins 2: player2 wins
                                //cout << "donelol3" << endl;
                                winner = Find_Winner(card_selected, card_to_attack, attack_type);
                                //cout << "donelol4" << endl;
                                //fill_animation_data(winner);
                                animation_status = ANIMATION_RUNNING;
                                //send(array with)
                                attack_type = 0;
                                cout << "donelol" << endl;
                            }
                            else if (card_to_attack == NULL && Clicked_Empty_Pos()) {
                            
                                winner = 2;
                                animation_status = ANIMATION_RUNNING;
                            
                            }

                                //[player2_card_attacked, player1_card_attacking, attack_type]

                                //[enemy card1,card2,card3, 0,0,0] 0's if card is not known, 1's if it is known
                        }
                        
                    }

                    //moving cards to board
                    if (player_1_ready == FALSE && gamestate == CARD_PLACING) {
                        if (card_selected != NULL) {
                            if (Check_If_Card_Board_Available(window,game_board, card_selected) == TRUE) {
                                Set_Card_To_Board(window, game_board, card_selected);
                                player1_cards = Put_Card_At_Back(player1_cards, card_selected->card_num);
                                card_selected->on_board = TRUE;
                                //card_selected = NULL;
                                Set_New_Position(player1_cards);
                                
                            }
                        }
                    }
                    //cout << "sucess2!" << endl;
                    if (attack_type == 0) {
                        card_selected = Get_Selected_Card(window, player1_cards, textures);
                    }
                    //cout << "sucess3!" << endl;
                }
            }
        }
        window.clear();

        //DO DRAWINGS
        
        //Draw_Card_Outlines(window, empty_card_array);
        Draw_Board(window, game_board, card_selected);
        Draw_Cards(window, player1_cards, player2_cards);
        if (animation_status == ANIMATION_RUNNING) {
            window.draw(animation_screen->player1_Card_image);
            window.draw(animation_screen->player2_Card_image);
        }
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
