#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(int argc, char *argv[]) {
	int a = 0, b = 0, i = 0, j = 0;
	
	char wynik[1000];
	int p[1000]; // w  p bêd¹ wartoœci po¿yczek zsumowane w liczami, wype³niamy zerami

	printf("a = "); scanf("%d",&a);
	printf("b = "); scanf("%d",&b);
	
	int a_length;
	int b_length;
	
	
	if(a==0){
		a_length= 1;
		b_length= 1;
	}else if(b==0){
		a_length= floor(log10(abs(a))) + 1;
		b_length= 1;		
	}else{
		a_length= floor(log10(abs(a))) + 1;
		b_length= floor(log10(abs(b))) + 1;	
	}
	
	char l1[a_length], l2[b_length];
	
	itoa(a, l1, 10); 
	itoa(b, l2, 10);
	
 	for(i=0; i<a_length; i++) {
		wynik[i]='0';//zerujemy tablicê wyników
		p[i] = l1[i] - 48;//wszystkie cyfry z a kopiujemy do p jako liczby
	}
	for(i=a_length-1, j=b_length-1; i>=0; i--,j--){	
	if(j>=0) {
		if(p[i]<l2[j]-48){ 
			p[i]+=10;//po¿yczamy 10 z poprzedniej pozycji
			p[i-1]--; //poprzedni¹ cyfrê zmniejszamy (bo po¿yczyliœmy)
		}
		wynik[i] = p[i] - (l2[j]-48) + 48 ;
	}	
	else {
		if(p[i]==-1) { //przy np.1000000-999, gdy skoñczy³y siê cyfry w mnjejszej liczbie
			p[i]=9;
			if(i>0) p[i-1]--; //
		}
		wynik[i] = p[i]+48;
	}	
	}
	i=0;
	while(wynik[i]=='0') wynik[i]=' ';
	printf("\n\n");
	
	//wyœwietlamy po¿yczki + liczba
	printf(" ");
	for(i=0; i<a_length; i++) 
		if(p[i]>=0 && p[i]!=l1[i]-48) printf("%2d", p[i]); 
		else printf("%2c",' ');
	
	printf("\n  "); 
	
	for(i=0; i<strlen(l1); i++){
		printf("%c ",l1[i]);
	}
	printf("\n");
	printf("-"); 
	  
	for(i=0; i<((a_length-b_length)*2) + 1; i++){
	printf(" ");
	}
	for(i=0; i<strlen(l2); i++){
		printf("%c ",l2[i]);
	}
	printf("\n");
	
	//wypisanie pod³óg  
	for(i = 0; i< a_length*2 + 1; i++){
		printf("-");
	}
	
printf("\n");
	
	//wypisanie wyniku w chwili kiedy wynik to 0
	if(a-b==0){
		for(i = 0; i< ((a_length-floor(log10(abs(1))))*2) ; i++){
			printf(" ");
		}
	}else{
		for(i = 0; i< ((a_length-floor(log10(abs(a-b))))*2) ; i++){
			printf(" ");
		}
	}
	itoa(a-b,wynik,10);
	
	for(i=0; i<strlen(wynik); i++){
		printf("%c ",wynik[i]);
	}
	printf("\n");
	
	return 0;
}

