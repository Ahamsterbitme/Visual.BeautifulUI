/**
 * @file button.h
 * @brief Simplification GTKMM4.0 Button writing method | 简单的简化GTKMM4.0的Button的繁琐写法
 * @author KwzDEV
 * @date 2025
 */

#pragma once

#include <gtkmm/button.h>
#include <functional>

namespace Vbui {
    
    // Create default button
    inline Gtk::Button* DefaultButton(
        int NewWidth, int NewHeight,
        const std::string& ButtonTitle,
        int ButtonMargin = 0, 
        bool AdaptiveHeight = false,
        bool AdaptiveWidth = false
    ) {
        Gtk::Button* NewDefaultButton = new Gtk::Button();  // 直接创建
        NewDefaultButton->set_size_request(NewWidth, NewHeight);
        NewDefaultButton->set_label(ButtonTitle);
        NewDefaultButton->set_margin(ButtonMargin);
        NewDefaultButton->set_vexpand(AdaptiveHeight); 
        NewDefaultButton->set_hexpand(AdaptiveWidth);   
        
        return NewDefaultButton;
    }
    
    // Create click button with action
    inline Gtk::Button* ClickButton(
        int NewWidth, int NewHeight,
        const std::string& ButtonLabel, 
        std::function<void()> action,
        int margin = 0, 
        bool AdaptiveHeight = false,
        bool AdaptiveWidth = false
    ) {
        Gtk::Button* NewClickButton = new Gtk::Button(); 
        NewClickButton->set_size_request(NewWidth, NewHeight);
        NewClickButton->set_label(ButtonLabel);
        NewClickButton->set_margin(margin);
        NewClickButton->set_vexpand(AdaptiveHeight);
        NewClickButton->set_hexpand(AdaptiveWidth);
        NewClickButton->signal_clicked().connect(action);
        
        return NewClickButton;
    }

    inline Gtk::Button* SimpleButton(
        const std::string& label,
        std::function<void()> onClick = nullptr,
        int margin = 10
    ) {
        Gtk::Button* button = new Gtk::Button(label);
        button->set_margin(margin);
        if (onClick) {
            button->signal_clicked().connect(onClick);
        }
        return button;
    }
}