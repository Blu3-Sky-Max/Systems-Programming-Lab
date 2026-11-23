

  // finding max and mininum in an array and printing it 
public class max_min_process{ 

	public static void main ( String[] args) {

	    // using one dimension array 	

		int [] arr= { 39 , 102 , 45, 12 , 43, 48, 203, 7980, 234,90}; 
		 
		int max, min; 
		max=min=arr[0]; 

		for ( int i=1; i < arr.length; i++) { 

			 if ( max < arr[i] ) 
					 max = arr[i]; 
					 if (min >  arr[i]) 
					 min = arr[i]; 
		} 

		System.out.println("The max is: " +max  +  " and min is : " +min ); 
	} 	
} 
