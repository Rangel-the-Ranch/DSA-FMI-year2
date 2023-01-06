#pragma once

#include<string>
#include<queue>
#include<vector>
#include"SkipList.hpp"

class TaskA{
    public:

        void getPath();

        void getInput();
        void hardCodeInput();

        void printPath()const;
        void printList()const;

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

        void addSkip(const std::string& from, const std::string& to);

        std::vector<std::string> getPathBetweenAandB(SkipList<std::string>::Iterator A, SkipList<std::string>::Iterator B,  std::vector<std::string> path)const;
        void getStationFromName(SkipList<std::string>::Iterator& Itr, std::string name)const;

        void reverseVector(std::vector<std::string>& vector)const; 
};

