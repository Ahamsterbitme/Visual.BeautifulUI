/**
 * @file image.h
 * @brief Simpleification GTKMM4.0 Picture Load writing method | 简单的简化GTKMM4.0的 图片加载 的繁琐写法
 * @author KwzDEV
 * @date 2025
 */

 #include "gtkmm/object.h"
 #include "gtkmm/widget.h"
 #include "vbui.h"
 #include <filesystem>
 #include <gtkmm/picture.h>
 #include <memory>
 #include <string>

 namespace Vbui {
    //verify path method
    inline bool VerifyPath (const std::string path) {
        if (std::filesystem::exists(path)){
            return true;
        }
        else {
            return false;
        }
    }

    //this is default picture controller
    class CreatNewImg{
        private:
            std::string filename;
            std::shared_ptr<Gtk::Picture> picture_;
            int margin = 20;
            int height = 100;
            int width = 100;
            bool AdaptiveHeight = false;
            bool AdaptiveWidth = false;

        public:
            CreatNewImg(const std::string &filename_ , int margin_ , int height_ , int width_ , 
                bool AdaptiveHeight = false , bool AdaptiveWidth = false)
                        :filename(filename_) , margin(margin_) , width(width_) , height(height_) , 
                         AdaptiveHeight(AdaptiveHeight) , AdaptiveWidth(AdaptiveWidth)

                        {
                            //this is creat new Picuter
                            static auto path_config = Vbui::config::picturePath;
                            static auto filepath = path_config + filename_;
                            if (std::filesystem::exists(filepath))
                            {
                                //creat new picture
                                picture_ = CreatDefaultPicture(filepath, margin, height, width, 
                                    AdaptiveHeight, AdaptiveWidth);
                            }else{
                                std::cout << "VBUI:[ERROR]this '" << filepath << "'of picture is not existent!" << std::endl;
                                return;
                            }
                        }

                        Gtk::Widget* addWidget(){
                            if (!picture_)
                            {
                                std::cout << "VBUI:[ERROR]:'" << "assets ->" << filename << "not found" << std::endl;
                                return nullptr;
                            }else{
                                return picture_.get();
                            }
                        }

                        private:
                        //this creat funtion
                        std::shared_ptr<Gtk::Picture> CreatDefaultPicture (const std::string path , int margin ,
                             int height , int width , bool AdaptiveHeight , bool AdaptiveWidth){
                                auto pic  = std::make_shared<Gtk::Picture>();
                                pic -> set_size_request(width , height);
                                pic -> set_margin(margin);
                                pic -> set_vexpand(AdaptiveWidth);
                                pic -> set_hexpand(AdaptiveHeight);
                                pic -> set_filename(path);

                                return pic;
                             }
    };


    //This simpleification creat Defaultpicture
    inline Gtk::Widget *NewPicture (
        const std::string &Newfile_name,
        int width,
        int height,
        int margin,
        bool AdaptiveHeight = false,
        bool AdaptiveWidth = false
    ){
        const auto file_path = Vbui::config::picturePath + Newfile_name;
        if (std::filesystem::exists(file_path)){
            //creat new picture
            auto NewPicture = Gtk::make_managed<Gtk::Picture>();
            NewPicture -> set_margin(margin);
            NewPicture -> set_size_request(width , height);
            NewPicture -> set_filename(file_path);
            NewPicture -> set_vexpand(AdaptiveWidth);
            NewPicture -> set_hexpand(AdaptiveHeight);

            return NewPicture;
        }else{
            //return error
            std::cout << "VBUI:[ERROR]" << "assets ->'" << file_path << "'not found !" << std::endl;
            return nullptr; 
        }
    }

    //this is varible picture
    class ReactivePicture{
        private:
            std::shared_ptr<std::string> initSRC;  //this is init_src 
            Gtk::Picture *newPicture;
            int width = 100; int height = 100;
            int margin = 20;
            public:
                ReactivePicture(const std::string &initSRC_ , 
                    int width_ , int height_ , int margin_)
                    : initSRC(std::make_shared<std::string>(initSRC_)),width(width_),
                      height(height_),margin(margin_)
                      {
                        const auto initPath = Vbui::config::picturePath + *initSRC;
                        if (VerifyPath(initPath)){
                            newPicture =  Gtk::make_managed<Gtk::Picture>();
                            newPicture -> set_size_request(width , height);
                            newPicture -> set_margin(margin);
                            newPicture -> set_filename(initPath); 
                        }else {
                            std::cout << "VBUI[ERROR]: assets ->'" << initPath << "' not found!" << std::endl;
                            newPicture = nullptr;
                            return;
                        }
                      }

                      void update(){
                        const auto _newSRC = Vbui::config::picturePath + *initSRC;
                        newPicture -> set_filename(_newSRC);
                      }

                      //this is settings new Src
                      void setPicutreSRC (const std::string newSrc){
                        *initSRC = newSrc;
                        update();
                      }

                      Gtk::Widget* addWidget(){ return newPicture; }

                      //this is creat function
                      static std::shared_ptr<ReactivePicture>CreatNewsrcVar(const std::string& initSRC ,
                          int width_ , int height_ , int margin_)
                         {
                            return std::make_shared<ReactivePicture>(initSRC , width_ , height_ , margin_);
                         }
    };
 }