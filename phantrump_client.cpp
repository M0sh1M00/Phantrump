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

#define STARTINGCARDS 5
#define MAXCARDS 8

#define TRUE 1
#define FALSE 0

#define SCREENWIDTH 1350
#define SCREENHEIGHT 800

#define A2WIDTH 220//238 //140*1.7//84//140   25.25% is PS
#define A2HEIGHT 308//336 //198*1.7//109//198   25.25%

#define A2WIDTHHIGHLIGHTED 241    // 27.75% IN PS
#define A2HEIGHTHIGHLIGHTED 338   // 27.75%

#define LARGECARDWIDTH 398
#define LARGECARDHEIGHT 557

#define ICONSIZE 50

#define BYTESOFGAMEDATA 6

//gamestates
#define CARD_PLACING 1
#define PLAYER_1_ATK 2
#define PLAYER_2_ATK 3
#define PLAYER_1_WON 4
#define PLAYER_2_WON 5

#define SHOWBATTLE 1
#define SHOWONECARD 2
#define SHOWDISCARD 3
#define SHOWALLCARD 4
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

    sf::Texture Win_Screen;
    sf::Texture Lose_Screen;

    sf::Texture S_Card_Backside;

    sf::Texture Ready_Button_Lit;
    sf::Texture Discard_Button_Lit;
    sf::Texture Show_Button_Lit;
    sf::Texture Inspect_Button_Lit;
    sf::Texture Ready_Button_Unlit;
    sf::Texture Discard_Button_Unlit;
    sf::Texture Show_Button_Unlit;
    sf::Texture Inspect_Button_Unlit;

    sf::Texture Power_Button;
    sf::Texture Defence_Button;
    sf::Texture Intelligence_Button;
    sf::Texture Freakiness_Button;
    sf::Texture Agility_Button;

    sf::Texture Power_ButtonL;
    sf::Texture Defence_ButtonL;
    sf::Texture Intelligence_ButtonL;
    sf::Texture Freakiness_ButtonL;
    sf::Texture Agility_ButtonL;

    sf::Texture Animation_Screen;

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

    sf::Texture L_Terra;
    sf::Texture L_Amphibious;
    sf::Texture L_Aerial;
    sf::Texture L_Incognito;

};


struct Animation_Screen {

    struct Inventory* player1_Card = NULL;
    struct Inventory* player2_Card = NULL;

    sf::RectangleShape player1_Card_image;
    sf::RectangleShape player2_Card_image;

    sf::RectangleShape background_image;
    sf::RectangleShape icon_image;

    sf::Font font;

    sf::Text player1_text;
    sf::Text player2_text;

    sf::Text icon_text;

    sf::RectangleShape player1_colour;
    sf::RectangleShape player2_colour;

    int attacktype;

    int empty_element;

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

    uint32_t player1_Ter_image_x_coord;
    uint32_t player1_Amp_image_x_coord;
    uint32_t player1_Aer_image_x_coord;

    sf::RectangleShape ready_button_image;
    sf::RectangleShape discard_button_image;
    sf::RectangleShape inspect_button_image;
    sf::RectangleShape show_button_image;

    sf::RectangleShape power_button_image;
    sf::RectangleShape defence_button_image;
    sf::RectangleShape intelligence_button_image;
    sf::RectangleShape freakiness_button_image;
    sf::RectangleShape agility_button_image;

    uint32_t player1_y_coord;
    uint32_t player2_y_coord;

    sf::RectangleShape player2_Ter_image;
    sf::RectangleShape player2_Amp_image;
    sf::RectangleShape player2_Aer_image;

    sf::RectangleShape board_image;
    sf::RectangleShape elements;

    sf::RectangleShape background;

    int turn_count;

    sf::Font font;
    sf::Text current_phase;
    sf::Text turn_count_string;
    //sf::RectangleShape selecting_image; // when a card is click highlight possible board movements in yellow

    sf::RectangleShape win_screen;
    sf::RectangleShape lose_screen;

};
struct Empty_Card {

    uint32_t x_coord = 0;
    uint32_t y_coord = 0;

    sf::RectangleShape card_image;
    struct Empty_Card* next;

};

struct Inventory {

    uint32_t card_num;

    uint32_t x_coord = 0;
    uint32_t y_coord = 0;

    uint32_t power = 0;
    uint32_t agility = 0;
    uint32_t defence = 0;
    uint32_t freakiness = 0;
    uint32_t intelligence = 0;

    uint32_t element = TERRA;

    uint32_t display_type = 1; //1 is normal, 2 is enlarged (happens when mouse is over) and 3 is when the card is in play (skip over it in functions)

    uint32_t selected = FALSE;

    sf::RectangleShape card_image;

    string card_name;

    uint32_t on_board = FALSE;

    //sf::RectangleShape card_graphics; ADD ACTUAL GRAPHICS HERE

    struct Inventory* next;
};
struct Card_Backside {

    sf::RectangleShape card_image;

};
struct EmptyCard {

    int x_coord;
    int y_coord;

    sf::RectangleShape card_graphics;
};

