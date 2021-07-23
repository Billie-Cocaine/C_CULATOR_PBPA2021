  //Andrés Corrales Castro || andres.corralescastro@ucr.ac.cr
 // Aarón Sibaja Garita || aaron.sibajagarita@ucr.ac.cr
			//---Programación Bajo Plataformaas Abiertas---//


/**
 * 
 * @file main.c 
 * @version 1.0
 * @date July/2021
 * @author Andrés Corrales Castro || andres.corralescastro@ucr.ac.cr
 * @author Aarón Sibaja Garita || aaron.sibajagarita@ucr.ac.cr
 * @brief Calculator for basic operations with integers,
 * the application is implemented in a graphical interface created with GTK+3.
 * 
 * For the construction of the grphic interfce we used Glade aplication(version 3.22.1), Glade makes it easy
 * to design the interface and assign properties to graphic objects.
 * 
 * @brief This application was built as final project for  
 * the course of "Programación Bajo Plataformaas Abiertas", Escuela de Ingeniería Eléctrica,
 * Universidad de Costa Rica. **/


#include <stdlib.h>
#include <gtk/gtk.h>
#include <string.h>
#include <stdio.h>


/**@brief VALUES CONTAINERS 
 * 
 *  
 *@brief value1 and value2 are ser as char array for an easy way to concatenate 
 * numbers in order to use strcat().
 * 
 * 
 * 
 *  
 * value1  contains the first number to operate.
 * 
 * value2  contains the second number to operate.
 * 
 * value3  contains the result of the operation.
 * 
 * method is set to indicate wich is the arithmetic operation.
 * 
 * 0-->addition.
 * 
 * 1-->rest.
 * 
 * 2-->multiplication.
 * 
 * 3-->division .
 * 
 * 
 * 
 * gate is set to indicate wich value to fill.
 * 
 * 0-->fill value1.
 * 
 * 1-->fill value2.
 * 
 * @code
 	char value1[100]="";
	char value2[100]="";
	float value3=0;
	int method=0;
	int gate=0;
 * @endcode
 * */





char value1[100]="";
char value2[100]="";
float value3=0;
int method=0;
int gate=0;




GtkWidget *lbl_SCREEN;

/**
 *GTK OBJECTS  AND FUNCTIONS
 * @brief Here is where all graphicla objects are build and import from Glade template.
 * 
 * @code
 * GtkWidget *lbl_SCREEN;
 * int main(int argc, char *argv[])
{
    GtkBuilder      *builder; 
    GtkWidget       *window;



    gtk_init(&argc, &argv);


    builder = gtk_builder_new(); // here is set a plece in memory for the  glade template
    gtk_builder_add_from_file (builder, "glade/window_main.glade", NULL); //this fucntion load a glade template fom a file

    window = GTK_WIDGET(gtk_builder_get_object(builder, "window_main")); // this is set a place in memory for the main window graphical object
    gtk_builder_connect_signals(builder, NULL);


    lbl_SCREEN = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_SCREEN")); // here is set a label which is used as screen


    g_object_unref(builder);

    gtk_widget_show(window);                
    gtk_main();


    return 0;
}
 * @endcode
 **/

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

/**
 * 
 * @brief This function send a signal that closes the aplication
 * 
 ***/

void on_window_main_destroy()
{
    gtk_main_quit();
}



/**    
 * 
 * @brief Change the values for method and gate
 * 
 *  	gate=1;
    	method=3;

 * */

	

	void on_operationDIV()
	{
 
		gate=1;
    	method=3;

	}
/**    
 * 
 * @brief Change the values for method and gate
 * 
 * 		gate=1;
    		method=2;
 * */

	void on_operationMULT()
	{

		gate=1;
    	method=2;

	}
/**    
 * 
 * @brief Change the values for method and gate
 * 
 *   		gate=1;
    		method=1;

 * */

	void on_operationREST(GtkWidget *widget, gpointer user_data)
	{

		gate=1;
    	method=1;

	}


