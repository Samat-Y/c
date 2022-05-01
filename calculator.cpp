
#include "stack.h"



int main()
{
	char input[100];
	PLink NUM,CH;
	CreativeL(NUM);
	CreativeL(CH);
	printf("«Î ‰»Îº∆À„ Ω£∫");
	scanf("%s",&input);
	printf("%s=",input);
	int end=rule(input,NUM,CH);
	if(end==-999)
	{
		return 0;
	}
	printf("%d",end);
	return 0;
}

