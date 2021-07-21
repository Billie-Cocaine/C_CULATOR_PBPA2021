// Aarón Sibaja || Garita aaron.sibajagarita@ucr.ac.cr
// Andrés Corrales Castro || andres.corralescastro@ucr.ac.cr

			//---Programación Bajo Plataformaas Abiertas---//




#include <stdlib.h>
#include <gtk/gtk.h>
#include <string.h>
#include <stdio.h>


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



char value1[100]="";
char value2[100]="";
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

	// change the values for method and door

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
    	char s1[100];		//a,b are containers for conversion of string to float
    	int a =atoi(value1); // atoi(mystring)--> is a fuction that converts
    	int b =atoi(value2); // string to an integer 
    	int value3=a-b;
    	sprintf(s1,"%d",value3);
    	gtk_label_set_text(GTK_LABEL(lbl_SCREEN),s1);
    }
    else if (method == 0)
    {
    	char s1[100];	//a,b are containers for conversion of string to float
    	int a =atoi(value1); // atoi(mystring)--> is a fuction that converts
    	int b =atoi(value2); // string to an integer 
    	int value3=a+b;
    	sprintf(s1,"%d",value3);
    	gtk_label_set_text(GTK_LABEL(lbl_SCREEN),s1);

    }
     else if (method == 2)
    {
    	char s1[100];		//a,b are containers for conversion of string to float
    	int a =atoi(value1); // atoi(mystring)--> is a fuction that converts
    	int b =atoi(value2); // string to an integer 
    	int value3=a*b;
    	sprintf(s1,"%d",value3);
    	gtk_label_set_text(GTK_LABEL(lbl_SCREEN),s1);

    }

    else if (method == 3)
    {
    	/*** a, b are containers for conversion of string to float
    	 strtof(mystring, *ptr)--> is a function that converts
    	 string to an float***/

    	char s1[100];
    	char *pEND;
    	float a, b; 				
    	a =strtof(value1, &pEND); 
    	b =strtof(value2, &pEND);  
    	
    	if (b == 0) // validation of division in cero
    	{
    		gtk_label_set_text(GTK_LABEL(lbl_SCREEN), "ERROR");
    	}
    	else
    	{

    	float value3=a/b;
    		sprintf(s1,"%f",value3);
    		gtk_label_set_text(GTK_LABEL(lbl_SCREEN),s1);
    	}



    }
    /**
     * strcpy(char1, char2)--> is a function that copy strings, 
     * copy char2 in char1
		 **/


    strcpy(value1,"");
    strcpy(value2,"");
    door=0;



    }


	void on_btmERRASE(GtkWidget *widget, gpointer user_data)
	{
		/***
		 * set all values to initial status 
		 * 
		 * 
		 * strcpy(char1, char2)--> is a function that copy strings, 
		 * copy char2 in char1
		 **/



    strcpy(value1,"");
    strcpy(value2,"");
	value3=0;
	method=0;
	door=0;
	gtk_label_set_text(GTK_LABEL(lbl_SCREEN), "");


}







