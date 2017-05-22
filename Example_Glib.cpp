#include "main.h"

 extern int errno;
 
 void FunctionForDrawText(Display* d, Window w, int s, int WhatLook, int size_n, int x, int y) {
     Glib InFunc;
     std::string texttofunction;
     
     texttofunction = std::to_string(WhatLook);
     InFunc.DrawText(d,w,DefaultGC(d,s), texttofunction.c_str() , 4 , x , y  , DefaultColormap(d,s));
 }

 int main() {
   Display *d;
   Window w;
   XEvent e;
   GC gc;
   Colormap cmap;
std::string texttofunction;
   Glib object;
   GButton b12;
   int Money = 1000;
   int s;
   int x,y;
   int n1 = 0;
///////////////////////////////////////////////
   d = object.OpenDisplay("display");
    object.DefScreen(d,s);
   gc = XDefaultGC(d,s);
    cmap = XDefaultColormap(d,s);
    
   w = XCreateSimpleWindow(d, RootWindow(d, s), 10, 10, 950, 600, 1,
                             XBlackPixel(d, s),  XWhitePixel(d,s));
   object.DeclaringVariables(w,gc,cmap,s);
   XSelectInput(d, w, ExposureMask | KeyPressMask|KeyReleaseMask
                            |FocusChangeMask | ButtonPressMask );
   
XMapWindow(d, w);

while (1) {
XNextEvent(d, &e);

switch (e.type) {
    
case ButtonPress: {
    StartButtonPress = 1;

    object.UpdateWindow(d,w,e);
    object.CurrentPointerPressPos(e,x,y,OnlyCoutPos);
break;
    }
case Expose: {
         std::cout << "Expose\n";
         b12.NewButton(gc,cmap);
         b12.SetColorB(d,0,0,65500);
        b12.CreateButton(d,w,XDefaultGC(d,s),e, 435,275 , 550,305, UpWindow, CLICK,2);
        if(b12.ButtonTF == CLICK) {n1++; std::cout << n1 << std::endl; FunctionForDrawText(d,w,s, Money,4,125,125);}
        

    object.DrawItem(d,w,65500,0,0,GNFRectangle, 325,150,325,45);
    object.DrawItem(d,w,0,65500,0,GNFRectangle, 325,215,325,45);
    object.DrawItem(d,w,0,0,65500,GArc,100,100,50,50,64*180,64*180);
    XFlush(d);
break;
    }    
  }
}
  /* Закрыть соединение с X сервером */
XCloseDisplay(d);
return 0;
}
