
#include <X11/X.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <stdio.h>
#include <X11/Xcms.h>
#include <X11/XKBlib.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <errno.h>
#include <X11/Xatom.h>

const int OnlyCoutPos = 900;
const int WorkWithXY = 901;
const int DrawInvisibleSpace = 902;
const int UpWindow = 903;
const int NONE = 404;
const int GRectangle = 801;
const int GLine = 802;
const int GNFRectangle = 803;
const int GArc = 804;
const int CLICK = 1700;
int StartButtonPress = 0;
int Button[100000];
using Start=int;


      class Glib
 {
      int Point[10];
     
 public:
     int Cord1[2];
     int Cord2[2];
      XColor Color;
     XFontStruct *TEXT;
     int red = 0; int green = 0; int blue = 0;
     int xC = 0; int yC = 0;
     Window *wClass;
     GC *GraphContextClass;
     Colormap *cMapClass;
     int *DefScree;
     int ButtonPoint[10000];
     char fontname[128];
     

 
 void DeclaringVariables(Window &w, GC &GraphContext, Colormap &cMap , int &s) {
         Point[5] = 25;
         wClass = &w;
         GraphContextClass = &GraphContext;
         cMapClass = &cMap;
         DefScree = &s;

     }
     
 void DrawItem(Display* d , Window w,int r,int g,int b , int FunctionMode , int x1 , int y1, int x2, int y2 , int AdvanceParam = 0, int AdvanceParam2 = 0) {
         
    Cord1[0] = x1;
    Cord1[1] = y1;
    Cord2[0] = x2;
    Cord2[1] = y2;
     Color.flags = DoRed | DoGreen | DoBlue;
     red , Color.red = r; green , Color.green = g; blue , Color.blue = b;
            XAllocColor(d, *cMapClass , &Color);
            XSetForeground(d, *GraphContextClass, Color.pixel);
   if(FunctionMode == GRectangle) {
       XFillRectangle(d, w, *GraphContextClass, x1, y1, x2 , y2);
   }
   if(FunctionMode == GLine) {
       XDrawLine(d,w,*GraphContextClass,x1,y1,x2,y2);
   }
   if(FunctionMode == GNFRectangle) {
        XDrawRectangle(d,w,*GraphContextClass,x1,y1,x2,y2);
   }
   if(FunctionMode == GArc) {
        XFillArc(d,w,*GraphContextClass,x1,y1,x2,y2,AdvanceParam,AdvanceParam2);
   }
  Color.blue = 0; Color.green = 0; Color.red = 0;
 }
 
 void DrawText(Display* d,Window w, GC GraphContext, const char * text , int num , int x1 , int y1 , Colormap cMap , const char * font1 = "0") {

  XAllocColor(d, cMap , &Color);
  XSetForeground(d, GraphContext, Color.pixel);
     if(font1 == "0") {
        TEXT = XLoadQueryFont (d, "fixed");
     }
     else {
        TEXT = XLoadQueryFont (d, font1);
     }
     XSetFont(d, GraphContext, TEXT->fid);
     XDrawString (d, w, GraphContext, x1, y1, text, num);
 }
 
 void UpdateWindow(Display *d, Window w,XEvent e) {
     e.type = Expose;
     XSendEvent(d, w, True, 0, (XEvent *)&e);
 }
 
Display* OpenDisplay( const char* name) {
     
   Display *d;
    if ((d = XOpenDisplay(getenv(name))) == NULL) {
    printf("Can't connect X server:%s\n", strerror(errno));
    exit(1);
   }
  return d;
 }
 
 void DefScreen(Display *d , int &INTs) {
     INTs = XDefaultScreen(d);
 }
 
 void CurrentPointerPressPos(XEvent e, int &x, int &y, int FunctionMode) {
  if(StartButtonPress == 1) {
     xC = e.xbutton.x;
     yC = e.xbutton.y;
     if(FunctionMode == 900) {
         std::cout << "x = " << xC << std::endl;
         std::cout << "y = " << yC << std::endl;
         int x = -1; int y = -1;
     }
     else if(FunctionMode == 901) {
         x = xC;
         y = yC;
      std::cout << "x = " << xC << std::endl;
      std::cout << "y = " << yC << std::endl;
     }
   }
 }
 
 int CliInThisRectangle(Display *d , XEvent e ,int x1, int y1, int x2, int y2 ,int ModeFunction, int WhatReturnIfTrue, int WhatReturnIfFalse)
 {
 int xInFunc = 0; int yInFunc = 0;
     if(ModeFunction == DrawInvisibleSpace)
     {
        XFillRectangle(d, *wClass, *GraphContextClass, x1, y1, x2-x1 , y2-y1);
     }
        CurrentPointerPressPos(e, xInFunc, yInFunc, WorkWithXY);
     if(xInFunc >= x1 && xInFunc <= x2 && yInFunc >= y1 && yInFunc <= y2) {return WhatReturnIfTrue; std::cout << "123\n"; if(ModeFunction == UpWindow)
                                                                           {UpdateWindow(d,*wClass,e);}                                                  }
     else {return WhatReturnIfFalse;}
     return WhatReturnIfFalse;
 }
 
};

class GButton : protected Glib
{
    
public:
    int ButtonTF;
    int ButtonTrue;
    int ButtonFalse;
     GC *GraphContextClassB;
     Colormap *cMapClassB;
 void CreateButton(Display *d, Window w, GC gc2 , XEvent e ,int x1, int y1, int x2, int y2 ,int ModeFunction, int WhatReturnIfTrue, int WhatReturnIfFalse)
 {
  int xInFunc = 0; int yInFunc = 0;
    XAllocColor(d, *cMapClassB , &Color);
    XSetForeground(d, *GraphContextClassB, Color.pixel);
    XFillRectangle(d, w, gc2, x1, y1, x2-x1 , y2-y1);
     CurrentPointerPressPos(e, xInFunc, yInFunc, WorkWithXY);
     
     if(xInFunc >= x1 && xInFunc <= x2 && yInFunc >= y1 && yInFunc <= y2) {ButtonTrue = WhatReturnIfTrue; ButtonTF = WhatReturnIfTrue; if(ModeFunction == UpWindow)
                                                                          {UpdateWindow(d,w,e);}                                      }
  else {ButtonFalse = WhatReturnIfFalse; ButtonTF = WhatReturnIfFalse;}
StartButtonPress = 0;
 }
 
 void SetColorB(Display *d,int r,int g,int b) {
     Color.flags = DoRed | DoGreen | DoBlue;
     red , Color.red = r; green , Color.green = g; blue , Color.blue = b;

 }
 
 void NewButton(GC &GraphContext, Colormap &cMap) {
    GraphContextClassB = &GraphContext;
    cMapClassB = &cMap;
 }
};
 
