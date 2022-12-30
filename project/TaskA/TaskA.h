#pragma once

#include<string>
#include<queue>
#include"SkipList.hpp"

class TaskA{
    public:
        TaskA();
    private:
        SkipList<std::string> m_List;
        std::queue<std::string> m_ReqStations;
        size_t m_StationsCount = 0;
        size_t m_SkipCout = 0;
        size_t m_reqCityCount = 0;


        void getStationsCount();
        void getStations();
        void getSkipsCount();
        void getSkips();
        void getReqCityCount();
        void getReqStations();
};

