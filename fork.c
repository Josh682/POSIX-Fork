#include <unistd.h>         //header file untuk system file POSIX(Portable Operating System Interface) (fork())
#include <stdio.h>          //header file untuk standard input output (printf, fflush)
#include <stdlib.h>         //header file standard library untuk fungsi exit()
#include <sys/wait.h>       //header file untuk menunggu (wait())
#include <sys/types.h>      //header file untuk tipe data sistem (pid_t)

int main(void) {
    int i, endvalue; //inisialisasi variabel i untuk perulangan dan endvalue untuk jumlah perulangan
    endvalue = 10; //membuat jumlah perulangan menjadi 10
    pid_t pid; //inisialisasi untuk id proses dengan tipe data pid_t 

    printf("calling fork()\n"); //mencetak kalimat calling fork() untuk menandakan kapan fungsi fork() dipanggil 
    pid = fork(); //menyimpan hasil kembalian(return) dari fungsi fork() ke dalam pid

    if (pid < 0){ //mengecek apakah program fork tidak berhasil (pid < 0)
        printf("Fork failed\n"); //mencetak Fork failed jika fork tidak berhasil
        exit(0); //exit setelah menyatakan jika fork tidak berhasil dijalankan
    } else if (pid == 0){ //mengecek apakah fungsi fork menghasilkan proses child (pid == 0)
        for (i = 0; i < endvalue; i++){ //memebuat perulangan dari i = 0 sampai i = endvalue (10)
            printf("Child\n"); //mencetak Child untuk menyatakan jika proses child sedang dilakukan
            fflush(stdout); //memaksa perintah printf sebelumnya yang masih tersimpan di buffer untuk dijalankan atau istilahnya "membersihkan" (flush) buffer output
        }
    } else{ //mengecek kondisi lain (parent)
        wait(NULL); //menunggu agar proses child selesai terlebih dahulu baru menjalankan proses parent, kalau tidak ada maka proses parent dan child akan saling bertumpuk
        for (i = 0; i < endvalue; i++) //memebuat perulangan dari i = 0 sampai i = endvalue (10)
        {
            printf("Parent\n"); //mencetak Parent untuk menyatakan jika proses parent sendang dijalankan
            fflush(stdout); //sama seperti fungsi fflush sebelumnya
        }
        printf("Parent Complete\n"); //mencetak Parent Complete jika proses parent sudah selesai dijalankan
        exit(0); //sama seperti fungsi exit sebelumnya 
    }
}