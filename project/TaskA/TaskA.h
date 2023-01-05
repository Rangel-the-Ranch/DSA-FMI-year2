#pragma once

#include<string>
#include<queue>
#include<list>
#include<vector>
#include"SkipList.hpp"

class TaskA{
    public:
        TaskA();

        void getPath();
        void getInput();
        void printPath()const;


    private:
        SkipList<std::string> m_List;
        std::queue<std::string> m_ReqStations;
        std::vector<std::string> m_Path;
        size_t m_StationsCount = 0;
        size_t m_SkipCout = 0;
        size_t m_reqCityCount = 0;
        

        void getStationsCount();
        void getStations();
        void getSkipsCount();
        void getSkips();
        void getReqCityCount();
        void getReqStations();

        std::vector<std::string> getPathBetweenAandB(SkipList<std::string>::Iterator A, SkipList<std::string>::Iterator B,  std::vector<std::string> path)const;
        void getStationFromName(SkipList<std::string>::Iterator& Itr, std::string name)const;
};

