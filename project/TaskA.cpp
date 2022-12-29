#include"TaskA.h"

TaskA::TaskA(){
    getStationsCount();

}

void TaskA::getStationsCount(){
    int input;
    std::cin>>input;
    if(input < 0){
        input *= -1;
    }
    m_StationsCount = input;
}
void TaskA::getStations(){
    for(size_t i=0; i<m_StationsCount; i++){
        
    }
}