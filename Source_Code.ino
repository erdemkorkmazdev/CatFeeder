#include <HX711.h>
#include <LiquidCrystal.h>
#include <AccelStepper.h>

// Loadcell ve HX711 pinleri
const int LOADCELL_DOUT_PIN = 6;
const int LOADCELL_SCK_PIN = 7;

// Step motor pinleri
const int MOTOR_PIN1 = 2;
const int MOTOR_PIN2 = 3;
const int MOTOR_PIN3 = 4;
const int MOTOR_PIN4 = 5;

const int LCD_RS_PIN = 13;
const int LCD_EN_PIN = 12;
const int LCD_D4_PIN = 11;
const int LCD_D5_PIN = 10;
const int LCD_D6_PIN = 9;
const int LCD_D7_PIN = 8;
const int LCD_COLS = 16;
const int LCD_ROWS = 2;

// Motor speed (steps per second)
const float MOTOR_SPEED = 300;

// Loadcell and HX711 objects
HX711 loadcell;
LiquidCrystal lcd(LCD_RS_PIN, LCD_EN_PIN, LCD_D4_PIN, LCD_D5_PIN, LCD_D6_PIN, LCD_D7_PIN);

// Stepper motor object
AccelStepper motor(AccelStepper::FULL4WIRE, MOTOR_PIN1, MOTOR_PIN3, MOTOR_PIN2, MOTOR_PIN4);

void setup() {
  // Serial iletişimi başlatma (hata ayıklama için)
  Serial.begin(57600);

  // LCD başlatma
  lcd.begin(LCD_COLS, LCD_ROWS);

  // Loadcell ve HX711 başlatma
  loadcell.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
  
  // Step motor ayarları
  motor.setMaxSpeed(MOTOR_SPEED);
  motor.setSpeed(MOTOR_SPEED);
  
  // Step motorun ilk konumunu ayarla
  motor.setCurrentPosition(0);
}

void loop() {
  // Loadcell verisini oku
  int sonuc = loadcell.read();
  int load = loadcell.get_units();
  Serial.println(load);
  Serial.println(sonuc);
  // Ağırlığı LCD ekrana yazdır
  lcd.clear();
  lcd.print("Agirlik: ");
  lcd.print(load);
  lcd.print("g");
  
  // Ağırlık kontrolü
  if (load < 1500) {
    // Saat yönünde hareket
    motor.moveTo(400);
    motor.runToPosition();
    Serial.println(load);
    // Geri dönme
    motor.moveTo(0);
    motor.runToPosition();
  }
  
  // Kısa bir bekleme süresi
  delay(100);
}
