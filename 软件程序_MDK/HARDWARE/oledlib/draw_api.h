#ifndef DRAW_API_H
#define DRAW_API_H
#include "oled_config.h"
#include "oled_driver.h"
#include "oled_draw.h"
#include "oled_basic.h"
#include "oled_color.h"
#include "oled_buffer.h"
#include "oled_font.h"
#include "oled_bmp.h"
#include "oled_debug.h"
//***********************************************************************
//*		 为了做这个绘制图形库，我参考了很多其他的算法,花了大量时间去做移植
//*优化，其中参考最多的是github中的arduboy游戏机，大部分图形是移植它的，
//*现在是最初的初稿版本,还有很多地方需要优化改进。我想要将这个图形库做大，
//*后续会加入更多有趣的东西，和模块，代码都是用最简单的方式编写的，都是开源的。
//*后续也会加上注释说明，让更多人以单片机和oled屏来入门硬件编程，如果你
//使用了该库，请标明出处。b站关注oximeterg，可获取该库的最新版本和消息。
//*oled屏图形库0.0.0.1        							作者：maoyongjie     
//https://github.com/hello-myj/stm32_oled/
//************************************************************************

//-------------------------------------------------------------------------
/**************************************************************************/
														//坐标说明
/*														 x(0~127)
												 ------------------>
												|
												|
												|y(0~63)
												|
												|
												v
*/
//--------------------------------------------------------------------------
/**************************************************************************/

//注意：绘制填充或实心的图形，影响刷新效率（待优化中）。


//*************************************************************************
//InitGraph
//功能:初始化图形库
//*************************************************************************
void InitGraph(void);

//*************************************************************************
//UpdateScreen
//功能:将屏幕数据更新到设备上
//*************************************************************************
void UpdateScreen(void);

//*************************************************************************
//ClearScreen
//功能:清屏
//*************************************************************************
void ClearScreen(void);


//*************************************************************************
//SetTextBkMode
//功能:设置字体的背景模式
//value:背景模式的值,0为透明，1为正常。
//*************************************************************************
void SetTextBkMode(unsigned char value);

//*************************************************************************
//GetTextBkMode
//功能:获取字体的背景模式
//return:返回当前背景模式的值,0为透明，1为正常。
//*************************************************************************
unsigned char GetTextBkMode(void);
//*************************************************************************
//SetDrawColor
//功能:设置绘制的颜色
//value：设置的颜色pix_black:黑色、pix_white:白色
//*************************************************************************
extern void SetDrawColor(Type_color value);

//*************************************************************************
//GetDrawColor
//功能:获取当前设置的绘制颜色
//return:返回当前的绘制的颜色pix_black:黑色、pix_white:白色
//*************************************************************************
extern Type_color GetDrawColor(void);

//*************************************************************************
//SetFillcolor
//功能:设置填充的颜色
//value：设置的颜色pix_black:黑色、pix_white:白色
//*************************************************************************
extern void SetFillcolor(Type_color value);

//*************************************************************************
//GetFillColor
//功能:获取当前设置的填充颜色
//return:返回当前的填充的颜色pix_black:黑色、pix_white:白色
//*************************************************************************
extern Type_color GetFillColor(void);

//*************************************************************************
//DrawPixel
//功能：绘制一个点
//参数x：横坐标0~127
//参数y：纵坐标0~63
//*************************************************************************
extern void DrawPixel(int x,int y);

//*************************************************************************

//*************************************************************************
//GetPixel
//功能：获取一个像素点的颜色
//参数x：横坐标0~127
//参数y：纵坐标0~63
//return：返回的像素颜色
//*************************************************************************
extern Type_color GetPixel(int x,int y);

//DrawLine
//功能:绘制一条线
//参数x1,y1:其中一个点的坐标
//参数x2,y2:另一个点坐标
//*************************************************************************
extern void DrawLine(int x1,int y1,int x2,int y2);

//*************************************************************************
//DrawFastHLine
//功能:快速绘制一条水平线
//参数x,y:水平线起点位置
//参数w:水平线长度
//*************************************************************************
extern void DrawFastHLine(int x, int y, unsigned char w);

