// function.c
#include <stdio.h>
#include <string.h>
#include "function.h" // Include file function.h de biet khai báo hàm
#include <stdlib.h> // Thu vien ho tro exit()

//dinh nghia ham


//chon vai tro
void chooseRole(){
	int chooserole;
	printf("***Student Management System Using C***\n");
	printf("\n      CHOOSE YOUR ROLE      \n");
	printf(" ==============================\n");
	printf("  [1] Admin.\n");
	printf("  [2] Student.\n");
	printf("  [3] Teacher.\n");
	printf("  [0] Exit the Program.\n");
	printf(" ==============================\n");
	printf("     Enter your choose:  ");
}




//print
void displayMenu() {
    printf("***Student Management System Using C***\n");
    printf("\n               MENU       \n");
    printf("   =============================\n");
    printf("   [1] Enter student information.\n");
    printf("   [2] Show student information.\n");
    printf("   [3] Search student information.\n");
    printf("   [4] Edit student information.\n");
    printf("   [5] Edit student information.\n");
    printf("   [6] Edit student information.\n");
    printf("   [0] Exit the program .\n");
    printf("   =============================\n");
    printf("     Enter your choose:  ");
} 

//case 1
void addStudent() {
    FILE *file = fopen("Student.bin", "ab");
    if (file == NULL) {
        printf("ERROR 404. Unable to open the file.\n");
        return;
    }

    int numberStudents;
    printf("Add the number of students you want to add: ");
    scanf("%d", &numberStudents);
    getchar();

    for (int i = 0; i < numberStudents; i++) {
        Student student;
        int isDuplicate;
        printf("\nStudent %d:\n", i + 1);

        // Kiem tra trrung ID
        do {
            isDuplicate = 0;
            printf("Enter ID: ");
            scanf("%d", &student.id);
            getchar();

            FILE *readFile = fopen("Student.bin", "rb");
            if (readFile == NULL) {
                printf("ERROR 404...\n");
                fclose(file);
                return;
            }

            Student temp;
            while (fread(&temp, sizeof(Student), 1, readFile)) {
                if (temp.id == student.id) {
                    printf("ID already exists\n");
                    isDuplicate = 1;
                    break;
                }
            }
            fclose(readFile);
        } while (isDuplicate);

        // Nhap thong tin sinh vien
		 
        printf("Enter name: ");
        fgets(student.name, 50, stdin);
        student.name[strcspn(student.name, "\n")] = '\0';

        printf("Enter class: ");
        scanf("%d", &student.classroomId);
        getchar();

        printf("Enter gender: ");
        fgets(student.gender, 10, stdin);
        student.gender[strcspn(student.gender, "\n")] = '\0';

        printf("Enter email: ");
        fgets(student.email, 50, stdin);
        student.email[strcspn(student.email, "\n")] = '\0';

        printf("Enter phone: ");
        fgets(student.phone, 20, stdin);
        student.phone[strcspn(student.phone, "\n")] = '\0';

        // Ghi sinh viên vào file
        fwrite(&student, sizeof(Student), 1, file);
    }

    fclose(file);
    printf("\n%d students added successfully.\n \n", numberStudents);
    pressToExitOrReturn();
}



//case 2 
void showStudents() {
	
    FILE *file = fopen("student.bin", "rb");
    if (file == NULL) {
        printf("Do not open the file.\n");
        return;
    }
    
    Student student;
    
    printf("\n       Student list:\n");
    printf("---------------------------------------------------------------------------------------\n");
    printf("  ID  |       Name           | Class | Gender  |       Email               |   Phone  \n");
    printf("--------------------------------------------------------------------------------------\n");
    
    while (fread(&student, sizeof(Student), 1, file)) {
        printf("%-4d | %-20s | %-5d | %-7s | %-25s | %-10s \n",
               student.id, student.name, student.classroomId, student.gender, student.email, student.phone);
    }
    printf("--------------------------------------------------------------------------------------\n");
    fclose(file);
    pressToExitOrReturn();//goi ham exit or back 
}


// case 3
void updateStudent() {
    FILE *file = fopen("Student.bin", "rb+");
    if (file == NULL) {
        printf("Unable to open the file.\n");
        return;
    }

    Student student;
    int id, found = 0;

    printf("Enter ID student you want to update: ");
    scanf("%d", &id);
    getchar();

    // Tim kiem id  
    while (fread(&student, sizeof(Student), 1, file)) {
        if (student.id == id) {
            found = 1;

            // print thong tin hien tai 
            printf("\nCurrent information student:\n");
            printf("ID: %d\n", student.id);
            printf("Name: %s\n", student.name);
            printf("Class: %d\n", student.classroomId);
            printf("Gender: %s\n", student.gender);
            printf("Email: %s\n", student.email);
            printf("Phone: %s\n", student.phone);

            // Update sinh vien moi  
            printf("\nUpdate new information:\n");
            printf("Name: ");
            fgets(student.name, 50, stdin);
            student.name[strcspn(student.name, "\n")] = '\0';

            printf("Class: ");
            scanf("%d", &student.classroomId);
            getchar();

            printf("Gender: ");
            fgets(student.gender, 10, stdin);
            student.gender[strcspn(student.gender, "\n")] = '\0';

            printf("Email: ");
            fgets(student.email, 50, stdin);
            student.email[strcspn(student.email, "\n")] = '\0';

            printf("Phone: ");
            fgets(student.phone, 20, stdin);
            student.phone[strcspn(student.phone, "\n")] = '\0';

            // Ghi sinh vien moi vào file
            fseek(file, -sizeof(Student), SEEK_CUR);
            fwrite(&student, sizeof(Student), 1, file);

            printf("\nStudent information successfully update.\n");
            break;
        }
    }

    if (!found) {
        printf("\nStudent ID %d do not exist.\n", id); //not exist : khong ton tai
    }

    fclose(file);
    pressToExitOrReturn();//goi ham exit or back 
}

//ham exit or back 
void pressToExitOrReturn() {
    char choice;
    printf("\n  [0] Exit?   or  [b] Back menu?\n");
    
    choice = getchar();  // Doc ky tu nguoi dung nhap tu ban phim 
    getchar(); // Doc ky tu xuong dong con lai

    if (choice == '0') {
        printf("Exiting...\n");
        exit(0);  // Thoat chuong trinh
    } else if (choice == 'b') {
        return;  // Quay lai menu
    } else {
        printf("Invalid choice. Returning to menu...\n");
        return;  // Quay lai menu neu nhap sai
    }
}



























