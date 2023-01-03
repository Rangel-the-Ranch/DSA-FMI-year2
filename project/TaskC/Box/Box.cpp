#include"Box.h"

std::string Box::getName()const{
    return m_Name;
}
void Box::setName(const std::string& newName){
    m_Name = newName;
}
void Box::addSouvenier(const std::string& newSounenier){
    m_Souvenirs.push_back(newSounenier);

}
unsigned int Box::getSouvenierCount()const{
    return m_Souvenirs.size();
}
Box::Box(){
}
Box::Box(const std::string& newName){
    m_Name = newName;
}
std::string Box::getSouvenier(const unsigned int index)const{
    return m_Souvenirs[index];
}
void Box::removeSouvenier(){
    m_Souvenirs.pop_back();
}

void Box::addBox(Box* newBox){
    if(newBox == nullptr){
        return;
    }
    m_InsideBoxes.push_back(newBox);
}

Box& Box::getBox(unsigned int index)const{
    return *m_InsideBoxes[index];
}

void Box::removeBox(const Box& toDelete){
    const size_t insideCount = m_InsideBoxes.size();
    for(size_t i=0; i<insideCount; i++){
        if(m_InsideBoxes[i]->getName() == toDelete.getName()){
            
            m_InsideBoxes.erase(m_InsideBoxes.begin() + i);

            return;
        }
    }
}

bool Box::shoudRemove()const{
    return !m_Souvenirs.size() && (getInsideBoxCount() == 0 || getInsideBoxCount() == 1);
}
std::vector<std::string> Box::getAllSouveniers()const{
    return m_Souvenirs;
}
unsigned int Box::getInsideBoxCount()const{
    return m_InsideBoxes.size();
}

void Box::print()const{
    std::cout<<getName()<<": ";

    const size_t souvenierCount = getSouvenierCount();
    for(size_t i=0; i<souvenierCount; i++){
        std::cout<<getSouvenier(i)<<" ";
    }
    
    const size_t insideBoxCount = getInsideBoxCount();
    
    for(size_t i=0; i<insideBoxCount; i++){
        
        std::cout<<std::endl;
        std::cout<<"  -> ";
        std::cout<<getBox(i).getName();
    }

    std::cout<<std::endl;
}
Box& Box::operator+=(Box& other){
    const size_t inBoxesCount = other.getInsideBoxCount();
    for(size_t i=0; i<inBoxesCount; i++){
        m_InsideBoxes.push_back(&other.getBox(i));
    }
    other.m_InsideBoxes.clear();
    return *this;
}
bool Box::operator==(const Box& other){
    return m_Name == other.getName();
}