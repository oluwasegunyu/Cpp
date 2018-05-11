#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/time.h>
#include <signal.h>
#include "diary_file.h"

struct itimerval new_timeval, old_timeval; 	//This struct is used to set timer, automatic save diary
GtkWidget *view;							//Text editor
						

int main(int argc, char* argv[]){
	GtkWidget *window;
	GtkTextBuffer *buffer;//Text buffer
	
	gtk_init(&argc, &argv);
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_default_size(GTK_WINDOW(window), 400, 400);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	g_signal_connect(G_OBJECT(window), "delete_event", G_CALLBACK(gtk_main_quit), NULL);
	
	view = gtk_text_view_new();//editor window
	gtk_container_add(GTK_CONTAINER(window), view);
	
	set_text_content();//set editor content if your have wrote diary today. Load diary!
	
	//set timer to save diary per second
	new_timeval.it_value.tv_sec=1;
	new_timeval.it_value.tv_usec=00000;
	new_timeval.it_interval.tv_sec=1;
	new_timeval.it_interval.tv_usec=00000;
	signal(SIGALRM, save_file);//save_file function to auto-save diary.
	setitimer(ITIMER_REAL,&new_timeval,&old_timeval);
	
	gtk_widget_show_all(window);
	gtk_main();
	return FALSE;
}