/*  SET FUNTIONS TO THE NUMERIC BOTTONS    */
	/**
	*strcat(char1, char2)--> is a function that concatenate strings, add
	*in the end of char1 the values of char2 
	**/



	void on_btm7(GtkWidget *widget, gpointer user_data)
	{
		/***
		 * set number 7 
		 * 
		*/


		if(door)
    	{ 
    		strcat(value2, "7");
    		gtk_label_set_text(GTK_LABEL(lbl_SCREEN), value2);

    	}
		else
    	{ 
    		
    		strcat(value1,"7");
    		gtk_label_set_text(GTK_LABEL(lbl_SCREEN), value1);
    	}
	}

	void on_btm4(GtkWidget *widget, gpointer user_data)
	{
		/***
		 * set number 4 
		 * 
		*/


		if(door)
    	{ 
			strcat(value2,"4");
    		gtk_label_set_text(GTK_LABEL(lbl_SCREEN), value2);

    	}
		else
    	{ 
    		strcat(value1,"4"); 
    		gtk_label_set_text(GTK_LABEL(lbl_SCREEN), value1);
    	}
	}


	void on_btm1(GtkWidget *widget, gpointer user_data)
	{
		/***
		 * set number 4 
		 * 
		*/


		if(door)
    	{ 
    		strcat(value2, "1"); 
    		gtk_label_set_text(GTK_LABEL(lbl_SCREEN), value2);
    	}
		else
    	{ 
    		strcat(value1, "1"); 
    		gtk_label_set_text(GTK_LABEL(lbl_SCREEN), value1);

    	}    
	}

	void on_btm8(GtkWidget *widget, gpointer user_data)
	{
		/***
		 * set number 8 
		 * 
		*/

		if(door)
    	{ 
    		strcat(value2, "8"); 
    		gtk_label_set_text(GTK_LABEL(lbl_SCREEN), value2);
    	}
		else
    	{ 
    		strcat(value1, "8"); 
    		gtk_label_set_text(GTK_LABEL(lbl_SCREEN), value1);

    	}	    
	}

	void on_btm5(GtkWidget *widget, gpointer user_data)
	{

		/***
		 * set number 5 
		 * 
		*/

		if(door)
    	{ 
    		strcat(value2, "5"); 
    		gtk_label_set_text(GTK_LABEL(lbl_SCREEN), value2);
    	}
		else
    	{ 
    		strcat(value1, "5"); 
    		gtk_label_set_text(GTK_LABEL(lbl_SCREEN), value1);

    	}
	}

	void on_btm2(GtkWidget *widget, gpointer user_data)
	{

		/***
		 * set number 2 
		 * 
		*/

	    if(door)
    	{ 
    		strcat(value2, "2"); 
    		gtk_label_set_text(GTK_LABEL(lbl_SCREEN), value2);
    	}
		else
    	{ 
    		strcat(value1, "2"); 
    		gtk_label_set_text(GTK_LABEL(lbl_SCREEN), value1);

    	}
	}

	void on_btm9(GtkWidget *widget, gpointer user_data)
	{
		/***
		 * set number 7 
		 * 
		*/


		if(door)
    	{ 
    		strcat(value2, "9"); 
    		gtk_label_set_text(GTK_LABEL(lbl_SCREEN), value2);
    	}
		else
    	{ 
    		strcat(value1, "9"); 
    		gtk_label_set_text(GTK_LABEL(lbl_SCREEN), value1);

    	}
	}

	void on_btm6(GtkWidget *widget, gpointer user_data)
	{
		/***
		 * set number 7 
		 * 
		*/


		if(door)
    	{ 
    		strcat(value2, "6"); 
    		gtk_label_set_text(GTK_LABEL(lbl_SCREEN), value2);
    	}
		else
    	{ 
    		strcat(value1, "6"); 
    		gtk_label_set_text(GTK_LABEL(lbl_SCREEN), value1);

    	}
	}

	void on_btm3(GtkWidget *widget, gpointer user_data)
	{

		/***
		 * set number 3 
		 * 
		*/

		if(door)
    	{ 
    		strcat(value2, "3"); 
    		gtk_label_set_text(GTK_LABEL(lbl_SCREEN), value2);
    	}
		else
    	{ 
    		strcat(value1, "3"); 
    		gtk_label_set_text(GTK_LABEL(lbl_SCREEN), value1);

    	}
	}

	void on_btm0(GtkWidget *widget, gpointer user_data)
	{
		/***
		 * set number 0 
		 * 
		*/


		if(door)
    	{ 
    		strcat(value2, "0"); 
    		gtk_label_set_text(GTK_LABEL(lbl_SCREEN), value2);
    	}
		else
    	{ 
    		strcat(value1, "0"); 
    		gtk_label_set_text(GTK_LABEL(lbl_SCREEN), value1);

    	}

	}

/*****************************/






