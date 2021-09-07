# Phantrumps

Phantrumps is a card game I created with friends in 2017. For the CSE project I wanted to try and turn this fun card game into an actual computer game. To play you need 2 players on two different computers, one will run the host exe and one will run the client exe. The game connects on Port 54000 so the host must ensure this Port is forwarded before the client can connect to the host's IP.

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

Because Phantrumps can seem a bit daunting with all the rules, I have demonstrated a simple game consisting of x turns here:

## About the game

SFML is the graphics library used with this project. SFML simply adds the ability to easily create a window and draw textures to that window.

Phantrumps is written with C format and syntax in C++ (excluding the use of new and delete in lieu of malloc and free, and strings to use with sf::Text). The reason for this is the graphics library SFML relies on C++ to function. I also wanted the language to be consistent and since I was far more comfortable in C than C++ I opted to not use the few C++ features I new such as vectors and maps and instead used C structures such as Linked Lists.

Additionally, because the game is fairly complex, there are almost certaintly edge cases that may causes issues/crashes. Thus in the file of the host folder to a file called transcript.txt that will generate all moves that happened during a game, so that game can be recreated to search for the issue.
