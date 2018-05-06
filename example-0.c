#include <gtk/gtk.h>

int main (int argc, char **argv)
{
  GtkWidget *window;
  
  /*初始化GTK+和所有的库*/
  gtk_init(&argc, &argv);
  
  /*新建窗口*/
  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(window), "Hello World");
  gtk_widget_show(window);
  
  /*主循环控制*/
  gtk_main();
  return 0;
}

