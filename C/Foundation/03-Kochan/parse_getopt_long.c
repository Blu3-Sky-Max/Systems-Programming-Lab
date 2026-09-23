#include <stdio.h> 
#include <getopt.h> 


/* long parse handler from cli input
 * vist man optind or man optarg 
 * on how to use getopt, getopt_long
 * and getopt_long_only for parse
 */ 






int main (int __argc ,char * __argv[]) { 



struct option opt[]= { 
   {"profile", required_argument , NULL, 'p'},
   { "verbose", optional_argument , NULL, 'v'}  
}; 

  int c; 

 while ((c=getopt_long(__argc, __argv,  "p:v", opt, NULL) ) != -1){ 

    switch (c){ 
     case 'p': 
	fprintf(stdout, "profile:  %s\n", optarg);
	break;

 	case 'v': 
 	fprintf(stdout, "verbose on\n"); 
 	break; 

} 
}    

fprintf(stdout,"%i", optind); 
for (int i=optind;  i < __argc;  i++) 
    fprintf(stdout,"leftover:%s\n",__argv[i]);

 






} 

