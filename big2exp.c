#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char* argv[]){

    if(argc==2){
        int exponent=atoi(argv[1]);
	printf("exp=%d\n",exponent);

        const int buff_size=0x10000; //65536 symbols
	char result[buff_size];
    
	//initialization
	for(int i=0; i<buff_size; i++) result[i]=0;
        result[0]='1';

	
        int carry=0,val;
	time_t start_t = time(NULL);
	for(int i=1; i<=exponent; i++){
	    int p=0;
	    while(result[p] || carry>0){
    		val = carry+2*((0==result[p])?0:result[p]-'0');
		if(val>9)
		{
		    result[p] = '0' + val % 10;
		    carry = val / 10; //allways = 1 for base == 2
		}
		else
		{
		    result[p] = '0' + val;
		    carry = 0;
		}
		++p;
	    }
	}
	time_t stop_t=time(NULL);

	int start=buff_size;
	while(0==result[--start]);

        for(int i=start; i>=0; i--){
	    putchar(result[i]);
	}
        putchar('\n');
	printf("Time sec:%ld\n",stop_t-start_t);
    }else{
	puts("not enough parameters");
    }
}