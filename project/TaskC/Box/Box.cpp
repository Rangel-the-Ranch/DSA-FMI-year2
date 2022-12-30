#include"Box.h"

std::string Box::getName()const{
    return m_Name;
}
void Box::setName(const std::string& newName){
    m_Name = newName;
}
void Box::addSouvenier(const std::string& newSounenier){
    m_Souvenirs.push(newSounenier);

}
unsigned int Box::getSouvenierCount()const{
    return m_Souvenirs.size();
}
Box::Box(){
}
Box::Box(const std::string& newName){
    m_Name = newName;
}
std::string Box::getSouvenier()const{
    return m_Souvenirs.top();
}
void Box::removeSouvenier(){
    m_Souvenirs.pop();
}

void Box::addBox(Box*& newBox){
    m_InsideBoxes.push_back(newBox);
}

Box* Box::getBox(unsigned int index){
    return m_InsideBoxes[index];
}

void Box::removeBox(){
    m_InsideBoxes.pop_back();
}
