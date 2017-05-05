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
   int s;
   int x,y;
   int Money = 1000;

   
   d = object.OpenDisplay("display");
    object.DefScreen(d,s);
   gc = XDefaultGC(d,s);
    cmap = XDefaultColormap(d,s);
   w = XCreateSimpleWindow(d, RootWindow(d, s), 10, 10, 950, 600, 1,
                                 XBlackPixel(d, s),  XWhitePixel(d,s));
    object.DeclaringVariables(w,gc,cmap,s);

   XSelectInput(d, w, ExposureMask | KeyPressMask|KeyReleaseMask|FocusChangeMask 
                | ButtonPressMask );
   
XMapWindow(d, w);

   while (1) {
XNextEvent(d, &e);
switch (e.type)
{
    
case ButtonPress:
{
    StartButtonPress = 1;

    object.UpdateWindow(d,w,e);
        object.CurrentPointerPressPos(e,x,y,OnlyCoutPos);
Button[1] = object.CliInThisRectangle(d,e, 0,0, 39,33, UpWindow , CLICK,2);

break;
}
case Expose:
{
         std::cout << "Expose\n";
         object.SetColor(65500,0,0);
                 b12.CreateButton(d,w,XDefaultGC(d,s),e, 130,130, 150,150, UpWindow , CLICK,2);
            if(Button[1] == CLICK) {FunctionForDrawText(d,w,s, Money,4,50,50);}
            if(b12.ButtonTF == CLICK) {FunctionForDrawText(d,w,s, Money,4,125,125);}
object.DrawItem(d,w, GLine , 0,32, 10000 ,32);
object.DrawText(d,w,DefaultGC(d,s), "Gold" , 4 , 10 , 15  , DefaultColormap(d,s));
object.DrawText(d,w,DefaultGC(d,s), "Money", 5 , 50 , 15  , DefaultColormap(d,s));
object.DrawText(d,w,DefaultGC(d,s), "Expensive fossils", 17 , 95 , 15  , DefaultColormap(d,s));

    XFlush(d);
break;
  }    
 }
}
  /* Закрыть соединение с X сервером */
   XCloseDisplay(d);
   return 0;
 }
