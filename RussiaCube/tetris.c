#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include <signal.h>
#include <unistd.h>
#include <gtk/gtk.h>
#include <gdk/gdkkeysyms.h>
#include <glade/glade.h>
#include "global_cube.h"

GtkWidget *window;
GtkWidget *game_area;
GtkWidget *time_label;
GtkWidget *grade_label;
GtkWidget *score_label;
GtkWidget *red_map, *blue_map, *violet_map;

unsigned char g_color = RED;
unsigned int grade=1;
unsigned int score=0;

gint g_brick[BRICKXSIZE][BRICKYSIZE];

/* global parameters for the brick*/
CandidateBlock candidate_block[7];  

gint current_brickblock_index=0;    
gint current_brick_x=5;             /* based on 0 */
gint current_brick_y=0;             /* based on 0 */

/* end of global parameters */




/* Create bitmap */
static GtkWidget* create_pixmap(char* filename, GdkWindow *window, GdkColor *background)
{
		GtkWidget *wpixmap;
		GdkPixmap *pixmap;
		GdkBitmap *mask;
		pixmap = gdk_pixmap_create_from_xpm(window, &mask, background, filename);
		wpixmap = gtk_pixmap_new(pixmap,mask);
		return wpixmap;
}

/* Select the desired color*/
static void set_color(GtkWidget *widget, gpointer arg)
{
		g_color = (unsigned char)arg;
}

/* handle for expose the drawing area
 */
static gint handle_expose(GtkWidget* widget, GdkEventExpose *event, gpointer arg)
{
		/* Calculate the area to be redrawn.
		The game area is divided into 13*19 blocks. So it is needed 
		to calculate the blocks cover the event area. The size of the 
		game area is 260*380, so 20*20 each block.
		*/
		gint t_loopx,t_loopy;
		GtkPixmap *pixmap;
		gint c_xsize=BRICKWIDTH,c_ysize=BRICKHEIGHT;
		gint t_startx, t_starty, t_endx, t_endy;// based on 0
		t_startx=event->area.x/c_xsize;
		t_starty=event->area.y/c_ysize;
		t_endx=(event->area.x+event->area.width-1)/c_xsize;
		t_endy=(event->area.y+event->area.height-1)/c_ysize;
		/* Select the correct pixmap
		*/
		switch(g_color)
		{
			case RED:
				pixmap=GTK_PIXMAP(red_map);
				break;
			case BLUE:
				pixmap=GTK_PIXMAP(blue_map);
				break;
			case VIOLET:
				pixmap=GTK_PIXMAP(violet_map);
				break;
			default:
				break;
		}
		/* Redraw the client area
		*/
		for(t_loopy=t_starty;t_loopy<=t_endy;t_loopy++)
		{// loop y
			for(t_loopx=t_startx;t_loopx<=t_endx;t_loopx++)
			{// loop x
				// get the value from matrix
				if(g_brick[t_loopx][t_loopy]==1)
				{// draw one break
					gdk_draw_pixmap(widget->window,widget->style->black_gc,pixmap->pixmap,0,0,t_loopx*c_xsize,t_loopy*c_ysize,-1,-1);
				}
				else
				{// end of draw on brick 
					gdk_window_clear_area(widget->window,t_loopx*c_xsize,t_loopy*c_ysize,c_xsize,c_ysize);// clear the area
				}
			}// end of loop x
		}// end of loop y
}


/* timer handle. Send a down arrow key event every 500ms */
void handle_timer(int arg)
{
		GdkEvent t_event;
		t_event.type=GDK_KEY_PRESS;
		((GdkEventKey*)&t_event)->window=((GtkWidget*)window)->window;
		((GdkEventKey*)&t_event)->send_event=TRUE;
		((GdkEventKey*)&t_event)->time=0;
		((GdkEventKey*)&t_event)->state=0;
		((GdkEventKey*)&t_event)->keyval=GDK_Down;
		((GdkEventKey*)&t_event)->length=4;
		((GdkEventKey*)&t_event)->string="Down";
		((GdkEventKey*)&t_event)->hardware_keycode=0;
		((GdkEventKey*)&t_event)->group=0;
		gdk_event_put(&t_event);
}

