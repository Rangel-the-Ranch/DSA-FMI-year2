#include"BoxList.h"

BoxList::BoxList(){

}
BoxList::BoxList(const char* file){
    inputFile(file);
    clear();
}

void BoxList::addBox(Box& newBox){
    m_List.push_back(newBox);
}
void BoxList::addBox(const std::string& newBoxName){
    m_List.push_back(Box(newBoxName));
}

bool BoxList::clearUpRes(){ 
    if(m_List.empty()){
        return false;
    }
    for(auto &itr : m_List){
        size_t insideCount = itr.getInsideBoxCount();
        for(size_t i=0; i<insideCount;i++){
            
            if(itr.getBox(i).shoudRemove()){
                itr += itr.getBox(i);
                
                Box toDelete = itr.getBox(i);
                m_List.remove(toDelete);
                
                itr.removeBox(toDelete);
                return true;
            }
        }
    }
    return false;
}
bool BoxList::clearBigBoxes(){
    if(m_List.empty()){
        return false;
    }
    for(auto &itr : m_List){
        if(itr.shoudRemove()){
            if(itr.getInsideBoxCount() == 0){
                m_List.remove(itr);
                return true;
            }else{
                std::string temp = itr.getName();
                itr = itr.getBox(0);
                itr.setName(temp);
                temp = itr.getBox(0).getName();
                
                Box toDelete = itr.getBox(0);
                m_List.remove(toDelete);
                
                itr.removeBox(toDelete);

                itr.setName(temp);
                return true;
            }
        }
    }
    return false;
}

void BoxList::clear(){
    while(clearUpRes()){
    }
    while(clearBigBoxes()){
    }

}


std::string BoxList::getWord(std::ifstream& iFile)const{
    std::string result;
    for(char sym = iFile.get(); !(sym == ' ' || sym == '\n'|| sym == '\0' || sym == '\f' ) ; sym = iFile.get()  ){
        result += sym;
        if( iFile.eof() ){
            return result;
        }
    }
    return result;
}
void BoxList::skipWord(std::ifstream& iFile)const{
    if( iFile.eof() ){
        return;
    }
    for(char sym = iFile.get(); !(sym == ' ' || sym == '\n' || sym == '\0' || sym == '\f') ; sym = iFile.get()  ){
        if( iFile.eof() ){
            return;
        }
    } 
}
unsigned int BoxList::getNumber(std::ifstream& iFile)const{
    return stoi(getWord(iFile));
}


void BoxList::moveLineDown(std::ifstream& iFile)const{
    
    if( iFile.eof() ){
        return;
    }

    for(char sym = iFile.get();  sym != '\n' ; sym = iFile.get()  ){
        if( iFile.eof() ){
            return;
        }
    }
}

void BoxList::inputFile(const char* file){
    std::ifstream iFile(file);
    if( !iFile.is_open()){
        return;
    }
    
    addAllBoxes(iFile);
    iFile.close();

    std::ifstream file2(file);
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    addInsides(file2);
    file2.close();
}

void BoxList::addAllBoxes(std::ifstream& iFile){
    iFile.seekg(std::ios::beg);
    const size_t boxCount = getNumber(iFile);
    for(size_t i = 0; i<boxCount; i++){
        Box toAdd(getWord(iFile));
        addSouveniers(iFile, toAdd);
        addBox(toAdd);
        moveLineDown(iFile);
    }
} 
void BoxList::addSouveniers(std::ifstream& iFile, Box& toAdd){
    const size_t souvenierCount = getNumber(iFile);
    for(size_t i=0; i<souvenierCount; i++){
        std::string name = getWord(iFile);
        toAdd.addSouvenier(name);
    }
} 
void BoxList::printList()const{
    if(!m_List.empty()){
        if(BORDER){
            std::cout<<"##############################################################################"<<std::endl;
        }
        for (auto const &itr: m_List) {
            itr.print();
        }
        if(BORDER){
            std::cout<<"##############################################################################"<<std::endl;
        }
    }
}
Box* BoxList::getPtrByName(const std::string& name){
    for(auto &i: m_List){
        if(i.getName() == name){
            return &i;
        }
    }
    return nullptr;
}

void BoxList::skipToInsides(std::ifstream& iFile)const{
    skipWord(iFile);
    const size_t souvenierCount = getNumber(iFile);
    for(size_t i=0 ;i<souvenierCount; i++){
        skipWord(iFile);
    }
}

void BoxList::addInsides(std::ifstream& iFile){
    skipWord(iFile);
    for (auto &i: m_List) {
        skipToInsides(iFile);
        const size_t insidesCount = getNumber(iFile);
        for(size_t j=0; j<insidesCount; j++){

            Box* toAdd = getPtrByName( getWord(iFile) );
            i.addBox( toAdd );
        }
    }
}

  