
#include <stdlib.h>
#include <gtk/gtk.h>


/**VALUES CONTAINERS  
 * 
 * value1  contains the first number to operate
 * value2  contains the second number to operate
 * value3  contains the result of the operation
 * 
 * method is set to indicate wich is the arithmetic operation
 * 0-->addition
 * 1-->rest
 * 2-->multiplication
 * 3-->division 
 * 
 * door is set to indicate wich value to fill
 * 0-->fill value1
 * 1-->fill value2*/



float value1=0;
float value2=0;
float value3=0;
int method=0;
int door=0;


/* GTK OBJECTS  AND FUNCTIONS*/


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

void on_window_main_destroy()
{
    gtk_main_quit();
}




/*  SET FUNTIONS TO THE ARITHIMETIC BOTTONS    */

	void on_operationDIV()
	{

	    
		door=1;
    	method=3;

	}


	void on_operationMULT()
	{
		door=1;
    	method=2;

	}


	void on_operationREST(GtkWidget *widget, gpointer user_data)
	{

		door=1;
    	method=1;


		

	}


	void on_operationSUM(GtkWidget *widget, gpointer user_data)
	{
		

		door=1;
    	method=0;
		

	}

	void on_btmRESULT(GtkWidget *widget, gpointer user_data)
	{

	
    if(method == 1) 
    {
    	char s1[3];
    	int value3=value1-value2;
    	sprintf(s1,"%d",value3);
    	gtk_label_set_text(GTK_LABEL(lbl_SCREEN),s1);
    }
    else if (method == 0)
    {
    	char s1[3];
    	int value3=value1+value2;
    	sprintf(s1,"%d",value3);
    	gtk_label_set_text(GTK_LABEL(lbl_SCREEN),s1);

    }
     else if (method == 2)
    {
    	char s1[3];
    	int value3=value1*value2;
    	sprintf(s1,"%d",value3);
    	gtk_label_set_text(GTK_LABEL(lbl_SCREEN),s1);

    }

    else if (method == 3)
    {
    	char s1[9];
    	if (value2 == 0)
    	{
    		gtk_label_set_text(GTK_LABEL(lbl_SCREEN), "ERROR");
    	}
    	else
    	{
    		value3=value1/value2;
    		sprintf(s1,"%f",value3);
    		gtk_label_set_text(GTK_LABEL(lbl_SCREEN),s1);
    	}



    }


    value1=0;
    value2=0;
    door=0;



    }


	void on_btmERRASE(GtkWidget *widget, gpointer user_data)
	{



	value1=0;
	value2=0;
	value3=0;
	method=0;
	door=0;
	gtk_label_set_text(GTK_LABEL(lbl_SCREEN), "");





	}

	void on_btmPOINT(GtkWidget *widget, gpointer user_data)
	{
		printf("---SIN ASIGNACIÓN---\n" );

		// printf("Valor V1: %f\n",value1 );
	 //    printf("Valor V2: %f\n",value2 );
	 //    printf("Valor V3: %f\n",value3 );
	 //    printf("Valor M: %d\n",method );
	 //    printf("Valor d: %d\n",door );
	 //    printf("       \n" );

	


	}





/*  SET FUNTIONS TO THE NUMERIC BOTTONS    */



	void on_btm7(GtkWidget *widget, gpointer user_data)
	{


		if(door)
    	{ 
    		value2=7; 
    	}
		else
    	{ 
    		
    		value1=7 ; 
    	}

	    gtk_label_set_text(GTK_LABEL(lbl_SCREEN),"7");



	}
	void on_btm4(GtkWidget *widget, gpointer user_data)
	{


		if(door)
    	{ 
    		value2=4; 
    	}
		else
    	{ 
    		value1=4; 
    	}

	    gtk_label_set_text(GTK_LABEL(lbl_SCREEN), "4");

	}
	void on_btm1(GtkWidget *widget, gpointer user_data)
	{
		if(door)
    	{ 
    		value2=1; 
    	}
		else
    	{ 
    		value1=1;

    	}


	    gtk_label_set_text(GTK_LABEL(lbl_SCREEN), "1");

	}
	void on_btm8(GtkWidget *widget, gpointer user_data)
	{

		if(door)
    	{ 
    		value2=8; 
    	}
		else
    	{ 
    		value1=8; 
    	}

	    
	    gtk_label_set_text(GTK_LABEL(lbl_SCREEN), "8");

	}

	void on_btm5(GtkWidget *widget, gpointer user_data)
	{
		if(door)
    	{ 
    		value2=5; 
    	}
		else
    	{ 
    		value1=5; 
    	}

	    
	    gtk_label_set_text(GTK_LABEL(lbl_SCREEN), "5");

	}
	void on_btm2(GtkWidget *widget, gpointer user_data)
	{

	    if(door)
    	{
    		value2=2; 
    	}
		else
    	{ 
    		value1=2; 
    	}


	    gtk_label_set_text(GTK_LABEL(lbl_SCREEN), "2");

	}

	void on_btm9(GtkWidget *widget, gpointer user_data)
	{
		if(door)
    	{
    		value2=9; 
    	}
		else
    	{ 
    		value1=9; 
    	}

	    
	    gtk_label_set_text(GTK_LABEL(lbl_SCREEN), "9");

	}
	void on_btm6(GtkWidget *widget, gpointer user_data)
	{
		if(door)
    	{
    		value2=6; 
    	}
		else
    	{
    		value1=6; 
    	}

	    
	    gtk_label_set_text(GTK_LABEL(lbl_SCREEN), "6");

	}
	void on_btm3(GtkWidget *widget, gpointer user_data)
	{

		if(door)
    	{
    		value2=3; 
    	}
		else
    	{ 
    		value1=3; 
    	}


	    gtk_label_set_text(GTK_LABEL(lbl_SCREEN), "3");

	}


	void on_btm0(GtkWidget *widget, gpointer user_data)
	{

		if(door)
    	{
    		value2=0;
    	}
		else
    	{
    		value1=0;
    	}


	    gtk_label_set_text(GTK_LABEL(lbl_SCREEN), "0");

	}

/*****************************/