/**    
 * 
 * @brief Change the values for method and gate
 * 
 * 		gate=1;
    		method=0;

 * */

	void on_operationSUM(GtkWidget *widget, gpointer user_data)
	{

		gate=1;
    	method=0;
		

	}
		/**
		 * @brief This botom operate the values that the user set. This opertion is guide by the value of "method".
		 * 
		 * 
		 * For the addition, rest ans multiplicatión firts is needed to convert values from value1 and value2
		 * to integer, this values were set as string. In this way "atoi()" function transform string values
		 * to integer,("a" and "b") are containers for the conversion of strings values.
		 * @code
				int a =atoi(value1); 
    			int b =atoi(value2); 
		 * 
		 * @endcode
		 * 
		 * For division operation, values need to be transform from string to float, in order to
		 * get a correct resoult. In this case "strtof()" is the fuction that works for it.
		 * @code
		 * 	char *pEND;
				int a =strtof(value1, &pEND); 
    			int b =strtof(value2, &pEND); 
		 * 
		 * @endcode
		 * 
		 * 
		 **/
	void on_btmRESULT(GtkWidget *widget, gpointer user_data)
	{

	
    if(method == 1) 
    {
    	char s1[100];		
    	int a =atoi(value1); 
    	int b =atoi(value2);  
    	int value3=a-b;
    	sprintf(s1,"%d",value3);
    	gtk_label_set_text(GTK_LABEL(lbl_SCREEN),s1);
    }
    else if (method == 0)
    {
    	char s1[100];	
    	int a =atoi(value1); 
    	int b =atoi(value2); 
    	int value3=a+b;
    	sprintf(s1,"%d",value3);
    	gtk_label_set_text(GTK_LABEL(lbl_SCREEN),s1);

    }
     else if (method == 2)
    {
    	char s1[100];		
    	int a =atoi(value1); 
    	int b =atoi(value2);  
    	int value3=a*b;
    	sprintf(s1,"%d",value3);
    	gtk_label_set_text(GTK_LABEL(lbl_SCREEN),s1);

    }

    else if (method == 3)
    {
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
    gate=0;



    }


	void on_btmERRASE(GtkWidget *widget, gpointer user_data)
	{
		/**
		 * @brief Set all values to initial status .
		 * 
		 * 
		 * strcpy(char1, char2)--> is a function that copy strings, 
		 * copy char2 in char1.
		 * 
		 * 
		 * @code
		 * 
			strcpy(value1,"");
   			strcpy(value2,"");
			value3=0;
			method=0;
			gate=0;
			gtk_label_set_text(GTK_LABEL(lbl_SCREEN), "");
			@endcode

		 **/



    strcpy(value1,"");
    strcpy(value2,"");
	value3=0;
	method=0;
	gate=0;
	gtk_label_set_text(GTK_LABEL(lbl_SCREEN), "");


}







/* SET FUNTIONS TO THE NUMERIC BOTTONS */

		/**
		 * set number 7
		 * @brief  The values stored in the variable "gate" are evaluated,
		 *  if "gate" is TRUE(gate=1), value2 is filled, for "gate" equal FALSE(gate=0), value1 is filled. 
		 * The value of "gate" Changes when an operation button is clicked.
		 * 
		 * strcat(char1, char2)--> is a function that concatenate strings, add
		 * in the end of char1 the values of char2 .
		 * 
		 * gtk_label_set_text(GTK_LABEL(lbl_SCREEN), value#), this function shows on label screen
		 * the values stored in variables "value1" and "value2".
		 * 
		 * 
		*/


	void on_btm7(GtkWidget *widget, gpointer user_data)
	{



		if(gate)
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
		/**
		 * set number 4
		 * @brief  The values stored in the variable "gate" are evaluated,
		 *  if "gate" is TRUE(gate=1), value2 is filled, for "gate" equal FALSE(gate=0), value1 is filled. 
		 * The value of "gate" Changes when an operation button is clicked.
		 * 
		 * strcat(char1, char2)--> is a function that concatenate strings, add
		 * in the end of char1 the values of char2.
		 * 
		 * gtk_label_set_text(GTK_LABEL(lbl_SCREEN), value#), this function shows on label screen
		 * the values stored in variables "value1" and "value2".
		 * 
		*/

	void on_btm4(GtkWidget *widget, gpointer user_data)
	{



		if(gate)
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
		/**
		 * set number 1
		 * @brief  The values stored in the variable "gate" are evaluated,
		 *  if "gate" is TRUE(gate=1), value2 is filled, for "gate" equal FALSE(gate=0), value1 is filled. 
		 * The value of "gate" Changes when an operation button is clicked.
		 * 
		 * strcat(char1, char2)--> is a function that concatenate strings, add
		 * in the end of char1 the values of char2.
		 * 
		 * gtk_label_set_text(GTK_LABEL(lbl_SCREEN), value#), this function shows on label screen
		 * the values stored in variables "value1" and "value2".
		 * 
		 * 
		*/


	void on_btm1(GtkWidget *widget, gpointer user_data)
	{



		if(gate)
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
		/**
		 * set number 8
		 * @brief  The values stored in the variable "gate" are evaluated,
		 *  if "gate" is TRUE(gate=1), value2 is filled, for "gate" equal FALSE(gate=0), value1 is filled. 
		 * The value of "gate" Changes when an operation button is clicked.
		 * 
		 * strcat(char1, char2)--> is a function that concatenate strings, add
		 * in the end of char1 the values of char2. 
		 * 
		 * gtk_label_set_text(GTK_LABEL(lbl_SCREEN), value#), this function shows on label screen
		 * the values stored in variables "value1" and "value2".
		 * 
		 * 
		*/

	void on_btm8(GtkWidget *widget, gpointer user_data)
	{
		

		if(gate)
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
		/**
		 * set number 5
		 * @brief  The values stored in the variable "gate" are evaluated,
		 *  if "gate" is TRUE(gate=1), value2 is filled, for "gate" equal FALSE(gate=0), value1 is filled. 
		 * The value of "gate" Changes when an operation button is clicked.
		 * 
		 * strcat(char1, char2)--> is a function that concatenate strings, add
		 * in the end of char1 the values of char2. 
		 * 
		 * gtk_label_set_text(GTK_LABEL(lbl_SCREEN), value#), this function shows on label screen
		 * the values stored in variables "value1" and "value2".
		 * 
		 * 
		*/

	void on_btm5(GtkWidget *widget, gpointer user_data)
	{



		if(gate)
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

		/**
		 * set number 2
		 * @brief  The values stored in the variable "gate" are evaluated,
		 *  if "gate" is TRUE(gate=1), value2 is filled, for "gate" equal FALSE(gate=0), value1 is filled. 
		 * The value of "gate" Changes when an operation button is clicked.
		 * 
		 * strcat(char1, char2)--> is a function that concatenate strings, add
		 * in the end of char1 the values of char2.
		 * 
		 * gtk_label_set_text(GTK_LABEL(lbl_SCREEN), value#), this function shows on label screen
		 * the values stored in variables "value1" and "value2".
		 * 
		 * 
		*/

	void on_btm2(GtkWidget *widget, gpointer user_data)
	{


	    if(gate)
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
		/**
		 * set number 9
		 * @brief  The values stored in the variable "gate" are evaluated,
		 *  if "gate" is TRUE(gate=1), value2 is filled, for "gate" equal FALSE(gate=0), value1 is filled. 
		 * The value of "gate" Changes when an operation button is clicked.
		 * 
		 * strcat(char1, char2)--> is a function that concatenate strings, add
		 * in the end of char1 the values of char2. 
		 * 
		 * gtk_label_set_text(GTK_LABEL(lbl_SCREEN), value#), this function shows on label screen
		 * the values stored in variables "value1" and "value2".
		 * 
		 * 
		*/

	void on_btm9(GtkWidget *widget, gpointer user_data)
	{
	


		if(gate)
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
		/**
		 * set number 6
		 * @brief  The values stored in the variable "gate" are evaluated,
		 *  if "gate" is TRUE(gate=1), value2 is filled, for "gate" equal FALSE(gate=0), value1 is filled. 
		 * The value of "gate" Changes when an operation button is clicked.
		 * 
		 * strcat(char1, char2)--> is a function that concatenate strings, add
		 * in the end of char1 the values of char2. 
		 * 
		 * gtk_label_set_text(GTK_LABEL(lbl_SCREEN), value#), this function shows on label screen
		 * the values stored in variables "value1" and "value2".
		 * 
		 * 
		*/


	void on_btm6(GtkWidget *widget, gpointer user_data)
	{


		if(gate)
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
		/**
		 * set number 3
		 * @brief  The values stored in the variable "gate" are evaluated,
		 *  if "gate" is TRUE(gate=1), value2 is filled, for "gate" equal FALSE(gate=0), value1 is filled. 
		 * The value of "gate" Changes when an operation button is clicked.
		 * 
		 * strcat(char1, char2)--> is a function that concatenate strings, add
		 * in the end of char1 the values of char2. 
		 * 
		 * gtk_label_set_text(GTK_LABEL(lbl_SCREEN), value#), this function shows on label screen
		 * the values stored in variables "value1" and "value2".
		 * 
		 * 
		*/

	void on_btm3(GtkWidget *widget, gpointer user_data)
	{



		if(gate)
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
			/**
		 * set number 0
		 * @brief  The values stored in the variable "gate" are evaluated,
		 *  if "gate" is TRUE(gate=1), value2 is filled, for "gate" equal FALSE(gate=0), value1 is filled. 
		 * The value of "gate" Changes when an operation button is clicked.
		 * 
		 * strcat(char1, char2)--> is a function that concatenate strings, add
		 * in the end of char1 the values of char2. 
		 * 
		 * gtk_label_set_text(GTK_LABEL(lbl_SCREEN), value#), this function shows on label screen
		 * the values stored in variables "value1" and "value2".
		 * 
		 * 
		*/

	void on_btm0(GtkWidget *widget, gpointer user_data)
	{



		if(gate)
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






