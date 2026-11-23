

// java adding up array 
 
public class process_sum_two_matrix{ 

	public static void main ( String[] argv) { 

		int [] yes= { 223, 23, 33, 12 };

	     int sum=0;
       String message = "sum is: " ; 	     

		for ( int i: yes)
		       sum +=i; 

		System.out.println(message + " " + sum );

	// Another method you can use to add the sum 
	 
		 sum=0;
	for ( int i =0; i< yes .length; i++)  
	    sum=sum + yes [i];

          System.out.println("Second loop " + message  +sum); 
       
      // sum of first and last in my one dimension array 
                  sum =0; 
        for ( int i=0; i < yes.length; i++){ 
                 
                 if ( i ==0 || i+1 == yes.length) 
	           sum += yes[i]; 
          } 
	 
	 System.out.println("The sum of first and last in the array is: " +sum); 
       	

	}
} 	
