# Phantrumps

Phantrumps is a card game I created with friends in 2017. For the CSE project I wanted to try and turn this fun card game into an actual computer game. To play you need 2 players on two different computers, one will run the host exe and one will run the client exe. **The game connects on Port 54000 so the host must ensure this Port is forwarded** before the client can connect to the host's IP. There are 30 cards in total to play with.

For playtesting purposes, running both executables and connecting with the IP address 127.0.0.1 works perfectly well.

## Requirements

Windows is necessary to play as the Winsock library was used as the socket library.

The computer must have a screen of at least 1350x800. Resizing is not possible as the SFML library ruins the graphics when a window is resized.

## Rules

1. Player 1 and Player 2 each get given 5 cards and 15 cards are put in the card bank.

2. Players can not have more than 8 cards in their inventory.

3. If there are no cards in the card bank then all cards in the discard bank are shuffled and placed back into the card bank

4. A turn is defined by both players placing cards on the board and each one attacking. A phase is either 'Placing', 'Player 1 Attacking' or 'Player 2 Attacking'.

5. Every turn both players place down 1 to 3 cards onto the board, each card being placed in a lane respective to its element. Incognito cards can be placed in any of the 3 lanes. Players click the ready button once their cards are placed.

6. If you have a card(s) that can be placed in a lane but you choose to keep the lane empty then the opposing player picks up extra card(s). The Icongnito cards do not apply to this rule, i.e. you can leave a lane empty if you have an incognito card but no other card that can go into that lane without aquiring a penalty. The reasoning for the penalty can be seen in the next rule.

7. If it is an attack phase then the player clicks a valid card, then one of the five stat buttons, then an opposing lane. If the player's stat is higher than the stat in the enemy lane chosen then the enemy loses their card in their lane. The player loses their card if their stat is lower than the enemy stat. If the stat is tied nothing happens. If the opposing lane is empty then the player loses their card.

8. If a player has no cards on the board (excluding the card placing phase) then they lose the game.

9. Every 2 turns each player gets 1 new card from the card pile.

## Sample game

Because Phantrumps can seem a bit daunting with all the rules, I have demonstrated a simple game consisting of 1 turn here:

Player 1's cards can be seen on the left side
![PLAYER1-1](https://user-images.githubusercontent.com/32857511/132941805-1764bfcb-68e4-479e-828e-d23fb7c8f4d5.PNG)


Player 2's screen is the exact same as Player 1's screen except with different cards.
![PLAYER2-1](https://user-images.githubusercontent.com/32857511/132941809-4156e2f8-e192-4ef0-81b1-deeb5689ceb5.PNG)


Player 1 has placed down 2 cards on the board and clicked the ready button. Now the phase has changed to Waiting as the game is waiting for Player 2 to click ready.
![PLAYER1-2](https://user-images.githubusercontent.com/32857511/132941854-29b1e936-2860-4dfa-8986-8a2f34a05815.PNG)


Player 2 has placed down 2 cards on the board and also clicked the ready button. Note that an Icognito card could have been placed down in any of the 3 lanes. In this case Player 2 choose to put it in the Terra lane. Once both Players are ready the phase switches to Attacking for Player 1 and Defending for Player 2.
![PLAYER2-2](https://user-images.githubusercontent.com/32857511/132941858-5591f2e2-5651-4ef2-843e-728466b71f8e.PNG)


Player 1 has clicked on the Qiggly card (which can be seen be the fact it is larger) and then clicked on the Intelligence button (second button from the left). Now all of Player 2's lanes have lit up red signifying an ability for Player 1 to attack any of them.
![PLAYER1-3](https://user-images.githubusercontent.com/32857511/132941863-d972c7f6-1160-4bf2-bf79-bd45ea023fca.PNG)


Player 1 attacked into Aerial - an lane Player 2 left empty. Thus because no card is there Player 1 lost the Qiggly card.
![PLAYER2-3](https://user-images.githubusercontent.com/32857511/132941876-bb9ac7cc-b690-43bd-bd1e-138e352276d7.PNG)


Player 2 then attacked with the Mosbie card into Aerial with Agility. Player 1 had their final card there - Spakie. As Mosbie's agility was higher than Spakie's agility, Player 2 won. Because Player 1 has no cards left on the board Player 2 wins the game.
![PLAYER-2-4](https://user-images.githubusercontent.com/32857511/132941873-7e2dca5a-37e8-4248-b1ab-ecb6613e6068.PNG)


## About the game

SFML is the graphics library used with this project. SFML simply adds the ability to easily create a window and draw textures to that window. 

Phantrumps is written with C format and syntax in the C++ language (excluding the use of new and delete in lieu of malloc and free, and strings to use with sf::Text). The reason for this is the graphics library SFML relies on C++ to function. I also wanted the language and syntax to be consistent and since I was far more comfortable in C than C++ I opted to not use the few C++ features I knew such as vectors and maps and instead used C structures such as Linked Lists.

Additionally, because the game is fairly complex, there are possibly edge cases that may causes issues/crashes. Thus in the file of the host folder to a file called transcript.txt that will generate all moves that happened during a game, so that game can be recreated to search for the issue. This will only be generated after a game has stared.