//*************************************************************************
//DrawFastVLine
//功能:快速绘制一条垂直线
//参数x,y:垂直线起点位置
//参数w:垂直线长度
//*************************************************************************
extern void DrawFastVLine(int x, int y, unsigned char h);

//*************************************************************************
//DrawPolyLineTo
//功能:画连续的多条线段,并移坐标
//参数points:每个点的坐标，数组元素个数为 num
//参数num:多条线段的顶点个数
//*************************************************************************
void DrawPolyLineTo(const TypeXY *points,int num);
//*************************************************************************
//DrawFillRect1
//功能:使用对角点绘制一个填充矩形
//参数left,top:左上角坐标
//参数right,bottom:右下角坐标
//*************************************************************************
extern void DrawFillRect1(int left,int top,int right,int bottom);

//*************************************************************************
//DrawRect1
//功能:使用对角点绘制一个矩形
//参数left,top:矩形左上角坐标
//参数right,bottom:矩形右下角坐标
//*************************************************************************
extern void DrawRect1(int left,int top,int right,int bottom);

//*************************************************************************
//DrawFillRect2
//功能:使用另一种方式绘制一个填充矩形
//参数left,top:矩形左上角坐标
//参数width:矩形宽度
//参数height:矩形高度
//*************************************************************************
extern void DrawFillRect2(int left,int top,int width,int height);

//*************************************************************************
//DrawRect2
//功能:使用另一种方式绘制一个矩形
//参数left,top:矩形左上角坐标
//参数width:矩形宽度
//参数height:矩形高度
//*************************************************************************
extern void DrawRect2(int left,int top,int width,int height);

//*************************************************************************
//DrawCircle
//功能:绘制一个圆
//参数usX_Center,usY_Center:圆中心坐标
//参数usRadius:圆半径
//*************************************************************************
extern void DrawCircle( int usX_Center, int usY_Center, int usRadius);

//*************************************************************************
//DrawFillCircle
//功能:绘制一个实心圆
//参数usX_Center,usY_Center:圆中心坐标
//参数usRadius:圆半径
//*************************************************************************
extern void DrawFillCircle( int usX_Center, int usY_Center, int usRadius);

//*************************************************************************
//DrawCircleHelper
//功能:绘制一个圆的部分(4分之一部分)
//参数usX_Center,usY_Center:圆中心坐标
//参数usRadius:圆半径
//参数cornername:选择所需绘制的部分
//*************************************************************************
extern void DrawCircleHelper(int x0, int y0, unsigned char r, unsigned char cornername);

//*************************************************************************
//DrawFillCircleHelper
//功能:绘制一个实心圆的部分(4分之一部分)
//参数usX_Center,usY_Center:圆中心坐标
//参数usRadius:圆半径
//参数cornername:选择所需绘制的部分
//参数delta：填充系数
//*************************************************************************
extern void DrawFillCircleHelper(int x0, int y0, unsigned char r, unsigned char cornername, int delta);

//*************************************************************************
//DrawArc
//功能:绘制一个圆弧(4分之一部分)
//x,y:圆弧中心坐标
//r:圆弧的半径
//angle_start:圆弧起始角度
//angle_end:圆弧终止角度
//注意：慎用此方法，此方法还需优化。
//*************************************************************************
extern void DrawArc(int x,int y,unsigned char r,int angle_start,int angle_end);
//extern void DrawFillArc(int x,int y,unsigned char r,int angle_start,int angle_end);

//*************************************************************************
//DrawRoundRect
//功能:绘制一个圆角矩形
//x,y:圆角矩形左上角坐标
//w:圆角矩形宽
//h:圆角矩形高
//r:圆角圆的半径
//*************************************************************************
extern void DrawRoundRect(int x, int y, unsigned char w, unsigned char h, unsigned char r);

//*************************************************************************
//DrawfillRoundRect
//功能:绘制一个填充圆角矩形
//x,y:填充圆角矩形左上角坐标
//w:填充圆角矩形宽
//h:填充圆角矩形高
//r:填充圆角圆的半径
//*************************************************************************
extern void DrawfillRoundRect(int x, int y, unsigned char w, unsigned char h, unsigned char r);

