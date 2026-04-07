// C++ code
//
#include <Wire.h>
#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal lcd(0);

// Fungsi untuk membuat padding spasi
String buatPadding(int panjang) {
  String hasil = "";
  for (int i = 0; i < panjang; i++) {
    hasil += " ";
  }
  return hasil;
}

String padding;
String quote = "Yang terbaik masih akan datang. - (Anas)";
String quoteHasil;

int pos = 0;

void setup() {
  lcd.begin(16, 2);

  // Baris 1: QUOTE
  lcd.setCursor(5, 0);
  lcd.print("QUOTE");

  // Buat padding 16 spasi
  padding = buatPadding(16);

  // Hasilkan padding + teks + padding
  quoteHasil = padding + quote + padding;
}

void loop() {
  lcd.setCursor(0, 1);

  String tampil = quoteHasil.substring(pos, pos + 16);
  lcd.print(tampil);

  pos++;

  if (pos > quoteHasil.length() - 16) {
    pos = 0;
  }

  delay(300);
}
