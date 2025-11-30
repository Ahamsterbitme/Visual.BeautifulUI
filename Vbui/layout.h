/**
 * @file layout.h
 * @brief Simpleification GTKMM4.0 Box Layout writing method | 简单的简化GTKMM4.0的 盒子布局 繁琐写法
 * @author KwzDEV
 * @date 2025
 */


#pragma once

#include "gtkmm/enums.h"
#include "gtkmm/object.h"
#include <gtkmm/grid.h>
#include <gtkmm/widget.h>
#include <gtkmm/box.h>
#include <vector>

 namespace Vbui{
   /*
   this is settings block layout
   */
    inline Gtk::Box* BlockLayout(std::vector<Gtk::Widget*> children , int number = 1 , int margin = 1){
      if (number <= 1){
          auto BlockBox =  Gtk::make_managed<Gtk::Box>(Gtk::Orientation::VERTICAL,number);
         BlockBox -> set_margin(margin);
         for (auto child : children){
            BlockBox->append(*child);
         }
         return BlockBox;
      }else {
         auto manyBlockBox =  Gtk::make_managed<Gtk::Box>(Gtk::Orientation::VERTICAL,number);
         manyBlockBox -> set_margin(margin);
         for (auto child:children){
            manyBlockBox->append(*child);
         }
         return manyBlockBox;
      }
   }
   /*
   this is settings flex layout
   */
   inline Gtk::Box* FlexLayout(std::vector<Gtk::Widget*> children , int number = 1 , int margin = 1){
      if (number <= 1){
         auto FlexBox = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL,5);
         FlexBox -> set_margin(margin);
         for (auto child: children) {
            FlexBox -> append(*child);
         }
         return FlexBox;
      }else {
         auto manyFlexBox =Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL,number);
         manyFlexBox -> set_margin(margin);
         for (auto child: children){
            manyFlexBox -> append(*child);
         }
         return manyFlexBox;
      }
   }
}