//*************************************************************************
//DrawEllipse
//功能:绘制一个椭圆
//x0,y0:椭圆的中心坐标
//a:椭圆水平长度
//b:椭圆垂直长度
//*************************************************************************
extern void DrawEllipse(int x0,int y0,int a,int b);

//*************************************************************************
//DrawFillEllipse
//功能:绘制一个填充椭圆
//x0,y0:填充椭圆的中心坐标
//a:填充椭圆水平长度
//b:填充椭圆垂直长度
//*************************************************************************
extern void DrawFillEllipse(int x0,int y0,int a,int b);

//*************************************************************************
//DrawEllipseRect
//功能:绘制一个矩形内切椭圆
//x0,y0:矩形左上角坐标
//x1,y1:矩形右下角坐标
//*************************************************************************
extern void DrawEllipseRect( int x0, int y0, int x1, int y1);

//*************************************************************************
//DrawTriangle
//功能:绘制一个三角形
//x0,y0:三角形的顶点之一坐标
//x1,y1:三角形的顶点之一坐标
//x2,y2:三角形的顶点之一坐标
//*************************************************************************
extern void DrawTriangle(unsigned char x0, unsigned char y0, unsigned char x1, unsigned char y1, unsigned char x2, unsigned char y2);

//*************************************************************************
//DrawFillTriangle
//功能:绘制一个填充三角形
//x0,y0:填充三角形的顶点之一坐标
//x1,y1:填充三角形的顶点之一坐标
//x2,y2:填充三角形的顶点之一坐标
//*************************************************************************
extern void DrawFillTriangle(int x0, int y0, int x1, int y1, int x2, int y2);

//*************************************************************************
//DrawBitmap
//功能:绘制一张图片
//bitmap:图片数据（可通过取模获取）
//w:图片的宽度
//h:图片的高度
//*************************************************************************
extern void DrawBitmap(int x, int y, const unsigned char *bitmap, unsigned char w, unsigned char h);

//*************************************************************************
//DrawSlowBitmap
//功能:绘制一张图片
//bitmap:图片数据（可通过取模获取）
//w:图片的宽度
//h:图片的高度
//注意：此方法绘制图片影响刷新效率，慎用
//*************************************************************************
extern void DrawSlowBitmap(int x, int y, const unsigned char *bitmap, unsigned char w, unsigned char h);


//*************************************************************************
//SetFontSize
//功能:设置字体大小
//value:字体大小
//*************************************************************************
extern void SetFontSize(unsigned char value);

//*************************************************************************
//GetFontSize
//功能:获取字体大小
//value:字体大小
//*************************************************************************
extern unsigned char GetFontSize(void);

//*************************************************************************
//SetTextBkMode
//功能:设置字体背景模式
//value:背景模式的值,TEXT_BK_NULL：无背景，TEXT_BK_NOT_NULL：有背景
//*************************************************************************
extern void SetTextBkMode(Type_textbk value);

//*************************************************************************
//GetTextBkMode
//功能:获取当前字体背景模式
//value:背景模式的值,TEXT_BK_NULL：无背景，TEXT_BK_NOT_NULL：有背景
//*************************************************************************
extern Type_textbk GetTextBkMode(void);

//*************************************************************************
//DrawChar
//功能:绘制一个字符
//x,y:字符坐标
//c:单字符
//*************************************************************************
extern void DrawChar(int x, int y, unsigned char c);

//*************************************************************************
//DrawChar
//功能:绘制字符串
//x,y:字符串坐标
//str:字符串
//*************************************************************************
extern void DrawString(int x, int y,char *str);

//*************************************************************************
//DrawNum
//功能:绘制数字
//x,y:数字坐标
//num:数字
//len:数字位数
//*************************************************************************
extern void DrawNum(unsigned char x,unsigned char y,unsigned int num,unsigned char len);

//*************************************************************************
//FloodFill2
//功能:可用于填充一个封闭图形
//x,y:在封闭图形任意一点坐标
//oldcolor:封闭图形中旧的颜色
//newcolor:填充的新颜色
//*************************************************************************
extern void FloodFill2(unsigned char x,unsigned char y,int oldcolor,int newcolor);

