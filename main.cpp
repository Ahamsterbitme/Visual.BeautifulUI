#include "Vbui/vbui.h"
#include "Vbui/layout.h"
#include "Vbui/text.h"
#include "Vbui/button.h"
#include "gtkmm/widget.h"
#include "Vbui/image.h"
using namespace Gtk;
using namespace std;
using namespace Vbui;

int main() {
    CreatAPPmethod app("Mya.app.com", "TestApp", 1, 1000 , 200); 
    app.setContent([]() -> Widget* {  
    // this is settings text var 
    static auto NewpictureVar = ReactivePicture::CreatNewsrcVar("1.png", 120, 120, 10);
    static auto NewtextVar = Reactivetext::CreatTextVar("hello world", 20);
        return BlockLayout({
            NewtextVar->addWidget(),
            NewpictureVar->addWidget(),
            Text("hello world this is my app", 20),
            DefaultButton(30, 40, "hello world", 30, false, false),
            ClickButton(30, 50, "Click Me", []() {  
                NewtextVar->setText("hai");
            }, 20, false, false),
                ClickButton(20, 20, "Click Next Picture", [](){
                    NewpictureVar->setPicutreSRC("2.png");
                })
        }, 20, 10);
    });

    app.Run();
    return 0;
}