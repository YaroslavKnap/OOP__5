#include <iostream>
#include <vector>
#include <memory>

const double PI = 3.14159265358979323846;

// Абстрактний клас геометричне тіло
class GeometricShape {
public:
    // Віртуальний метод для обчислення площі поверхні
    virtual double calculateSurfaceArea() const = 0;

    // Віртуальний метод для обчислення об'єму
    virtual double calculateVolume() const = 0;

    // Віртуальний деструктор
    virtual ~GeometricShape() = default;
};

// Похідний клас Піраміда
class Pyramid : public GeometricShape {
private:
    double baseArea; // Площа основи піраміди
    double height;   // Висота піраміди

public:
    // Конструктор
    Pyramid(double baseArea, double height) : baseArea(baseArea), height(height) {}

    // Реалізація віртуального методу для обчислення площі поверхні піраміди
    double calculateSurfaceArea() const override {
        // Формула для обчислення площі поверхні піраміди
        return baseArea + 0.5 * baseArea * sqrt(4 * pow(height, 2) + pow(baseArea, 2));
    }

    // Реалізація віртуального методу для обчислення об'єму піраміди
    double calculateVolume() const override {
        // Формула для обчислення об'єму піраміди
        return (1.0 / 3.0) * baseArea * height;
    }
};

// Похідний клас Куля
class Sphere : public GeometricShape {
private:
    double radius; // Радіус кулі

public:
    // Конструктор
    Sphere(double radius) : radius(radius) {}

    // Реалізація віртуального методу для обчислення площі поверхні кулі
    double calculateSurfaceArea() const override {
        // Формула для обчислення площі поверхні кулі
        return 4.0 * PI * pow(radius, 2);
    }

    // Реалізація віртуального методу для обчислення об'єму кулі
    double calculateVolume() const override {
        // Формула для обчислення об'єму кулі
        return (4.0 / 3.0) * PI * pow(radius, 3);
    }
};

int main() {
    setlocale(LC_ALL, "Ukr");

    // Використання поліморфізму через вказівники на базовий клас
    std::vector<std::unique_ptr<GeometricShape>> shapes;
    shapes.push_back(std::make_unique<Pyramid>(10.0, 5.0));
    shapes.push_back(std::make_unique<Sphere>(7.0));

    // Взаємодія з об'єктами через абстрактний клас
    for (const auto& shape : shapes) {
        std::cout << "Surface area: " << shape->calculateSurfaceArea() << std::endl;
        std::cout << "Volume: " << shape->calculateVolume() << std::endl;
        std::cout << "-------------------------\n";
    }

    return 0;
}
