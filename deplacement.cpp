#include"deplacement.h"
#include"acteur.h"
#include <memory>

deplacement::deplacement(){}

void deplacement::deplaceRight(std::unique_ptr<acteur> A){
    A->changePosition(A->position().x()+1,A->position().y());
}

void deplacement::deplaceLeft(std::unique_ptr<acteur> A){
     A->changePosition(A->position().x()-1,A->position().y());
}

void deplacement::deplaceUp(std::unique_ptr<acteur> A){
    A->changePosition(A->position().x(),A->position().y()-1);
}

void deplacement::deplaceDown(std::unique_ptr<acteur> A){
    A->changePosition(A->position().x(),A->position().y()+1);
}

void deplacement::deplaceRightUp(std::unique_ptr<acteur> A){
     A->changePosition(A->position().x()+1,A->position().y()-1);
}

void deplacement::deplaceRightDown(std::unique_ptr<acteur> A){
    A->changePosition(A->position().x()+1,A->position().y()+1);
}

void deplacement::deplaceLeftUp(std::unique_ptr<acteur> A){
    A->changePosition(A->position().x()-1,A->position().y()-1);
}

void deplacement::deplaceLeftDown(std::unique_ptr<acteur> A){
    A->changePosition(A->position().x()-1,A->position().y()+1);
}