gboolean show_time(gpointer data)
{
		static unsigned int run_time=0;
		unsigned char hour=0,minute=0,second=0;
		char runtime_text[10];
		unsigned int s;
		run_time++;
		hour = run_time/3600;
		s = run_time - hour * 3600;
		minute = s/60;
		second = s%60;
		sprintf(runtime_text, "%02d:%02d:%02d", hour,minute,second);
		gtk_label_set_text(GTK_LABEL(time_label),_N(runtime_text));	
		return TRUE;
}

void start_game(GtkWidget *widget, gpointer data)
{
		gtk_signal_connect(GTK_OBJECT(game_area),"expose-event",GTK_SIGNAL_FUNC(handle_expose), NULL);
		gtk_signal_connect(GTK_OBJECT(game_area),"key-press-event",GTK_SIGNAL_FUNC(key_press),(void*)game_area);
		gtk_widget_set_events(game_area,GDK_EXPOSURE_MASK | GDK_KEY_PRESS_MASK);
		gtk_signal_connect(GTK_OBJECT(window),"key-press-event",GTK_SIGNAL_FUNC(key_press),(void*)game_area);
		gtk_widget_set_events(window,GDK_KEY_PRESS_MASK);
		g_timeout_add(1000,show_time,NULL);
}

void restart_game(GtkWidget *widget, gpointer data)
{
		score = 0;
		gtk_label_set_text(GTK_LABEL(score_label), _N("得分: 0"));
}

void dialog_exit(GtkWidget * widget, gpointer data)
{
		gtk_widget_destroy((GtkWidget* )data);
}

void pause_game(GtkWidget *widget, gpointer data)
{
		GladeXML *PauseGame;
		GtkWidget *dialog,*Button;
		PauseGame = glade_xml_new("ui/PauseGame.glade", NULL, NULL);
		dialog = glade_xml_get_widget(PauseGame, "PauseGameDialog");
		Button = glade_xml_get_widget(PauseGame, "button");
		glade_xml_signal_autoconnect(PauseGame);
		g_signal_connect(G_OBJECT(Button), "clicked", G_CALLBACK(dialog_exit), dialog); 
		gtk_widget_show_all(dialog);
}

void first_grade(GtkWidget *widget, gpointer data)
{
		grade = 1;
		gtk_label_set_text(GTK_LABEL(grade_label), _N("等级: 1"));
		/* Set timer */
		new_timeval.it_value.tv_sec=1;
		new_timeval.it_value.tv_usec=00000;
		new_timeval.it_interval.tv_sec=1;
		new_timeval.it_interval.tv_usec=00000;
		signal(SIGALRM, handle_timer);
		setitimer(ITIMER_REAL,&new_timeval,&old_timeval);
}

void second_grade(GtkWidget *widget, gpointer data)
{
		grade = 2;
		gtk_label_set_text(GTK_LABEL(grade_label), _N("等级: 2"));
		/* Set timer */
		new_timeval.it_value.tv_sec=0;
		new_timeval.it_value.tv_usec=500000;
		new_timeval.it_interval.tv_sec=0;
		new_timeval.it_interval.tv_usec=500000;
		signal(SIGALRM, handle_timer);
		setitimer(ITIMER_REAL,&new_timeval,&old_timeval);
}

void third_grade(GtkWidget *widget, gpointer data)
{
		grade = 3;
		gtk_label_set_text(GTK_LABEL(grade_label), _N("等级: 3"));
		/* Set timer */
		new_timeval.it_value.tv_sec=0;
		new_timeval.it_value.tv_usec=300000;
		new_timeval.it_interval.tv_sec=0;
		new_timeval.it_interval.tv_usec=300000;
		signal(SIGALRM, handle_timer);
		setitimer(ITIMER_REAL,&new_timeval,&old_timeval);
}

