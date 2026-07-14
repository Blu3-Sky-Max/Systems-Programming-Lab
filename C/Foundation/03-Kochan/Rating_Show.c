#include <stdio.h>

// counting a movie show rating. 



int main()
{
    int rating[11], responses, i ; 
    
    // without curly braces { }, a loop's body is only the single next statement.
    for ( i=1; i < 11; i++) 
        rating[i] = 0;  
    
        
        printf("Enter the number of your rating [1-10]: "); 
        
        for (i=1; i<=20; i++){ 
            scanf("%d", &responses); 
            if ( responses < 0 || responses > 10)
            printf("Bad responses sir \n"); 
            else 
            ++rating[responses]; 
        } 
        printf("\n\nRating      number of responses\n");
        printf("----        ------------------\n");
        for ( i=1; i<11; i++){ 
            printf("%3d %5i\n", i, rating[i]); 
}
} 

