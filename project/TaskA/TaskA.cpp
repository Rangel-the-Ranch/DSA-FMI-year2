#include"TaskA.h"

TaskA::TaskA(){
    getStationsCount();
    getStations();
    getSkipsCount();
    getSkips();
    getReqCityCount();

    m_List.print();
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
    //std::cout<<std::endl;
}
void TaskA::getSkipsCount(){
    std::cout<<"Skips count: ";
    int input;
    std::cin>>input;
    if(input < 0){
        input *= -1;
    }
    m_SkipCout = input;
    //std::cout<<std::endl;
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
