diary:diary.c save_file.c set_text_content.c diary_file.h 
	gcc -g -o diary $^ `pkg-config --libs --cflags libglade-2.0 gtk+-2.0`
