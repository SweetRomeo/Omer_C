/*--------------------------------------------
  Klavyeden girilen gün ay ve yıl
  değerlerine bağlı olarak kendisine
  gönderilen tarihin geçerli bir tarih olup
  olmadığını test eden isValidDate isimli
  fonksiyon DateUtil.c dosyası içerisine
  yazınız ve test ediniz.

  Klavyeden girilen gün, ay ve yıl değerlerine
  göre girilen tarihin hangi güne denk geldiğini
  bulan getDayOfWeek isimli fonksiyonu yazınız
  ve test ediniz.
  - Fonksiyon geçersiz bir tarih için -1 değerini geri
  döndürecektir.
  - 01.01.1900 öncesindeki tüm tarihler geçersiz
  tarih sayılacak.
  - Haftanın günü 01.01.1900 ile verilen ile tarih
  arasındaki gün sayısının 7 ile bölümünden kadar
  sıfırsa "pazar", 1 ise "pazartesi", 2 ise "salı"
  .... 6 ise cumartesi
 ----------------------------------------------*/
#include "DateUtil.h"

int main()
{
    printDateTRTest();
}