void exit_game (GtkWidget *widget, gpointer data)
{ 
		GladeXML *ExitDialog;
		GtkWidget *dialog,*CancelButton;
		ExitDialog = glade_xml_new("ui/ExitDialog.glade", NULL, NULL);
		dialog = glade_xml_get_widget(ExitDialog, "ExitDialog");
		CancelButton = glade_xml_get_widget(ExitDialog, "cancel_button");
		glade_xml_signal_autoconnect(ExitDialog);
		g_signal_connect(G_OBJECT(CancelButton), "clicked", G_CALLBACK(dialog_exit), dialog);
		gtk_widget_show_all(dialog);
}

void highest_score(GtkWidget *widget, gpointer data)
{
		GladeXML *HighestScore;
		GtkWidget *dialog,*Button;
		HighestScore = glade_xml_new("ui/HighestScore.glade", NULL, NULL);
		dialog = glade_xml_get_widget(HighestScore, "HighestScoreDialog");
		Button = glade_xml_get_widget(HighestScore, "button");
		glade_xml_signal_autoconnect(HighestScore);
		g_signal_connect(G_OBJECT(Button), "clicked", G_CALLBACK(dialog_exit), dialog);	
		gtk_widget_show_all(dialog);

}

void about(GtkWidget *widget, gpointer data)
{
	GladeXML *AboutDialogXML;
	GtkWidget *AboutDialog,*CloseButton;
	AboutDialogXML = glade_xml_new ("ui/About.glade", NULL, NULL);
	AboutDialog = glade_xml_get_widget (AboutDialogXML, "aboutdialog");
	glade_xml_signal_autoconnect(AboutDialogXML);
	gtk_widget_show_all(AboutDialog);
}

