#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char* argv[]){

    if(argc==2){
	char topvalue = 82;
        int exponent=atoi(argv[1]);
	printf("exp=%d\n",exponent);

        const int buff_size=0x10000;
	char result[buff_size];
    
	//initialization
	for(int i=0; i<buff_size; i++) result[i]=topvalue;
        result[0]=1;

	
        int carry=0,val;
	time_t start_t = time(NULL);
	for(int i=1; i<=exponent; i++){
	    int p=0;
	    while(topvalue!=result[p] || carry>0){
    		val = carry+2*((topvalue==result[p])?0:result[p]);
		if(val>9)
		{
		    result[p] =  val % 10;
		    carry = val / 10; //allways = 1 for base == 2
		}
		else
		{
		    result[p] = val;
		    carry = 0;
		}
		++p;
	    }
	}

	time_t stop_t = time(NULL);

	int start=buff_size;
	while(topvalue==result[--start]);

        for(int i=start; i>=0; i--){
	    putchar('0'+result[i]);
	}
        putchar('\n');

	printf("time sec:%ld\n",stop_t-start_t);
    }else{
	puts("not enough parameters");
    }
}