//*************************************************************************
//MoveTo
//功能:移动绘制坐标
//x,y:坐标
//*************************************************************************
extern void MoveTo(int x,int y);

//*************************************************************************
//LineTo
//功能:线性绘制,并将绘制坐标移动到下一个坐标
//x,y:下一个坐标点
//*************************************************************************
extern void LineTo(int x,int y);

//*************************************************************************
//GetY
//功能:获取当前点绘制点的y坐标
//return：当前点的y坐标
//*************************************************************************
extern int GetY(void);

//*************************************************************************
//GetX
//功能:获取当前点绘制点的X坐标
//return：当前点的X坐标
//*************************************************************************
extern int GetX(void);

//*************************************************************************
//GetXY
//功能:获取当前点绘制点的X、Y坐标
//return：当前点的x,y坐标
//*************************************************************************
extern TypeXY GetXY(void);

//*************************************************************************
//GetRotateXY
//功能:将一个坐标旋转一定角度
//x,y:需要旋转的坐标
//return：旋转后的坐标
//*************************************************************************
extern TypeXY GetRotateXY(int x,int y);

//*************************************************************************
//SetRotateCenter
//功能:设置旋转中心点，配合GetRotateXY使用
//x0,y0:旋转中心坐标点
//*************************************************************************
extern void SetRotateCenter(int x0,int y0);

//*************************************************************************
//SetAnggleDir
//功能:设置旋转方向，配合GetRotateXY使用
//direction:旋转方向 1为逆时针，0为顺时针
//*************************************************************************
extern void SetAnggleDir(int direction);

//*************************************************************************
//SetAngle
//功能:设置旋转角度，配合GetRotateXY使用
//angle:旋转角度
//*************************************************************************
extern void SetAngle(float angle);

//*************************************************************************
//SetRotateValue
//功能:设置角度、旋转方向、旋转中心
//x,y:旋转中心点
//angle:旋转角度
//direct:旋转角度
//*************************************************************************
extern void SetRotateValue(int x,int y,float angle,int direct);

//*************************************************************************
//SetScreenBuffer
//功能:设置默认的缓冲作为屏幕数据
//*************************************************************************
extern void SetScreenBuffer(void);

//*************************************************************************
//SetTempBuffer
//功能:设置新的缓冲作为屏幕数据，
//*************************************************************************
extern void SetTempBuffer(void);

//*************************************************************************
//GetSelectedBuffer
//功能:获取当前的缓冲buffer的系数
//return:返回缓冲系数SCREEN_BUFFER和TEMP_BUFFER
//*************************************************************************
extern unsigned char GetSelectedBuffer(void);

//*************************************************************************
//ClearScreenBuffer
//功能:清除掉默认的屏幕缓冲数据
//*************************************************************************
extern void ClearScreenBuffer(unsigned char val);

//*************************************************************************
//ClearTempBuffer
//功能:清除掉临时的屏幕缓冲数据
//*************************************************************************
extern void ClearTempBuffer(void);

//*************************************************************************
//TempBufferFunc
//功能:临时缓冲的功能
//func:执行的功能可选择的参数如下
/*
	TEMPBUFF_COPY_TO_SCREEN, 将temp缓冲复制到屏幕缓冲
	TEMPBUFF_CLEAN,					 清楚掉temp缓冲数据
	TEMPBUFF_COVER_L,				 将temp缓冲的数据取反再覆盖掉屏幕上的数据
	TEMPBUFF_COVER_H				 将temp缓冲的数据覆盖掉屏幕上的数据
*/
//*************************************************************************
extern void TempBufferFunc(int func);

//*************************************************************************
//FrameRateUpdateScreen
//功能:固定帧刷新
//*************************************************************************

extern unsigned char FrameRateUpdateScreen(int value);
//*************************************************************************
//OledPrintf
//功能:用以打印调试bug，功能和printf一致，不用使用ClearScreen方法也可打印出数据
//*************************************************************************
extern int OledPrintf(const char *str,...);
#endif

