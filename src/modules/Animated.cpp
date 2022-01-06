#include <iostream>
#include "Animated.h"

void Animated::animate(sf::Sprite &sprite, int animRow, int maxFrameNumber) {
     currFrame = sprite.getTextureRect();
     int x = currFrame.width * (currFrameNumber-1);
     int y = currFrame.height * (animRow-1);

     if (animClock.getElapsedTime().asSeconds() >= frameIntervalTime)
     {
         //Next frame
         currFrameNumber++;
         if (currFrameNumber <= maxFrameNumber) {
             x += currFrame.width;
         }
         else {
             x = 0;
             currFrameNumber = 1;
         }

         currFrame = sf::IntRect(x,y,currFrame.width,currFrame.height);
         sprite.setTextureRect(currFrame);

         //Restart clock
         animClock.restart();
     }


}
