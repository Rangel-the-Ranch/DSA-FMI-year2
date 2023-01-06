#include"TaskA.h"

void TaskA::printList()const{
    m_List.print();
}

void TaskA::hardCodeInput(){
    m_SkipCout = 9;
    m_List.pushBack("Sofia");
    m_List.pushBack("Pazardjik");
    m_List.pushBack("Plovdiv");
    m_List.pushBack("Dimitrovgrad");
    m_List.pushBack("StaraZagora");
    m_List.pushBack("NovaZagora");
    m_List.pushBack("Yambol");
    m_List.pushBack("Karnobat");
    m_List.pushBack("Burgas");
    m_SkipCout = 5;
    addSkip("Sofia","Plovdiv");
    addSkip("Plovdiv","NovaZagora");
    addSkip("Dimitrovgrad","NovaZagora");
    addSkip("StaraZagora","Yambol");
    addSkip("NovaZagora","Burgas");
    m_reqCityCount = 3;
    m_ReqStations.push("Plovdiv");
    m_ReqStations.push("StaraZagora");
    m_ReqStations.push("Yambol");
}

void TaskA::addSkip(const std::string& from, const std::string& to){
    SkipList<std::string>::Iterator A(m_List.begin());
    SkipList<std::string>::Iterator B(m_List.begin());
    getStationFromName(A,from);
    getStationFromName(B,to);
    A.addSkip(B);
}

void TaskA::printPath()const{
    size_t pathSize = m_Path.size();
    for(size_t i=0; i<pathSize; i++){
        std::cout<<m_Path[i];
        if(i != pathSize-1){
            std::cout<<" -> ";
        }
    }
    std::cout<<std::endl;
}

void TaskA::getInput(){
    getStationsCount();
    getStations();
    getSkipsCount();
    getSkips();
    getReqCityCount();
}

void TaskA::getPath(){
    std::vector<std::string> res;
    SkipList<std::string>::Iterator from(m_List.begin());
    SkipList<std::string>::Iterator to(m_List.begin());
    std::string last = m_ReqStations.front();
    getStationFromName(to,last);
    m_ReqStations.pop();
    for(size_t i=1; i<=m_reqCityCount; i++){
        std::vector<std::string> temp = getPathBetweenAandB(from,to,{});
        reverseVector(temp);
        while(temp.size()){
            res.push_back(temp[temp.size()-1]);
            temp.pop_back();
        }
        if(i != m_reqCityCount){
            from = to;
            last = m_ReqStations.front();
            getStationFromName(to,last);
            m_ReqStations.pop();
        }else{
            if(last != m_List.peekBack() ){
                from = to;
                getStationFromName( to,m_List.peekBack() );
                std::vector<std::string> temp = getPathBetweenAandB(from,to,{});
                reverseVector(temp);
                while(temp.size()){
                    res.push_back(temp[temp.size()-1]);
                    temp.pop_back();
                }
                res.push_back(m_List.peekBack());

            }else{
                res.push_back(last);
            }
        }
    }
    m_Path = res;
}

void TaskA::reverseVector(std::vector<std::string>& vector)const{
    const size_t vectorSize = vector.size();
    const size_t vectorSize2 = vectorSize/2;

    for (size_t i = 0; i < vectorSize2; i++) {
        std::swap(vector[i], vector[vectorSize - i - 1]);
    }
}

void TaskA::getStationFromName(SkipList<std::string>::Iterator& Itr, std::string name)const{
    if(Itr.isNull()){
        return;
    }else if(*Itr == name){
        return;
    }else{
        ++Itr;
        getStationFromName(Itr,name);
    }
}

std::vector<std::string> TaskA::getPathBetweenAandB(SkipList<std::string>::Iterator A, SkipList<std::string>::Iterator B, std::vector<std::string> path)const{
    if(A == B){
        return path;
    }
    if(A.isAtEnd()){
        return {};
    }
    path.push_back(*A);
    
    if( ! A.haveSkip() ){
        SkipList<std::string>::Iterator itrN = A;
        ++itrN;
        std::vector<std::string> pathNext = getPathBetweenAandB(itrN,B,path);
        if( pathNext.size() == 0 ){
            return {};
        }else{
            return pathNext;
        }
    }
    SkipList<std::string>::Iterator itrN = A;
    SkipList<std::string>::Iterator itrS = A;
    ++itrN;
    itrS.skip();
    std::vector<std::string> pathNext = getPathBetweenAandB(itrN,B,path);
    std::vector<std::string> pathSkip = getPathBetweenAandB(itrS, B,path);
    if(pathNext.size() == 0 && pathSkip.size() == 0 ){
        return {};
    }else if(pathNext.size() == 0){
        return pathSkip;
    }else if(pathSkip.size() == 0){
        return pathNext;
    }else{
        if(pathNext.size() < pathSkip.size()){
            return pathNext;
        }else{
            return pathSkip;
        }
    }
}



void TaskA::getStationsCount(){
    std::cout<<"Stations count: ";
    int input;
    std::cin>>input;
    if(input < 0){
        input *= -1;
    }
    m_StationsCount = input;
    std::cout<<std::endl;
}
void TaskA::getStations(){
    std::cout<<"Stations: ";
    for(size_t i=0; i<m_StationsCount; i++){
        std::string input;
        std::cin>>input;
        m_List.pushBack(input);
    }
}
void TaskA::getSkipsCount(){
    std::cout<<"Skips count: ";
    int input;
    std::cin>>input;
    if(input < 0){
        input *= -1;
    }
    m_SkipCout = input;
}
void TaskA::getSkips(){
    for(size_t i=0 ;i< m_SkipCout; i++){
        std::string stationA;
        std::string stationB;
        std::cin>>stationA;
        std::cin>>stationB;
        for(SkipList<std::string>::Iterator itr = m_List.begin(); !itr.isNull(); ++itr ){
            if(*itr == stationA){
                for(SkipList<std::string>::Iterator itr2 = itr; !itr2.isNull(); ++itr2 ){
                    if(*itr2 == stationB){
                        itr.addSkip(itr2);
                        break;
                    }
                }
                break;
            }
            
        }
    }
}
void TaskA::getReqCityCount(){
    std::cout<<"Requred city count: ";
    int input;
    std::cin>>input;
    if(input < 0){
        input *= -1;
    }
    m_reqCityCount = input;
    //std::cout<<std::endl;
}
void TaskA::getReqStations(){
    std::cout<<"Requred cityes: ";
    for(size_t i=0; i<m_reqCityCount; i++){
        std::string input;
        std::cin>>input;
        m_ReqStations.push(input);
    }
}
