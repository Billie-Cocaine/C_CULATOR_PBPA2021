#include <stdlib.h>
#include <gtk/gtk.h>


GtkWidget *lbl_SCREEN;

int main(int argc, char *argv[])
{
    GtkBuilder      *builder; 
    GtkWidget       *window;

    gtk_init(&argc, &argv);

    builder = gtk_builder_new();
    gtk_builder_add_from_file (builder, "glade/window_main.glade", NULL);

    window = GTK_WIDGET(gtk_builder_get_object(builder, "window_main"));
    gtk_builder_connect_signals(builder, NULL);


    lbl_SCREEN = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_SCREEN"));


    g_object_unref(builder);

    gtk_widget_show(window);                
    gtk_main();


    return 0;
}
///////////////////  SET FUNTIONS TO THE ARITHIMETIC BOTTONS    ////////////////////////////

	void on_operationDIV()
	{

	    
	    gtk_label_set_text(GTK_LABEL(lbl_SCREEN), "División");

	}



///////////////////  SET FUNTIONS TO THE NUMERIC BOTTONS    ////////////////////////////



	void on_btm7()
	{

	    
	    gtk_label_set_text(GTK_LABEL(lbl_SCREEN), "7");

	}
	void on_btm4()
	{

	    
	    gtk_label_set_text(GTK_LABEL(lbl_SCREEN), "4");

	}
	void on_btm1()
	{

	    
	    gtk_label_set_text(GTK_LABEL(lbl_SCREEN), "1");

	}
	void on_btm8()
	{

	    
	    gtk_label_set_text(GTK_LABEL(lbl_SCREEN), "8");

	}

	void on_btm5()
	{

	    
	    gtk_label_set_text(GTK_LABEL(lbl_SCREEN), "5");

	}
	void on_btm2()
	{

	    
	    gtk_label_set_text(GTK_LABEL(lbl_SCREEN), "2");

	}

	void on_btm9()
	{

	    
	    gtk_label_set_text(GTK_LABEL(lbl_SCREEN), "9");

	}
	void on_btm6()
	{

	    
	    gtk_label_set_text(GTK_LABEL(lbl_SCREEN), "6");

	}
	void on_btm3()
	{

	    
	    gtk_label_set_text(GTK_LABEL(lbl_SCREEN), "3");

	}
/*****************************/





void on_window_main_destroy()
{
    gtk_main_quit();
}