#include "Glib.h"

 extern int errno;

 int main() {
   Display *d;
   Window w;
   XEvent e;
   int s;
   GC gc;
   Colormap cmap;
   int x,y;
   int Point;
   Glib object;
   
   d = object.OpenDisplay("display");
   object.DefScreen(d,s);
   
   gc = XDefaultGC(d,s);
   cmap = XDefaultColormap(d,s);

   w = XCreateSimpleWindow(d, RootWindow(d, s), 10, 10, 950, 600, 1,
                        XBlackPixel(d, s),  XWhitePixel(d,s));
   
   object.DeclaringVariables(w,gc,cmap,s);

   XSelectInput(d, w, ExposureMask | KeyPressMask|KeyReleaseMask|FocusChangeMask | ButtonPressMask | StructureNotifyMask | ResizeRedirectMask | PointerMotionMask );
    XMapWindow(d, w);
   while (1) {
     XNextEvent(d, &e);
switch (e.type)
{
    
case ButtonPress:
    StartButtonPress = 1;
    object.CurrentPointerPressPos(e,x,y,OnlyCoutPos);
        object.UpdateWindow(d,w,e);
break;

case Expose:

         std::cout << "Expose\n";
         object.SetColor(65500,0,0);
             Point = object.CliInThisRectangle(d,e, 25,25, 125,66, DrawInvisibleSpace , 2,3);
            if(Point == 2) {std::cout << "Click REC" << std::endl;}
object.DrawItem(d,w, GLine , 0,32, 750 ,32);
object.DrawText(d,w,DefaultGC(d,s), "Gold" , 4 , 10 , 15  , DefaultColormap(d,s));
object.DrawText(d,w,DefaultGC(d,s), "Money", 5 , 50 , 15  , DefaultColormap(d,s));
object.DrawText(d,w,DefaultGC(d,s), "Expensive fossils", 17 , 95 , 15  , DefaultColormap(d,s));

    XFlush(d);
break;
   }
}

  /* Закрыть соединение с X сервером */
   XCloseDisplay(d);
   return 0;
 }
