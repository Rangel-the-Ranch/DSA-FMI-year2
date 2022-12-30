#pragma once

#include<string>
#include<stack>
#include<vector>

class Box{
    public:
        Box();
        Box(const std::string& newName);

        std::string getName()const;
        void setName(const std::string& newName);

        void addSouvenier(const std::string& newSouvenier);
        std::string getSouvenier()const;
        void removeSouvenier();
        unsigned int getSouvenierCount()const;

        void addBox(Box*& newBox);
        Box* getBox(unsigned int index);
        void removeBox();


    private:
        std::stack<std::string> m_Souvenirs;
        std::vector<Box*> m_InsideBoxes;
        std::string m_Name;

};