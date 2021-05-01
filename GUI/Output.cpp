#include "Output.h"


Output::Output()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;
	
	UI.width = 1300;
	UI.height = 700;
	UI.wx = 5;
	UI.wy =5;

	
	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 50;
	UI.MenuItemWidth = 80;
	
	UI.DrawColor = BLUE;	//Drawing color
	UI.FillColor = GREEN;	//Filling color
	UI.MsgColor = RED;		//Messages color
	UI.BkGrndColor = LIGHTGOLDENRODYELLOW;	//Background color
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = TURQUOISE;
	UI.PenWidth = 3;	//width of the figures frames

	
	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project");
	
	CreateDrawToolBar();
	CreateStatusBar();
}


Input* Output::CreateInput() const
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int w, int h, int x, int y) const
{ 
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);	
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateDrawToolBar() const
{
	UI.InterfaceMode = MODE_DRAW;

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way
	
	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[DRAW_ITM_COUNT];
	MenuItemImages[ITM_RECT] = "images\\MenuItems\\rect.jpg";
	MenuItemImages[ITM_CIRC] = "images\\MenuItems\\circle.jpg";
	MenuItemImages[ITM_LINE] = "images\\MenuItems\\line.jpg";
	MenuItemImages[ITM_TRI]= "images\\MenuItems\\triangle.jpg";
	MenuItemImages[ITM_CHNG_DCLR]= "images\\MenuItems\\draw_color.jpg";
	MenuItemImages[ITM_CHNG_FCLR]= "images\\MenuItems\\fill_icon.jpg";
	MenuItemImages[ITM_DELETE]= "images\\MenuItems\\delete.jpg";
	MenuItemImages[ITM_SLCT]= "images\\MenuItems\\select.jpg";
	MenuItemImages[ITM_COPY]= "images\\MenuItems\\copy_icon.jpg";
	MenuItemImages[ITM_CUT]= "images\\MenuItems\\cut_icon.jpg";
	MenuItemImages[ITM_PASTE]= "images\\MenuItems\\paste.jpg";
	MenuItemImages[ITM_ADD] = "images\\MenuItems\\upload_icon.jpg";
	MenuItemImages[ITM_ZOOM_IN] = "images\\MenuItems\\zoom in.jpg";
	MenuItemImages[ITM_ZOOM_OUT] = "images\\MenuItems\\zoom out.jpg";
	MenuItemImages[ITM_RESIZE]= "images\\MenuItems\\resize.jpg";
	MenuItemImages[ITM_ROTATE]= "images\\MenuItems\\rotate_icon.jpg";
	MenuItemImages[ITM_BTF]= "images\\MenuItems\\bringtofront.jpg";
	MenuItemImages[ITM_STB]= "images\\MenuItems\\sendtoback.jpg";
	MenuItemImages[ITM_SAVE]= "images\\MenuItems\\save_icon.jpg";
	MenuItemImages[ITM_SWITCH_PLAY] = "images\\MenuItems\\to_play.jpg";
	MenuItemImages[ITM_EXIT] = "images\\MenuItems\\exit.jpg";
	
	//TODO: Prepare images for each menu item and add it to the list

	//Draw menu item one image at a time
	for(int i=0; i<DRAW_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth,0,UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::CreatePlayToolBar() const
{
	UI.InterfaceMode = MODE_PLAY;
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, 0, UI.width, UI.height - UI.ToolBarHeight);

	string MenuItemImages2[PLAY_ITM_COUNT];
	MenuItemImages2[ITM_P_H_FSHAPE] = "images\\MenuItems\\Pickbyshape.jpg";
	MenuItemImages2[ITM_P_H_FCOLOR] = "images\\MenuItems\\Pickbycolor.jpg";
	MenuItemImages2[ITM_P_H_FBOTH] = "images\\MenuItems\\Pickbyboth.jpg";
	MenuItemImages2[ITM_AREA]= "images\\MenuItems\\area.jpg";
	MenuItemImages2[ITM_SWITCH_DRAW ] = "images\\MenuItems\\to_draw.jpg";

	MenuItemImages2[ITM_EXIT2] = "images\\MenuItems\\exit.jpg";


	//Draw menu item one image at a time
	for (int i = 0; i < PLAY_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);


}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);
	
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar
	
	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD , BY_NAME, "Arial");   
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight/1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntDrawColor() const	//get current drwawing color
{	return UI.DrawColor;	}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntFillColor() const	//get current filling color
{	return UI.FillColor;	}
//////////////////////////////////////////////////////////////////////////////////////////
	
int Output::getCrntPenWidth() const		//get current pen width
{	return UI.PenWidth;	}

//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

void Output::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, RectGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);

}

// draw line function
void Output::Drawline(Point P1, Point P2, GfxInfo lineGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = lineGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, lineGfxInfo.BorderWdth);	//Set Drawing color   if didnt work try a num ex:2,or try BorderWdth

	pWind->DrawLine(P1.x, P1.y, P2.x, P2.y);


	// PenWidth
}


// draw triangle function
void Output::Drawtrig(Point P1, Point P2, Point P3, GfxInfo trigGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = trigGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, trigGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (trigGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(trigGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, style);

}


// draw circle function
void Output::Drawcir(Point P1, Point P2, GfxInfo cirGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = cirGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, cirGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (cirGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(cirGfxInfo.FillClr);
	}
	else
		style = FRAME;
	int radius = sqrt(pow(P1.x - P2.x, 2) + pow(P1.y - P2.y, 2));

	pWind->DrawCircle(P1.x, P1.y, radius, style);

}






//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}

