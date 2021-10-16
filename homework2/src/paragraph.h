#pragma once
#include <typeinfo>
#include <string>
#include <list>
#include "article.h"
#include "list_item.h"
#include "text.h"

class Paragraph : public Article {
  public:
    Paragraph(int level, std::string text):_level(level) ,_text(" "+text) {
        if( _level >= 1 && _level <= 6 )
            _text = std::string(_level ,'#')+ _text + "\n";
        else
            throw std::string("A paragraph can only have a level between one to six");
    }

    ~Paragraph() {}

    std::string getText() const override {       
        std::string res = _text;
        if(flag == true){
            for(Article* n: items)
                res += n->getText() + "\n";
            res.pop_back();  
        }
        else return res;
    }

    int getLevel() const override {
        return _level;
    }

    void add(Article* content) override {
        if(typeid(*content) == typeid(Paragraph)){
            int p_level = content->getLevel();
            if(p_level <= _level)
                throw std::string("New paragraphs have to be higher level than the previous ones");
            else{
                items.push_back(content);
                flag=1;
            }
        }
        else{
            items.push_back(content);
            flag=1;
        }
    }

private:
    int _level;
    std::string _text;
    std::list<Article*> items;
    bool flag=0;
};