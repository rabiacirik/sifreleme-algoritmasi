//
//  main.c
//  algoritmaödev
//
//  Created by Rabia Cırık on 6.12.2023.
//

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    char metin[200], sifrelenmisIfade[200], sifresicozunmus[200];
    int anahtar = 0, i = 0;
    char c;
    int islem;
    printf("         GIRILEN METNI ŞIFRELEME ALGORITMASI\n");
    printf("İslem=1 metni sifreler\n");
    printf("İslem=2 sifrelenmis metni cozer\n");
    printf("Yapmak istediginiz islemi secin:");
    scanf("%d", &islem);
    getchar();//Standart girişten bir sonraki karakteri okur.

    if (islem == 1) {
        printf("Sifrelenmesi istediginiz metni giriniz:");
        fgets(metin, sizeof(metin), stdin);

        printf("Harflerin kaydirma miktarini giriniz:");
        scanf("%d", &anahtar);

        while (metin[i] != 0) { //girdiğin metinin elemanları 0'a eşit değilse döngü çalışır
            c = metin[i];

            if (isalpha(c)) {//Fonksiyona geçirilen c parametre değerinin alfabede bulunan bir harf olup olmadığını kontrol eder
                
                c = toupper(c);// küçük harfteki karakterleri büyük harfe dönüştürür
                c = (c - 'A' + anahtar) % 26 + 'A'; // şifrelemede kaydırma yaparken harf dışı karakter kullanmaz
                sifrelenmisIfade[i] = c;
            } else {
                
                sifrelenmisIfade[i] = c;
            }

            i++;
        }

        sifrelenmisIfade[i] = 0;
        printf("%s\n", sifrelenmisIfade);
    } else if (islem == 2) {
        i = 0;  //ikinci döngü için i'yi sıfırla
        printf("Sifresini cözmek istediginiz metni girin:");
        fgets(metin, sizeof(metin), stdin);

        printf("Harflerin kaydirma miktarini giriniz:");
        scanf("%d", &anahtar);

        while (metin[i] != 0) {
            c = metin[i];

            if (isalpha(c)) {//Fonksiyona geçirilen c parametre değerinin alfabede bulunan bir harf olup olmadığını kontrol eder
                
                c = toupper(c);// küçük harfleri büyük harfe dönüştür
                c = (c - 'A' - anahtar + 26) % 26 + 'A'; // şifrelemede kaydırma yaparken harf dışı karakter kullanmaz
                sifresicozunmus[i] = c;
            } else {
                //harf olmayan ifadeler değişmeden kalır
                sifresicozunmus[i] = c;
            }

            i++;
        }

        sifresicozunmus[i] = 0;
        printf("%s\n", sifresicozunmus);
    }
    else{
        printf("hatali giriş");
    }
    return 0;
}
