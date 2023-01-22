// Stage.cpp
// Stage class implementation

#include "Stage.h"
#include <iostream>

/*--------------------------- CONSTRUTORES ---------------------------*/
Stage::Stage()
{
    name = -1;
    goal = NULL;
    past = NULL;
    future = NULL;
}

Stage::Stage(int n)
{
    name = n;
    goal = NULL;
    past = NULL;
    future = NULL;
}

/*------------------------ METODOS: GET E SET ------------------------*/
int Stage::getName()
{
    return name;
}

Stage* Stage::getGoal()
{
    return goal;
}

Stage* Stage::getPast()
{
    return past;
}

Stage* Stage::getFuture()
{
    return future;
}

void Stage::setName(int n)
{
    name = n;
}

void Stage::setGoal(Stage* destination)
{
    goal = destination;
}

void Stage::setPast(Stage* destination)
{
    past = destination;
}

void Stage::setFuture(Stage* destination)
{
    future = destination;
}