#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>

extern GtkWidget  *view;//we need get the content of text editor, so it declared global

void set_text_content(){
	FILE *fp;
	GtkTextBuffer *buffer;
	gchar line_buf[1024];		//this buffer save a line of diary, I want read diary one line per time.
	GtkTextIter start, end;
	
	//Time function use below is to creat diary name.
	time_t t;
	t=time(NULL);
	gchar *filename;
	filename = (char *)malloc(sizeof(char)*10);//malloc filename memory
	//t variable is second from 1970, I divide 24 and 3600 is to get days from 1970
	//filename will add 1 every day.
	snprintf (filename, sizeof(filename), "%ld",t/24/3600);
	
	fp = fopen(filename, "r");
	if(fp==NULL){
		g_print("Error: file cann't open.\n");
		g_free(line_buf);
		return;
	}
	
	buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(view));// get buffer form view editor
	//if your have wrote diary today, I will read diary to editor line by line.
	while(fgets(line_buf,sizeof(line_buf),fp)!=NULL)  
    {  
    	gtk_text_buffer_get_end_iter(buffer, &end);//get the pointer to the end of the viewer
        gtk_text_buffer_insert(GTK_TEXT_BUFFER(buffer), &end, line_buf, -1);//insert diary line to editor
    } 
	
	fclose(fp);
}
