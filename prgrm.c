#include<stdio.h>
#include<ctype.h>

int main(int argc, char *argv[]){
	FILE *fp;
	FILE *wp;
	char str[50];
	fp=fopen(argv[1],"r");
	wp=fopen("output","w");
	int i=0,j=0,k=0;
	char buff[255],temp[255];
	while(fgets(buff, 255, (FILE*)fp)){
		
		for(i=0;buff[i]!='\0';i++)
		{
			printf(" %c", buff[i]);
			
			if (buff[i]=='&')
			{
				if(buff[i+1] == '&')
				{
				   	fprintf(wp,"< logical operator, && >\n");
					i++;
				}
				else
				{
					 fprintf(wp,"<bitwise operator, & >\n");
				}
			}
			
			if (buff[i]=='|')
			{
				if(buff[i+1] == '|')
				{
				   	fprintf(wp,"< logical operator, || >\n");
					i++;
				}
				else
				{
					 fprintf(wp,"<no operator, | >\n");
				}
			}
			
			if (buff[i]=='+')
			{
				fprintf(wp,"<operator, + >\n");
				
			}
			
			if (buff[i]=='-')
			{
				fprintf(wp,"<operator, - >\n");
				
			}
			
			if (buff[i]=='=')
			{
				printf("hello");
				if(buff[i+1] == '=')
				{
				   	fprintf(wp,"<operator, == >\n");
					i++;
				}
				else
				{
					 fprintf(wp,"<operator, = >\n");
				}
			}
			
			if (isalpha(buff[i]))
			{
				k=0;
				for(j=i;isalnum(buff[j]);j++,i++)
				{
					temp[k]= buff[j];
					k++;
				}
				temp[k]='\0';
				fprintf(wp,"<identifier, %s >\n",temp);

			} 

			if (buff[i]=='>')
			{
				if(buff[i+1] == '=')
				{
				   	fprintf(wp,"<operator, >= >\n");
					i++;
				}
				else
				{
					 fprintf(wp,"<operator, > >\n");
				}
			}

			if (buff[i] == '<')
			{
				if(buff[i+1] == '=')
				{
					fprintf(wp, "<operator, <= >\n");
					i++;	
				}
				else
				{
					fprintf(wp, "operator, < >\n");
				}
			}
			
			if (buff[i] == '!')
			{
				if(buff[i+1] == '=')
				{
					fprintf(wp, "<operator, <= >\n");
					i++;	
				}
				else
				{
					fprintf(wp, "operator, < >\n");
				}
			}
			
						
			
					

			
			
		//	printf(" %c\n",buff[i]);
		}
	}
	
	//printf(" %s",argv[1]);
}
