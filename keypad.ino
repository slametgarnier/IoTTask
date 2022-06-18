#include<M5Stack.h>             // untuk menambahkan library dari m5stack
#include <Keypad.h>             // untuk menambahkan library dari keypad

const byte ROWS = 4;            // untuk mengatur posisi keypad
const byte COLS = 4;            // untuk mengatur posisi keypad 
byte rowPins[ROWS] = {17,16,21,22};   // untuk menyambungkan ke pinout baris keypad
byte colPins[COLS] = {5, 26, 13, 15}; // untuk menyambungkan ke pinout kolom keypad
char keys[ROWS][COLS] =         // untuk tata letak keypad
{
{'a','b','c','d'},
{'e','f','g','h'},
{'i','j','k','l'},
{'m','n','o','p'}
};
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS); // Inisialisasi library dengan pin yang digunakan

void setup() {                  // Semua kode dalam fungsi ini akan dieksekusi sekali
M5.begin();                     // digunakan untuk menentukan kecepatan dan penerimaan data melalui port m5
M5.Lcd.setCursor(100, 0, 4);    // digunakan untuk setting cursor hitungan
M5.Lcd.println("KEYBOARD");     // untuk menampilkan input dari keypad pada LCD
}
void loop()                     // Semua kode dalam fungsi ini di eksekusi
{
char key = keypad.getKey();     // untuk membaca keypad
if(key){                        // Kondisi pilihan jika keypad ditekan
Serial.println(key);            // untuk memindah ke baris berikutnya
M5.Lcd.fillRect(150, 150, 80, 50, BLACK); // untuk menggambar persegi panjang mulai dari sudut kiri atas yang ditentukan dan dengan lebar dan tinggi yang ditentukan
M5.Lcd.setCursor(150, 140, 4);  // digunakan untuk setting cursor hitungan
M5.Lcd.printf("%c",'A');        // untuk menampilkan output ke layar komputer
}
}
