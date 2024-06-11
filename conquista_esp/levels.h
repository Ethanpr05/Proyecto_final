#ifndef LEVELS_H
#define LEVELS_H

#include "gold.h"
#include "player.h"
#include "enemy.h"
#include "ground.h"
#include "seatrap.h"
#include "ship.h"
#include "trap.h"
#include "qcolor.h"
#include "seatrap.h"
#include "ship.h"
#include "qgraphicsview.h"

void level1(QGraphicsScene *scene, QGraphicsView *view, unsigned short &level);
void level2(QGraphicsScene *scene, QGraphicsView *view, unsigned short &level);
void level3(QGraphicsScene *scene, QGraphicsView *view, unsigned short &level);
void changeLevel(QGraphicsScene *scene, QGraphicsView *view, unsigned short int &whichlvl);

#endif // LEVELS_H
