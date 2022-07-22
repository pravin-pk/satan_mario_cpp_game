#include "Render.h"

extern int moveDownFlag, level, upInAir, diamondCollected, moveRight, moveLeft, gameOverFlag;

void platformCollision(Human &human, Platforms &platform)
{   
    // (human.bottomRight.x - human.topLeft.x) is the size of the human.
    bool collideX = ( human.bottomRight.x >= platform.bottomLeft.x+5 && platform.bottomRight.x-5 >= human.bottomLeft.x ); 

    bool collideY = ( human.bottomRight.y >= platform.bottomLeft.y && platform.bottomRight.y >= human.bottomLeft.y );

    bool collided = collideX && collideY;
    if(collided)
    {
        moveDownFlag = 0;
        // std::cout<<collided<<" - omg\t";
    }
    else
        moveDownFlag = 1;
}

void ladderCollision(Human &human , Ladder &ladder)
{
    bool collideX = ( human.bottomLeft.x >= ladder.bottomLeft.x && human.bottomRight.x <= ladder.bottomRight.x ); 
    bool collideY = ( human.bottomLeft.y <= ladder.topLeft.y+51 && ladder.bottomLeft.y >= human.bottomLeft.y+51 );
    bool collided = collideX && collideY;
    if(collideX && human.bottomLeft.y > 900|| human.bottomLeft.y < 940 && human.bottomLeft.y >= 440)
    {
        moveDownFlag = 1;
        level = 2;
    }
    else if (collideX && human.bottomLeft.y > 400 || human.bottomLeft.y < 440 && human.bottomLeft.y >= 0)
    {
        moveDownFlag = 2;
        level = 3;
    }
    else
    {
        moveDownFlag = 0;
        level = 1;
    } 
}

void blockCollision(Human &human, Blocks &block)
{
    bool collideX = human.bottomRight.x >= block.bottomLeft.x && block.bottomLeft.x+10 >= human.bottomLeft.x;
    bool collideY = human.bottomRight.y >= block.bottomLeft.y && block.bottomLeft.y+30 >= human.bottomLeft.y;

    if(collideX & collideY){
        upInAir = 0;
    }
    else{
        upInAir = 1;
    }

    //if(collideX)
    //{
    //    moveRight = 0;
    //}
    //else{
    //    moveRight = 1;
    //}
}

void diamondCollision(Human &human, Diamonds &diamond0)
{
    bool collideX = human.bottomRight.x >= diamond0.bottom.x-5;
    bool collideY = diamond0.bottom.y >= human.bottomRight.y && diamond0.top.y <= human.topRight.y;

    if(collideX & collideY){
        // std::cout<<"diamond is destroyed";
        diamond0.enabled = 0;
        diamondCollected += 1;
    }
}

void ThornCollision(Human &human, Thorns &Thorn)
{
    //bool collideX = human.bottomLeft.x <= 980 && human.bottomLeft.x >= 800;
    bool collideY = human.bottomLeft.y <= 50;
    //bool collided = collideX && collideY;
    if(collideY)
    {
        std::cout<<"You died";
        gameOverFlag = 1;
    }
}