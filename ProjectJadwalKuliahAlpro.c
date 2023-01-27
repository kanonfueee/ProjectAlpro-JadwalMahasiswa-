#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define CHUNK 1024

void display(char *file_name){

    FILE *file;
    char buf[CHUNK];
    size_t nread;

    file = fopen(file_name, "r");
    if (file){
        while ((nread = fread(buf, 1, sizeof buf, file)) > 0)
        fwrite(buf, 1, nread, stdout);
        if (ferror(file)){}
        fclose(file);
    }
}

void editdata(char *file_name){

    FILE *file;
    FILE *temp_file;
    size_t nread;
    char buf[CHUNK];
    char search[50], replace[50];
    int line_number, class;

    file = fopen(file_name, "r");
    if (file){
        while ((nread = fread(buf, 1, sizeof buf, file)) > 0)
        fwrite(buf, 1, nread, stdout);
        if (ferror(file)){}
        fclose(file);
    }

    printf("Masukan Line : ");
    scanf("%d", &line_number);
    fflush(stdin);

    printf("Masukan Data Yang Ingin di Ganti : ");
    scanf(" %[^\n]s", search);
    fflush(stdin);

    printf("Masukan Data Baru : ");
    scanf(" %[^\n]s", replace);
    fflush(stdin);

    file = fopen("IF 01.txt", "r+");
    if (file == NULL) {
        printf("Error Membuka File!\n");
        return;
    }

    int current_line1 = 1;
    temp_file = fopen("temp.txt", "w");
    if (temp_file == NULL) {
        printf("Error!\n");
    }

    while (fgets(buf, CHUNK, file) != NULL) {
        if (current_line1 == line_number) {
                        
            char *pos = strstr(buf, search);
            if (pos != NULL) {
                            
                int offset = pos - buf;
                int searchLen = strlen(search);
                int replaceLen = strlen(replace);
                int bufferLen = strlen(buf);

                memmove(buf + offset + replaceLen, buf + offset + searchLen, bufferLen - offset - searchLen + 1);
                memcpy(buf + offset, replace, replaceLen);
            }
        }
        fputs(buf, temp_file);
        current_line1++;
    }

    fclose(file);
    fclose(temp_file);

    remove(file_name);
    rename("temp.txt", file_name);
}

void search_word(char *file_name, char *word){
    char buf[CHUNK];

    FILE *file = fopen(file_name, "r");
    if (file)
    {
        while (fgets(buf, sizeof buf, file))
        {
            if (strstr(buf, word) && strcmp(buf, "\n"))
            {
                printf("%s", buf);
            }
        }
        fclose(file);
    }
    else
    {
        printf("File Tidak Ditemukan\n");
    }
}

int main(){
    char buf[CHUNK], word[100];
    int class, choice;
    
    do{
        printf("\n======Main Menu======");
        printf("\n|1).Lihat Jadwal Kuliah\t|");
        printf("\n|2).Edit Jadwal Kuliah\t|");
        printf("\n|3).Cari Jadwal Kuliah\t|");
        printf("\n|0). Keluar Menu\t|");
        printf("\n=====================\n");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                system("cls");
                do {
                    printf("\nJadwal Untuk Kelas\n");
                    printf("1. IF 01\n");
                    printf("2. IF 02\n");
                    printf("3. IF 03\n");
                    printf("4. IF 04\n");
                    printf("0. Kembali\n");
                    printf("Pilih : \n");
                    scanf("%d", &class);
                        switch(class){
                            case 1:
                                system("cls");
                                display("IF 01.txt");
                                break;
                            case 2:
                                system("cls");
                                display("IF 02.txt");
                                break;
                            case 3:
                                system("cls");
                                display("IF 03.txt");
                                break;
                            case 4:
                                system("cls");
                                display("IF 04.txt");
                                break;
                            case 0:
                                system("cls");
                                break;
                                    }
                } while(class!=0);
                break;
            case 2:
                system("cls");
                do {
                    printf("\nEdit Data Untuk Kelas\n");
                    printf("1. IF 01\n");
                    printf("2. IF 02\n");
                    printf("3. IF 03\n");
                    printf("4. IF 04\n");
                    printf("0. Kembali\n");
                    printf("Pilih : \n");
                    scanf("%d", &class);
                        switch(class){
                            case 1:
                                system("cls");
                                editdata("IF 01.txt");
                                break;
                            case 2:
                                system("cls");
                                editdata("IF 02.txt");
                                break;
                            case 3:
                                system("cls");
                                editdata("IF 03.txt");
                                break;
                            case 4:
                                system("cls");
                                editdata("IF 04.txt");
                                break;
                            case 0:
                                system("cls");
                                break;
                                    }
                } while(class!=0);
                break;
            case 3:
                system("cls");
                do {
                    printf("\nCari Matkul Untuk Kelas\n");
                    printf("1. IF 01\n");
                    printf("2. IF 02\n");
                    printf("3. IF 03\n");
                    printf("4. IF 04\n");
                    printf("0. Kembali\n");
                    printf("Pilih : \n");
                    scanf("%d", &class);
                        switch(class){
                            case 1:
                                system("cls");
                                printf("Matkul yang ingin dicari: ");
                                scanf("%s", word);
                                search_word("Jadwal 01.txt", word);
                                break;
                            case 2:
                                system("cls");
                                printf("Matkul yang ingin dicari: ");
                                scanf("%s", word);
                                search_word("Jadwal 02.txt", word);
                                break;
                            case 3:
                                system("cls");
                                printf("Matkul yang ingin dicari: ");
                                scanf("%s", word);
                                search_word("Jadwal 03.txt", word);
                                break;
                            case 4:
                                system("cls");
                                printf("Matkul1 yang ingin dicari: ");
                                scanf("%s", word);
                                search_word("Jadwal 04.txt", word);
                                break;
                            case 0:
                                system("cls");
                                break;
                                    }
                } while(class!=0);
                break;
        }
    } while(choice!=0);
    system("cls");
    return 0;
}
