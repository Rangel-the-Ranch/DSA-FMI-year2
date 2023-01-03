#pragma once

#include<list>
#include<iterator>
#include<iostream>
#include <fstream>

#include"../Box/Box.h"

class BoxList{
    public:
        BoxList();
        BoxList(const char* file);


        void clear();
        void inputFile(const char* file);
        void printList()const;

    private:
        static const bool BORDER = true;

        std::list<Box> m_List;

        Box* getPtrByName(const std::string& name);

        std::string getWord(std::ifstream& iFile)const;
        unsigned int getNumber(std::ifstream& iFile)const;

        void moveLineDown(std::ifstream& iFile)const;
        void skipToInsides(std::ifstream& iFile)const;
        void skipWord(std::ifstream& iFile)const;


        void addBox(Box& newBox);
        void addBox(const std::string& newBoxName);
        void addAllBoxes(std::ifstream& iFile);
        void addSouveniers(std::ifstream& iFile, Box& toAdd);
        void addInsides(std::ifstream& iFile);

        bool clearUpRes();
        bool clearBigBoxes();
};