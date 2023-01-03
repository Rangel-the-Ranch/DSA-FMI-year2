#pragma once

#include<string>
#include<vector>
#include<iostream>

class Box{
    public:
        Box();
        Box(const std::string& newName);

        std::string getName()const;
        void setName(const std::string& newName);

        void addSouvenier(const std::string& newSouvenier);
        std::string getSouvenier(const unsigned int index)const;
        std::vector<std::string> getAllSouveniers()const;
        void removeSouvenier();
        unsigned int getSouvenierCount()const;

        void addBox(Box* newBox);
        Box& getBox(unsigned int index)const;
        unsigned int getInsideBoxCount()const;
        void removeBox(const Box& toDelete);

        bool shoudRemove()const;

        void print()const;

        Box& operator+=(Box& other);
        bool operator==(const Box& other);

    private:
        std::vector<std::string> m_Souvenirs;
        std::vector<Box*> m_InsideBoxes;
        std::string m_Name;

};