int main(int argc, char*argv[])
{		
		GtkWidget *vbox,*hbox, *button,*toolbar;
		GdkWindowHints geo_mask;
		GdkGeometry geometry;
		GtkWidget *menu,*menubar,*rootmenu,*menuitem;
		GtkWidget *vseparator;
		GtkWidget *table;
		GtkWidget *start_button;
		GtkWidget *restart_button;
		GtkWidget *pause_button;
		GtkWidget *exit_button;
		GtkWidget *label1;
		GtkWidget *label2;
		
		initialize();
		gtk_init(&argc,&argv);
		window = gtk_window_new(GTK_WINDOW_TOPLEVEL);	
		gtk_window_set_title(GTK_WINDOW(window),_N("俄罗斯方块"));	
		gtk_window_set_icon_from_file(GTK_WINDOW(window),"tetris.ico",NULL);	
		gtk_window_set_position(GTK_WINDOW(window),GTK_WIN_POS_CENTER_ALWAYS);	
		gtk_signal_connect(GTK_OBJECT(window),"destroy",GTK_SIGNAL_FUNC(gtk_main_quit),window);
		gtk_container_border_width(GTK_CONTAINER(window),0);
		gtk_widget_show(window);		
		vbox=gtk_vbox_new(FALSE,0);
		gtk_container_add(GTK_CONTAINER(window),vbox);

		/*创建菜单栏*/
		/*创建第一组菜单*/
		menu = gtk_menu_new();
		menuitem = gtk_menu_item_new_with_label(_N("开始(N)"));
		gtk_menu_append(GTK_MENU(menu),menuitem);
		g_signal_connect(G_OBJECT(menuitem), "activate", G_CALLBACK(start_game), window);
		menuitem = gtk_menu_item_new_with_label(_N("重新开始(R)"));
		gtk_menu_append(GTK_MENU(menu),menuitem);
		g_signal_connect(G_OBJECT(menuitem), "activate", G_CALLBACK(restart_game), window);
		menuitem = gtk_menu_item_new_with_label(_N("初级(B)"));
		gtk_menu_append(GTK_MENU(menu),menuitem);
		g_signal_connect(G_OBJECT(menuitem), "activate", G_CALLBACK(first_grade), window);
		menuitem = gtk_menu_item_new_with_label(_N("中级(I)"));
		gtk_menu_append(GTK_MENU(menu),menuitem);
		g_signal_connect(G_OBJECT(menuitem), "activate", G_CALLBACK(second_grade), window);
		menuitem = gtk_menu_item_new_with_label(_N("高级(E)"));
		gtk_menu_append(GTK_MENU(menu),menuitem);
		g_signal_connect(G_OBJECT(menuitem), "activate", G_CALLBACK(third_grade), window);
		menuitem = gtk_menu_item_new_with_label(_N("暂停(P)"));
		gtk_menu_append(GTK_MENU(menu),menuitem);
		g_signal_connect(G_OBJECT(menuitem), "activate", G_CALLBACK(pause_game), window);
		menuitem = gtk_menu_item_new_with_label(_N("退出(X)"));
		gtk_menu_append(GTK_MENU(menu),menuitem);
		g_signal_connect(G_OBJECT(menuitem), "activate", G_CALLBACK(exit_game), window);
		rootmenu = gtk_menu_item_new_with_label(_N("游戏(G)"));
		gtk_menu_item_set_submenu(GTK_MENU_ITEM(rootmenu),menu);
		menubar = gtk_menu_bar_new();
		gtk_menu_bar_append(GTK_MENU_BAR(menubar),rootmenu);
		/* 创建第二组菜单 */
		menu = gtk_menu_new();
		menuitem = gtk_menu_item_new_with_label(_N("最高得分(M)"));
		gtk_menu_append(GTK_MENU(menu),menuitem);
		g_signal_connect(G_OBJECT(menuitem), "activate", G_CALLBACK(highest_score), window);
		menuitem = gtk_menu_item_new_with_label(_N("关于(A)"));
		gtk_menu_append(GTK_MENU(menu),menuitem);
		g_signal_connect(G_OBJECT(menuitem), "activate", G_CALLBACK(about), window);
		rootmenu = gtk_menu_item_new_with_label(_N("帮助(H)"));
		gtk_menu_item_set_submenu(GTK_MENU_ITEM(rootmenu),menu);
		gtk_menu_bar_append(GTK_MENU_BAR(menubar),rootmenu);		
		gtk_box_pack_start(GTK_BOX(vbox), menubar, TRUE, FALSE, 0);
		
		/* 创建工具栏 */
		toolbar = gtk_toolbar_new();
		red_map = create_pixmap("Image/red.xpm",window->window,&window->style->bg[GTK_STATE_NORMAL]);
		gtk_toolbar_append_item(GTK_TOOLBAR(toolbar),_N("红色"),_N("设置方块为红色"), NULL, red_map,(GtkSignalFunc)set_color, (gpointer)RED);
		blue_map = create_pixmap("Image/blue.xpm", window->window,&window->style->bg[GTK_STATE_NORMAL]);
		gtk_toolbar_append_item(GTK_TOOLBAR(toolbar), _N("蓝色"),_N("设置方块为蓝色"), NULL, blue_map,(GtkSignalFunc)set_color, (gpointer)BLUE);
		violet_map = create_pixmap("Image/violet.xpm",window->window,&window->style->bg[GTK_STATE_NORMAL]);
		gtk_toolbar_append_item(GTK_TOOLBAR(toolbar),_N("紫色"),_N("设置方块为紫色"), NULL, violet_map,(GtkSignalFunc)set_color, (gpointer)VIOLET);
		gtk_box_pack_start(GTK_BOX(vbox), toolbar, TRUE, FALSE, 0);			
		hbox=gtk_hbox_new(FALSE,0);
		gtk_box_pack_start(GTK_BOX(vbox), hbox,TRUE,TRUE,0);

		/* 创建绘图去*/
		game_area = gtk_drawing_area_new();
		gtk_drawing_area_size(GTK_DRAWING_AREA(game_area),BRICKWIDTH*BRICKXSIZE,BRICKHEIGHT*BRICKYSIZE);
		geometry.min_width=BRICKWIDTH*BRICKXSIZE;
		geometry.min_height=BRICKHEIGHT*BRICKYSIZE;
		geo_mask=GDK_HINT_MIN_SIZE|GDK_HINT_MAX_SIZE;
		gtk_window_set_geometry_hints(GTK_WINDOW(window),game_area,&geometry,geo_mask);
		gtk_box_pack_start(GTK_BOX(hbox),game_area,TRUE,FALSE,0);
		vseparator = gtk_vseparator_new();
		gtk_box_pack_start(GTK_BOX(hbox), vseparator, TRUE, FALSE, 0);
		
		/*创建界面右侧的按钮及标签*/
		table = gtk_table_new(9,1,FALSE);
		gtk_box_pack_start(GTK_BOX(hbox),table,TRUE,FALSE,0);
		start_button = gtk_button_new_with_label(_N("开始(N)"));
		g_signal_connect(G_OBJECT(start_button), "released", G_CALLBACK(start_game), window);
		gtk_table_attach(GTK_TABLE(table), start_button, 0, 1, 0, 1, (GtkAttachOptions)(0), (GtkAttachOptions)(0), 5, 10);		
		restart_button = gtk_button_new_with_label(_N("重新开始(R)"));
		g_signal_connect(G_OBJECT(restart_button), "released", G_CALLBACK(restart_game), window);
		gtk_table_attach(GTK_TABLE(table), restart_button, 0, 1, 1, 2, (GtkAttachOptions)(0), (GtkAttachOptions)(0), 5, 10);		
		pause_button = gtk_button_new_with_label(_N("暂停(P)"));
		g_signal_connect(G_OBJECT(pause_button), "released", G_CALLBACK(pause_game), window);
		gtk_table_attach(GTK_TABLE(table), pause_button, 0, 1, 2, 3, (GtkAttachOptions)(0), (GtkAttachOptions)(0), 5, 10);
		exit_button = gtk_button_new_with_label(_N("退出(X)"));
		g_signal_connect(G_OBJECT(exit_button), "released", G_CALLBACK(exit_game), window);
		gtk_table_attach(GTK_TABLE(table), exit_button, 0, 1, 3, 4, (GtkAttachOptions)(0), (GtkAttachOptions)(0), 5, 10);
		label1= gtk_label_new(_N(""));
		gtk_table_attach(GTK_TABLE(table), label1, 0, 1, 4, 5, (GtkAttachOptions)(0), (GtkAttachOptions)(0), 5, 5);
		label2= gtk_label_new(_N("时间"));
		gtk_table_attach(GTK_TABLE(table), label2, 0, 1, 5, 6, (GtkAttachOptions)(0), (GtkAttachOptions)(0), 5, 3);
		time_label = gtk_label_new(_N("00:00:00"));
		gtk_table_attach(GTK_TABLE(table), time_label, 0, 1, 6, 7, (GtkAttachOptions)(0), (GtkAttachOptions)(0), 5, 10);
		grade_label = gtk_label_new(_N("等级: 1"));
		gtk_table_attach(GTK_TABLE(table), grade_label, 0, 1, 7, 8, (GtkAttachOptions)(0), (GtkAttachOptions)(0), 5, 10);
		score_label = gtk_label_new(_N("得分: 0"));
		gtk_table_attach(GTK_TABLE(table), score_label, 0, 1, 8, 9, (GtkAttachOptions)(0), (GtkAttachOptions)(0), 5, 10);
		gtk_widget_show_all(window);
		

		new_timeval.it_value.tv_sec=1;
		new_timeval.it_value.tv_usec=00000;
		new_timeval.it_interval.tv_sec=1;
		new_timeval.it_interval.tv_usec=00000;
		signal(SIGALRM, handle_timer);
		setitimer(ITIMER_REAL,&new_timeval,&old_timeval);
		gtk_main();
		return 0;
}
