/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 *   Modul               : 03 – Structures and Dynamic Arrays
 *   Hari dan Tanggal    : Rabu, 29 April 2026
 *   Nama (NIM)          : Muhammad Zaki Azzamy Syauqi (13224045)
 *   Nama File           : soal1.c
 *   Deskripsi           : Diberi input:
 *                           N nama1 kategori1 tahun1 nilai1 ... {n}
 *                         Dimana N adalah jumlah artefak, dan yang lain self explanatory
 *                         Semuanya harus diurut berdasarkan:
 *                          1. kategori alphabet naik
 *                          2. tahun naik
 *                          3. nilai turun
 *                          4. nama alphabet naik
 *                         Format output:
 *                           nama1 kategori1 tahun1 nilai1
 *                           ... {n}
 * 
 *                         Contoh:
 *                         Input: 3 Orb relik 2002 80 Rune kitab 1998 95 Aegis relik 1999 100
 *                         
 *                         Output: 
 *                         Rune kitab 1998 95
 *                         Aegis relik 1999 100
 *                         Orb relik 2002 80
 * 
 *                         Referensi:
 *                          1. Bubble sort: https://www.geeksforgeeks.org/dsa/bubble-sort-algorithm/
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LENGTH 100
typedef struct Artifact {
    char name[MAX_STR_LENGTH];
    char category[MAX_STR_LENGTH];
    int year;
    int value;
} Artifact;

Artifact* makeArtifactList(int N) {
    Artifact* list = (Artifact*)malloc(sizeof(Artifact) * N);
    if (list == NULL) {
        printf("Memory tidak cukup\n");
        return NULL;
    }
    return list;
}

void swap(Artifact* n1, Artifact* n2) {
    Artifact temp = *n1;
    *n1 = *n2;
    *n2 = temp;
    return;
}

void sortList(Artifact* list, int N) {
    int i, j;
    int swapped = 0;
    for (i = 0; i < N - 1; i += 1) {
        swapped = 0;
        for (j = 0; j < N - i - 1; j += 1) {
            // if biggest swap and swap = true
            if (strcmp(list[j].category, list[j+1].category) > 0) {
                swap(&list[j], &list[j+1]);
                swapped = 1;
            }

            else if (strcmp(list[j].category, list[j+1].category) == 0) {
                if (list[j].year > list[j+1].year) {
                    swap(&list[j], &list[j+1]);
                    swapped = 1;
                }

                else if (list[j].year == list[j+1].year) {
                    if (list[j].value < list[j+1].value) {
                        swap(&list[j], &list[j+1]);
                        swapped = 1;
                    }

                    else if (list[j].value == list[j+1].value) {
                        if (strcmp(list[j].name, list[j+1].name) > 0) {
                            swap(&list[j], &list[j+1]);
                            swapped = 1;
                        }
                    }
                }
            }
        }

        if (swapped == 0) {
            break;
        }
    }
}

void printList(Artifact* list, int N) {
    for (int i = 0; i < N; i += 1) {
        printf("%s %s %d %d\n", list[i].name, list[i].category, list[i].year, list[i].value);
    }
}

int main() {
    int N;
    scanf("%d", &N);
    Artifact* list = makeArtifactList(N);
    for (int i = 0; i < N; i += 1) {
        scanf("%s %s %d %d", list[i].name, list[i].category, &list[i].year, &list[i].value);
    }

    sortList(list, N);
    printList(list, N);
    return 0;
}