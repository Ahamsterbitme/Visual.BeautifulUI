/**
 * @file vbui.h
 * @brief Simpleification GTKMM4.0 writing method | 简单的简化GTKMM4.0的繁琐写法
 * @author KwzDEV
 * @date 2025
 * @note 因为Linux需要更多的开发者
 */

#pragma once

#include "gtkmm/widget.h"
#include <functional>
#include <string>
#include <iostream>
#include <gtkmm/window.h>
#include <gtkmm/button.h>
#include <gtkmm/label.h>
#include <gtkmm/application.h>
#include <gtkmm/entry.h>
#include <gtkmm/box.h>
#include <sigc++/sigc++.h>

namespace Vbui{
    class config {
        public:
            static inline std::string assetsPath = "assets/";
            static inline std::string stylePath = "assets/style/css/";
            static inline std::string picturePath = "assets/Picture/";
            static void SetAssestPath(const std::string& Newpath) {
                assetsPath = Newpath;
            }
    };

    //creat new widows class method
    class CreatAPPmethod{
        private:
         std::string APPID;
         int width;
         int height;
         int margin;
         std::function<Gtk::Widget*()> content_callback;
         std::string AppTitle;
         
        public:
            CreatAPPmethod(const std::string &id , const std::string title , int margin = 20 , 
                int width = 1000 , int height = 500)
                : APPID(id) , AppTitle(title) , width(width) , height(height) , 
                margin(margin)
                {
                    std::cout << "Creat New APP ->" << APPID << std::endl;
                }
                void setContent (std::function<Gtk::Widget*()> callback){
                    content_callback = callback;
                }
                void Run(){
                    auto NewAPP = Gtk::Application::create(APPID);
                    static auto window = new Gtk::Window;
                    window -> set_default_size(width,height);
                    window -> set_title(AppTitle);
                    window -> set_margin(margin);

                    NewAPP -> signal_activate().connect([this](){
                        if (content_callback){
                            auto content = content_callback();
                            if (content){
                                window -> set_child(*content);
                            }
                        }
                        window -> show();
                        std::cout << "Window Creat Success" << std::endl;  
                        std::cout << APPID << " APP READY! 💖" << std::endl;
                        std::cout << "Thank you for starting!" << std::endl;
                        std::cout << "My goal is to give the Linux 🐧 community more apps" << std::endl;
        
                    });
                    NewAPP -> hold();
                    NewAPP -> run();
                }
           };
        }