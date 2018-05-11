#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>

extern GtkWidget  *view; //we need get the content of text editor, so it declared global

void save_file(int arg){
	FILE *fp;
	gchar *buf;
	GtkTextIter start, end;
	GtkTextBuffer *buffer;
	
	//Time function use below is to creat diary name.
	time_t t;
	t=time(NULL);
	gchar *filename;
	filename = (char *)malloc(sizeof(char)*10);//malloc filename memory
	//t variable is second from 1970, I divide 24 and 3600 is to get days from 1970
	//filename will add 1 every day.
	snprintf (filename, sizeof(filename), "%ld",t/24/3600);
	
	buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(view));// get buffer form view editor
	//get start and end point for viewer
	gtk_text_buffer_get_start_iter(buffer, &start);
	gtk_text_buffer_get_end_iter(buffer, &end);
	
	fp = fopen(filename, "w");
	if(fp==NULL){
		g_print("Error: file cann't open.\n");
		g_free(buf);
		return;
	}
	
	buf = gtk_text_buffer_get_text(buffer, &start, &end, TRUE);//get content of buffer
	fputs(buf, fp);//store diary
	fclose(fp);
}
