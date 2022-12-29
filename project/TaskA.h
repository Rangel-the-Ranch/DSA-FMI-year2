#pragma once

#include<string>
#include"SkipList.hpp"

class TaskA{
    public:
        TaskA();
    private:
        static const size_t MAX_INPUT_SIZE;
        SkipList<std::string> m_List;
        size_t m_StationsCount;

        void getStationsCount();
        void getStations();

};