void Switch_Highlighted_Image(struct Texture_Struct* textures, struct Inventory* selected_card, int highlighted) {
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
    else {
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
    cout << "ERROR SHOULD NOT REACH END OF HIGHLIGHT SWITCH FUNCTION" << selected_card->card_num << endl;
    return;



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
        while (iterater != counter + 1) {
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
void Starting_Cards(uint32_t player2_cards_array[STARTINGCARDS], struct Empty_Card* player1_cards, struct Inventory* player2_cards) {

    /* Organises both players cards and the total card bank into linked lists */
    //Print_Array(card_bank, CARDBANKSIZE);
    sf::RectangleShape card(sf::Vector2f(A2WIDTH, A2HEIGHT));
    //card.setFillColor(sf::Color::Red);

    int counter = 0;

    //player1_cards->card_num = card_bank[counter];
    player1_cards->next = NULL;

    player1_cards->card_image = card; //= card(sf::Vector2f(A2WIDTH, A2HEIGHT));


    player1_cards->card_image.setPosition(0, 0);

    counter++;
    while (counter != STARTINGCARDS) {

        struct Empty_Card* new_card = new struct Empty_Card;//(struct Inventory*)malloc(sizeof(struct Inventory));
        new_card->next = NULL;
        //new_card->card_num = card_bank[counter];

        struct Empty_Card* cur_node = player1_cards;

        while (cur_node->next != NULL) {
            cur_node = cur_node->next;
        }
        cur_node->next = new_card;

        counter++;
    }
    //Print_Linked_List(player1_cards);
    counter = 0;
    player2_cards->card_num = player2_cards_array[counter];
    player2_cards->next = NULL;
    counter++;
    while (counter != (STARTINGCARDS)) {

        struct Inventory* new_card = new struct Inventory;//(struct Inventory*)malloc(sizeof(struct Inventory));
        new_card->next = NULL;
        new_card->card_num = player2_cards_array[counter];

        struct Inventory* cur_node = player2_cards;

        while (cur_node->next != NULL) {
            cur_node = cur_node->next;
        }
        cur_node->next = new_card;

        counter++;
    }
    //Print_Linked_List(player2_cards);

}

void Create_Card_Graphics(struct EmptyCard empty_card_array[16]) {
    //0 - 7 are top, 8-15 are bottom    
    sf::RectangleShape card(sf::Vector2f(A2WIDTH, A2HEIGHT));
    card.setFillColor(sf::Color::Green);

    int card_buffer = (SCREENWIDTH - (7 * 1.2 * ((SCREENWIDTH - (SCREENWIDTH / 6)) / 8)) - A2WIDTH) / 2;
    for (int i = 0; i != 8; i++) {
        struct EmptyCard NewCard;

        NewCard.x_coord = card_buffer + (i * 1.2 * ((SCREENWIDTH - (SCREENWIDTH / 6)) / 8));
        NewCard.y_coord = card_buffer;//+ (1.18 * ((SCREENWIDTH - (SCREENWIDTH / 6)) / 8));
        NewCard.card_graphics = card;
        NewCard.card_graphics.setPosition(NewCard.x_coord, NewCard.y_coord);

        empty_card_array[i] = NewCard;
    }
    for (int i = 0; i != 8; i++) {
        struct EmptyCard NewCard;

        NewCard.x_coord = card_buffer + (i * 1.2 * ((SCREENWIDTH - (SCREENWIDTH / 6)) / 8));
        NewCard.y_coord = SCREENHEIGHT - card_buffer - (A2HEIGHT);
        NewCard.card_graphics = card;
        NewCard.card_graphics.setPosition(NewCard.x_coord, NewCard.y_coord);

        empty_card_array[i + 8] = NewCard;
    }

}
void Initialise_Graphics(struct Texture_Struct* textures, struct Inventory* player1_cards, struct Game_Board* game_board) {

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


    if (!textures->L_Terra.loadFromFile("Graphics/Cards/Large/L_Terra.png")) { cout << "TEXTURE ERROR" << endl; }
    if (!textures->L_Amphibious.loadFromFile("Graphics/Cards/Large/L_Amphibious.png")) { cout << "TEXTURE ERROR" << endl; }
    if (!textures->L_Aerial.loadFromFile("Graphics/Cards/Large/L_Aerial.png")) { cout << "TEXTURE ERROR" << endl; }
    if (!textures->L_Incognito.loadFromFile("Graphics/Cards/Large/L_Incognito.png")) { cout << "TEXTURE ERROR" << endl; }


    if (!textures->S_Card_Backside.loadFromFile("Graphics/Cards/Small/TopTrumpBackside.png")) { cout << "TEXTURE ERROR" << endl; }

    //Board and background
    if (!textures->Board_Cards.loadFromFile("Graphics/Board/Game_Board_Cards.png")) { cout << "TEXTURE ERROR" << endl; }
    if (!textures->Elements.loadFromFile("Graphics/Board/Elements.png")) { cout << "TEXTURE ERROR" << endl; }
    if (!textures->Background.loadFromFile("Graphics/Board/Background.png")) { cout << "TEXTURE ERROR" << endl; }
    if (!textures->Animation_Screen.loadFromFile("Graphics/Board/Animation_Screen.png")) { cout << "TEXTURE ERROR" << endl; }

    if (!textures->Win_Screen.loadFromFile("Graphics/Board/Win_Screen.png")) { cout << "TEXTURE ERROR" << endl; }
    if (!textures->Lose_Screen.loadFromFile("Graphics/Board/Lose_Screen.png")) { cout << "TEXTURE ERROR" << endl; }

    if (!textures->Ready_Button_Unlit.loadFromFile("Graphics/Buttons/Ready_Unlit.png")) { cout << "TEXTURE ERROR" << endl; }
    if (!textures->Discard_Button_Unlit.loadFromFile("Graphics/Buttons/Discard_Unlit.png")) { cout << "TEXTURE ERROR" << endl; }
    if (!textures->Show_Button_Unlit.loadFromFile("Graphics/Buttons/Show_Unlit.png")) { cout << "TEXTURE ERROR" << endl; }
    if (!textures->Inspect_Button_Unlit.loadFromFile("Graphics/Buttons/Inspect_Unlit.png")) { cout << "TEXTURE ERROR" << endl; }

    if (!textures->Ready_Button_Lit.loadFromFile("Graphics/Buttons/Ready_Lit.png")) { cout << "TEXTURE ERROR" << endl; }
    if (!textures->Discard_Button_Lit.loadFromFile("Graphics/Buttons/Discard_Lit.png")) { cout << "TEXTURE ERROR" << endl; }
    if (!textures->Show_Button_Lit.loadFromFile("Graphics/Buttons/Show_Lit.png")) { cout << "TEXTURE ERROR" << endl; }
    if (!textures->Inspect_Button_Lit.loadFromFile("Graphics/Buttons/Inspect_Lit.png")) { cout << "TEXTURE ERROR" << endl; }

    if (!textures->Power_Button.loadFromFile("Graphics/Buttons/Power_Unlit.png")) { cout << "TEXTURE ERROR" << endl; }
    if (!textures->Defence_Button.loadFromFile("Graphics/Buttons/Defence_Unlit.png")) { cout << "TEXTURE ERROR" << endl; }
    if (!textures->Agility_Button.loadFromFile("Graphics/Buttons/Agility_Unlit.png")) { cout << "TEXTURE ERROR" << endl; }
    if (!textures->Freakiness_Button.loadFromFile("Graphics/Buttons/Freakiness_Unlit.png")) { cout << "TEXTURE ERROR" << endl; }
    if (!textures->Intelligence_Button.loadFromFile("Graphics/Buttons/Intelligence_Unlit.png")) { cout << "TEXTURE ERROR" << endl; }

    if (!textures->Power_ButtonL.loadFromFile("Graphics/Buttons/Power_Lit.png")) { cout << "TEXTURE ERROR" << endl; }
    if (!textures->Defence_ButtonL.loadFromFile("Graphics/Buttons/Defence_Lit.png")) { cout << "TEXTURE ERROR" << endl; }
    if (!textures->Agility_ButtonL.loadFromFile("Graphics/Buttons/Agility_Lit.png")) { cout << "TEXTURE ERROR" << endl; }
    if (!textures->Freakiness_ButtonL.loadFromFile("Graphics/Buttons/Freakiness_Lit.png")) { cout << "TEXTURE ERROR" << endl; }
    if (!textures->Intelligence_ButtonL.loadFromFile("Graphics/Buttons/Intelligence_Lit.png")) { cout << "TEXTURE ERROR" << endl; }


    struct Inventory* curnode = player1_cards;
    while (curnode != NULL) {
        //curnode->card_image.setTexture(&textures->S_Sledstac_16, true);
        Switch_Highlighted_Image(textures, curnode, TRUE);
        curnode = curnode->next;
    }

    game_board->ready_button_image.setTexture(&textures->Ready_Button_Unlit, true);
    game_board->discard_button_image.setTexture(&textures->Discard_Button_Unlit, true);
    game_board->show_button_image.setTexture(&textures->Show_Button_Unlit, true);
    game_board->inspect_button_image.setTexture(&textures->Inspect_Button_Unlit, true);

    game_board->power_button_image.setTexture(&textures->Power_Button, true);
    game_board->defence_button_image.setTexture(&textures->Defence_Button, true);
    game_board->freakiness_button_image.setTexture(&textures->Freakiness_Button, true);
    game_board->intelligence_button_image.setTexture(&textures->Intelligence_Button, true);
    game_board->agility_button_image.setTexture(&textures->Agility_Button, true);

    game_board->board_image.setTexture(&textures->Board_Cards, true);
    game_board->elements.setTexture(&textures->Elements, true);
    game_board->background.setTexture(&textures->Background, true);

    game_board->win_screen.setTexture(&textures->Win_Screen, true);
    game_board->lose_screen.setTexture(&textures->Lose_Screen, true);

}

void Set_Animation_Graphics(struct Texture_Struct* textures, struct Animation_Screen* animation_screen, int empty_element, int opposing_element) {
    if (empty_element != 4) {
        animation_screen->empty_element = empty_element;
        //opposing_element = empty_element;
    }

    int player1_card;
    int player2_card;
    if (animation_screen->player1_Card == NULL) {
        player1_card = 0;
    }
    else {
        player1_card = animation_screen->player1_Card->card_num;
    }

    if (animation_screen->player2_Card == NULL) {
        player2_card = 0;
    }
    else {
        player2_card = 0;//animation_screen->player2_Card->card_num;
    }
    if (player1_card == 1)animation_screen->player1_Card_image.setTexture(&textures->L_Vriska_1, true);
    else if (player1_card == 2)animation_screen->player1_Card_image.setTexture(&textures->L_Phantom_2, true);
    else if (player1_card == 3)animation_screen->player1_Card_image.setTexture(&textures->L_Kanelf_3, true);
    else if (player1_card == 4)animation_screen->player1_Card_image.setTexture(&textures->L_Gaxx_4, true);
    else if (player1_card == 5)animation_screen->player1_Card_image.setTexture(&textures->L_Shellbow_5, true);
    else if (player1_card == 6)animation_screen->player1_Card_image.setTexture(&textures->L_Marshan_6, true);
    else if (player1_card == 7)animation_screen->player1_Card_image.setTexture(&textures->L_Traria_7, true);
    else if (player1_card == 8)animation_screen->player1_Card_image.setTexture(&textures->L_Raorm_8, true);
    else if (player1_card == 9)animation_screen->player1_Card_image.setTexture(&textures->L_Krei_9, true);
    else if (player1_card == 10)animation_screen->player1_Card_image.setTexture(&textures->L_Sponk_10, true);
    else if (player1_card == 11)animation_screen->player1_Card_image.setTexture(&textures->L_Spurtle_11, true);
    else if (player1_card == 12)animation_screen->player1_Card_image.setTexture(&textures->L_Mosbie_12, true);
    else if (player1_card == 13)animation_screen->player1_Card_image.setTexture(&textures->L_Qiggly_13, true);
    else if (player1_card == 14)animation_screen->player1_Card_image.setTexture(&textures->L_Lani_14, true);
    else if (player1_card == 15)animation_screen->player1_Card_image.setTexture(&textures->L_Blatoud_15, true);
    else if (player1_card == 16)animation_screen->player1_Card_image.setTexture(&textures->L_Sledstac_16, true);
    else if (player1_card == 17)animation_screen->player1_Card_image.setTexture(&textures->L_Gunin_17, true);
    else if (player1_card == 18)animation_screen->player1_Card_image.setTexture(&textures->L_Dotal_18, true);
    else if (player1_card == 19)animation_screen->player1_Card_image.setTexture(&textures->L_Spakie_19, true);
    else if (player1_card == 20)animation_screen->player1_Card_image.setTexture(&textures->L_Smorbib_20, true);
    else if (player1_card == 21)animation_screen->player1_Card_image.setTexture(&textures->L_Shweed_21, true);
    else if (player1_card == 22)animation_screen->player1_Card_image.setTexture(&textures->L_Thakell_22, true);
    else if (player1_card == 23)animation_screen->player1_Card_image.setTexture(&textures->L_Zage_23, true);
    else if (player1_card == 24)animation_screen->player1_Card_image.setTexture(&textures->L_Cludogo_24, true);
    else if (player1_card == 25)animation_screen->player1_Card_image.setTexture(&textures->L_Beiglu_25, true);
    else if (player1_card == 26)animation_screen->player1_Card_image.setTexture(&textures->L_Clybok_26, true);
    else if (player1_card == 27)animation_screen->player1_Card_image.setTexture(&textures->L_Togarsaw_27, true);
    else if (player1_card == 28)animation_screen->player1_Card_image.setTexture(&textures->L_Slock_28, true);
    else if (player1_card == 29)animation_screen->player1_Card_image.setTexture(&textures->L_Caeseliar_29, true);
    else if (player1_card == 30)animation_screen->player1_Card_image.setTexture(&textures->L_Omnia_30, true);
    if (player2_card == 1)animation_screen->player2_Card_image.setTexture(&textures->L_Vriska_1, true);
    else if (player2_card == 2)animation_screen->player2_Card_image.setTexture(&textures->L_Phantom_2, true);
    else if (player2_card == 3)animation_screen->player2_Card_image.setTexture(&textures->L_Kanelf_3, true);
    else if (player2_card == 4)animation_screen->player2_Card_image.setTexture(&textures->L_Gaxx_4, true);
    else if (player2_card == 5)animation_screen->player2_Card_image.setTexture(&textures->L_Shellbow_5, true);
    else if (player2_card == 6)animation_screen->player2_Card_image.setTexture(&textures->L_Marshan_6, true);
    else if (player2_card == 7)animation_screen->player2_Card_image.setTexture(&textures->L_Traria_7, true);
    else if (player2_card == 8)animation_screen->player2_Card_image.setTexture(&textures->L_Raorm_8, true);
    else if (player2_card == 9)animation_screen->player2_Card_image.setTexture(&textures->L_Krei_9, true);
    else if (player2_card == 10)animation_screen->player2_Card_image.setTexture(&textures->L_Sponk_10, true);
    else if (player2_card == 11)animation_screen->player2_Card_image.setTexture(&textures->L_Spurtle_11, true);
    else if (player2_card == 12)animation_screen->player2_Card_image.setTexture(&textures->L_Mosbie_12, true);
    else if (player2_card == 13)animation_screen->player2_Card_image.setTexture(&textures->L_Qiggly_13, true);
    else if (player2_card == 14)animation_screen->player2_Card_image.setTexture(&textures->L_Lani_14, true);
    else if (player2_card == 15)animation_screen->player2_Card_image.setTexture(&textures->L_Blatoud_15, true);
    else if (player2_card == 16)animation_screen->player2_Card_image.setTexture(&textures->L_Sledstac_16, true);
    else if (player2_card == 17)animation_screen->player2_Card_image.setTexture(&textures->L_Gunin_17, true);
    else if (player2_card == 18)animation_screen->player2_Card_image.setTexture(&textures->L_Dotal_18, true);
    else if (player2_card == 19)animation_screen->player2_Card_image.setTexture(&textures->L_Spakie_19, true);
    else if (player2_card == 20)animation_screen->player2_Card_image.setTexture(&textures->L_Smorbib_20, true);
    else if (player2_card == 21)animation_screen->player2_Card_image.setTexture(&textures->L_Shweed_21, true);
    else if (player2_card == 22)animation_screen->player2_Card_image.setTexture(&textures->L_Thakell_22, true);
    else if (player2_card == 23)animation_screen->player2_Card_image.setTexture(&textures->L_Zage_23, true);
    else if (player2_card == 24)animation_screen->player2_Card_image.setTexture(&textures->L_Cludogo_24, true);
    else if (player2_card == 25)animation_screen->player2_Card_image.setTexture(&textures->L_Beiglu_25, true);
    else if (player2_card == 26)animation_screen->player2_Card_image.setTexture(&textures->L_Clybok_26, true);
    else if (player2_card == 27)animation_screen->player2_Card_image.setTexture(&textures->L_Togarsaw_27, true);
    else if (player2_card == 28)animation_screen->player2_Card_image.setTexture(&textures->L_Slock_28, true);
    else if (player2_card == 29)animation_screen->player2_Card_image.setTexture(&textures->L_Caeseliar_29, true);
    else if (player2_card == 30)animation_screen->player2_Card_image.setTexture(&textures->L_Omnia_30, true);

    if (player1_card == 0) {
        if (animation_screen->empty_element == 1) animation_screen->player1_Card_image.setTexture(&textures->L_Terra, true);
        else if (animation_screen->empty_element == 2) animation_screen->player1_Card_image.setTexture(&textures->L_Amphibious, true);
        else if (animation_screen->empty_element == 3) animation_screen->player1_Card_image.setTexture(&textures->L_Aerial, true);

    }
    if (player2_card == 0) {
        if (opposing_element == 1) animation_screen->player2_Card_image.setTexture(&textures->L_Terra, true);
        else if (opposing_element == 2) animation_screen->player2_Card_image.setTexture(&textures->L_Amphibious, true);
        else if (opposing_element == 3) animation_screen->player2_Card_image.setTexture(&textures->L_Aerial, true);

    }
    if (animation_screen->attacktype == 1) animation_screen->icon_image.setTexture(&textures->Agility_Button, true);
    else if (animation_screen->attacktype == 2) animation_screen->icon_image.setTexture(&textures->Intelligence_Button, true);
    else if (animation_screen->attacktype == 3) animation_screen->icon_image.setTexture(&textures->Power_Button, true);
    else if (animation_screen->attacktype == 4) animation_screen->icon_image.setTexture(&textures->Defence_Button, true);
    else if (animation_screen->attacktype == 5) animation_screen->icon_image.setTexture(&textures->Freakiness_Button, true);
    animation_screen->background_image.setTexture(&textures->Animation_Screen, true);

    return;


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
            //cout << line << endl;
            if (counter == 0) {
                //name
                curnode->card_name = line;
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
    else cout << "Unable to open file " << card_num << endl;
    curnode->card_num = card_num;
}
void Get_Card_Data(struct Inventory* player1_cards) {

    struct Inventory* curnode = player1_cards;
    while (curnode != NULL) {
        Get_Card_Data_Two(curnode, curnode->card_num);
        curnode = curnode->next;
    }


}
/*
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
    game_board->discard_button_image.setPosition(20 + board_pos_x + ((new_width / 4) * 1), new_height);
    game_board->inspect_button_image.setPosition(20 + board_pos_x + ((new_width / 4) * 2), new_height);
    game_board->show_button_image.setPosition(20 + board_pos_x + ((new_width / 4) * 3), new_height);
}
*/
void Setup_Animation(struct Animation_Screen* animation_screen) {
    //60% size from original


    sf::RectangleShape card(sf::Vector2f(LARGECARDWIDTH, LARGECARDHEIGHT));
    animation_screen->player1_Card_image = card;
    animation_screen->player2_Card_image = card;

    animation_screen->player1_Card_image.setPosition(60 + (SCREENWIDTH / 10) * 1, 20 + (SCREENHEIGHT / 10) * 1);
    animation_screen->player2_Card_image.setPosition(SCREENWIDTH - 60 - LARGECARDWIDTH - (SCREENWIDTH / 10) * 1, 20 + (SCREENHEIGHT / 10) * 1);

    sf::RectangleShape box(sf::Vector2f((SCREENWIDTH / 10) * 8, (SCREENHEIGHT / 10) * 8));

    animation_screen->background_image = box;
    animation_screen->background_image.setPosition((SCREENWIDTH / 10) * 1, (SCREENHEIGHT / 10) * 1);

    sf::RectangleShape icon(sf::Vector2f(ICONSIZE, ICONSIZE));

    animation_screen->icon_image = icon;
    animation_screen->icon_image.setPosition((SCREENWIDTH / 2) - (ICONSIZE / 2), (SCREENHEIGHT / 2) - (ICONSIZE / 2));

    //cout << "test" << endl;

}

void Setup_Buttons(struct Game_Board* game_board) {

    int new_height = (A2HEIGHT * 2) + (A2WIDTH / 2);//(A2HEIGHT * 3) + (A2HEIGHT / 2);
    int new_width = (A2WIDTH * 3) + (A2WIDTH / 2);
    sf::RectangleShape button(sf::Vector2f(154, ICONSIZE));
    int board_pos_x = (SCREENWIDTH / 2) - (new_width / 2);

    game_board->ready_button_image = button;
    game_board->discard_button_image = button;
    game_board->inspect_button_image = button;
    game_board->show_button_image = button;
    //154 is width of image
    /*
    game_board->ready_button_image.setPosition(20 + board_pos_x, new_height);
    game_board->discard_button_image.setPosition(20 + board_pos_x + ((new_width / 4) * 1), new_height);
    game_board->inspect_button_image.setPosition(20 + board_pos_x + ((new_width / 4) * 2), new_height);
    game_board->show_button_image.setPosition(20 + board_pos_x + ((new_width / 4) * 3), new_height);
    */

    game_board->ready_button_image.setPosition(SCREENWIDTH / 2 - (154 / 2) - 255, new_height + 10);

    game_board->inspect_button_image.setPosition(SCREENWIDTH / 2 - (154 / 2), new_height + 10);

    game_board->show_button_image.setPosition(SCREENWIDTH / 2 - (154 / 2) + 255, new_height + 10);

    sf::RectangleShape button2(sf::Vector2f(ICONSIZE, ICONSIZE));

    game_board->power_button_image = button2;
    game_board->defence_button_image = button2;
    game_board->freakiness_button_image = button2;
    game_board->agility_button_image = button2;
    game_board->intelligence_button_image = button2;

    game_board->power_button_image.setPosition(40 + board_pos_x + ((new_width / 5) * 2), ((new_height / 2) - 25));
    game_board->defence_button_image.setPosition(40 + board_pos_x + ((new_width / 5) * 3), ((new_height / 2) - 25));
    game_board->freakiness_button_image.setPosition(40 + board_pos_x + ((new_width / 5) * 4), ((new_height / 2) - 25));
    game_board->agility_button_image.setPosition(40 + board_pos_x + ((new_width / 5) * 0), ((new_height / 2) - 25));
    game_board->intelligence_button_image.setPosition(40 + board_pos_x + ((new_width / 5) * 1), ((new_height / 2) - 25));
}

void Set_Board_Position(struct Game_Board* game_board) {

    int new_height = (A2HEIGHT * 2) + (A2WIDTH / 2);//(A2HEIGHT * 3) + (A2HEIGHT / 2);
    int new_width = (A2WIDTH * 3) + (A2WIDTH / 2);
    sf::RectangleShape board(sf::Vector2f(new_width, new_height));
    int board_pos_x = (SCREENWIDTH / 2) - (new_width / 2);
    //board.setFillColor(sf::Color::Red);
    board.setPosition(board_pos_x, 0);
    game_board->board_image = board;
    game_board->elements = board;


    //REDO THIS SECTION IN A FUTURE UPDATE - MAKE IT NOT HARDCODED
    sf::RectangleShape card(sf::Vector2f(A2WIDTH, A2HEIGHT));
    card.setFillColor(sf::Color::Yellow);

    game_board->player1_Ter_image = card;
    game_board->player1_Amp_image = card;
    game_board->player1_Aer_image = card;

    sf::RectangleShape card2(sf::Vector2f(A2WIDTH, A2HEIGHT));
    card2.setFillColor(sf::Color::Red);
    game_board->player2_Ter_image = card2;
    game_board->player2_Amp_image = card2;
    game_board->player2_Aer_image = card2;

    game_board->player1_Ter_image_x_coord = board_pos_x + 21;
    game_board->player1_Amp_image_x_coord = board_pos_x + 21 + 34 + A2WIDTH;
    game_board->player1_Aer_image_x_coord = board_pos_x + 21 + (34 * 2) + (A2WIDTH * 2);

    game_board->player1_y_coord = 16 + 79 + A2HEIGHT;
    game_board->player2_y_coord = 16;

    game_board->player1_Ter_image.setPosition(game_board->player1_Ter_image_x_coord, game_board->player1_y_coord);
    game_board->player1_Amp_image.setPosition(game_board->player1_Amp_image_x_coord, game_board->player1_y_coord);
    game_board->player1_Aer_image.setPosition(game_board->player1_Aer_image_x_coord, game_board->player1_y_coord);
    //game_board->player1_Ter_image.setPosition(board_pos_x + new_width /(21), new_height /16);

    game_board->player2_Ter_image.setPosition(game_board->player1_Aer_image_x_coord, game_board->player2_y_coord);
    game_board->player2_Amp_image.setPosition(game_board->player1_Amp_image_x_coord, game_board->player2_y_coord);
    game_board->player2_Aer_image.setPosition(game_board->player1_Ter_image_x_coord, game_board->player2_y_coord);

    game_board->turn_count = 1;

    if (!game_board->font.loadFromFile("Fonts/Myriad.ttf")) cout << "failed to load Myriad" << endl;
    game_board->turn_count_string.setFont(game_board->font);
    game_board->current_phase.setFont(game_board->font);

    game_board->turn_count_string.setString("Turn: 1");
    game_board->current_phase.setString("Phase: Placing");

    game_board->turn_count_string.setCharacterSize(20);
    game_board->current_phase.setCharacterSize(20);

    game_board->turn_count_string.setFillColor(sf::Color::Black);
    game_board->current_phase.setFillColor(sf::Color::Black);

    sf::FloatRect turn_count_rect = game_board->turn_count_string.getLocalBounds();
    game_board->turn_count_string.setOrigin(turn_count_rect.left + turn_count_rect.width, turn_count_rect.top);
    game_board->turn_count_string.setPosition(SCREENWIDTH - 30, SCREENHEIGHT - 25);

    sf::FloatRect phase_rect = game_board->current_phase.getLocalBounds();
    game_board->current_phase.setOrigin(phase_rect.left, phase_rect.top);
    game_board->current_phase.setPosition(30, SCREENHEIGHT - 25);

    sf::RectangleShape background(sf::Vector2f(SCREENWIDTH, SCREENHEIGHT));
    game_board->background = background;

    sf::RectangleShape endgame_screen(sf::Vector2f(800, 400));
    game_board->win_screen = endgame_screen;
    game_board->lose_screen = endgame_screen;

    game_board->win_screen.setPosition(SCREENWIDTH / 2 - 400, SCREENHEIGHT / 2 - 200);
    game_board->lose_screen.setPosition(SCREENWIDTH / 2 - 400, SCREENHEIGHT / 2 - 200);

}

void Set_Card_Positions(struct Inventory* player1_cards, struct Empty_Card* player2_cards) {
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


    struct Empty_Card* curnode_2 = player2_cards;
    i = 0;
    while (curnode != NULL) {
        curnode_2->x_coord = SCREENWIDTH - buffer - A2WIDTH;
        curnode_2->y_coord = buffer + (card_room * i);
        curnode_2->card_image = card;
        curnode_2->card_image.setPosition(curnode_2->x_coord, curnode_2->y_coord);
        curnode_2 = curnode_2->next;
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

struct Inventory* Get_Selected_Card(sf::RenderWindow& window, struct Inventory* player1_cards, struct Texture_Struct* textures) {

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
        if (curnode->display_type == ENLARGED_DISPLAY && bounds.contains(mouse)) {
            selected_card = curnode;
        }
        curnode = curnode->next;
    }
    if (selected_card != NULL) {
        Switch_Highlighted_Image(textures, selected_card, FALSE);
        selected_card->card_image.setSize(sf::Vector2f(A2WIDTHHIGHLIGHTED, A2HEIGHTHIGHLIGHTED));
        selected_card->card_image.setPosition((selected_card->x_coord) - ((A2WIDTHHIGHLIGHTED - A2WIDTH) / 2), (selected_card->y_coord) - ((A2HEIGHTHIGHLIGHTED - A2HEIGHT) / 2));
        selected_card->display_type = ENLARGED_DISPLAY;
        //selected_card->card_image.setSize(sf::Vector2f(A2WIDTH * 1.2, A2HEIGHT * 1.2));
        return selected_card;
    }
    else {
        return NULL;
    }


}

int Check_If_Card_Board_Available(sf::RenderWindow& window, struct Game_Board* game_board, struct Inventory* card_selected) {
    sf::Vector2f mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));
    sf::FloatRect bounds;
    bounds = game_board->player1_Ter_image.getGlobalBounds();
    if ((card_selected->element == TERRA || card_selected->element == INCOGNITO) && game_board->player1_Ter == NULL) {
        if (bounds.contains(mouse)) { return TRUE; }
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

void Fill_Animation_Data(Animation_Screen* animation_screen, int winner, struct Inventory* player1_card, struct Inventory* player2_card, int attacktype) {
    if (animation_screen->player2_Card != NULL) delete animation_screen->player2_Card;
    /*
    Animation Struct

    struct Inventory* player1_Card = NULL;
    struct Inventory* player2_Card = NULL;

    sf::RectangleShape player1_Card_image;
    sf::RectangleShape player2_Card_image;

    sf::RectangleShape background_image;
    sf::RectangleShape icon_image;

    sf::Text player1_text;
    sf::Text player2_text;

    int attacktype;

    */
    animation_screen->player1_Card = player1_card;
    animation_screen->player2_Card = player2_card;
    std::string attacktypestring;

    if (attacktype == 1) attacktypestring = "Agility";
    else if (attacktype == 2) attacktypestring = "Intelligence";
    else if (attacktype == 3) attacktypestring = "Power";
    else if (attacktype == 4) attacktypestring = "Defence";
    else if (attacktype == 5) attacktypestring = "Freakiness";

    animation_screen->attacktype = attacktype;


    if (!animation_screen->font.loadFromFile("Fonts/Myriad.ttf")) cout << "failed to load Myriad" << endl;

    animation_screen->player1_text.setFont(animation_screen->font);
    animation_screen->player2_text.setFont(animation_screen->font);
    // If player1 clicked an empty card
    if (player2_card == NULL) {
        animation_screen->player2_text.setString("No card in this lane");
    }
    else {
        std::string statnum;
        if (attacktype == 1) statnum = std::to_string(player2_card->agility);
        else if (attacktype == 2) statnum = std::to_string(player2_card->intelligence);
        else if (attacktype == 3) statnum = std::to_string(player2_card->power);
        else if (attacktype == 4) statnum = std::to_string(player2_card->defence);
        else if (attacktype == 5) statnum = std::to_string(player2_card->freakiness);

        animation_screen->player2_text.setString(attacktypestring + ": " + statnum);

    }
    if (player1_card == NULL) {
        animation_screen->player1_text.setString("No card in this lane");
    }
    else {
        std::string statnum;
        if (attacktype == 1) statnum = std::to_string(player1_card->agility);
        else if (attacktype == 2) statnum = std::to_string(player1_card->intelligence);
        else if (attacktype == 3) statnum = std::to_string(player1_card->power);
        else if (attacktype == 4) statnum = std::to_string(player1_card->defence);
        else if (attacktype == 5) statnum = std::to_string(player1_card->freakiness);

        animation_screen->player1_text.setString(attacktypestring + ": " + statnum);

    }


    animation_screen->player1_text.setCharacterSize(35);
    animation_screen->player2_text.setCharacterSize(35);

    animation_screen->player1_text.setFillColor(sf::Color::Black);
    animation_screen->player2_text.setFillColor(sf::Color::Black);

    sf::FloatRect player1Rect = animation_screen->player1_text.getLocalBounds();
    animation_screen->player1_text.setOrigin(player1Rect.left + player1Rect.width / 2.0f, player1Rect.top + player1Rect.height / 2.0f);

    animation_screen->player1_text.setPosition(60 + (SCREENWIDTH / 10) * 1 + (LARGECARDWIDTH / 2), LARGECARDHEIGHT + 47.5 + (SCREENHEIGHT / 10) * 1);

    sf::FloatRect player2Rect = animation_screen->player2_text.getLocalBounds();
    animation_screen->player2_text.setOrigin(player2Rect.left + player2Rect.width / 2.0f, player2Rect.top + player2Rect.height / 2.0f);

    animation_screen->player2_text.setPosition(SCREENWIDTH - 60 - LARGECARDWIDTH - (SCREENWIDTH / 10) * 1 + (LARGECARDWIDTH / 2), LARGECARDHEIGHT + 47.5 + (SCREENHEIGHT / 10) * 1);

    animation_screen->player1_Card_image.setPosition(60 + (SCREENWIDTH / 10) * 1, 20 + (SCREENHEIGHT / 10) * 1);

    // Tie
    if (winner == 0) {


    }
    // Player 1 Wins
    else if (winner == 1) {


    }
    // Player 2 Wins
    else if (winner == 2) {


    }

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
        return 2;
    }
    bounds = game_board->player2_Aer_image.getGlobalBounds();
    if (bounds.contains(mouse)) {
        return 3;
    }
    return 0;

}
void Set_New_Position_Normalised(struct Inventory* player1_cards, struct Game_Board* game_board) {
    //reorganise LL so all on board cards are at the end
    // 
    //Setup xcoords and ycoords
    int buffer = 25; // empty space in top right corner
    int card_room = 60; // y distance between cards

    //sf::RectangleShape card(sf::Vector2f(A2WIDTH, A2HEIGHT));

    struct Inventory* curnode = player1_cards;
    int i = 0;
    while (curnode != NULL) {
        curnode->on_board = FALSE;
        curnode->x_coord = buffer;
        curnode->y_coord = buffer + (card_room * i);
        //curnode->card_image = card;
        curnode->display_type = NORMAL_DISPLAY;
        curnode->card_image.setPosition(curnode->x_coord, curnode->y_coord);

        curnode = curnode->next;
        i++;

    }

    game_board->player1_Ter = NULL;
    game_board->player1_Amp = NULL;
    game_board->player1_Aer = NULL;

    game_board->player2_Ter = NULL;
    game_board->player2_Amp = NULL;
    game_board->player2_Aer = NULL;

    //Print_Linked_List(player1_cards);
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
int GetAttackType(sf::RenderWindow& window, struct Game_Board* game_board) {

    sf::Vector2f mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));
    sf::FloatRect bounds;

    bounds = game_board->power_button_image.getGlobalBounds();
    if (bounds.contains(mouse)) {
        return 3;
    }
    bounds = game_board->defence_button_image.getGlobalBounds();
    if (bounds.contains(mouse)) {
        return 4;
    }
    bounds = game_board->freakiness_button_image.getGlobalBounds();
    if (bounds.contains(mouse)) {
        return 5;
    }
    bounds = game_board->intelligence_button_image.getGlobalBounds();
    if (bounds.contains(mouse)) {
        return 2;
    }
    bounds = game_board->agility_button_image.getGlobalBounds();
    if (bounds.contains(mouse)) {
        return 1;
    }
    return 0;

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
    return 0;


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
            while (curnode->next->next != NULL) {

                if (curnode->next->card_num == card_number) {
                    curnode->next = curnode->next->next;
                    if (curnode->next->next == NULL) { break; }
                }
                curnode = curnode->next;

            }
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

    if (game_board->player1_Ter != NULL) if (game_board->player1_Ter->card_num == card_selected->card_num) game_board->player1_Ter = NULL;
    if (game_board->player1_Amp != NULL) if (game_board->player1_Amp->card_num == card_selected->card_num) game_board->player1_Amp = NULL;
    if (game_board->player1_Aer != NULL) if (game_board->player1_Aer->card_num == card_selected->card_num) game_board->player1_Aer = NULL;

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


void Highlight_Buttons(sf::RenderWindow& window, struct Game_Board* game_board, struct Texture_Struct* textures) {

    game_board->ready_button_image.setTexture(&textures->Ready_Button_Unlit, true);
    game_board->discard_button_image.setTexture(&textures->Discard_Button_Unlit, true);
    game_board->inspect_button_image.setTexture(&textures->Inspect_Button_Unlit, true);
    game_board->show_button_image.setTexture(&textures->Show_Button_Unlit, true);

    game_board->power_button_image.setTexture(&textures->Power_Button, true);
    game_board->defence_button_image.setTexture(&textures->Defence_Button, true);
    game_board->freakiness_button_image.setTexture(&textures->Freakiness_Button, true);
    game_board->intelligence_button_image.setTexture(&textures->Intelligence_Button, true);
    game_board->agility_button_image.setTexture(&textures->Agility_Button, true);

    sf::Vector2f mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));
    sf::FloatRect bounds;

    bounds = game_board->power_button_image.getGlobalBounds();
    if (bounds.contains(mouse)) {
        game_board->power_button_image.setTexture(&textures->Power_ButtonL, true);
    }
    bounds = game_board->defence_button_image.getGlobalBounds();
    if (bounds.contains(mouse)) {
        game_board->defence_button_image.setTexture(&textures->Defence_ButtonL, true);
    }
    bounds = game_board->freakiness_button_image.getGlobalBounds();
    if (bounds.contains(mouse)) {
        game_board->freakiness_button_image.setTexture(&textures->Freakiness_ButtonL, true);
    }
    bounds = game_board->intelligence_button_image.getGlobalBounds();
    if (bounds.contains(mouse)) {
        game_board->intelligence_button_image.setTexture(&textures->Intelligence_ButtonL, true);
    }
    bounds = game_board->agility_button_image.getGlobalBounds();
    if (bounds.contains(mouse)) {
        game_board->agility_button_image.setTexture(&textures->Agility_ButtonL, true);
    }

    bounds = game_board->ready_button_image.getGlobalBounds();
    if (bounds.contains(mouse)) {
        game_board->ready_button_image.setTexture(&textures->Ready_Button_Lit, true);
    }
    bounds = game_board->discard_button_image.getGlobalBounds();
    if (bounds.contains(mouse)) {
        game_board->discard_button_image.setTexture(&textures->Discard_Button_Lit, true);
    }
    bounds = game_board->inspect_button_image.getGlobalBounds();
    if (bounds.contains(mouse)) {
        game_board->inspect_button_image.setTexture(&textures->Inspect_Button_Lit, true);
    }
    bounds = game_board->show_button_image.getGlobalBounds();
    if (bounds.contains(mouse)) {
        game_board->show_button_image.setTexture(&textures->Show_Button_Lit, true);
    }


}
void Update_Phase_Turn(struct Game_Board* game_board, int phase) {

    if (phase == CARD_PLACING) {
        game_board->current_phase.setString("Phase: Placing");
    }
    else if (phase == PLAYER_1_ATK) {
        game_board->current_phase.setString("Phase: Defending");
    }
    else if (phase == PLAYER_2_ATK) {
        game_board->current_phase.setString("Phase: Attacking");
    }
    else if (phase == -1) {
        game_board->current_phase.setString("Phase: Waiting");
    }
    std::string turn_num = std::to_string(game_board->turn_count);

    game_board->turn_count_string.setString("Turn: " + turn_num);

}

void Draw_Card_Outlines(sf::RenderWindow& window, struct EmptyCard empty_card_array[16]) {
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
void Draw_Board(sf::RenderWindow& window, struct Game_Board* game_board, struct Inventory* card_selected, int attack_type, int gamestate, int player_2_ready) {
    window.draw(game_board->background);
    window.draw(game_board->board_image);
    //add selector here
    if (card_selected != NULL && gamestate == CARD_PLACING && player_2_ready == FALSE) {
        Draw_Selected_Board(window, game_board, card_selected);

    }
    if (attack_type != 0) {
        window.draw(game_board->player2_Ter_image);
        window.draw(game_board->player2_Amp_image);
        window.draw(game_board->player2_Aer_image);
    }
    window.draw(game_board->elements);

    window.draw(game_board->ready_button_image);
    window.draw(game_board->show_button_image);
    //window.draw(game_board->discard_button_image);
    window.draw(game_board->inspect_button_image);

    window.draw(game_board->power_button_image);
    window.draw(game_board->defence_button_image);
    window.draw(game_board->agility_button_image);
    window.draw(game_board->freakiness_button_image);
    window.draw(game_board->intelligence_button_image);

    window.draw(game_board->turn_count_string);
    window.draw(game_board->current_phase);
}

void Draw_Animation(sf::RenderWindow& window, struct Game_Board* game_board, struct Animation_Screen* animation_screen) {

    /*
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

    */

    //Add green and red boxes here


    /*
    window.draw(animation_screen->icon_image);

    window.draw(animation_screen->player1_text);
    window.draw(animation_screen->player2_text);
    */
    window.draw(animation_screen->background_image);
    window.draw(animation_screen->player1_Card_image);
    window.draw(animation_screen->player2_Card_image);

    window.draw(animation_screen->player1_text);
    window.draw(animation_screen->player2_text);

    window.draw(animation_screen->icon_image);


}

void Draw_All_Card_Animation(sf::RenderWindow& window, struct Animation_Screen* animation_screen, struct Inventory* cards) {
    /*    sf::RectangleShape box(sf::Vector2f((SCREENWIDTH /10)*8, (SCREENHEIGHT / 10) * 8));

    animation_screen->background_image = box;
    animation_screen->background_image.setPosition((SCREENWIDTH / 10) * 1, (SCREENHEIGHT / 10) * 1);
    */


    window.draw(animation_screen->background_image);

    struct Inventory* cur = cards;
    int i = 0;
    int y = 0;
    while (cur != NULL) {
        if (i == 4) {
            i = 0;
            y = 3;
        }
        cur->card_image.setPosition((SCREENWIDTH / 10) * (1.5 + (i * 1.8)), (SCREENHEIGHT / 10) * (1.1 + (1.3 * y)));

        window.draw(cur->card_image);
        cur->card_image.setPosition(cur->x_coord, cur->y_coord);
        i++;
        cur = cur->next;


    }

}

void Draw_One_Card_Animation(sf::RenderWindow& window, struct Animation_Screen* animation_screen) {

    window.draw(animation_screen->player1_Card_image);
}
void Draw_Player2(sf::RenderWindow& window, struct Card_Backside* card_backside, int num_cards) {


    int buffer = 25; // empty space in top right corner
    int card_room = 60; // y distance between cards

    //sf::RectangleShape card(sf::Vector2f(A2WIDTH, A2HEIGHT));


    for (int i = 0; i != num_cards; i++) {
        int x = SCREENWIDTH - buffer - A2WIDTH;
        int y = buffer + (card_room * i);
        card_backside->card_image.setPosition(x, y);
        window.draw(card_backside->card_image);
    }

}
void Populate_Backside(struct Texture_Struct* textures, struct Card_Backside* card_backside) {


    sf::RectangleShape card(sf::Vector2f(A2WIDTH, A2HEIGHT));

    card_backside->card_image = card;

    card_backside->card_image.setTexture(&textures->S_Card_Backside, true);
}
void Draw_Cards(sf::RenderWindow& window, struct Empty_Card* player1_cards, struct Inventory* player2_cards) {
    struct Inventory* selected_card = NULL;

    struct Inventory* curnode = player2_cards;
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

    struct Empty_Card* curnode_2 = player1_cards;
    while (curnode_2 != NULL) {
        //window.draw(curnode->card_image);
        curnode_2 = curnode_2->next;
    }

    /*
    for (int i = 0; i != 8; i++) {
        window.draw(player1_cards->card_image);
    }
    */
}
void Add_To_Linked_List(struct Inventory** list, struct Inventory* Node) {

    Node->next = (*list);
    (*list) = Node;

}


void Remove_From_Linked_List(struct Inventory** list, int value) {

    Inventory* temp = *list;
    Inventory* prev = NULL;
    if (temp != NULL && temp->card_num == value)
    {
        *list = temp->next;
        return;
    }
    else {
        while (temp != NULL && temp->card_num != value)
        {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL) return;
        prev->next = temp->next;
        return;
    }

}
void Remove_Card(struct Inventory* card, struct Inventory** player1_cards, struct Inventory** discard_pile, struct Game_Board* game_board) {

    Remove_From_Linked_List(player1_cards, card->card_num);
    //Print_Linked_List((*discard_pile));
    Add_To_Linked_List(discard_pile, card);


    if (game_board->player1_Ter != NULL) if (game_board->player1_Ter->card_num == card->card_num) game_board->player1_Ter = NULL;
    if (game_board->player1_Amp != NULL) if (game_board->player1_Amp->card_num == card->card_num) game_board->player1_Amp = NULL;
    if (game_board->player1_Aer != NULL) if (game_board->player1_Aer->card_num == card->card_num) game_board->player1_Aer = NULL;

    if (game_board->player2_Ter != NULL) if (game_board->player2_Ter->card_num == card->card_num) game_board->player2_Ter = NULL;
    if (game_board->player2_Amp != NULL) if (game_board->player2_Amp->card_num == card->card_num) game_board->player2_Amp = NULL;
    if (game_board->player2_Aer != NULL) if (game_board->player2_Aer->card_num == card->card_num) game_board->player2_Aer = NULL;
}
int Board_Is_Empty(struct Game_Board* game_board) {
    int return_val = 0;
    if (game_board->player1_Ter == NULL && game_board->player1_Amp == NULL && game_board->player1_Aer == NULL) return_val = 1;
    //cout << "RETURN " << return_val << endl;

    //cout << "RETURN " << return_val << endl;
    return return_val;
}
void main() {
	string ipAddress;//= "192.168.86.27";
	cout << "IP Address loading as: ";
	getline(cin, ipAddress);

	//cin >> ipAddress;
	//string ipAddress = "127.0.0.1"; //58.166.208.45
	int port = 54000;

	//intiz

	WSAData data;
	WORD ver = MAKEWORD(2, 2);
	int wsResult = WSAStartup(ver, &data);
	if (wsResult != 0) {
		cerr << "Cant start Winsock, error number: " << wsResult << endl;
		getchar();
		return;
	}

	//socket create

	SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);

	if (sock == INVALID_SOCKET) {
		cerr << "cant create socket, error number: " << WSAGetLastError() << endl;
		WSACleanup();
		getchar();
		return;
	}

	//hint struct

	sockaddr_in hint;
	hint.sin_family = AF_INET;
	hint.sin_port = htons(port);
	inet_pton(AF_INET, ipAddress.c_str(), &hint.sin_addr);

	//connect
	int connResult = connect(sock, (sockaddr*)&hint, sizeof(hint));
	if (connResult == SOCKET_ERROR) {

		//cerr << "Can't connect to server, error number: \n" << WSAGetLastError() << endl;
		cerr << "Can't connect to that IP either because server is not open on that IP or port forwarding has not been enabled on that IP." << endl;
		closesocket(sock);
		WSACleanup();
		getchar();
		return;
	}
	//while loop
	cout << "\nSuccesfully connected to: "<< ipAddress << " on port: " << ntohs(hint.sin_port) << endl;
	uint32_t game_data[STARTINGCARDS];
	string userInput;
	//getline(cin, userInput);
	//do {
		//THIS IS WHERE INFO IS PARSED

		//promt user
		
		//cout << "> ";
		//getline(cin, userInput);


	ZeroMemory(game_data, STARTINGCARDS);
	int byteSize = recv(sock, (char*)game_data, STARTINGCARDS * sizeof(uint32_t), 0);

    


    srand(time(NULL));

    int player1_cards_integer = STARTINGCARDS;
    int attack_type = 0;
    int player_2_ready = FALSE;
    int animation_status = ANIMATION_NOT_RUNNING;
    int turn_type = 0;
    int get_card_status = FALSE;
    struct Inventory* discard_pile = NULL;

    //turn into function
    struct Inventory* player2_cards = new struct Inventory;
    struct Empty_Card* player1_cards = new struct Empty_Card;
    struct Inventory* card_selected = NULL;
    //struct EmptyCard empty_card_array[16];
    struct Texture_Struct* textures = new struct Texture_Struct;
    struct Animation_Screen* animation_screen = new struct Animation_Screen;
    struct Game_Board* game_board = new struct Game_Board;//(struct Inventory*)malloc(sizeof(struct Inventory));
    struct Card_Backside* card_backside = new struct Card_Backside;
    //Game Logic Functions
    //Get_Card_Bank(card_bank);
    Starting_Cards(game_data, player1_cards, player2_cards);
    //Starting_Cards(card_bank, player1_cards, player2_cards);
    //Create_Card_Graphics(empty_card_array);
    //Print_Linked_List(player1_cards);
    Set_Card_Positions(player2_cards, player1_cards);
    Set_Board_Position(game_board);
    Setup_Animation(animation_screen);
    Setup_Buttons(game_board);
    
    
    Initialise_Graphics(textures, player2_cards, game_board);
    Populate_Backside(textures, card_backside);
    Get_Card_Data(player2_cards);

    //getchar();

    int gamestate = CARD_PLACING;

		/*
		//send
		if (userInput.size() > 0) {
			int sendResult = send(sock, userInput.c_str(), userInput.size() + 1, 0);
			if (sendResult != SOCKET_ERROR) {
				got_data = true;
				//ZeroMemory(game_data, STARTING_CARDS);
				//int bytesReceived = recv(sock, game_data, STARTING_CARDS, 0);
				//if (bytesReceived > 0) {
					//printf("%d\n", game_data[0]);
					//cout << "message sent from the server ---> " << buf[0] << endl;//string(buf, 0, bytesReceived) << endl;

				//}

			}
		}
		*/

	//} while (got_data == false);//while (userInput.size() != 0); //while (userInput.size() > 0);
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    //sf::RenderWindow window(sf::VideoMode(800, 600), "SFML shapes", sf::Style::Default, settings);
    sf::RenderWindow window(sf::VideoMode(SCREENWIDTH, SCREENHEIGHT), "Phantrumps - Client", sf::Style::Close);
    window.setFramerateLimit(60);
    sf::View view = window.getDefaultView();
    int ret;
    while (window.isOpen())
    {

        /*

        //win check

        if (player1_cards == NULL) {
            //do something
        }
        else if (player2_cards == NULL) {
            //do something else
        }
        */

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
            if (bytesReceived == SOCKET_ERROR) { cerr << "Client quit program or Socket error occured, quitting program " << endl; break; }
            if (bytesReceived == 0) { cout << "client disconnected " << endl; break; }

            //Sending Data
            printf("Client> %s\n", buf);
            string userInput = "Hello World!";
            cout << userInput.size() << endl;
            //send(clientSocket, userInput.c_str(), userInput.size() + 1, 0);
            //send(clientSocket, (char*)game_data, BYTESOFGAMEDATA+ 1, 0);
        }
        else if (ret == -1) {
            cout << "ret is -1 ERROR\n" << endl;
            WSACleanup();
            closesocket(clientSocket);
        }




        sf::Vector2f mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));

        // retrieve the bounding box of the sprite

        sf::FloatRect bounds;
        struct Inventory* curnode = player2_cards;
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

        if (gamestate == PLAYER_1_ATK) {
            struct timeval timeout;
            timeout.tv_sec = 0;
            timeout.tv_usec = 0;
            fd_set rds;
            FD_ZERO(&rds);
            FD_SET(sock, &rds);
            ret = select(sock + 1, &rds, NULL, NULL, &timeout);
            if (FD_ISSET(sock, &rds)) {
                uint32_t pl1_atk_game_data[6];
                ZeroMemory((char*)pl1_atk_game_data, 6 * sizeof(uint32_t));
                int bytesReceived = recv(sock, (char*)pl1_atk_game_data, 6 * sizeof(uint32_t), 0);
                if (bytesReceived == SOCKET_ERROR) { cerr << "Client quit program or Socket error occured, quitting program " << endl; break; }
                if (bytesReceived == 0) { cout << "client disconnected " << endl; break; }
                

                if (pl1_atk_game_data[0] == 2) player1_cards_integer--;

                //Player 2 card is player 1 card in this case and vice versa

                struct Inventory* player2_card_chosen = NULL;
                if (pl1_atk_game_data[2] == 0) player2_card_chosen = NULL;
                else {
                    struct Inventory* cur = player2_cards;
                    while (cur != NULL) {
                        if (cur->card_num == pl1_atk_game_data[2]) player2_card_chosen = cur;
                        cur = cur->next;
                    }
                }
                struct Inventory* player1_card_chosen = new struct Inventory;
                Get_Card_Data_Two(player1_card_chosen, pl1_atk_game_data[1]);
                animation_screen->empty_element = pl1_atk_game_data[4];
                Fill_Animation_Data(animation_screen, pl1_atk_game_data[0], player2_card_chosen, player1_card_chosen, pl1_atk_game_data[3]);
                animation_status = SHOWBATTLE;
                Set_Animation_Graphics(textures, animation_screen, pl1_atk_game_data[4], pl1_atk_game_data[5]);

                if (pl1_atk_game_data[0] == 1) {
                    //Print_Linked_List(discard_pile);
                    Remove_Card(player2_card_chosen, &player2_cards, &discard_pile, game_board);
                }
                if (pl1_atk_game_data[0] == 4 || pl1_atk_game_data[0] == 5) gamestate = pl1_atk_game_data[0];
                else {
                    if (turn_type == 0) {
                        Update_Phase_Turn(game_board, PLAYER_2_ATK);
                        gamestate = PLAYER_2_ATK;
                    }
                    else if (turn_type == 1) {
                        turn_type = 0;
                        
                        game_board->turn_count++;
                        Update_Phase_Turn(game_board, CARD_PLACING);
                        gamestate = CARD_PLACING;
                        get_card_status = TRUE;
                    }
                }

            }
            else if (ret == -1) {
                cout << "ret is -1 ERROR\n" << endl;
                WSACleanup();
                closesocket(sock);
            }

        }

        if (gamestate == CARD_PLACING && player_2_ready == TRUE) {
            //cout << "WAITING" << endl;
            struct timeval timeout;
            timeout.tv_sec = 0;
            timeout.tv_usec = 0;
            fd_set rds;
            FD_ZERO(&rds);
            FD_SET(sock, &rds);
            ret = select(sock + 1, &rds, NULL, NULL, &timeout);
            if (FD_ISSET(sock, &rds)) {
                uint32_t wait_check[1];
                ZeroMemory((char*)wait_check, sizeof(uint32_t));
                int bytesReceived = recv(sock, (char*)wait_check, sizeof(uint32_t), 0);
                if (bytesReceived == SOCKET_ERROR) { cerr << "Client quit program or Socket error occured, quitting program " << endl; break; }
                if (bytesReceived == 0) { cout << "client disconnected " << endl; break; }
                if (wait_check[0] == 1) {
                    if (turn_type == 0) {
                        Update_Phase_Turn(game_board, PLAYER_1_ATK);
                        gamestate = PLAYER_1_ATK;
                    }
                    else if (turn_type == 1) {
                        Update_Phase_Turn(game_board, PLAYER_2_ATK);
                        gamestate = PLAYER_2_ATK;
                    }
                    player_2_ready = FALSE;
                }

            }
            else if (ret == -1) {
                cout << "ret is -1 ERROR\n" << endl;
                WSACleanup();
                closesocket(sock);
            }

        }

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            else if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Right) {
                    if (gamestate == CARD_PLACING && player_2_ready == FALSE) {
                        Remove_From_Board(window, game_board, player2_cards);
                        Set_New_Position(player2_cards);
                    }

                }
                else if (event.mouseButton.button == sf::Mouse::Left)
                {

                    //clicking buttons
                    if (animation_status != ANIMATION_NOT_RUNNING) {
                        animation_status = ANIMATION_NOT_RUNNING;
                    }
                    else {
                        sf::Vector2f mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                        sf::FloatRect bounds;

                        bounds = game_board->inspect_button_image.getGlobalBounds();
                        if (bounds.contains(mouse) && card_selected != NULL) {
                            animation_screen->player1_Card = card_selected;
                            Set_Animation_Graphics(textures, animation_screen, 4, 4);
                            animation_screen->player1_Card_image.setPosition((SCREENWIDTH / 2) - (LARGECARDWIDTH / 2), (SCREENHEIGHT / 2) - (LARGECARDHEIGHT / 2));
                            animation_status = SHOWONECARD;
                        }

                        bounds = game_board->show_button_image.getGlobalBounds();
                        if (bounds.contains(mouse)) {
                            Set_Animation_Graphics(textures, animation_screen, 4, 4);
                            animation_status = SHOWALLCARD;
                        }

                        bounds = game_board->ready_button_image.getGlobalBounds();
                        // Case for sending data in card placing phase
                        if (bounds.contains(mouse)) {
                            if (gamestate == CARD_PLACING && player_2_ready == FALSE && Board_Is_Empty(game_board) != 1) {
                                //player_2_ready = TRUE;
                                uint32_t Ter = 0;
                                uint32_t Amp = 0;
                                uint32_t Aer = 0;

                                if (game_board->player1_Ter != NULL) {
                                    Ter = game_board->player1_Ter->card_num;
                                }
                                if (game_board->player1_Amp != NULL) {
                                    Amp = game_board->player1_Amp->card_num;
                                }
                                if (game_board->player1_Aer != NULL) {
                                    Aer = game_board->player1_Aer->card_num;
                                }

                                uint32_t Board_Data[3];
                                Board_Data[0] = Ter;
                                Board_Data[1] = Amp;
                                Board_Data[2] = Aer;

                                send(sock, (char*)Board_Data, 3 * sizeof(uint32_t), 0);
                                player_2_ready = TRUE;
                                Update_Phase_Turn(game_board, -1);
                                //gamestate = WAITING;


                            }
                        }

                        if (gamestate == PLAYER_2_ATK) {

                            if (attack_type != 0) {
                                if (int lane_clicked = Clicked_Empty_Pos(window, game_board)) {

                                    // Send card attacking with, lane clicked and attack type
                                    uint32_t  pl2_atk_game_data1[3];
                                    pl2_atk_game_data1[0] = card_selected->card_num;
                                    //if (lane_clicked == 1) lane_clicked = 3;
                                    //else if (lane_clicked == 3) lane_clicked = 1;
                                    pl2_atk_game_data1[1] = lane_clicked;
                                    pl2_atk_game_data1[2] = attack_type;
                                    send(sock, (char*)pl2_atk_game_data1, 3 * sizeof(uint32_t), 0);

                                    // WAIT FOR PACKETS DETAILING RESULT TO RETURN
                                    uint32_t pl2_atk_game_data2[6];
                                    ZeroMemory(pl2_atk_game_data2, 6);
                                    int byteSize = recv(sock, (char*)pl2_atk_game_data2, 6 * sizeof(uint32_t), 0);

                                    

                                    //else {
                                    if (pl2_atk_game_data2[0] == 2) player1_cards_integer--;

                                    animation_screen->empty_element = pl2_atk_game_data2[4];

                                    struct Inventory* player2_card_chosen = card_selected;
                                    //struct Inventory* player1_card_chosen = new struct Inventory;
                                    //Get_Card_Data_Two(player1_card_chosen, pl2_atk_game_data2[1]);

                                    struct Inventory* player1_card_chosen = NULL;
                                    if (pl2_atk_game_data2[1] != 0) {
                                        player1_card_chosen = new struct Inventory;
                                        Get_Card_Data_Two(player1_card_chosen, pl2_atk_game_data2[1]);
                                    }

                                    Fill_Animation_Data(animation_screen, pl2_atk_game_data2[0], player2_card_chosen, player1_card_chosen, pl2_atk_game_data2[3]);
                                    animation_status = SHOWBATTLE;
                                    Set_Animation_Graphics(textures, animation_screen, pl2_atk_game_data2[4], pl2_atk_game_data2[5]);

                                    if (pl2_atk_game_data2[0] == 1) {
                                        //Print_Linked_List(discard_pile);
                                        Remove_Card(player2_card_chosen, &player2_cards, &discard_pile, game_board);
                                    }

                                    if (pl2_atk_game_data2[0] == 4 || pl2_atk_game_data2[0] == 5) gamestate = pl2_atk_game_data2[0];
                                    else {
                                        if (turn_type == 0) {
                                            turn_type = 1;
                                            game_board->turn_count++;
                                            Update_Phase_Turn(game_board, CARD_PLACING);

                                            gamestate = CARD_PLACING;

                                            get_card_status = TRUE;
                                            /*

                                            0 - player 1 new cards
                                            1 - player 2 card 1
                                            2 - player 2 card 2 (0 if no card)
                                            3 - player 2 card 3 (0 if no card)

                                            */
                                        }
                                        else if (turn_type == 1) {

                                            Update_Phase_Turn(game_board, PLAYER_1_ATK);
                                            //game_board->turn_count++;
                                            gamestate = PLAYER_1_ATK;
                                        }
                                        //}
                                    }
                                    attack_type = 0;


                                }
                            }

                            // Get the attack type
                            if (card_selected != NULL) {
                                if (Is_Card_Selected_On_Board(game_board, card_selected)) {
                                    attack_type = GetAttackType(window, game_board);
                                }
                            }

                        }

                        // Get Card when ply1 is attacking
                        if (player_2_ready == FALSE && gamestate == CARD_PLACING) {
                            if (card_selected != NULL) {
                                if (Check_If_Card_Board_Available(window, game_board, card_selected) == TRUE) {
                                    Set_Card_To_Board(window, game_board, card_selected);
                                    player2_cards = Put_Card_At_Back(player2_cards, card_selected->card_num);
                                    card_selected->on_board = TRUE;
                                    //card_selected = NULL;
                                    Set_New_Position(player2_cards);

                                }
                            }
                        }
                        if (attack_type == 0) {
                            card_selected = Get_Selected_Card(window, player2_cards, textures);
                        }
                    }
                }
            }
        }


        if (get_card_status == TRUE) {
            uint32_t new_card_data_pl2[5];
            ZeroMemory(new_card_data_pl2, 5);
            int byteSize = recv(sock, (char*)new_card_data_pl2, 5 * sizeof(uint32_t), 0);

            for (int i = 1; i != 4; i++) {
                if (new_card_data_pl2[i] != 0) {
                    struct Inventory* new_card = new struct Inventory;
                    new_card->card_num = new_card_data_pl2[i];
                    new_card->next = NULL;

                    sf::RectangleShape card(sf::Vector2f(A2WIDTH, A2HEIGHT));

                    new_card->card_image = card;

                    Switch_Highlighted_Image(textures, new_card, 1);
                    Get_Card_Data_Two(new_card, new_card_data_pl2[i]);


                    Add_To_Linked_List(&player2_cards, new_card);


                }
            }

            if (card_selected != NULL) {
                card_selected->card_image.setSize(sf::Vector2f(A2WIDTH, A2HEIGHT));
                Switch_Highlighted_Image(textures, card_selected, TRUE); //true means it is highlighted
                
                card_selected = NULL;
            }


            Set_New_Position_Normalised(player2_cards, game_board);
            get_card_status = FALSE;
            player1_cards_integer += new_card_data_pl2[4];
        }
        window.clear();

        //DO DRAWINGS

        Highlight_Buttons(window, game_board, textures);
        Draw_Board(window, game_board, card_selected, attack_type, gamestate, player_2_ready); // PUT ATTACK TYPE HERE
        Draw_Cards(window, player1_cards, player2_cards);
        Draw_Player2(window, card_backside, player1_cards_integer);
        if (animation_status == SHOWBATTLE) {
            Draw_Animation(window, game_board, animation_screen);
        }
        else if (animation_status == SHOWONECARD) {
            // Assume card selected is not null
            Draw_One_Card_Animation(window, animation_screen);
        }
        else if (animation_status == SHOWDISCARD) {
            //Draw_Discard_Animation(window, game_board, discard_pile);
        }
        else if (animation_status == SHOWALLCARD) {
            Draw_All_Card_Animation(window, animation_screen, player2_cards);
        }

        if (gamestate == PLAYER_1_WON || gamestate == PLAYER_2_WON) {
            if (gamestate == PLAYER_2_WON) {
                //text.setString("You Won");
                window.draw(game_board->win_screen);
            }
            if (gamestate == PLAYER_1_WON) {
                //text.setString("You Lost");
                window.draw(game_board->lose_screen);
            }
        }


        window.display();


    }
	

	
	closesocket(sock);
	WSACleanup();

	

}
