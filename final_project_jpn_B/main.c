// main.c
#include <stdio.h>
#include <stdlib.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int choose;
	
	
	do{
		chooseRole();
		scanf("%d", chooserole);
		getchar();
	
		switch(chooserole){
			case 1:{//admin
				printf("Updating...");
				break;
			}
			case 2:{//student
				do{
				displayMenu(); 
				scanf("%d",&choose);
				getchar();
				
				switch(choose){
					case 1:{
						addStudent();
						break;
					}
					case 2:{
						showStudents();
						break;
					}
					case 3:{
						updateStudent();
						break;
					}
					case 0:{
						printf("Exit the Program...\n");
						break;
					}
					default:{
						printf("Invalid selection...\n");
						break;
					}
				}	
			}while(choose!=0);
				break;
			}
			case 3:{//teacher
				
				break;
			}
			
		}
		
	}while(chooserole!=0);
	
	
	return 0;
}







