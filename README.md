## Task

#### Computer retro game

We consider a computer game in which a player controls a basket consisting of two blue pixels placed side by side in horizontal direction. He uses this basket to catch falling single-pixel eggs. The pixels of the eggs are orange. The other pixels in the game are background pixels and have a different color from the basket and eggs. The time in the game is dicreet. In one time unit (stroke), the eggs are moved one pixel down. During the turn, the player can move the basket one pixel to the right or left, but only if none of the pixels of the basket leaves the rectangular playing area by moving. The player can also leave the position of the basket unchanged. If the egg reaches the bottom row and its position coincides with the position of one of the blue pixels in the basket, it is caught. In the subsequent turn, the eggs on the bottom line disappear from the game, whether they were caught or not. For each egg caught, the player gets one point.

<p align="center">
  <img src="pictures/example.png" width="200" title="example">
</p>

#### Input (example)

`5 10`  <sub> width of game field & number of eggs </sub>  
`2 1`  
`1 4`  
`5 4`  
`4 5`  
`5 7`  
`4 7`  
`2 7`  
`2 9`  
`1 10`  
`5 10`  <sub> coordinates [column & height] of each egg </sub>

#### Output (example)

`7` <sub> maximum of score player can achieve </sub>




## Solution



