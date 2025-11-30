/**
 * @file text.h
 * @brief Simpleification GTKMM4.0 Label Text writing method | 简单的简化GTKMM4.0的Label Text 的繁琐写法
 * @author KwzDEV
 * @date 2025
 */

 #pragma once

 #include "gtkmm/object.h"
 #include "gtkmm/widget.h"
 #include <gtkmm/label.h>
 #include <memory>
 #include <string>

 namespace Vbui {
    /*
    ========== return gtkmm method ===========
    */

    inline Gtk::Label* Text(
        const std::string text,
        int margin
    ){
        auto newText = Gtk::make_managed<Gtk::Label>();
        newText->set_text(text);
        return newText;
    }

    inline Gtk::Label* HtmlText(
        const std::string html,
        int margin
    ){
        auto newHtmlText = Gtk::make_managed<Gtk::Label>();
        newHtmlText->set_markup(html);
        newHtmlText->set_margin(margin);

        return newHtmlText;
    }

    /*                            
    ========== class model method ===========
    */

    class Text{
        std::string text;
        int margin;
        public:
            Text (std::string t , int margin): text(t) , margin(margin){}
            Gtk::Label *Builder(){
                auto text_controller = Gtk::make_managed<Gtk::Label>();
                text_controller -> set_text(text);
                text_controller -> set_margin(margin);
                
                return text_controller;
            }
    };
    
    class HtmlText{
        std::string html;
        public:
            HtmlText (std::string ht): html(ht){}
            Gtk::Label *Builder(){
                auto NewHtmltext = Gtk::make_managed<Gtk::Label>();
                NewHtmltext -> set_markup(html);
                return NewHtmltext; 
            }
    };

    class Reactivetext{
        private:
            std::shared_ptr<std::string> textPtr;
            Gtk::Label* newLabel;
            public:
                Reactivetext(const std::string& InitText, int InitMargin)
                :textPtr(std::make_shared<std::string>(InitText)){
                    newLabel = new Gtk::Label;
                    newLabel->set_label(*textPtr);
                    newLabel->set_margin(InitMargin);
                }
                void update(){
                    newLabel->set_label(textPtr->c_str());
                }
                void setText(const std::string &NewText){
                    *textPtr = NewText;
                    update();
                }
                Gtk::Widget* addWidget() {return newLabel;}
                static std::shared_ptr<Reactivetext>CreatTextVar(const std::string& InitText , int initMargin = 20){
                    return std::make_shared<Reactivetext>(InitText , initMargin);
                }
    };
 }